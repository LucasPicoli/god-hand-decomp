#include "godhand/cModel.h"

/* sn-2.95.3-136 matched TU. */

extern int PostInc_D_00566E10_0015B0F0_15B0F0(int a0);
extern void func_00155BE8(void *this, int flag, int bit);
extern void func_00155C68(void *a0, void *a1, int a2);
extern void func_0031A600(void *a0, int a1, int a2, int a3);
extern void func_0031A650(void *a0, int a1, int a2, int a3, int t0);
extern void func_0030A548(void *dst, void *src);
extern void sceVu0UnitMatrix(void *m);
extern int D_007476B0;
extern unsigned char D_00754C80[];
extern float D_003BD860[];
extern float D_003BD870[];
extern float D_003BD880[];
extern float D_003BD890[];
extern char D_004A6940[];
extern void sceVu0ApplyMatrix(void *dst, void *m, void *v);
extern void Draw_Line2(void *pts, int n, unsigned color, int flag);
extern void ClearFields_4_8_C_E_159998(int a0);
extern void func_001599B0(void *a0, void *a1, void *a2);

typedef struct { unsigned long lo; int w2; int w3; } Q;
typedef int TI __attribute__((mode(TI)));

#define CP4B(d, s) { float *dp = (d); int k = 3; float *sp_ = (s); for (; k != -1; k--) *dp++ = *sp_++; }
#define CP4(d, s) { float *dp = (d); float *sp_ = (s); int k; for (k = 3; k != -1; k--) *dp++ = *sp_++; }

/* Build the 0x120 byte display list that draws one mesh node's colour pass:
 * a DMA header, light and colour matrices, the node's uv scroll as a
 * translation, and two empty tags that func_00155C68 patches. Then queue it
 * under the model's draw kind. A late-sorted model uses draw flag 0x14. */
__attribute__((section(".text.func_0014B9A0")))
void func_0014B9A0(cModel *self, cModelNode *node, short id)
{
    char *w;
    char *pkt;
    char *m;
    char *v8;
    char *v9;
    char *vC;
    char *vD;
    int bit;
    int flag;
    float tmp[4] __attribute__((aligned(16)));
    float vec[4] __attribute__((aligned(16)));
    float one;
    int st;
    int flags;

    bit = D_007476B0 & 1;
    flag = 2;
    if (self->objFlags & CMODEL_F_LATE) flag = 0x14;
    func_00155BE8(self, flag, bit);
    w = (char *)PostInc_D_00566E10_0015B0F0_15B0F0(0x120);
    pkt = w;
    if (w == 0) return;
    ((cQuad *)w)->w2 = 0;
    ((cQuad *)w)->lo = 0x1000000D;
    ((cQuad *)w)->w3 = 0;
    w += 0x10;
    ((cModelPktTail *)w)->unk00 = 0;
    ((cModelPktTail *)w)->unk04 = 0;
    ((cModelPktTail *)w)->vif = 0x01000404;
    ((cModelPktTail *)w)->unk0C = 0x6C0C00C8;
    CP4((float *)(w + 0x10), D_003BD860)
    CP4B((float *)(w + 0x20), D_003BD870)
    CP4((float *)(w + 0x30), D_003BD870)
    CP4B((float *)(w + 0x40), D_003BD880)
    CP4B((float *)(w + 0x50), D_003BD880)
    CP4B((float *)(w + 0x60), D_003BD880)
    CP4((float *)(w + 0x70), D_003BD880)
    CP4((float *)(w + 0x80), D_003BD890)
    m = w + 0x90;
    *(float *)(w + 0x2C) = 255.0f;
    func_0030A548(m, D_004A6940);
    sceVu0UnitMatrix(m);
    one = 1.0f;
    vec[0] = node->uvScroll[0];
    vec[1] = node->uvScroll[1];
    vec[3] = one;
    vec[2] = 0.0f;
    *(TI *)tmp = *(TI *)vec;
    CP4B((float *)(w + 0xC0), tmp)
    w += 0xD0;
    vD = w;
    ((cQuad *)w)->lo = 0x10000000; ((cQuad *)w)->w2 = 0; ((cQuad *)w)->w3 = 0;
    w += 0x10;
    ((cQuad *)w)->lo = 0x10000000; ((cQuad *)w)->w2 = 0; ((cQuad *)w)->w3 = 0;
    vC = w;
    w += 0x10;
    ((cQuad *)w)->lo = *(unsigned long *)(node->packet[bit] + 0x90); ((cQuad *)w)->w2 = 0; ((cQuad *)w)->w3 = 0;
    w += 0x10;
    ((cQuad *)w)->lo = 0; ((cQuad *)w)->w2 = 0; ((cQuad *)w)->w3 = 0;
    func_00155C68(vD, vC, flag);
    st = self->drawKind;
    flags = node->dispFlags;
    if (st == CMODEL_KIND_PER_NODE) {
        if ((flags & CMODEL_NODE_SORTED) != 0) {
            if (w == 0) func_0031A600(D_00754C80, 2, id, (int)pkt);
            else func_0031A650(D_00754C80, 2, id, (int)pkt, (int)w);
        } else {
            if (w == 0) func_0031A600(D_00754C80, 1, 0xD, (int)pkt);
            else func_0031A650(D_00754C80, 1, 0xD, (int)pkt, (int)w);
        }
    } else {
        if (w == 0) func_0031A600(D_00754C80, st, self->id, (int)pkt);
        else func_0031A650(D_00754C80, st, self->id, (int)pkt, (int)w);
    }
}

