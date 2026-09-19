/* ee-2.9-991111 matched TU. */

typedef unsigned int u_int;
typedef unsigned short u_short;

typedef struct alarm {
    struct alarm *next;   /* 0x00 */
    int id;               /* 0x04 */
    void *fn;             /* 0x08 */
    void *arg;            /* 0x0C */
} Alarm;

extern Alarm *volatile D_00784040;   /* g_pFreeAlarm */
extern int iAllocTimerCounter(void);
extern int func_003B7400(int id, int time, void *handler, void *arg);   /* iSetTimerHandler */
extern int iStartTimerCounter(int id);
extern int AlarmHandler(int id, u_short time, void *common, void *arg);

static __inline__ Alarm *AllocAlarm(void)
{
    Alarm *p;

    p = D_00784040;
    if (p != 0) {
        D_00784040 = p->next;
    }
    return p;
}

static __inline__ void FreeAlarm(volatile Alarm *p)
{
    Alarm *old;

    old = D_00784040;
    D_00784040 = (Alarm *)p;
    p->next = old;
    p->id = 0;
}

__attribute__((section(".text.func_003B7898")))
int func_003B7898(int time, void *fn, void *common)
{
    Alarm *p;
    int id;

    if (fn == 0) {
        return 0x80000016;
    }
    p = AllocAlarm();
    if (p == 0) {
        return 0x80008005;
    }
    id = iAllocTimerCounter();
    if (id < 0) {
        FreeAlarm(p);
        return id;
    }
    p->fn = fn;
    p->arg = common;
    p->id = id;
    func_003B7400(id, time, AlarmHandler, p);
    iStartTimerCounter(id);
    return (((u_int)p << 4) | (id & 0xFE)) | 1;
}
