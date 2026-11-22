/* sn-2.95.3-136: CustomID panel helpers (offset slides, scale/colour pulses on 0x7C-byte works at +0x60). */
#include "godhand/CustomIDPanel.h"

__attribute__((section(".text.func_001DE5F8")))
void func_001DE5F8(char *self, unsigned char sel, unsigned char mode)
{
    CustomIDSlotTbl8 ids;
    unsigned int i;

    if (sel < 8) {
        ids = D_0042B678;
        for (i = 0; i < 8; i++)
            SetCustomIDDispOneOrAll_1DD258(self, ids.w[i], 0);
        SetCustomIDDispOneOrAll_1DD258(self, 0x3E, 0);
        SetCustomIDDispOneOrAll_1DD258(self, 0x47, 0);
        switch (mode) {
        default:
        case 0:
            CustomIDWork_SetOffsetPosX(self + 0x1E68, -0x1C2);
            break;
        case 1:
            CustomIDWork_SetOffsetPosX(self + 0x1E68, 0);
            SetCustomIDDispOneOrAll_1DD258(self, ids.w[sel], 1);
            SetCustomIDDispOneOrAll_1DD258(self, 0x3E, 1);
            SetCustomIDDispOneOrAll_1DD258(self, 0x47, 1);
            break;
        case 2:
            CustomIDWork_SetMoveOffsetPosX(self + 0x1E68, -0x1C2, 0, 0xA);
            SetCustomIDDispOneOrAll_1DD258(self, ids.w[sel], 1);
            SetCustomIDDispOneOrAll_1DD258(self, 0x3E, 1);
            SetCustomIDDispOneOrAll_1DD258(self, 0x47, 1);
            break;
        case 3:
            CustomIDWork_SetMoveOffsetPosX(self + 0x1E68, 0, 0x1C2, 0xA);
            SetCustomIDDispOneOrAll_1DD258(self, ids.w[sel], 1);
            SetCustomIDDispOneOrAll_1DD258(self, 0x3E, 1);
            SetCustomIDDispOneOrAll_1DD258(self, 0x47, 1);
            break;
        }
    }
}

__attribute__((section(".text.func_001DE858")))
void func_001DE858(char *self, unsigned char sel)
{
    CustomIDSlotTbl8 ids;
    unsigned int i;
    CustomIDColor hi, from, to;

    ids = D_0042B698;
    for (i = 0; i < 8; i++)
        CustomIDWork_ResetColorAnim(self + (ids.w[i] * 0x7C + 0x60));
    CustomIDWork_ResetColorAnim(self + 0xDF0);
    CustomIDWork_SetOffsetPosY(self + 0xDF0, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x1C, 0);
    if (sel < 8) {
        hi.r = 0xE1; hi.g = 0x51; hi.b = 0x13; hi.a = 0x80;
        CustomIDWork_SetColorAnimNormal_2D6898(self + (ids.w[sel] * 0x7C + 0x60), *(unsigned int *)&hi, 1);
        from.r = 0x60; from.g = 0x60; from.b = 0x60; from.a = 0x50;
        to.r = 0xA0; to.g = 0xA0; to.b = 0xA0; to.a = 0x80;
        CustomIDWork_SetColorAnimSin(self + 0xDF0, *(unsigned int *)&from, *(unsigned int *)&to, 3);
        CustomIDWork_SetOffsetPosY(self + 0xDF0, sel * 17);
        SetCustomIDDispOneOrAll_1DD258(self, 0x1C, 1);
    }
}

