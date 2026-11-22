/* cygnus-2.96 matched TU. */

extern void Obj3290_Tramp_0033E6A8_9070(void);
extern void func_00328E18(void *a0, int a1);
extern void Obj3290_Tramp_0033E6B0_9088(void);
extern void NoOp_33E6A8(void);
extern void adxt_StartSj(void *a0, int a1);
extern void NoOp_33E6B0(void);
extern void func_0032A900(signed char *a0, int a1);
extern void Obj0000_Call_00328C80_If_NonNull(void *arg0);
extern void func_00347E20(void *a0, int a1);
extern void func_0032ABB0(int a0, int a1);

__attribute__((section(".text.ADXSTM_SetPause")))
void ADXSTM_SetPause(void *obj, int a1) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00328E18(obj, a1);
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_00329D38")))
void func_00329D38(void *obj, int a1) {
    NoOp_33E6A8();
    adxt_StartSj(obj, a1);
    NoOp_33E6B0();
}

__attribute__((section(".text.ADXT_SetOutBalance")))
void ADXT_SetOutBalance(signed char *obj, int a1) {
    NoOp_33E6A8();
    func_0032A900(obj, a1);
    NoOp_33E6B0();
}

__attribute__((section(".text.MWSFD_SetFlowLimit")))
void MWSFD_SetFlowLimit(void *obj, int a1) {
    Obj0000_Call_00328C80_If_NonNull(*(void **)((char*)obj + 0x40));
    func_00347E20(obj, a1);
}

__attribute__((section(".text.ADXT_SetSvrFreq")))
void ADXT_SetSvrFreq(int a0, int a1) {
    NoOp_33E6A8();
    func_0032ABB0(a0, a1);
    NoOp_33E6B0();
}
