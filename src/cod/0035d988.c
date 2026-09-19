/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct Hdr { int f0; void *f4; unsigned int f8; int fC; } Hdr;


extern void *getElemInfPtr(Hdr *h, int id);
extern int isEnableAudFtr(int id, void *p);
extern int isEnableVidFtr(int id, void *p);

__attribute__((section(".text.SFH_IsEffFtrInf")))
int SFH_IsEffFtrInf(Hdr *h, int id, int *out)
{
    int b;
    void *p;
    int kind;

    b = id & 0xFF;
    if (h->fC < 0x6E) return 0;
    kind = func_0035E9E8(b);
    switch (kind) {
    case 0xC0:
        p = getElemInfPtr(h, b);
        if (p == 0) return 0;
        *out = isEnableAudFtr(b, p);
        break;
    case 0xE0:
        p = getElemInfPtr(h, b);
        if (p == 0) return 0;
        *out = isEnableVidFtr(b, p);
        break;
    default:
        return 0;
    }
    return 1;
}
