/* sn-2.95.3-136 matched TU. */

extern int D_00747A3C;
extern char D_003BD718[];
extern void func_001F8A88(void *a0, float x0, float x1, float y0, float y1, float z0, float z1);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern unsigned char D_005FEE00[];
extern int AllocActiveSlot_1FE218(int a0, int a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, int a2, float f);
extern void SetListNodeBitByKey_14A398(int a0, int a1, int a2);
extern int D_00574380;
extern int D_003BD880;
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern void SetField380Bit2000ForTag_1B7300(void *a0, int a1, int a2);
extern void func_001BE498(char *a0, int a1, float *a2, float *a3);
extern int D_00747A78;
extern char *D_00586A7C;

/* sn-2.95.3-136 */
__attribute__((section(".text.Binit")))
char *Binit(char *p)
{
    *(short *)(p + 0xC) = 1;
    *(int *)(p + 0x4) = 3;
    *(int *)(p + 0x8) = 8;
    *(int *)(p + 0x10) = 0;
    *(short *)(p + 0xE) = 0;
    return p;
}

__attribute__((section(".text.cCoreSave_getAllKillEmNum")))
int cCoreSave_getAllKillEmNum(char **self, int idx) {
    char *p = *self;
    int off;

    if (p == 0) {
        return 0;
    }
    idx--;
    if (idx < 0) {
        return 0;
    }
    if (idx >= 5) {
        return 0;
    }
    off = idx * 2;
    return *(unsigned short *)(p + off + 0xBAC);
}

__attribute__((section(".text.cCoreSave_getClearNum")))
int cCoreSave_getClearNum(char **self) {
    char *p = *self;

    if (p == 0) {
        return 0;
    }
    if ((D_00747A3C & 0x40000) == 0) {
        return *(unsigned short *)(p + 0x10);
    }
    if (*(unsigned short *)(p + 0x10) == 0) {
        return 1;
    }
    return *(unsigned short *)(p + 0x10);
}

__attribute__((section(".text.cCoreSave_setComboMax")))
void cCoreSave_setComboMax(int a0,unsigned int a1,int a2){int p=*(int*)a0;if(p==0)return;if(a1>=6)return;if(a2<0)a2=0;if(a2>6)a2=6;*(int*)(p+a1*0x24+0x1D0)=a2;}

__attribute__((section(".text.cEm00_CkDevilEvent")))
int cEm00_CkDevilEvent(char *p) {
    if (*(unsigned char *)(p + 0x2F4) != 0) {
        return 0;
    }
    if (*(unsigned char *)(p + 0x2F5) != 4) {
        return 0;
    }
    return *(unsigned char *)(p + 0x2F6) >= 2;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.cEm00_setEm65Separate")))
void cEm00_setEm65Separate(char *p)
{
    *(unsigned char *)(p + 0x2F4) = 0;
    *(unsigned char *)(p + 0x2F6) = 0;
    *(float *)(p + 0x54C) = 3.0f;
    *(unsigned char *)(p + 0x2F5) = 0x9A;
    *(unsigned char *)(p + 0x2F7) = 0;
}

__attribute__((section(".text.cEma2_gotoSwitch")))
void cEma2_gotoSwitch(char *p, float *src) {
    float *dst = (float *)(p + 0x15A0);

    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    *(int *)(p + 0x15B0) |= 0x80;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.cGame_isReleaseActiveHeap")))
int cGame_isReleaseActiveHeap(char *p)
{
    if (*(short *)(p + 0x1B2) > 0) {
        *(unsigned short *)(p + 0x1B2) = *(unsigned short *)(p + 0x1B2) - 1;
        return 0;
    }
    return 1;
}

__attribute__((section(".text.classCFILTER_TAG_initialize")))
void classCFILTER_TAG_initialize(char *p) {
    *(char **)(p + 0x10000) = (char *)(((unsigned int)p | 0x20000000) + 0x10);
    *(char **)(p + 0x14080) =
        (char *)((((unsigned int)(p + 0x10080)) | 0x20000000) + 0x10);
}

__attribute__((section(".text.cOl21_setCollisionActive")))
void cOl21_setCollisionActive(int a0,int a1,float f12){int i;int **arr=(int**)(a0+0x654);for(i=0;i<8;i++){int *q=arr[i];if(a1==1)q[2]|=1;else q[2]&=~1;}*(float*)(a0+0x608)=f12;}

/* sn-2.95.3-136 */
__attribute__((section(".text.cOl2b_setInit")))
void cOl2b_setInit(char *p)
{
    if (*(int *)(p + 0xA24) != 0) {
        *(unsigned char *)(p + 0x2F4) = 3;
        *(unsigned char *)(p + 0x2F5) = 0;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
    }
}

__attribute__((section(".text.CustomIDWork_Initialize")))
void CustomIDWork_Initialize(char *a0, char *a1) {
    if (a1 != 0) {
        *(char **)(a0 + 0x4) = a1;
        *(float *)(a0 + 0xC) = *(float *)(a1 + 0x38);
        *(float *)(a0 + 0x10) = *(float *)(a1 + 0x3C);
        *(int *)(a0 + 0x4C) = *(int *)(a1 + 0x4C);
        *(unsigned char *)(a0 + 0x78) = *(unsigned char *)(a1 + 0x2B);
    }
}

/* sn-2.95.3-136 */
__attribute__((section(".text.CustomIDWork_ResetScaleAnim")))
void CustomIDWork_ResetScaleAnim(char *p)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(int *)(p + 0x5C) = 0;
        *(float *)(q + 0x40) = *(float *)(p + 0x60);
        *(float *)(*(char **)(p + 0x4) + 0x44) = *(float *)(p + 0x60);
    }
}

