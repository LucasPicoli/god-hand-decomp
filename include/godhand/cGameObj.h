/* include/godhand/cGameObj.h - cGameObj, the base of every moving game object.
 *
 * cGameObj derives from cObjBase and is the base class of the player, the
 * enemies and the NPCs. It adds a screen-clip flag word, a stored position
 * with a wait byte, a rotation, a pointer to the live position, and a method
 * table at 0x214 that its subclasses override. The field names for the
 * state bytes and flag words match cOmBase.h where the meaning is the same.
 *
 * The span of cGameObj in the retail ELF also holds an instantiated STL
 * sort (heap and insertion sort) over 8-byte {id, key} entries, which
 * the object code uses to order targets by distance. Those entries and
 * their order are declared here too.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CGAMEOBJ_H
#define GODHAND_CGAMEOBJ_H

#include "godhand/cOmBase.h"

/* Bits of cGameObj.scrFlags (0x5A0). */
#define GAMEOBJ_SCR_CLIP     0x01       /* cut off by the screen frustum */
#define GAMEOBJ_SCR_BEHIND   0x02       /* behind the camera */
#define GAMEOBJ_SCR_SUSPEND  0x08       /* set by setSuspend(1) */

/* Bits of cGameObj.motionFlags (0x3AC), set by the model code. */
#define GAMEOBJ_MOTION_END   0x01       /* the current motion has finished */
#define GAMEOBJ_MOTION_LOOP  0x02       /* the current motion has looped */

/* Bits of cGameObj.objFlags (0x250). */
#define GAMEOBJ_OBJ_SUSPEND  0x8000     /* set by setSuspend(1) */

/* The method table every game object points at (0x214). Each entry is a g++
 * 2.x delta (short) and function pointer; only the pair at 0x80 is used here. */
typedef struct cGameObjVt {
    char unk00[0x80];
    short lockOnDelta;                  /* 0x80 */
    short pad82;
    void (*lockOn)(void *self);         /* 0x84 getLockOnPos and getHitCheckPos both call it */
} cGameObjVt;

/* One effect the object has started (cGameObj.effList). The retail table
 * is a block with a header and an array of 0xC-byte entries. */
#define GAMEOBJ_EFF_NONE      (-1)      /* cGameObjEffect.id of an unused entry */
#define GAMEOBJ_EFF_FLAG_FADE 0x02      /* cGameObjEffect.flags: kill with the fade-out mode */

typedef struct cGameObjEffect {
    int id;                             /* 0x0 effect number, GAMEOBJ_EFF_NONE if unused */
    char unk04[6];
    unsigned char flags;                /* 0xA */
    char unk0B;
} cGameObjEffect;                       /* 0xC */

typedef struct cGameObjEffectList {
    char unk00[0x14];
    unsigned short entryOfs;            /* 0x14 byte offset of the entries */
    unsigned short entryNum;            /* 0x16 */
} cGameObjEffectList;

