/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char pad0[0x10];
    int           open;
    unsigned char pad14[0x8];
} PadInfoT;

extern PadInfoT D_0077C110[2][4];



extern int scePadSetButtonInfo(int port, int slot, int mask);

__attribute__((section(".text.scePadEnterPressMode")))
int scePadEnterPressMode(int port, int slot)
{
    if (D_0077C110[port][slot].open == 0)
        return 0;
    return scePadSetButtonInfo(port, slot, 0xFFF);
}
