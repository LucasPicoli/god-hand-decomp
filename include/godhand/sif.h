/* include/godhand/sif.h - EE side of the SIF: DMA to the IOP and the command packets (0x3B2xxx-0x3B6xxx). */
#ifndef GODHAND_SIF_H
#define GODHAND_SIF_H

/* One SIF DMA transfer: size bytes from data (EE) to addr (IOP). */
typedef struct sceSifDmaData {
    void *data;                         /* 0x0 */
    void *addr;                         /* 0x4 */
    int size;                           /* 0x8 */
    int mode;                           /* 0xC SIF_DMA_* */
} sceSifDmaData;

#define SIF_DMA_INT_O  0x04             /* interrupt the IOP when the transfer ends */
#define SIF_DMA_ERT    0x40             /* end-of-transfer tag */

/* The header every SIF command packet starts with. */
typedef struct sceSifCmdHdr {
    unsigned int psize : 8;             /* 0x0 packet size */
    unsigned int dsize : 24;            /*     size of the data sent with it */
    void *daddr;                        /* 0x4 IOP address of that data */
    unsigned int fcode;                 /* 0x8 command number */
    unsigned int opt;                   /* 0xC */
} sceSifCmdHdr;

/* _sceSifSendCmd mode bits. */
#define SIF_CMD_M_INTR  0x01            /* called from an interrupt handler */
#define SIF_CMD_M_WBDC  0x04            /* write the data back from the data cache first */

/* System command numbers. */
#define SIF_CMD_INIT_CMD   0x80000002
#define SIF_CMD_RPC_END    0x80000008
#define SIF_CMD_RPC_BIND   0x80000009
#define SIF_CMD_RPC_CALL   0x8000000A
#define SIF_CMD_RPC_RDATA  0x8000000C

#define SIF_SYSREG_RPCINIT 0x80000002   /* set once the IOP side of the RPC is up */

#define SIF_RPC_TABLE_LEN  32           /* entries in each RPC packet table */

/* The RPC layer's state (D_0077FF40). */
typedef struct sceSifRpcState {
    int pid;                            /* 0x00 next packet id */
    void *pktTable;                     /* 0x04 uncached view of D_0077E740 */
    int pktTableLen;                    /* 0x08 */
    int unk0C;
    int unk10;
    void *rdataTable;                   /* 0x14 uncached view of D_0077EF40 */
    int rdataTableLen;                  /* 0x18 */
    void *clientTable;                  /* 0x1C uncached view of D_0077F740 */
    int clientTableLen;                 /* 0x20 */
    int rdataTableIdx;                  /* 0x24 */
    void *activeQueue;                  /* 0x28 */
} sceSifRpcState;

extern void *D_0077E520;                /* IOP address of the command buffer */
extern int D_003FAE54;                  /* nonzero once sceSifInitRpc has run */
extern char D_0077E740[SIF_RPC_TABLE_LEN * 64];    /* RPC packet table */
extern char D_0077EF40[SIF_RPC_TABLE_LEN * 64];    /* RPC receive-data table */
extern char D_0077F740[SIF_RPC_TABLE_LEN * 64];    /* RPC client table */
extern sceSifRpcState D_0077FF40;

unsigned int SifSetDma(sceSifDmaData *dma, int count);
unsigned int isceSifSetDma(sceSifDmaData *dma, int count);
unsigned int SifGetReg(unsigned int reg);
void SifSetReg(unsigned int reg, unsigned int val);
void func_003B2850(void *p, int size);  /* sceSifWriteBackDCache */
void func_003B21D0(void);               /* sceSifInitCmd */
int func_003B2058(int reg);             /* sceSifGetSreg */
void func_003B2488(unsigned int fid, void *func, void *data);   /* sceSifAddCmdHandler */
/* RPC command handlers, as sceSifAddCmdHandler calls them: the packet, then the handler's data. */
void _request_end(void *pkt, void *data);
void func_003B2E78(void *pkt, void *data);  /* _request_bind */
void _request_call(void *pkt, void *data);
void func_003B2D10(void *pkt, void *data);  /* _request_rdata */

unsigned int _sceSifSendCmd(unsigned int fid, int mode, void *pkt, int pktsize, void *src, void *dest, int size);
void sceSifInitRpc(int mode);
unsigned int sceSifSendCmd(unsigned int fid, void *pkt, int pktsize, void *src, void *dest, int size);

/* The next receive-data slot of the RPC tables, cycling through rdataTableLen slots. */
void *func_003B2B90(sceSifRpcState *s);
void *func_003B2DE8(int key, char *a1);

#endif
