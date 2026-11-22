/* cygnus-2.96: ADX SJ header step: skip the 0x8001 header and its zero padding, otherwise hand the
 * chunk to the decoder. */
#include "godhand/criSj.h"
typedef struct {
    char f0;
    char st;
    char f2;
    signed char mode;
    void *sj;
    SjObj *in;
    SjObj *out;
    char pad10[4];
    SjChunk ck;
    char pad1C[0x34 - 0x1C];
    int f34;
    int f38;
    int f3C;
    int f40;
    char pad44[4];
    void (*cb)(void *);
    void *cbarg;
    char pad50[0x9C - 0x50];
    int f9C;
} AdxSjHdrHn;

extern int Obj33C8_GetShort_98(void *sj);
extern int Obj3270_GetVia4_Obj33C8_18_77E8(AdxSjHdrHn *hn);
extern int Obj3270_GetVia4_Obj33C8_10_77D0(AdxSjHdrHn *hn);
extern int func_003279A0(AdxSjHdrHn *hn);
extern int ADX_DecodeFooter(char *p, int len, short *out);
extern void SJ_SplitChunk(SjChunk *ck, int len, SjChunk *head, SjChunk *tail);
extern void ADXB_EntryData(void *sj, char *p, int len);
extern void func_0033D218(void *sj);

__attribute__((section(".text.adxsjd_decexec_start")))
void adxsjd_decexec_start(AdxSjHdrHn *hn)
{
    SjChunk tail;
    short h;
    void *sj = hn->sj;
    SjObj *in = hn->in;
    int ch;

    if (hn->f3C >= 0 && hn->f40 >= hn->f3C && hn->cb != 0)
        hn->cb(hn->cbarg);
    if (hn->mode == 1 && in->vt->getNumData(in, 1) == 0) {
        hn->st = 3;
        return;
    }
    in->vt->getChunk(in, 1, 0x7FFFFFFF, &hn->ck);
    if (Obj33C8_GetShort_98(sj) == 0 && hn->ck.len >= 4
        && (unsigned short)((*(unsigned short *)hn->ck.data << 8) | (unsigned char)hn->ck.data[1]) == 0x8001) {
        hn->st = 3;
        if (ADX_DecodeFooter(hn->ck.data, hn->ck.len, &h) == 0) {
            if (hn->ck.len < h) {
                in->vt->ungetChunk(in, 1, &hn->ck);
                return;
            }
            SJ_SplitChunk(&hn->ck, h, &hn->ck, &tail);
            in->vt->putChunk(in, 0, &hn->ck);
            in->vt->ungetChunk(in, 1, &tail);
        }
        if (hn->f9C == 0)
            return;
        {
            int n;
            int i;
            int found;

            while (in->vt->getChunk(in, 1, 0x7FFFFFFF, &hn->ck), (n = hn->ck.len) != 0) {
                for (i = 0; i < hn->ck.len && hn->ck.data[i] == 0; i++)
                    ;
                found = i < n;
                SJ_SplitChunk(&hn->ck, i, &hn->ck, &tail);
                in->vt->putChunk(in, 0, &hn->ck);
                in->vt->ungetChunk(in, 1, &tail);
                if (found)
                    return;
            }
        }
        return;
    }
    if (Obj3270_GetVia4_Obj33C8_18_77E8(hn) <= hn->f34) {
        ch = Obj33C8_GetShort_98(sj);
        if (ch != 1 || func_003279A0(hn) != ch) {
            hn->st = 3;
            in->vt->ungetChunk(in, 1, &hn->ck);
            return;
        }
    }
    ch = Obj3270_GetVia4_Obj33C8_10_77D0(hn);
    if (hn->out->vt->getNumData(hn->out, 0) / 2 < ch) {
        in->vt->ungetChunk(in, 1, &hn->ck);
        return;
    }
    if (Obj33C8_GetShort_98(sj) == 10)
        in->vt->ungetChunk(in, 1, &hn->ck);
    if (Obj33C8_GetShort_98(sj) == 15)
        in->vt->ungetChunk(in, 1, &hn->ck);
    ADXB_EntryData(sj, hn->ck.data, hn->ck.len);
    func_0033D218(sj);
}
