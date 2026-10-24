#include "godhand/menuCtl.h"

typedef struct VolEnt {
    char pad0[8];
    short vol[2];
    char padC[4];
    MenuInfo info;
    char pad44[0x48 - 0x44];
} VolEnt;

typedef struct VolSel {
    char pad0[5];
    unsigned char idx;
    char pad6[0x48 - 6];
    VolEnt ent[1];
} VolSel;

extern void func_0032A6D0(int handle, int ch, int vol);

__attribute__((section(".text.func_003812B0")))
void func_003812B0(VolSel *sel, MenuPad *pad, unsigned char right)
{
    VolEnt *e = &sel->ent[sel->idx];
    MenuInfo *info = &e->info;
    short *v;
    int ch;

    if (right) {
        v = &e->vol[1];
        ch = 1;
    } else {
        v = &e->vol[0];
        ch = 0;
    }
    if (pad->trg & 0x8000) {
        if (*v == -0x80)
            *v = 0xF;
        else if (*v >= -0xE)
            *v = *v - 1;
        else
            *v = -0x80;
        if (info->handle != 0)
            func_0032A6D0(info->handle, ch, *v);
    }
    if (pad->trg & 0x2000) {
        if (*v == -0x80)
            *v = -0xF;
        else if (*v < 0xF)
            *v = *v + 1;
        else
            *v = -0x80;
        if (info->handle != 0)
            func_0032A6D0(info->handle, ch, *v);
    }
}
