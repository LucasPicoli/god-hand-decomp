/* sn-2.95.3-136 matched TU. */

extern char *InitFields_1B6E90(char *a0);
extern int D_0042AA98;

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"




__attribute__((section(".text.func_001C9140")))
void *func_001C9140(void *a0)
{
    char *s0 = (char *)a0;
    char *p;
    int i;

    InitFields_1B6E90(s0);
    *(int *)(s0 + 0x214) = (int)&D_0042AA98;
    VU0_SQC2_VF0(s0, 0x610);
    VU0_SQC2_VF0(s0, 0x620);
    VU0_SQC2_VF0(s0, 0x640);
    VU0_SQC2_VF0(s0, 0x6A0);
    p = s0 + 0x6B0;
    i = 6;
    do {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        p += 0x20;
    } while (--i != -1);
    return s0;
}

/* sn-2.95.3-136 candidate. */

struct VtEnt { short delta; short index; void *pfn; };


extern int func_001FCAE8(void *obj, int r, int p2, int p3, int p4, void *self,
                         float f12, float f13);

__attribute__((section(".text.cDamageUnit_AddDamageCollCylinder")))
int cDamageUnit_AddDamageCollCylinder(char *self, int a1, int a2, int a3,
                                      float f12, float f13)
{
    struct VtEnt *vt;
    char *obj;
    char *p;
    int r;

    if (*(signed char *)(self + 0x49) == 0) return -1;
    vt = *(struct VtEnt **)(self + 0x50);
    obj = (char *)((int (*)(void *))vt[2].pfn)(self + vt[2].delta);
    if (obj == 0) return -1;
    if (func_001FD908(self) == 0) return -1;
    r = func_001FCAE8(obj, func_001FD908(self), a1, a2, a3, self, f12, f13);
    if (r == -1) return r;
    if (*(char **)(self + 0x3C) != 0) {
        p = *(char **)(self + 0x3C);
        while (*(char **)(p + 0x24) != 0) p = *(char **)(p + 0x24);
        *(char **)(p + 0x24) = obj;
        *(char **)(obj + 0x20) = p;
    } else {
        *(char **)(self + 0x3C) = obj;
    }
    return r;
}
