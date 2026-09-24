/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int  moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern int  D_00747A24;
extern int  D_00569B70;
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_005FEE00[];
extern unsigned short D_003F2060[];
extern void func_0032A9F0(int a0, int a1);
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern void func_002BB868(void *a0, void *a1, float f);
extern int EnsureInitThenForward_2A9538_30EE08(int a0, int a1, void *a2);
extern char D_00754240[];

/* func_001212D0 — 0x001212D0, 760 B — sn-2.95.3-136.
 * +0x2F6 phase machine, 0x694 object family; template src/cod/0011c348.c. */
#include "godhand/vu0.h"






















__attribute__((section(".text.func_001212D0")))
void func_001212D0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    char *p;
    char *q;

    *(float *)(s0 + 0x54C) = 5.0f;
    *(int *)(s0 + 0x250) |= 0x10000;
    s1 = *(char **)(s0 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        buf[1] = 0.0f;
        z = buf[1];
        buf[0] = -0.2378f;
        buf[2] = 1.5403f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, z);
        cEm00_GetPlMotion(s1, 0x2C, z, z);
        *(int *)(s0 + 0x15B0) = 1;
        *(int *)(s0 + 0x15B4) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        if (s1 != 0) {
            func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 15.0f));
        }
        func_0012C348(s0, 2);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    
    
    case 1:
        if (*(short *)(s0 + 0x56E) == 0 || s1 == 0)
            goto join;
        (*(short *)(s0 + 0x56E))--;
        p = *(char **)(s0 + 0xF0);
    
        q = s1 + 0x550;
        VU0_VADD_XYZ_IP(p, 0, q);
    join:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) > 0) {
                ClearField15F4Bit1_124F60(s0, 0, 0);
                *(char *)(s0 + 0x2F4) = 1;
                *(char *)(s0 + 0x2F5) = 4;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
            if (*(int *)(s0 + 0x15B0) != 0) {
                *(int *)(s0 + 0x15B0) = 0;
                if (s1 != 0) {
                    func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 15.0f));
                }
                func_0012C348(s0, 2);
            }
        } else {
            *(int *)(s0 + 0x15B0) = 1;
        }
        if ((*(unsigned short *)(s0 + 0x3AC) & 2) != 0) {
            if (*(int *)(s0 + 0x15B4) != 0) {
                *(int *)(s0 + 0x15B4) = 0;
                if (s1 != 0) {
                    func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 20.0f));
                }
                if (*(short *)(s0 + 0x54A) <= 0) {
                    *(short *)(s0 + 0x54A) = 0;
                    OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
                    cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                    *(unsigned short *)(s0 + 0x434) |= 8;
                }
                func_0012C348(s0, 2);
            }
        } else {
            *(int *)(s0 + 0x15B4) = 1;
        }
        break;
    default:
        break;
    }
}

__attribute__((section(".text.func_00306AF0")))
int func_00306AF0(char *base, int idx, char *hdr)
{
    int i;
    char *q;
    int tmp;
    char **slot;
    char *tbl;

    if (*(int *)hdr != 0x444D45) goto ng;
    if (idx >= 0x4E2) goto ng;
    tbl = base + 0x100;
    slot = (char **)(tbl + idx * 4);
    if (*slot != 0) goto ng;
    *slot = hdr;

    do { do { do { i = 0; } while (0); } while (0); } while (0);
    if (*(int *)(hdr + 0x4) == 0) goto ok;

    q = base;
    do {
        if (func_00306A48(hdr, i, &tmp) != 0) {
            if (tmp != 0) *(int *)q = tmp;
        }
        i++;
        q += 4;
    } while ((unsigned int)i < (unsigned int)*(int *)(hdr + 0x4));
    return 1;
ng:
    return 0;
ok:
    return 1;
}

/* sn-2.95.3-136 */





