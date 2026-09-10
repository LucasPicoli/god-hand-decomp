/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct {
    unsigned char pad0[0x24];
    int           server;
} SifRpcClientData;

extern SifRpcClientData D_0077C0C0[2];
extern int  D_003F85C8;
extern int  D_003F85CC;
extern char D_0045E038[];
extern char D_0045E060[];


extern int  scePadGetModVersion(void);

extern void func_003B1F28(const char *fmt, ...);

__attribute__((section(".text.func_00397630")))
int func_00397630(int mode)
{
    int i;
    int ver;

    if (D_003F85C8 == 0) {
        for (;;) {
            func_003B2F48(&D_0077C0C0[0], 0x80000100, 0);
            if (D_0077C0C0[0].server != 0)
                break;
            i = 0x10000;
            do {
                i--;
            } while (i != -1);
        }
        for (;;) {
            func_003B2F48(&D_0077C0C0[1], 0x80000101, 0);
            if (D_0077C0C0[1].server != 0)
                break;
            i = 0x10000;
            do {
                i--;
            } while (i != -1);
        }
        ver = scePadGetModVersion();
        if ((ver >> 8) != 4) {
            if (D_003F85CC != 0) {
                func_003B1F28(D_0045E038);
                func_003B1F28(D_0045E060, 4, 0, ver >> 8, ver & 0xFF);
            }
            return 0;
        }
    }
    i = func_003977C8(mode);
    D_003F85C8 = 1;
    return i;
}
