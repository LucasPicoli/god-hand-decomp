/* sn-2.95.3-136 matched TU. */

extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);
extern void cModel_calcParts(void *);
extern void cModel_calcWorldParts(void *);
extern void cCollisionSolidManage_ChkHit(void *, void *);
extern char D_00462FC0[];
extern void func_001C0450(void *);
extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];
extern void cModel_ScrollTexture(void *a0, float f);
extern char D_003C0480[];
extern int D_00574380;
extern int D_005CAE50;
extern int D_00420EF0;
extern void ClearAndResetFields_1FE278(void *a, void *b);
extern void cDamageManage_ReleaseDamageGive(void *a, int b);
extern void func_0012EC58(void *a, int b);
extern void *SetField214PtrThenInit_1B6F38(void *a, void *b);

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_001788A0 { short f0; short f2; short f4; short f6; };
struct Table_func_001788A0 { struct Entry_func_001788A0 e[1]; };




extern struct Table_func_001788A0 D_003BDA08;



__attribute__((section(".text.func_001788A0")))
void func_001788A0(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDA08 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDA08 + i8 + 4);
    }
    f0 = D_003BDA08.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
    cModel_calcParts(s0);
    cModel_calcWorldParts(s0);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_001B0468 { short f0; short f2; short f4; short f6; };
struct Table_func_001B0468 { struct Entry_func_001B0468 e[1]; };




extern struct Table_func_001B0468 D_003BDC98;



__attribute__((section(".text.func_001B0468")))
void func_001B0468(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDC98 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDC98 + i8 + 4);
    }
    f0 = D_003BDC98.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cCollisionSolidManage_ChkHit(D_00462FC0, s0);
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_001C0378 { short f0; short f2; short f4; short f6; };
struct Table_func_001C0378 { struct Entry_func_001C0378 e[1]; };




extern struct Table_func_001C0378 D_003BDE40;


__attribute__((section(".text.func_001C0378")))
void func_001C0378(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; void (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDE40 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (void (*)(int))(int)(entry >> 32);
    } else {
        fp = *(void (**)(int))((char *)&D_003BDE40 + i8 + 4);
    }
    f0 = D_003BDE40.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    if (*(unsigned char *)(s0 + 0x675) == 0) {
        func_002A87E8(s0, 0);
    }
    func_001C0450(s0);
    func_001B76D8(s0);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_001AEDB0 { short f0; short f2; short f4; short f6; };
struct Table_func_001AEDB0 { struct Entry_func_001AEDB0 e[1]; };




extern struct Table_func_001AEDB0 D_003BDC68;






__attribute__((section(".text.func_001AEDB0")))
void func_001AEDB0(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    float rate;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDC68 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDC68 + i8 + 4);
    }
    f0 = D_003BDC68.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    rate = cEmManage_GetSpeedRate(D_005864F0);
    *(float *)(s0 + 0x5A8) = rate;
    cModel_ScrollTexture(s0, rate);
    cCollisionSolidManage_ChkHit(D_00462FC0, s0);
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* Tick: dispatch the current action: pick the table entry for state byte +0x2F5 (reset to 0 when out of range) and call its handler, then sync. */



__attribute__((section(".text.func_0028A4A0")))
void func_0028A4A0(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 1) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003C0480 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003C0480 + i8 + 4);
    }
    f0 = *(short *)(D_003C0480 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
}

/* Release an object's slot array: free the slot at +0x600, the damage give at +0x604 and the entry at +0xDA8, then reset the base. */








__attribute__((section(".text.func_00171D20")))
void *func_00171D20(void *a0, void *a1) {
    int *p = (int *)((char *)a0 + 0x600);
    int i = 0;
    *(int **)((char *)a0 + 0x214) = &D_00420EF0;
    do {
        if (*p != 0) {
            ClearAndResetFields_1FE278(&D_00574380, (void *)*p);
            *p = 0;
        }
        p++;
        i--;
    } while (i >= 0);
    if (*(int *)((char *)a0 + 0x604) != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, *(int *)((char *)a0 + 0x604));
        *(int *)((char *)a0 + 0x604) = 0;
    }
    if (*(int *)((char *)a0 + 0xDA8) != 0) {
        func_0012EC58(&D_005CAE50, *(int *)((char *)a0 + 0xDA8));
        *(int *)((char *)a0 + 0xDA8) = 0;
    }
    return SetField214PtrThenInit_1B6F38(a0, a1);
}
