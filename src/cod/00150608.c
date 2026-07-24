/* sn-2.95.3-136 matched TU. */

extern void SetFlagOnEntries7C_1D51B8(void *a0, int a1, int a2);
extern void SetCustomIDDispOneOrAll_1DD258(void *a0, int a1, int a2);
extern int D_00466470;
extern void func_002A9790(void *);
extern int D_004664A0;
extern void func_001508F8(void *);
extern int D_00566E50;
extern void func_001612C8(void *);
extern int D_00568240;
extern void ClearField00_1F6CE0(void *);
extern int D_00580D40;
extern void InitSlotTable_1FF800(void *);
extern int D_00583F20;
extern void GetSelf_200AB0(void *);
extern int D_005864F0;
extern void func_00290090(void *);
extern int D_00586AB0;
extern void cEmSetParam_roomInit(void *);
extern int D_005CB000;
extern void func_002A98A8(void *);
extern int D_005E6900;
extern void func_002AE3D0(void *);
extern int D_005E75B0;
extern void func_001380A8(void *);
extern int D_005E8040;
extern void InitVtableEntry_2B8AE0(void *);
extern int D_005FEC58;
extern void func_002C8E60(void *);
extern int D_00603A40;
extern void func_002D2DC8(void *);
extern int D_00604700;
extern void func_002D6D80(void *);
extern int D_0061A998;
extern void Obj0000_Set_Vtbl_D_0044D388_2D9E18(void *);
extern void func_001B6FB8(void *);
extern void func_0032DB70(int);
extern void func_0032E040(int, int);
extern void func_0032D6F0(int);
extern void func_0031C900(int);
extern void SetFields_4_And_8_1FE6B8(void *, void *, int);
extern char D_005864E0[];
extern char D_00585960[];
extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);
extern struct Table_00171200 D_003BD9F0;
extern struct Table_0017BA28 D_003BDA40;
extern struct Table_0017ED00 D_003BDA88;
extern struct Table_00182A18 D_003BDB20;
extern struct Table_001841E8 D_003BDB38;
extern struct Table_00195F18 D_003BDB68;
extern struct Table_001A85B8 D_003BDBD0;
extern struct Table_001A8A70 D_003BDBF0;
extern struct Table_001B3800 D_003BDD20;
extern struct Table_001B6968 D_003BDD78;
extern struct Table_001BD6B0 D_003BDDC8;
extern struct Table_001BE950 D_003BDE08;
extern struct Table_001BF518 D_003BDE30;

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001D5360")))
void func_001D5360(void *a0, unsigned char a1) {
    switch (a1) {
    case 0:
        SetFlagOnEntries7C_1D51B8(a0, 0xB, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0xC, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0x23, 1);
        break;
    case 1:
        SetFlagOnEntries7C_1D51B8(a0, 0xB, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0xC, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0x23, 1);
        break;
    case 2:
        SetFlagOnEntries7C_1D51B8(a0, 0xB, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0xC, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0x23, 1);
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001D5430")))
void func_001D5430(void *a0, unsigned char a1) {
    switch (a1) {
    case 0:
        SetFlagOnEntries7C_1D51B8(a0, 0x9, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0xa, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0x24, 1);
        break;
    case 1:
        SetFlagOnEntries7C_1D51B8(a0, 0x9, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0xa, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0x24, 1);
        break;
    case 2:
        SetFlagOnEntries7C_1D51B8(a0, 0x9, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0xa, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0x24, 1);
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001D5500")))
void func_001D5500(void *a0, unsigned char a1) {
    switch (a1) {
    case 0:
        SetFlagOnEntries7C_1D51B8(a0, 0xd, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0xe, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0xf, 1);
        break;
    case 1:
        SetFlagOnEntries7C_1D51B8(a0, 0xd, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0xe, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0xf, 1);
        break;
    case 2:
        SetFlagOnEntries7C_1D51B8(a0, 0xd, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0xe, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0xf, 1);
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001D5690")))
void func_001D5690(void *a0, unsigned char a1) {
    switch (a1) {
    case 0:
        SetFlagOnEntries7C_1D51B8(a0, 0x10, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0x11, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0x12, 1);
        break;
    case 1:
        SetFlagOnEntries7C_1D51B8(a0, 0x10, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0x11, 1);
        SetFlagOnEntries7C_1D51B8(a0, 0x12, 1);
        break;
    case 2:
        SetFlagOnEntries7C_1D51B8(a0, 0x10, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0x11, 0);
        SetFlagOnEntries7C_1D51B8(a0, 0x12, 1);
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001DD770")))
void func_001DD770(void *a0, unsigned char a1) {
    switch (a1) {
    case 0:
        SetCustomIDDispOneOrAll_1DD258(a0, 0x3, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x4, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x5, 1);
        break;
    case 1:
        SetCustomIDDispOneOrAll_1DD258(a0, 0x3, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x4, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x5, 1);
        break;
    case 2:
        SetCustomIDDispOneOrAll_1DD258(a0, 0x3, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x4, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x5, 1);
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001DD840")))
void func_001DD840(void *a0, unsigned char a1) {
    switch (a1) {
    case 0:
        SetCustomIDDispOneOrAll_1DD258(a0, 0x6, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x7, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x8, 1);
        break;
    case 1:
        SetCustomIDDispOneOrAll_1DD258(a0, 0x6, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x7, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x8, 1);
        break;
    case 2:
        SetCustomIDDispOneOrAll_1DD258(a0, 0x6, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x7, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0x8, 1);
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001DD9E0")))
void func_001DD9E0(void *a0, unsigned char a1) {
    switch (a1) {
    case 0:
        SetCustomIDDispOneOrAll_1DD258(a0, 0xc, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0xd, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0xe, 1);
        break;
    case 1:
        SetCustomIDDispOneOrAll_1DD258(a0, 0xc, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0xd, 1);
        SetCustomIDDispOneOrAll_1DD258(a0, 0xe, 1);
        break;
    case 2:
        SetCustomIDDispOneOrAll_1DD258(a0, 0xc, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0xd, 0);
        SetCustomIDDispOneOrAll_1DD258(a0, 0xe, 1);
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00150608")))
void func_00150608(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_002A9790(&D_00466470);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001523F8")))
void func_001523F8(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_001508F8(&D_004664A0);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00161480")))
void func_00161480(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_001612C8(&D_00566E50);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001F6E18")))
void func_001F6E18(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        ClearField00_1F6CE0(&D_00568240);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001FFDB0")))
void func_001FFDB0(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        InitSlotTable_1FF800(&D_00580D40);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00201A80")))
void func_00201A80(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        GetSelf_200AB0(&D_00583F20);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00294AE0")))
void func_00294AE0(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_00290090(&D_005864F0);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00295928")))
void func_00295928(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        cEmSetParam_roomInit(&D_00586AB0);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002A9D30")))
void func_002A9D30(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_002A98A8(&D_005CB000);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002AE940")))
void func_002AE940(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_002AE3D0(&D_005E6900);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002B4850")))
void func_002B4850(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_001380A8(&D_005E75B0);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002BA428")))
void func_002BA428(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        InitVtableEntry_2B8AE0(&D_005E8040);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002C9C38")))
void func_002C9C38(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_002C8E60(&D_005FEC58);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002D31B0")))
void func_002D31B0(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_002D2DC8(&D_00603A40);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002D9B70")))
void func_002D9B70(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_002D6D80(&D_00604700);
    }
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002D9E98")))
void func_002D9E98(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        Obj0000_Set_Vtbl_D_0044D388_2D9E18(&D_0061A998);
    }
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_001A96E8")))
int func_001A96E8(void *a0){ func_001B6FB8(a0); *(int*)((char*)a0+0x250)|=0x10000; return 1; }

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00381D60")))
void func_00381D60(int a0, int a1, int a2)
{
    int t;
    func_0032DB70(*(int*)((char*)a1+0x20));
    if (*(unsigned char*)((char*)a2+0x0) != 0) {
        *(char*)((char*)a2+0x0) = 0;
        func_0032E040(*(int*)((char*)a1+0x20), 0);
    }
    func_0032D6F0(*(int*)((char*)a1+0x20));
    t = *(int*)((char*)a1+0x24);
    *(int*)((char*)a1+0x20) = 0;
    func_0031C900(t);
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_0028FF80")))
void func_0028FF80(int enable, int id) {
    int i;
    if (id != 0xFFFF) return;
    if (enable == 0) return;
    i = 0x20;
    while (i--) { ; }
    SetFields_4_And_8_1FE6B8(D_005864E0, D_00585960, 0x20);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_00171200 { short f0; short f2; short f4; short f6; };
struct Table_00171200 { struct Entry_00171200 e[1]; };


__attribute__((section(".text.func_00171200")))
void func_00171200(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BD9F0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BD9F0 + i8 + 4);
    }
    f0 = D_003BD9F0.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_0017BA28 { short f0; short f2; short f4; short f6; };
struct Table_0017BA28 { struct Entry_0017BA28 e[1]; };


__attribute__((section(".text.func_0017BA28")))
void func_0017BA28(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDA40 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDA40 + i8 + 4);
    }
    f0 = D_003BDA40.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_0017ED00 { short f0; short f2; short f4; short f6; };
struct Table_0017ED00 { struct Entry_0017ED00 e[1]; };


__attribute__((section(".text.func_0017ED00")))
void func_0017ED00(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDA88 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDA88 + i8 + 4);
    }
    f0 = D_003BDA88.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_00182A18 { short f0; short f2; short f4; short f6; };
struct Table_00182A18 { struct Entry_00182A18 e[1]; };


__attribute__((section(".text.func_00182A18")))
void func_00182A18(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDB20 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDB20 + i8 + 4);
    }
    f0 = D_003BDB20.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_001841E8 { short f0; short f2; short f4; short f6; };
struct Table_001841E8 { struct Entry_001841E8 e[1]; };


__attribute__((section(".text.func_001841E8")))
void func_001841E8(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDB38 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDB38 + i8 + 4);
    }
    f0 = D_003BDB38.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_00195F18 { short f0; short f2; short f4; short f6; };
struct Table_00195F18 { struct Entry_00195F18 e[1]; };


__attribute__((section(".text.func_00195F18")))
void func_00195F18(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDB68 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDB68 + i8 + 4);
    }
    f0 = D_003BDB68.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_001A85B8 { short f0; short f2; short f4; short f6; };
struct Table_001A85B8 { struct Entry_001A85B8 e[1]; };


__attribute__((section(".text.func_001A85B8")))
void func_001A85B8(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDBD0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDBD0 + i8 + 4);
    }
    f0 = D_003BDBD0.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_001A8A70 { short f0; short f2; short f4; short f6; };
struct Table_001A8A70 { struct Entry_001A8A70 e[1]; };


__attribute__((section(".text.func_001A8A70")))
void func_001A8A70(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDBF0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDBF0 + i8 + 4);
    }
    f0 = D_003BDBF0.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_001B3800 { short f0; short f2; short f4; short f6; };
struct Table_001B3800 { struct Entry_001B3800 e[1]; };


__attribute__((section(".text.func_001B3800")))
void func_001B3800(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDD20 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDD20 + i8 + 4);
    }
    f0 = D_003BDD20.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_001B6968 { short f0; short f2; short f4; short f6; };
struct Table_001B6968 { struct Entry_001B6968 e[1]; };


__attribute__((section(".text.func_001B6968")))
void func_001B6968(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDD78 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDD78 + i8 + 4);
    }
    f0 = D_003BDD78.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_001BD6B0 { short f0; short f2; short f4; short f6; };
struct Table_001BD6B0 { struct Entry_001BD6B0 e[1]; };


__attribute__((section(".text.func_001BD6B0")))
void func_001BD6B0(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDDC8 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDDC8 + i8 + 4);
    }
    f0 = D_003BDDC8.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_001BE950 { short f0; short f2; short f4; short f6; };
struct Table_001BE950 { struct Entry_001BE950 e[1]; };


__attribute__((section(".text.func_001BE950")))
void func_001BE950(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDE08 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDE08 + i8 + 4);
    }
    f0 = D_003BDE08.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

/* sn-2.95.3-136 matched TU. */





struct Entry_001BF518 { short f0; short f2; short f4; short f6; };
struct Table_001BF518 { struct Entry_001BF518 e[1]; };


__attribute__((section(".text.func_001BF518")))
void func_001BF518(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDE30 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDE30 + i8 + 4);
    }
    f0 = D_003BDE30.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}
