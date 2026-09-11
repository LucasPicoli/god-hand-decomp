/* cygnus-2.96 matched TU. */

extern int GetArrayElemA0C_35A1C8(void *hn, int id);
extern void func_0034FA28(void *hn, int *na, int *nv);

__attribute__((section(".text.sfmps_AutoVchPlay")))
int sfmps_AutoVchPlay(void *hn, int vch)
{
    int na;
    int nv;
    int cond;

    cond = GetArrayElemA0C_35A1C8(hn, 0x3B);
    if (cond == 1) return vch;
    if (cond < 2) return vch;
    if (cond != 2) goto ret_vch;
    func_0034FA28(hn, &na, &nv);
    if (nv >= 2) return cond;
    return vch;
ret_vch:
    return vch;
}
