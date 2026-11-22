/* cygnus-2.96: work out how many ADX blocks to decode this pass and dispatch to the stereo, extended
 * or mono expander. */

typedef struct AdxbIn {
    int unk0;
    int nbyte;      /* 0x04 */
    int nch;        /* 0x08 */
    int unkC;
    int blk;        /* 0x10 */
    int unk14;
    int end;        /* 0x18 */
    int unk1C;
    int pos;        /* 0x20 */
    int room;       /* 0x24 */
    int wpos;       /* 0x28 */
} AdxbIn;

typedef struct AdxbHn {
    char unk0[0x48];
    AdxbIn in;      /* 0x48 */
    char unk74[0x74];
    int ext;        /* 0xE8 */
} AdxbHn;

extern void ADXB_EvokeExpandSte(AdxbHn *adxb, int nblk);
extern int ADXB_EvokeExpandPl2(int a0, int a1);
extern int ADXB_EvokeExpandMono(int *a0, int a1);

__attribute__((section(".text.ADXB_EvokeDecode")))
void ADXB_EvokeDecode(AdxbHn *b)
{
    AdxbIn *in = &b->in;
    int nch = in->nch;
    int blk, end, pos, wpos, room;
    int full, len;
    int nin, nout, nend, nroom, tail;

    nin = in->nbyte / nch;
    end = in->end;
    pos = in->pos;
    blk = in->blk;
    wpos = in->wpos;
    nend = (end - pos + blk - 1) / blk;
    nout = (wpos + blk - 1) / blk;
    room = in->room;
    tail = blk - (wpos + blk - 1) % blk - 1;
    full = wpos < room;
    len = nend * blk;
    if (nout < nend)
        nend += pos + len - tail < end;
    room += full * tail;
    nroom = room / blk;
    if (nroom < nin)
        nin = nroom;
    if (nout < nin)
        nin = nout;
    if (nend < nin)
        nin = nend;
    if (nch == 2) {
        ADXB_EvokeExpandSte(b, nin);
        return;
    }
    if (b->ext != 0) {
        ADXB_EvokeExpandPl2((int)b, nin);
        return;
    }
    ADXB_EvokeExpandMono((int *)b, nin);
}
