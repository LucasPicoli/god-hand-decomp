/* sn-2.95.3-136 matched TU. */

extern int scePadSetMainMode(int port, int slot, int offs, int lock);
extern int scePadSetActAlign(int port, int slot, const unsigned char *align);
extern int scePadEnterPressMode(int port, int slot);
extern void func_0031B560(void *a, void *b, int c);
extern void func_0031AFE0(void *a, void *b, void *c);
extern void func_0031BB80(void *a);
extern unsigned char D_007474A0[];
extern unsigned int D_00747A78;
extern long D_003C3D38;
extern long D_003C3D40;
extern long D_003C3D48;

__attribute__((section(".text.func_0031A808")))
void func_0031A808(char *p) {
    unsigned char *c0;
    unsigned char *ctx;
    int r;
    int r2;
    int st;
    unsigned char *q;

    c0 = D_007474A0;
    if (*(int *)(c0 + 0x56C) == 0) {
        D_003C3D38 = 0x800000000L;
        D_003C3D40 = 0x200000000L;
        D_003C3D48 = 0x100000000L;
    } else {
        D_003C3D38 = 0x40;
        D_003C3D40 = 0x10;
        D_003C3D48 = 0x10;
    }
    ctx = D_007474A0;

    r = func_00397D98(0, 0);
    *(int *)(p + 0x140) = r;
    if (r == 6 || r == 2) {
        if (*(int *)(p + 0x154) & 1) {
            if (*(unsigned short *)(p + 0x14A) != func_00397F38(0, 0, 1, 0)) {
                *(int *)(p + 0x154) = 0;
                *(unsigned short *)(p + 0x148) = 0;
            }
            func_00397D20(0, 0, (unsigned char *)(p + 0x100));
            goto tail0;
        }
        switch (*(unsigned short *)(p + 0x148)) {
        case 0:
            r2 = func_00397F38(0, 0, 1, 0);
            if (r2 == 4 || r2 == 7) {
                st = *(int *)(p + 0x154);
                *(unsigned short *)(p + 0x148) = 1;
                *(int *)(p + 0x154) = st | 2;
                if (r2 == 7) {
                    *(int *)(p + 0x154) = st | 6;
                }
            }
            break;
        case 1:
            if (func_00397F38(0, 0, 2, 0) == 2) {
                *(int *)(p + 0x154) |= 8;
            }
            *(unsigned short *)(p + 0x148) = 2;
            break;
        case 2:
            if (scePadSetMainMode(0, 0, 1, 3) == 1) {
                *(unsigned short *)(p + 0x148) = 3;
            }
            break;
        case 3:
            {
                int r2 = func_00397ED0(0, 0);
                if (r2 != 0) {
                    if (r2 == 1) {
                        *(unsigned short *)(p + 0x148) = 2;
                    }
                } else {
                    *(unsigned short *)(p + 0x148) = 4;
                    *(int *)(p + 0x154) |= 0x10;
                }
            }
            break;
        case 4:
            if (scePadSetActAlign(0, 0, (unsigned char *)(p + 0x158)) != 0) {
                *(unsigned short *)(p + 0x148) = 5;
            }
            break;
        case 5:
            {
                int r2 = func_00397ED0(0, 0);
                if (r2 != 0) {
                    if (r2 == 1) {
                        *(unsigned short *)(p + 0x148) = 4;
                    }
                } else {
                    *(unsigned short *)(p + 0x148) = 6;
                    *(int *)(p + 0x154) |= 0x20;
                }
            }
            break;
        case 6:
            if (func_00397F38(0, 0, 1, 0) == 7) {
                *(int *)(p + 0x154) |= 4;
            }
            *(unsigned short *)(p + 0x148) = 7;
            break;
        case 7:
            if (func_00398378(0, 0) != 0) {
                if (scePadEnterPressMode(0, 0) != 0) {
                    *(unsigned short *)(p + 0x148) = 8;
                    *(int *)(p + 0x154) |= 0x40;
                }
            } else {
                *(unsigned short *)(p + 0x148) = 9;
            }
            break;
        case 8:
            {
                int r2 = func_00397ED0(0, 0);
                if (r2 != 0) {
                    if (r2 == 1) {
                        *(unsigned short *)(p + 0x148) = 7;
                    }
                } else {
                    *(unsigned short *)(p + 0x148) = 9;
                }
            }
            break;
        case 9:
            *(int *)(p + 0x154) |= 1;
            *(unsigned short *)(p + 0x14A) = func_00397F38(0, 0, 1, 0);
            *(unsigned short *)(p + 0x148) = 0;
            break;
        }
        *(unsigned short *)(p + 0x102) = 0xFFFF;
    } else {
        *(unsigned short *)(p + 0x102) = 0xFFFF;
        *(unsigned int *)(p + 0x104) = 0x80808080;
        if (r == 0) {
            *(int *)(p + 0x154) = 0;
            *(unsigned short *)(p + 0x148) = 0;
        }
    }
tail0:
    if ((*(int *)(p + 0x154) & 4) == 0) {
        *(unsigned int *)(p + 0x104) = 0x80808080;
    }
    {
        unsigned int v = *(unsigned short *)(p + 0x102);
        unsigned int w = *(unsigned int *)(p + 0x104);
        *(unsigned short *)(p + 0x102) = ~v;
        *(unsigned int *)(p + 0x104) = ~w;
    }
    func_0031B560(p, ctx, 1);
    func_0031AFE0(p, ctx + 0x178, ctx);

    r = func_00397D98(1, 0);
    *(int *)(p + 0x144) = r;
    if (r == 6 || r == 2) {
        if (*(int *)(p + 0x4AC) & 1) {
            if (*(unsigned short *)(p + 0x4A2) != func_00397F38(1, 0, 1, 0)) {
                *(int *)(p + 0x4AC) = 0;
                *(unsigned short *)(p + 0x4A0) = 0;
            }
            func_00397D20(1, 0, (unsigned char *)(p + 0x480));
            goto tail1;
        }
        switch (*(unsigned short *)(p + 0x4A0)) {
        case 0:
            r2 = func_00397F38(1, 0, 1, 0);
            if (r2 == 4 || r2 == 7) {
                st = *(int *)(p + 0x4AC);
                *(unsigned short *)(p + 0x4A0) = 1;
                *(int *)(p + 0x4AC) = st | 2;
                if (r2 == 7) {
                    *(int *)(p + 0x4AC) = st | 6;
                }
            }
            break;
        case 1:
            if (func_00397F38(1, 0, 2, 0) == 2) {
                *(int *)(p + 0x4AC) |= 8;
            }
            *(unsigned short *)(p + 0x4A0) = 2;
            break;
        case 2:
            if (scePadSetMainMode(1, 0, 1, 3) == 1) {
                *(unsigned short *)(p + 0x4A0) = 3;
            }
            break;
        case 3:
            {
                int r2 = func_00397ED0(1, 0);
                if (r2 != 0) {
                    if (r2 == 1) {
                        *(unsigned short *)(p + 0x4A0) = 2;
                    }
                } else {
                    *(unsigned short *)(p + 0x4A0) = 4;
                    *(int *)(p + 0x4AC) |= 0x10;
                }
            }
            break;
        case 4:
            if (scePadSetActAlign(1, 0, (unsigned char *)(p + 0x4B0)) != 0) {
                *(unsigned short *)(p + 0x4A0) = 5;
            }
            break;
        case 5:
            {
                int r2 = func_00397ED0(1, 0);
                if (r2 != 0) {
                    if (r2 == 1) {
                        *(unsigned short *)(p + 0x4A0) = 4;
                    }
                } else {
                    *(unsigned short *)(p + 0x4A0) = 6;
                    *(int *)(p + 0x4AC) |= 0x20;
                }
            }
            break;
        case 6:
            if (func_00397F38(1, 0, 1, 0) == 7) {
                *(int *)(p + 0x4AC) |= 4;
            }
            *(unsigned short *)(p + 0x4A0) = 7;
            break;
        case 7:
            if (func_00398378(1, 0) != 0) {
                if (scePadEnterPressMode(1, 0) != 0) {
                    *(unsigned short *)(p + 0x4A0) = 8;
                    *(int *)(p + 0x4AC) |= 0x40;
                }
            } else {
                *(unsigned short *)(p + 0x4A0) = 9;
            }
            break;
        case 8:
            {
                int r2 = func_00397ED0(1, 0);
                if (r2 != 0) {
                    if (r2 == 1) {
                        *(unsigned short *)(p + 0x4A0) = 7;
                    }
                } else {
                    *(unsigned short *)(p + 0x4A0) = 9;
                }
            }
            break;
        case 9:
            *(int *)(p + 0x4AC) |= 1;
            *(unsigned short *)(p + 0x4A2) = func_00397F38(1, 0, 1, 0);
            *(unsigned short *)(p + 0x4A0) = 0;
            break;
        }
        *(unsigned short *)(p + 0x482) = 0xFFFF;
    } else {
        *(unsigned short *)(p + 0x482) = 0xFFFF;
        *(unsigned int *)(p + 0x484) = 0x80808080;
        if (r == 0) {
            *(int *)(p + 0x4AC) = 0;
            *(unsigned short *)(p + 0x4A0) = 0;
        }
    }
tail1:
    if ((*(int *)(p + 0x4AC) & 4) == 0) {
        *(unsigned int *)(p + 0x484) = 0x80808080;
    }
    q = (unsigned char *)(p + 0x480);
    func_00397D20(1, 0, q);
    {
        unsigned int v = *(unsigned short *)(p + 0x482);
        unsigned int w = *(unsigned int *)(p + 0x484);
        *(unsigned short *)(p + 0x482) = ~v;
        *(unsigned int *)(p + 0x484) = ~w;
    }
    if (D_00747A78 & 0x1000000) {
        func_0031B560(p, ctx + 0x7C, 0);
    } else {
        func_0031B560(p, ctx + 0x7C, 0);
    }
    func_0031BB80(p);
}
