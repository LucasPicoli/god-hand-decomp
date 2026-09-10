/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char pad0[0x10];
    int           open;
    unsigned char pad14[0x8];
} PadInfoT;

extern PadInfoT D_0077C110[2][4];



__attribute__((section(".text.func_00397D98")))
int func_00397D98(int port, int slot)
{
    unsigned char buf[0x80];

    if (D_0077C110[port][slot].open == 0)
        return 0x63;
    func_00397BC8(port, slot, buf);
    if (buf[0x70] != 6 || buf[0x71] != 2)
        return buf[0x70];
    return 5;
}
