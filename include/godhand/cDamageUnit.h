/* include/godhand/cDamageUnit.h - cDamageUnit, the damage hit volumes of one actor.
 *
 * The unit keeps a singly linked list of nodes at 0x3C. Each node carries a
 * numeric id and points at a data record whose word at 0x34 is the
 * cCollisionShape. Methods walk the list and either touch every node
 * (SetDamageCollActive, SetDamageCollOffset) or look one up by id
 * (SetDamageCollRadius). The shape's virtual call uses the g++ 2.x
 * delta/index/pfn table entry. Offsets are exact; unknown spans stay unkNNN.
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

typedef struct cCollisionShape {
    char unk000[0x100];
    cDamageVtEnt *vt;           /* 0x100 */
} cCollisionShape;

typedef struct cDamageData {
    int flags;                  /* 0x00 bit 1 = active */
    char unk04[0x30];
    cCollisionShape *shape;     /* 0x34 */
} cDamageData;

typedef struct cDamageNode {
    char unk00[0x24];
    struct cDamageNode *next;   /* 0x24 */
    cDamageData *data;          /* 0x28 */
    short id;                   /* 0x2C */
} cDamageNode;

/* The fields a give (cDamageGive, 0x60 bytes) and a take (cDamageTake, 0x70
 * bytes) share, 0x00..0x4F: the cDamageUnit head both derive from (the type
 * info registers 11cDamageUnit before 11cDamageGive and 11cDamageTake). The manager runs the same code on both kinds:
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
    signed char type;           /* 0x49 1 or 2, by the record's setup */        \
    unsigned char live;         /* 0x4A in use */                               \
    char unk4B;                                                                 \
    int power                   /* 0x4C hit strength, 0 when parked */

/* The head a give and a take share. */
typedef struct cDamageUnit {
    CDAMAGE_UNIT_FIELDS;
} cDamageUnit;                  /* 0x50 */

typedef char cDamageUnit_size_check[(sizeof(cDamageUnit) == 0x50) ? 1 : -1];

/* A take record: what cDamageManage_CreateDamageTake returns and
 * cOmBase_checkDamage (checkDamage__7cOmBaseP11cDamageTake) tests. */
typedef struct cDamageTake {
    CDAMAGE_UNIT_FIELDS;
    char unk50[0x60 - 0x50];
    unsigned int hitFlags;      /* 0x60 bit 0 must be set for the hit to count */
    char unk64[0x70 - 0x64];
} cDamageTake;                  /* 0x70: the manager's take array has a 0x70 stride */

typedef char cDamageTake_size_check[(sizeof(cDamageTake) == 0x70) ? 1 : -1];

/* Turns every node of the unit on or off. */
void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active);

#define CDAMAGE_SHAPE_SETRADIUS  3      /* vt[3] of cCollisionShape */

#endif
