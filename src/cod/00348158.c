/* cygnus-2.96 matched TU. */

extern void sfmps_SetOption(void *a0);
extern void UpdateObj0000Fields_34F6C0(void *a0);
extern void func_00346968(void *a0, int *a1, int *a2);
extern void mwPlyReleaseLp(void *a0);
extern void SFPLY_MeasureFps(int *a0);
extern int Obj34D8_SetGlobalEE0B8_IfField48(int *a0);
extern int GetArrayElemA0C_35A1C8(int *a0, int a1);

/* MATCH via cygnus-2.96 +drop-freorder. */




__attribute__((section(".text.func_0034E1F0")))
int func_0034E1F0(char *a0) {
    int r;
    if (sfmps_GetTermDst(a0) == 1)
        return 0;
    sfmps_SetOption(a0);
    r = sfmps_DecodeSomeUnit(a0);
    if (*(int *)(a0 + 0x48) == 2)
        UpdateObj0000Fields_34F6C0(a0);
    return r;
}

/* MATCH via cygnus-2.96 +drop-freorder. */


__attribute__((section(".text.CheckReleasLpTiming")))
void CheckReleasLpTiming(char *a0) {
    int local0, local1;
    func_00346968(a0, &local0, &local1);
    if (local0 / local1 < *(int *)(a0 + 0x2FC) / 1000)
        return;
    if (*(int *)(a0 + 0x2E8) != 2)
        return;
    mwPlyReleaseLp(a0);
    *(int *)(a0 + 0x2E8) = 3;
}

/* MATCH via cygnus-2.96 +drop-freorder. */






__attribute__((section(".text.sfply_ChkFin")))
int sfply_ChkFin(int *a0)
{
    if (sfply_IsEtime(a0) != 0 ||
        sfply_IsEtrg(a0) != 0 ||
        sfply_IsStagnant(a0) != 0 ||
        sfply_IsPlayTimeAutoStop(a0) != 0 ||
        a0[0x18] != 0) {
        return sfply_Fin(a0);
    }
    return 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.sfply_Fin")))
int sfply_Fin(int *a0)
{
    int v0 = sfply_TrStop(a0);
    if (v0 != 0) return v0;
    a0[0x13] = 6;
    SFPLY_MeasureFps(a0);
    return 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */






__attribute__((section(".text.SFD_Start")))
int SFD_Start(int *a0)
{
    int r;
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0)
        return func_0034DD70(0, 0xFF000132);
    if (GetArrayElemA0C_35A1C8(a0, 0x2F) == 1)
        r = SFPL2_Standby(a0);
    else
        r = sfply_Start(a0);
    a0[0x11] = 1;
    return r;
}
