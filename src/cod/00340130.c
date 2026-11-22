/* cygnus-2.96: DTR_ExecServer, waits out pending SIF DMA on the stream slots: if any active slot
 * still has a transfer in flight, try again later; otherwise finish every used slot. */
typedef struct {
    signed char used; /* 0x0 */
    signed char stat; /* 0x1 */
    signed char req; /* 0x2 */
    char pad3[0x2C - 3];
    unsigned int dma_id; /* 0x2C */
    char pad30[0x40 - 0x30];
} SifDmaSlot;
extern SifDmaSlot D_003EBC20[0x20];
extern int SifDmaStat(unsigned int id);
extern void func_0033FDC0(SifDmaSlot *slot);
extern void func_00332778(void);

__attribute__((section(".text.DTR_ExecServer")))
void DTR_ExecServer(void)
{
    SifDmaSlot *slot;
    int i;

    slot = D_003EBC20;
    for (i = 0; i < 0x20; i++, slot++) {
        if (slot->stat == 1 && slot->req == slot->stat) {
            if (SifDmaStat(slot->dma_id) >= 0)
                return;
        }
    }
    slot = D_003EBC20;
    for (i = 0; i < 0x20; i++, slot++) {
        if (slot->used == 1)
            func_0033FDC0(slot);
    }
    func_00332778();
}
