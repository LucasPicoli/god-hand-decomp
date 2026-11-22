/* cygnus-2.96: ADXT_SetOutPos, sets the decoder's output callback once the stream is running. */
#include "godhand/globals.h"
typedef struct {
    char pad0[0xE8];
    void *dec;     /* 0xE8 */
    int cbfn;      /* 0xEC */
    int cbobj;     /* 0xF0 */
} StmCore;

typedef struct {
    char pad0[4];
    StmCore *core; /* 0x04 */
} StmLink;

typedef struct {
    char pad0[3];
    signed char stat; /* 0x03 */
    StmLink *link;    /* 0x04 */
} DecOutHn;

extern void func_0033F130(char *msg);
extern void PL2ENC_SetPos(void *dec, int fn, int obj);

__attribute__((section(".text.ADXT_SetOutPos")))
void ADXT_SetOutPos(DecOutHn *hn, int fn, int obj)
{
    StmCore *c;
    void *dec;

    if (hn == 0) {
        func_0033F130(D_00455308);
        return;
    }
    c = hn->link->core;
    dec = c->dec;
    if (hn->stat < 2 || dec == 0) {
        func_0033F130(D_00455330);
        return;
    }
    PL2ENC_SetPos(dec, fn, obj);
    c->cbfn = fn;
    c->cbobj = obj;
}
