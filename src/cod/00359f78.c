/* cygnus-2.96: sfset_SetCondAll, run SFSET_SetCond(hn, ...) on every handle that is not busy. */
extern void *D_003EE2C4[8];
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *hn);
extern void SFSET_SetCond(void *hn, int a0, int a1);

__attribute__((section(".text.sfset_SetCondAll")))
void sfset_SetCondAll(int a0, int a1)
{
    int i;
    void *hn;

    for (i = 0; i < 8; i++) {
        hn = D_003EE2C4[i];
        if (Obj34D8_SetGlobalEE0B8_IfField48(hn) == 0)
            SFSET_SetCond(hn, a0, a1);
    }
}
