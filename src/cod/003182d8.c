/* sn-2.95.3-136 */
#include "godhand/heapArena.h"
#include "godhand/sideCounter.h"
#include "godhand/ptrVec.h"

extern int D_00754C50;

/* Static initialiser of the game object list TU: constructs the two arenas
 * and the side counter and clears the list. */
__attribute__((section(".text.func_003182D8")))
void func_003182D8(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize != 0) {
        func_002A9528(&D_00754C10);
        func_002A9528(&D_00754C20);
        D_00754C30.v = 0;
        func_002C53A8(&D_00754C38);
        D_00754C50 = 0;
        D_00754C58.v = 0;
    }
}
