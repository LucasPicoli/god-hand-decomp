/* sn-2.95.3-136 */
#include "godhand/seqNode.h"
#include "godhand/globals.h"

extern SeqNode *(*D_003F2810[])(signed char kind);  /* the voice node allocators */

/* Take a free voice node of the given kind with the selected allocator. */
__attribute__((section(".text.SdeVregOpen")))
SeqNode *SdeVregOpen(int kind)
{
    return D_003F2810[D_0076A7AC](kind);
}
