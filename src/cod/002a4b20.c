/* ee-2.9-991111 matched TU. */

extern int D_00747A0C;

__attribute__((section(".text.func_002A4B20")))
int func_002A4B20(char *base, unsigned short id)
{
    int a;
    unsigned int t;

    if (id == 0) {
        if (D_00747A0C != 0) return 4;
        return 8;
    }
    { unsigned int off = (id >> 12) * 16; a = *(int *)(base + off + 4); }
    t = *(unsigned int *)((((id & 0xFFF) << 2) + a) + 8);
    return (short)(((t >> 20) & 0x3F) - ((t >> 8) & 0x3F) + 1);
}
