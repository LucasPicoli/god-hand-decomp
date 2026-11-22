/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void NoOp_33E6A8(void);
extern void func_00329AF0(void);
extern void NoOp_33E6B0(void);
extern void Forward33B658_3403C8(void);
extern void Forward3A52F0_3406B0(int);
extern void Forward33B670_3403E0(void);
extern void Obj33F8_NoOp_FCA0(void);
extern void aixp_Stop(int);
extern void Obj33F8_NoOp_FCA8(void);
extern void func_003B9AF8(void);
extern void ADXT_Destroy(int);
extern void func_00357490(void);
extern void SFSEE_ExecServer(int);
extern void ADXT_ClearErrCode(int);
extern void Forward33B658_3389F8(void);
extern void func_00338B40(void);
extern void Forward33B670_338A10(void);
extern void SJCRS_Finish(void);
extern void SJCRS_Init(void);
extern void ResetBufferOnFirstEnterA(void);
extern void func_003396F8(int);
extern void func_003404B0(int);
extern void Obj3290_Tramp_0033E6A8_9070(void);
extern void func_00328398(int);
extern void Obj3290_Tramp_0033E6B0_9088(void);
extern void Forward33E6A8_324880(void);
extern void func_00323B80(void);
extern void Forward33E6B0_324898(void);
extern void AC3CNV_Stop(void);
extern void func_003A52F0(int, int, int);
extern void func_00338EC8(int);
extern void func_0033A300(int);
extern void PushGlobalD8478History_331C78(int);
extern void func_00398DA0(int);
extern void func_00328FA0(int);
extern void Tramp_Obj3270_Tramp_0033D040_7728_32BB20(int);
extern void ResetBufferOnFirstEnterC(void);
extern void func_00338CD0(int);
extern void StmMgr_runStartupPass(void);
extern void func_0033A4F8(int);
extern void func_003397C8(int);
extern void Obj0000_PreDec_D_003EC450_340520(int);
extern void ADXSTM_StopNw(void);
extern void ADXSTM_ReleaseFileNw(int);
extern void func_00328048(int);
extern void _IO_flush_all(void);
extern void _IO_unbuffer_all(void);
extern void M2V_Setup(void);
extern void func_0036CCC8(int, int, int);
extern void func_0033A140(void);
extern void ADXT_ExecHndl(int);
extern void func_00335CD8(void);
extern void LSC_ResetEntry(int);
extern void func_00335CE0(void);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void func_003301B0(int);
extern void Obj33F8_Tramp_0033B670_FC88(void);
extern void Obj0000_Set_D_003D1410_And_D_003D1414_32AB58(int);
extern void func_00323AA0(int);
extern void Forward330C88_328C58(void);
extern void func_00327DC0(int);
extern void adxt_ExecFsSvr(void);
extern void Obj0000_Set_D_007588C0_Fields_0_1_33BF88(int, int);
extern void Obj0000_Set_D_007588C8_Args_0_1_33BFA0(int, int);
extern void Forward326800_32B4C8(int);
extern void adxf_StopPtLd(void);
extern void func_003358E8(int);
extern void Forward335A18_324C78(void);
extern void func_003241F8(void);
extern void aixp_Destroy(int);
extern void func_00328BB0(void);
extern void aixp_DestroyAll(void);
extern void Forward3466C0_348B78(void);
extern void Forward3466D8_348B90(void);

__attribute__((section(".text.ADXT_DestroyAll")))
void ADXT_DestroyAll(void) {
    NoOp_33E6A8();
    func_00329AF0();
    NoOp_33E6B0();
}

__attribute__((section(".text.PL2ENC_Destroy")))
void PL2ENC_Destroy(int a0) {
    Forward33B658_3403C8();
    Forward3A52F0_3406B0(a0);
    Forward33B670_3403E0();
}

__attribute__((section(".text.func_0032DB70")))
void func_0032DB70(int a0) {
    Obj33F8_NoOp_FCA0();
    aixp_Stop(a0);
    Obj33F8_NoOp_FCA8();
}

__attribute__((section(".text.func_00342A08")))
void func_00342A08(int a0) {
    func_003B9AF8();
    ADXT_Destroy(a0);
}

__attribute__((section(".text.func_00357468")))
void func_00357468(int a0) {
    func_00357490();
    SFSEE_ExecServer(a0);
}

