/* include/godhand/cMc.h - cMc, the loader for the memory card overlay.
 *
 * The memory card code is a separate module that DllLoad reads from disc
 * into a heap block (D_00754230) while it pumps the frame (cMc_Move and
 * cMc_Trans), and DllRelease frees again. The object keeps a loaded flag
 * and the block pointer. Retail logs each step through func_0, a call that
 * was stripped to address 0; the string argument is address 0 as well.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CMC_H
#define GODHAND_CMC_H

typedef struct cMc {
    unsigned char loaded;               /* 0x00 1 while the module is in memory */
    char unk01[3];
    void *dll;                          /* 0x04 heap block that holds the module */
} cMc;

/* The task reference block D_00752C00: the loader sleeps on its task
 * while the disc read is pending. */
typedef struct cMcTaskRef {
    int unk0;
    void *task;                         /* 0x4 */
} cMcTaskRef;

/* What the per-frame move loop reads of a game object: its method table
 * (g++ 2.x delta and function pointer at 0x50 and 0x54) and its flag word. */
#define MCOBJ_FLAG_SUSPEND  0x8000
#define MCOBJ_FLAG_SKIP     0x80000000

typedef struct cMcObjVt {
    char unk00[0x50];
    short moveDelta;                    /* 0x50 added to this before the call */
    short pad52;
    void (*move)(void *self);           /* 0x54 */
} cMcObjVt;

typedef struct cMcObj {
    char unk000[0x214];
    cMcObjVt *vt;                       /* 0x214 */
    char unk218[0x38];
    unsigned int objFlags;              /* 0x250 */
} cMcObj;

/* The game object list D_00754C58: begin and end of an array of pointers. */
typedef struct cMcObjList {
    int unk0;
    cMcObj **begin;                     /* 0x4 */
    cMcObj **end;                       /* 0x8 */
} cMcObjList;

#endif
