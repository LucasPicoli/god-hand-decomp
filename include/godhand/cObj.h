/* include/godhand/cObj.h - the actor record: a model plus an id and a state machine.
 *
 * cObj derives from cModel. It adds the actor id, the data pack the actor
 * was built from and the four state bytes that the move code writes together.
 * cObjBase and cOmBase derive from cObj. This header names the cObj fields
 * and repeats the cModel record in front of them (see cModel.h).
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_COBJ_H
#define GODHAND_COBJ_H

#include "godhand/cModel.h"

/* Bits of cObj.actorGroup (0x2D0): one per range of actor ids, set by setId. */
#define COBJ_GROUP_PLAYER   0x80000000  /* ids 0x100..0x1FE */
#define COBJ_GROUP_2        0x40000000  /* ids 0x200..0x2FF */
#define COBJ_GROUP_3        0x20000000  /* ids 0x300..0x4FF */
#define COBJ_GROUP_4        0x10000000  /* ids 0x500..0x5FF */
#define COBJ_GROUP_5        0x00800000  /* ids 0x600..0x6FF */

/* Bits of cModel.objFlags (0x250) that cObj itself sets. */
#define COBJ_F_SUSPEND      0x8000      /* the actor is suspended */

#define COBJ_FIELDS \
    CMODEL_FIELDS \
    char unk2E4[0x10]; \
    unsigned char mode;                 /* 0x2F4 0x2F4..0x2F7 are the four state bytes the move code writes together */ \
    unsigned char phase;                /* 0x2F5 */ \
    unsigned char step;                 /* 0x2F6 */ \
    unsigned char stepArg;              /* 0x2F7 */ \
    char unk2F8[0x6]; \
    unsigned short actorId;             /* 0x2FE actor type id */ \
    char unk300[0x4]; \
    char *pack;                         /* 0x304 the data pack: offset tables read as pack + pack[N] */ \
    char unk308[0x8];

struct cObj {
    COBJ_FIELDS
};                                      /* 0x310 */

/* As in cModel.h: a TU that defines or declares the constructor cObj defines
 * COBJ_NO_TYPEDEF before this include and writes struct cObj. */
#ifndef COBJ_NO_TYPEDEF
typedef struct cObj cObj;
#endif

typedef char cObj_size_check[(sizeof(struct cObj) == 0x310) ? 1 : -1];

#endif
