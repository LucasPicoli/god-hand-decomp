/* sn-2.95.3-136: func_002D3D88, movie player setup: allocate the decoder work, the two stream buffers and
 * the output image, create the player, and attach the effect buffer when the high flag bit is set. */
#include "godhand/heapArena.h"
#include "godhand/criStm.h"
#include "godhand/cMovie.h"
typedef struct {
    int size;
    int f4;
    int f8;
    short fC;
    short fE;
    char f10;
    char f11;
    char f12;
    char f13;
    short w;
    short h;
    long tex0;
    long f20;
    int f28;
    int f2C;
} MovieImg;

typedef struct {
    char name[4];
    char f4;
    char f5;
    short f6;
    char pad8[8];
    MovieImg img;
} MovieImgHdr;

extern char D_0044D188[];
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *region);
extern void func_003A5DA0(void *dst, void *src, int n);
extern int mwPlyCalcWorkCprmSfd(void *cp);
extern void func_003B0640(void *start, void *end);
extern void func_002D45B0(cMovieTrack *p, int i);
extern int func_00309C30(unsigned int a, int w);
extern int func_00309D40(int n);
extern int func_00343E28(int *cp);
extern int mwPlyFxSetLumiPrm(void *h, int a, int b, int c);
extern void Obj3260_Tramp_00337C00_D1F0(void);
extern int func_003481D8(void);
extern int Forward3428A0_342870(int a0, int a1, int a2);

__attribute__((section(".text.func_002D3D88")))
int func_002D3D88(cMovieTrack *p)
{
    int cp[12];
    int n;
    void *fx;

    func_003A52F0(cp, 0, 0x30);
    cp[8] = p->f28;
    cp[0] = p->f2C;
    cp[1] = p->f34;
    cp[2] = p->w;
    cp[3] = p->h;
    cp[4] = p->f38;
    cp[5] = 1;
    cp[9] = p->f30;
    cp[7] = mwPlyCalcWorkCprmSfd(cp);
    cp[6] = 0;
    p->work = EnsureInitThenForward_2A9538_30EE08(0x90, 0x80, D_003C3CF0);
    if (p->work == 0) {
        ResHolder_release(p);
        return 0;
    }
    func_003A52F0(p->work, 0, 0x90);
    if (p->flags & MOVIE_TRACK_STREAM) {
        int i;
        int size = ((p->w * 6 / 16 + 38) / 16) << 8;

        for (i = 0; i < 2; i++) {
            p->stm[i] = EnsureInitThenForward_2A9538_30EE08(size, 0x80, D_003C3CF0);
            if (p->stm[i] == 0) {
                ResHolder_release(p);
                return 0;
            }
            func_003B0640(p->stm[i], (char *)p->stm[i] + size - 1);
        }
        func_002D45B0(p, 0);
        func_002D45B0(p, 1);
    }
    if (p->flags & MOVIE_TRACK_TEXIMG) {
        MovieImgHdr *q;
        MovieImg *im;
        int a, b, c;

        q = EnsureInitThenForward_2A9538_30EE08(p->w * p->h * 4 + 0x40, 0x80, D_003C3CF0);
        p->img = q;
        func_003A5DA0(q, D_0044D188, 4);
        im = &q->img;
        q->f4 = 4;
        q->f5 = 0;
        q->f6 = 1;
        im->size = p->w * p->h * 4 + 0x30;
        im->f4 = 0;
        im->f8 = p->w * p->h * 4;
        im->fC = 0x30;
        im->f13 = 3;
        im->f11 = 1;
        im->fE = 0;
        im->f10 = 0;
        im->f12 = 0;
        im->w = p->w;
        im->h = p->h;
        a = func_00309C30(0, p->w);
        b = func_00309D40(p->w);
        c = func_00309D40(p->h);
        im->f28 = 0;
        im->f20 = 0x60;
        im->tex0 = ((long)a << 14) | ((long)b << 26) | ((long)c << 30) | (1L << 34);
        im->f2C = 0;
    } else if ((p->flags & MOVIE_TRACK_IMAGE) || p->f30 == 1) {
        p->img = EnsureInitThenForward_2A9538_30EE08(p->w * p->h * 4, 0x80, D_003C3CF0);
    } else {
        p->img = 0;
    }
    p->cell18 = 0;
    p->handle = func_00343E28(cp);
    if (p->handle == 0) {
        ResHolder_release(p);
        return 0;
    }
    if (p->f28 == 0x31)
        mwPlyFxSetLumiPrm((void *)p->handle, p->lumi0, p->lumi1, (p->flags >> 4) & 1);
    if (p->flags < 0) {
        Obj3260_Tramp_00337C00_D1F0();
        n = func_003481D8();
        fx = EnsureInitThenForward_2A9538_30EE08(n, 0x80, D_003C3CF0);
        p->fxbuf = fx;
        if (fx == 0)
            return 1;
        Forward3428A0_342870(p->handle, (int)fx, n);
    }
    return 1;
}
