/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 matched TU. */

typedef struct _sif_rpc_pkt {
    unsigned char  pad00[0x14];
    void          *w14;      /* 0x14 */
    unsigned int   w18;      /* 0x18 */
    void          *w1c;      /* 0x1C */
    int            w20;      /* 0x20 */
    unsigned char  pad24[0x1C];
} sceSifRpcPkt;

typedef struct _sif_client_data {
    sceSifRpcPkt  *paddr;    /* 0x00 */
    unsigned int   pid;      /* 0x04 */
    int            sema;     /* 0x08 */
    unsigned char  pad0C[0x4];
    unsigned int   command;  /* 0x10 */
    unsigned char  pad14[0x10];
    void          *server;   /* 0x24 */
} sceSifClientData;

typedef struct _ee_sema {
    int            count;        /* 0x00 */
    int            max_count;    /* 0x04 */
    int            init_count;   /* 0x08 */
    int            wait_threads; /* 0x0C */
    unsigned int   attr;         /* 0x10 */
    unsigned int   option;       /* 0x14 */
} sceSifSemaParam;

extern unsigned char D_0077FF40;
extern unsigned char D_00460060;

extern void  func_003B2B70(sceSifRpcPkt *p);
extern int   sceSifSendCmd(unsigned int fno, void *pkt, int pktsize,
                           void *src, void *dst, int size);
extern int   CreateSema(sceSifSemaParam *sp);
extern int   DeleteSema(int id);
extern int   WaitSema(int id);

__attribute__((section(".text.func_003B2F48")))
int func_003B2F48(sceSifClientData *cd, int sid, unsigned int mode)
{
    sceSifRpcPkt *p;
    sceSifSemaParam sp;

    cd->command = 0;
    cd->server = 0;
    p = func_003B2AC8(&D_0077FF40);
    if (p == 0)
        return -1;
    cd->paddr = p;
    cd->pid = p->w18;
    p->w20 = sid;
    p->w14 = p;
    p->w1c = cd;
    if ((mode & 1) == 0) {
        sp.max_count = 1;
        sp.option = (unsigned int)&D_00460060;
        sp.init_count = 0;
        cd->sema = CreateSema(&sp);
        if (cd->sema < 0) {
            func_003B2B70(p);
            return -3;
        }
        if (sceSifSendCmd(0x80000009, p, 64, 0, 0, 0) == 0) {
            func_003B2B70(p);
            DeleteSema(cd->sema);
            return -2;
        }
        WaitSema(cd->sema);
        DeleteSema(cd->sema);
        return 0;
    } else {
        cd->sema = -1;
        if (sceSifSendCmd(0x80000009, p, 64, 0, 0, 0) != 0)
            return 0;
        func_003B2B70(p);
        return -2;
    }
}
