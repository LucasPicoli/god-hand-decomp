/* cygnus-2.96 matched TU. */

extern int D_003EE314;
extern int D_003EE318;
extern void Thunk_func_0033B658(void *p);
extern void Thunk_func_0033B670(void *p);
extern int GetArrayElemA0C_35A1C8(int, int);
extern int sftim_GetTimeNone(int a0, int a1, int a2);
extern int SFTIM_IsStagnant(void *hn);

/* cygnus-2.96 candidate: SFTIM_GetVideoStartSample */





__attribute__((section(".text.func_0035A9C8")))
int func_0035A9C8(int a0, int a1, int *a2)
{
    int *p1 = (int *)(a0 + 0x118);
    int *p2 = (int *)(a0 + 0xEC);
    int smp;
    int den;
    int t;
    int r;
    t = p1[0];
    *a2 = t;
    if (t != 0) {
        smp = p1[9];
        den = p1[10];
    } else {
        t = p2[9];
        if (t >= 0) {
            smp = t;
            den = p2[10];
        } else {
            return -1;
        }
    }
    r = func_0036C920(smp, a1, den);
    D_003EE314 = smp;
    D_003EE318 = r;
    return r;
}

/* cygnus-2.96 candidate: SFTIM_GetTimeSub */




__attribute__((section(".text.func_0035AAC8")))
int func_0035AAC8(int a0, int *tp, int *unit)
{
    int *tim = (int *)(a0 + 0xD30);
    int *q = (int *)(a0 + 0xE48);
    int r;
    int u;
    r = func_0035AB80(a0);
    u = *unit;
    if (u == 1) {
        return r;
    }
    if (u == tim[82]) {
        *tp = *tp + tim[81];
    } else if (*q != 0) {
        *tp = *tp + func_0036C920(q[9], u, q[10]);
    }
    return r;
}

/* cygnus-2.96 candidate: SFTIM_GetNowTime */

typedef int (*GetTimeFn)(int a0, int a1, int a2);






__attribute__((section(".text.func_0035ABC0")))
int func_0035ABC0(int a0, int a1, int a2)
{
    int cs[4];
    GetTimeFn *tbl;
    GetTimeFn fn;
    int r;
    Thunk_func_0033B658(cs);
    tbl = (GetTimeFn *)(a0 + 0xD30);
    tbl += GetArrayElemA0C_35A1C8(a0, 0xF);
    fn = *tbl;
    if (fn == 0) {
        fn = sftim_GetTimeNone;
    }
    r = fn(a0, a1, a2);
    Thunk_func_0033B670(cs);
    return r;
}

__attribute__((section(".text.func_00358090")))
int func_00358090(void *hn)
{
    int *tmr = (int *)((char *)hn + 0x950);

    if (*(int *)((char *)hn + 0x48) != 4 || *(int *)((char *)hn + 0x50) == 1
        || tmr[8] == 1) {
        return 0;
    }
    return SFTIM_IsStagnant(hn) != 0;
}
