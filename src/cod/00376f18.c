/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */

typedef struct Trk {
    short vol;
    short a;
    short b;
    short c;
} Trk;

typedef struct Ch {
    unsigned short used;
    short pad02;
    int id;
    short f08;
    short f0A;
    short f0C;
    unsigned char f0E;
    unsigned char f0F;
    short f10;
    short f12;
    short f14;
    short f16;
    int z[8];
    Trk trk[4];
    int f58;
    short f5C;
    short f5E;
    short outL[4];
    short outR[4];
    short f70;
    short f72;
    short f74;
    short f76;
    unsigned int n;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    char pad90[0x10];
} Ch;

typedef struct Rq {
    char pad00[4];
    int id;
    unsigned char f08;
    char pad09[3];
    short idx;
    short pad0E;
    unsigned short f10;
    unsigned short f12;
    unsigned short f14;
    char pad16[6];
    unsigned short f1C;
    short pad1E;
    unsigned short vol[4][4];
    int f40;
    unsigned short f44;
    unsigned short f46;
    unsigned short f48;
    unsigned short f4A;
    char pad4C[4];
    unsigned int n;
    int f54;
    int f58;
    int f5C;
    int f60;
    int f64;
} Rq;

extern Ch D_0076E910[];



__attribute__((section(".text.func_00376F18")))
int func_00376F18(Rq *r)
{
    Ch *c;
    unsigned int i;

    c = &D_0076E910[r->idx];
    if (c->used != 0)
        return -1;
    c->used = 1;
    c->id = r->id;
    c->f08 = r->f10;
    c->f0A = r->f12;
    c->f0C = r->f14;
    c->f0E = r->f08;
    c->f0F = 2;
    c->f10 = 0;
    c->f12 = r->f1C;
    c->f14 = 0;
    c->f16 = 0;
    c->f5C = r->f44;
    c->f5E = r->f46;
    for (i = 0; i < 4; i++) {
        if (i <= (r->n - 1) / 2)
            c->trk[i].vol = r->vol[i][0];
        else
            c->trk[i].vol = 0;
        c->trk[i].a = 0;
        c->trk[i].b = 0;
        c->trk[i].c = 0;
        c->outL[i] = func_003780B0(c->f5C, c->trk[i].vol);
        c->outR[i] = func_003780B0(c->f5E, c->trk[i].vol);
    }
    c->f58 = r->f40;
    c->f70 = r->f48;
    c->f72 = r->f4A;
    c->f74 = 0;
    c->f76 = 0;
    c->n = r->n;
    c->f7C = r->f54;
    c->f80 = r->f58;
    c->f84 = r->f5C;
    c->f88 = r->f60;
    c->f8C = r->f64;
    for (i = 0; i < 8; i++)
        c->z[i] = 0;
    for (i = 0; i < c->n; i++)
        func_00377150(c, &r->f10, i);
    return 0;
}
