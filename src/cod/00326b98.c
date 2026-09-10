/* cygnus-2.96 matched TU. */

extern struct SJXE D_003E8DE8[0x20];
extern void Forward33B658_3389F8(void);
extern void Forward33B670_338A10(void);
extern int D_007561C0[];
extern int D_007562C0[];
extern char D_003D8D40[];
extern void Forward33B568_33B658(void);
extern void Forward33B5C8_33B670(void);
extern int GetField_F_33CE80(int h);

typedef struct T8 { char b[8]; } T8;
struct SJVT { char pad[0x18]; int (*f18)(void *, int, int, void *); };
struct SJ { struct SJVT *vt; };
struct SJXE { signed char f0; char f1; short f2; struct SJ *f4; int f8; int fC; int f10; };
struct ENT { char f0; char f1; short f2; int f4; char f8[8]; };





__attribute__((section(".text.func_0033B0F0")))
void func_0033B0F0(void *unused, int *out)
{
    char buf[0x10];
    struct SJXE *e;
    int base = (int)out + 0x10;
    struct ENT *q;
    int w;
    int n = 0;
    int i;

    Forward33B658_3389F8();
    for (i = 0, e = D_003E8DE8; i < 0x20; e++) {
        if (e->f0 != 1) { i++; continue; }
        q = (struct ENT *)(n * 0x10 + base);
        for (;;) {
            struct SJ *sj;
            if (n == 0x80) goto done;
            sj = e->f4;
            sj->vt->f18(sj, e->fC, 0x7FFFFFFF, buf);
            if (*(int *)(buf + 4) == 0) break;
            q->f0 = 0;
            n++;
            w = e->f10;
            q->f1 = e->fC;
            q->f4 = w;
            do { } while (0);
            q->f2 = e->f2;
            *(T8 *)q->f8 = *(T8 *)buf;
            q++;
        }
        i++;
    }
done:
    Forward33B670_338A10();
    *out = n;
}

__attribute__((section(".text.DTX_CallUrpc")))
int DTX_CallUrpc(int cmd, int *in, int nin, int *out, int nout)
{
    int i;

    Forward33B568_33B658();
    for (i = 0; i < nin; i++) D_007561C0[i] = in[i];
    func_003B3128(D_003D8D40, cmd + 0x400, 0, D_007561C0, nin * 4,
                  D_007562C0, nout * 4, 0, 0);
    for (i = 0; i < nout; i++) out[i] = D_007562C0[i];
    Forward33B5C8_33B670();
    return D_007562C0[0];
}

typedef struct OBJ OBJ;
struct OVT { char pad[0x18]; void (*f18)(OBJ *, int, int, void *); };
struct OBJ { struct OVT *vt; };
struct S {
    int f0;
    int f4;
    int f8;
    OBJ *fC[4];
    int f1C;
    int f20;
    int f24, f28, f2C, f30, f34, f38;
    int f3C;
    int f40;
};





__attribute__((section(".text.adxsjd_get_wr")))
int adxsjd_get_wr(struct S *p, int *o1, int *o2, int *o3)
{
    int i = 0;
    OBJ *sj0 = p->fC[0];
    int *r = &p->f1C;
    OBJ **q = p->fC;
    OBJ *o;
    int t, u;

    while (i < func_0033CE98(p->f4)) {
        o = *q;
        q++;
        o->vt->f18(o, 0, 0x4000, r);
        r += 2;
        i++;
    }
    *o1 = (p->f1C - func_00339FF8(sj0)) / 2;
    t = p->f20 / 2;
    u = p->f38;
    if (t < u) u = t;
    *o2 = u;
    if (p->f3C >= 0) *o3 = p->f3C - p->f40;
    else *o3 = 0x1FFFFFFF;
    return GetField_F_33CE80(p->f4);
}
