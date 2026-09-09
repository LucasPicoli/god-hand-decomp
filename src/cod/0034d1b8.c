/* cygnus-2.96 matched TU. */

extern void *SFH_Create(void *buf, int size);
extern int SFH_IsSfdHeader(void *h, int *out);
extern void SFH_Destroy(void *h);
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *hn);
extern void func_0034DD70(void *a0, unsigned int err);
extern void func_0035C2D0(void *hn, int a1, int a2, void *a3, int a4);

__attribute__((section(".text.SFHDS_IsSfdHeader")))
int SFHDS_IsSfdHeader(void *buf, int size)
{
    int r;
    void *h;

    h = SFH_Create(buf, size);
    if (h == 0) return 0;
    if (SFH_IsSfdHeader(h, &r) == 0) r = 0;
    SFH_Destroy(h);
    return r;
}

__attribute__((section(".text.SFD_AddWritePtr")))
void SFD_AddWritePtr(void *hn, void *p, int n)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(hn) != 0) {
        func_0034DD70(0, 0xFF000135);
        return;
    }
    func_0035C2D0(hn, 0, 0xA, p, n);
}
