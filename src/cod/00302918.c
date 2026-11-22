/* cygnus-2.96 matched TU. */

extern int NoOp_33E6A8(int a0, int a1);
extern int NoOp_33E6B0(void);

__attribute__((section(".text.ADXT_SetOutVol")))
void ADXT_SetOutVol(int a0, int a1) {
    NoOp_33E6A8(a0, a1);
    func_0032AA30(a0, a1);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_00302918")))
void func_00302918(int *a0){
    *(int *)((char *)a0 + 0x114) |= 0x40000000;
}
