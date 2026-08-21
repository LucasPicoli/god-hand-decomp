/* sn-2.95.3-136 matched TU. */

extern void func_001B6FB8(void *a0);
extern void *AllocActiveSlot_1FE218(void *a0, void *a1, int a2);
extern void cDamageUnit_AddDamageCollCylinder(void *a0, void *a1, float *a2, float *a3, float f0, float f1);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern int D_00574380;

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_00173AD8")))
int func_00173AD8(char *p)
{
    float f[16];
    float *m;
    float *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[7] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[6] = ca;
    m[3] = one;
    slot = AllocActiveSlot_1FE218(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, f[5], f[4] * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_0017C708")))
int func_0017C708(char *p)
{
    float f[16];
    float *m;
    float *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[7] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[6] = ca;
    m[3] = one;
    slot = AllocActiveSlot_1FE218(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, f[5], f[4] * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_00186A80")))
int func_00186A80(char *p)
{
    float f[16];
    float *m;
    float *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[7] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[6] = ca;
    m[3] = one;
    slot = AllocActiveSlot_1FE218(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, f[5], f[4] * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_0018CF88")))
int func_0018CF88(char *p)
{
    float f[16];
    float *m;
    float *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[7] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[6] = ca;
    m[3] = one;
    slot = AllocActiveSlot_1FE218(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, f[5], f[4] * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_0018DD40")))
int func_0018DD40(char *p)
{
    float f[16];
    float *m;
    float *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[7] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[6] = ca;
    m[3] = one;
    slot = AllocActiveSlot_1FE218(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, f[5], f[4] * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_0019C670")))
int func_0019C670(char *p)
{
    float f[16];
    float *m;
    float *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[7] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[6] = ca;
    m[3] = one;
    slot = AllocActiveSlot_1FE218(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, f[5], f[4] * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
    return 1;
}
