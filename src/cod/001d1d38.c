/* sn-2.95.3-136 matched TU. */

#include "godhand/BlackJack.h"

extern void SetFlagEntries21And22_1D55D0(BlackJack *self, int on);
extern void SetBlendField105C_1D5998(BlackJack *self, int on);
extern void SetBlendField6AC_1D58F0(BlackJack *self, int on);
extern void func_001D5360(BlackJack *self, int a);
extern void func_001D5430(BlackJack *self, int a);
extern void func_001D5500(BlackJack *self, int a);
extern void CustomIDWork_SetNumber_1D5760(BlackJack *self, int n);
extern void cCoreSave_addGold(char *save, int gold, int log);
extern int cSnd_SeCall_2CB8A0(void *snd, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_007474A0;

/* Bet state: press a button to leave (deal or quit) or take chips back off the bet. */
__attribute__((section(".text.BlackJack_UpdateBetState")))
void BlackJack_UpdateBetState(BlackJack *self)
{
    switch (self->phase) {
    case 0:
        SetFlagEntries21And22_1D55D0(self, 1);
        SetBlendField105C_1D5998(self, 1);
        self->phase += 1;
        /* fallthrough */
    case 1: {
        char *g = (char *)&D_007474A0;
        long f = *(long *)(g + 0x1B0);

        if ((f & 0x3300003000000L) != 0) {
            SetFlagEntries21And22_1D55D0(self, 0);
            SetBlendField6AC_1D58F0(self, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            if (self->bet != 0) {
                self->phase = 0;
                self->state = 3;
            } else {
                self->phase = 0;
                self->state = 1;
            }
            return;
        }
        {
            long h = *(long *)(g + 0x1A0);

            if ((h & 0x10000000L) != 0) {
                cCoreSave_addGold(D_00569B70, self->bet, 0);
                self->bet = 0;
                CustomIDWork_SetNumber_1D5760(self, 0);
                self->phase = 0;
                self->state = 0x14;
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                return;
            }
            if ((h & 0x20000000L) != 0) {
                if (self->bet > 0) {
                    int v;

                    cCoreSave_addGold(D_00569B70, 0x64, 0);
                    v = self->bet - 0x64;
                    self->bet = v;
                    CustomIDWork_SetNumber_1D5760(self, v);
                    func_001D5360(self, 1);
                    func_001D5430(self, 1);
                    if (self->bet == 0)
                        func_001D5500(self, 2);
                } else {
                    self->phase = 0;
                    self->state = 0x14;
                }
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            }
        }
        break;
    }
    }
}
