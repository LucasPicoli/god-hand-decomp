typedef struct MpvBlk {
    int w[11];
} MpvBlk;

typedef struct MpvWork {
    char buf[0x200];
    int size;
} MpvWork;

typedef struct MpvDec {
    int busy;
    int rate;
    int on;
    MpvBlk blk;
    MpvWork work;
} MpvDec;

typedef struct MpvSub {
    char pad0[0x3C];
    MpvBlk blk;
} MpvSub;

typedef struct MpvHn {
    char pad0[0xD30];
    MpvSub sub;
} MpvHn;

typedef struct MpvPara {
    void *src;
    int len;
    MpvWork *w;
} MpvPara;

extern MpvDec *sfmpv_GetHd(MpvHn *hn);
extern int MEM_Copy(MpvWork *w, void *src, int len);

__attribute__((section(".text.sfmpv_SetMpvHd")))
void sfmpv_SetMpvHd(MpvHn *hn, int rate, MpvPara *para)
{
    MpvDec *m;
    MpvSub *sub;
    int len;
    MpvWork *w;

    m = sfmpv_GetHd(hn);
    if (m == 0 || m->busy != 0)
        return;
    len = para->len;
    if (len > 0x200)
        len = 0x200;
    w = &m->work;
    w->size = len;
    sub = &hn->sub;
    MEM_Copy(w, para->src, len);
    if (rate == 0x3FFFF) {
        m->rate = 0;
        m->on = 0;
    } else {
        m->on = 1;
        m->rate = rate * 50;
    }
    m->blk = sub->blk;
    m->busy = 1;
}
