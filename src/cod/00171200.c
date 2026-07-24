/* sn-2.95.3-136 matched TU. */

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
