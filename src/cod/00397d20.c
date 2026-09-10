/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char pad0[0x10];
    int           open;
    unsigned char pad14[0x8];
} PadInfoT;

extern PadInfoT D_0077C110[2][4];



extern void func_003A5148(unsigned char *d, unsigned char *s, int n);

__attribute__((section(".text.func_00397D20")))
int func_00397D20(int port, int slot, unsigned char *data)
{
    unsigned char buf[0x80];

    if (D_0077C110[port][slot].open == 0)
        return 0;
    func_00397BC8(port, slot, buf);
    func_003A5148(data, buf, *(int *)(buf + 0x60));
    return *(int *)(buf + 0x60);
}
