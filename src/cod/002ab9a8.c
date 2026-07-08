/* sn-2.95.3-136 matched TU. */

extern int D_005E7510;
extern void func_002AF6A8(void *a0, int a1, int a2);

__attribute__((section(".text.func_002AB9A8")))
void func_002AB9A8(void *unused, unsigned char val)
{
    int quotient;
    int remainder;

    quotient = val / 10;
    remainder = val % 10;

    switch (remainder - 1) {
    case 0:
        func_002AF6A8(&D_005E7510, 3, quotient & 0xFF);
        break;
    case 1:
        func_002AF6A8(&D_005E7510, 4, quotient & 0xFF);
        break;
    case 2:
        func_002AF6A8(&D_005E7510, 5, quotient & 0xFF);
        break;
    case 3:
        func_002AF6A8(&D_005E7510, 6, quotient & 0xFF);
        break;
    case 4:
        func_002AF6A8(&D_005E7510, 7, quotient & 0xFF);
        break;
    case 5:
        func_002AF6A8(&D_005E7510, 8, quotient & 0xFF);
        break;
    case 6:
        func_002AF6A8(&D_005E7510, 9, quotient & 0xFF);
        break;
    default:
        func_002AF6A8(&D_005E7510, 2, quotient & 0xFF);
        return;
    }
}
