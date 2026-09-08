/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern unsigned short D_00747A50;
extern int D_005FEA60;
extern void func_002DBE98(void);
extern unsigned int D_00747A78;
extern void func_00139180(int a0);
extern char D_0041DCC8[];
extern void __builtin_delete(void *a0);

__attribute__((section(".text.IsSpecialConditionMet_12C758")))
int IsSpecialConditionMet_12C758(char *a0) {
    if (D_00747A50 != 0x608) {
        return 0;
    }
    if (*(int*)(a0 + 0x698) != 0) {
        return 0;
    }
    if (*(int*)(a0 + 0x6A0) != 0) {
        return 0;
    }
    if (FindNodeByType_2C2568(&D_005FEA60, *(int*)(a0 + 0xF0), 0) == 1) {
        func_002DBE98();
        return 1;
    }
    return 0;
}

__attribute__((section(".text.func_00139060")))
void func_00139060(int a0)
{
    if ((D_00747A78 & 0x800000) == 0) {
        func_00139180(a0);
    }
}

__attribute__((section(".text.SetVtable80AndForwardNeg20_13D338")))
void SetVtable80AndForwardNeg20_13D338(void *a0, int a1)
{
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}

__attribute__((section(".text.SetVtable80AndMaybeForwardNeg20_13E300")))
void SetVtable80AndMaybeForwardNeg20_13E300(void *a0, int a1)
{
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}

__attribute__((section(".text.InitVtable80ConditionalForward_13E750")))
void InitVtable80ConditionalForward_13E750(void *a0, int a1)
{
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}

__attribute__((section(".text.SetField80VtableAndForward_13EC50")))
void SetField80VtableAndForward_13EC50(void *a0, int a1)
{
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}
