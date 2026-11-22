/* sn-2.95.3-136: SdeTblTestParaChange, looks up the object's entry in one of three 0x14-byte tables by kind and runs its handler when any 0xF000 flag is set. */
#include "godhand/menuCtl.h"
typedef struct {
    char unk0[7];
    signed char kind;
    char unk8[0x1D];
    signed char idx;
    char unk26[0x12];
    unsigned int flags;
} MenuActObj;

extern void (*D_003F2628[])(MenuActObj *obj, MenuRowEnt *e);

__attribute__((section(".text.SdeTblTestParaChange")))
int SdeTblTestParaChange(MenuActObj *obj)
{
    MenuRowEnt *e = 0;

    switch (obj->kind) {
    case 0:
        e = &D_003F21E8[obj->idx];
        break;
    case 1:
        e = &D_003F2368[obj->idx];
        break;
    case 2:
        e = &D_003F24D0[obj->idx];
        break;
    }
    if ((obj->flags & 0xF000) == 0)
        return 0;
    D_003F2628[e->handler](obj, e);
    return 1;
}
