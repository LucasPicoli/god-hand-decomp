/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136, -f=-fno-gcse */

extern void func_001B6FB8(void *a0);
extern void *AllocActiveSlot_1FE218(void *a0, void *a1, int a2);
extern void cDamageUnit_AddDamageCollCylinder(void *a0, void *a1, float *a2, float *a3, float f0, float f1);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern int D_00574380;

__attribute__((section(".text.func_00179E40")))
int func_00179E40(char *p)
{
    float f[8];
    float *nv;
    void *slot;
    float one;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    f[0] = 0.0f;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = one;
    slot = AllocActiveSlot_1FE218(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[4];
        f[4] = 0.0f;
        f[5] = 0.0f;
        f[6] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, f, nv, one, 0.600000024f);
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
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[0] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (!(i < 9 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}
