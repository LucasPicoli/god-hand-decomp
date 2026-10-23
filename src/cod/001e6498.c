/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/Slot2.h"
#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"
#include "godhand/gameWork.h"

#define SLOT2_JACKPOT_COIN   10
#define PAD_SKIP_BUTTONS     0xF00000000L

extern void func_001E6ED8(Slot2 *self, int on, int lit);
extern void func_001E6E10(Slot2 *self, int on, int lit);
extern int func_001E8E48(void *reel, void *pos);
extern int cSnd_SeCall(void *snd, int slot, short key1, int mtx, int idA, int idB);
extern void cSnd_SeStop(void *snd, int id);
extern char D_005FEE00[];

/* Slot2 payout stage, jackpot line: light the line, then pay out ten gold at a time until a button is pressed or the coins run out. */
__attribute__((section(".text.Slot2_PayoutJackpotLine")))
void Slot2_PayoutJackpotLine(Slot2 *self)
{
    cVec pos;
    int done;

    switch (self->phase) {
    case 0:
        func_001E6ED8(self, 1, 1);
        func_001E6E10(self, 1, 1);
        self->timer = 0x3C;
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->timer != 0) {
            self->timer = self->timer - 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        if (self->jackpotLine == 2) {
            self->coinUnit = SLOT2_JACKPOT_COIN;
            self->coinNum = self->unk36C[2] / SLOT2_JACKPOT_COIN;
        } else if (self->jackpotLine == 3) {
            self->coinUnit = SLOT2_JACKPOT_COIN;
            self->coinNum = self->unk36C[3] / SLOT2_JACKPOT_COIN;
        } else if (self->jackpotLine == 4) {
            self->coinUnit = SLOT2_JACKPOT_COIN;
            self->coinNum = self->unk36C[4] / SLOT2_JACKPOT_COIN;
        } else if (self->jackpotLine == 5) {
            self->coinUnit = SLOT2_JACKPOT_COIN;
            self->coinNum = self->unk36C[5] / SLOT2_JACKPOT_COIN;
        }
        VU0_SQC2_VF0_MEM(&pos, 0);
        func_001E8E48(&self->reel[0], &pos);
        self->seId[1] = cSnd_SeCall(D_005FEE00, 2, 2, (int)&pos, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->coinNum == 0 || cCoreSave_isGoldFull(&D_00569B70) != 0 || (D_007474A0.rep & PAD_SKIP_BUTTONS) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId[1]);
            cCoreSave_addGold(&D_00569B70, self->coinUnit * self->coinNum, 0);
            func_001E6ED8(self, 0, 0);
            func_001E6E10(self, 0, 0);
            self->phase = self->phase + 1;
            break;
        }
        cCoreSave_addGold(&D_00569B70, self->coinUnit, 0);
        self->coinNum = self->coinNum - 1;
        break;
    case 3:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}
