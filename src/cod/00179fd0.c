/* sn-2.95.3-136 matched TU. */

extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_001C7E30(void *a0);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);
extern struct Table_func_00179FD0 D_00421918;

struct Entry_func_00179FD0 { short f0; unsigned short type; unsigned short f4; short f6; };
struct Table_func_00179FD0 { struct Entry_func_00179FD0 e[4]; };

__attribute__((section(".text.func_00179FD0")))
void func_00179FD0(void *a0)
{
    char *s0 = (char *)a0;
    struct Table_func_00179FD0 buf;
    char *e;
    int i8;
    int f0;
    long flags; int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    flags = *(unsigned int *)(s0 + 0x5B0);
    if (((flags >> 2) & 1) == 0) {
        buf = D_00421918;
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
        func_002A87E8(s0, 0);
        func_001B76D8(s0);
    } else {
        func_001C7E30(s0);
    }
}
