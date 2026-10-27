/* sn-2.95.3-136 */
#include "godhand/seqNode.h"

extern SeqNode *(*D_003F2810[])(signed char kind);  /* the voice node allocators */
extern int D_0076A7AC;                  /* which allocator D_003F2810 uses */

/* Take a free voice node of the given kind with the selected allocator. */
__attribute__((section(".text.func_0037D298")))
SeqNode *func_0037D298(int kind)
{
    return D_003F2810[D_0076A7AC](kind);
}
