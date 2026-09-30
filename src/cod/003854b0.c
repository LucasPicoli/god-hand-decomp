/* sn-2.95.3-136 matched TU. */

extern void func_002E0DE8();
extern void func_00380720();


extern char D_0045CDE8[], D_0045CE00[], D_0045CE08[], D_0045CE18[], D_0045CE30[], D_0045CE40[];
extern char D_0045CE58[], D_0045CE68[], D_0045CE88[], D_0045CEA8[], D_0045CEC8[], D_0045CED8[];
extern char D_0045CEE0[], D_0045CEE8[], D_0045CEF8[], D_0045CF08[], D_0045CF18[], D_0045CF30[];
extern char D_0045CF40[], D_0045CF50[], D_0045CF70[], D_0045CF88[], D_0045CFA8[], D_0045CFB8[], D_0045CFC8[];
extern int D_003F2848[];
extern int D_003F2840[];
extern int D_003F2820[];

__attribute__((section(".text.func_003854B0")))
void func_003854B0(unsigned char *a0)
{
    char buf[0x100];
    int q[4];
    int *e = (int *)(a0 + 0x4BC);
    unsigned char *s7 = a0 + 0x470;
    unsigned char *s5 = a0 + 0x484;
    int col;
    int mode;
    int t;
    int len;
    char *obj;
    char *name;
    char *fmt;

    func_002E0DE8(0x11, 3, 0xD, D_0045CDE8);
    fmt = D_0045CE08;
    obj = *(char **)(a0 + 0x44);
    len = *(int *)(obj - 0x10);
    if (len == 0) {
        name = D_0045CE00;
    } else {
        obj[len] = 0;
        name = *(char **)(a0 + 0x44);
    }
    func_002E0DE8(3, 5, 8, fmt, name);
    mode = *(int *)(s7 + 0xC);
    switch (mode) {
    case 0:
        col = 0xF;
        break;
    case -1:
        if (s7[1] != 0) {
            func_002E0DE8(0xF, 0x16, 0xE, D_003F2848[s7[1] - 1]);
            func_002E0DE8(0x13, 0x17, 8, D_0045CE18);
        }
    case 5:
        col = 0xF;
        break;
    case 6:
        col = 0xA;
        t = func_0032B0B0(*(int *)(s5 + 0x30));
        func_002E0DE8(0x14, 7, 0xD, D_0045CE30, t);
        break;
    default:
        col = 0xD;
        break;
    }
    func_002E0DE8(3, 7, 0xD, D_0045CE40);
    func_002E0DE8(3, 8, 8, D_0045CE58, s7[2]);
    func_00380720(a0, *(int *)(s5 + 4), *(int *)s5, &q[0], &q[1], &q[2], &q[3]);
    func_002E0DE8(3, 9, 8, D_0045CE68, q[0], q[1], q[2], q[3]);
    func_00380720(a0, *(int *)(s5 + 4), *(int *)(s5 + 0x10), &q[0], &q[1], &q[2], &q[3]);
    func_002E0DE8(3, 0xA, 8, D_0045CE88, q[0], q[1], q[2], q[3]);
    func_00380720(a0, *(int *)(s5 + 4), *(int *)(s5 + 0x14), &q[0], &q[1], &q[2], &q[3]);
    func_002E0DE8(3, 0xB, 8, D_0045CEA8, q[0], q[1], q[2], q[3]);
    func_002E0DE8(3, 0xC, 8, D_0045CEC8);
    if (*(int *)(s7 + 0xC) >= 0) {
        func_002E0DE8(0x10, 0xC, col, D_0045CED8, D_003F2820[*(int *)(s7 + 0xC)]);
    } else {
        do { do { func_002E0DE8(0x10, 0xC, col, D_0045CEE0); } while (0); } while (0);
    }
    func_002E0DE8(0x18, 0xC, 0xE, D_003F2840[s7[0]]);
    func_002E0DE8(0x20, 7, 8, D_0045CEE8, *(int *)(s5 + 4));
    func_002E0DE8(0x20, 8, 8, D_0045CEF8, *(int *)(s5 + 8));
    func_002E0DE8(0x20, 9, 8, D_0045CF08, *(int *)(s5 + 0xC));
    func_003A6C58(buf, D_0045CF18, *(float *)(s5 + 0x18));
    func_002E0DE8(0x20, 0xA, 8, D_0045CED8, buf);
    func_002E0DE8(0x20, 0xB, 8, D_0045CF30, *(int *)(s5 + 0x1C));
    func_002E0DE8(3, 0xE, 0xD, D_0045CF40);
    func_002E0DE8(3, 0xF, 8, D_0045CE58, a0[7]);
    func_00380720(a0, e[1], e[0], &q[0], &q[1], &q[2], &q[3]);
    func_002E0DE8(3, 0x10, 8, D_0045CE68, q[0], q[1], q[2], q[3]);
    func_002E0DE8(0x20, 0xE, 8, D_0045CEE8, e[1]);
    func_002E0DE8(0x20, 0xF, 8, D_0045CEF8, e[2]);
    func_002E0DE8(0x20, 0x10, 8, D_0045CF08, e[3]);
    func_002E0DE8(3, 0x12, 0xD, D_0045CF50);
    func_002E0DE8(3, 0x14, 8, D_0045CF70, a0[7], *(int *)(s7 + 0x10));
    func_002E0DE8(3, 0x15, 8, D_0045CF88, *(short *)(s7 + 4), *(short *)(s7 + 6));
    func_002E0DE8(3, 0x16, 8, D_0045CFA8, *(short *)(s7 + 8));
    func_002E0DE8(3, 0x17, 8, D_0045CFB8, *(short *)(s7 + 0xA));
    func_002E0DE8(3, 0x18, 8, D_0045CFC8, *(int *)(s5 + 0x20));
}
