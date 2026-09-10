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



extern int func_00397E18(int port, int slot, int state);



extern void SyncDCache(void *start, void *end);

__attribute__((section(".text.func_00397E18")))
int func_00397E18(int port, int slot, int state)
{
    int oldstat;
    unsigned char *p;

    if (D_0077C110[port][slot].open == 0)
        return 0;
    oldstat = func_003B63A0();
    p = func_00397BC8(port, slot, 0);
    p[0x71] = state;
    SyncDCache(p, p + 0x7F);
    if (oldstat == 1)
        func_003B63F0();
    return 1;
}
