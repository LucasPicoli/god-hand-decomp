#include "include_asm.h"

extern int D_00747A34;
extern char D_00754C10[];
extern char D_00754220[];
extern void func_003A52F0(void *, int, int);
extern void func_002CD740(void *);
extern int func_002CD7C8(int, int);

__attribute__((section(".text.IsSlotAvailable_2CB778")))
int IsSlotAvailable_2CB778(int a0, int a1)
{
    int *p;
    if (a1 == -1) return 1;
    p = GetIndexedEntry_2CC4B8(a0, a1);
    if (p[0x3C/4] == -1) return 1;
    p = GetIndexedEntry_2CC4B8(a0, a1);
    return cSeData_IsAlive(p);
}

__attribute__((section(".text.InitSlotContext_2CD6D0")))
void InitSlotContext_2CD6D0(int a0, int a1, int a2)
{
    int ret;
    *(int *)(a0 + 0x380) = a0;
    func_003A52F0((void *)a0, 0, 0x380);
    *(int *)(a0 + 0x384) = a2;
    func_002CD740((void *)a0);
    *(int *)(a0 + 0x38C) = a1;
    ret = func_002CD7C8(a1, a2);
    *(int *)(a0 + 0x388) = ret;
    *(int *)(*(int *)(a0 + 0x380) + 0x10) = ret;
}


__attribute__((section(".text.Setup_00309028_309028")))
void Setup_00309028_309028(char *a0)
{
    func_003A52F0((int)a0, 0, 0x2E0);
    *(char *)(a0 + 0x8D) = 6;
    *(short *)(a0 + 0x8E) = 5;
    *(unsigned int *)(a0 + 0x4C) = 0x80808080u;
    *(float *)(a0 + 0x7C) = 1.0f;
    *(float *)(a0 + 0x78) = 1.0f;
    *(float *)(a0 + 0x40) = 1.0f;
    *(short *)(a0 + 0xA0) = 0;
    *(short *)(a0 + 0xA2) = 0;
    *(short *)(a0 + 0xA6) = 0;
    *(short *)(a0 + 0xA8) = 0;
    *(short *)(a0 + 0xA4) = 0;
}

__attribute__((section(".text.AllocAndInitSystem_312F00")))
void *AllocAndInitSystem_312F00(void)
{
    void *p;
    if (!(D_00747A34 & 0x10000))
    {
        p = EnsureInitThenForward_2A9538_30EE08(0x1690, 0x10, D_00754C10);
        if (p != 0)
        {
            func_003A52F0(p, 0, 0x1690);
            return func_00107E40(p);
        }
    }
    return 0;
}

__attribute__((section(".text.AllocZeroedAndInit_3130E0")))
void *AllocZeroedAndInit_3130E0(void)
{
    void *p;
    if (!(D_00747A34 & 0x100000))
    {
        p = EnsureInitThenForward_2A9538_30EE08(0x1980, 0x10, D_00754220);
        if (p != 0)
        {
            func_003A52F0(p, 0, 0x1980);
            return func_00201FA0(p);
        }
    }
    return 0;
}
