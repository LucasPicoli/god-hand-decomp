/* ee-2.9-991111 matched TU. */

typedef unsigned int u_int;

typedef struct alarm {
    struct alarm *next;   /* 0x00 */
    int id;               /* 0x04 */
    void *fn;             /* 0x08 */
    void *arg;            /* 0x0C */
} Alarm;

extern Alarm *volatile D_00784040;   /* g_pFreeAlarm */
extern int func_003B63A0(void);      /* DIntr */
extern int EIntr(void);
extern int func_003B7270(void);      /* AllocTimerCounter */
extern int func_003B7510(int id, int time, void *handler, void *arg);   /* SetTimerHandler */
extern int func_003B7380(int id);    /* StartTimerCounter */
extern int AlarmHandler(int id, int time, void *common, void *arg);

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

__attribute__((section(".text.func_003B7768")))
int func_003B7768(int time, void *fn, void *common)
{
    Alarm *p;
    int id;
    int intr;

    if (fn == 0) {
        return 0x80000016;
    }
    intr = func_003B63A0();
    p = AllocAlarm();
    if (p == 0) {
        if (intr) EIntr();
        return 0x80008005;
    }
    id = func_003B7270();
    if (id < 0) {
        FreeAlarm(p);
        if (intr) EIntr();
        return id;
    }
    p->fn = fn;
    p->arg = common;
    p->id = id;
    func_003B7510(id, time, AlarmHandler, p);
    func_003B7380(id);
    if (intr) EIntr();
    return (((u_int)p << 4) | (id & 0xFE)) | 1;
}
