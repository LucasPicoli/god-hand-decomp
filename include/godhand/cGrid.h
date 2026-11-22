/* include/godhand/cGrid.h - a uniform grid over an axis-aligned box (sn code at 0x12F288..0x133948),
 * and the collision bodies it holds (func_0012D3C8 at 0x12D3C8 draws one).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CGRID_H
#define GODHAND_CGRID_H

#include "godhand/cOmBase.h"

typedef struct cGrid {
    char unk00[0x30];
    cVec min;                           /* 0x30 */
    cVec max;                           /* 0x40 */
    cVec cell;                          /* 0x50 cell size */
    unsigned int num[3];                /* 0x60 cells per axis */
    int lo[3];                          /* 0x6C first cell the query box covers */
    int hi[3];                          /* 0x78 last cell */
    char unk84[0xC];
    cVec boxMin;                        /* 0x90 query box */
    cVec boxMax;                        /* 0xA0 */
} cGrid;

/* One face of a collision body. */
typedef struct cCollFace {
    unsigned short colorClass;          /* 0x0 picks the debug outline's and fill's colour */
    unsigned short kind;                /* 0x2 face kind bits */
    int attr;                           /* 0x4 face attribute bits */
    unsigned short unk8;                /* 0x8 */
    unsigned char unkA;                 /* 0xA */
    unsigned char unkB;                 /* 0xB */
    char unkC[4];
} cCollFace;

typedef char cCollFace_size_check[(sizeof(cCollFace) == 0x10) ? 1 : -1];

/* A collision body in the grid's list. The ELF's type names call the base
 * cCollisionScrollSolid, with cCollisionScrollBoard and cCollisionScrollBox
 * derived from it. Retail allocates a board with 0x100 bytes
 * (func_0030F550(0x100) at 0x12EA1C and 0x12EA64, for func_0012CF70) and a
 * box with 0x190 (at 0x12EB64 and 0x12EBC8, for cHitRec_constructSixBlob):
 * the ends of u.board and u.box. */
typedef struct cCollisionScrollSolid {
    struct cCollisionScrollSolid *next; /* 0x00 */
    int type;                           /* 0x04 */
    unsigned int flags;                 /* 0x08 */
    char unk0C[4];
    cVec min;                           /* 0x10 bounds */
    cVec max;                           /* 0x20 */
    void *owner;                        /* 0x30 the object the body follows */
    char unk34[0x20];                   /* 0x34 cleared */
    int unk54;                          /* 0x54 cleared */
    float *mtx;                         /* 0x58 the owner's matrix */
    const void *vt;                     /* 0x5C vtable; D_0041D5A8 for the base */
    cVec pos;                           /* 0x60 */
    cVec unk70;                         /* 0x70 */
    cVec rot;                           /* 0x80 */
    cVec unk90;                         /* 0x90 */
    union {
        struct {
            char unkA0[8];
            cCollFace face;             /* 0xA8 */
            char unkB8[8];
            cVec corner[4];             /* 0xC0 */
        } board;                        /* cCollisionScrollBoard (vt D_0041D580) */
        struct {
            cVec extent;                /* 0xA0 the size argument, each axis made positive */
            cCollFace face[6];          /* 0xB0 */
            cVec corner[8];             /* 0x110 */
        } box;                          /* cCollisionScrollBox (vt D_0041D558) */
    } u;                                /* 0xA0 */
} cCollisionScrollSolid;

typedef char cCollisionScrollSolid_size_check[(sizeof(cCollisionScrollSolid) == 0x190) ? 1 : -1];
typedef char cCollisionScrollSolid_board_size_check[(sizeof(((cCollisionScrollSolid *)0)->u.board) == 0x100 - 0xA0) ? 1 : -1];

/* 1 << n for n = 0..31; the board debug draw copies it to the stack. */
extern const int D_0041D2E0[32];

/* Debug draw of a board's outline, and with fill set its face filled. */
void func_0012D3C8(cCollisionScrollSolid *self, int mode, int fill);

/* Debug draw of pts[0..2], or pts[0..3] when quad is set, filled in one colour. */
void func_001334A8(cVec *pts, int quad, int color);

/* Adds a box body for obj at the end of the collision list self (first body
 * at 0x190, count at 0x194) and returns it; 0 when obj is 0 or the body
 * can't be made. The body is cHitRec_constructSixBlob on func_0030F550(0x190). */
cCollisionScrollSolid *func_0012EAD8(char *self, void *obj, void *mtx, void *half,
                                     void *zero, void *center, void *ax0, void *ax1,
                                     void *ax2, void *ax3, void *ax4, void *ax5);

extern void func_00133948(void *self, void *boxMin, void *boxMax);
extern int func_00133408(void *unused, float *min, float *max, float *boxMin, float *boxMax);

#endif /* GODHAND_CGRID_H */
