/* include/godhand/criSj.h - CRI stream joint (SJ) interface and the Sofdec SJ helpers.
 *
 * Field names are ours; vtable offsets are exact.
 */
#ifndef GODHAND_CRISJ_H
#define GODHAND_CRISJ_H

/* CRI scalar types. */
typedef signed char Sint8;
typedef unsigned char Uint8;
typedef int Sint32;
typedef unsigned int Uint32;

/* A chunk of stream data (CRI's SJCK). */
typedef struct SjChunk {
    Sint8 *data;                /* 0x00 */
    Sint32 len;                 /* 0x04 */
} SjChunk;

typedef struct SjObj SjObj;

/* The stream joint interface (CRI's SJ_IF). */
typedef struct SjIf {
    void *obj;                                                  /* 0x00 */
    void (*addRef)(SjObj *sj);                                  /* 0x04 */
    void (*release)(SjObj *sj);                                 /* 0x08 */
    void (*destroy)(SjObj *sj);                                 /* 0x0C */
    void *(*getUuid)(SjObj *sj);                                /* 0x10 */
    void (*reset)(SjObj *sj);                                   /* 0x14 */
    void (*getChunk)(SjObj *sj, int id, int len, SjChunk *ck);  /* 0x18 */
    void (*ungetChunk)(SjObj *sj, int id, SjChunk *ck);         /* 0x1C */
    void (*putChunk)(SjObj *sj, int id, SjChunk *ck);           /* 0x20 */
    int (*getNumData)(SjObj *sj, int id);                       /* 0x24 */
} SjIf;

struct SjObj {
    SjIf *vt;
};

/* The memory stream joint (SJMEM). */
typedef struct SjMem {
    int unk00;
    int used;                   /* 0x04 */
    int unk08;
    int dataLen;                /* 0x0C bytes of data available */
    int readPos;                /* 0x10 offset of the next read from base */
    Sint8 *base;                /* 0x14 */
    int size;                   /* 0x18 */
    void (*cb)(void *obj, int ev);  /* 0x1C error callback */
    void *cbobj;                /* 0x20 */
} SjMem;

/* A recorded tag chunk; set is 1 once ck holds the chunk. */
typedef struct SjTagRec {
    int set;                    /* 0x00 */
    SjChunk ck;                 /* 0x04 */
} SjTagRec;

#define SJ_TAG_SET  1           /* SjTagRec.set once ck holds the chunk */

/* The ring-buffer stream joint (CRI's SJRBF), one of a pool of 0x40-byte objects. */
typedef struct SjRbf {
    void *vtbl;                 /* 0x00 */
    int used;                   /* 0x04 */
    void *uuid;                 /* 0x08 */
    int data;                   /* 0x0C bytes of data */
    int free;                   /* 0x10 bytes free */
    int freePos;                /* 0x14 */
    int dataPos;                /* 0x18 */
    Sint8 *buf;                 /* 0x1C */
    int size;                   /* 0x20 */
    int extra;                  /* 0x24 */
    int freeTaken;              /* 0x28 bytes taken from the free lane */
    int unk2C;
    int dataTaken;              /* 0x30 bytes taken from the data lane */
    int unk34;
    void (*err)(void *obj, int code);   /* 0x38 */
    void *errObj;               /* 0x3C */
} SjRbf;

/* One chunk of the unified stream joint (CRI's SJUNI). */
typedef struct SjUniChunk {
    struct SjUniChunk *next;    /* 0x00 */
    int unk4;
    void *unk8;
    int unkC;
} SjUniChunk;

/* The unified stream joint (CRI's SJUNI). */
typedef struct SjUni {
    void *f0;
    signed char f4;
    signed char f5;
    char pad6[2];
    void *f8;
    SjUniChunk *buf;            /* 0x0C */
    int nchunk;                 /* 0x10 */
    SjUniChunk *free;           /* 0x14 */
    SjUniChunk *list[4];        /* 0x18 */
} SjUni;

extern Sint8 *SJ_SearchTag(SjChunk *ck, Sint8 *tag, Sint8 *endtag, SjChunk *tagck);

/* Sofdec stream-joint position feed (0x327818..). */
extern int GetVia4_Obj33C8_GetField_28_7818_327818(void *sj);
extern int func_00327830(void *sj);
extern int GetVia4_Obj33C8_GetField_30_7860_327860(void *sj);
extern int Forward33CFB8_327970(void *sj);
extern void Forward33CFF8_327988(void *sj);
extern void Obj3270_SetField_34(void *sj, int v);
extern void Obj3270_SetField_3C(void *sj, int v);
extern void Obj3270_SetField_40(void *sj, int v);
extern void Obj3270_SetField_44(void *sj, int v);
extern void Obj3270_SetField_48_4C(void *sj, void (*fn)(char *), void *arg);
extern void func_0033F130(const char *msg);

#endif /* GODHAND_CRISJ_H */
