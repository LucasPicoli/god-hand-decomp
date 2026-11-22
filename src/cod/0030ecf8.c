#include "godhand/heapArena.h"
#include "godhand/globals.h"
extern char D_003C3CFC;

__attribute__((section(".text.func_0030ECF8")))
void func_0030ECF8(int a0)
{
    D_003C3CF4 = 0x7C0000;
    D_003C3CF8 = 0x01FFB000;
    D_003C3D00 = 0x7C0000;
    if (a0 != 1)
        Arena_init(&D_00754200, 0x8A0000, 0x6B0000, 0);
    Arena_init(&D_00754210, 0xF50000, 0x1C0000, 0);
    Arena_init(&D_00754230, 0x01110000, 0xB0000, 0);
    Arena_init(&D_00754220, 0x011C0000, 0xE3B000, 0);
    Arena_init(&D_00754240, 0, 0, 0);
    Arena_init(&D_00754C10, 0, 0, 0);
    Arena_init(&D_00754C20, 0, 0, 0);
    D_003C3CF0 = &D_00754220;
    D_003C3CFC = 1;
}
