/* sn-2.95.3-136 matched TU. */
#include "godhand/cIDBase.h"

extern int D_005E7510;
extern void func_002AF6A8(void *a0, int a1, int a2);

/* Select the shared message environment's draw style from `val`: val % 10 in
 * 1..7 picks style 3..9, anything else style 2. val / 10 is the second
 * argument. */
__attribute__((section(".text.func_002AB9A8")))
void func_002AB9A8(cIDBaseObj *self, unsigned char val)
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
