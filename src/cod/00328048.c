/* cygnus-2.96 matched TU. */

extern void mwsftag_GetAinfFromSj(void);
extern void mwsftag_GetSFXinfFromAinf(void *a0);
extern void sfsee_ExecHeadAnaly(void);
extern void sfsee_ExecFinAnaly(void *a0);
extern void sfxcnv_ExecCnvFrmByCbFunc(void *a0, int a1, int a2, int a3);
extern void Sfx_buildFrameRecord(void *a0, int a1, int a2);
extern void ADXSTM_Stop(void *obj);
extern void ADXSTM_ReleaseFileNw(void *obj);
extern void func_0033F590(void);
extern void Obj33F8_Tramp_0033B658_FC70(void *obj);
extern void func_003A52F0(void *obj, int a1, int a2);
extern void Obj33F8_Tramp_0033B670_FC88(void);

__attribute__((section(".text.MWSFTAG_UpdateTagInf")))
void MWSFTAG_UpdateTagInf(void *obj) {
    if (*(int *)((char*)obj + 0x17C) != 0) {
        mwsftag_GetAinfFromSj();
        mwsftag_GetSFXinfFromAinf(obj);
    }
}

__attribute__((section(".text.SFSEE_ExecServer")))
void SFSEE_ExecServer(void *obj) {
    if (*(int *)((char*)obj + 0x36B0) != 0) {
        sfsee_ExecHeadAnaly();
        sfsee_ExecFinAnaly(obj);
    }
}

__attribute__((section(".text.sfxcnv_ExecFullAlphaByCbFunc")))
void sfxcnv_ExecFullAlphaByCbFunc(void *obj, int a1, int a2) {
    sfxcnv_ExecCnvFrmByCbFunc(obj, a1, a2, 0);
    Sfx_buildFrameRecord(obj, a1, a2);
}

__attribute__((section(".text.func_00328048")))
void func_00328048(void *obj) {
    ADXSTM_Stop(obj);
    ADXSTM_ReleaseFileNw(obj);
    while (*(signed char *)((char*)obj + 0x49) != 0) {
        func_0033F590();
    }
}

__attribute__((section(".text.func_0032F428")))
void func_0032F428(void *obj) {
    Obj33F8_Tramp_0033B658_FC70(obj);
    if (obj != 0) {
        func_003A52F0(obj, 0, 0x1964);
    }
    Obj33F8_Tramp_0033B670_FC88();
}
