/* sn-2.95.3-136 matched TU. */

extern void func_002E0DE8();
extern void func_00384350();
extern void func_00384590();
extern void func_00384828();
extern void func_00384980();
extern void func_00384B10();
extern char D_0045CAA0[], D_0045CAB8[], D_0045CAC0[], D_0045CAD0[], D_0045CAE8[], D_0045CB00[], D_0045CB10[], D_0045CB30[];
extern int D_003F28C8[];
extern char D_0045CB48[], D_0045CB68[], D_0045CB88[], D_0045CBA0[], D_0045CBB0[], D_0045CBC0[];
extern char D_003F28D0[];
extern char *D_003F2858[];
extern char *D_003F2848[];
extern char *D_003F2840[];
extern char *D_003F2820[];
extern char D_0045BB50[], D_0045BB68[], D_0045BB80[], D_0045BB98[], D_0045BBB0[], D_0045BBC8[], D_0045BBE0[], D_0045BBF8[];
extern char D_0045BC10[], D_0045BC28[], D_0045BC40[], D_0045BC58[], D_0045BC70[], D_0045BC88[], D_0045BCA0[], D_0045BCA8[];
extern short D_0076A790[];

__attribute__((section(".text.func_00384198")))
void func_00384198(unsigned char *a0)
{
    unsigned char *s2 = a0 + 0x370;
    int *s4;
    char *obj;
    int len;
    char *name;
    char *fmt;
    int t;

    s4 = *(int **)(s2 + 0xFC);
    func_002E0DE8(0x11, 3, 0xD, D_0045CAA0);
    fmt = D_0045CAC0;
    obj = *(char **)(a0 + 0x40);
    len = *(int *)(obj - 0x10);
    if (len == 0) {
        name = D_0045CAB8;
    } else {
        obj[len] = 0;
        name = *(char **)(a0 + 0x40);
    }
    func_002E0DE8(3, 5, 8, fmt, name);
    func_00384350(a0, s2);
    func_002E0DE8(3, 7, 0xD, D_0045CAD0);
    t = (s2[3] & 1) ? D_003F28C8[1] : D_003F28C8[0];
    func_002E0DE8(3, 8, 8, D_0045CAE8, s2[2], t);
    func_00384590(a0, s2);
    func_002E0DE8(3, 0xE, 0xD, D_0045CB00);
    t = (s2[3] & 2) ? D_003F28C8[1] : D_003F28C8[0];
    func_002E0DE8(3, 0xF, 8, D_0045CAE8, a0[6], t);
    func_00384828(a0, s2);
    func_002E0DE8(3, 0x12, 0xD, D_0045CB10);
    func_002E0DE8(3, 0x14, 8, D_0045CB30, a0[6], s4[2]);
    func_00384980(a0, s2);
    func_00384B10(a0, s2);
}

__attribute__((section(".text.func_00384350")))
void func_00384350(int a0, unsigned char *s0)
{
    int col;
    int t;
    char *p;

    p = D_003F28D0;
    if (s0[3] & 1) {
        switch (*(int *)(s0 + 0x30)) {
        case 0:
            col = 0xF;
            break;
        case -1:
            if (s0[1] != 0) {
                if (s0[1] == 1)
                    func_002E0DE8(0xF, 0x16, 0xE, D_0045CB48);
                else
                    func_002E0DE8(0xF, 0x16, 0xE, D_0045CB68);
                func_002E0DE8(0x13, 0x17, 8, D_0045CB88);
            }
        case 3:
            col = 0xF;
            break;
        case 4:
            col = 0xA;
            break;
        default:
            col = 0xD;
            break;
        }
        if (*(int *)(s0 + 0x30) >= 0)
            p = D_003F2858[*(int *)(s0 + 0x30)];
    } else {
        switch (*(int *)(s0 + 0x30)) {
        case 0:
            col = 0xF;
            break;
        case -1:
            if (s0[1] != 0) {
                func_002E0DE8(0xF, 0x16, 0xE, D_003F2848[s0[1] - 1]);
                func_002E0DE8(0x13, 0x17, 8, D_0045CB88);
            }
        case 5:
            col = 0xF;
            break;
        case 6:
            col = 0xA;
            t = func_0032B0B0(*(int *)(s0 + 0x64));
            func_002E0DE8(0x14, 7, 0xD, D_0045CBA0, t);
            break;
        default:
            col = 0xD;
            break;
        }
        if (*(int *)(s0 + 0x30) >= 0)
            p = D_003F2820[*(int *)(s0 + 0x30)];
    }
    func_002E0DE8(3, 0xC, 8, D_0045CBB0);
    func_002E0DE8(0x10, 0xC, col, D_0045CBC0, p);
    func_002E0DE8(0x18, 0xC, 0xE, D_003F2840[s0[0]]);
}

typedef struct { char pad[6]; short v; char pad2[12]; } E14;
extern E14 D_003F2638[];


__attribute__((section(".text.func_0037AEC0")))
void func_0037AEC0(unsigned char *a0)
{
    short *s0;
    short *s1 = D_0076A790;
    int y;
    int k;

    func_002E0DE8(0x1B, 3, 0xD, D_0045BB50);
    s0 = (short *)(a0 + 0x15C);
    func_002E0DE8(0x1B, 5, 8, D_0045BB68, *(short *)(a0 + 0x15C));
    func_002E0DE8(0x1B, 6, 8, D_0045BB80, s0[1]);
    func_002E0DE8(0x1B, 8, 8, D_0045BB98, s0[3]);
    func_002E0DE8(0x1B, 0xA, 8, D_0045BBB0, s0[4]);
    func_002E0DE8(0x1B, 0xB, 8, D_0045BBC8, s0[5]);
    func_002E0DE8(0x1B, 0xD, 8, D_0045BBE0, s0[6]);
    func_002E0DE8(0x1B, 0xE, 8, D_0045BBF8, s0[7]);
    func_002E0DE8(0x1B, 0x10, 0xD, D_0045BC10);
    func_002E0DE8(0x1B, 0x12, 8, D_0045BC28, s1[0x3A / 2]);
    k = 0x14;
    func_002E0DE8(0x1B, k, 8, D_0045BC40, s1[0x3C / 2]);
    func_002E0DE8(0x1B, 0x15, 8, D_0045BC58, s1[0x3E / 2]);
    func_002E0DE8(0x1B, 0x17, 8, D_0045BC70, s1[0x40 / 2]);
    func_002E0DE8(0x1B, 0x18, 8, D_0045BC88, s1[0x42 / 2]);
    { short w = ((E14 *)((char *)D_003F2638 + (char)a0[0x26] * k))->v; y = (short)(w + 3); }
    func_002E0DE8(0x19, y, 0xC, D_0045BCA0);
    func_002E0DE8(0x31, y, 0xC, D_0045BCA8);
}
