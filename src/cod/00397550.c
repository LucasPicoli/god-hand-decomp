/* ee-2.9-991111 matched TU. */

typedef struct {
    volatile unsigned int chcr;
} sceDmaChan;

extern void WaitDma(sceDmaChan *chan);

__attribute__((section(".text.sceDmaSync")))
int sceDmaSync(sceDmaChan *chan, int mode)
{
    if (mode == 1) {
        return (chan->chcr >> 8) & 1;
    }
    WaitDma(chan);
    return 0;
}
