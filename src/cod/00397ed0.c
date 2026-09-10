/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char pad0[0x10];
    int           open;
    unsigned char pad14[0x8];
} PadInfoT;

extern PadInfoT D_0077C110[2][4];



__attribute__((section(".text.func_00397ED0")))
int func_00397ED0(int port, int slot)
{
    unsigned char *p;

    if (D_0077C110[port][slot].open == 0)
        return 0;
    p = func_00397BC8(port, slot, 0);
    return p[0x71];
}
