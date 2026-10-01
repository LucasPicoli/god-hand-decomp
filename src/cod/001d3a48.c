/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"

extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern void SetLinkedObjField2B_1D6D68(void *a0, int a1);
extern void cCoreSave_addGold(void *a0, int a1, int a2);
extern void func_001D49E0(void *a0, int a1);
extern void func_001D4AA8(void *a0, int a1);
extern void func_001D65B0(void *a0, int a1);
extern void func_001D6A30(void *a0, int a1);
extern void func_001D6A50(void *a0, int a1);
extern void func_001D6A70(void *a0, int a1);
extern void func_001D6D20(void *a0, int a1);
extern char D_00569B70[];
extern long D_00747640;

/* sn-2.95.3-136 matched TU. */
















/* Bet-back state: pay the bet back into the gold total in steps of 10, then end the round. */
__attribute__((section(".text.func_001D3A48")))
void func_001D3A48(BlackJack *self) {
    switch (self->phase) {
    case 0:
        self->timer = 0x14;
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->timer == 0) {
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
            func_001D6A50(self, func_001D4720(self));
            func_001D6A30(self, func_001D47E8(self));
            func_001D49E0(self, 1);
            func_001D4AA8(self, 1);
            func_001D65B0(self, 4);
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
            self->timer = self->bet / 10;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 5:
        if ((D_00747640 & 0x30000000) != 0 || self->timer == 0) {
            self->bet = 0;
            CustomIDWork_SetNumber_1D5760(self, 0);
            cCoreSave_addGold(D_00569B70, self->timer * 10, 0);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            int v0 = self->bet;
            if (v0 != 0) {
                self->bet = v0 - 10;
                CustomIDWork_SetNumber_1D5760(self, v0 - 10);
            }
            cCoreSave_addGold(D_00569B70, 10, 0);
            self->timer = self->timer - 1;
        }
        break;
    case 6:
        if (self->timer == 0) {
            func_001D49E0(self, 0);
            func_001D4AA8(self, 0);
            func_001D65B0(self, 3);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
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
