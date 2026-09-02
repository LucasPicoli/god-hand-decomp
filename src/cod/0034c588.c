/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef unsigned char Uint8;
typedef short Sint16;
typedef unsigned short Uint16;
typedef int Sint32;
typedef unsigned int Uint32;

typedef struct _sj_obj {
    struct _sj_vtbl *vtbl;
} SJ_OBJ, *SJ;

typedef struct {
    Uint8 *data;
    Sint32 len;
} SJCK;

struct _sj_vtbl {
    void (*QueryInterface)();
    void (*AddRef)();
    void (*Release)();
    void (*Destroy)();
    void *(*GetUuid)();
    void (*Reset)();
    void (*GetChunk)(SJ, Sint32, Sint32, SJCK *);
    void (*UngetChunk)(SJ, Sint32, SJCK *);
    void (*PutChunk)();
    Sint32 (*GetNumData)(SJ, Sint32);
    Sint32 (*IsGetChunk)();
    void (*EntryErrFunc)();
};

#define SJ_GetNumData(sj, t)        ((sj)->vtbl->GetNumData((sj), (t)))
#define SJ_GetChunk(sj, t, n, ck)   ((sj)->vtbl->GetChunk((sj), (t), (n), (ck)))
#define SJ_UngetChunk(sj, t, ck)    ((sj)->vtbl->UngetChunk((sj), (t), (ck)))

__attribute__((section(".text.sfbuf_PeekChunk")))
Sint32 sfbuf_PeekChunk(SJ sj, Sint32 type, SJCK *ck1, SJCK *ck2)
{
    Sint32 ndata;

    ndata = SJ_GetNumData(sj, type);
    SJ_GetChunk(sj, type, 0x7FFFFFFF, ck1);
    if (ck1->len < ndata) {
        SJ_GetChunk(sj, type, 0x7FFFFFFF, ck2);
        SJ_UngetChunk(sj, type, ck2);
    } else {
        ck2->data = 0;
        ck2->len = 0;
    }
    SJ_UngetChunk(sj, type, ck1);
    return ndata;
}
