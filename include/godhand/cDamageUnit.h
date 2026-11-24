/* include/godhand/cDamageUnit.h - cDamageUnit, the damage hit volumes of one actor.
 *
 * The unit keeps a doubly linked list of nodes at 0x3C. Each node carries a
 * numeric id and points at a cCollisionUnit, the collision manager's record,
 * whose word at 0x34 is the cCollisionShape it holds at 0xE0. Methods walk
 * the list and either touch every node (SetDamageCollActive,
 * SetDamageCollOffset) or look one up by id (SetDamageCollRadius). The
 * shape's virtual call uses the g++ 2.x delta/index/pfn table entry. Offsets
 * are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CDAMAGEUNIT_H
#define GODHAND_CDAMAGEUNIT_H

#include "godhand/cVecType.h"

struct cGameObj;

typedef struct cDamageVtEnt {
    short delta;                /* added to this before the call */
    short index;
    void *pfn;
} cDamageVtEnt;

/* Retail's matrix type, cMatrix (MtxInitRotY__FR7cMatrixf and others). Only
 * its address is passed here, so no layout yet. */
struct cMatrix;

/* A collision shape: the base of cCollisionShapeCylinder,
 * cCollisionShapeRectbox and cCollisionShapeSphere, which the three pool
 * creators build inside a cCollisionUnit. */
typedef struct cCollisionShape {
    int state;                  /* 0x000 CCOLLISION_SHAPE_SPHERE, _CYLINDER or _RECTBOX */
    unsigned char flags;        /* 0x004 bit 1: mtx isn't the world matrix */
    char unk005[3];
    const struct cMatrix *mtx;  /* 0x008 the matrix it follows */
    char unk00C[0x50 - 0xC];
    cVec ofs;                   /* 0x050 offset in mtx's space */
    cVec rot;                   /* 0x060 */
    char unk070[0xC0 - 0x70];
    cVec *pos;                  /* 0x0C0 the shape's world position */
    char unk0C4[0x100 - 0xC4];
    cDamageVtEnt *vt;           /* 0x100 */
    char unk104[0x110 - 0x104];
} cCollisionShape;              /* 0x110: the deleting destructor func_002BAFE0 frees 0x110 (0x2BB000) */

typedef char cCollisionShape_size_check[(sizeof(cCollisionShape) == 0x110) ? 1 : -1];

#define CCOLLISION_SHAPE_NOT_WORLD  0x2     /* flags bit 1 */

/* The shape a creator builds: its state, and the kind it asks create for. */
#define CCOLLISION_SHAPE_SPHERE     0
#define CCOLLISION_SHAPE_CYLINDER   2
#define CCOLLISION_SHAPE_RECTBOX    4

/* Slots of the shape's vtable. */
#define CCOLLISION_SHAPE_SETRADIUS  3       /* sphere and cylinder */
#define CCOLLISION_SHAPE_SETHEIGHT  5       /* cylinder; the rectbox sets size.y */
#define CCOLLISION_SHAPE_SETSIZE    7       /* rectbox */
#define CCOLLISION_SHAPE_UPDATE     10

/* The base vtable, which the constructor stores, and the vtables of the
 * three shapes the pool creators build. */
extern cDamageVtEnt D_0044BED0[];       /* cCollisionShape */
extern cDamageVtEnt D_0044BCA0[];       /* cCollisionShapeCylinder */
extern cDamageVtEnt D_0044BB20[];       /* cCollisionShapeRectbox */
extern cDamageVtEnt D_0044BD60[];       /* cCollisionShapeSphere */

/* The shape's operator delete; the deleting destructor func_002BAFE0 passes
 * sizeof(cCollisionShape). */
void func_002BB018(void *p, int size);

/* The world matrix: a shape that follows it keeps CCOLLISION_SHAPE_NOT_WORLD clear. */
extern struct cMatrix D_00747AC0;

/* Constructor: the base vtable, the flags and four vectors cleared, the
 * matrix, then the offset and the rotation. Returns self. */
cCollisionShape *cCollisionShape_construct(cCollisionShape *self, const struct cMatrix *mtx,
                                           const cVec *ofs, const cVec *rot);
/* Store the offset (x, y, z) and update the shape. */
void cCollisionShape_setOffsetPos(cCollisionShape *self, const cVec *ofs);
/* Store the rotation (x, y, z) and update the shape. */
void func_002BB298(cCollisionShape *self, const cVec *rot);

