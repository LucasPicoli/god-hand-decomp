/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"

#define SEE_EYE_HEIGHT    1.0f
#define SEE_FLAG_PLAYER   0x200000
#define SEE_HIT_MASK      0x10

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* Whether the enemy sees the player, kept in its flags. Some kinds always see. */
__attribute__((section(".text.func_0026F328")))
int func_0026F328(cEm00 *self)
{
    cVec me;
    cVec pl;

    switch (self->emNo) {
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26A:
        self->emFlags |= SEE_FLAG_PLAYER;
        return 1;
    }
    cVec_zero(&me);
    cVec_zero(&pl);
    cVec_copy3(&me, self->pos);
    me.y += SEE_EYE_HEIGHT;
    cVec_copy3(&pl, Getplayer()->pos);
    pl.y += SEE_EYE_HEIGHT;
    if (ChkLine(&me, &pl, 0, 0, 1, SEE_HIT_MASK, 0, 0, 0, 0, 0, 0, 1) == 1) {
        self->emFlags &= ~SEE_FLAG_PLAYER;
        return 0;
    }
    self->emFlags |= SEE_FLAG_PLAYER;
    return 1;
}
