/* ee-2.9-991111 matched TU. */

typedef struct _sif_serve_data sceSifServeData;
typedef struct _sif_queue_data sceSifQueueData;

typedef void *(*sceSifRpcFunc)(unsigned int, void *, int);

struct _sif_serve_data {
    unsigned int      command;   /* 0x00 */
    sceSifRpcFunc     func;      /* 0x04 */
    void             *buff;      /* 0x08 */
    int               size;      /* 0x0C */
    sceSifRpcFunc     cfunc;     /* 0x10 */
    void             *cbuff;     /* 0x14 */
    int               csize;     /* 0x18 */
    void             *client;    /* 0x1C */
    void             *paddr;     /* 0x20 */
    unsigned int      fno;       /* 0x24 */
    void             *receive;   /* 0x28 */
    int               rsize;     /* 0x2C */
    int               rmode;     /* 0x30 */
    unsigned int      rid;       /* 0x34 */
    sceSifServeData  *link;      /* 0x38 */
    sceSifServeData  *next;      /* 0x3C */
    sceSifQueueData  *base;      /* 0x40 */
};

struct _sif_queue_data {
    int               key;       /* 0x00 */
    int               active;    /* 0x04 */
    sceSifServeData  *link;      /* 0x08 */
    sceSifServeData  *start;     /* 0x0C */
    sceSifServeData  *end;       /* 0x10 */
    sceSifQueueData  *next;      /* 0x14 */
};

typedef struct {
    unsigned char     pad00[0x28];
    sceSifQueueData  *queue;     /* 0x28 */
    unsigned char     pad2C[0x14];
} sceSifRpcCtl;

extern sceSifRpcCtl D_0077FF40;
extern void func_003B63A0(void);
extern void func_003B63F0(void);

__attribute__((section(".text.func_003B3400")))
void func_003B3400(sceSifServeData *sd, unsigned int command,
                   sceSifRpcFunc func, void *buff,
                   sceSifRpcFunc cfunc, void *cbuff, sceSifQueueData *qd)
{
    sceSifServeData *p;
    sceSifServeData *s;

    func_003B63A0();
    sd->command = command;
    sd->func = func;
    sd->buff = buff;
    sd->cfunc = cfunc;
    sd->cbuff = cbuff;
    sd->next = 0;
    sd->link = 0;
    sd->base = qd;
    p = qd->link;
    if (p == 0) {
        qd->link = sd;
    } else {
        s = p;
        while (s->link != 0) {
            s = s->link;
        }
        s->link = sd;
    }
    func_003B63F0();
}
