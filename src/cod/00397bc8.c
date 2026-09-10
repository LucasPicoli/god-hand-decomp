/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char b[0x58];
    int           frame;
    unsigned char c[0x24];
} PadData;

typedef struct {
    PadData *buf;
    int      f4;
    int      f8;
    int      dmaid;
    int      open;
    int      f14;
    int      f18;
} PadInfoT;

extern PadInfoT D_0077C110[2][4];



extern void SyncDCache(void *start, void *end);

__attribute__((section(".text.func_00397BC8")))
PadData *func_00397BC8(int port, int slot, PadData *buf)
{
    int oldstat;
    PadData *pd;
    int n;

    oldstat = func_003B63A0();
    pd = D_0077C110[port][slot].buf;
    SyncDCache(pd, (char *)pd + 0xFF);
    n = pd[0].frame < pd[1].frame;
    if (buf != 0)
        *buf = pd[n];
    if (oldstat == 1)
        func_003B63F0();
    return &pd[n];
}