/* A four-slot table of {key, value} pairs (KeySlotTable_set). */
typedef struct KeySlot {
    int key;                            /* 0x0 key, 0 when the slot is free */
    int value;                          /* 0x4 */
} KeySlot;

/* Store value under key: replace the value of an existing key, else take a
 * free slot. 1 on success, 0 if full. */
int KeySlotTable_set(KeySlot *tbl, int key, int value);
/* The slot holding key, or 0. */
KeySlot *func_002BB068(KeySlot *tbl, int key);
/* The first free slot, or 0. */
KeySlot *func_002BB098(KeySlot *tbl);
/* The value stored under key, or 0. */
int func_002BB138(KeySlot *tbl, int key);

/* A record of the collision manager (cManager<cCollisionUnit>, D_005E8040):
 * its list link, its group and the shape it holds. The manager's element
 * size is 0x26C (InitVtableEntry_2B8AE0 passes it to func_002BA178), so the
 * shape span runs from 0xE0 to the end. */
typedef struct cCollisionUnit {
    unsigned int flags;             /* 0x00 bit 1 = active */
    struct cCollisionUnit *next;    /* 0x04 the manager's list */
    const void *vt;                 /* 0x08 */
    unsigned char kind;             /* 0x0C the group's kind (func_002B8A70) */
    char unk0D[3];
    int group;                      /* 0x10 layer bit number */
    KeySlot keyTable[4];            /* 0x14 */
    cCollisionShape *shape;         /* 0x34 the shape at 0xE0 */
    char unk38[0xD8 - 0x38];
    int unkD8;                      /* 0xD8 cleared by func_002B8AA8 */
    char unkDC[0xE0 - 0xDC];
    cCollisionShape body;           /* 0xE0 the shape this unit holds */
    char unk1F0[0x26C - 0x1F0];     /* the derived shape's own fields */
} cCollisionUnit;                   /* 0x26C */

typedef char cCollisionUnit_size_check[(sizeof(cCollisionUnit) == 0x26C) ? 1 : -1];

/* Bits of cCollisionUnit.flags. */
#define COLL_UNIT_FLAG_ACTIVE         0x2
#define COLL_UNIT_FLAG_INACTIVE_MASK  0xFFFFFFFD    /* written out: ~2 compiles to a different insn */
/* A unit is live when it's active (bit 1) and bit 0 is set, with bit 9 clear. */
#define COLL_UNIT_FLAGS_MASK          0x203
#define COLL_UNIT_FLAGS_LIVE          0x3
/* What a creator needs from the unit create hands it: bit 0 set, bit 9 clear. */
#define COLL_UNIT_FLAGS_READY_MASK    0x201
#define COLL_UNIT_FLAGS_READY         0x1

/* The collision manager: the live units and, per layer, the groups that count. */
typedef struct cCollisionManager {
    char unk00[0x10];
    cCollisionUnit *head;           /* 0x10 the live units */
    char unk14[4];
    const cDamageVtEnt *vt;         /* 0x18 */
    unsigned int mask[16];          /* 0x1C per layer, a bit per group that counts */
} cCollisionManager;                /* 0x5C up to the masks; the real size isn't known */

typedef char cCollisionManager_size_check[(sizeof(cCollisionManager) == 0x5C) ? 1 : -1];

#define CCOLLISION_MANAGER_RELEASE  6   /* vt[6] gives a unit back */

extern cCollisionManager D_005E8040;

/* Take the first unused unit of the manager's array, set it up for kind and
 * put it on the live list; 0 when every unit is in use. */
cCollisionUnit *create(cCollisionManager *pool, int kind);
/* The kind of group: 1 for 0 and the odd groups 1-7, 0 for the even ones
 * 2-8 and anything else. self isn't read. */
int func_002B8A30(cCollisionManager *self, unsigned int group);
/* Put the unit in group and store the group's kind. */
void func_002B8A70(cCollisionUnit *self, int group);
/* Clear unkD8 and, when the unit is live, update its shape. */
void func_002B8AA8(cCollisionUnit *self);
/* func_002BA250, then func_002B8AA8 on every live unit, then func_002B8F48. */
void func_002B9D58(cCollisionManager *self);

