/* sn-2.95.3-136 matched TU. */

extern int D_003C2388;
extern void *cIDManager_getTexAddr(int a, int b, int c);
extern char D_0041ECC0[];
extern char D_0041ECD8[];
extern char D_0041ED08[];
extern char D_0041ED28[];
extern char D_0041ED48[];
extern void func_002E0DA8(int x, int y, int a2, int a3, char *fmt, ...);
extern void func_002D9458(void *dst, void *src);
extern void func_003A52F0(void *d, int c, int n);
extern void *sceSifAllocIopHeap(int size);
extern int Tramp_sceSifFreeSysMemory_3B5A50(void *p);

/* sn-2.95.3-136 candidate. */

typedef struct Node {
    struct Node *next;
} Node;


extern Node *func_0012CF70(void *mem, void *obj, int flags, float *v1, float *v2,
                           float f12, float f13, char *blob);

__attribute__((section(".text.func_0012E990")))
Node *func_0012E990(char *self, void *obj, int flags, float *v1, float *v2,
                    char *blob, float f12, float f13)
{
    Node *q;
    Node *p;

    if (obj != 0) {
        if (*(Node **)(self + 0x190) != 0) {
            q = *(Node **)(self + 0x190);
            while (q->next != 0) {
                q = q->next;
            }
            p = func_0012CF70(func_0030F550(0x100), obj, flags, v1, v2, f12, f13, blob);
            q->next = p;
            if (p != 0) {
                *(int *)(self + 0x194) = *(int *)(self + 0x194) + 1;
                return q->next;
            }
        } else {
            p = func_0012CF70(func_0030F550(0x100), obj, flags, v1, v2, f12, f13, blob);
            *(Node **)(self + 0x190) = p;
            if (p != 0) {
                *(int *)(self + 0x194) = *(int *)(self + 0x194) + 1;
                return p;
            }
        }
    }
    return 0;
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"



extern void *Gp_draw_polyFT4(void *v, unsigned int col, int n, void *tex,
                             int t0, int t1, void *cfg, int t3, int extra);

static __inline__ void SetVec4(float *d, float x, float y, float z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
    d[3] = 1.0f;
}

__attribute__((section(".text.func_00163C58")))
void func_00163C58(char *self)
{
    char cfg[0x50];
    float v[4][4];
    void *tex;
    void *r;
    char **tbl;
    char *z;
    int i;

    *(int *)(cfg + 0x0) = 1;
    *(float *)(cfg + 0x4) = 1.0f - *(float *)(self + 0x108);
    *(int *)(cfg + 0x8) = 0;
    *(float *)(cfg + 0xC) = 1.0f;
    *(float *)(cfg + 0x10) = *(float *)(self + 0x108);
    z = (char *)v;
    i = 3;
    do {
        VU0_SQC2_VF0(z, 0x0);
        z += 0x10;
    } while (--i != -1);

    tbl = (char **)(self + 0x80);
    tex = cIDManager_getTexAddr(D_003C2388, 7, 4);
    {
    char *e;
    int k;
    float x, y, s;
    k = *(signed char *)(self + 0xF0) + 8;
    k = k * 4;
    e = *(char **)((char *)tbl + k);
    s = *(float *)(self + 0x108);
    x = *(float *)(self + 0x100);
    y = *(float *)(self + 0x104);
    SetVec4(v[0], x - *(float *)(e + 0x68) * s, y, 0.0f);
    SetVec4(v[1], x, y, 0.0f);
    SetVec4(v[2], x - *(float *)(e + 0x68) * s, y + *(float *)(e + 0x6C) * s, 0.0f);
    SetVec4(v[3], x, y + *(float *)(e + 0x6C) * s, 0.0f);
    r = Gp_draw_polyFT4(v, 0x80808080, 1, tex, 0x3800, 0x1CF0, cfg, 6, 5);
    }
    if (r != 0) {
        *(long *)((char *)r + 0x1A0) = 0x3001D;
    }

    *(int *)(cfg + 0x4) = 0;
    *(int *)(cfg + 0x8) = 0;
    *(float *)(cfg + 0xC) = *(float *)(self + 0x118);
    *(float *)(cfg + 0x10) = *(float *)(self + 0x118);
    tex = cIDManager_getTexAddr(D_003C2388, 7, 5);
    {
    char *e;
    int k;
    float x, y, s;
    k = *(signed char *)(self + 0xF0) + 8;
    k = k * 4;
    e = *(char **)((char *)tbl + k);
    x = *(float *)(self + 0x110);
    y = *(float *)(self + 0x114);
    s = *(float *)(self + 0x118);
    SetVec4(v[0], x, y, 0.0f);
    SetVec4(v[1], x + *(float *)(e + 0x68) * s, y, 0.0f);
    SetVec4(v[2], x, y + *(float *)(e + 0x6C) * s, 0.0f);
    SetVec4(v[3], x + *(float *)(e + 0x68) * s, y + *(float *)(e + 0x6C) * s, 0.0f);
    r = Gp_draw_polyFT4(v, 0x80808080, 1, tex, 0x3800, 0x1CF0, cfg, 6, 5);
    }
    if (r != 0) {
        *(long *)((char *)r + 0x1A0) = 0x3001D;
    }
}

/* sn-2.95.3-136 candidate. */

typedef struct Vec {
    float x, y, z, w;
} Vec;

typedef struct Light {
    unsigned short state;
    unsigned short id;
    int f04;
    int pad08[2];
    Vec v10;
    Vec v20;
    Vec v30;
    float f40;
    float f44;
    float f48;
    int f4C[2];
    int f54;
    int f58;
    unsigned short f5C;
    unsigned short f5E;
    unsigned char f60;
    unsigned char f61;
    unsigned short f62;
    int pad64[3];
} Light;

typedef struct World {
    char pad[0x78];
    int count;
    int pad7C;
    Light light[256];
} World;

static __inline__ void VecCopy(Vec *d, Vec *s)
{
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static __inline__ void LightCopy(Light *d, Light *s)
{
    int *dp;
    int *sp;
    int n;

    d->state = s->state;
    d->id = s->id;
    d->f04 = s->f04;
    VecCopy(&d->v10, &s->v10);
    VecCopy(&d->v20, &s->v20);
    VecCopy(&d->v30, &s->v30);
    d->f40 = s->f40;
    d->f44 = s->f44;
    d->f48 = s->f48;
    dp = d->f4C;
    n = 1;
    sp = s->f4C;
    do {
        *dp = *sp;
        sp++;
        dp++;
    } while (--n != -1);
    d->f54 = s->f54;
    d->f58 = s->f58;
    d->f5C = s->f5C;
    d->f5E = s->f5E;
    d->f60 = s->f60;
    d->f61 = s->f61;
    d->f62 = s->f62;
}

__attribute__((section(".text.cWorldLight_Del_LightData")))
void cWorldLight_Del_LightData(World *self, unsigned short id, int key)
{
    int i;
    int k;

    if (id == 0) {
        return;
    }
    for (i = 0; i < 256; i++) {
        char *p = (char *)self + i * 0x70;
        if (*(unsigned short *)(p + 0x80) == 0xFF) {
            continue;
        }
        if (*(unsigned short *)(p + 0x82) != id) {
            continue;
        }
        if (*(int *)(p + 0xD4) != key) {
            continue;
        }
        *(unsigned short *)(p + 0x80) = 0xFF;
        for (k = i; k < 0xFF && self->light[k + 1].state != 0xFF; k++) {
            LightCopy(&self->light[k], &self->light[k + 1]);
            self->light[k + 1].state = 0xFF;
        }
        self->count--;
    }
}

/* sn-2.95.3-136 candidate. */








__attribute__((section(".text.func_00150AA8")))
void func_00150AA8(char *self)
{
    int i;
    char *p;
    unsigned int m;

    func_002E0DA8(0x50, 0x58, 0, 5, D_0041ECC0, *(unsigned short *)(self + 0x3F8A8), 0x1C2);
    func_002E0DA8(0x50, 0x60, 0, 5, D_0041ECD8, *(unsigned char *)(self + 0x3F8AA),
                  *(unsigned char *)(self + 0x3F8AB),
                  *(unsigned char *)(self + 0x3F8AA) + *(unsigned char *)(self + 0x3F8AB), 0x140);
    func_002E0DA8(0x50, 0x70, 0, 5, D_0041ED08, *(int *)(self + 0x3DC60), *(int *)(self + 0x3DC64));
    func_002E0DA8(0x50, 0x78, 0, 5, D_0041ED28, *(int *)(self + 0x3DC78), *(int *)(self + 0x3DC7C));
    func_002E0DA8(0x50, 0x80, 0, 5, D_0041ED48, *(int *)(self + 0x3DC6C), *(int *)(self + 0x3DC70));

    *(int *)(self + 0x34) = 0x2800;
    *(int *)(self + 0x38) = 0x1C20;
    *(unsigned short *)(self + 0x3F8A8) = 0;
    *(int *)(self + 0x3DC60) = 0x2800;
    *(int *)(self + 0x3DC64) = 0x1C20;
    *(int *)(self + 0x3DC6C) = 0x2800;
    *(int *)(self + 0x3DC70) = 0x1C20;
    *(int *)(self + 0x3DC78) = 0x2800;
    *(int *)(self + 0x3DC7C) = 0x1C20;
    *(int *)(self + 0x3C) = 0;
    m = 0xFFFFFFFF;
    for (i = 150; i != 0; i--) {
        *(unsigned int *)(self + 0x3C030 + i * 0x10) = m;
        *(unsigned int *)(self + 0x3C990 + i * 0x10) = m;
        *(unsigned int *)(self + 0x3D2F0 + i * 0x10) = m;
    }
    *(unsigned char *)(self + 0x3F8AA) = 0;
    *(unsigned char *)(self + 0x3F8AB) = 0;
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"

typedef struct {
    short f00;
    short f02;
    int   f04;
    int   f08;
    int   f0C;
    float v0[4];   /* 0x10 */
    float v1[4];   /* 0x20 */
    float v2[4];   /* 0x30 */
    float f40;
    int   f44;
    int   f48;
    int   f4C;
    int   f50;
    int   f54;
    int   f58;
    short f5C;
    short f5E;
    char  f60;
    char  f61;
    short f62;
    int   f64;
    int   f68;
    int   f6C;
} LightData;   /* 0x70 */



extern int cWorldLight_Set_LightData(void *a0, LightData *d);

__attribute__((section(".text.func_002D9778")))
void func_002D9778(char *self)
{
    LightData d __attribute__((aligned(16)));
    float *p;
    float *q;
    float *v;
    int i;

    func_002D9458(self + 0xE8A0, self);
    *(int *)(self + 0x78) = 0;
    func_003A52F0(self + 0x80, 0, 0x7000);
    for (i = 255; i >= 0; i--) {
        *(short *)(self + 0x80 + i * 0x70) = 0xFF;
    }
    v = (float *)(self + 0x40);
    v[0] = 0.45f;
    v[1] = 0.45f;
    v[2] = 0.45f;

    p = d.v0;
    VU0_SQC2_VF0(&d, 0x10);
    VU0_SQC2_VF0(&d, 0x20);
    q = d.v2;
    VU0_SQC2_VF0(&d, 0x30);

    d.f54 = 0;
    d.f04 = 0;
    d.f00 = 1;
    d.f02 = 1;
    *(int *)&p[0] = 0;
    p[1] = 0.4f;
    p[2] = 3.5f;
    p[3] = 1.0f;
    q[0] = 0.5f;
    q[1] = 0.5f;
    q[2] = 0.5f;
    q[3] = 1.0f;
    d.f40 = 0.01f;
    d.f50 = 1;
    d.f58 = 0x87000000;
    d.f44 = 0;
    d.f48 = 0;
    d.f4C = 0;
    cWorldLight_Set_LightData(self, &d);
}

/* sn-2.95.3-136 candidate. */




__attribute__((section(".text.func_002D3388")))
void func_002D3388(char *self)
{
    void **buf;
    int i;
    int n;
    int fail;
    void *p;
    int k;

    n = 0;
    *(int *)(self + 0x78) = 0;
    *(int *)(self + 0x7C) = *(int *)(self + 0x74);
    *(int *)(self + 0x8C) = 0;
    *(int *)(self + 0x90) = 0;
    buf = (void **)(self + 0x84);
    for (i = 0; i < 2; i++) {
        ((int *)buf)[i - 0x1D] = 0;
        buf[i] = 0;
    }
    do {
        fail = 0;
        *(int *)(self + 0x68) = 0x20000 >> n;
        n++;
        i = 0;
    again:
        p = sceSifAllocIopHeap(*(int *)(self + 0x68));
        k = i * 4;
        *(void **)((char *)buf + k) = p;
        if (p == 0) {
            fail = 1;
            for (i = 0; i < 2; i++) {
                if (buf[i] != 0) {
                    Tramp_sceSifFreeSysMemory_3B5A50(buf[i]);
                }
                buf[i] = 0;
            }
        } else {
            i++;
            if (i < 2) {
                goto again;
            }
        }
    } while (fail);
    *(int *)(self + 0x0) |= 2;
}
