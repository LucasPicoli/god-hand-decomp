/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"
extern int MWSPR_SaveSprMem(void *sprAddr, int size, void *dst);
extern int MWSPR_SaveSprByCpu(int scratchpadOffset, int byteCount, void *destination);

/* Save scratchpad memory to the destination using the selected copy mode. */
__attribute__((section(".text.SprMem_save")))
int SprMem_save(int scratchpadOffset, int byteCount, void *destination)
{
    int result;

    if (D_003EE084 == 0) {
        result = MWSPR_SaveSprMem((void *)scratchpadOffset, byteCount, destination);
    } else {
        result = MWSPR_SaveSprByCpu(scratchpadOffset, byteCount, destination);
    }
    return result;
}
