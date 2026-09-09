/* cygnus-2.96 matched TU. */

extern int SFH_IsExistStmId(void *h, unsigned char id, int *out);
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *hn);
extern void func_0034DD70(void *p, unsigned int err);
extern void func_0035AAC8(void *hn, void *a1, void *a2);

__attribute__((section(".text.sfhds_AnlyUsedStmid")))
int sfhds_AnlyUsedStmid(void *h, int from, int to)
{
    int exist;
    int i;

    for (i = from; i <= to; i++) {
        if (SFH_IsExistStmId(h, i, &exist) != 0) {
            if (exist != 0) return i;
        }
    }
    return 0;
}

__attribute__((section(".text.SFD_GetTime")))
void SFD_GetTime(void *hn, void *a1, void *a2)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(hn) != 0) {
        func_0034DD70(0, 0xFF000121);
        return;
    }
    func_0035AAC8(hn, a1, a2);
}
