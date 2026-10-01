/* include/godhand/cBgmData.h - the sound manager's data records.
 *
 * cSnd keeps two kinds of loaded sound data. cSeData (0x40 bytes) is one
 * sound-effect bank: a state word, the bank id, and the image read from disc.
 * cBgmData (0x44 bytes) is the BGM table: a header with a table of 0x20-byte
 * entries, one per sequence. cSnd_GetBgmData(cSnd, n) returns record n.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding or fNN.
 * The BGM nodes themselves live in cSnd.h.
 */
#ifndef GODHAND_CBGMDATA_H
#define GODHAND_CBGMDATA_H

#define CSEDATA_STATE_FREE    0
#define CSEDATA_STATE_LOADING 1
#define CSEDATA_STATE_ALIVE   2
#define CSEDATA_STATE_FAILED  3

#define CBGMDATA_STATE_READY  0xF       /* cBgmData.state when fully loaded */
#define CBGM_TBL_UNUSED       0x80      /* cBgmTbl.type of an empty entry */
#define CBGM_HIT_ENT_MAX      0x100     /* hit table entry count is a ushort */

/* The image of a sound-effect bank as read from disc. */
typedef struct cSeBuf {
    char unk00[4];
    float version;              /* 0x04 1.1 */
    int f08;                    /* 0x08 */
    unsigned char relocated;    /* 0x0C pointers below already rebased */
    char unk0D[3];
    int f10;                    /* 0x10 */
    char unk14[4];
    int f18;                    /* 0x18 */
    char unk1C[4];
    int f20;                    /* 0x20 */
    int f24;                    /* 0x24 */
    int f28;                    /* 0x28 */
    int f2C;                    /* 0x2C */
    int f30;                    /* 0x30 */
} cSeBuf;

/* One sound-effect bank slot. */
typedef struct cSeData {
    int state;                  /* 0x00 CSEDATA_STATE_* */
    unsigned int flags;         /* 0x04 load progress bits */
    void *pool;                 /* 0x08 allocator the bank is read into */
    cSeBuf *head;               /* 0x0C */
    cSeBuf *buf;                /* 0x10 the bank image */
    int f14;                    /* 0x14 */
    int sysMem;                 /* 0x18 IOP memory, freed on release */
    int f1C;                    /* 0x1C */
    int f20;                    /* 0x20 */
    int f24;                    /* 0x24 */
    int f28;                    /* 0x28 */
    union {
        int bankId;             /* 0x2C */
        short bankIdS;          /* the sound driver takes it as a short */
    };
    int f30;                    /* 0x30 */
    int f34;                    /* 0x34 */
    int f38;                    /* 0x38 */
    int f3C;                    /* 0x3C */
} cSeData;                      /* 0x40 */

/* Header of a loaded BGM table. */
typedef struct cBgmHead {
    unsigned int tblNum;        /* 0x00 entries in the table */
    int tblOfs;                 /* 0x04 */
    int f08;                    /* 0x08 */
    unsigned char relocated;    /* 0x0C pointers already rebased */
} cBgmHead;

/* One entry of the BGM table. */
typedef struct cBgmTbl {
    char unk00[0xB];
    unsigned char type;         /* 0x0B CBGM_TBL_UNUSED = empty */
    char unk0C[5];
    unsigned char reqNo;        /* 0x11 */
    char unk12[0xE];
} cBgmTbl;                      /* 0x20 */

/* One BGM data record. */
typedef struct cBgmData {
    signed char loadMode;       /* 0x00 */
    signed char f01;            /* 0x01 */
    char unk02[2];
    int state;                  /* 0x04 bit flags, CBGMDATA_STATE_READY when loaded */
    void *pool;                 /* 0x08 allocator the data is read into */
    cBgmHead *head;             /* 0x0C */
    void *tbl;                  /* 0x10 */
    void *f14;                  /* 0x14 */
    int f18;                    /* 0x18 -1 = none */
    int f1C;                    /* 0x1C */
    int f20;                    /* 0x20 -1 = none */
    char name[0x20];            /* 0x24 */
} cBgmData;                     /* 0x44 */

/* One entry of the per-stage bgm table at D_003C3138, 0x18 bytes. */
typedef struct cBgmStageEnt {
    unsigned short id;          /* 0x00 stage id */
    unsigned short pad;
    int bgm[5];                 /* 0x04 bgm request per eBgmState */
} cBgmStageEnt;                 /* 0x18 */

/* One entry of the hit table. */
typedef struct cBgmHitEnt {
    char unk00[0x28];
    signed char id;             /* 0x28 */
    unsigned char flags;        /* 0x29 bit 0: hit flag set */
    char unk2A[0x42];
} cBgmHitEnt;                   /* 0x6C */

/* The hit table cSnd.hit points at. */
typedef struct cBgmHit {
    char unk00[4];
    float version;              /* 0x04 1.3 */
    unsigned short entNum;      /* 0x08 */
    char unk0A[2];
    float scale;                /* 0x0C */
    cBgmHitEnt ent[1];          /* 0x10 */
} cBgmHit;

#endif /* GODHAND_CBGMDATA_H */