/* The three pool creators: take a free unit, put it in group, build its
 * shape at ofs in mtx's space (turned by rot) and point the unit at it.
 * They return the unit, or 0 when none is free. */
cCollisionUnit *Pool_createObjWithTable(cCollisionManager *pool, int group, const struct cMatrix *mtx,
                                        const cVec *ofs, const cVec *rot, float height, float radius);
cCollisionUnit *Pool_createObjWithVt(cCollisionManager *pool, int group, const struct cMatrix *mtx,
                                     const cVec *ofs, const cVec *rot, const cVec *size);
cCollisionUnit *Pool_createObjWithScale(cCollisionManager *pool, int group, const struct cMatrix *mtx,
                                        const cVec *ofs, float radius);

/* First live unit of the layer's opposite kind whose shape lies within radius
 * of pos, or 0. layer is retail's eCollisionLayer
 * (checkNearCollision__17cCollisionManager15eCollisionLayerRC4cVecf). */
cCollisionUnit *cCollisionManager_checkNearCollision(cCollisionManager *self, int layer, const cVec *pos,
                                                     float radius);

/* A volume of a damage unit: two copies of the shape's position, the list
 * links, the collision unit and the id the adders return. The nodes come from
 * the unit's vt[2]; their size isn't known. cDamageNode is this project's
 * name: retail has no type string for it, and the attaches below are named
 * after it. */
typedef struct cDamageNode {
    cVec posA;                      /* 0x00 */
    cVec posB;                      /* 0x10 */
    struct cDamageNode *prev;       /* 0x20 */
    struct cDamageNode *next;       /* 0x24 */
    cCollisionUnit *unit;           /* 0x28 */
    short id;                       /* 0x2C */
    unsigned char ready;            /* 0x2E set once the unit is attached */
} cDamageNode;                      /* 0x30 up to ready; the real size isn't known */

typedef char cDamageNode_size_check[(sizeof(cDamageNode) == 0x30) ? 1 : -1];

/* The fields a give (cDamageGive, 0x60 bytes) and a take (cDamageTake, 0x70
 * bytes) share, 0x00..0x53: the cDamageUnit head both derive from (the type
 * info registers 11cDamageUnit before 11cDamageGive and 11cDamageTake). The
 * manager runs the same code on both kinds:
 * - The constructors store the vtable at 0x50: D_0042C4D8 for cDamageUnit
 *   (0x1FCE38, 0x1FD3D0), then D_0042C4B8 for a give (0x1FCE58) or
 *   D_0042C498 for a take (0x1FD3F8). g++ 2.x places the vptr after the
 *   members of the first class with virtuals.
 * - ActorRec_reset clears flags, both vectors, owner, unk38, nodes, unk44,
 *   kind, live and power, sets unk40 to -1 and sets unitKind (func_001FD988).
 * - SetObjTargetAndActivate_1FD2C0 and SetTarget_1FD530 read type, then store
 *   owner, clear attacker and set live.
 * - When a give hits a take, func_001FCF20 copies kind, unk40, unk44 and power
 *   from the give to the take, writes the hit's direction and position into
 *   the take, sets bits 0 and 1 of its hitFlags, and stores each side's owner
 *   in the other's attacker.
 * - func_001FDFD8 reads live on both arrays (0x60 and 0x70 strides). */
#define CDAMAGE_UNIT_FIELDS                                                     \
    unsigned int flags;         /* 0x00 bit 0 is set by the enemy setups */     \
    char unk04[0xC];                                                            \
    cVec hitVec;                /* 0x10 push direction of the hit */            \
    cVec unk20;                 /* 0x20 cleared by the reset; a hit's position */ \
    struct cGameObj *owner;     /* 0x30 the object the manager gave it to */    \
    struct cGameObj *attacker;  /* 0x34 the other side's owner in the last hit */ \
    int unk38;                  /* 0x38 cleared by the reset */                 \
    cDamageNode *nodes;         /* 0x3C list head, 0 when empty */              \
    int unk40;                  /* 0x40 -1 after the reset; cleared by the enemy setups */ \
    short unk44;                /* 0x44 */                                      \
    short kind;                 /* 0x46 attack kind: the setups store 0x2E..0x52, 0 when parked */ \
    signed char unitKind;       /* 0x48 set by func_001FD988 */                 \
    signed char type;           /* 0x49 CDAMAGE_TYPE_*, by the record's setup */        \
    unsigned char live;         /* 0x4A in use */                               \
    char unk4B;                                                                 \
    int power;                  /* 0x4C hit strength, 0 when parked */          \
    const cDamageVtEnt *vt      /* 0x50 vtable */

