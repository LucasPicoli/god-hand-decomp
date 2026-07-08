/* sn-2.95.3-136 matched TU. */

extern int D_005FEE00;

__attribute__((section(".text.func_002CC830")))
int func_002CC830(char *a0, char *a1, int a2)
{
    int val;
    int sel;

    val = *(int *)(a1 + 8);
    sel = *(int *)(a0 + 0x94);
    *(int *)(a0 + 0x98) = a2;
    *(int *)(a0 + 0x9C) = val;

    switch (sel) {
    default:
        break;
    case 3:
        *(int *)(a0 + 0xAC) = *(unsigned short *)(a1 + 0xC);
        *(int *)(a0 + 0xA4) = func_002D0578(&D_005FEE00, *(unsigned short *)(a1 + 0xE));
        break;
    case 2:
        *(int *)(a0 + 0xA8) = func_002D0598(&D_005FEE00, *(unsigned short *)(a1 + 0xC));
        *(int *)(a0 + 0xA4) = func_002D0578(&D_005FEE00, *(unsigned short *)(a1 + 0xE));
        break;
    case 1:
    case 4:
    case 5:
        *(unsigned short *)(a0 + 0xA0) = *(unsigned short *)(a1 + 0xC);
        *(unsigned short *)(a0 + 0xA2) = *(unsigned short *)(a1 + 0xE);
        break;
    case 0:
        *(int *)(a0 + 0x94) = 0;
        return 0;
    }
    return 1;
}
