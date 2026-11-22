/* cygnus-2.96: func_00350718, per-frame movie step: skipped while element 5 is unset or the handle is idle. */
extern int GetArrayElemA0C_35A1C8(char *hn, int i);
extern int sfmpv_GetTermDst(char *hn);
extern void sfmpv_SetCondY16(char *hn);
extern void sfmpv_ProcessAuxShc(char *hn);
extern int sfmpv_DecodeSomePic(char *hn);
extern void sfmpv_ChkPrepFlg(char *hn);
extern void sfmpv_ChkTermFlg(char *hn);

__attribute__((section(".text.func_00350718")))
int func_00350718(char *hn)
{
    int r = GetArrayElemA0C_35A1C8(hn, 5);
    int res;

    if (r == 0)
        return r;
    if (sfmpv_GetTermDst(hn) == 1)
        return 0;
    sfmpv_SetCondY16(hn);
    if (*(int *)(hn + 0x48) == 2)
        sfmpv_ProcessAuxShc(hn);
    res = sfmpv_DecodeSomePic(hn);
    sfmpv_ChkPrepFlg(hn);
    sfmpv_ChkTermFlg(hn);
    return res;
}
