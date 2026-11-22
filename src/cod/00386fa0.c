/* sn-2.95.3-136: SdeStrOpen, queues a copy of a 0x60-byte request in a new node unless the id is
 * already busy or the request is flagged; returns the node's handle. */
typedef struct SndReq {
    char pad0[6];
    unsigned char kind;                 /* 0x06 */
    char pad7[7];
    unsigned short flags;               /* 0x0E */
    char pad10[0x50];
} SndReq;

typedef struct SndReqNode {
    short used;                         /* 0x00 */
    int handle;                         /* 0x04 */
    unsigned char kind;                 /* 0x08 */
    unsigned char state;                /* 0x09 */
    short link;                         /* 0x0A */
    short id;                           /* 0x0C */
    char pad0E[2];
    SndReq req;                      /* 0x10 */
} SndReqNode;

extern int SdeStrStatusGetByWorkId(short id);
extern SndReqNode *SdeStrExeOpen(void);
extern int SdeSndIdNew(void);

__attribute__((section(".text.SdeStrOpen")))
int SdeStrOpen(short id, SndReq *req)
{
    SndReqNode *n;

    if (SdeStrStatusGetByWorkId(id) != 0)
        return 0;
    if (req->flags & 0x8000)
        return 0;
    n = SdeStrExeOpen();
    if (n == 0)
        return 0;
    n->used = 1;
    n->handle = SdeSndIdNew();
    n->kind = req->kind;
    n->state = 2;
    n->link = -1;
    n->id = id;
    n->req = *req;
    return n->handle;
}
