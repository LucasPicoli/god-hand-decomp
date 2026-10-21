/* cygnus-2.96 matched TU. */
extern int D_003EE084; /* Scratchpad copy mode: zero uses DMA, nonzero uses the CPU. */
extern int MWSPR_SaveSprMem(void *sprAddr, int size, void *dst);
extern int func_003464D8(int scratchpadOffset, int byteCount, void *destination);

/* Save scratchpad memory to the destination using the selected copy mode. */
__attribute__((section(".text.SprMem_save")))
int SprMem_save(int scratchpadOffset, int byteCount, void *destination)
{
    int result;

    if (D_003EE084 == 0) {
        result = MWSPR_SaveSprMem((void *)scratchpadOffset, byteCount, destination);
    } else {
        result = func_003464D8(scratchpadOffset, byteCount, destination);
    }
    return result;
}
