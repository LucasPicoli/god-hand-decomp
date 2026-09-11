/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpc.o :: _slice0 */

#define D3_QWC   (*(volatile unsigned int *)0x1000B020)
#define D4_CHCR  (*(volatile unsigned int *)0x1000B400)
#define D4_QWC   (*(volatile unsigned int *)0x1000B420)
#define IPU_CTRL (*(volatile unsigned int *)0x10002010)
#define IPU_BP   (*(volatile unsigned int *)0x10002020)
#define IPU_TOP  (*(volatile long long *)0x10002030)

typedef struct Blk {
    int f00, f04, f08, f0C, f10, f14, f18, f1C;
} Blk;

extern char D_0045E700[];

extern void _waitIpuIdle(void *s);
extern void func_0039AB98(int h);
extern void _sceMpegStopIpuDma(void);
extern void _sceMpegErrorBdec(void *s);
extern void _doMC(void *s, int f);
extern void func_0039C390(void *s, char *msg);







__attribute__((section(".text.func_0039D7F8")))
int func_0039D7F8(char *s, int nmb)
{
    Blk b;
    int p1[4];
    int p2[4];
    int mba;
    int ninc;
    int v48;
    int v4C;
    int v50;
    long long top;
    unsigned int bp;
    unsigned int k;
    unsigned int v;
    int r;
    int ok;
    int res;
    int rc;

    mba = 0;
    ninc = 0;
    r = func_0039FE78(s, nmb, &mba, &ninc, &b);
    if (r != 0)
        return r;
    *(int *)(s + 0x12C) = 0;
    for (;;) {
        if (mba >= nmb)
            return 0;
        ok = 1;
        *(int *)(s + *(int *)(s + 0x820) * 0x140 + 0x6DC) = 0;
        _waitIpuIdle(s);
        while (D3_QWC != 0 && (IPU_CTRL & 0x4000) == 0) {

                if (D4_QWC == 0 && (D4_CHCR & 0x100) == 0)
                    func_0039AB98(*(int *)(s + 0x868));
                if (*(int *)(s + 0x878) != 0) {
                    _sceMpegStopIpuDma();
                    res = 0;
                    goto skip;
                }

        }
        bp = IPU_BP;
        top = IPU_TOP;
        *(int *)(s + 0x848) = (int)top;
        if (top < 0) {
            k = bp & 0x1F;
            if (k != 0)
                v = 0x20 - k;
            else
                v = 0;
        } else {
            v = 0x20;
        }
        *(int *)(s + 0x84C) = v;
        if ((IPU_CTRL & 0x4000) != 0) {
            _sceMpegErrorBdec(s);
            ok = 0;
        }
        res = ok;
    skip:
        if (res == 0) {
            if (*(int *)(s + 0x878) == 0)
                rc = 2;
            else
                rc = 4;
            return rc;
        }
        if (ninc == 0) {
            if (func_0039EB90(s, 0x17) == 0 || *(int *)(s + 0x12C) != 0) {
                *(int *)(s + 0x12C) = 0;
                return 3;
            }
            ninc = func_0039E648(s);
            if (*(int *)(s + 0x12C) != 0) {
                *(int *)(s + 0x12C) = 0;
                return 1;
            }
        }
        if (mba >= nmb) {
            func_0039C390(s, D_0045E700);
            return 2;
        }
        if (ninc == 1) {
            if (func_0039E0F0(s, &v48, &v4C, &v50, &b, p1, p2) == 0) {
                *(int *)(s + 0x12C) = 0;
                return 1;
            }
        } else {
            if (func_0039ECF8(s, &b, &v4C, p1, &v48) == 0) {
                *(int *)(s + 0x12C) = 0;
                return 2;
            }
        }
        if (func_0039CCC0(s, mba, ninc, v48, v4C, &b, p1, p2) == 0) {
            *(int *)(s + 0x12C) = 0;
            return 2;
        }
        if (mba != 0)
            _doMC(s, *(int *)(s + 0x820) ^ 1);
        mba = mba + 1;
        *(int *)(s + 0x820) = *(int *)(s + 0x820) ^ 1;
        ninc = ninc - 1;
    }
}
