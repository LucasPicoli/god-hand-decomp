#include "godhand/cSnd.h"

extern void CustomIDWork_SetColorAnimSin(void *p, int x, int y, int z);
extern void CustomIDWork_ResetColorAnim(void *p);

__attribute__((section(".text.SetBlendField5F4_1C2C00")))
void SetBlendField5F4_1C2C00(void *a0)
{

    int s = *(short *)((char *)a0 + 0x5F4);
    if (s >= 0) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, s, a0, 0, 0, 0, 0);
    }
}

__attribute__((section(".text.SetBlendField5F6_1C2D60")))
void SetBlendField5F6_1C2D60(void *a0)
{

    int s = *(short *)((char *)a0 + 0x5F6);
    if (s >= 0) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, s, a0, 0, 0, 0, 0);
    }
}

__attribute__((section(".text.SetBlendField5B4_1D57A0")))
void SetBlendField5B4_1D57A0(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x5B4, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x5B4);
    }
}

__attribute__((section(".text.SetBlendField4BC_1D5848")))
void SetBlendField4BC_1D5848(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x4BC, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x4BC);
    }
}

__attribute__((section(".text.SetBlendField6AC_1D58F0")))
void SetBlendField6AC_1D58F0(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x6AC, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x6AC);
    }
}

__attribute__((section(".text.SetBlendField105C_1D5998")))
void SetBlendField105C_1D5998(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x105C, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x105C);
    }
}

__attribute__((section(".text.SetBlendField3C4_1D5A40")))
void SetBlendField3C4_1D5A40(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x3C4, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x3C4);
    }
}

__attribute__((section(".text.SetBlendField2CC_1D5AE8")))
void SetBlendField2CC_1D5AE8(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x2CC, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x2CC);
    }
}

__attribute__((section(".text.SetBlendField820_1D5B90")))
void SetBlendField820_1D5B90(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x820, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x820);
    }
}

__attribute__((section(".text.SetBlendField1D4_1DDB10")))
void SetBlendField1D4_1DDB10(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x1D4, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x1D4);
    }
}

__attribute__((section(".text.SetBlendField348_1DDBB8")))
void SetBlendField348_1DDBB8(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x348, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x348);
    }
}

__attribute__((section(".text.SetBlendField4BCColor_1DDC60")))
void SetBlendField4BCColor_1DDC60(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x4BC, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x4BC);
    }
}

__attribute__((section(".text.SetBlendField630_1DDD08")))
void SetBlendField630_1DDD08(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x630, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x630);
    }
}
