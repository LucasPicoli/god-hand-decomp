/* ee-2.9-991111 matched TU. */

extern void  func_003B3650(void *sd);
extern void  SleepThread(void);
extern void  func_003B63F0(void);
extern void SetT2_B0001010_3B6A10(int mode);
extern unsigned long iGetTimerSystemTime(void);
extern void SetNextComp(unsigned long t);

/* ee-2.9-991111 matched TU. */

typedef struct _sif_rpc_packet {
    unsigned char  pad00[0x10];
    unsigned int   rec;        /* 0x10 */
    unsigned char  pad14[0x4];
    unsigned int   pid;        /* 0x18 */
} sceSifRpcPacket;

typedef struct _sif_rpc_data {
    sceSifRpcPacket *paddr;    /* 0x00 */
    unsigned int     pid;      /* 0x04 */
} sceSifRpcData;

__attribute__((section(".text.sceSifCheckStatRpc")))
int sceSifCheckStatRpc(sceSifRpcData *rd)
{
    sceSifRpcPacket *p;

    p = rd->paddr;
    if (p == 0)
        goto zero;
    if (rd->pid != p->pid)
        goto zero;
    if (p->rec & 1)
        goto one;
zero:
    return 0;
one:
    return 1;
}

/* ee-2.9-991111 matched TU. */

typedef struct _sif_rpc_rpkt {
    unsigned char  pad00[0x24];
    void          *src;      /* 0x24 */
    void          *dst;      /* 0x28 */
    int            size;     /* 0x2C */
} sceSifRpcRpkt;

extern int isceSifSendCmd(unsigned int fno, void *pkt, int pktsize,
                          void *src, void *dst, int size);

__attribute__((section(".text.func_003B2CD0")))
unsigned int func_003B2CD0(int id, int t, int c, sceSifRpcRpkt *p)
{
    return isceSifSendCmd(0x80000008, p, 64, p->src, p->dst, p->size) ? 0 : 0x800;
}

extern int isceSifSendCmd(unsigned int fno, void *pkt, int pktsize,
                          void *src, void *dst, int size);

__attribute__((section(".text.func_003B2E38")))
unsigned int func_003B2E38(int id, int t, int c, void *rd)
{
    return isceSifSendCmd(0x80000008, rd, 64, 0, 0, 0) ? 0 : 0x800;
}

__attribute__((section(".text.sceSifRpcLoop")))
void sceSifRpcLoop(void *qd)
{
    void *sd;

    for (;;) {
        while ((sd = func_003B35F8(qd)) != 0) {
            func_003B3650(sd);
        }
        SleepThread();
    }
}

/* ee-2.9-991111 matched TU. */





__attribute__((section(".text.func_003B7510")))
void *func_003B7510(void *a, void *b, void *c, void *d)
{
    int state;
    void *r;

    state = func_003B63A0();
    r = func_003B7400(a, b, c, d);
    if (state != 0) {
        func_003B63F0();
    }
    return r;
}

/* ee-2.9-991111 matched TU. */







__attribute__((section(".text.func_003B6B90")))
int func_003B6B90(void)
{
    int state;
    int mode;

    state = func_003B63A0();
    mode = *(volatile int *)0x10001010;
    if (mode & 0x80) {
        if (state != 0) {
            func_003B63F0();
        }
        return 1;
    }
    SetT2_B0001010_3B6A10((mode & 0xFFFFF3FF) | 0x80);
    SetNextComp(iGetTimerSystemTime());
    if (state != 0) {
        func_003B63F0();
    }
    return 0;
}
