/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"
extern int MWSPR_RestoreSprMem(void *src, int size, void *sprAddr);
extern int MWSPR_RestoreSprByCpu(void *source, int byteCount, int scratchpadOffset);

/* Restore a saved memory buffer to scratchpad using the selected transfer mode. */
__attribute__((section(".text.SprMem_restore")))
int SprMem_restore(void *source, int byteCount, int scratchpadOffset)
{
    int result;

    if (D_003EE084 == 0) {
        result = MWSPR_RestoreSprMem(source, byteCount, (void *)scratchpadOffset);
    } else {
        result = MWSPR_RestoreSprByCpu(source, byteCount, scratchpadOffset);
    }
    return result;
}
