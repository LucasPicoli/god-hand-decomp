/* sn-2.95.3-136 */
/* func_001B7568: classify a hit into the cOmBase hit flags (sn-2.95.3-136) */
#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"

/* Classify an incoming hit by its attack kind into the COMBASE_HIT_* bits of hitFlags:
 * strong for kinds 0x2E-0x2F, player for a strong-enough hit from an actor in 0x100-0x1FE
 * (most kinds), knock-back for kinds 8-11, 0x1C, 0x30 and 0x52. */
__attribute__((section(".text.func_001B7568")))
void func_001B7568(cOmBase *self, cDamageTake *hit)
{
    short kind = hit->kind;

    if (kind < 0x30) {
        if (kind >= 0x2E)
            self->hitFlags |= COMBASE_HIT_STRONG;
    }
    if ((unsigned int)(kind - 7) >= 2) {
        if (kind != 0x15 && kind != 0x13 && kind != 0x18 && kind != 0x1C && kind != 0x21
            && kind != 0x22 && kind != 0x29 && kind != 0x2A && kind != 0x2B && kind != 0x31
            && hit->attacker != 0) {
            if (cGameObj_idInRange((cGameObj *)hit->attacker, 0x100, 0x1FF) == 1 && hit->power >= 0xB)
                self->hitFlags |= COMBASE_HIT_PLAYER;
        }
    }
    if ((unsigned int)(kind - 8) < 4 || kind == 0x1C || kind == 0x30 || kind == 0x52)
        self->hitFlags |= COMBASE_HIT_KNOCKBACK;
}