__attribute__((section(".text.func_003851C0")))
void func_003851C0(char *a0, char *a1)
{
    char *p;
    char *q;
    short step;
    int f;

    p = a0 + 0x470;
    q = a0 + 0x484;
    step = 1;
    if ((*(int *)(a1 + 0x2C) & 2) != 0) {
        step = 10;
    }
    f = *(int *)(a1 + 0x38);
    if (f < 0) {
        if (*(short *)(p + 4) >= step - 0x3C0) {
            *(short *)(p + 4) = *(short *)(p + 4) - step;
        } else {
            *(short *)(p + 4) = -0x3C0;
        }
        goto call1;
    }
    if ((f & 0x40000000) != 0) {
        if (*(short *)(p + 4) <= -step) {
            *(short *)(p + 4) = step + *(short *)(p + 4);
        } else {
            *(short *)(p + 4) = 0;
        }
call1:
        *(short *)(p + 6) = func_003807E0(a0, *(short *)(p + 4));
    } else if ((f & 0x8000) != 0) {
        if (*(short *)(p + 6) >= step) {
            *(short *)(p + 6) = *(short *)(p + 6) - step;
        } else {
            *(short *)(p + 6) = 0;
        }
        *(short *)(p + 4) = D_003F2060[*(short *)(p + 6)];
    } else {
        if ((f & 0x2000) == 0) {
            return;
        }
        if (*(short *)(p + 6) <= 0x7F - step) {
            *(short *)(p + 6) = step + *(short *)(p + 6);
        } else {
            *(short *)(p + 6) = 0x7F;
        }
        *(short *)(p + 4) = D_003F2060[*(short *)(p + 6)];
    }
    if (*(int *)(q + 0x30) != 0) {
        func_0032A9F0(*(int *)(q + 0x30), *(short *)(p + 4));
    }
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"




__attribute__((section(".text.func_002BB760")))
void func_002BB760(void *a0, void *a1, char *a2, float f12)
{
    unsigned char frame[0xA0];

    float *d;
    char *p;
    unsigned int i;
    int n;

    p = (char *)frame;
    n = 7;
    do {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    } while (--n != -1);


    i = 0;
    d = (float *)frame;
    do {
        VU0_LQC2(4, a2 + i * 0x10, 0x0);
        VU0_SQC2(4, frame, 0x90);
        sceVu0ApplyMatrix(frame + 0x90, a1, frame + 0x90);
        VU0_LQC2(4, frame + 0x90, 0x0);
        VU0_SQC2(4, frame, 0x80);
        if (d != (float *)(frame + 0x80)) {
            d[0] = *(float *)(frame + 0x80);
            d[1] = *(float *)(frame + 0x84);
            d[2] = *(float *)(frame + 0x88);
        }
        d += 4;
        i++;
    } while (i < 8);
    func_002BB868(a0, frame, f12);
}

/* sn-2.95.3-136 matched TU. */

typedef struct T {
    int a;
    float k;
} T;

extern void func_002A8D30(T *first, T *last, T *mid, T *dummy, void *comp);


static __inline__ unsigned char fcmp(float a, float b)
{
    return a < b;
}

static __inline__ T *median(T *a, T *b, T *c)
{
    if (fcmp(a->k, b->k)) {
        if (fcmp(b->k, c->k)) {
            return b;
        } else if (fcmp(a->k, c->k)) {
            return c;
        } else {
            return a;
        }
    } else if (fcmp(a->k, c->k)) {
        return a;
    } else if (fcmp(b->k, c->k)) {
        return c;
    } else {
        return b;
    }
}

__attribute__((section(".text.func_002A8EF0")))
void func_002A8EF0(T *first, T *last, T *dummy, int depth, void *comp)
{
    T *cut;
    T pivot;

    while (last - first > 16) {
        if (depth == 0) {
            func_002A8D30(first, last, last, 0, comp);
            return;
        }
        --depth;
        pivot = *median(first, first + (last - first) / 2, last - 1);
        cut = func_002A8E48(first, last,
                            ((long)*(int *)((char *)&pivot + 4) << 32)
                                | *(unsigned int *)&pivot,
                            comp);
        func_002A8EF0(cut, last, 0, depth, comp);
        last = cut;
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002EBD10")))
int func_002EBD10(void *a0, int a1, int n)
{
    char *s1 = (char *)a0;
    int sz;
    int sz2;
    int p;
    unsigned int i;
    char *q;

    if (*(int *)(s1 + 0x2E0) & 8) {
        char *d = D_00754240;

        sz = n * 0x60 + 0xF0;
        p = EnsureInitThenForward_2A9538_30EE08(sz, 0x10, d);
        *(int *)(s1 + 0x2CC) = p;
        if (p == 0) {
            return 0;
        }
        p = EnsureInitThenForward_2A9538_30EE08(sz, 0x10, d);
        *(int *)(s1 + 0x2D0) = p;
    } else {
        char *d = D_00754240;

        sz = n * 0x40 + 0xF0;
        sz2 = sz;
        p = EnsureInitThenForward_2A9538_30EE08(sz2, 0x10, d);
        *(int *)(s1 + 0x2C4) = p;
        if (p == 0) {
            return 0;
        }
        p = EnsureInitThenForward_2A9538_30EE08(sz, 0x10, d);
        *(int *)(s1 + 0x2C8) = p;
    }
    if (p == 0) {
        return 0;
    }
    sz2 = n * 0x10;
    p = EnsureInitThenForward_2A9538_30EE08(sz2, 0x10, D_00754240);
    *(int *)(s1 + 0x2BC) = p;
    if (p == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        q = (char *)(i * 0x10 + *(int *)(s1 + 0x2BC));
        *(int *)(q + 0x0) = 0;
        *(int *)(q + 0x4) = 0;
        *(int *)(q + 0x8) = 0;
        *(float *)(q + 0xC) = 1.0f;
    }
    if (*(int *)(s1 + 0x2E0) & 4) {
        p = EnsureInitThenForward_2A9538_30EE08(n * 0x10, 0x10, D_00754240);
        *(int *)(s1 + 0x2C0) = p;
        if (p == 0) {
            return 0;
        }
        for (i = 0; i < n; i++) {
            q = (char *)(i * 0x10 + *(int *)(s1 + 0x2C0));
            *(int *)(q + 0x0) = 0;
            *(int *)(q + 0x4) = 0;
            *(int *)(q + 0x8) = 0;
            *(float *)(q + 0xC) = 1.0f;
        }
    }
    if ((*(unsigned long *)(s1 + 0x240) & ((unsigned long)0xFFFF << 40))
        != ((unsigned long)0x8080 << 33)
        || *(float *)(s1 + 0x2DC) != 0.0f) {
        *(int *)(s1 + 0x2E0) = *(int *)(s1 + 0x2E0) | 1;
    }
    *(int *)(s1 + 0x2E4) = 1;
    return 1;
}
