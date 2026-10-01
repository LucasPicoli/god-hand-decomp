/* include/godhand/cWorldLight.h - the world lighting object.
 *
 * cWorldLight holds the lights of one stage: up to 256 light records of
 * 0x70 bytes starting at +0x80, a live count at +0x78, and a second block
 * of 0x30 small records at +0x7080. A far sub-block starting at +0x15D00 (presets, slots, area tables)
 * holds the fade and fog state. A free light slot has state 0xFF.
 *
 * Method names are the game's own, from the retail symbol table. Field
 * names are ours, taken from the methods that read and write them. Offsets
 * are exact: every body that uses this header builds byte-identical to
 * retail. A field we cannot name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CWORLDLIGHT_H
#define GODHAND_CWORLDLIGHT_H

#define WORLDLIGHT_LIGHT_NUM   256
#define WORLDLIGHT_LIGHT_FREE  0xFF      /* state of an unused slot */
#define WORLDLIGHT_EXTRA_NUM   0x30
#define WORLDLIGHT_PRESET_NUM  8

/* cWorldLight.flags */
#define WORLDLIGHT_FLAG_FADING   0x10    /* a fade is running */
#define WORLDLIGHT_FLAG_FADED    0x20    /* last fade finished */

typedef struct cWorldLightRec {
    unsigned short state;               /* 0x00 0xFF = free */
    unsigned short id;                  /* 0x02 */
    int unk04;
    int unk08[2];
    float v10[4];                       /* 0x10 */
    float v20[4];                       /* 0x20 */
    float v30[4];                       /* 0x30 */
    float f40;
    float f44;
    float f48;
    int ownerIdx;                       /* 0x4C index into the owner's list */
    int ownerUse;                       /* 0x50 nonzero: key comes from the owner */
    int key;                            /* 0x54 owner key */
    unsigned int flags;                 /* 0x58 */
    unsigned short f5C;
    unsigned short f5E;
    unsigned char f60;
    unsigned char f61;
    unsigned short f62;
    int unk64[3];
} __attribute__((aligned(16))) cWorldLightRec; /* 0x70 */

/* Byte blobs that the game copies as plain structs (unaligned word moves). */
typedef struct { char b[4]; } cWorldLightBlob4;

/* First 16 bytes of the object: sky colour, then settings copied as words. */
typedef union cWorldLightHead {
    cWorldLightBlob4 w[4];
    unsigned char b[16];                /* b[0..2] = sky colour r, g, b */
} cWorldLightHead;

/* The object the lights are attached to (returned by
 * Obj0000_Get_D_00747A94_2DB6B0): a list of owner handles. */
typedef struct cWorldLightOwner {
    char unk00[0x278];
    int *list;                          /* 0x278 owner keys */
    char unk27C[0x38];
    unsigned char listNum;              /* 0x2B4 */
} cWorldLightOwner;

/* Table behind cWorldLight.unk16130: a count, then 0x50-byte entries. */
typedef struct cWorldLightTblEnt {
    char unk00[2];
    unsigned char id;                   /* 0x02 */
    char unk03;
    float value;                        /* 0x04 */
    char unk08[0x48];
} cWorldLightTblEnt;                    /* 0x50 */

typedef struct cWorldLightTbl {
    unsigned int num;                   /* 0x00 */
    char unk04[0xC];
    cWorldLightTblEnt ent[1];           /* 0x10 */
} cWorldLightTbl;

/* A slot table: 16-byte rows. Row 0 word 0 is the row count; the lookup
 * compares row k + 1 word 0 and returns row k word 1. */
typedef struct cWorldLightRow {
    int w[4];
} cWorldLightRow;

typedef struct cWorldLightSlot {
    cWorldLightRow row[1];
} cWorldLightSlot;

typedef struct cWorldLightExtra {
    int w[5];
} cWorldLightExtra;                     /* 0x14 */

/* One stage light preset (table D_0061A400, 0x80 bytes each). It holds the
 * same settings as the first 0x78 bytes of cWorldLight, packed differently,
 * plus a pointer to its own light array. */
