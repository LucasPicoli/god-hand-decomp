/* sn-2.95.3-136 matched TU. */

extern unsigned int Forward30F348_31CFE0(void);
extern void cEmManage__CreateItem(void *a0, int a1, int a2, int a3);
extern unsigned short D_00747A50;
extern unsigned char D_005864F0[];

/* sn-2.95.3-136 candidate. */







__attribute__((section(".text.func_00273D30")))
void func_00273D30(void *a0)
{
    char *s0 = (char *)a0;
    int f = *(int *)(s0 + 0x16D4);

    if ((f & 2) != 0) {
        return;
    }
    *(int *)(s0 + 0x16D4) = f | 2;
    switch (*(int *)(s0 + 0x564)) {
    case 0x220: case 0x221: case 0x222: case 0x223:
        if (D_00747A50 == 0x801) {
            unsigned int r = Forward30F348_31CFE0() % 100;

            *(int *)(s0 + 0x560) = 0x3C1;
            if (r >= 0x14) {
                *(int *)(s0 + 0x560) = 0x3C8;
            }
            if (r >= 0x28) {
                *(int *)(s0 + 0x560) = 0x3D1;
            }
            if (r >= 0x31) {
                *(int *)(s0 + 0x560) = 0x3D0;
            }
            if (r >= 0x32) {
                *(int *)(s0 + 0x560) = 0x3E0;
            }
            if (r >= 0x41) {
                *(int *)(s0 + 0x560) = 0x3E1;
            }
            if (r >= 0x3B) {
                *(int *)(s0 + 0x560) = 0x3DE;
            }
            if (r >= 0x50) {
                *(int *)(s0 + 0x560) = 0x3E2;
            }
            if (r >= 0x5A) {
                *(int *)(s0 + 0x560) = 0x3DF;
            }
        } else {
            *(int *)(s0 + 0x560) = func_002920B0(&D_005864F0);
            if (Forward30F348_31CFE0() % 100 >= 0x46) {
                *(int *)(s0 + 0x560) = 0x3D8;
            }
        }
        break;
    case 0x21F: case 0x250: case 0x251: case 0x252: case 0x256: case 0x260:
    case 0x264: case 0x265: case 0x26A: case 0x275: case 0x27E:
        return;
    default:
        break;
    }
    cEmManage__CreateItem(&D_005864F0, *(int *)(s0 + 0xF0), *(int *)(s0 + 0x560), 1);
}