#include "godhand/vu0.h"

static __inline__ void CV3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

#define XF(x, y, z) \
    *(float *)(f + 0x30) = (x); *(float *)(f + 0x34) = (y); *(float *)(f + 0x38) = (z); \
    *(float *)(v + 0xC) = one; \
    VU0_LQC2(4, v, 0); VU0_SQC2(4, f, 0x40); \
    sceVu0ApplyMatrix(w, m, w); \
    VU0_LQC2(4, w, 0); VU0_SQC2(4, f, 0x20);

#define P0() CV3((float *)f, (float *)(f + 0x20));
#define P1(col) \
    *(float *)(f + 0x10) = *(float *)(f + 0x20); \
    *(float *)(f + 0x14) = *(float *)(f + 0x24); \
    *(float *)(f + 0x18) = *(float *)(f + 0x28); \
    Draw_Line2(f, 2, col, 1);

__attribute__((section(".text.drawLocator")))
void drawLocator(void *m, float size)
{
    char f[0x50] __attribute__((aligned(16)));
    char *v = f + 0x30;
    char *w = f + 0x40;
    float neg;
    float one;
    char *z;
    int i;

    z = f;
    for (i = 1; i != -1; i--) {
        VU0_SQC2_VF0(z, 0);
        z += 16;
    }
    neg = -size;
    one = 1.0f;
    XF(neg, 0.0f, 0.0f) P0()
    XF(0.0f, 0.0f, 0.0f) P1(0xFFA0A0A0)
    XF(0.0f, 0.0f, 0.0f) P0()
    XF(size, 0.0f, 0.0f) P1(0xFF0000FF)
    XF(0.0f, neg, 0.0f) P0()
    XF(0.0f, 0.0f, 0.0f) P1(0xFFA0A0A0)
    XF(0.0f, 0.0f, 0.0f) P0()
    XF(0.0f, size, 0.0f) P1(0xFF00FF00)
    XF(0.0f, 0.0f, neg) P0()
    XF(0.0f, 0.0f, 0.0f) P1(0xFFA0A0A0)
    XF(0.0f, 0.0f, 0.0f) P0()
    XF(0.0f, 0.0f, size) P1(0xFFFF0000)
}

