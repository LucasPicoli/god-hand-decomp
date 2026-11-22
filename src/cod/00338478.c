/* cygnus-2.96: once every channel's stream holds a full block, drain one block from each channel and
 * restart its decoder. */
#include "godhand/criSj.h"
typedef struct {
    char pad0[8];
    SjObj *sj;                  /* 0x08 */
} AdxSjCh;
typedef struct {
    char pad00[8];
    AdxSjCh *ch[2];               /* 0x08 */
    void *dec[2];               /* 0x10 */
    char pad18[0x2C - 0x18];
    int blk;                    /* 0x2C */
    char pad30[0x52 - 0x30];
    signed char nch;            /* 0x52 */
    char pad53[0x58 - 0x53];
    signed char stat;           /* 0x58 */
    char pad59[2];
    char f5B;                   /* 0x5B */
} AdxSjdView;

extern int func_00340128(void *dec);
extern void DTR_Start(void *dec);

__attribute__((section(".text.PS2RNA_ExecHndl")))
void PS2RNA_ExecHndl(AdxSjdView *o)
{
    SjChunk ck;
    int cnt;
    int i;
    SjObj *sj;

    if (o->stat != 1)
        return;
    cnt = 0;
    for (i = 0; i < o->nch; i++) {
        if (func_00340128(o->dec[i]) != 1) {
            sj = o->ch[i]->sj;
            if (sj->vt->getNumData(sj, 0) == o->blk)
                cnt++;
        }
    }
    if (cnt != o->nch)
        return;
    for (i = 0; i < o->nch; i++) {
        sj = o->ch[i]->sj;
        sj->vt->getChunk(sj, 0, 0x7FFFFFFF, &ck);
        o->ch[i]->sj->vt->putChunk(o->ch[i]->sj, 0, &ck);
        sj = o->ch[i]->sj;
        sj->vt->getChunk(sj, 0, 0x7FFFFFFF, &ck);
        if (ck.len != o->blk)
            for (;;)
                ;
        sj = o->ch[i]->sj;
        sj->vt->putChunk(sj, 0, &ck);
        o->f5B = 0;
        DTR_Start(o->dec[i]);
    }
}
