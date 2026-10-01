/* sn-2.95.3-136 matched TU. */

#include "godhand/BlackJack.h"

extern char D_005FEE00[];
extern float D_00568080[];
extern void func_001D0C98(BlackJackCard *card, int on);

extern int cSnd_SeCall_2CBA48(void *snd, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);

#define DEAL_FRAMES 20
#define DEALER_HIT_MAX 0x10

/* Deal the dealer's hand B one card at a time while its total stays under 17. */
__attribute__((section(".text.BlackJack_UpdateDealDealerHandB")))
void BlackJack_UpdateDealDealerHandB(BlackJack *self)
{
    switch (self->phase) {
    case 0:
        self->timer = DEAL_FRAMES;
        self->phase += 1;
        break;
    case 1:
        if (self->timer == 0) {
            self->phase += 1;
            break;
        }
        self->timer -= 1;
        break;
    case 2:
        func_001D0C98(self->handB[1], 1);
        self->phase += 1;
        break;
    case 3: {
        long f = self->handB[1]->flags;

        if (((f >> 1) & 1) == 0)
            break;
        self->phase += 1;
        break;
    }
    case 4:
        if (func_001D47E8(self) <= DEALER_HIT_MAX) {
            if (self->dealSlotB < BLACKJACK_HAND_NUM) {
                self->handB[self->dealSlotB]->obj->flags &= ~BLACKJACK_CARD_FACE_DOWN;
                func_001D0C98(self->handB[self->dealSlotB], 0);
                cSnd_SeCall_2CBA48(D_005FEE00, 2, 0, self->handB[self->dealSlotB]->obj, 0, 0, 0, 0);
                self->timer = DEAL_FRAMES;
                self->phase += 1;
                break;
            }
        }
        self->phase = 0;
        self->state = 0xD;
        break;
    case 5: {
        float *pos = &D_00568080[self->dealSlotB * 4];
        float t = ((float)DEAL_FRAMES - (float)self->timer) / (float)DEAL_FRAMES;
        float start[4];

        start[0] = pos[0] + 1.0f;
        start[1] = pos[1];
        start[2] = pos[2];
        start[3] = 1.0f;
        *self->handB[self->dealSlotB]->obj->pos =
            t * (D_00568080[self->dealSlotB * 4] - start[0]) + start[0];
        if (self->timer == 0) {
            self->dealSlotB += 1;
            self->phase -= 1;
        } else {
            self->timer -= 1;
        }
        break;
    }
    }
}
