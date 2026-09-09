/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 matched TU. */

typedef struct _sif_rpc_pkt {
    unsigned char  pad00[0x10];
    unsigned int   mode;     /* 0x10 */
    void          *rbuff;    /* 0x14 */
    unsigned char  pad18[0x4];
    void          *client;   /* 0x1C */
    void          *paddr;    /* 0x20 */
    void          *receive;  /* 0x24 */
    void          *rsize;    /* 0x28 */
    void          *w2c;      /* 0x2C */
} sceSifRpcPkt;

extern void *_sceRpcGetFPacket2(void *q, int i);

extern int   isceSifSendCmd(unsigned int fno, void *pkt, int pktsize,
                            void *src, void *dst, void *size);
extern void  func_003B7898(int usec, void *handler, void *arg);
extern unsigned int func_003B2CD0(int id, int t, int c, void *rd);

__attribute__((section(".text.func_003B2D10")))
void func_003B2D10(sceSifRpcPkt *rq, void *q)
{
    sceSifRpcPkt *p;
    unsigned int mode;
    void *rbuff;
    void *client;

    mode = rq->mode;
    if (mode & 4) {
        p = _sceRpcGetFPacket2(q, mode >> 16);
    } else {
        p = func_003B2B90(q);
    }
    rbuff  = rq->rbuff;
    client = rq->client;
    p->rbuff   = rbuff;
    p->client  = client;
    p->paddr   = (void *)0x8000000C;
    p->receive = rq->paddr;
    p->rsize   = rq->receive;
    p->w2c     = rq->rsize;
    if (isceSifSendCmd(0x80000008, p, 64, rq->paddr, rq->receive, rq->rsize) == 0) {
        func_003B7898(0x800, (void *)func_003B2CD0, p);
    }
}
