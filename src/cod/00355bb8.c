/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef struct {
    /* 0x00 */ unsigned int base;
    /* 0x04 */ unsigned int tagp;
    /* 0x08 */ int nblk;
    /* 0x0C */ int rd;
    /* 0x10 */ int rdofs;
    /* 0x14 */ int wr;
    /* 0x18 */ int size;
    /* 0x1C */ unsigned char pad1C[0x40 - 0x1C];
    /* 0x40 */ int sema;
    /* 0x44 */ int active;
    /* 0x48 */ long long total;
    /* 0x50 */ void *ent;
    /* 0x54 */ int nent;
    /* 0x58 */ int f58;
    /* 0x5C */ int f5C;
} ViBuf;

extern int WaitSema(int sid);
extern int SignalSema(int sid);

__attribute__((section(".text.viBufEndPut")))
void viBufEndPut(ViBuf *b, int n)
{
    WaitSema(b->sema);
    b->wr += n;
    b->total = n + b->total;
    SignalSema(b->sema);
}
