/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    int           f0;
    int           f4;
    int           f8;
    unsigned char act[6];
} PadDma;

typedef struct {
    int     f0;
    PadDma *dma;
    int     f8;
    int     fC;
    int     open;
    int     f14;
    int     f18;
} PadInfoT;

extern PadInfoT D_0077C110[2][4];



__attribute__((section(".text.func_00398128")))
int func_00398128(int port, int slot, const unsigned char *data)
{
    unsigned char buf[0x80];
    PadDma *p;
    int i;
    int ret;

    func_00397BC8(port, slot, buf);
    if (buf[0x72] != 1)
        return 0;
    p = D_0077C110[port][slot].dma;
    for (i = 0; i < 6; i++)
        p->act[i] = data[i];
    p->f4 = 1;
    p->f8 = 6;
    ret = 1;
    if (func_003978C8(port, slot) != 1)
        ret = 0;
    return ret;
}
