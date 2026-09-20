/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef signed char  Sint8;
typedef signed short Sint16;
typedef signed int   Sint32;

typedef struct {
    Sint8 *data;
    Sint32 len;
} SJCK;

typedef struct {
    Sint32 sid;
    char   fname[8];
    void  *dir;
    Sint32 ofst;
    Sint32 fsct;
    Sint32 stat;
    Sint32 rdsct;
} LSC_SINFO;

struct sj_obj;

typedef struct {
    void  *QueryInterface;
    void  *AddRef;
    void  *Release;
    void  *Destroy;
    void  *GetUuid;
    void  *Reset;
    void  *GetChunk;
    void  *UngetChunk;
    void  *PutChunk;
    Sint32 (*GetNumData)(struct sj_obj *sj, Sint32 flag);
    void  *IsGetChunk;
    void  *EntryErrFunc;
} SJ_IF;

typedef struct sj_obj {
    SJ_IF *vtbl;
} SJ_OBJ;

typedef struct {
    Sint8  used;
    Sint8  stat;
    Sint8  rdflg;
    Sint8  lpflg;
    Sint8  pause;
    Sint8  rsv1;
    Sint16 rsv2;
    SJ_OBJ *sj;
    SJCK   ck;
    Sint32 bufmin;
    Sint32 bsize;
    Sint32 wpos;
    Sint32 rpos;
    Sint32 nstm;
    void  *fp;
    Sint32 fsct;
    Sint32 reqsct;
    Sint32 errcnt;
    LSC_SINFO sinfo[16];
} LSC_OBJ;

extern void func_00335D40(char *msg);

extern void Forward33B658_335CE8(Sint32 *crs);
extern void Forward33B670_335D00(Sint32 *crs);
extern char D_00454BB8[];
extern char D_00454BE8[];

__attribute__((section(".text.func_003353F8")))
LSC_OBJ *func_003353F8(SJ_OBJ *sj)
{
    LSC_OBJ *lsc;
    Sint32 crs;
    Sint32 i;

    if (sj == 0) {
        func_00335D40(D_00454BB8);
        return 0;
    }
    Forward33B658_335CE8(&crs);
    lsc = (LSC_OBJ *)func_00335360();
    if (lsc == 0) {
        func_00335D40(D_00454BE8);
        goto unlock;
    }
    lsc->stat = 0;
    lsc->sj = sj;
    lsc->bsize = sj->vtbl->GetNumData(sj, 0) + sj->vtbl->GetNumData(sj, 1);
    lsc->bufmin = lsc->bsize * 8 / 10;
    for (i = 15; i >= 0; i--) {
        lsc->sinfo[i].stat = 0;
    }
    lsc->used = 1;
unlock:
    Forward33B670_335D00(&crs);
    return lsc;
}
