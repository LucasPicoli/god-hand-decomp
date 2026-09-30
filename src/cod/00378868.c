/* sn-2.95.3-136 matched TU. */

extern void func_002E0DE8();
extern void func_0031C950();
extern void func_0031CB80();
extern void func_0031CA88();
extern char D_0045B1B8[], D_0045B1C8[], D_0045B1E8[], D_0045B200[], D_0045B218[], D_0045B230[], D_0045B248[], D_0045B260[], D_0045B278[], D_0045B290[], D_0045B2A0[], D_0045B2C0[], D_0045B2C8[], D_0045B2D8[], D_0045B2F0[], D_0045B300[], D_0045B308[];
extern signed char D_003F21C0[], D_003F21D0[];
typedef struct { short s[8]; } R;

__attribute__((section(".text.func_00378868")))
void func_00378868(unsigned char *a0)
{
    R r = *(R *)D_0045B1B8;
    short y;
    int t;

    func_002E0DE8(0x15, 4, 8, D_0045B1C8);
    func_002E0DE8(0x15, 0x6, 8, D_0045B1E8);
    func_002E0DE8(0x15, 0x7, 8, D_0045B200);
    func_002E0DE8(0x15, 0x8, 8, D_0045B218);
    func_002E0DE8(0x15, 0x9, 8, D_0045B230);
    func_002E0DE8(0x15, 0xa, 8, D_0045B248);
    func_002E0DE8(0x15, 0xb, 8, D_0045B260);
    func_002E0DE8(0x15, 0x11, 8, D_0045B278);
    func_002E0DE8(0x15, 0x12, 8, D_0045B290);
    func_002E0DE8(0x15, 0x15, 8, D_0045B2A0);
    func_002E0DE8(0x1F, 0x16, 8, D_0045B2C0, D_0045B2C8);
    func_002E0DE8(0x15, 0x18, 8, D_0045B2D8, D_0045B2F0);
    { signed char w = D_003F21C0[(char)a0[5]]; y = w + 4; }
    func_002E0DE8(0x15, y, 0xC, D_0045B300);
    func_002E0DE8(0x2D, y, 0xC, D_0045B308);
    func_0031C950(0xA0, 0x1C, 0x178, 0x1C, 0x805C0000, 0);
    func_0031C950(0xA0, 0x2A, 0x178, 0x2A, 0x805C0000, 0);
    y <<= 3;
    r.s[1] = y;
    r.s[3] = y;
    t = y + 8;
    r.s[5] = t;
    r.s[7] = t;
    func_0031CB80(&r, 0x80006060, 0);
    func_0031CA88(D_003F21D0, 5, 0x80808080, 0);
}
