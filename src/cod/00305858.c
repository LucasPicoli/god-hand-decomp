/* sn-2.95.3-136 */
#include "godhand/espSys.h"

extern char D_00741DC8[];
extern int func_00306BB0(void *list, int id);
extern void Effect_killByMode(int a0, int a1);

/* Drops one reference to an effect data slot (id, two words, use count).
 * On the last reference, or when `force` is 1, unregisters the data, kills
 * its effects and frees the slot; returns 1 then. A count that was already
 * used up returns 0. */
__attribute__((section(".text.func_00305858")))
int func_00305858(int *self, int force)
{
    int left = 0;

    self[3]--;
    if (force != 1) {
        left = self[3];
    }
    if (left > 0) {
        return 0;
    }
    if (left != 0) {
        return 0;
    }
    func_00306BB0(D_00741DC8, self[0]);
    Effect_killByMode(self[0], 2);
    self[3] = 0;
    self[1] = 0;
    self[2] = 0;
    self[0] = 5;
    return 1;
}
