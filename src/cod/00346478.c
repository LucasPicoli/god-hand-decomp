/* cygnus-2.96 matched TU. */

extern void MWDMA_WaitEnd(int ch);

__attribute__((section(".text.mwrsc_WaitSprDmaEnd")))
void mwrsc_WaitSprDmaEnd(void)
{
    MWDMA_WaitEnd(8);
    MWDMA_WaitEnd(9);
}
