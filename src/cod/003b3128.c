/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 candidate: func_003B3128 = sceSifCallRpc (libkernl sifrpc.c) */
#include "godhand/gp.h"

typedef unsigned int u_int;

typedef struct _sif_rpc_pkt {
    unsigned char  pad00[0x14];
    u_int          self;     /* 0x14 */
    u_int          pid;      /* 0x18 */
    u_int          client;   /* 0x1C */
    u_int          fno;      /* 0x20 */
    int            ssize;    /* 0x24 */
    u_int          recv;     /* 0x28 */
    int            rsize;    /* 0x2C */
    int            rmode;    /* 0x30 */
    int            server;   /* 0x34 */
    unsigned char  pad38[0x8];
} sceSifRpcPkt;

typedef struct _sif_client_data {
    sceSifRpcPkt  *paddr;    /* 0x00 */
    u_int          pid;      /* 0x04 */
    int            sema;     /* 0x08 */
    int            pad0C;    /* 0x0C */
    u_int          command;  /* 0x10 */
    u_int          buff;     /* 0x14 */
    u_int          gp;       /* 0x18 */
    void         (*efunc)(void *); /* 0x1C */
    void          *epara;    /* 0x20 */
    int            server;   /* 0x24 */
} sceSifClientData;

struct SemaParam {
    int            count;        /* 0x00 */
    int            max_count;    /* 0x04 */
    int            init_count;   /* 0x08 */
    int            wait_threads; /* 0x0C */
    u_int          attr;         /* 0x10 */
    u_int          option;       /* 0x14 */
};

extern unsigned char D_0077FF40;
extern unsigned char D_00460070;

extern sceSifRpcPkt *func_003B2AC8(void *rd);      /* _sceRpcGetPacket */
extern void  func_003B2B70(sceSifRpcPkt *p);       /* _sceRpcFreePacket */
extern void  func_003B2850(void *p, int size);     /* sceSifWriteBackDCache */
extern int   sceSifSendCmd(u_int fno, void *pkt, int pktsize, void *src, void *dst, int size);
extern int   CreateSema(struct SemaParam *sp);
extern int   DeleteSema(int id);
extern int   WaitSema(int id);

__attribute__((section(".text.func_003B3128")))
int func_003B3128(sceSifClientData *cd, u_int fno, u_int mode, void *send, int ssize,
                  void *recv, int rsize, void (*efunc)(void *), void *epara)
{
    sceSifRpcPkt *p;
    struct SemaParam sp;
    int srv;

    p = func_003B2AC8(&D_0077FF40);
    if (p == 0)
        return -1;
    cd->epara = epara;
    cd->pid = p->pid;
    cd->paddr = p;
    cd->efunc = efunc;
    cd->gp = (u_int)GetGp();
    p->fno = fno;
    p->ssize = ssize;
    p->recv = (u_int)recv;
    p->rsize = rsize;
    p->self = (u_int)p;
    srv = cd->server;
    p->client = (u_int)cd;
    p->server = srv;
    if ((mode & 2) == 0) {
        if (send == recv) {
            func_003B2850(send, (ssize < rsize) ? rsize : ssize);
        } else {
            if (ssize > 0)
                func_003B2850(send, ssize);
            if (rsize > 0)
                func_003B2850(recv, rsize);
        }
    }
    if (mode & 1) {
        if (efunc == 0) {
            p->rmode = 0;
        } else {
            p->rmode = 1;
        }
        cd->sema = -1;
        if (sceSifSendCmd(0x8000000A, p, 64, send, (void *)cd->buff, ssize) != 0)
            return 0;
        func_003B2B70(p);
        return -2;
    } else {
        sp.init_count = 0;
        sp.option = (u_int)&D_00460070;
        sp.max_count = 1;
        cd->sema = CreateSema(&sp);
        if (cd->sema < 0) {
            func_003B2B70(p);
            return -3;
        }
        p->rmode = 1;
        if (sceSifSendCmd(0x8000000A, p, 64, send, (void *)cd->buff, ssize) == 0) {
            DeleteSema(cd->sema);
            func_003B2B70(p);
            return -2;
        }
        WaitSema(cd->sema);
        DeleteSema(cd->sema);
        return 0;
    }
}
