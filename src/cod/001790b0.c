/* sn-2.95.3-136 matched TU. */
#include "godhand/cModel.h"

/* sn-2.95.3-136 */

extern void func_001B6FB8(void *a0);
extern void *cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern void cDamageUnit_AddDamageCollSphere(void *a0, void *a1, float *a2, float f12);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern int D_00574380;

#define SPHERE_RADIUS    0.5f
#define CHILD_FIRST      1
#define CHILD_END        6          /* children below this index get their flags set */

/* Set the object up: one hit point, a damage-take unit with a 0.5 sphere half a unit up, mesh layers 0 (shown) and
 * 0x40 (hidden), and CPARTS_NO_LOCAL and CPARTS_NO_PARENT set on its child objects 1 to 5. Returns 1. */
__attribute__((section(".text.cOmBase_setupSphereVolume")))
int cOmBase_setupSphereVolume(char *p)
{
    float f[4];
    void *slot;
    float one;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    f[0] = 0.0f;
    f[3] = one;
    f[1] = SPHERE_RADIUS;
    f[2] = 0.0f;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        cDamageUnit_AddDamageCollSphere(slot, p + 0x80, f, SPHERE_RADIUS);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&f[0] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= CPARTS_NO_LOCAL;
        ok2 = ((*(int *)&f[0] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= CPARTS_NO_PARENT;
        i++;
        n++;
        if (!(i < CHILD_END && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}
