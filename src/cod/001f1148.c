/* sn-2.95.3-136 */
#include "godhand/ColiseumBattle.h"
#include "godhand/cEmWrap.h"
#include "godhand/cEmManage.h"

extern void cEmWrap_SetVitalMax(void *a0, int a1);
extern void cEmWrap_SetVital(void *a0, int a1);
extern void cEm00_setDevilFlag(char *a0);
extern void ColiseumBattle_DefeatAllEnemies(ColiseumBattle *self);

#define VITAL_MAX_FRACTION  0.01f       /* the wave's enemies keep 1 percent of their max */

/* The entry number comes in as an int, as a constructor would take it:
 * assigning the byte constant directly changes the code. */
static __inline__ void cEmWrap_setEntry(cEmWrap *em, int entryNo)
{
    em->entryNo = entryNo;
}

/* Devil wave of the coliseum: phase 0 cuts the three wave enemies to 1 percent
 * of their max at full health and turns on their devil flag; phase 1 counts
 * each one once when it dies. */
__attribute__((section(".text.func_001F1148")))
void func_001F1148(ColiseumBattle *self)
{
    cEmWrap em[3];
    long dead;

    cEmWrap_setEntry(&em[0], 0);
    cEmWrap_setEntry(&em[1], 1);
    cEmWrap_setEntry(&em[2], 2);
    switch (self->phase) {
    case 0:
        cEmWrap_SetVitalMax(&em[0], (int)(cEmWrap_GetVitalMax(&em[0]) * VITAL_MAX_FRACTION));
        cEmWrap_SetVitalMax(&em[1], (int)(cEmWrap_GetVitalMax(&em[1]) * VITAL_MAX_FRACTION));
        cEmWrap_SetVitalMax(&em[2], (int)(cEmWrap_GetVitalMax(&em[2]) * VITAL_MAX_FRACTION));
        cEmWrap_SetVital(&em[0], cEmWrap_GetVitalMax(&em[0]));
        cEmWrap_SetVital(&em[1], cEmWrap_GetVitalMax(&em[1]));
        cEmWrap_SetVital(&em[2], cEmWrap_GetVitalMax(&em[2]));
        cEm00_setDevilFlag((char *)cEmManage_GetEm(&D_005864F0, em[0].entryNo));
        cEm00_setDevilFlag((char *)cEmManage_GetEm(&D_005864F0, em[1].entryNo));
        cEm00_setDevilFlag((char *)cEmManage_GetEm(&D_005864F0, em[2].entryNo));
        ColiseumBattle_DefeatAllEnemies(self);
        self->deadMask = 0;
        self->phase++;
        break;
    case 1:
        dead = (unsigned int)self->deadMask;
        if ((dead & 1) == 0 && cEmWrap_isDead(&em[0])) {
            self->enemyNum++;
            self->deadMask |= 1;
        }
        dead = (unsigned int)self->deadMask;
        if ((dead >> 1 & 1) == 0 && cEmWrap_isDead(&em[1])) {
            self->enemyNum++;
            self->deadMask |= 2;
        }
        dead = (unsigned int)self->deadMask;
        if ((dead >> 2 & 1) == 0 && cEmWrap_isDead(&em[2])) {
            self->enemyNum++;
            self->deadMask |= 4;
        }
        break;
    }
}
