/* cygnus-2.96 matched TU. */

extern const char D_00454458[];
extern void Forward33B658_3389F8(void);
extern void Forward33B670_338A10(void);

struct DVCI { char pad0[8]; int f8; int fC; char pad10[4]; int f14; };



__attribute__((section(".text.dvCiSeek")))
int dvCiSeek(struct DVCI *hn, int off, int whence)
{
    int pos, len;
    if (hn == 0) {
        func_00332808(hn, D_00454458);
        return 0;
    }
    if (whence == 0) hn->fC = off;
    else if (whence == 2) hn->fC = hn->f8 + off;
    else if (whence == 1) hn->fC = hn->fC + off;
    len = hn->f8;
    pos = hn->fC;
    hn->f14 = 0;
    if (pos >= len) pos = len;
    if (pos < 0) pos = 0;
    hn->fC = pos;
    return pos;
}

typedef struct O O;
struct OVT { char pad[0x20]; void (*f20)(O *, int, void *); };
struct O { struct OVT *vt; };
struct H2 { char pad[4]; O *f4; };
struct E { signed char f0; signed char f1; char pad2[2]; struct H2 *f4; char f8[8]; };
struct SJX { int n; char pad[0xC]; struct E e[1]; };




__attribute__((section(".text.func_0033B050")))
void func_0033B050(void *unused, struct SJX *p)
{
    int i, n;
    if (p == 0) for (;;) ;
    n = p->n;
    Forward33B658_3389F8();
    for (i = 0; i < n; i++) {
        struct E *e = &p->e[i];
        if (e->f0 == 0) {
            O *o = e->f4->f4;
            o->vt->f20(o, e->f1, e->f8);
        }
    }
    Forward33B670_338A10();
}
