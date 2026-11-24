/* include/godhand/criSjIf.h - the CRI stream joint chunk and interface types.
 *
 * Split from criSj.h so that a header can use them without criSj.h's
 * Sofdec helper declarations. Field names are ours; vtable offsets are exact.
 */
#ifndef GODHAND_CRISJIF_H
#define GODHAND_CRISJIF_H

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
typedef char SjChunk_size_check[(sizeof(SjChunk) == 0x8) ? 1 : -1];

struct SjObj;

/* The stream joint interface (CRI's SJ_IF). */
typedef struct SjIf {
    void *obj;                                                         /* 0x00 */
    void (*addRef)(struct SjObj *sj);                                  /* 0x04 */
    void (*release)(struct SjObj *sj);                                 /* 0x08 */
    void (*destroy)(struct SjObj *sj);                                 /* 0x0C */
    void *(*getUuid)(struct SjObj *sj);                                /* 0x10 */
    void (*reset)(struct SjObj *sj);                                   /* 0x14 */
    void (*getChunk)(struct SjObj *sj, int id, int len, SjChunk *ck);  /* 0x18 */
    void (*ungetChunk)(struct SjObj *sj, int id, SjChunk *ck);         /* 0x1C */
    void (*putChunk)(struct SjObj *sj, int id, SjChunk *ck);           /* 0x20 */
    int (*getNumData)(struct SjObj *sj, int id);                       /* 0x24 */
} SjIf;
typedef char SjIf_size_check[(sizeof(SjIf) == 0x28) ? 1 : -1];

typedef struct SjObj {
    SjIf *vt;
} SjObj;
typedef char SjObj_size_check[(sizeof(SjObj) == 0x4) ? 1 : -1];

#endif /* GODHAND_CRISJIF_H */
