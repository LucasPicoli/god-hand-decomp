/* sn-2.95.3-136 matched TU. */

#include "godhand/cMessDrawFont.h"
#include "godhand/cIDBase.h"
#include "godhand/globals.h"

extern unsigned int cMessCommon_getCodeSize(unsigned int code);
extern int cMessCommon_isHighCodeEnd(unsigned short code);
extern int func_002B04C0(cMessDrawFont *self, unsigned short *text, float *arg);
extern float func_002B0BE0(cMessDrawFont *self, unsigned short *text, float *arg);
extern void Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(void *self);
extern void cIDManager_setIDData(void *mgr, int kind, int res);
extern void cIDBase_initialize(void *self, int kind, int arg);
extern void cIDBase_restartAnim(void *self);
extern void **D_003C2384;
extern float Curve_sample(void *a0, int a1, int a2, int a3);

/* Find the tallest glyph on a line: walk the codes until an end code, ask func_002B0BE0 for each code's height, and keep the largest in the running maximum; each new maximum also stores arg[0] scaled by charH and zoomY to *out. Returns the end-code position. */
__attribute__((section(".text.cMessDrawFont_measureLineHeight")))
unsigned short *cMessDrawFont_measureLineHeight(cMessDrawFont *self, unsigned short *text, float *arg, float *out)
{
    float best = 0.0f;
    float h;
    *out = best;
    goto test;
glyph:
    h = func_002B0BE0(self, text, arg);
    if (best < h) {
        best = h;
        *out = *arg * self->charH * self->zoomY;
    }
    text += cMessCommon_getCodeSize(*text);
test:
    if ((*text >> 15) == 0) {
        goto glyph;
    }
    func_002B04C0(self, text, arg);
    if (cMessCommon_isHighCodeEnd(*text) == 0) {
        goto glyph;
    }
    return text;
}

#define IDOBJ16_KIND       0x16
#define IDOBJ16_WORK_NUM   4
#define IDOBJ16_PLAYING    8
#define IDOBJ16_LINK_HIDE  0x08000000   /* flag cleared on the linked object */

typedef struct IdDispLink {
    char unk00[0x2C];
    unsigned int flags;                 /* 0x2C */
} IdDispLink;

typedef struct IdDispObj16 {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[8];
    int resHandle;                      /* 0x50 */
    char unk54[6];
    unsigned char variantCopy;          /* 0x5A */
    char unk5B[5];
    int state;                          /* 0x60 */
    unsigned char variant;              /* 0x64 */
    char unk65[0x1B];
    void *work[IDOBJ16_WORK_NUM];       /* 0x80 */
    char unk90;
    unsigned char clearByte;            /* 0x91 */
} IdDispObj16;

/* Constructor of the kind 0x16 display object: base setup, then (when its data table matches) the ID data and first animation, the four display works, and for variant 1 the copied variant byte and the hide flag cleared on the last work. */
__attribute__((section(".text.IdDispObj16_construct")))
void IdDispObj16_construct(IdDispObj16 *self)
{
    int i;
    Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(self);
    if (func_00161500(self, D_0041FC50) != 0) {
        cIDManager_setIDData(*D_003C2384, IDOBJ16_KIND, self->resHandle);
        cIDBase_initialize(self, IDOBJ16_KIND, 0);
        cIDBase_restartAnim(self);
        self->state = IDOBJ16_PLAYING;
    }
    for (i = 0; i < IDOBJ16_WORK_NUM; i++) {
        self->work[i] = cIDBase_getIDWork(&self->base, i);
    }
    if (self->variant == 1) {
        IdDispLink *link;
        self->variantCopy = self->variant;
        link = (IdDispLink *)self->work[3];
        link->flags &= ~IDOBJ16_LINK_HIDE;
    }
    self->clearByte = 0;
}

#define MOVE_SRC_HAS_CURVE   0x400000   /* src.flags: entry follows a curve */
#define MOVE_SRC_LOOP        0x20000    /* src.flags: restart the curve at the end */
#define MOVE_ENT_DONE        0x800      /* ent.flags: curve finished */
#define MOVE_ENT_HOLD        0x20       /* ent.flags: do not advance the frame */
#define MOVE_DEG_FULL        360.0f

typedef struct MoveCurveKey {
    short frames;                       /* 0x00 last frame of this key */
    char unk02[10];
} MoveCurveKey;

typedef struct MoveCurveSrc {
    char unk00[4];
    unsigned int flags;                 /* 0x04 */
    char unk08[0x57];
    signed char hold;                   /* 0x5F nonzero: not moved */
    char unk60[0x1B4];
    short keyNum;                       /* 0x214 */
    char unk216[0xA];
    MoveCurveKey key[1];                /* 0x220 */
} MoveCurveSrc;

typedef struct MoveCurveEnt {
    char unk00[0xC];
    int curveArg;                       /* 0x0C */
    char unk10[0xC];
    MoveCurveSrc *src;                  /* 0x1C */
    char unk20[0xC];
    unsigned int flags;                 /* 0x2C */
    char unk30[0x18];
    float rotSpeed;                     /* 0x48 */
    char unk4C[0x58];
    short frame;                        /* 0xA4 */
    unsigned short step;                /* 0xA6 */
} MoveCurveEnt;

/* Step an entry's curve-driven rotation: skip when held or finished, wrap or finish at the last key frame, sample the curve at the current frame into rotSpeed (as degrees) and advance the step counter unless held. */
__attribute__((section(".text.IdEnt_stepCurveRotation")))
void IdEnt_stepCurveRotation(void *curves, MoveCurveEnt *ent)
{
    MoveCurveSrc *src = ent->src;
    unsigned int flags = src->flags;
    unsigned int m;
    int n;
    int last;
    float t;
    unsigned long bits;
    if ((flags & MOVE_SRC_HAS_CURVE) == 0) {
        return;
    }
    m = ent->flags;
    if (m & MOVE_ENT_DONE) {
        return;
    }
    if (src->hold != 0) {
        return;
    }
    n = src->keyNum;
    last = src->key[n - 1].frames;
    if ((flags & MOVE_SRC_LOOP) != 0) {
        if (last < (unsigned short)ent->frame) {
            ent->frame = 0;
        }
    } else {
        if (last < (unsigned short)ent->frame) {
            ent->flags = m | MOVE_ENT_DONE;
            return;
        }
    }
    t = Curve_sample(curves, ent->frame, n, ent->curveArg);
    ent->rotSpeed = t * MOVE_DEG_FULL;
    bits = ent->flags;
    if (((bits >> 5) & 1) == 0) {
        ent->step = ent->step + 1;
    }
}
