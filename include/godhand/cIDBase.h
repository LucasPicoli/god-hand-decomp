/* include/godhand/cIDBase.h - the on-screen message and icon display object.
 *
 * cIDBase owns a table of display entries (cIDBaseEnt, 0xAC bytes each,
 * `ent`/`entNum`), built from a packed resource: an array of 0x2E0-byte
 * source records (cIDBaseSrc) found through D_003C2384. Each entry is one
 * sprite, text line, panel or icon. move() advances every entry each frame
 * and trans() draws them layer by layer, from layer 4 down to -4.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we cannot name yet stays as unkNN padding. The object
 * has no size check, its total size is not known.
 */
#ifndef GODHAND_CIDBASE_H
#define GODHAND_CIDBASE_H

#define IDBASE_ENT_SIZE     0xAC    /* sizeof(cIDBaseEnt) */
#define IDBASE_SRC_SIZE     0x2E0   /* sizeof(cIDBaseSrc) */
#define IDBASE_FRAME_MAX    0x2710  /* frame counter wraps to 0 here */
#define IDBASE_RAND_MAX     0x270F  /* random jitter values are 0..this */
#define IDBASE_LAYER_MAX    4       /* trans() draws layers 4 down to -4 */

/* Byte offset of a cIDBase field, for the few bodies that only match when
 * the access is a raw cast and not a struct member access. */
#define IDBASE_OFFSET(field) ((int)&((cIDBaseObj *)0)->field)

/* cIDBaseEnt.flags */
#define IDENT_FLAG_MSG_SENT  0x00000002  /* completion message already posted */
#define IDENT_FLAG_TEXT_OPT  0x00000004  /* text entries: passed to func_002ACC28 as its option */
#define IDENT_FLAG_CHILD     0x00000008  /* trans() tests the parents' NO_DRAW only when this is set on them */
#define IDENT_FLAG_KIND_PAR  0x00000010  /* on a parent: its kind is copied to the children */
#define IDENT_FLAG_OWN_ROT   0x00000080  /* ignore the parents' rotation speed */
#define IDENT_FLAG_RAND      0x00000040  /* randomise jitter in resetAnim */
#define IDENT_FLAG_RAND_BIT  6           /* bit number of IDENT_FLAG_RAND */
#define IDENT_FLAG_ANIM_ON   0x00004000  /* cleared when the animation restarts */
#define IDENT_FLAG_SRC_SKIP  0x00000200  /* source record is not used (src flags) */
#define IDENT_FLAG_OFF_PAR   0x04000000  /* offset is scaled by the accumulated parent scale */
#define IDENT_FLAG_NO_TINT   0x10000000  /* skip the parent colour tint */
#define IDENT_FLAG_NO_DRAW   0x08000000
#define IDENT_FLAG_HIDDEN    0x20000000  /* set by setDispFamily */
#define IDENT_FLAG_ACTIVE    0x80000000  /* entry is in use */
#define IDENT_FLAG_SCL_PAR   0x40000000  /* draw scale is multiplied by the parent's */

/* cIDBaseEnt.kind: which draw routine trans() calls */
#define IDENT_KIND_SPRITE    1
#define IDENT_KIND_TEXT      2
#define IDENT_KIND_PANEL     3
#define IDENT_KIND_ICON      4

typedef union cIDColor {
    unsigned int word;
    unsigned char c[4];         /* r, g, b, a */
} cIDColor;

/* Scratch sprite-draw state that trans() builds once per frame (initialised
 * by cScrSpriteDraw_drawInit) and passes to the sprite draw methods. */
typedef struct cIDBaseDraw {
    char unk00[0x28];
    int colorNo;                /* 0x28 colour table index */
    int fontNo;                 /* 0x2C */
    short unk30;                /* 0x30 cleared by trans() */
    char unk32[0xE];
} cIDBaseDraw;                  /* 0x40 */

typedef struct cIDBaseEnt cIDBaseEnt;
typedef struct cIDBaseSrc cIDBaseSrc;