__attribute__((section(".text.ADXT_ClearErrCode_32B118")))
void ADXT_ClearErrCode_32B118(int a0) {
    NoOp_33E6A8();
    ADXT_ClearErrCode(a0);
    NoOp_33E6B0();
}

__attribute__((section(".text.SJMEM_Finish")))
void SJMEM_Finish(void) {
    Forward33B658_3389F8();
    func_00338B40();
    Forward33B670_338A10();
    SJCRS_Finish();
}

__attribute__((section(".text.SJMEM_Init")))
void SJMEM_Init(void) {
    SJCRS_Init();
    Forward33B658_3389F8();
    ResetBufferOnFirstEnterA();
    Forward33B670_338A10();
}

__attribute__((section(".text.SJRBF_Destroy")))
void SJRBF_Destroy(int a0) {
    Forward33B658_3389F8();
    func_003396F8(a0);
    Forward33B670_338A10();
}

__attribute__((section(".text.PL2ENC_Init")))
void PL2ENC_Init(int a0) {
    Forward33B658_3403C8();
    func_003404B0(a0);
    Forward33B670_3403E0();
}

__attribute__((section(".text.ADXSTM_Stop")))
void ADXSTM_Stop(int a0) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00328398(a0);
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.ADXF_CloseAll")))
void ADXF_CloseAll(void) {
    Forward33E6A8_324880();
    func_00323B80();
    Forward33E6B0_324898();
}

__attribute__((section(".text.AC3CNV_Destroy")))
void AC3CNV_Destroy(int a0) {
    AC3CNV_Stop();
    func_003A52F0(a0, 0, 0x3c);
}

__attribute__((section(".text.SJMEM_Reset")))
void SJMEM_Reset(int a0) {
    Forward33B658_3389F8();
    func_00338EC8(a0);
    Forward33B670_338A10();
}

__attribute__((section(".text.SJUNI_Destroy")))
void SJUNI_Destroy(int a0) {
    Forward33B658_3389F8();
    func_0033A300(a0);
    Forward33B670_338A10();
}

__attribute__((section(".text.srd_wait_dvd")))
void srd_wait_dvd(void) {
    PushGlobalD8478History_331C78(0x1300);
    func_00398DA0(0);
    PushGlobalD8478History_331C78(0x1301);
}

__attribute__((section(".text.ADXSTM_OpenCvfs")))
void ADXSTM_OpenCvfs(int a0) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00328FA0(a0);
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_0032BAF0")))
void func_0032BAF0(int a0) {
    NoOp_33E6A8();
    Tramp_Obj3270_Tramp_0033D040_7728_32BB20(a0);
    NoOp_33E6B0();
}

__attribute__((section(".text.SJUNI_Init")))
void SJUNI_Init(void) {
    SJCRS_Init();
    Forward33B658_3389F8();
    ResetBufferOnFirstEnterC();
    Forward33B670_338A10();
}

__attribute__((section(".text.SJMEM_Destroy")))
void SJMEM_Destroy(int a0) {
    Forward33B658_3389F8();
    func_00338CD0(a0);
    Forward33B670_338A10();
}

__attribute__((section(".text.func_0032AF88")))
void func_0032AF88(void) {
    NoOp_33E6A8();
    StmMgr_runStartupPass();
    NoOp_33E6B0();
}

__attribute__((section(".text.SJUNI_Reset")))
void SJUNI_Reset(int a0) {
    Forward33B658_3389F8();
    func_0033A4F8(a0);
    Forward33B670_338A10();
}

__attribute__((section(".text.SJRBF_Reset")))
void SJRBF_Reset(int a0) {
    Forward33B658_3389F8();
    func_003397C8(a0);
    Forward33B670_338A10();
}

__attribute__((section(".text.PL2ENC_Finish")))
void PL2ENC_Finish(int a0) {
    Forward33B658_3403C8();
    Obj0000_PreDec_D_003EC450_340520(a0);
    Forward33B670_3403E0();
}

__attribute__((section(".text.func_00349B60")))
void func_00349B60(int a0) {
    ADXSTM_StopNw();
    ADXSTM_ReleaseFileNw(a0);
}

