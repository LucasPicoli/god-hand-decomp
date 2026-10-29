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
#include "godhand/cObjBase.h"

/* Bits of cGameObj.scrFlags (0x5A0). */
#define GAMEOBJ_SCR_CLIP     0x01       /* cut off by the screen frustum */
#define GAMEOBJ_SCR_BEHIND   0x02       /* behind the camera */
#define GAMEOBJ_SCR_SUSPEND  0x08       /* set by setSuspend(1) */

/* Bits of cGameObj.seqFlags (0x3AC). These names are still under review:
 * nothing yet shows what bits 1 and 2 mean. */
#define GAMEOBJ_MOTION_END   0x01
#define GAMEOBJ_MOTION_LOOP  0x02

/* Bits of cGameObj.objFlags (0x250). */
#define GAMEOBJ_OBJ_SUSPEND  0x8000     /* set by setSuspend(1) */
#define GAMEOBJ_OBJ_SKIP     0x80000000 /* set by ReleaseObj; the move loops skip the object (MCOBJ_FLAG_SKIP) */

/* The method table every game object points at (0x214). Each entry is a g++
 * 2.x delta (short) and function pointer. */
typedef struct cGameObjVt {
    char unk00[0x40];
    short initialDelta;                 /* 0x40 */
    short pad42;
    int (*initial)(void *self);         /* 0x44 run right after CreateObj; 0 when it fails ("model initial failed") */
    char unk48[0x50 - 0x48];
    short moveDelta;                    /* 0x50 */
    short pad52;
    void (*move)(void *self);           /* 0x54 the per-frame update MoveObj calls */
    char unk58[0x60 - 0x58];
    short resetDelta;                   /* 0x60 */
    short pad62;
    void (*reset)(void *self, int arg); /* 0x64 */
    short getPosDelta;                  /* 0x68 */
    short pad6A;
    cVec *(*getPos)(void *self);        /* 0x6C the object's current position */
    char unk70[0x80 - 0x70];
    short lockOnDelta;                  /* 0x80 */
    short pad82;
    void (*lockOn)(void *self);         /* 0x84 getLockOnPos and getHitCheckPos both call it */
    char unk88[0xC0 - 0x88];
    short canAngerDelta;                /* 0xC0 */
    short padC2;
    int (*canAnger)(void *self);        /* 0xC4 nonzero if the enemy can be angered */
    short ckTargetDelta;                /* 0xC8 */
    short padCA;
    int (*ckTarget)(void *self);        /* 0xCC nonzero: skip the height test of GetTargetNear */
} cGameObjVt;

/* One effect the object has started: the entries of its seqData effect
 * block, 0xC bytes each. */
#define GAMEOBJ_EFF_NONE      (-1)      /* cGameObjEffect.id of an unused entry */
#define GAMEOBJ_EFF_FLAG_FADE 0x02      /* cGameObjEffect.flags: kill with the fade-out mode */

typedef struct cGameObjEffect {
    int id;                             /* 0x0 effect number, GAMEOBJ_EFF_NONE if unused */
    char unk04[6];
    unsigned char flags;                /* 0xA */
    char unk0B;
} cGameObjEffect;                       /* 0xC */

/* cGameObj is cObjBase (COBJBASE_FIELDS, 0x000..0x4D0) plus its own fields:
 * the retail constructor (0x2A7338) calls cObjBase first, then writes only
 * 0x214, 0x4AC and 0x4D0 onward. */
#ifndef CGAMEOBJ_NO_TYPEDEF
typedef struct cGameObj cGameObj;
#endif
struct cGameObj {
    COBJBASE_FIELDS
    char unk4D0[0x520 - 0x4D0];
    cVec stored;                        /* 0x520 position remembered with storedWait (w is 1.0) */
    unsigned char storedWait;           /* 0x530 */
    signed char unk531;                 /* 0x531 -1 after construction */
    char unk532[0x548 - 0x532];
    short hpMax;                        /* 0x548 */
    short hp;                           /* 0x54A */
    float hitFlash;                     /* 0x54C counts down after a hit */
    cVec vel;                           /* 0x550 velocity, zeroed when the object is stopped */
    int dropItem;                       /* 0x560 item id it drops, as in cOmBase */
    int emNo;                           /* 0x564 enemy number of an enemy */
    char unk568[0x570 - 0x568];
    short effNo;                        /* 0x570 one more effect to kill with the object, -1 if none */
    short pad572;
    int effArg;                         /* 0x574 the mode to kill it with */
    char unk578[0x5A0 - 0x578];
    int scrFlags;                       /* 0x5A0 GAMEOBJ_SCR_* */
    char unk5A4[4];
    float speedRate;                    /* 0x5A8 1.0 normal, copied from the manager every frame */
};

