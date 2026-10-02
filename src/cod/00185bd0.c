/* sn-2.95.3-136 matched TU. */

extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_001B76D8(void *a0);
extern void cCollisionSolidManage_ChkHit(void *, void *);
extern char D_00462FC0[];
extern void cOmBase_setMeshDispFromLayer(int a0, int a1, int a2);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void SetEffect(int a0, int a1, int a2, int a3, int a4, unsigned int a5);
extern int D_005FEE00;
extern void func_001B6FB8(void *a0);
extern void *cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern void func_001FD9D8(void *a0, void *a1, float *a2, float *a3, float *t0);
extern void func_001BFB28(void *a0);
extern int D_00574380;

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_00194480 { short f0; short f2; short f4; short f6; };
struct Table_func_00194480 { struct Entry_func_00194480 e[1]; };



extern struct Table_func_00194480 D_003BDB48;



__attribute__((section(".text.func_00194480")))
void func_00194480(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDB48 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDB48 + i8 + 4);
    }
    f0 = D_003BDB48.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cCollisionSolidManage_ChkHit(D_00462FC0, s0);
    func_001B76D8(s0);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_001A5470 { short f0; short f2; short f4; short f6; };
struct Table_func_001A5470 { struct Entry_func_001A5470 e[1]; };



extern struct Table_func_001A5470 D_003BDB98;



__attribute__((section(".text.func_001A5470")))
void func_001A5470(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDB98 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDB98 + i8 + 4);
    }
    f0 = D_003BDB98.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cCollisionSolidManage_ChkHit(D_00462FC0, s0);
    func_001B76D8(s0);
}

/* Show the mesh layer picked by arg1 (0 or 1) and hide the other; arg1 == 4 plays the sound effect and spawns effect 0x298 instead. */





__attribute__((section(".text.func_00185BD0")))
void func_00185BD0(int arg0, int arg1)
{
    cOmBase_setMeshDispFromLayer(arg0, 0x28, 0);
    cOmBase_setMeshDispFromLayer(arg0, 0x29, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(arg0, 0x28, 1);
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(arg0, 0x29, 1);
        break;
    case 4:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x113, arg0, 0, 0, 0, 0);
        SetEffect(0x298, 4, arg0, 0, -1, 0xFFFFFFFF);
        break;
    }
}

/* Spawn the damage-take volume of an object: build the three float vectors and register them, then set the two shorts at +0x548 and +0x54A. */






__attribute__((section(".text.func_0018ED30")))
int func_0018ED30(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 0.90639997f;
    cb = 2.0f;
    cc = 0.2f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[4] = ca;
    f[1] = cb;
    f[2] = cc;
    f[6] = cc;
    f[5] = cb;
    f[3] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[10] = 0.0f;
    f[9] = f[1] * -0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    func_001BFB28(p);
    return 1;
}

/* Spawn the damage-take volume of an object: build the three float vectors and register them, then set the two shorts at +0x548 and +0x54A. */






__attribute__((section(".text.func_0019D848")))
int func_0019D848(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.6f;
    cb = 1.5f;
    cc = 0.2f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[4] = ca;
    f[1] = cb;
    f[2] = cc;
    f[6] = cc;
    f[5] = cb;
    f[3] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[10] = 0.0f;
    f[9] = f[1] * -0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    func_001BFB28(p);
    return 1;
}

/* Spawn the damage-take volume of an object: build the three float vectors and register them, then set the two shorts at +0x548 and +0x54A. */






__attribute__((section(".text.func_0019C1B0")))
int func_0019C1B0(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 0.84f;
    cb = 1.356f;
    cc = 0.84f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[2] = cc;
    f[1] = cb;
    f[4] = ca;
    f[6] = cc;
    f[5] = cb;
    f[3] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[10] = 0.0f;
    f[9] = f[1] * -0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    func_001BFB28(p);
    return 1;
}
