/* sn-2.95.3-136 matched TU. */

extern char D_00450D80[];
extern char D_00450D90[];
extern char D_00450DA8[];
extern void func_003A6A20(const char *s);
extern int scePadPortOpen(int port, int slot, void *data);
extern int sceSifCheckStatRpc(void *cd);
extern unsigned char D_0076A880[];

__attribute__((section(".text.func_0031A718")))
void func_0031A718(char *buf) {
    unsigned char *p;
    int i;

    while (func_00397630(0) == 0) {
        func_003A6A20(D_00450D80);
    }

    if (scePadPortOpen(0, 0, buf) == 0) {
        func_003A6A20(D_00450D90);
    }
    if (scePadPortOpen(1, 0, buf + 0x380) == 0) {
        func_003A6A20(D_00450DA8);
    }

    p = (unsigned char *)(buf + 0x360);

    *(short *)(buf + 0x148) = 0;
    *(int *)(buf + 0x154) = 0;
    *(short *)(buf + 0x14A) = 0;
    *(char *)(buf + 0x158) = 0;
    *(char *)(buf + 0x159) = 1;
    *(unsigned char *)(buf + 0x15D) = 0xFF;
    *(unsigned char *)(buf + 0x15C) = 0xFF;
    *(unsigned char *)(buf + 0x15B) = 0xFF;
    *(char *)(buf + 0x4B8) = 1;
    *(unsigned char *)(buf + 0x15A) = 0xFF;

    for (i = 5; i != -1; i--) {
        p[i] = 0;
    }
}

__attribute__((section(".text.func_003758E8")))
int func_003758E8(int arg0) {
    unsigned char *base = D_0076A880;
    void *cd = base + 0xDC;
    int i;

    while (sceSifCheckStatRpc(base + 0xDC)) {
        i = 10000;
        while (i--) {
            ;
        }
    }

    func_003B3128(cd, arg0, 1, base, 0x40, base + 0x40, 0x40, 0, 0);
    return *(int *)(base + 0x40);
}
