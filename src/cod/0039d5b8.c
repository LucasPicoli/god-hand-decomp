/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpc.o :: _sceMpegPictureData0 */

#define D3_QWC   (*(volatile unsigned int *)0x1000B020)
#define D4_CHCR  (*(volatile unsigned int *)0x1000B400)
#define D4_QWC   (*(volatile unsigned int *)0x1000B420)
#define D9_CHCR  (*(volatile unsigned int *)0x1000D400)
#define IPU_CTRL (*(volatile unsigned int *)0x10002010)
#define IPU_BP   (*(volatile unsigned int *)0x10002020)
#define IPU_TOP  (*(volatile long long *)0x10002030)

extern char D_0045E6E0[];

extern void _waitIpuIdle(void *s);
extern void func_0039AB98(int h);
extern void _sceMpegStopIpuDma(void);
extern void _sceMpegErrorBdec(void *s);
extern void _doMC(void *s, int f);
extern void func_0039C390(void *s, char *msg);

__attribute__((section(".text.func_0039D5B8")))
int func_0039D5B8(char *s)
{
    long long top;
    unsigned int bp;
    unsigned int k;
    int n;
    int r;
    int ok;
    int res;
    unsigned int v;

    *(int *)(s + 0x820) = 0;
    *(int *)(s + 0x824) = 0;
    n = *(int *)(s + 0x13C) * *(int *)(s + 0x140);
    if (*(int *)(s + 0x184) != 3)
        n = n >> 1;
    do {
        r = func_0039D7F8(s, n);
    } while (r == 1 || r == 3);
    ok = 1;
    _waitIpuIdle(s);
    _waitIpuIdle(s);
    if (D3_QWC != 0 && (IPU_CTRL & 0x4000) == 0) {
        do {
            if (D4_QWC == 0 && (D4_CHCR & 0x100) == 0)
                func_0039AB98(*(int *)(s + 0x868));
            if (*(int *)(s + 0x878) != 0) {
                _sceMpegStopIpuDma();
                res = 0;
                goto skip;
            }
        } while (D3_QWC != 0 && (IPU_CTRL & 0x4000) == 0);
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
        if (*(int *)(s + 0x878) != 0)
            return 4;
        r = 2;
    }
    while (((D9_CHCR >> 8) & 1) != 0)
        ;
    if (r == 0)
        _doMC(s, *(int *)(s + 0x820) == 0);
    if ((unsigned int)(r - 1) < 2)
        func_0039C390(s, D_0045E6E0);
    return (unsigned int)r < 1;
}
