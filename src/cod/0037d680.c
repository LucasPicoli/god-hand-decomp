/* sn-2.95.3-136 matched TU. */

extern char D_0076A790[];

__attribute__((section(".text.func_0037D680")))
void func_0037D680(char *p) {
    char *g1;

    g1 = D_0076A790;
    if (*(int *)(g1 + 0x14) == 0) {
        *(short *)(p + 0x44) = 0x40;
        return;
    }
    switch (*(unsigned char *)(p + 5)) {
    case 1:
    case 9:
        {
            char *g2 = D_0076A790;
            if (*(int *)(g2 + 0x14) == 1) {
                *(short *)(p + 0x44) = *(unsigned short *)(p + 0x40);
            } else {
                *(short *)(p + 0x44) = *(unsigned short *)(p + 0x42);
            }
        }
        return;
    case 4:
        if (*(unsigned short *)(p + 0x24) & 2) {
            *(short *)(p + 0x44) = *(unsigned short *)(p + 0x40);
            return;
        }
    case 2:
        *(short *)(p + 0x44) = *(unsigned short *)(p + 0x2C);
        return;
    }
}
