/* cygnus-2.96 matched TU. */

extern void *GetD003EC7E0_3452B0();

__attribute__((section(".text.MWSFD_GetUsePicUsr")))
int MWSFD_GetUsePicUsr(int a0) {
    int *p = GetD003EC7E0_3452B0(a0);
    return *(int *)((char *)p + 0x38);
}

__attribute__((section(".text.MWSFD_GetPauseBdr")))
int MWSFD_GetPauseBdr(int a0) {
    int *p = GetD003EC7E0_3452B0(a0);
    return *(int *)((char *)p + 0x3C);
}

__attribute__((section(".text.MWSFD_GetReqSvrBdrLib")))
int MWSFD_GetReqSvrBdrLib(int a0) {
    int *p = GetD003EC7E0_3452B0(a0);
    return *(int *)((char *)p + 0x24);
}

__attribute__((section(".text.Forward328098_349B88")))
void Forward328098_349B88(void) { func_00328098(); }

__attribute__((section(".text.func_0034D068")))
void func_0034D068(void) { SFH_Finish(); }
