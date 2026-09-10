/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char  a[0x50];
    unsigned short w[8];
    unsigned char  b[0x20];
} PadFrame;

typedef struct {
    unsigned char pad0[0x10];
    int           open;
    unsigned char pad14[0x8];
} PadInfoT;

extern PadInfoT D_0077C110[2][4];


__attribute__((section(".text.func_00397F38")))
int func_00397F38(int port, int slot, int term, int offs)
{
    PadFrame fr;

    if (D_0077C110[port][slot].open == 0)
        return 0;
    func_00397BC8(port, slot, &fr);
    if (fr.b[0x12] != 1)
        return 0;
    if (fr.b[0x11] == 2)
        return 0;
    switch (term) {
    case 1:
        if (fr.b[5] == 0xF3)
            return 0;
        return fr.b[5] >> 4;
    case 2:
        if (fr.b[4] == 1)
            return 0;
        return fr.w[fr.b[9]];
    case 3:
        if (fr.b[4] == 1)
            return 0;
        return fr.b[9];
    case 4:
        if (fr.b[4] == 1)
            return 0;
        if (offs == -1)
            return fr.b[8];
        if (offs >= fr.b[8])
            return 0;
        return fr.w[offs];
    }
    return 0;
}