__attribute__((section(".text.CustomIDWork_SetColorAnimNormal_2D6898")))
void CustomIDWork_SetColorAnimNormal_2D6898(char *p, int a1, unsigned short a2) {
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
    /* SWEEP-BEGIN */
        *(int *)(p + 0x48) = 3;
        *(int *)(p + 0x50) = *(int *)(q + 0x4C);
        *(int *)(p + 0x54) = a1;
        *(short *)(p + 0x58) = a2;
/* SWEEP-END */
        if (a2 == 0) {
            *(short *)(p + 0x58) = 1;
        }
        *(short *)(p + 0x5A) = 0;
    }
}

/* CustomIDWork_SetNoDisp */
__attribute__((section(".text.CustomIDWork_SetNoDisp")))
void CustomIDWork_SetNoDisp(int a0,int a1){int p=*(int*)(a0+4);if(p==0)return;if(a1)*(int*)(p+0x2C)|=0x8000000;else *(int*)(p+0x2C)&=~0x8000000;}

__attribute__((section(".text.CustomIDWork_SetScaleAnimNormal")))
void CustomIDWork_SetScaleAnimNormal(int a0,unsigned short a1,float f12,float f13){if(*(int*)(a0+4)==0)return;*(int*)(a0+0x5C)=3;*(float*)(a0+0x64)=f12;*(float*)(a0+0x68)=f13;*(float*)(a0+0x6C)=f12;*(float*)(a0+0x70)=f13;*(short*)(a0+0x74)=a1;if(a1==0)*(short*)(a0+0x74)=1;*(short*)(a0+0x76)=0;}

__attribute__((section(".text.CustomIDWork_SetScaleAnimSin")))
void CustomIDWork_SetScaleAnimSin(int a0,unsigned short a1,float f12,float f13){if(*(int*)(a0+4)==0)return;*(int*)(a0+0x5C)=5;*(float*)(a0+0x64)=f12;*(float*)(a0+0x68)=f13;*(float*)(a0+0x6C)=f12;*(float*)(a0+0x70)=f13;*(short*)(a0+0x74)=a1;if(a1==0)*(short*)(a0+0x74)=1;*(short*)(a0+0x76)=0;}

/* sn-2.95.3-136 */


__attribute__((section(".text.func_00148F28")))
void func_00148F28(char *p, int i)
{
    char *e = (char *)(i * 8 + (int)D_003BD718);

    *(long *)(p + 0x50) = *(long *)e;
    *(long *)(p + 0x100) = *(long *)e;
}

/* sn-2.95.3-136, no extra flags */


