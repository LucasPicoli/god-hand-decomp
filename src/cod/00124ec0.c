/* sn-2.95.3-136 matched TU. */

extern int D_00463050;

typedef unsigned char unsigned char;

typedef struct Sub {
    char pad0[0x6C];
    int unk6C;  /* 0x6C */
    int unk70;  /* 0x70 */
} Sub;

typedef struct Obj_00124ec0 {
    char pad0[0x278];
    Sub *unk278;                 /* 0x278 */
    char pad27C[0x2B4 - 0x27C];
    unsigned char unk2B4;                   /* 0x2B4 */
    char pad2B5[0x15F4 - 0x2B5];
    int unk15F4;                 /* 0x15F4 */
} Obj_00124ec0;



void cCamManager_setPartsCamera(void *cam, int mode);
void Obj0000_Set_Fields_360_364_368_139B68(void *parts, Obj_00124ec0 *obj, int a2, int a3);

__attribute__((section(".text.func_00124EC0")))
void func_00124EC0(Obj_00124ec0 *obj) {
    unsigned char *base;
    void *parts;
    int a2v;
    int a3v;
    int b;
    int lim;
    int spill[2];

    base = (unsigned char *)&D_00463050;
    cCamManager_setPartsCamera(base, 0);
    parts = base + 0x920;

    b = obj->unk2B4;
    spill[0] = b;
    lim = 0x1B;
    if (lim < b) {
        a2v = obj->unk278->unk6C;
    } else {
        a2v = 0;
    }

    b = obj->unk2B4;
    spill[0] = b;
    lim = 0x1C;
    if (lim < b) {
        a3v = obj->unk278->unk70;
    } else {
        a3v = 0;
    }

    Obj0000_Set_Fields_360_364_368_139B68(parts, obj, a2v, a3v);
    obj->unk15F4 |= 2;
}
