/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"

extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern void cSnd_BgmEventStart(void *a0, int a1, int a2, int a3);
extern void func_001D49E0(void *a0, int a1);
extern void func_001D4AA8(void *a0, int a1);
extern void func_001D6460(void *a0, int a1);
extern void func_001D6A30(void *a0, int a1);
extern void func_001D6A50(void *a0, int a1);
extern void func_001D6A70(void *a0, int a1);
extern char D_005FEE00[];
extern long D_00747640;

/* sn-2.95.3-136 matched TU. */
















/* Lost-round state: clear the bet display, start bgm event 0x28, then end the round. */
__attribute__((section(".text.func_001D3808")))
void func_001D3808(BlackJack *self) {
    switch (self->phase) {
    case 0:
        self->timer = 0x14;
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->timer == 0) {
            CustomIDWork_SetNumber_1D5760(self, 0);
            func_001D6A70(self, 1);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 2:
        if (self->timer == 0) {
            cSnd_BgmEventStart(D_005FEE00, 0x28, 0, 0);
            func_001D6A50(self, func_001D4720(self));
            func_001D49E0(self, func_001D4720(self) >= 0x16 ? 2 : 1);
            {
                int c = func_001D4720(self) < 0x16;
                if ((c ^ 1) == 0) {
                    func_001D6A30(self, func_001D47E8(self));
                    if (func_001D49B0(self) != 0) {
                        func_001D4AA8(self, 4);
                    } else if (func_001D4918(self) != 0) {
                        func_001D4AA8(self, 3);
                    } else {
                        func_001D4AA8(self, 1);
                    }
                }
            }
            func_001D6460(self, 4);
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
            func_001D49E0(self, 0);
            func_001D4AA8(self, 0);
            func_001D6460(self, 3);
            self->timer = 0x1E;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 5:
        if (self->timer == 0) {
            func_001D6A70(self, 2);
            self->timer = 0x14;
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 6:
        if (self->timer == 0) {
            self->phase = self->phase + 1;
        } else {
            self->timer = self->timer - 1;
        }
        break;
    case 7:
        self->state = 0x13;
        self->phase = 0;
        break;
    }
}
