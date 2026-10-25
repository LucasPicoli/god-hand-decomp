/* include/godhand/cIDBaseScreen.h - the five-row ID display screen.
 *
 * Five cIDBase displays (rows) at 0x100 and two extra displays at 0x430/0x480.
 * Each row holds five entries, cached in tbl[row][n] by func_00144C90. The
 * screen shows a list of up to SCR_LIST_MAX items: their texture addresses,
 * their item ids, a second id table and an attribute byte each, loaded by
 * BlendSetup_load. Every frame func_00145238 runs the phase handler (opening,
 * open, pop-in, closing) and moves the rows.
 *
 * Offsets are exact; a field nobody names yet stays as unkNNN padding.
 */
#ifndef GODHAND_CIDBASESCREEN_H
#define GODHAND_CIDBASESCREEN_H

#include "godhand/cIDBase.h"
#include "godhand/cObjSimple.h"

#define SCR_ROW_NUM     5       /* rows, and entries cached per row */
#define SCR_LIST_MAX    0x23    /* list items the tables hold */

/* cIDBaseScreen.flags */
#define SCR_FLAG_SETUP  0x10000000  /* cleared once func_00145410 has set the rows up */
#define SCR_FLAG_SHOWN  0x20000000  /* cleared with SCR_FLAG_READY when the screen closes */
#define SCR_FLAG_READY  0x40000000  /* set by each table load */

/* cIDBaseScreen.attr[] bits */
#define SCR_ATTR_DIM    0x01        /* item drawn dimmed */

/* Store through a cast pointer, not a member access. A member store cannot alias the scalar
 * global D_003BD70C, so the scheduler lifts that load above it; retail keeps the load after
 * the stores, which only the cast form reproduces (cIDBaseScreen_init, ScrObj_reset). */
#define SCR_STORE(type, field, value)  (*(type *)&(field) = (value))

/* A display on a 0x50 stride. */
typedef struct cIDBaseScreenRow {
    cIDBaseObj id;                      /* 0x00 */
    char pad48[0x50 - sizeof(cIDBaseObj)];
} cIDBaseScreenRow;

typedef struct cIDBaseScreen {
    char unk000[0x90];
    unsigned int flags;                 /* 0x090 SCR_FLAG_* */
    cIDBaseEnt *tbl[SCR_ROW_NUM][SCR_ROW_NUM]; /* 0x094 entry n of row r */
    char unk0F8[8];
    cIDBaseScreenRow row[SCR_ROW_NUM];  /* 0x100 */
    cObjSimpleVec3 pos;                 /* 0x290 screen origin */
    char unk29C[8];
    float unk2A4;                       /* 0x2A4 the draw shows the rows in another order above 1.0 */
    void *tex[SCR_LIST_MAX];            /* 0x2A8 texture address of each item */
    short texNum;                       /* 0x334 */
    char unk336[2];
    float scale;                        /* 0x338 animation scale of the current phase */
    float rowY[SCR_ROW_NUM];            /* 0x33C */
    float rowX[SCR_ROW_NUM];            /* 0x350 */
    unsigned int color0;                /* 0x364 */
    unsigned int color1;                /* 0x368 */
    short item[SCR_LIST_MAX];           /* 0x36C item id of each list entry */
    short listNum;                      /* 0x3B2 entries in item/item2/attr */
    short item2[SCR_LIST_MAX];          /* 0x3B4 */
    unsigned char attr[SCR_LIST_MAX];   /* 0x3FA SCR_ATTR_* */
    char unk41D;
    short phase;                        /* 0x41E handler func_00145238 runs */
    short step;                         /* 0x420 step inside the phase */
    short cur;                          /* 0x422 list entry shown on the first row */
    char unk424[0xC];
    cIDBaseScreenRow extraA;            /* 0x430 */
    cIDBaseScreenRow extraB;            /* 0x480 */
    unsigned short timer;               /* 0x4D0 */
} cIDBaseScreen;

typedef char cIDBaseScreen_row_check[((int)&((cIDBaseScreen *)0)->row == 0x100) ? 1 : -1];
typedef char cIDBaseScreen_tex_check[((int)&((cIDBaseScreen *)0)->tex == 0x2A8) ? 1 : -1];
typedef char cIDBaseScreen_attr_check[((int)&((cIDBaseScreen *)0)->attr == 0x3FA) ? 1 : -1];
typedef char cIDBaseScreen_extraA_check[((int)&((cIDBaseScreen *)0)->extraA == 0x430) ? 1 : -1];
typedef char cIDBaseScreen_timer_check[((int)&((cIDBaseScreen *)0)->timer == 0x4D0) ? 1 : -1];

/* Base scale of the five rows' label entries. */
extern const float D_0041E880[SCR_ROW_NUM];
/* Tints (r, g, b, a) of the item entries: [0] a listed row, [1] the picked row. */
extern const float D_0041E840[4][4];
/* Start value of cIDBaseScreen.timer. */
extern short D_003BD70C;




#endif
