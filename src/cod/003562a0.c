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
extern int DeleteSema(int sid);
extern void func_00355880(unsigned int chcr);   /* setD4_CHCR */

#define D4_CHCR (*(volatile unsigned int *) 0x1000B400)
#define D4_MADR (*(volatile unsigned int *) 0x1000B410)
#define D4_QWC  (*(volatile unsigned int *) 0x1000B420)
#define D4_TADR (*(volatile unsigned int *) 0x1000B430)

__attribute__((section(".text.viBufDelete")))
int viBufDelete(ViBuf *b)
{
    func_00355880(5);
    D4_QWC = 0;
    D4_MADR = 0;
    D4_TADR = 0;
    DeleteSema(b->sema);
    return 1;
}
