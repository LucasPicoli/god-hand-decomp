/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct {
    unsigned char pad0[0x114];
    int f114;
} SfSrc;

typedef struct {
    unsigned char pad0[0x10];
    int f10;
} SfPic;

extern int func_0036A1D8(int h, unsigned int *rate);                 /* MPV_GetBitRate */
extern int func_0034DD70(void *hn, int code);                        /* SFLIB_SetErr */
extern void func_0036A238(int h, int *a, int *b, int *c);            /* MPV_GetVbvBufSiz */
extern int GetArrayElemA0C_35A1C8(void *hn, int idx);                /* SFSET_GetCond */
extern int func_0034C7B0(void *hn, int f);                           /* SFBUF_GetRingBufSiz */
extern void func_00352F40(void *hn, int rate, void *para);           /* sfmpv_SetMpvHd */
extern void func_00353060(void *pa, int rate, int a2, int vbv);      /* sfmpv_SetMvInf */
extern int func_00353098(void *hn, void *pa);                        /* sfmpv_ChkBufSiz */

__attribute__((section(".text.func_00352E10")))
int func_00352E10(char *hn, int h, int a2, void *para)
{
    unsigned int rate;
    int vbv;
    int b;
    int c;
    SfPic *pa = (SfPic *) (hn + 0x90C);
    SfSrc *src;
    int sz;
    int v;

    src = *(SfSrc **) (hn + 0x1FC0);
    if (pa->f10 != 0)
        return 0;
    if (func_0036A1D8(h, &rate) != 0)
        return func_0034DD70(hn, 0xFF000F16);
    func_0036A238(h, &vbv, &b, &c);
    if (GetArrayElemA0C_35A1C8(hn, 0x3C) == 0) {
        src->f114 = 0;
    } else {
        sz = func_0034C7B0(hn, 1);
        if (c == -1)
            c = vbv;
        src->f114 = c < sz ? c : sz;
    }
    func_00352F40(hn, rate, para);
    func_00353060(pa, rate, a2, vbv);
    return func_00353098(hn, pa);
}
