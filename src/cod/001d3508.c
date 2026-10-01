/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"

extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern void SetLinkedObjField2B_1D6D68(void *a0, int a1);
extern void cCoreSave_addGold(void *a0, int a1, int a2);
extern void cSnd_BgmEventStart(void *a0, int a1, int a2, int a3);
extern void func_001D49E0(void *a0, int a1);
extern void func_001D4AA8(void *a0, int a1);
extern void func_001D6310(void *a0, int a1);
extern void func_001D6A30(void *a0, int a1);
extern void func_001D6A50(void *a0, int a1);
extern void func_001D6A70(void *a0, int a1);
extern void func_001D6D20(void *a0, int a1);
extern char D_00569B70[];
extern char D_005FEE00[];
extern long D_00747640;

/* sn-2.95.3-136 matched TU. */


















/* Win state: pay out twice the bet, counting the winnings into the gold total. */
__attribute__((section(".text.BlackJack_UpdateWin")))
void BlackJack_UpdateWin(BlackJack *self) {
    switch (self->phase) {
    case 0:
        self->timer = 0x14;
        self->phase = self->phase + 1;
        self->payout = (int)((float)self->bet * 2.0f);
        break;
    case 1:
        if (self->timer == 0) {
            CustomIDWork_SetNumber_1D5760(self, self->payout);
            func_001D6D20(self, 1);
            SetLinkedObjField2B_1D6D68(self, 1);
            func_001D6A70(self, 1);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 2:
        if (self->timer == 0) {
            cSnd_BgmEventStart(D_005FEE00, 0x29, 0, 0);
            func_001D6A50(self, func_001D4720(self));
            func_001D6A30(self, func_001D47E8(self));
            func_001D49E0(self, 1);
            func_001D4AA8(self, func_001D47E8(self) >= 0x16 ? 2 : 1);
            func_001D6310(self, 4);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 3:
        if (self->timer == 0) {
            self->timer = 0x12C;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 4:
        if ((D_00747640 & 0x30000000) != 0 || self->timer == 0) {
            self->timer = self->payout / 10;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 5:
        if ((D_00747640 & 0x30000000) != 0 || self->timer == 0) {
            self->payout = 0;
            CustomIDWork_SetNumber_1D5760(self, 0);
            cCoreSave_addGold(D_00569B70, self->timer * 10, 0);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            int v0 = self->payout;
            if (v0 != 0) {
                self->payout = v0 - 10;
                CustomIDWork_SetNumber_1D5760(self, v0 - 10);
            }
            cCoreSave_addGold(D_00569B70, 10, 0);
            self->timer = self->timer - 1;
        }
        break;
    case 6:
        {
            int t = self->timer;
            if (t != 0) {
                t = t - 1;
                self->timer = t;
                if (t != 0) break;
            }
        }
        func_001D49E0(self, 0);
        func_001D4AA8(self, 0);
        func_001D6310(self, 3);
        self->timer = 0x1E;
        self->phase = self->phase + 1;
        break;
    case 7:
        if (self->timer == 0) {
            func_001D6A70(self, 2);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 8:
        if (self->timer == 0) {
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 9:
        self->state = 0x13;
        self->phase = 0;
        break;
    }
}
