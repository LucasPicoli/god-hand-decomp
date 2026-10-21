/* include/godhand/criStm.h - CRI stream handle pool (cygnus code at 0x336E88..).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CRISTM_H
#define GODHAND_CRISTM_H

typedef struct StmObjVtbl {
    void *unk00[3];
    void (*destroy)(void *obj);                     /* 0x0C */
    void *unk10[4];
    void (*setBuf)(void *obj, int idx, void *desc); /* 0x20 */
} StmObjVtbl;

typedef struct StmObj {
    StmObjVtbl *vt;
} StmObj;

typedef struct StmEnt {
    char used;                  /* 0x00 */
    void *f4;                   /* 0x04 */
    StmObj *obj;                /* 0x08 */
    void *sjx;                  /* 0x0C */
    char *buf;                  /* 0x10 */
    int bufSize;                /* 0x14 */
} StmEnt;

/* One 0xF0-byte stream slot of the stream manager (set up by func_00354A70). */
typedef struct StmSlot {
    int stat;                   /* 0x00 2 or 4 when it can be attached */
    int unk04;                  /* 0x04 */
    int id;                     /* 0x08 */
    char lock[0x38 - 0x0C];     /* 0x0C */
    int unk38;                  /* 0x38 */
    int unk3C;                  /* 0x3C */
    int unk40;                  /* 0x40 */
    int unk44;                  /* 0x44 */
    int unk48;                  /* 0x48 */
    int unk4C;                  /* 0x4C */
    int unk50;                  /* 0x50 */
    int unk54;
    int owner;                  /* 0x58 -1 while unattached */
    char que[0xE8 - 0x5C];      /* 0x5C */
    int unkE8;                  /* 0xE8 */
    int unkEC;
} StmSlot;

typedef struct StmMgr {
    char unk000[0x178];
    int num;                    /* 0x178 */
    int unk17C;
    StmSlot slot[1];            /* 0x180 */
} StmMgr;

/* An opened stream buffer. */
typedef struct StmBuf {
    char unk00[0x14];
    int start;                  /* 0x14 */
    int size;                   /* 0x18 */
} StmBuf;

typedef struct StmRange {
    char unk000[0x27C];
    int start;                  /* 0x27C */
    int size;                   /* 0x280 */
} StmRange;

/* The stream system the slots belong to. */
typedef struct StmSys {
    char unk0000[0x58];
    int mode;                   /* 0x58 */
    char unk005C[0xD30 - 0x5C];
    StmRange range;             /* 0xD30 */
    char unkFB4[0x16B0 - 0xFB4];
    char ent[1][0x88];          /* 0x16B0 one record per slot */
    char unk1738[0x1FC0 - 0x1738];
    StmMgr *mgr;                /* 0x1FC0 */
} StmSys;

/* The stream reader a player owns; destroy is vtable slot 3. */
typedef struct StmRd StmRd;

typedef struct StmRdVtbl {
    void *unk00[3];
    void (*destroy)(StmRd *rd); /* 0x0C */
} StmRdVtbl;

struct StmRd {
    StmRdVtbl *vt;
};

/* A stream player (cygnus code at 0x329E08..0x32E150). */
typedef struct StmPly {
    char unk00;
    unsigned char stat;         /* 0x01 1..3 while it runs */
    signed char kind;           /* 0x02 */
    char unk03;
    void *dec;                  /* 0x04 the decoder */
    char unk08[4];
    void *sj;                   /* 0x0C */
    char unk10[4];
    StmRd *rd;                  /* 0x14 */
    char unk18[0x74 - 0x18];
    void *buf;                  /* 0x74 */
    char unk78[0xAC - 0x78];
    char eos;                   /* 0xAC */
} StmPly;

extern int D_003E0708;          /* pool entry count */
extern int D_003E070C;          /* heap size */
extern int D_003E0710;          /* config flag */

#define CRISTM_POOL_CONFIGURED  1       /* D_003E0710 once the pool is set up */
#define PS2RNA_BITS_PER_SAMPLE  16      /* the only sample width PS2RNA plays */
extern void *D_003E0714;        /* IOP heap block */
extern char *D_003E0718;        /* aligned heap base */
extern char D_003E071C;         /* heap owned */
extern StmEnt D_003E0768[];

/* printf-style logger. */
extern void func_003260C8(const char *fmt, ...);
/* memset; callers depend on the void * return. */
extern void *func_003A52F0(void *dst, int c, int n);

/* A queued asynchronous call (0x104 bytes; 16 of them at D_003E9D60). */
typedef struct AsyncCall {
    short used;
    char pad2[6];
    void *pd;
    char padC[0x38 - 0xC];
    int a0;
    int a1;
    int a2;
    int a3;
    char pad48[0x78 - 0x48];
    void *cb;
    struct AsyncCall *cbarg;
    void (*fn)(void);
    struct AsyncCall *fnarg;
    char pad88[0xCC - 0x88];
    int ainfSize;               /* 0xCC size of the ADX AINF chunk, 0 without one */
    char ainfData[16];          /* 0xD0 AINF data id */
    short volumeOffset;         /* 0xE0 */
    short panOffset[2];         /* 0xE2 one per channel */
    char padE6[0x104 - 0xE6];
} AsyncCall;

#define AINF_PAN_DEFAULT    (-128)  /* no pan offset set */

extern AsyncCall D_003E9D60[16];

/* A stream handle as the volume calls see it. */
typedef struct StmVolHn {
    char unk00;
    char stat;                  /* 0x01 */
    char unk02[0x38 - 0x02];
    int vol;                    /* 0x38 */
    char unk3C[0x56 - 0x3C];
    char mode;                  /* 0x56 */
} StmVolHn;

#endif /* GODHAND_CRISTM_H */
