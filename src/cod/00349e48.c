/* cygnus-2.96: func_00349E48, one decode step of an active movie handle. */
extern int GetArrayElemA0C_35A1C8(void *hn, int idx);
extern int sfadxt_GetTermDst(void *hn);
extern void func_00349EE8(void *hn);
extern int sfadxt_SupplyData(void *hn, int *out);
extern int sfadxt_ChkPrepFlg(void *hn);
extern void sfadxt_ChkTermFlg(void *hn, int v);
extern void sfadxt_SetAdxtHd(void *hn);
extern void sfadxt_SetSvrFreq(void *hn);
extern void sfadxt_HeadDecCallBack(void *hn);

__attribute__((section(".text.func_00349E48")))
int func_00349E48(void *hn)
{
    int v;
    int ret;

    ret = GetArrayElemA0C_35A1C8(hn, 6);
    if (ret == 0)
        return ret;
    if (sfadxt_GetTermDst(hn) == 1)
        return 0;
    func_00349EE8(hn);
    ret = sfadxt_SupplyData(hn, &v);
    sfadxt_ChkPrepFlg(hn);
    sfadxt_ChkTermFlg(hn, v);
    sfadxt_SetAdxtHd(hn);
    sfadxt_SetSvrFreq(hn);
    sfadxt_HeadDecCallBack(hn);
    return ret;
}
