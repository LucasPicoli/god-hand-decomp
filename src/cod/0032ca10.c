/* cygnus-2.96 matched TU. */

#include "godhand/sfxlib.h"
#include "godhand/adxsjd.h"
#include "godhand/criFs.h"

extern int Obj0000_Get_D_003EE34C_35FC28(void);
extern char D_00459F60[];
extern int Obj3260_Tramp_003383B0_D358(void *rna);
extern int Obj3270_GetVia4_Obj33C8_10_77D0(void *sjd);
extern int Obj3260_GetByte_1_D778(void *sjd);
extern void Obj3260_Tramp_00338338_D338(void *rna, int a);
extern char D_003D9EE8[];
extern char D_004544F8[];
extern char D_00454510[];
extern char D_00454528[];
extern char D_00454540[];
extern void LogPrintf(char *fmt, ...);
extern void func_00333390(char *name, char *dir);
extern void PushGlobalD8478History_331C78(int id);
extern void func_003260C8(char *fmt, int a);

/* cygnus-2.96: func_0035F418, builds the frame info block and the output frame record for a picture
 * source, then calls the stream's frame callback. */


typedef struct SfdFrmSrc {
    unsigned int type;                  /* 0x00 */
    void *y_ptr;                        /* 0x04 */
    int y_height;                       /* 0x08 */
    int y_pitch;                        /* 0x0C */
    char pad10[0x34];
    int width;                          /* 0x44 */
} SfdFrmSrc;

typedef struct SfdFrmInf {
    unsigned int type;                  /* 0x00 */
    char *y_ptr;                        /* 0x04 */
    int y_width;                        /* 0x08 */
    int y_pitch;                        /* 0x0C */
    int y_height;                       /* 0x10 */
    char *u_ptr;                        /* 0x14 */
    int u_width;                        /* 0x18 */
    int u_pitch;                        /* 0x1C */
    int u_height;                       /* 0x20 */
    char *v_ptr;                        /* 0x24 */
    int v_width;                        /* 0x28 */
    int v_pitch;                        /* 0x2C */
    int v_height;                       /* 0x30 */
    char pad34[0x30];
} SfdFrmInf;

typedef struct FrmTim {
    int time;                           /* 0x00 */
    int rate;                           /* 0x04 */
    int pad8[6];
} FrmTim;

typedef struct FrmRec {
    int unk0;                           /* 0x00 */
    char *y_ptr;                        /* 0x04 */
    int y_height;                       /* 0x08 */
    int y_pitch;                        /* 0x0C */
    int stride;                         /* 0x10 */
    char pad14[0x5C];
} FrmRec;

typedef struct Sfx Sfx;
struct Sfx {
    char pad0[8];
    int pitch;                          /* 0x08 */
    char pad0C[0x38 - 0x0C];
    int time;                           /* 0x38 */
    char pad3C[0x6C - 0x3C];
    void (*cbfn)(SfdFrmInf *inf, FrmRec *frm, FrmTim *tim); /* 0x6C */
};

extern void func_0035F288(Sfx *sfx, void *src, SfdFrmInf *inf);



/* Pointer locals for the plane cursors are required: they make gcc form one address pseudo each. */
__attribute__((section(".text.func_0035F418")))
void func_0035F418(Sfx *sfx, SfdFrmSrc *src, SfdFrmSrc *frmsrc)
{
    SfdFrmInf inf;
    FrmRec frm;
    FrmTim tim;
    char **yp;
    char **up;
    char **vp;
    char **fp;
    int half;

    func_0035F288(sfx, src, &inf);
    yp = &inf.y_ptr;
    up = &inf.u_ptr;
    vp = &inf.v_ptr;
    fp = &frm.y_ptr;
    switch (src->type) {
    case 3:
        half = inf.y_height * inf.y_pitch / 2;
        *yp += half;
        *up += half / 2;
        *vp += half / 2;
        frm.y_height = frmsrc->y_height;
        frm.y_pitch = frmsrc->y_pitch;
        *fp = frmsrc->y_ptr;
        if (sfx->pitch != 0)
            frm.stride = sfx->pitch;
        else
            frm.stride = inf.y_width << 2;
        break;
    case 1:
    case 2:
        *fp = frmsrc->y_ptr;
        frm.y_height = frmsrc->y_height;
        frm.y_pitch = frmsrc->y_pitch;
        if (sfx->pitch == 0)
            frm.stride = inf.y_width << 2;
        else
            frm.stride = sfx->pitch;
        break;
    default:
        SFXLIB_Error(sfx, src, D_00459F60);
    }
    if (Obj0000_Get_D_003EE34C_35FC28() == 1)
        tim.time = sfx->time;
    else
        tim.time = 0;
    if (sfx->cbfn != 0)
        sfx->cbfn(&inf, &frm, &tim);
}

