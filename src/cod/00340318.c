/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef int Sint32;
typedef unsigned char Uint8;

typedef struct {
    Uint8 *data;
    Sint32 len;
} SJCK;

struct _sj_obj;

struct _sj_vtbl {
    void (*QueryInterface)();
    void (*AddRef)();
    void (*Release)();
    void (*Destroy)();
    void *(*GetUuid)();
    void (*Reset)();
    void (*GetChunk)();
    void (*UngetChunk)();
    void (*PutChunk)(struct _sj_obj *, Sint32, SJCK *);
    Sint32 (*GetNumData)();
    Sint32 (*IsGetChunk)();
    void (*EntryErrFunc)();
};

typedef struct _sj_obj {
    struct _sj_vtbl *vtbl;
} SJ_OBJ, *SJ;

typedef struct dtr_obj {
    Sint8 used;
    Sint8 stat;
    Sint8 trnflg;
    Sint8 rsv;
    SJ sjsrc;
    SJ sjdst;
    SJCK cks;
    SJCK ckd;
    struct { unsigned int data; unsigned int addr; unsigned int size; unsigned int mode; } dma;
    Sint32 dma_id;
    Sint32 srclin;
    Sint32 dstlin;
    Sint32 blklen;
    Sint32 total_tbyte;
} DTR_OBJ, *DTR;

extern int SifDmaStat(Sint32 id);

__attribute__((section(".text.DTR_Stop")))
void DTR_Stop(DTR dtr)
{
    dtr->stat = 0;
    if (dtr->trnflg == 1) {
        while (SifDmaStat(dtr->dma_id) >= 0) {
        }
        dtr->sjsrc->vtbl->PutChunk(dtr->sjsrc, 0, &dtr->cks);
        dtr->cks.data = 0;
        dtr->cks.len = 0;
        dtr->sjdst->vtbl->PutChunk(dtr->sjdst, 1, &dtr->ckd);
        dtr->ckd.data = 0;
        dtr->trnflg = 0;
        dtr->ckd.len = 0;
        dtr->total_tbyte += dtr->cks.len;
    }
}
