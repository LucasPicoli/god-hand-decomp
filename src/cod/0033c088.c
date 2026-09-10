/* cygnus-2.96 matched TU. */

typedef struct OBJ OBJ;
struct OVT {
    char pad0[0x14];
    void (*f14)(OBJ *);
    void (*f18)(OBJ *, int, int, void *);
    void (*f1C)(OBJ *, int, void *);
    char pad20[4];
    int (*f24)(OBJ *, int);
};
struct OBJ { struct OVT *vt; };
struct SJI { char *p; int len; int f8; int fC; };
struct AMP {
    char f0;
    char f1;
    signed char f2;
    char f3;
    OBJ *f4[2];
    OBJ *fC[2];
    int f14[6];
    int f2C;
};



__attribute__((section(".text.func_0033C088")))
void func_0033C088(struct AMP *amp)
{
    struct SJI buf;
    int i;
    OBJ *o;
    int n;

    for (i = 0; i < amp->f2; i++) {
        amp->f14[i] = 0;
    }
    amp->f2C = 0;
    {
        for (i = 0; i < amp->f2; i++) {
            o = amp->f4[i];
            o->vt->f14(o);
            n = o->vt->f24(o, 0);
            o->vt->f18(o, 0, n, &buf);
            func_003A52F0(buf.p, 0, buf.len);
            o->vt->f1C(o, 0, &buf);
        }
    }
    {
        for (i = 0; i < amp->f2; i++) {
            o = amp->fC[i];
            o->vt->f14(o);
            n = o->vt->f24(o, 0);
            o->vt->f18(o, 0, n, &buf);
            func_003A52F0(buf.p, 0, buf.len);
            o->vt->f1C(o, 0, &buf);
        }
    }
    amp->f1 = 2;
}
