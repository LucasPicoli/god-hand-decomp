/* sn-2.95.3-136 */
/* func_00150C10: place one bank header on the next free channels (mode 0 directly, mode 1 unless the
 * header is already loaded) and advance the cursor; returns the first channel, or -1 (sn-2.95.3-136) */

typedef struct BankHdr {
    char pad0[0x12];
    unsigned short blocks;      /* 0x12 */
} BankHdr;

typedef struct BankCh {
    char pad0[2];
    unsigned char blocks;       /* 0x02 */
    char pad3[0x10 - 0x3];
    unsigned short nch;         /* 0x10 */
    unsigned short len;         /* 0x12 */
    BankHdr *hdr;               /* 0x14 */
    char pad18[0xB0 - 0x18];
} BankCh;

typedef struct BankCursor {
    int count;                  /* 0x00 */
    int ch;                     /* 0x04 */
    char *addr;                 /* 0x08 */
    int spu;                    /* 0x0C */
} BankCursor;

extern BankCh D_00747BA0[];

extern int func_0030A298(int a0);
extern void func_003090F8(unsigned char ch, char *hdr, char *addr, unsigned int spu);
extern short func_00150D78(void *a0, int id);
extern void func_00309D88(int ch, char *hdr, char *addr, int spu, int flag);
extern void func_0030A200(int n);

__attribute__((section(".text.func_00150C10")))
int func_00150C10(BankCursor *c, char *str, int mode)
{
    int r = -1;
    short s;

    if (str != 0) {
        if (mode == 0) {
            BankCh *e;

            func_003090F8(c->ch, str, c->addr, func_0030A298(c->spu));
            r = c->ch;
            e = &D_00747BA0[r];
            c->count++;
            c->ch = r + e->nch;
            c->spu += e->blocks;
            c->addr += e->len;
        }
        if (mode == 1) {
            s = func_00150D78(c, (int)str);
            if (s != -1)
                r = s;
            else {
                BankCh *e;
                BankHdr *hdr;

                func_00309D88(c->ch, str, c->addr, c->spu, 1);
                func_0030A200(c->ch);
                r = c->ch;
                e = &D_00747BA0[r];
                c->count++;
                hdr = e->hdr;
                c->ch = r + e->nch;
                c->spu += hdr->blocks;
                c->addr += e->len;
            }
        }
    }
    return r;
}