typedef struct cWorldLightPreset {
    float v30[3];                       /* 0x00 */
    float pad0C;
    float ambient[3];                   /* 0x10 */
    float pad1C;
    float v50[3];                       /* 0x20 */
    float pad2C;
    cWorldLightHead head;               /* 0x30 sky colour in head.b[0..2] */
    float f10[6];                       /* 0x40 */
    cWorldLightBlob4 b60;               /* 0x58 */
    float f64;                          /* 0x5C */
    float f68;                          /* 0x60 */
    cWorldLightBlob4 b6C;               /* 0x64 */
    float f70;                          /* 0x68 */
    float f74;                          /* 0x6C */
    int lightNum;                       /* 0x70 */
    cWorldLightRec *lights;             /* 0x74 */
    char pad78[8];
} cWorldLightPreset;                    /* 0x80 */

typedef struct cWorldLight {
    cWorldLightHead head;               /* 0x00 */
    float f10[6];                       /* 0x10 */
    char pad28[8];
    float v30[4];                       /* 0x30 */
    float ambient[4];                   /* 0x40 rgb */
    float v50[4];                       /* 0x50 */
    cWorldLightBlob4 b60;
    float f64;
    float f68;
    cWorldLightBlob4 b6C;
    float f70;
    float f74;
    int lightNum;                       /* 0x078 live records in light[] */
    int unk7C;
    cWorldLightRec light[WORLDLIGHT_LIGHT_NUM]; /* 0x080 */
    cWorldLightExtra extra[WORLDLIGHT_EXTRA_NUM]; /* 0x7080 */
    int extraNum;                       /* 0x7440 */
    char unk7444[0xE8A0 - 0x7444];
    char backup[0x7444];                /* 0xE8A0 copy of 0x00..0x7443 */
    char unk15CE4[0x15D00 - 0x15CE4];
    cWorldLightPreset preset[WORLDLIGHT_PRESET_NUM]; /* 0x15D00 table D_0061A400 */
    cWorldLightSlot *slot[8];           /* 0x16100 one per preset */
    cWorldLightTbl *areaTbl;            /* 0x16120 area check table */
    int areaId;                         /* 0x16124 */
    int areaIdPrev;                     /* 0x16128 */
    int areaIdx;                        /* 0x1612C */
    cWorldLightTbl *tbl;                /* 0x16130 */
    int unk16134;
    int unk16138;
    int unk1613C;
    int unk16140;
    int unk16144;
    int unk16148;
    int unk1614C;
    float fogNear;                      /* 0x16150 */
    float fogFar;                       /* 0x16154 */
    float fogColor[3];                  /* 0x16158 r, g, b in 0..255 */
    char unk16164[4];
    unsigned char fadeSlot;             /* 0x16168 preset index being faded to */
    char unk16169[3];
    float fadeT;                        /* 0x1616C 1.0 once the fade is done */
    signed char gaibuFrames;            /* 0x16170 outside-light countdown */
    char unk16171[0x161A0 - 0x16171];
    float lightDir[3][4];               /* 0x161A0 three light directions */
    float lightCol[3][4];               /* 0x161D0 their colours */
    char unk16200[0x16280 - 0x16200];
    short fadeFrame;                    /* 0x16280 */
    short fadeFrames;                   /* 0x16282 length of the fade */
    unsigned int flags;                 /* 0x16284 */
    int unk16288;
} cWorldLight;

/* Offset of a field from the start of cWorldLight. Fields past 0x10000 are
 * written as a 0x10000 base plus the rest where retail forms the base once. */
#define WORLDLIGHT_OFFSET(field) ((int)&((cWorldLight *)0)->field)
#define WORLDLIGHT_FAR_BASE      0x10000

/* Access a field as a bare `T` at its offset. Retail's scheduler treats
 * such an access differently from a struct member access; use it only where
 * the typed spelling changes the emitted order. */
#define WORLDLIGHT_FAR_FIELD(far, T, field) \
    (*(T *)((char *)(far) + (WORLDLIGHT_OFFSET(field) - WORLDLIGHT_FAR_BASE)))
#define WORLDLIGHT_RAW(self, T, field) \
    (*(T *)((char *)(self) + WORLDLIGHT_OFFSET(field)))

#endif
