/* cygnus-2.96: Sofdec timer step, measures the decode time of one unit (0x3537C0). */
extern void sfmpv_SetSkipTtu(char *h);
extern int SJRBF_GetFlowCnt(char *a0, int a1, int a2);
extern int func_00369FB8(char *a0, char *a1);
extern int sfmpv_ChkMpvErr(char *h, int a1, int a2, int a3);
extern void sfmpv_AddRtotSj(char *h, int a1);
extern void SFPLY_AddSkipPic(char *h, int a1, int a2);

__attribute__((section(".text.sfmpv_SkipFrm")))
int sfmpv_SkipFrm(char *h, char *tm)
{
    char *w;
    char *obj;
    char *sub;
    int start;
    int r;
    int dt;
    int ret;

    w = *(char **)(h + 0x1FC0);
    obj = *(char **)w;
    sfmpv_SetSkipTtu(h);
    start = SJRBF_GetFlowCnt(tm, 0, 1);
    sub = w + 0x8C;
    r = func_00369FB8(obj, tm);
    dt = SJRBF_GetFlowCnt(tm, 0, 1) - start;
    ret = sfmpv_ChkMpvErr(h, r, dt, 0xFF000F07);
    sfmpv_AddRtotSj(h, dt);
    if (ret == 0) {
        if (*(signed char *)(sub + 0x58) == 0) {
            *(int *)(w + 0x16C) = 1;
        }
        SFPLY_AddSkipPic(h, 1, *(int *)(sub + 0x18));
        return 0;
    }
    return ret;
}
