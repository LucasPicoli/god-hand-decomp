/* cygnus-2.96: SFD_TermSupply, error-reports when busy, otherwise switches the current track to state 1. */
extern int Obj34D8_SetGlobalEE0B8_IfField48(char *hn);
extern int func_0034DD70(int a0, int code);
extern int SFBUF_GetTermFlg(char *hn, int id);
extern void SFBUF_SetTermFlg(char *hn, int id, int state);

__attribute__((section(".text.SFD_TermSupply")))
int SFD_TermSupply(char *hn)
{
    int id;

    if (Obj34D8_SetGlobalEE0B8_IfField48(hn) != 0)
        return func_0034DD70(0, 0xFF000135);
    id = *(int *)(hn + 0x1F44);
    if (SFBUF_GetTermFlg(hn, id) == 1)
        return 0;
    SFBUF_SetTermFlg(hn, id, 1);
    *(int *)(hn + 0x44) = 1;
    return 0;
}
