/* cygnus-2.96 matched TU. */
#include "godhand/adxm.h"
#include "godhand/globals.h"

extern int CreateThread(void *);
extern void StartThread_3B0BA8(int, int);
extern void ChangeThreadPriority(int, int);
extern void adxm_mwidle_proc(void);
extern int D_00468CF0;

typedef struct {
    int status;
    void *func;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    int attr;
    int option;
} ThreadParam;

__attribute__((section(".text.func_00325578")))
void func_00325578(void) {
    ThreadParam param;
    param.func = (void *)adxm_mwidle_proc;
    param.stack = D_003CB9D0;
    param.stackSize = 0x2000;
    param.initPriority = D_003CF9D8;
    param.gpReg = &D_00468CF0;
    D_003C814C = CreateThread(&param);
    D_003C814C;
    StartThread_3B0BA8(D_003C814C, 0);
    ChangeThreadPriority(D_003C814C, D_003C80C8);
    adxm_SuspendThread(D_003C814C);
    D_003C814C;
}

__attribute__((section(".text.SFTIM_IsVideoTerm")))
int SFTIM_IsVideoTerm(char *a0) {
    int local0, local1;
    int a1val, s0, s1, r;
    char *p;
    a1val = *(int *)(a0 + 0x950);
    p = a0 + 0xD30;
    s1 = *(int *)(p + 0x27C);
    s0 = *(int *)(p + 0x280);
    if (a1val == 0) return 1;
    if (s1 == -5) return 0;
    SFTIM_GetTime(a0, &local0, &local1);
    r = UTY_CmpTime(s1 + s0 * 2000 / 59940, s0, local0, local1);
    return r != 0;
}
