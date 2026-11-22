/* sn-2.95.3-136: CustomID panel helpers at 0x1ECE30 (works are 0x7C bytes from +0x60). */
#include "godhand/CustomIDPanel.h"

__attribute__((section(".text.func_001ED050")))
void func_001ED050(char *self, unsigned short slot, int n)
{
    CustomIDDigitTbl tbl;

    if (slot < 5) {
        if (n >= 1000) n = 999;
        tbl = D_0042BD70;
        CustomIDWork_SetNumber(self + (tbl.w[slot][0] * 0x7C + 0x60), n / 10);
        CustomIDWork_SetNumber(self + (tbl.w[slot][1] * 0x7C + 0x60), n - n / 10 * 10);
    }
}

extern void CustomIDWork_setDispAllButEight(char *self, int id, int on);
extern void func_001ED4B0(char *self, int on);
extern void CustomIDOwner_setBob(char *self, int on);

__attribute__((section(".text.func_001ED178")))
void func_001ED178(char *self, unsigned char mode)
{
    int i;

    CustomIDWork_setDispAllButEight(self, 0x2D, 0);
    switch (mode) {
    case 0:
        for (i = 0; i < 0x1D; i++)
            CustomIDWork_setDispAllButEight(self, i, 1);
        CustomIDWork_setDispAllButEight(self, 0x24, 1);
        CustomIDWork_setDispAllButEight(self, 0x25, 1);
        CustomIDWork_setDispAllButEight(self, 0x1D, 1);
        CustomIDWork_setDispAllButEight(self, 0x2B, 1);
        CustomIDWork_setDispAllButEight(self, 0x26, 1);
        CustomIDWork_setDispAllButEight(self, 0x27, 1);
        CustomIDWork_setDispAllButEight(self, 0x28, 1);
        CustomIDWork_setDispAllButEight(self, 0x29, 1);
        CustomIDWork_setDispAllButEight(self, 0x2A, 1);
        func_001ED4B0(self, 1);
        CustomIDOwner_setBob(self, 0);
        break;
    case 1:
        for (i = 0; i < 0x1D; i++)
            CustomIDWork_setDispAllButEight(self, i, 1);
        CustomIDWork_setDispAllButEight(self, 0x24, 1);
        CustomIDWork_setDispAllButEight(self, 0x25, 1);
        CustomIDWork_setDispAllButEight(self, 0x1E, 1);
        CustomIDWork_setDispAllButEight(self, 0x2C, 1);
        CustomIDWork_setDispAllButEight(self, 0x1F, 1);
        CustomIDWork_setDispAllButEight(self, 0x20, 1);
        CustomIDWork_setDispAllButEight(self, 0x21, 1);
        CustomIDWork_setDispAllButEight(self, 0x22, 1);
        CustomIDWork_setDispAllButEight(self, 0x23, 0);
        CustomIDWork_setDispAllButEight(self, 0x26, 1);
        CustomIDWork_setDispAllButEight(self, 0x27, 1);
        CustomIDWork_setDispAllButEight(self, 0x28, 1);
        CustomIDWork_setDispAllButEight(self, 0x29, 1);
        CustomIDWork_setDispAllButEight(self, 0x2A, 1);
        func_001ED4B0(self, 0);
        CustomIDOwner_setBob(self, 1);
        break;
    case 2:
        break;
    }
}
