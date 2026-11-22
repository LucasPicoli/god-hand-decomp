/* cygnus-2.96: mwlSfdExecDecSvrPrep, clear the pending flag at +0x1AC once acknowledged, step, and set state 2
 * when the sound at +0x3C reports 4 or 6. */
extern int func_00348FF0(char *self);
extern void mwsfsvr_StartPlayback(char *self);
extern int SFD_GetHnStat(int snd);

__attribute__((section(".text.mwlSfdExecDecSvrPrep")))
void mwlSfdExecDecSvrPrep(char *self)
{
    int pending = *(int *)(self + 0x1AC);
    int snd = *(int *)(self + 0x3C);
    int st;

    if (pending == 1 && func_00348FF0(self) == pending)
        *(int *)(self + 0x1AC) = 0;
    mwsfsvr_StartPlayback(self);
    st = SFD_GetHnStat(snd);
    if (st == 4 || st == 6)
        *(int *)(self + 0x4) = 2;
}
