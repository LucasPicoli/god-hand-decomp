/* cygnus-2.96 matched TU. */

extern int M2VERR_SetCode();
extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2();
extern int GetD003EC7E0_3452B0();

/* clone */



__attribute__((section(".text.M2V_Destroy")))
void M2V_Destroy(void *a0)
{
    if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(a0)) {
        M2VERR_SetCode(0, 0xFF030201);
        return;
    }
    *(int *)((char *)a0 + 0x0) = 1;
}

/* clone */


__attribute__((section(".text.MWSFSVR_SetMwsfdSvrFlg")))
void MWSFSVR_SetMwsfdSvrFlg(int a0) {
    char *p = GetD003EC7E0_3452B0();
    *(int *)(p + 0x58) = a0;
}

/* clone */


__attribute__((section(".text.MWSTM_IsFsStatErr")))
int MWSTM_IsFsStatErr(void) {
    return func_00328098() == 4;
}
