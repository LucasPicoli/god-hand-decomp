/* ee-2.9-991111 matched TU. */

typedef struct {
    volatile unsigned int chcr;
} sceDmaChan;

#define D_ENABLER (*(volatile unsigned int *)0x1000F520)
#define D_ENABLEW (*(volatile unsigned int *)0x1000F590)
#define D_CTRL    (*(volatile unsigned int *)0x1000E000)

extern int func_003B63A0(void);  /* DIntr */
extern int EIntr(void);  /* EIntr */

__attribute__((section(".text.sceDmaPause")))
unsigned int sceDmaPause(sceDmaChan *chan)
{
    int oldstat;
    unsigned int en;
    unsigned int chcr;

    oldstat = func_003B63A0();
    en = D_ENABLER;
    if (!(en & 0x10000)) {
        D_ENABLEW = en | 0x10000;
    }
    D_CTRL;
    chcr = chan->chcr;
    chan->chcr = chcr & 0xFFFFFEFF;
    D_ENABLEW = en;
    if (oldstat) {
        EIntr();
    }
    return chcr;
}
