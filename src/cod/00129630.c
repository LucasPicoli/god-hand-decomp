/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"


__attribute__((section(".text.func_00129630")))
void func_00129630(void *this)
{
    int cn;
    cSnd *g;
    if (!(*(int *)((char *)this + 0x15F4) & 0x10)) {
        *(int *)((char *)this + 0x15F4) |= 0x20;
        cn = cCoreSave_getCostumeNo(&D_00569B70);
        switch (cn) {
        case 0:
        case 2:
        case 4:
        case 6:
        default:
            SetEffect(0, 0x2E, this, 0, -1, EFFECT_FOLLOW_OWNER);
            break;
        case 1:
        case 3:
        case 5:
        case 7:
            SetEffect(0, 0x74, this, 0, -1, EFFECT_FOLLOW_OWNER);
            break;
        }
    }
    g = &D_005FEE00;
    g->flagsB0 &= 0xFFBFFFFF;
    g->flagsAC &= 0xFFBFFFFF;
}
