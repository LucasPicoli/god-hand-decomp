/* cygnus-2.96: Sofdec transfer build, video/audio/user streams (0x35BEF0). */
extern void sftrn_ConnBufTrn(char *a0, int a1, int a2);
extern void Obj35C0_Set_a1_0_a2_C160(char *a0, int a1, int a2);
extern int sftrn_BuildVideo(char *h, char *s);
extern void SFSET_SetCond(char *a0, int a1, int a2);
extern void sftrn_ConnTrnBufA(char *a0, int a1, int a2);
extern void sftrn_BuildAudio(char *h, char *s);
extern void sftrn_ConnTrnBufU(char *a0, int a1, int a2);
extern void sftrn_BuildUsr(char *h, char *s);

__attribute__((section(".text.sftrn_BuildSystem")))
void sftrn_BuildSystem(char *h, char *s)
{
    sftrn_ConnBufTrn(h, 0, 1);
    if (*(void **)(s + 0x8) != 0) {
        Obj35C0_Set_a1_0_a2_C160(h, 1, 1);
        sftrn_BuildVideo(h, s);
    } else {
        SFSET_SetCond(h, 5, 0);
        *(int *)(h + 0xBB0) = 0;
    }
    if (*(void **)(s + 0xC) != 0) {
        sftrn_ConnTrnBufA(h, 1, 2);
        sftrn_BuildAudio(h, s);
    } else {
        SFSET_SetCond(h, 6, 0);
        *(int *)(h + 0xBB4) = 0;
    }
    if (*(int *)(s + 0x20) != 0) {
        sftrn_ConnTrnBufU(h, 1, 7);
        sftrn_BuildUsr(h, s);
    }
}
