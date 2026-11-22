/* cygnus-2.96: sfmpv_InitFrmObj, initialises n 0xF0-byte stream slots, taking each slot's id from ids[]. */
#include "godhand/criStm.h"
extern void SFTIM_InitTtu(void *p, int a);
extern void sfmpv_InitPicAtr(void *p);

__attribute__((section(".text.sfmpv_InitFrmObj")))
void sfmpv_InitFrmObj(StmSlot *s, int *ids, int n)
{
    int *p;
    int cnt;

    if (n > 0) {
        p = ids;
        cnt = n;
        do {
            s->stat = 0;
            s->unk04 = 0;
            cnt--;
            SFTIM_InitTtu(s->lock, 0);
            s->id = *p++;
            s->unk38 = 0;
            s->unk3C = 1;
            s->unk40 = 0;
            s->unk44 = 0;
            s->unk48 = 0;
            s->unk4C = 0;
            s->unk50 = 0;
            s->owner = -1;
            sfmpv_InitPicAtr(s->que);
            s->unkE8 = 0;
            s++;
        } while (cnt != 0);
    }
}
