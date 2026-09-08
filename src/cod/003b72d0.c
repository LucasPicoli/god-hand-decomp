/* ee-2.9-991111 matched TU. */

typedef unsigned int u_int;

typedef struct {
    int  pad00[2];
    int  f08;     /* 0x08 */
    int  f0C;     /* 0x0C */
    long f10;     /* 0x10 */
} TimerCounter;

typedef struct {
    unsigned char pad00[0x1C];
    int  f1C;     /* 0x1C */
} TimerCtl;

extern volatile TimerCtl D_003FBE90;
extern long iGetTimerSystemTime(void);
extern void func_003B6DB8(TimerCounter *t);
extern void SetNextComp(long tm);

__attribute__((section(".text.iStartTimerCounter")))
int iStartTimerCounter(int id)
{
    TimerCounter *t;
    long tm;
    int c;

    t = (TimerCounter *)(((u_int)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != t->f08) {
        return 0x80008002;
    }
    if (D_003FBE90.f1C == id) {
        return 0x80000010;
    }
    if (t->f0C & 1) {
        return 1;
    }
    tm = iGetTimerSystemTime();
    t->f10 = tm;
    c = t->f0C | 1;
    t->f0C = c;
    if (c & 2) {
        func_003B6DB8(t);
        SetNextComp(tm);
    }
    return 0;
}