__attribute__((section(".text.func_001490B0")))
void func_001490B0(void *a0, char **a1, void *a2)
{
    char hold[16];
    char *obj;
    char *e;
    int *tab;
    int i4;
    float *q;
    int i;
    int j;
    int n;
    int m;
    float x0, x1, y0, y1, z0, z1;

    x0 = 1000000000.0f;
    x1 = -1000000000.0f;
    y0 = x0;
    y1 = x1;
    z0 = y0;
    z1 = y1;
    obj = *a1;
    n = *(unsigned short *)(obj + 0xA);
    for (i = 0; i < n; i++) {
        i4 = i * 4;
        tab = (int *)(obj + 0x20);
        e = (char *)(*(int *)((int)tab + i4) + (int)obj);
        *(int *)hold = (int)e;
        q = (float *)(*(int *)e + (int)e);
        m = *(unsigned short *)(e + 0x14);
        for (j = 0; j < m; j++) {
            if (q[0] < x0) x0 = q[0];
            if (x1 < q[0]) x1 = q[0];
            if (q[1] < y0) y0 = q[1];
            if (y1 < q[1]) y1 = q[1];
            if (q[2] < z0) z0 = q[2];
            if (z1 < q[2]) z1 = q[2];
            q += 4;
        }
    }
    func_001F8A88(a2, x0, x1, y0, y1, z0, z1);
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_00155D98")))
void func_00155D98(char *p, long v, int i)
{
    *(long *)(p + i * 0xB0 + 0x50) = v;
}

/* sn-2.95.3-136 */






__attribute__((section(".text.func_001B1630")))
void func_001B1630(char *p)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    char *o;
    char *o2;
    int b, idx, obj;
    unsigned char ok;
    float *d, *s;
    char *q;

    o = *(char **)(p + 0x600);
    if (o != 0) {
        idx = *(int *)(p + 0x604);
        ok = ((*(int *)frame = b = *(unsigned char *)(o + 0x2B4)), (idx >= 0 && idx < b));
        if (ok) obj = *(int *)(idx * 4 + *(int *)(o + 0x278)); else obj = 0;
        d = *(float **)(p + 0xF0);
        s = (float *)(p + 0x610);
        q = (char *)(obj + 0x80);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
        sceVu0ApplyMatrix(*(void **)(p + 0xF0), q, *(void **)(p + 0xF0));
        o2 = *(char **)(p + 0x600);
        *(float *)(p + 0x24C) = *(float *)(o2 + 0x24C);
        if ((*(int *)(o2 + 0x250) & 0x10) != 0)
            *(int *)(p + 0x250) = *(int *)(p + 0x250) | 0x10;
        else
            *(int *)(p + 0x250) = *(int *)(p + 0x250) & 0xFFFFFFEF;
        if (*(unsigned char *)(p + 0x667) == 0) {
            *(unsigned char *)(p + 0x667) = 1;
            SetEffect(0x58, 5, p, 0, 7, 0xFFFFFFFFu);
            *(int *)(p + 0x668) = cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x117, p, 0, 0, 0, 0);
        }
    }
}

/* sn-2.95.3-136 */








#include "godhand/vu0.h"

__attribute__((section(".text.func_001B2548")))
int func_001B2548(char *p)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int flag;
    int n;
    int dg;
    int sph;

    func_001B6FB8(p);
    dg = AllocActiveSlot_1FE218((int)&D_00574380, (int)p, 1);
    *(int *)(p + 0x600) = dg;
    if (dg != 0) {
        flag = *(unsigned char *)(p + 0x2B4);
        *(int *)frame = flag;
        if (flag) {
            n = **(int **)(p + 0x278);
        } else {
            n = 0;
        }
        n = n + 0x80;
        sph = (int)(frame + 0x10);
        VU0_LQC2(4, &D_003BD880, 0);
        VU0_SQC2(4, frame, 0x10);
        cDamageUnit_AddDamageCollSphere(*(int *)(p + 0x600), n, sph, 2.25f);
        *(int *)(*(int *)(p + 0x600)) |= 1;
    }
    *(short *)(p + 0x548) = 0x3E8;
    *(int *)(p + 0x624) = 0;
    *(unsigned char *)(p + 0x62C) = 0;
    *(unsigned char *)(p + 0x2F5) = 0;
    *(short *)(p + 0x54A) = 0x3E8;
    *(int *)(p + 0x5B8) |= 8;
    *(float *)(p + 0x620) = 1.8f;
    *(float *)(p + 0x628) = 0.036f;
    SetListNodeBitByKey_14A398((int)p, 0, 1);
    SetListNodeBitByKey_14A398((int)p, 0x40, 0);
    *(unsigned char *)(p + 0x62D) = 0;
    return 1;
}

__attribute__((section(".text.func_001B7EA8")))
void func_001B7EA8(char *p, float *src) {
    float *dst = (float *)(p + 0x100);

    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    *(int *)(p + 0x5B8) |= 0x10;
}

/* sn-2.95.3-136 */