/* The head a give and a take share. */
typedef struct cDamageUnit {
    CDAMAGE_UNIT_FIELDS;
} cDamageUnit;                  /* 0x54 */

typedef char cDamageUnit_size_check[(sizeof(cDamageUnit) == 0x54) ? 1 : -1];

/* A take record: what cDamageManage_CreateDamageTake returns and
 * cOmBase_checkDamage (checkDamage__7cOmBaseP11cDamageTake) tests. */
typedef struct cDamageTake {
    CDAMAGE_UNIT_FIELDS;
    char unk54[0x60 - 0x54];
    unsigned int hitFlags;      /* 0x60 bit 0 must be set for the hit to count */
    char unk64[0x70 - 0x64];
} cDamageTake;                  /* 0x70: the manager's take array has a 0x70 stride */

typedef char cDamageTake_size_check[(sizeof(cDamageTake) == 0x70) ? 1 : -1];

/* Hand take to owner and set it up for kind; nothing on the spare. Returns 1. */
int SetTarget_1FD530(cDamageTake *self, struct cGameObj *owner, int kind);

/* Clears the head: flags, both vectors, owner, unk38, nodes, unk44, kind, live
 * and power; unk40 to -1 and unit kind 4. */
void ActorRec_reset(cDamageUnit *self);
/* Resets a take: the head, attacker, type 2 and hitFlags. */
void ResetObjectFields_1FCDE8(cDamageTake *self);

/* The collision group of the unit: 1 to 8 by unitKind 0-3, the odd one for a
 * give, the even one otherwise; 0 for any other unit kind. */
int func_001FD908(cDamageUnit *self);

/* Sets unitKind and stores the unit's group (func_001FD908) in the record of
 * every node. */
void func_001FD988(cDamageUnit *self, int kind);

/* Turns every node of the unit on or off. */
void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active);

/* The three volume adders. Each takes a new node from the unit's vtable,
 * attaches it to mtx at ofs and links it at the end of nodes. They return
 * the node's id, or -1 when the unit has no type, no node is free or the
 * attach fails. The sphere and cylinder types are retail's:
 * AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf and
 * AddDamageCollCylinder__11cDamageUnitRC7cMatrixRC4cVecT2ff, with the
 * references as pointers. The box has no retail name and follows them. */
/* A box of size, turned by rot (cDamageNode_attachBox). */
int func_001FD9D8(cDamageUnit *self, const struct cMatrix *mtx, const cVec *ofs,
                  const cVec *rot, const cVec *size);
/* A sphere of radius (cDamageNode_attachSphere). */
int cDamageUnit_AddDamageCollSphere(cDamageUnit *self, const struct cMatrix *mtx,
                                    const cVec *ofs, float radius);
/* A cylinder of height and radius, turned by rot (cDamageNode_attachCylinder). */
int cDamageUnit_AddDamageCollCylinder(cDamageUnit *self, const struct cMatrix *mtx,
                                      const cVec *ofs, const cVec *rot,
                                      float height, float radius);

/* The three attaches the adders call: take a unit from the pool for the
 * node (a box, a sphere or a cylinder), store owner under key 1 of its key
 * table and start both position copies from the shape's position. They
 * return the node's id, or -1 when the pool is full. */
int cDamageNode_attachBox(cDamageNode *self, int group, const struct cMatrix *mtx, const cVec *ofs,
                          const cVec *rot, const cVec *size, cDamageUnit *owner);
int cDamageNode_attachSphere(cDamageNode *self, int group, const struct cMatrix *mtx, const cVec *ofs,
                             float radius, cDamageUnit *owner);
int cDamageNode_attachCylinder(cDamageNode *self, int group, const struct cMatrix *mtx, const cVec *ofs,
                               const cVec *rot, float height, float radius, cDamageUnit *owner);

#define CDAMAGE_TYPE_SPARE       0      /* type of a unit that isn't set up */
#define CDAMAGE_TYPE_GIVE        1
#define CDAMAGE_TYPE_TAKE        2
#define CDAMAGE_UNIT_NEWNODE     2      /* vt[2] of cDamageUnit returns a free node */

#endif
