/* cygnus-2.96 matched TU. */

extern void Obj3290_Tramp_0033E6A8_9070(void);
extern void ADXSTM_SetSj(void *a0, int a1);
extern void Obj3290_Tramp_0033E6B0_9088(void);
extern void NoOp_33E6A8(void);
extern int Forward32BC98_32BD90(int a0, int a1);
extern void NoOp_33E6B0(void);
extern void Forward33B658_3403C8(void);
extern void Obj0000_Set_D_003EC454_D_003EC458_340438(int a0, int a1);
extern void Forward33B670_3403E0(void);

__attribute__((section(".text.func_00328E38")))
void func_00328E38(void *obj, int a1) {
    Obj3290_Tramp_0033E6A8_9070();
    ADXSTM_SetSj(obj, a1);
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_0032BD50")))
void func_0032BD50(void *obj, int a1) {
    NoOp_33E6A8();
    Forward32BC98_32BD90((int)obj, a1);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_003403F8")))
void func_003403F8(int a0, int a1) {
    Forward33B658_3403C8();
    Obj0000_Set_D_003EC454_D_003EC458_340438(a0, a1);
    Forward33B670_3403E0();
}