__attribute__((section(".text.func_001BE740")))
void func_001BE740(char *p)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    float *v;
    float fa;

    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x10);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;
    *(float *)(frame + 0x0) = 0.0f;
    *(float *)(frame + 0x4) = 0.0f;
    *(float *)(frame + 0x8) = 0.0f;
    fa = 1.0f;
    *(float *)(frame + 0xC) = fa;
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    v[3] = fa;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        do {
            func_001BE498(p, i, (float *)frame, (float *)(frame + 0x10));
            i++;
        } while (i < 8 && *(unsigned char *)(p + 0x2B4) != i);
    }
}

/* sn-2.95.3-136 */



__attribute__((section(".text.func_001BF2F0")))
void func_001BF2F0(char *p)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b1, b2, b3, b4;
    int o1, o2, o3, o4;
    int i1, i2, i3, i4;

    switch (*(unsigned char *)(p + 0x2F5)) {
    case 0:
        i1 = 1;
        if ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4), (i1 >= 0 && i1 < b1)))
            o1 = *(int *)(*(int *)(p + 0x278) + i1 * 4);
        else o1 = 0;
        if (o1 != 0) {
            i2 = 1;
            if ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4), (i2 >= 0 && i2 < b2)))
                o2 = *(int *)(*(int *)(p + 0x278) + i2 * 4);
            else o2 = 0;
            *(float *)(o2 + 0x100) = *(float *)(o2 + 0x100) + 0.1745329201221466f;
            i3 = 1;
            if ((*(int *)frame = b3 = *(unsigned char *)(p + 0x2B4), (i3 >= 0 && i3 < b3)))
                o3 = *(int *)(*(int *)(p + 0x278) + i3 * 4);
            else o3 = 0;
            if (0.0f < *(float *)(o3 + 0x100)) {
                i4 = 1;
                if ((*(int *)frame = b4 = *(unsigned char *)(p + 0x2B4), (i4 >= 0 && i4 < b4)))
                    o4 = *(int *)(*(int *)(p + 0x278) + i4 * 4);
                else o4 = 0;
                *(float *)(o4 + 0x100) = 0.0f;
                *(unsigned char *)(p + 0x2F5) = *(unsigned char *)(p + 0x2F5) + 1;
            }
        }
        break;
    case 1:
        D_00747A78 = D_00747A78 & 0xFDFFFFFF;
        *(char *)(p + 0x2F4) = 0;
        *(char *)(p + 0x2F5) = 0;
        *(int *)(p + 0x600) = *(int *)(p + 0x600) & -2;
        break;
    }
}

__attribute__((section(".text.func_001D0108")))
void func_001D0108(char *p) {
    /* SWEEP-BEGIN */
    *(unsigned int *)(p + 0x250) = *(unsigned int *)(p + 0x250) & 0xFFFFFFEFU;
    *(unsigned char *)(p + 0x2F5) = 0x10;
    *(unsigned char *)(p + 0x2F7) = 0;
    *(unsigned char *)(p + 0x2F4) = 0;
    *(unsigned char *)(p + 0x2F6) = 0;
    *(float *)(p + 0x24C) = 1.0f;
/* SWEEP-END */
}

struct Node {
    char pad[4];
    struct Node *next;
};

__attribute__((section(".text.func_001F7820")))
void func_001F7820(char *base, struct Node *target) {
    struct Node *p = (struct Node *)(base + 0xF4);
    struct Node *q;

    while (p != 0) {
        q = p->next;
        if (q == target) {
            p->next = q->next;
            q->next = 0;
            return;
        }
        p = q;
    }
}

