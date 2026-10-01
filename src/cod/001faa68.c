/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"


/* Max vitality grows by 20 for every vitality upgrade, from a base of 100. */
__attribute__((section(".text.cCoreSave_updateVitalMax")))
void cCoreSave_updateVitalMax(cCoreSave *self)
{
    if (self->data != 0) {
        self->data->vitalMax = cCoreSave_getState154(self) * 20 + 100;
    }
}

/* Set upgrade counter `kind` (0..4, else 0) to `lv` clamped to 0..9. */
__attribute__((section(".text.cCoreSave_setUpgradeLv")))
void cCoreSave_setUpgradeLv(cCoreSave *self, unsigned int kind, int lv)
{
    cCoreSaveData *data = self->data;
    if (data == 0) return;
    if (kind >= 5) kind = 0;
    if (lv > 9) lv = 9;
    if (lv < 0) lv = 0;
    data->upgradeLv[kind] = lv;
}

/* Add `n` to upgrade counter `kind` (0..4, else 0), then clamp it to 0..9. */
__attribute__((section(".text.cCoreSave_addUpgradeLv")))
void cCoreSave_addUpgradeLv(cCoreSave *self, unsigned int kind, int n)
{
    if (self->data == 0) return;
    if (kind >= 5) kind = 0;
    self->data->upgradeLv[kind] += n;
    if (self->data->upgradeLv[kind] >= 10) self->data->upgradeLv[kind] = 9;
    if (self->data->upgradeLv[kind] < 0) self->data->upgradeLv[kind] = 0;
}

extern int D_00747A2C[];            /* [2] is the cheat flag word */




/* New game: empty every combo set, give the starting combos (the all-moves
 * cheat adds a longer first set) and unlock the first god reels. */
__attribute__((section(".text.cCoreSave_initCombos")))
void cCoreSave_initCombos(cCoreSave *self)
{
    unsigned int set;
    unsigned int slot;

    if (self->data != 0) {
        for (set = 0; set < CORESAVE_COMBO_SETS; set++) {
            for (slot = 0; slot < CORESAVE_COMBO_LEN; slot++) {
                cCoreSave_setCombo(self, set, slot, 0, 0);
            }
            cCoreSave_setComboMax(self, set, 0);
        }
        if ((D_00747A2C[2] & 0x800) != 0) {
            cCoreSave_setCombo(self, 0, 0, 0, 0);
            cCoreSave_setCombo(self, 0, 1, 4, 0);
            cCoreSave_setCombo(self, 0, 2, 0xD, 0);
            cCoreSave_setCombo(self, 0, 3, 0x27, 0);
            cCoreSave_setComboMax(self, 0, 4);
            cCoreSave_setCombo(self, 1, 0, 0x1D, 0);
            cCoreSave_setComboMax(self, 1, 1);
            cCoreSave_setCombo(self, 2, 0, 0x25, 0);
            cCoreSave_setComboMax(self, 2, 1);
            cCoreSave_setCombo(self, 3, 0, 0x54, 0);
            cCoreSave_setComboMax(self, 3, 1);
            cCoreSave_setCombo(self, 4, 0, 0x55, 0);
            cCoreSave_setComboMax(self, 4, 1);
            cCoreSave_setCombo(self, 5, 0, 0x34, 0);
            cCoreSave_setComboMax(self, 5, 1);
        } else {
            cCoreSave_setCombo(self, 0, 0, 0, 0);
            cCoreSave_setCombo(self, 0, 1, 4, 0);
            cCoreSave_setCombo(self, 0, 2, 0xA, 0);
            cCoreSave_setCombo(self, 0, 3, 0xD, 0);
            cCoreSave_setComboMax(self, 0, 4);
            cCoreSave_setCombo(self, 1, 0, 0x1D, 0);
            cCoreSave_setComboMax(self, 1, 1);
            cCoreSave_setCombo(self, 2, 0, 0x25, 0);
            cCoreSave_setComboMax(self, 2, 1);
            cCoreSave_setCombo(self, 3, 0, 0x54, 0);
            cCoreSave_setComboMax(self, 3, 1);
            cCoreSave_setCombo(self, 4, 0, 0x55, 0);
            cCoreSave_setComboMax(self, 4, 1);
            cCoreSave_setCombo(self, 5, 0, 0x34, 0);
            cCoreSave_setComboMax(self, 5, 1);
        }
        cCoreSave_setGodReel(self, 1);
        cCoreSave_setGodReel(self, 2);
        cCoreSave_setGodReel(self, 3);
        cCoreSave_setGodReel(self, 7);
        cCoreSave_setGodReel(self, 0xB);
        cCoreSave_setGodReel(self, 0xE);
        cCoreSave_setGodReel(self, 0xF);
        cCoreSave_setGodReel(self, 0x17);
    }
}
