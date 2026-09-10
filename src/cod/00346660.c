/* cygnus-2.96 matched TU. */

typedef struct VT {
    char pad0[0xC];
    void (*fC)(void *p);
    char pad10[0x14];
    int (*f24)(void *p, int n);
} VT;
typedef struct P { VT *vt; } P;
typedef struct S { int f0; int f4; } S;




__attribute__((section(".text.MPV_DecodePicAtr")))
int MPV_DecodePicAtr(void *h, S *s, int *out)
{
    P *p;
    int r;

    p = func_00338B90(s->f0, s->f4);
    if (p == 0) return -1;
    r = func_0036A3E8(h, p);
    *out = s->f4 - p->vt->f24(p, 1);
    p->vt->fC(p);
    return r;
}

__attribute__((section(".text.MWDMA_WaitEnd")))
void MWDMA_WaitEnd(int ch)
{
    void *p;

    p = func_00397100(ch);
    while (func_00397550(p, 1, 0x1E) != 0)
        ;
}
