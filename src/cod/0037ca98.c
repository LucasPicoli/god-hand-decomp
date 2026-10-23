/* sn-2.95.3-136 */
#include "godhand/seqNode.h"

/* Ages every live sequence link by one frame, stopping at the maximum. */
__attribute__((section(".text.func_0037CA98")))
void func_0037CA98(void)
{
    SeqLink *l = D_0076C8C0;
    int i;

    for (i = 0; i < SEQ_NUM; i++, l++) {
        if (l->flags != 0 && l->age != 0xFFFFFFFF) {
            l->age++;
        }
    }
}
