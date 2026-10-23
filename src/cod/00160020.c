/* sn-2.95.3-136 */
#include "godhand/gameWork.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/cSubScr.h"


/* A GameWork field read through its constant address. Retail addresses the
 * flag words from &D_007474A0.flags5E4 and &D_007474A0.flags5D8; a plain
 * D_007474A0.field access addresses them from D_007474A0 and changes the code. */
#define GAMEWORK_AT(field) \
    (*(__typeof__(D_007474A0.field) *)((char *)&D_007474A0 + (int)&((GameWork *)0)->field))

/* Open sub screen `kind` unless the game flags block it or one is open: save the game flag words, preset the screen's selection, flash the player, set the sub-screen flags and push the kind. */
__attribute__((section(".text.cSubScr_SubScrOn")))
void cSubScr_SubScrOn(cSubScr *self, int kind, unsigned char sel, unsigned char arg)
{
    unsigned long f = GAMEWORK_AT(flags5E4);
    unsigned long g;
    unsigned long bit;

    if (f & 0x20000000)
        return;
    if (f & 0x10000000)
        return;
    bit = (f >> 6) & 1;
    if (bit != 0)
        return;
    g = GAMEWORK_AT(flags);
    bit = (g >> 3) & 1;
    if (bit != 0)
        return;
    if (f & 0x200000)
        return;
    if (self->open != 0)
        return;
    self->unkEDC = arg;
    self->saved5D8 = D_007474A0.flags5D8;
    self->saved5E0 = D_007474A0.flags5E0;
    self->kind = kind;
    self->depth = 0;
    switch (kind) {
    case 1:
        self->sel374 = sel;
        break;
    case 2:
        self->sel684 = sel;
        break;
    case 3:
        self->sel794 = sel;
        break;
    case 4:
        self->sel8E4 = 0;
        break;
    case 5:
        self->selA24 = 0;
        break;
    case 7:
        self->selCA4 = 0;
        break;
    case 8:
        self->selC04 = 0;
        break;
    case 6:
        self->selB44 = 0;
        break;
    case 0:
    default:
        self->sel794 = 0;
        break;
    }
    self->open = 1;
    Getplayer()->hitFlash = 5.0f;
    GAMEWORK_AT(flags5D8) |= 0x40000000;
    GAMEWORK_AT(flags5D8) |= 0x80000000;
    GAMEWORK_AT(flags5D8) |= 0x20000000;
    GAMEWORK_AT(flags5D8) |= 0x10000000;
    GAMEWORK_AT(flags5D8) |= 0x08000000;
    GAMEWORK_AT(flags5D8) |= 0x40000;
    GAMEWORK_AT(flags5E0) |= 0x02000000;
    GAMEWORK_AT(flags5E4) |= 0x08000000;
    self->stack[self->depth] = kind;
    self->depth++;
}
