/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char pad0[0x10];
    int           open;
    unsigned char pad14[0x8];
} PadInfoT;

typedef struct {
    int cmd;
    int port;
    int slot;
    int a;
    int b;
    int c;
    int rest[26];
} PadSif;

extern PadInfoT D_0077C110[2][4];
extern PadSif   D_0077C300;
extern char     D_0077C0C0[];





__attribute__((section(".text.scePadSetMainMode")))
int scePadSetMainMode(int port, int slot, int offs, int lock)
{
    int r;

    D_0077C300.cmd  = 6;
    D_0077C300.port = port;
    D_0077C300.slot = slot;
    D_0077C300.a    = offs;
    D_0077C300.b    = lock;
    if (func_003B3128(D_0077C0C0, 1, 0, &D_0077C300, 128, &D_0077C300, 128, 0, 0) < 0)
        return 0;
    r = D_0077C300.c;
    if (r == 1) {
        func_00397E18(port, slot, 2);
        r = D_0077C300.c;
    }
    return r;
}
