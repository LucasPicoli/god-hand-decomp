/* sn-2.95.3-136 matched TU. */

extern int SifGetReg(int reg);
extern void Obj0000_Set_D_003FAE30_Field_10_Zero(void);
extern void func_003B79C0(int a0, int a1);

__attribute__((section(".text.func_003B6240")))
int func_003B6240(void) {
    if (SifGetReg(4) & 0x40000) {
        Obj0000_Set_D_003FAE30_Field_10_Zero();
        func_003B79C0(1, 1);
        func_003B79C0(0, 1);
        return 1;
    }
    return 0;
}

__attribute__((section(".text.func_0039C390")))
int func_0039C390(int a0, int a1) {
    int local[2];
    int v1 = *(int *)(a0 + 0x868);
    if (v1 != 0 && a0 != 0 && *(int *)(a0 + 0xC) != 0) {
        local[1] = a1;
        local[0] = 0;
        return func_0039AB20(v1, local);
    }
    return func_0039C218(a1);
}
