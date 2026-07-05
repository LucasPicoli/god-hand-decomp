/* sn-2.95.3-136 matched TU. */

extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_001A6558(void *a0);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);
extern struct Table_1A D_004273C0;
extern void func_001BD430(void *a0);
extern struct Table_1B D_00429258;

struct Entry_1A { short f0; unsigned short type; unsigned short f4; short f6; };
struct Table_1A { struct Entry_1A e[4]; };





__attribute__((section(".text.func_001A6188")))
void func_001A6188(void *a0)
{
    char *s0 = (char *)a0;
    struct Table_1A buf;
    char *e;
    int i8;
    int f0;
    long flags; int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    buf = D_004273C0;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&buf + i8;
    type = (short)*(unsigned short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + (short)*(unsigned short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&buf + i8 + 4);
    }
    f0 = buf.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001A6558(s0);
    flags = *(unsigned int *)(s0 + 0x5B0);
    if (((flags >> 1) & 1) == 0)
        func_002A87E8(s0, 0);
    func_001B76D8(s0);
}

struct Entry_1B { short f0; unsigned short type; unsigned short f4; short f6; };
struct Table_1B { struct Entry_1B e[4]; };




__attribute__((section(".text.func_001BC0A0")))
void func_001BC0A0(void *a0)
{
    char *s0 = (char *)a0;
    struct Table_1B buf;
    char *e;
    int i8;
    int f0;
    long flags; int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    flags = *(unsigned int *)(s0 + 0x5B0);
    if (((flags >> 1) & 1) == 0)
        func_001BD430(s0);
    buf = D_00429258;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&buf + i8;
    type = (short)*(unsigned short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + (short)*(unsigned short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&buf + i8 + 4);
    }
    f0 = buf.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001B76D8(s0);
}

__attribute__((section(".text.cOmBase_canItemDrop")))
long cOmBase_canItemDrop(int a0)
{
    long v;
    long b;
    v = *(unsigned int *)(a0 + 0x5B0);
    b = v >> 1 & 1;
    if (b == 1 || *(int *)(a0 + 0x560) == 0x9C3) { return 0; }
    if (*(int *)(a0 + 0x560) != 0xFFFF) { return 1; }
    switch (*(unsigned short *)(a0 + 0x2FE)) {
    case 0x301: case 0x302: case 0x309: case 0x30A: case 0x30B: case 0x30C:
    case 0x325: case 0x32A: case 0x32B: case 0x32C: case 0x32E: case 0x32F:
    case 0x332: case 0x33D: case 0x33F: case 0x340: case 0x341: case 0x342:
    case 0x343: case 0x344: case 0x345: case 0x347: case 0x348: case 0x400:
    case 0x401: case 0x402: case 0x410: case 0x411: case 0x418: case 0x419:
    case 0x41A: case 0x41F: case 0x42E:
        return 1;
    }
    return 0;
}