__attribute__((section(".text.func_001FACF8")))
int func_001FACF8(char **self, int i, int d) {
    char *b = *self + 0x134;
    unsigned char *p = (unsigned char *)(b + i);
    unsigned int v = *p + d;

    if (v < 0x100) {
        *p = v;
        return 1;
    }
    *p = 0xFF;
    return 0;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_001FBD00")))
void func_001FBD00(char *p, unsigned char v)
{
    char *q = *(char **)p;

    if (q != 0) {
        if ((unsigned int)(v - 1) < 6) {
            *(unsigned char *)(q + 0x8A) = v;
        }
    }
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_001FF090")))
void func_001FF090(char *p)
{
    int n = *(int *)(p + 0x4);

    if (n >= 0) {
        *(int *)(p + 0x4) = n + 1;
    }
    *(int *)(p + 0x0) = 3;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_001FF0B0")))
void func_001FF0B0(char *p)
{
    if (*(int *)(p + 0x4) > 0) {
        *(int *)(p + 0x4) = *(int *)(p + 0x4) - 1;
    }
    if (*(int *)(p + 0x4) == 0) {
        *(int *)(p + 0x0) = 4;
    }
}

/* sn-2.95.3-136 */



__attribute__((section(".text.func_002799B8")))
void func_002799B8(char *a0)
{
    float A[4] __attribute__((aligned(16)));
    float B[4] __attribute__((aligned(16)));
    unsigned char hold[0x10] __attribute__((aligned(16)));
    float *pb;
    char *g;
    int idx, b1, b2, o1, o2;
    float *d, *p2, *p3, *p4;

    A[0] = -0.03999999910593033f;
    A[1] = 0.07999999821186066f;
    A[2] = 0.0f;
    A[3] = 1.0f;
    pb = B;
    B[0] = 0.0f;
    pb[1] = -0.20000000298023224f;
    pb[2] = -0.20000000298023224f;
    pb[3] = 1.0f;
    idx = 6;
    g = D_00586A7C;
    if ((*(int *)hold = b1 = *(unsigned char *)(g + 0x2B4), (idx >= 0 && idx < b1)))
        o1 = *(int *)(*(int *)(g + 0x278) + idx * 4);
    else o1 = 0;
    if (o1 != 0) {
        if ((*(int *)hold = b2 = *(unsigned char *)(a0 + 0x2B4), b2 != 0))
            o2 = *(int *)(*(int *)(a0 + 0x278) + 0 * 4);
        else o2 = 0;
        if (o2 != 0) {
            d = *(float **)(o2 + 0xD0);
            *(int *)(o2 + 0x148) = o1;
            *(int *)(o2 + 0x100) = 0;
            *(int *)(o2 + 0x104) = 0;
            *(int *)(o2 + 0x108) = 0;
            if (d != A) { d[0] = A[0]; d[1] = A[1]; d[2] = A[2]; }
            p2 = (float *)(o2 + 0x100);
            if (p2 != B) { p2[0] = B[0]; p2[1] = B[1]; p2[2] = B[2]; }
            *(int *)(a0 + 0x1580) = (int)g;
            *(int *)(a0 + 0x1584) = idx;
            p3 = (float *)(a0 + 0x1590);
            if (p3 != A) { p3[0] = A[0]; p3[1] = A[1]; do { } while (0); p3[2] = A[2]; }
            p4 = (float *)(a0 + 0x15A0);
            if (p4 != B) { p4[0] = B[0]; p4[1] = B[1]; do { } while (0); p4[2] = B[2]; }
            *(char *)(a0 + 0x2F5) = 3;
            *(char *)(a0 + 0x2F4) = 0;
            *(char *)(a0 + 0x2F6) = 0;
            *(char *)(a0 + 0x2F7) = 0;
        }
    }
}

/* sn-2.95.3-136 */

__attribute__((section(".text.func_0027D1D0")))
void func_0027D1D0(char *a0, char *a1, int idx, float *va, float *vb)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b1, b2, obj, o2;
    unsigned char ok1, ok2;
    float *p1, *p2, *p3, *p4, *p5, *q5;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a1 + 0x2B4)), (idx >= 0 && idx < b1));
    if (ok1) obj = *(int *)(idx * 4 + *(int *)(a1 + 0x278)); else obj = 0;
    if (obj != 0) {
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (0 >= 0 && 0 < b2));
        if (ok2) o2 = *(int *)(*(int *)(a0 + 0x278) + 0 * 4); else o2 = 0;
        if (o2 != 0) {
            p1 = *(float **)(o2 + 0xD0);
            *(int *)(o2 + 0x148) = obj;
            *(int *)(o2 + 0x100) = 0;
            *(int *)(o2 + 0x104) = 0;
            *(int *)(o2 + 0x108) = 0;
            if (p1 != va) { p1[0] = va[0]; p1[1] = va[1]; p1[2] = va[2]; }
            p2 = (float *)(o2 + 0x100);
            if (p2 != vb) { p2[0] = vb[0]; p2[1] = vb[1]; p2[2] = vb[2]; }
            *(int *)(a0 + 0x1584) = idx;
            *(int *)(a0 + 0x1580) = (int)a1;
            p3 = (float *)(a0 + 0x1590);
            if (p3 != va) { p3[0] = va[0]; p3[1] = va[1]; p3[2] = va[2]; }
            p4 = (float *)(a0 + 0x15A0);
            p5 = (float *)(a0 + 0x110);
            if (p4 != vb) { p4[0] = vb[0]; p4[1] = vb[1]; p4[2] = vb[2]; }
            q5 = (float *)(a1 + 0x110);
            if (p5 != q5) { p5[0] = q5[0]; p5[1] = q5[1]; p5[2] = q5[2]; }
        }
    }
}

