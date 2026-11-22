/* sn-2.95.3-136: SdeSsqHedOpen, registers a sound bank header in slot `bank` and posts command 6. */
#include "godhand/sndBank.h"
extern int func_003758E8(int cmd);

__attribute__((section(".text.SdeSsqHedOpen")))
void SdeSsqHedOpen(short bank, SndBankHdr *hdr, int sysMem, int size)
{
    SndBank *b;
    SndBankCmd *c;

    c = &D_0076A880;
    b = &D_0076EA50[bank];
    b->id = hdr->id;
    b->data = (char *)hdr + hdr->dataOfs;
    b->sysMem = sysMem;
    b->size = size;
    if (hdr->tblOfs == 0) {
        b->tbl = 0;
    } else {
        b->tbl = (char *)hdr + hdr->tblOfs;
    }
    b->num = hdr->num;
    if (hdr->tbl2Ofs == 0) {
        b->tbl2 = 0;
    } else {
        b->tbl2 = (char *)hdr + hdr->tbl2Ofs;
    }
    if (hdr->tbl3Ofs == 0) {
        b->tbl3 = 0;
    } else {
        b->tbl3 = (char *)hdr + hdr->tbl3Ofs;
    }
    c->bank = bank;
    c->id = b->id;
    c->data = b->data;
    c->sysMem = b->sysMem;
    c->size = b->size;
    c->tbl = b->tbl;
    c->num = b->num;
    c->tbl2 = b->tbl2;
    c->tbl3 = b->tbl3;
    func_003758E8(6);
}
