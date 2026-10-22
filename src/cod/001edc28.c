/* sn-2.95.3-136 */
#include "godhand/CustomIDPanel.h"

#define PANEL_WORK_OFFSET  0x250
#define PANEL_SLIDE_X      400

extern void func_001ED700(char *self, int n, int f);

/* Slides the panel's item in or out for the given step: 0 shows it off to the left,
 * 1 shows it in place, 2 pulses its colour and slides it in, 3 slides it out. */
__attribute__((section(".text.func_001EDC28")))
void func_001EDC28(char *self, unsigned char step)
{
    CustomIDColor from, to;

    switch (step) {
    default:
    case 0:
        CustomIDWork_ResetColorAnim(self + PANEL_WORK_OFFSET);
        CustomIDWork_SetOffsetPosX(self + PANEL_WORK_OFFSET, -PANEL_SLIDE_X);
        func_001ED700(self, 4, 0);
        break;
    case 1:
        CustomIDWork_ResetColorAnim(self + PANEL_WORK_OFFSET);
        CustomIDWork_SetOffsetPosX(self + PANEL_WORK_OFFSET, 0);
        func_001ED700(self, 4, 1);
        break;
    case 2:
        from.a = 0x80; from.b = 0x80; from.g = 0x80; from.r = 0x80;
        to.r = 0xD0; to.g = 0xD0; to.b = 0xD0; to.a = 0x80;
        CustomIDWork_SetColorAnimSin(self + PANEL_WORK_OFFSET, *(unsigned int *)&from, *(unsigned int *)&to, 6);
        CustomIDWork_SetMoveOffsetPosX(self + PANEL_WORK_OFFSET, -PANEL_SLIDE_X, 0, 12);
        func_001ED700(self, 4, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosX(self + PANEL_WORK_OFFSET, 0, PANEL_SLIDE_X, 8);
        func_001ED700(self, 4, 1);
        break;
    }
}
