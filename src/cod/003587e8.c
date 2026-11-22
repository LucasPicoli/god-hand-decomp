/* cygnus-2.96 matched TU. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(void *a0);
extern void SFPLY_Stop(void *a0);
extern void SFHDS_FinishFhd(void *a0);
extern void SFBUF_DestroySj(void *a0);
extern int D_003EE2C4[];

__attribute__((section(".text.SFD_Destroy")))
int SFD_Destroy(void *a0) {
    int i;
    int *p;
    int r;
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0)) {
        return func_0034DD70(0, 0xFF000131);
    }
    SFPLY_Stop(a0);
    SFHDS_FinishFhd((char *)a0 + 0x78);
    SFBUF_DestroySj(a0);
    r = sfply_TrDestroy(a0);
    p = D_003EE2C4;
    for (i = 7; i >= 0; i--) {
        if (*p == (int)a0)
            *p = 0;
        p++;
    }
    return r;
}
