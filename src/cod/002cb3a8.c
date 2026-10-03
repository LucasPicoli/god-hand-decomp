/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

/* Find the enemy sound group that lists this sound id; return the group's first id, or the id itself when no group lists it. */
#define EMSE_GROUP_NUM  15
#define EMSE_END        0x2FF           /* ends every group list */

extern int *D_003C30C0[EMSE_GROUP_NUM];

__attribute__((section(".text.cSnd_getEmSeGroupOwner")))
int cSnd_getEmSeGroupOwner(cSnd *self, int id)
{
    int i;
    for (i = 0; i < EMSE_GROUP_NUM; i++) {
        int *p = D_003C30C0[i];
        if (*p == EMSE_END) {
            continue;
        }
        do {
            if (id == *p++) {
                return *D_003C30C0[i];
            }
        } while (*p != EMSE_END);
    }
    return id;
}
