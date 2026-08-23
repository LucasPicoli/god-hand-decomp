/* TU: cOmWeapon [object] - recovered C++ class. */
#include "include_asm.h"

extern void func_001CF3A8(void *a0);
extern void cModel_calcParts(void *a0);
extern void func_001331B8(char *a0, long a1, int a2);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern char D_005CAE50[];

static inline void cpy3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.cOmWeapon_setParent")))
void cOmWeapon_setParent(char *p, char *par, int idx, float *v0p, float *v1p)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b, b2;
    unsigned char ok, ok2;
    char *obj;
    char *o;
    float *s;

    ok = ((*(int *)frame = b = *(unsigned char *)(par + 0x2B4)), (idx >= 0 && idx < b));
    if (ok) obj = *(char **)(*(char **)(par + 0x278) + idx * 4); else obj = 0;
    if (obj == 0) return;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (b2 != 0));
    if (ok2) o = **(char ***)(p + 0x278); else o = 0;
    if (o == 0) return;
    s = *(float **)(o + 0xD0);
    *(int *)(o + 0x100) = 0;
    *(int *)(o + 0x104) = 0;
    *(int *)(o + 0x108) = 0;
    *(char **)(o + 0x148) = obj;
    cpy3(s, v0p);
    cpy3((float *)(o + 0x100), v1p);
    *(int *)(p + 0x604) = idx;
    *(char **)(p + 0x600) = par;
    cpy3((float *)(p + 0x610), v0p);
    cpy3((float *)(p + 0x620), v1p);
    p[0x2F4] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
    p[0x664] = 0;
    p[0x2F5] = 1;
    func_001CF3A8(p);
    cModel_calcParts(p);
    func_001331B8(D_005CAE50, *(long *)(p + 0x540), 0);
    if (*(unsigned short *)(p + 0x2FE) != 0x369) return;
    if (par == 0) return;
    if (*(int *)(par + 0x564) == 0x252) {
        SetEffect(0xAA, 0xC, p, 0, 8, 0xFFFFFFFFu);
    }
    if (*(int *)(par + 0x564) == 0x263) {
        SetEffect(0xBC, 0x1D, p, 0, 8, 0xFFFFFFFFu);
    }
}