__attribute__((section(".text.func_001595F8")))
void func_001595F8(char *this)
{
    char *hdr;
    char *q;
    int mask;
    char *p;
    char *obj;
    char *o2;
    unsigned char ok;
    int s6;
    int n;
    int i;
    unsigned char flag;
    unsigned char frame[16] __attribute__((aligned(16)));

    hdr = *(char **)(this + 0x428);
    s6 = (*(unsigned short *)(this + 0x434) >> 1) & 1;
    p = hdr + 8;
    if ((*(int *)p & 0xFFF) == 0xFF) {
        q = p;
        p += 0xC;
        func_001599B0(this + 0x1B4, hdr, q);
    } else {
        ClearFields_4_8_C_E_159998((int)(this + 0x1B4));
    }
    if ((*(int *)p & 0xFFF) == 0x1FF) {
        q = p;
        p += 0xC;
        func_001599B0(this + 0x1D4, hdr, q);
    } else {
        ClearFields_4_8_C_E_159998((int)(this + 0x1D4));
    }
    if ((*(int *)p & 0xFFF) == 0x2FF) {
        q = p;
        p += 0xC;
        func_001599B0(this + 0x1F4, hdr, q);
    } else {
        ClearFields_4_8_C_E_159998((int)(this + 0x1F4));
    }
    n = *(unsigned char *)(this + 0x2B4);
    i = 0;
    if ((*(int *)p & 0xFFF) == 0x3FF) p += 0xC;
    if ((*(int *)p & 0xFFF) == 0x4FF) p += 0xC;
    if ((*(int *)p & 0xFFF) == 0x5FF) p += 0xC;
    if ((*(int *)p & 0xFFF) == 0x6FF) p += 0xC;
    if ((*(int *)p & 0xFFF) == 0x7FF) p += 0xC;
    if ((*(int *)p & 0xFFF) == 0x8FF) p += 0xC;

    for (i = 0; i < n; i++) {
        int cnt;
        mask = 0x800000;
        ok = ((*(int *)frame = cnt = *(unsigned char *)(this + 0x2B4)), (i >= 0 && i < cnt));
        if (ok) obj = *(char **)(*(char **)(this + 0x278) + i * 4); else obj = 0;
        o2 = obj;
        flag = 0;
        if (s6 != 0) {
            if (*(int *)(o2 + 0x14C) != 0)
                flag = (*(int *)(o2 + 0x154) & mask) == 0;
        }
        if (flag) o2 = *(char **)(obj + 0x14C);
        if ((*(int *)(o2 + 0x154) & 1) != 0) {
            if (*p == i) {
                do { p += 0xC; } while (*p == i);
            }
            continue;
        }
        if (*p != i) goto clr1;
        if ((*(int *)p & 0xF00) == 0) p += 0xC;
        if (*p != i) goto clr1;
        if ((*(int *)p & 0xF00) == 0x100) p += 0xC;
        if (*p != i) goto clr1;
        if ((*(int *)p & 0xF00) == 0x200) p += 0xC;
        if (*p != i) goto clr1;
        if ((*(int *)p & 0xF00) != 0x300) goto clr1;
        q = p;
        p += 0xC;
        func_001599B0(o2 + 0x1B4, hdr, q);
        goto n1;
clr1:
        ClearFields_4_8_C_E_159998((int)(o2 + 0x1B4));
n1:
        if (*p != i) goto clr2;
        if ((*(int *)p & 0xF00) != 0x400) goto clr2;
        q = p;
        p += 0xC;
        func_001599B0(o2 + 0x1D4, hdr, q);
        goto n2;
clr2:
        ClearFields_4_8_C_E_159998((int)(o2 + 0x1D4));
n2:
        if (*p != i) goto clr3;
        if ((*(int *)p & 0xF00) != 0x500) goto clr3;
        q = p;
        p += 0xC;
        func_001599B0(o2 + 0x1F4, hdr, q);
        goto n3;
clr3:
        ClearFields_4_8_C_E_159998((int)(o2 + 0x1F4));
n3:
        if (*p == i) {
            if ((*(int *)p & 0xF00) == 0x600) p += 0xC;
            if (*p == i) {
                if ((*(int *)p & 0xF00) == 0x700) p += 0xC;
                if (*p == i) {
                    if ((*(int *)p & 0xF00) == 0x800) p += 0xC;
                }
            }
        }
    }
}
