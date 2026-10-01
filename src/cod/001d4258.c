/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"

/* sn-2.95.3-136 */
typedef struct Vec { float x, y, z, w; } Vec;

extern void func_001D6D20(BlackJack *, int);
extern void SetLinkedObjField2B_1D6D68(BlackJack *, int);
extern void CustomIDWork_SetNumber_1D5760(BlackJack *, int);
extern int  cSnd_SeCall_2CBA48(void *, int, int, int, int, int, int, int);
extern void func_001D6030(BlackJack *, int);
extern void func_001D60F8(BlackJack *, int);
extern void func_001D61C0(BlackJack *, int);
extern void func_001D5C38(BlackJack *, int);
extern void func_001D5D20(BlackJack *, int);
extern void func_001D5E08(BlackJack *, int);
extern void func_001D5F50(BlackJack *, int);

extern char D_005FEE00[];
extern Vec  D_005680F0[];
extern Vec  D_00568080[];

/* Dealing-in state: slide both hands into place, then hand control to the next state. */
__attribute__((section(".text.func_001D4258")))
void func_001D4258(BlackJack *self)
{
    float r;
    float k;
    int i;

    switch (self->phase) {
    case 0:
        func_001D6D20(self, 0);
        SetLinkedObjField2B_1D6D68(self, 0);
        self->bet = 0;
        CustomIDWork_SetNumber_1D5760(self, 0);
        self->timer = 0x14;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0, (int)self->handA[0]->obj, 0, 0, 0, 0);
        self->phase++;
    case 1:
        k = -1.0f;
        r = (20.0f - (float)self->timer) / 20.0f;
        i = 0;
        if (self->dealSlot != 0) {
            float s = -r;
            Vec *t = D_005680F0;
            BlackJackCard **q = &self->handA[0];
            do {
                BlackJackCard *card = *q;
                i++;
                q++;
                *card->obj->pos = s + t->x;
                t++;
            } while (i < self->dealSlot);
        }
        i = 0;
        if (self->dealSlotB != 0) {
            float s = r * k;
            Vec *t = D_00568080;
            BlackJackCard **q = &self->handB[0];
            do {
                BlackJackCard *card = *q;
                i++;
                q++;
                *card->obj->pos = s + t->x;
                t++;
            } while (i < self->dealSlotB);
        }
        if (self->timer != 0) {
            self->timer--;
            break;
        }
        func_001D6030(self, 3);
        func_001D60F8(self, 3);
        func_001D61C0(self, 3);
        self->timer = 0x1E;
        self->phase++;
        break;
    case 2:
        if (self->timer != 0) {
            self->timer--;
            break;
        }
        func_001D5C38(self, 2);
        func_001D5D20(self, 2);
        func_001D5E08(self, 2);
        func_001D5F50(self, 2);
        self->timer = 0x1E;
        self->phase++;
        break;
    case 3:
        if (self->timer == 0) {
            self->phase++;
        } else {
            self->timer--;
        }
        break;
    case 4:
        self->state = 0;
        self->phase = 0;
        break;
    }
}
