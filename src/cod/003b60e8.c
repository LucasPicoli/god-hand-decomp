/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct sifdma {
    void *src;
    void *dest;
    int size;
    int attr;
} SifDmaTransfer;

typedef struct resetpkt {
    unsigned int psize : 8;
    unsigned int dsize : 24;
    void *dest;
    int fcode;
    unsigned int opt;
    int arglen;
    int mode;
    char arg[80];
} __attribute__((aligned(16))) ResetPkt;

extern ResetPkt D_00781BC0;
extern void func_003B79C0(int a, int b);
extern void SifStopDma(void);
extern unsigned int SifGetReg(unsigned int reg);
extern void SifSetReg(unsigned int reg, unsigned int val);
extern int SifSetDma(SifDmaTransfer *t, int count);
extern void func_003B2850(void *p, int len);

__attribute__((section(".text.func_003B60E8")))
int func_003B60E8(char *arg, int mode)
{
    SifDmaTransfer dma;
    unsigned int iopaddr;
    int i;

    func_003B79C0(0, 0);
    func_003B79C0(1, 0);
    SifStopDma();
    iopaddr = SifGetReg(0x80000000);
    D_00781BC0.mode = mode;
    for (i = 0; arg[i] != 0; i++)
        D_00781BC0.arg[i] = arg[i];
    D_00781BC0.dest = 0;
    D_00781BC0.arglen = i;
    D_00781BC0.fcode = 0x80000003;
    D_00781BC0.dsize = 0;
    D_00781BC0.psize = 0x68;
    dma.src = &D_00781BC0;
    dma.dest = (void *)iopaddr;
    dma.size = 0x68;
    dma.attr = 0x44;
    func_003B2850(&D_00781BC0, 0x68);
    SifSetReg(4, 0x40000);
    if (SifSetDma(&dma, 1) != 0) {
        SifSetReg(4, 0x10000);
        SifSetReg(4, 0x20000);
        SifSetReg(0x80000002, 0);
        SifSetReg(0x80000000, 0);
        return 1;
    }
    return 0;
}
