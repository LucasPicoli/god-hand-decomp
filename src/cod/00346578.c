/* cygnus-2.96 matched TU. */
extern int D_003EE084; /* Scratchpad transfer mode: zero uses DMA, nonzero uses CPU copying. */
extern int MWSPR_RestoreSprMem(void *source, int byteCount, void *scratchpadOffset);
extern int func_003465B8(void *source, int byteCount, int scratchpadOffset);

/* Restore a saved memory buffer to scratchpad using the selected transfer mode. */
__attribute__((section(".text.SprMem_restore")))
int SprMem_restore(void *source, int byteCount, int scratchpadOffset)
{
    int result;

    if (D_003EE084 == 0) {
        result = MWSPR_RestoreSprMem(source, byteCount, (void *)scratchpadOffset);
    } else {
        result = func_003465B8(source, byteCount, scratchpadOffset);
    }
    return result;
}
