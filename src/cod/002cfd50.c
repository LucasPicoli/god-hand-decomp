/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern char D_00754210[];
extern char D_00754220[];
extern char D_00602F80[];
extern char D_00603310[];
extern char D_006036A0[];
extern unsigned short D_00747A50;

/* Point a sound-effect slot at the allocator and table set that its bank id uses. */
__attribute__((section(".text.func_002CFD50")))
void func_002CFD50(cSeData *d) {
    switch (d->bankId) {
    case 0:
        d->pool = D_00754210;
        d->head = (cSeBuf *)D_00602F80;
        break;
    case 3:
        d->pool = D_00754210;
        d->head = (cSeBuf *)D_00602F80;
        break;
    case 1:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 16:
    case 17:
    case 18:
    case 19:
        if (D_00747A50 == 0x504 || D_00747A50 == 0x506 || D_00747A50 == 0x801 ||
            D_00747A50 == 0x4F || D_00747A50 == 0x4E) {
            d->pool = D_00754220;
        } else {
            d->pool = D_00754210;
        }
        d->head = (cSeBuf *)D_006036A0;
        break;
    case 2:
    case 4:
    case 5:
    case 6:
    case 14:
    case 15:
    default:
        d->pool = D_00754210;
        d->head = (cSeBuf *)D_00603310;
        break;
    }
}
