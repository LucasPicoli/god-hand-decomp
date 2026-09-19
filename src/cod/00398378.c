/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111. Donor libpad.o scePadInfoPressMode. */
typedef struct {
    unsigned char pad0[0x10];
    int           open;
    unsigned char pad14[0x8];
} PadInfoT;

extern PadInfoT D_0077C110[2][4];


__attribute__((section(".text.func_00398378")))
int func_00398378(int port, int slot)
{
    unsigned char buf[0x80];

    if (D_0077C110[port][slot].open == 0)
        goto ng;
    func_00397BC8(port, slot, buf);
    if (buf[0x72] == 1)
        goto ok;
ng:
    return 0;
ok:
    if (buf[0x64] < 2)
        goto ng;
    if (buf[0x66] & 2)
        return 1;
    goto ng;
}
