/* cygnus-2.96 matched TU. */

extern void Obj33F8_NoOp_FCA0(void);
extern int aixp_SetReloadTime(void *a0, float f12);
extern int Obj33F8_NoOp_FCA8(void);
extern void Forward33B568_33B658(void);
extern void func_0033B978(int a0, int a1);
extern void Forward33B5C8_33B670(void);

__attribute__((section(".text.AIXP_SetReloadTime")))
int AIXP_SetReloadTime(void *a0, float f12) {
    Obj33F8_NoOp_FCA0();
    aixp_SetReloadTime(a0, f12);
    return Obj33F8_NoOp_FCA8();
}

__attribute__((section(".text.SVM_DelCbSvr")))
void SVM_DelCbSvr(int a0, int a1) {
    Forward33B568_33B658();
    func_0033B978(a0, a1);
    Forward33B5C8_33B670();
}
