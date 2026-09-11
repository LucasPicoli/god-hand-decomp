/* cygnus-2.96 matched TU. */

typedef struct Hdr {
    int f0;
    void *f4;
    unsigned int f8;
    int fC;
} Hdr;

extern char D_00459C28[];
extern int Obj35D0_IsField0Zero_D7A8(Hdr *h);



__attribute__((section(".text.SFH_IsSfdHeader")))
int SFH_IsSfdHeader(Hdr *h, int *out)
{
    int n;
    int m;
    char *p;

    *out = 0;
    p = (char *)h->f4 + 0x20;
    if (Obj35D0_IsField0Zero_D7A8(h) == 1) return 0;
    if (h->f8 < 0x800) {
        h->f0 = -1;
        return 0;
    }
    if (func_003A50B4(p, D_00459C28, 0x18) != 0) {
        h->f0 = -1;
        return 0;
    }
    h->f0 = 2;
    if (func_0035DB38(h, &n, &m) == 0) return 0;
    h->fC = n * 100 + m;
    *out = 1;
    return 1;
}
