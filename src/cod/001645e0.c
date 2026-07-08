/* sn-2.95.3-136 matched TU. */

extern int IsSet_Field_A4_1FBFD0(void *a0, int a1);
extern int D_00569B70;

__attribute__((section(".text.func_001645E0")))
void func_001645E0(char *a0)
{
    unsigned short i;

    for (i = 1; i < 9; i++) {
        if (!IsSet_Field_A4_1FBFD0(&D_00569B70, i)) {
            break;
        }
    }
    i--;
    switch (i - 1) {
    case 0:
        *(unsigned short *)(a0 + 0x134) = 0x200;
        break;
    case 1:
        *(unsigned short *)(a0 + 0x134) = 0x300;
        break;
    case 2:
        *(unsigned short *)(a0 + 0x134) = 0x400;
        break;
    case 3:
        *(unsigned short *)(a0 + 0x134) = 0x500;
        break;
    case 4:
        *(unsigned short *)(a0 + 0x134) = 0x600;
        break;
    case 5:
        *(unsigned short *)(a0 + 0x134) = 0x700;
        break;
    case 6:
        *(unsigned short *)(a0 + 0x134) = 0x802;
        break;
    case 7:
        *(unsigned short *)(a0 + 0x134) = 0x806;
        break;
    }
}