__attribute__((section(".text.ADXSTM_ReleaseFile")))
void ADXSTM_ReleaseFile(int a0) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00328048(a0);
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_0038CFA0")))
void func_0038CFA0(void) {
    _IO_flush_all();
    _IO_unbuffer_all();
}

__attribute__((section(".text.MPVM2V_Init")))
void MPVM2V_Init(void) {
    M2V_Setup();
    func_0036CCC8(8, D_00766D48, 0x3840);
}

__attribute__((section(".text.SJUNI_Finish")))
void SJUNI_Finish(void) {
    Forward33B658_3389F8();
    func_0033A140();
    Forward33B670_338A10();
    SJCRS_Finish();
}

__attribute__((section(".text.func_0032CFC8")))
void func_0032CFC8(int a0) {
    NoOp_33E6A8();
    ADXT_ExecHndl(a0);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_00335848")))
void func_00335848(int a0) {
    func_00335CD8();
    LSC_ResetEntry(a0);
    func_00335CE0();
}

__attribute__((section(".text.AIXSJD_ExecHndl")))
void AIXSJD_ExecHndl(int a0) {
    Obj33F8_Tramp_0033B658_FC70();
    func_003301B0(a0);
    Obj33F8_Tramp_0033B670_FC88();
}

__attribute__((section(".text.ADXT_SetDefSvrFreq")))
void ADXT_SetDefSvrFreq(int a0) {
    NoOp_33E6A8();
    Obj0000_Set_D_003D1410_And_D_003D1414_32AB58(a0);
    NoOp_33E6B0();
}

__attribute__((section(".text.ADXF_Close")))
void ADXF_Close(int a0) {
    Forward33E6A8_324880();
    func_00323AA0(a0);
    Forward33E6B0_324898();
}

__attribute__((section(".text.func_00328C30")))
void func_00328C30(void) {
    Obj3290_Tramp_0033E6A8_9070();
    Forward330C88_328C58();
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.ADXSTM_Destroy")))
void ADXSTM_Destroy(int a0) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00327DC0(a0);
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_0033F590")))
void func_0033F590(void) {
    NoOp_33E6A8();
    adxt_ExecFsSvr();
    NoOp_33E6B0();
}

__attribute__((section(".text.MWSFSVM_DeleteWaitVsyncFunc")))
void MWSFSVM_DeleteWaitVsyncFunc(void) {
    Obj0000_Set_D_007588C0_Fields_0_1_33BF88(0, 0);
    Obj0000_Set_D_007588C8_Args_0_1_33BFA0(0, 0);
}

__attribute__((section(".text.ADXT_TermSupply")))
void ADXT_TermSupply(int a0) {
    NoOp_33E6A8();
    Forward326800_32B4C8(a0);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_00322F58")))
void func_00322F58(void) {
    Forward33E6A8_324880();
    adxf_StopPtLd();
    Forward33E6B0_324898();
}

__attribute__((section(".text.func_003358B8")))
void func_003358B8(int a0) {
    func_00335CD8();
    func_003358E8(a0);
    func_00335CE0();
}

__attribute__((section(".text.func_00324C50")))
void func_00324C50(void) {
    NoOp_33E6A8();
    Forward335A18_324C78();
    NoOp_33E6B0();
}

__attribute__((section(".text.ADXF_ExecServer")))
void ADXF_ExecServer(void) {
    Forward33E6A8_324880();
    func_003241F8();
    Forward33E6B0_324898();
}

__attribute__((section(".text.func_0032D6F0")))
void func_0032D6F0(int a0) {
    Obj33F8_NoOp_FCA0();
    aixp_Destroy(a0);
    Obj33F8_NoOp_FCA8();
}

__attribute__((section(".text.ADXSTM_ExecServer")))
void ADXSTM_ExecServer(void) {
    Obj3290_Tramp_0033E6A8_9070();
    func_00328BB0();
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_0032EBD8")))
void func_0032EBD8(void) {
    Obj33F8_NoOp_FCA0();
    aixp_DestroyAll();
    Obj33F8_NoOp_FCA8();
}

__attribute__((section(".text.func_00348B20")))
void func_00348B20(void) {
    Obj0000_Set_D_007588C0_Fields_0_1_33BF88((int)Forward3466C0_348B78, 0);
    Obj0000_Set_D_007588C8_Args_0_1_33BFA0((int)Forward3466D8_348B90, 0);
}
