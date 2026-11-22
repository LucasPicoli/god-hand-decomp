/* cygnus-2.96: ADX SJ decoder: consume one block from the input SJ and hand the decoded data to each
 * output SJ. */
#include "godhand/criSj.h"
struct AdxSjDecHn {
    int f0;
    void *f4;
    SjObj *f8;
    SjObj *fC[2];
    SjChunk f14;
    SjChunk f1C[2];
    int f2C, f30, f34, f38, f3C, f40, f44;
    char pad48[0x50 - 0x48];
    void (*f50)(void *, int, int, int);
    void *f54;
};

extern int Obj33C8_GetField_18(void *sj);
extern int func_0033D2B8(void *sj);
extern int func_0033D2C0(void *sj);
extern int Obj33C8_GetShort_98(void *sj);
extern int func_003279A0(struct AdxSjDecHn *hn);
extern int func_0033CE98(void *sj);
extern void ADXB_Reset(void *sj);
extern void SJ_SplitChunk(SjChunk *ck, int len, SjChunk *head, SjChunk *tail);

__attribute__((section(".text.adxsjd_decexec_end")))
void adxsjd_decexec_end(struct AdxSjDecHn *hn)
{
    SjChunk ck, tail;
    void *sj = hn->f4;
    SjObj *in = hn->f8;
    int a, b, c, n, ch;
    int i;
    SjObj **o;
    SjChunk *p;

    a = Obj33C8_GetField_18(sj);
    b = func_0033D2B8(sj);
    c = func_0033D2C0(sj);
    ch = Obj33C8_GetShort_98(sj);
    if (ch != 1 || func_003279A0(hn) != ch) {
        n = a - hn->f34;
        if (c >= n) c = n;
    }
    i = 0;
    SJ_SplitChunk(&hn->f14, b, &ck, &tail);
    in->vt->putChunk(in, 0, &ck);
    in->vt->ungetChunk(in, 1, &tail);
    o = hn->fC;
    p = hn->f1C;
    for (; i < func_0033CE98(hn->f4); i++) {
        SJ_SplitChunk(p, c * 2, &ck, &tail);
        if (hn->f50 != 0)
            hn->f50(hn->f54, i, (int)ck.data, ck.len);
        (*o)->vt->putChunk(*o, 1, &ck);
        p++;
        (*o)->vt->ungetChunk(*o, 0, &tail);
        o++;
    }
    hn->f2C += c;
    hn->f30 += b;
    hn->f34 += c;
    hn->f40 += c;
    hn->f44 += b;
    ADXB_Reset(sj);
}