/* One source record, 0x2E0 bytes. Offsets that the methods read are named. */
struct cIDBaseSrc {
    char unk00;
    unsigned char b01;          /* 0x01 */
    signed char parentRef;      /* 0x02 */
    signed char id;             /* 0x03 */
    unsigned int flags;         /* 0x04 */
    float posX;                 /* 0x08 */
    float posY;                 /* 0x0C */
    char unk10[4];
    float f14;                  /* 0x14 */
    float f18;                  /* 0x18 */
    char unk1C[8];
    float rotSpeed;             /* 0x24 */
    float sclX;                 /* 0x28 */
    float sclY;                 /* 0x2C */
    char unk30[0x10];
    float f40[4];               /* 0x40 */
    unsigned int colorBase;     /* 0x50 */
    unsigned char b54;          /* 0x54 */
    unsigned char b55;          /* 0x55 */
    unsigned char b56;          /* 0x56 */
    char unk57;
    unsigned char b58;          /* 0x58 */
    signed char layer;          /* 0x59 */
    unsigned short h5A;         /* 0x5A */
    char unk5C[4];
    float f60;                  /* 0x60 */
    char unk64;
    signed char b65;            /* 0x65 */
    unsigned char kind;         /* 0x66 */
    char unk67[9];
    char partB[0xC0];           /* 0x70 */
    char partA[0x84];           /* 0x130 */
    char partC[0x64];           /* 0x1B4 */
    char partD[0x64];           /* 0x218 */
    char partE[0x64];           /* 0x27C */
};                              /* 0x2E0 */

/* One display entry. */
struct cIDBaseEnt {
    void *part[5];              /* 0x00 pointers into the source record: partA, B, C, D, E */
    char unk14[8];
    cIDBaseSrc *src;            /* 0x1C record this entry came from */
    cIDBaseEnt *parent;         /* 0x20 entry this one hangs off, or 0 */
    void *tex;                  /* 0x24 texture address, 0 = not loaded yet */
    unsigned char b28;          /* 0x28 */
    signed char parentRef;      /* 0x29 >= 0: follows its parent */
    signed char id;             /* 0x2A id looked up by getIDWork */
    signed char layer;          /* 0x2B draw layer, -4..4 */
    unsigned int flags;         /* 0x2C IDENT_FLAG_* */
    float offX;                 /* 0x30 */
    float offY;                 /* 0x34 */
    float posX;                 /* 0x38 */
    float posY;                 /* 0x3C */
    float sclX;                 /* 0x40 base scale */
    float sclY;                 /* 0x44 */
    float rotSpeed;             /* 0x48 */
    cIDColor colorBase;         /* 0x4C */
    float drawX;                /* 0x50 final position */
    float drawY;                /* 0x54 */
    float drawSclX;             /* 0x58 final scale */
    float drawSclY;             /* 0x5C */
    float drawRot;              /* 0x60 */
    cIDColor color;             /* 0x64 rgba after the parent tint */
    float f68;                  /* 0x68 */
    float f6C;                  /* 0x6C */
    float f70[4];               /* 0x70 */
    float f80;                  /* 0x80 */
    unsigned int seed;          /* 0x84 */
    unsigned char kind;         /* 0x88 IDENT_KIND_* */
    unsigned char b89;          /* 0x89 */
    unsigned char b8A;          /* 0x8A */
    unsigned char b8B;          /* 0x8B */
    signed char b8C;            /* 0x8C */
    unsigned char b8D;          /* 0x8D */
    short h8E;                  /* 0x8E */
    unsigned short msg;         /* 0x90 message id, 0xFFFF = none */
    char unk92[2];
    float rotX;                 /* 0x94 */
    float rotY;                 /* 0x98 */
    char unk9C[4];
    short jit[5];               /* 0xA0 random jitter, see resetAnim */
    char unkAA[2];
};                              /* 0xAC */

/* The display object. */
typedef struct cIDBase {
    cIDBaseSrc *src;            /* 0x00 packed source records */
    cIDBaseEnt *ent;            /* 0x04 entry table, 0 before setWorkFromData */
    void *packed;               /* 0x08 packed message data */
    int entNum;                 /* 0x0C */
    int id;                     /* 0x10 */
    int resNo;                  /* 0x14 */
    unsigned char stop;         /* 0x18 nonzero: move() does nothing */
    unsigned char hide;         /* 0x19 nonzero: trans() draws nothing */
    unsigned short frame;       /* 0x1A counts up to IDBASE_FRAME_MAX */
    unsigned char playing;      /* 0x1C */
    unsigned char b1D;
    unsigned char b1E;
    char unk1F;
    float vecA[4];              /* 0x20 cleared by the constructor, set from D_003BD880 */
    float vecB[4];              /* 0x30 same */
    float f40;                  /* 0x40 starts at 0.01 */
    short h44;                  /* 0x44 starts at 0x80 */
    unsigned char mode;         /* 0x46 starts at 6: draw with the entry's own colour number */
} cIDBaseObj;

typedef char cIDBaseEnt_size_check[sizeof(cIDBaseEnt) == IDBASE_ENT_SIZE ? 1 : -1];
typedef char cIDBaseSrc_size_check[sizeof(cIDBaseSrc) == IDBASE_SRC_SIZE ? 1 : -1];
typedef char cIDBaseDraw_size_check[sizeof(cIDBaseDraw) == 0x40 ? 1 : -1];

#endif
