/* sn-2.95.3-136 */

#include "godhand/ColiseumBattle.h"
#include "godhand/cGameObj.h"
#include "godhand/cSnd.h"

/* 1 when a live, non-boss enemy of the given kind is on the field. */
__attribute__((section(".text.cSnd_IsEnemyAlive")))
int cSnd_IsEnemyAlive(cSnd *self, int kind)
{
    ColiseumEmNode *node;
    ColiseumEm *em;

    for (node = D_005869F0; node != 0; node = node->next) {
        em = node->em;
        if (em != 0 && (cGameObj_idInRange((cGameObj *)em, COLISEUM_EM_KIND_FIRST, COLISEUM_EM_KIND_END) & 0xFF)) {
            if (!(cGameObj_idInRange((cGameObj *)em, COLISEUM_EM_KIND_BOSS, COLISEUM_EM_KIND_END) & 0xFF)
                && !cEmBase_checkDeadFlag(em) && em->kind == kind) {
                return 1;
            }
        }
    }
    return 0;
}
