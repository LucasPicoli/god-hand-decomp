/* sn-2.95.3-136: texture TEX0 / MIPTBP1-2 setup and per-level upload (0x3092E0). */
typedef struct GsTex0 {
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long TCC : 1;
    unsigned long TFX : 2;
    unsigned long CBP : 14;
    unsigned long CPSM : 4;
    unsigned long CSM : 1;
    unsigned long CSA : 5;
    unsigned long CLD : 3;
} GsTex0;

typedef struct TexHdr {
    char pad00[0xC];
    unsigned short dataOfs;     /* 0x0C */
    char pad0E[0x11 - 0xE];
    unsigned char nlevels;      /* 0x11 */
    char pad12;
    unsigned char fmt;          /* 0x13 */
    unsigned short w;           /* 0x14 */
    unsigned short h;           /* 0x16 */
    GsTex0 tex0;                /* 0x18 */
    char pad20[0x30 - 0x20];
    unsigned long mip1;         /* 0x30 */
    unsigned long mip2;         /* 0x38 */
    int mipOfs[1];              /* 0x40 */
} TexHdr;

extern int D_004501D0[];
extern int func_00309C30(unsigned int psm, int w);
extern void func_003099D8(int psm, int tbp, int tbw, int w, int h, char *data);
extern int func_00309CA0(int psm, int w, int h);

__attribute__((section(".text.func_003092E0")))
int func_003092E0(TexHdr *t, int tbp)
{
    int psm;
    int w;
    int h;
    int tbw;
    int i;
    char *data;

    if (t->nlevels) {
        psm = D_004501D0[t->fmt - 1];
        w = t->w;
        h = t->h;
        data = (char *)t + t->dataOfs;
        t->tex0.PSM = psm;
        tbw = func_00309C30(psm, w);
        t->tex0.TBP0 = tbp;
        t->tex0.TBW = tbw;
        t->tex0.TCC = 1;
        func_003099D8(psm, tbp, tbw, w, h, data);
        tbp += func_00309CA0(psm, w, h);
        if (t->nlevels >= 2) {
            unsigned long *mip = &t->mip1;

            data = (char *)t + t->dataOfs;
            for (i = 1; i < t->nlevels; i++) {
                w /= 2;
                h /= 2;
                data += t->mipOfs[i - 1];
                tbw = func_00309C30(psm, w);
                if (i < 4)
                    mip[0] = mip[0] | ((unsigned long)(unsigned int)tbp << ((i - 1) * 20)) | ((unsigned long)tbw << ((i - 1) * 20 + 14));
                else
                    mip[1] = mip[1] | ((unsigned long)(unsigned int)tbp << ((i - 4) * 20)) | ((unsigned long)tbw << ((i - 4) * 20 + 14));
                func_003099D8(psm, tbp, tbw, w, h, data);
                tbp += func_00309CA0(psm, w, h);
            }
        }
    }
    return tbp;
}
