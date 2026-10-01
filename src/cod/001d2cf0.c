/* sn-2.95.3-136 matched TU. */

#include "godhand/BlackJack.h"

extern char D_005FEE00[];
extern float D_005680F0[];
extern int cSnd_SeCall_2CBA48(void *snd, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);

#define DEAL_FRAMES 20

/* Deal one card to the player: wait, slide it onto the table, then pick the next state. */
__attribute__((section(".text.func_001D3110")))
void func_001D3110(BlackJack *self)
{
    switch ((unsigned int)self->phase) {
    case 0:
        self->timer = DEAL_FRAMES;
        self->phase += 1;
        break;
    case 1:
        if (self->timer == 0) {
            self->handA[self->dealSlot]->obj->flags &= ~BLACKJACK_CARD_FACE_DOWN;
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0, self->handA[self->dealSlot]->obj, 0, 0, 0, 0);
            self->timer = DEAL_FRAMES;
            self->phase += 1;
        } else {
            self->timer -= 1;
        }
        break;
    case 2: {
        float *pos = &D_005680F0[self->dealSlot * 4];
        float t = ((float)DEAL_FRAMES - (float)self->timer) / (float)DEAL_FRAMES;
        float start[4];

        start[0] = pos[0] + 1.0f;
        start[1] = pos[1];
        start[2] = pos[2];
        start[3] = 1.0f;
        *self->handA[self->dealSlot]->obj->pos =
            t * (D_005680F0[self->dealSlot * 4] - start[0]) + start[0];
        if (self->timer == 0) {
            int over;

            self->dealSlot += 1;
            over = func_001D4720(self) >= 0x16;
            if (over) {
                self->phase = 0;
                self->state = 0xF;
            } else {
                self->phase += 1;
            }
        } else {
            self->timer -= 1;
        }
        break;
    }
    case 3:
        self->phase = 0;
        self->state = 0xA;
        break;
    }
}

#define DEAL_FRAMES 20

/* Deal one card to the dealer: wait, slide it onto the table, then pick the next state. */
__attribute__((section(".text.func_001D2CF0")))
void func_001D2CF0(BlackJack *self)
{
    switch ((unsigned int)self->phase) {
    case 0:
        self->timer = DEAL_FRAMES;
        self->phase += 1;
        break;
    case 1:
        if (self->timer == 0) {
            self->handA[self->dealSlot]->obj->flags &= ~BLACKJACK_CARD_FACE_DOWN;
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0, self->handA[self->dealSlot]->obj, 0, 0, 0, 0);
            self->timer = DEAL_FRAMES;
            self->phase += 1;
        } else {
            self->timer -= 1;
        }
        break;
    case 2: {
        float *pos = &D_005680F0[self->dealSlot * 4];
        float t = ((float)DEAL_FRAMES - (float)self->timer) / (float)DEAL_FRAMES;
        float start[4];

        start[0] = pos[0] + 1.0f;
        start[1] = pos[1];
        start[2] = pos[2];
        start[3] = 1.0f;
        *self->handA[self->dealSlot]->obj->pos =
            t * (D_005680F0[self->dealSlot * 4] - start[0]) + start[0];
        if (self->timer == 0) {
            int over;

            self->dealSlot += 1;
            over = func_001D4720(self) >= 0x16;
            if (over) {
                self->phase = 0;
                self->state = 0xF;
            } else if (func_001D4980(self) != 0) {
                self->phase = 0;
                self->state = 0x12;
            } else {
                self->phase += 1;
            }
        } else {
            self->timer -= 1;
        }
        break;
    }
    case 3:
        if (func_001D4720(self) == 0x15) {
            self->phase = 0;
            self->state = 0xA;
            break;
        }
        self->phase = 0;
        self->state = 6;
        break;
    }
}
