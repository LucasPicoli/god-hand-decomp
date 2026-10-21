/* include/godhand/sfxlib.h - the SFX library stream context (0x35E8.. cygnus code).
 *
 * Field names are ours; offsets are exact. Only the words this code
 * bodies touch are named.
 */
#ifndef GODHAND_SFXLIB_H
#define GODHAND_SFXLIB_H

#include "godhand/criSj.h"

/* Stream context. */
typedef struct {
    char pad0[0x24];
    int unk24;
    char pad28[0x8];
    int unk30;                  /* 0x30 handle */
    int unk34;                  /* 0x34 mode */
    void *unk38;
    char pad3C[0x34];
    void (*unk70)(void *);      /* 0x70 callback */
} SfxCtx;

typedef struct {
    char pad0[0x44];
    int unk44;
    int unk48;
    int unk4C;
} SfxCtxArg;

/* Stream type id at 0x4 (0x11..0x1001). */
typedef struct { char pad0[0x4]; int unk4; } SfxTypeView;
typedef struct { char pad0[0x90]; int unk90; int unk94; } SfxModeView;

/* Stream type/rate view of the stream context (type is SfxTypeView.unk4). */
typedef struct SfxStm {
    int unk0;
    int type;                   /* 0x04 */
    int rate;                   /* 0x08 */
    char unk0C[0x50 - 0x0C];
    int f50;                    /* 0x50 */
} SfxStm;

/* Source info: kind, sample rate and data size. */
typedef struct SfxInf {
    int kind;                   /* 0x00 */
    char unk04[0x44 - 0x04];
    int rate;                   /* 0x44 */
    int size;                   /* 0x48 */
} SfxInf;

typedef struct SfxEnt {
    int val;                    /* 0x00 */
    int rate;                   /* 0x04 */
    int size;                   /* 0x08 */
    int outRate;                /* 0x0C */
} SfxEnt;

typedef struct SfxTbl {
    int valid;                  /* 0x00 */
    SfxEnt ent[1];              /* 0x04 */
} SfxTbl;

extern void SFXLIB_Error(void *a, void *b, void *s);
extern int func_0035EBB0(void *a, void *b, int mode);
extern void func_0035EDE0(unsigned char *t);

/* ZMV tag search state: the input chunk and the header and frame chunks found in it. */
typedef struct SfxZmvTagState {
    char unk00[0x08];
    SjTagRec input;             /* 0x08 */
    char unk14[0x04];
    SjTagRec header;            /* 0x18 */
    char unk24[0x04];
    SjTagRec frame;             /* 0x28 */
} SfxZmvTagState;

#define SFXZMV_TAG_SET  1       /* SjTagRec.set once the search ran */

#endif
