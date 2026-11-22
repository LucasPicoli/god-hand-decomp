/* cygnus-2.96: lsc_StatEnd, advances a 16-entry ring of queued requests; when the ring empties it
 * finishes the stream, and in mode 1 forwards the entry that was current. */
typedef struct StmReq {
    int unk0;
    int a;      /* 0x04 */
    int unk8;
    int b;      /* 0x0C */
    int c;      /* 0x10 */
    int d;      /* 0x14 */
    char unk18[8];
} StmReq;

typedef struct StmReqRing {
    char unk0;
    char done;          /* 0x01 */
    char unk2;
    signed char mode;   /* 0x03 */
    char unk4[0x1C];
    int idx;            /* 0x20 */
    int count;          /* 0x24 */
    int active;         /* 0x28 */
    char unk2C[0xC];
    StmReq req[16];  /* 0x38 */
} StmReqRing;

extern void func_00335C30(void);
extern int func_00335638(StmReqRing *r, int a, int b, int c, int d);

__attribute__((section(".text.lsc_StatEnd")))
void lsc_StatEnd(StmReqRing *r)
{
    int a = 0, c = 0, d = 0, b = 0;

    if (r->active == 0)
        return;
    if (r->mode == 1) {
        StmReq *q = &r->req[r->idx];
        c = q->c;
        a = q->a;
        b = q->b;
        d = q->d;
    }
    r->idx = (r->idx + 1) % 16;
    if (--r->count <= 0) {
        func_00335C30();
        r->done = 1;
    }
    if (r->mode == 1)
        func_00335638(r, a, b, c, d);
}
