/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot2.h"
#include "godhand/cCoreSave.h"

/* sn-2.95.3-136 matched TU. */

extern void func_001E7848(char *a0, int a1);
extern void func_001E7868(char *a0, int a1);
extern void func_001E7888(char *a0, int a1);
extern void func_001E78A8(char *a0, int a1);
extern void func_001E78C8(char *a0, int a1);
extern void func_001E78E8(char *a0, int a1);
extern void func_001E6ED8(char *a0, int a1, int a2);
extern void func_001E6A48(char *a0);
extern void func_001E6B70(char *a0, int a1, int a2);
extern void func_001E6C80(char *a0, int a1, int a2);
extern void func_001E6D48(char *a0, int a1, int a2);
extern void func_001E6E10(char *a0, int a1, int a2);
extern void func_001E7660(char *a0, int a1);
extern void SetUiIdWorkDispRange(char *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_005FEE00[];
extern int D_007474A0;
extern int D_00747A2C;
extern long D_00747640;

#define GAMEWORK_PAD(g) (*(long *)((g) + 0x1A0))
/* Slot2 bet screen: the player raises or lowers the bet, then the reels
 * start. */
__attribute__((section(".text.Slot2_UpdateBet")))
void Slot2_UpdateBet(Slot2 *self)
{
    long v;
    int done;

    switch (self->step) {
    case 0: {
        char *layer = self->layer;
        Slot2Reel *p0;
        Slot2Reel *p1;
        Slot2Reel *p2;

        func_001E7848(layer, self->unk36C[0]);
        func_001E7868(layer, self->unk36C[1]);
        func_001E7888(layer, self->unk36C[2]);
        func_001E78A8(layer, self->unk36C[3]);
        func_001E78C8(layer, self->unk36C[4]);
        func_001E78E8(layer, self->unk36C[5]);
        self->betLv = 0;
        func_001E6ED8(self, 0, 0);
        func_001E6A48(self);
        func_001E6B70(self, 0, 0);
        func_001E6C80(self, 0, 0);
        func_001E6D48(self, 0, 0);
        func_001E6E10(self, 0, 0);
        p0 = &self->reel[0];
        p1 = &self->reel[1];
        p2 = &self->reel[2];
        p0->state = 0;
        p0->step = 0;
        p0->phase = 0;
        p1->state = 0;
        p1->step = 0;
        p1->phase = 0;
        p2->state = 0;
        p2->step = 0;
        p2->phase = 0;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 1:
        if (D_00747A2C & 0x200) {
            char *o = (char *)&D_00747A2C;
            if (*(long *)(o - 0x3DC) & 0x33000000000L) {
                cCoreSave_addGold(&D_00569B70, 0x3E8, 0);
            }
        }
        v = self->reel[0].doneFlag;
        if ((v & 1) == 0) {
            return;
        }
        v = self->reel[1].doneFlag;
        if ((v & 1) == 0) {
            return;
        }
        v = self->reel[2].doneFlag;
        if ((v & 1) == 0) {
            return;
        }
        if (self->betLv == 0) {
            char *g = (char *)&D_007474A0;
            if (GAMEWORK_PAD(g) & 0x20000000L) {
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
                self->state = 4;
                self->step = 0;
                self->phase = 0;
                return;
            }
        }
        {
            char *g = (char *)&D_007474A0;
            long f = GAMEWORK_PAD(g);

            if (f & 0x400000000L) {
                if (self->betLv >= 3) {
                    return;
                }
                if (cCoreSave_getGold(&D_00569B70) < self->betCost) {
                    return;
                }
                self->betLv += 1;
                cCoreSave_subGold(&D_00569B70, self->betCost);
                func_001E6A48(self);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
                return;
            }
            if (f & 0x20000000L) {
                if (self->betLv == 0) {
                    return;
                }
                self->betLv -= 1;
                cCoreSave_addGold(&D_00569B70, self->betCost, 0);
                func_001E6A48(self);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
                return;
            }
            if (self->betLv != 0 && (f & 0x2200012000000L)) {
                self->state = 1;
                self->step = 0;
                self->phase = 0;
                return;
            }
        }
        {
            char *g = (char *)&D_007474A0;
            if ((GAMEWORK_PAD(g) & 0x10000000000L) == 0) {
                return;
            }
        }
        func_001E7660(self->layer, 1);
        self->timer = 0xF;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        self->step = self->step + 1;
        break;
    case 2:
        if (self->timer != 0) {
            self->timer -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            SetUiIdWorkDispRange(self->layer, 1);
            self->timer = 0xA;
            self->step = self->step + 1;
        }
        break;
    case 3:
        if (self->timer != 0) {
            self->timer -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            if (D_00747640 & 0x33F00000000L) {
                char *layer = self->layer;
                SetUiIdWorkDispRange(layer, 0);
                func_001E7660(layer, 2);
                self->timer = 0xA;
                self->step = self->step + 1;
            }
        }
        break;
    case 4:
        if (self->timer != 0) {
            self->timer -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            self->step = 1;
        }
        break;
    }
}