/* sn-2.95.3-136 */

__attribute__((section(".text.func_0027E6B8")))
void func_0027E6B8(char *a0, char *a1, int idx, float *va, float *vb)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b1, b2, obj, o2;
    unsigned char ok1, ok2;
    float *p1, *p2, *p3, *p4, *p5, *q5;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a1 + 0x2B4)), (idx >= 0 && idx < b1));
    if (ok1) obj = *(int *)(idx * 4 + *(int *)(a1 + 0x278)); else obj = 0;
    if (obj != 0) {
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (0 >= 0 && 0 < b2));
        if (ok2) o2 = *(int *)(*(int *)(a0 + 0x278) + 0 * 4); else o2 = 0;
        if (o2 != 0) {
            p1 = *(float **)(o2 + 0xD0);
            *(int *)(o2 + 0x148) = obj;
            *(int *)(o2 + 0x100) = 0;
            *(int *)(o2 + 0x104) = 0;
            *(int *)(o2 + 0x108) = 0;
            if (p1 != va) { p1[0] = va[0]; p1[1] = va[1]; p1[2] = va[2]; }
            p2 = (float *)(o2 + 0x100);
            if (p2 != vb) { p2[0] = vb[0]; p2[1] = vb[1]; p2[2] = vb[2]; }
            *(int *)(a0 + 0x1584) = idx;
            *(int *)(a0 + 0x1580) = (int)a1;
            p3 = (float *)(a0 + 0x1590);
            if (p3 != va) { p3[0] = va[0]; p3[1] = va[1]; p3[2] = va[2]; }
            p4 = (float *)(a0 + 0x15A0);
            if (p4 != vb) { p4[0] = vb[0]; p4[1] = vb[1]; p4[2] = vb[2]; }
            *(int *)(a0 + 0x1608) = (int)a1;
            p5 = (float *)(a0 + 0x110);
            q5 = (float *)(a1 + 0x110);
            *(int *)(a0 + 0x15E8) = 0;
            if (p5 != q5) { p5[0] = q5[0]; p5[1] = q5[1]; p5[2] = q5[2]; }
        }
    }
}

/* sn-2.95.3-136 */

__attribute__((section(".text.func_00282F40")))
void func_00282F40(char *a0, char *a1, int idx, float *va, float *vb)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b1, b2, obj, o2;
    unsigned char ok1, ok2;
    float *p1, *p2, *p3, *p4, *p5, *q5;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a1 + 0x2B4)), (idx >= 0 && idx < b1));
    if (ok1) obj = *(int *)(idx * 4 + *(int *)(a1 + 0x278)); else obj = 0;
    if (obj != 0) {
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (0 >= 0 && 0 < b2));
        if (ok2) o2 = *(int *)(*(int *)(a0 + 0x278) + 0 * 4); else o2 = 0;
        if (o2 != 0) {
            p1 = *(float **)(o2 + 0xD0);
            *(int *)(o2 + 0x148) = obj;
            *(int *)(o2 + 0x100) = 0;
            *(int *)(o2 + 0x104) = 0;
            *(int *)(o2 + 0x108) = 0;
            if (p1 != va) { p1[0] = va[0]; p1[1] = va[1]; p1[2] = va[2]; }
            p2 = (float *)(o2 + 0x100);
            if (p2 != vb) { p2[0] = vb[0]; p2[1] = vb[1]; p2[2] = vb[2]; }
            *(int *)(a0 + 0x1584) = idx;
            *(int *)(a0 + 0x1580) = (int)a1;
            p3 = (float *)(a0 + 0x1590);
            if (p3 != va) { p3[0] = va[0]; p3[1] = va[1]; p3[2] = va[2]; }
            p4 = (float *)(a0 + 0x15A0);
            p5 = (float *)(a0 + 0x110);
            if (p4 != vb) { p4[0] = vb[0]; p4[1] = vb[1]; p4[2] = vb[2]; }
            q5 = (float *)(a1 + 0x110);
            if (p5 != q5) { p5[0] = q5[0]; p5[1] = q5[1]; p5[2] = q5[2]; }
        }
    }
}
