/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"

extern void func_001D5430(void *a0, int a1);
extern void SetBlendField4BC_1D5848(void *a0, int a1);
extern void func_001D5360(void *a0, int a1);
extern void func_001D5500(void *a0, int a1);
extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern int cCoreSave_getGold(char *a0);
extern void cCoreSave_addGold(char *a0, int a1, int a2);
extern void cCoreSave_subGold(char *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_007474A0;

/* sn-2.95.3-136 matched TU. */














/* Betting state: pad buttons confirm the bet or step it by 100, paying gold in and out. */
__attribute__((section(".text.BlackJack_UpdateMaxBetMenu")))
void BlackJack_UpdateMaxBetMenu(BlackJack *self)
{
    switch (self->phase) {
    case 0:
        func_001D5430(self, 0);
        SetBlendField4BC_1D5848(self, 1);
        self->phase += 1;
        /* fallthrough */
    case 1: {
        char *g = (char *)&D_007474A0;
        long f = *(long *)(g + 0x1B0);

        if ((f & 0x8800004000000L) != 0) {
            func_001D5430(self, 1);
            SetBlendField4BC_1D5848(self, 0);
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
        if ((f & 0x4400008000000L) != 0) {
            func_001D5430(self, 1);
            SetBlendField4BC_1D5848(self, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            self->phase = 0;
            self->state = 1;
            return;
        }
        if ((f & 0x3300003000000L) != 0) {
            func_001D5430(self, 1);
            SetBlendField4BC_1D5848(self, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            self->phase = 0;
            self->state = 4;
            return;
        }
        {
            long h = *(long *)(g + 0x1A0);

            if ((h & 0x10000000L) != 0) {
                while (self->bet < self->betMax &&
                       cCoreSave_getGold(D_00569B70) >= 0x64) {
                    cCoreSave_subGold(D_00569B70, 0x64);
                    self->bet += 0x64;
                    self->flags |= 8;
                }
                if (self->bet != 0) {
                    CustomIDWork_SetNumber_1D5760(self, self->bet);
                    func_001D5430(self, 2);
                    SetBlendField4BC_1D5848(self, 0);
                    func_001D5360(self, 2);
                    self->phase = 0;
                    self->state = 3;
                }
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
                    if (self->bet == 0)
                        func_001D5500(self, 2);
                } else {
                    func_001D5430(self, 1);
                    SetBlendField4BC_1D5848(self, 0);
                    self->phase = 0;
                    self->state = 4;
                }
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            }
        }
        break;
    }
    }
}