/* cygnus-2.96: func_0032CA10, per-frame step of an ADX decoder slot: while the RNA output has room
 * and the decoder is in state 3, restarts a stopped slot (state 3, input ready), then silences the
 * next block of every output stream joint. */


#define ADXSJD_STAT_PLAY    3
#define ADXSJD_MAX_FILL     0x2000








extern volatile int D_003C7418;   /* volatile keeps retail's separate lui+addiu address (plain int folds %lo into the lw) */

__attribute__((section(".text.func_0032CA10")))
void func_0032CA10(AdxSjdRun *run)
{
    SjChunk ck;
    SjObj *sj;
    void *rna = run->rna;
    void *sjd = run->sjd;
    int have = Obj3260_Tramp_003383B0_D358(rna);
    int need = func_00326370(rna);
    int lim = run->flush;
    int nsj;
    int bytes;
    int i;

    if (lim > ADXSJD_MAX_FILL)
        lim = ADXSJD_MAX_FILL;
    if (have < lim && Obj3270_GetVia4_Obj33C8_10_77D0(sjd) < need
        && Obj3260_GetByte_1_D778(run->sjd) != ADXSJD_STAT_PLAY)
        goto next;
    if (run->busy == 0) {
        if (run->stopReq == 0) {
            Obj3260_Tramp_00338338_D338(rna, 1);
            run->unk9C = 0;
            run->unkA0 = D_003C7418;
        }
        run->stat = ADXSJD_STAT_PLAY;
    }
    run->unk71 = 1;
next:
    if (Obj3260_GetByte_1_D778(run->sjd) != ADXSJD_STAT_PLAY)
        return;
    nsj = func_0032A5B8(run);
    bytes = run->flush * nsj * 2;
    for (i = 0; i < nsj; i++) {
        sj = run->sj[i];
        sj->vt->getChunk(sj, 0, bytes, &ck);
        func_003A52F0(ck.data, 0, ck.len);
        sj->vt->putChunk(sj, 1, &ck);
    }
}

/* cygnus-2.96: func_00333880, resolves every file named in a file-list table on the disc. Each hit
 * overwrites the entry's (lsn, size) pair; the history ring gets a progress code per step. Returns
 * the number resolved and reports the failures through the log. */


typedef struct FlLayout {
    char *tbl;                  /* 0x00 */
    int num;                    /* 0x04 */
    int nameBase;               /* 0x08 name block offset, in 8-byte units */
    int nameStride;             /* 0x0C name stride less 1 */
} FlLayout;

extern FlLayout D_003D9DC0;












__attribute__((section(".text.func_00333880")))
int func_00333880(char *tbl, int num)
{
    CriFileStat info;
    int fail = 0;
    int ok = 0;
    int i;
    char *name;

    for (i = 0; i < num; i++) {
        name = tbl + ((D_003D9DC0.nameBase << 3) + (D_003D9DC0.nameStride * i + i));
        if (name[0] == 0)
            continue;
        func_00333390(name, D_003D9EE8);
        PushGlobalD8478History_331C78(0x9400);
        while (func_00398DA0(1) == 1)
            ;
        PushGlobalD8478History_331C78(0x9401);
        PushGlobalD8478History_331C78(0x9500);
        if (func_00332838(&info, D_003D9EE8) == 1) {
            PushGlobalD8478History_331C78(0x9501);
            ok++;
            ((int *)tbl)[i * 2] = info.unk00;
            ((int *)tbl)[i * 2 + 1] = info.found;
            LogPrintf(D_004544F8, name);
        } else {
            PushGlobalD8478History_331C78(0x9502);
            fail++;
            LogPrintf(D_00454510, name);
        }
    }
    LogPrintf(D_00454528, ok);
    if (fail > 0)
        func_003260C8(D_00454540, 10);
    return ok;
}