/* The typed method table behind cGameObj's g++ vtable (0x214). */
static __inline__ cGameObjVt *cGameObj_vt(const struct cGameObj *self)
{
    return (cGameObjVt *)self->vtable;
}

#define GAMEOBJ_OFFSET(field) ((int)&((struct cGameObj *)0)->field)
typedef char cGameObj_chk_mtx[GAMEOBJ_OFFSET(mtx) == 0x80 ? 1 : -1];
typedef char cGameObj_chk_pos[GAMEOBJ_OFFSET(pos) == 0xF0 ? 1 : -1];
typedef char cGameObj_chk_rot[GAMEOBJ_OFFSET(rot) == 0x100 ? 1 : -1];
typedef char cGameObj_chk_anim[GAMEOBJ_OFFSET(tint.w) == 0x24C ? 1 : -1];
typedef char cGameObj_chk_vt[GAMEOBJ_OFFSET(vtable) == 0x214 ? 1 : -1];
typedef char cGameObj_chk_step[GAMEOBJ_OFFSET(step) == 0x2F6 ? 1 : -1];
typedef char cGameObj_chk_posA[GAMEOBJ_OFFSET(posA) == 0x490 ? 1 : -1];
typedef char cGameObj_chk_stored[GAMEOBJ_OFFSET(stored) == 0x520 ? 1 : -1];
typedef char cGameObj_chk_motion[GAMEOBJ_OFFSET(seqFlags) == 0x3AC ? 1 : -1];
typedef char cGameObj_chk_hp[GAMEOBJ_OFFSET(hp) == 0x54A ? 1 : -1];
typedef char cGameObj_chk_kind[GAMEOBJ_OFFSET(kindName) == 0x4AC ? 1 : -1];
typedef char cGameObj_chk_emno[GAMEOBJ_OFFSET(emNo) == 0x564 ? 1 : -1];
typedef char cGameObj_chk_eff[GAMEOBJ_OFFSET(seqData) == 0x42C ? 1 : -1];
typedef char cGameObj_chk_effno[GAMEOBJ_OFFSET(effNo) == 0x570 ? 1 : -1];
typedef char cGameObj_chk_scr[GAMEOBJ_OFFSET(scrFlags) == 0x5A0 ? 1 : -1];
typedef char cGameObj_chk_scale[GAMEOBJ_OFFSET(scale) == 0x110 ? 1 : -1];
typedef char cGameObj_chk_child[GAMEOBJ_OFFSET(children) == 0x278 ? 1 : -1];
typedef char cGameObj_chk_childn[GAMEOBJ_OFFSET(partNum) == 0x2B4 ? 1 : -1];
typedef char cGameObj_chk_ik[GAMEOBJ_OFFSET(ik) == 0x448 ? 1 : -1];
typedef char cGameObj_chk_drop[GAMEOBJ_OFFSET(dropItem) == 0x560 ? 1 : -1];
typedef char cGameObj_chk_rate[GAMEOBJ_OFFSET(speedRate) == 0x5A8 ? 1 : -1];
typedef char cGameObj_chk_ground[GAMEOBJ_OFFSET(groundKind) == 0x474 ? 1 : -1];
typedef char cGameObj_chk_frame[GAMEOBJ_OFFSET(motionFrame) == 0x430 ? 1 : -1];
typedef char cGameObj_chk_size[sizeof(struct cGameObj) == 0x5AC ? 1 : -1];

/* The sort uses insertion sort alone below this many entries. */
#define GAMEOBJ_SORT_THRESHOLD 16

/* Whether the actor id of obj lies in [lo, hi), as a long flag. The retail
 * range tests build the flag with a branch and a copy, then mask it with 0xFF
 * where it is tested: write `if (cGameObj_idInRange(obj, lo, hi) & 0xFF)`. */
static __inline__ long cGameObj_idInRange(const struct cGameObj *obj, int lo, int hi)
{
    int id = obj->actorId;
    long in = 0;

    if (id >= lo) {
        int below = id < hi;

        in = below;
    }
    return in;
}

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


extern void func_002831C8(struct cGameObj *self, unsigned int kind, unsigned char arg);

#endif /* GODHAND_CGAMEOBJ_H */