/* The fields the cGameObj methods and the move code share. */
typedef struct cGameObj {
    char unk000[0xF0];
    cVec *pos;                          /* 0x0F0 the object's live position */
    char unk0F4[0xC];
    float rot[3];                       /* 0x100 rotation, rot[1] is the heading */
    char unk10C[0x214 - 0x10C];
    cGameObjVt *vt;                     /* 0x214 */
    char unk218[0x250 - 0x218];
    int objFlags;                       /* 0x250 */
    char unk254[0x2F4 - 0x254];
    unsigned char mode;                 /* 0x2F4 the four state bytes the move code writes together */
    unsigned char phase;                /* 0x2F5 */
    unsigned char step;                 /* 0x2F6 the phase machines switch on it */
    unsigned char stepArg;              /* 0x2F7 */
    char unk2F8[0x6];
    unsigned short actorId;             /* 0x2FE */
    char unk300[0x4];
    char *motionData;                   /* 0x304 the loaded model's data block */
    char unk308[0x3AC - 0x308];
    unsigned short motionFlags;         /* 0x3AC GAMEOBJ_MOTION_* */
    char unk3AE[0x42C - 0x3AE];
    cGameObjEffectList *effList;        /* 0x42C effects started by this object */
    char unk430[0x490 - 0x430];
    cVec posA;                          /* 0x490 position copy used by setPos */
    char unk4A0[0x4AC - 0x4A0];
    const char *kindName;               /* 0x4AC class name of the object, set by its constructor */
    char unk4B0[0x520 - 0x4B0];
    cVec stored;                        /* 0x520 position remembered with storedWait (w is 1.0) */
    unsigned char storedWait;           /* 0x530 */
    signed char unk531;                 /* 0x531 -1 after construction */
    char unk532[0x548 - 0x532];
    short hpMax;                        /* 0x548 */
    short hp;                           /* 0x54A */
    char unk54C[0x570 - 0x54C];
    short effNo;                        /* 0x570 one more effect to kill with the object, -1 if none */
    short pad572;
    int effArg;                         /* 0x574 the mode to kill it with */
    char unk578[0x5A0 - 0x578];
    unsigned int scrFlags;              /* 0x5A0 GAMEOBJ_SCR_* */
    char unk5A4[4];
    float speedRate;                    /* 0x5A8 1.0 normal, copied from the manager every frame */
} cGameObj;

#define GAMEOBJ_OFFSET(field) ((int)&((cGameObj *)0)->field)
typedef char cGameObj_chk_pos[GAMEOBJ_OFFSET(pos) == 0xF0 ? 1 : -1];
typedef char cGameObj_chk_rot[GAMEOBJ_OFFSET(rot) == 0x100 ? 1 : -1];
typedef char cGameObj_chk_vt[GAMEOBJ_OFFSET(vt) == 0x214 ? 1 : -1];
typedef char cGameObj_chk_step[GAMEOBJ_OFFSET(step) == 0x2F6 ? 1 : -1];
typedef char cGameObj_chk_posA[GAMEOBJ_OFFSET(posA) == 0x490 ? 1 : -1];
typedef char cGameObj_chk_stored[GAMEOBJ_OFFSET(stored) == 0x520 ? 1 : -1];
typedef char cGameObj_chk_motion[GAMEOBJ_OFFSET(motionFlags) == 0x3AC ? 1 : -1];
typedef char cGameObj_chk_hp[GAMEOBJ_OFFSET(hp) == 0x54A ? 1 : -1];
typedef char cGameObj_chk_kind[GAMEOBJ_OFFSET(kindName) == 0x4AC ? 1 : -1];
typedef char cGameObj_chk_eff[GAMEOBJ_OFFSET(effList) == 0x42C ? 1 : -1];
typedef char cGameObj_chk_effno[GAMEOBJ_OFFSET(effNo) == 0x570 ? 1 : -1];
typedef char cGameObj_chk_scr[GAMEOBJ_OFFSET(scrFlags) == 0x5A0 ? 1 : -1];
typedef char cGameObj_chk_rate[GAMEOBJ_OFFSET(speedRate) == 0x5A8 ? 1 : -1];

/* The sort uses insertion sort alone below this many entries. */
#define GAMEOBJ_SORT_THRESHOLD 16

/* One entry of the sorted target list: an id and the key it is ordered by. */
typedef struct cGameObjSortEnt {
    int id;                             /* 0x0 */
    float key;                          /* 0x4 */
} cGameObjSortEnt;

/* The sort helpers' callers hand an entry over by value, packed into one
 * 64-bit register: id in the low word, key in the high word. The helpers
 * themselves declare the parameter as the struct. */
static __inline__ long cGameObjSortEnt_pack(const cGameObjSortEnt *e)
{
    return ((long)*(const unsigned int *)&e->key << 32) | (unsigned int)e->id;
}

/* Entry order of the sort: smaller key first. The helper returns a 0/1 byte
 * because that is the only spelling that keeps the compare as a materialised
 * flag the way the retail sort loops have it. */
static __inline__ unsigned char cGameObjSortEnt_less(const cGameObjSortEnt *a, const cGameObjSortEnt *b)
{
    return a->key < b->key;
}


#endif /* GODHAND_CGAMEOBJ_H */
