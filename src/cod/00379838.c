#include "godhand/menuCtl.h"
#include "godhand/globals.h"
typedef struct {
    char pad0[7];
    signed char mode;
    char pad8[0x25 - 0x8];
    signed char idx;
} MenuRowObj;

extern void func_002E0DE8(int a0, int a1, int a2, const char *fmt, ...);

__attribute__((section(".text.func_00379838")))
void func_00379838(MenuRowObj *o)
{
    int y = 3;

    switch (o->mode) {
    case 0:
        y = (D_003F21E8 + o->idx)->y + 3;
        break;
    case 1:
        y = (D_003F2368 + o->idx)->y + 3;
        break;
    case 2:
        y = (D_003F24D0 + o->idx)->y + 3;
        break;
    }
    {
        short sy = y;
        func_002E0DE8(0x19, sy, 0xC, D_0045B758);
        func_002E0DE8(0x2E, sy, 0xC, D_0045B760);
    }
}
