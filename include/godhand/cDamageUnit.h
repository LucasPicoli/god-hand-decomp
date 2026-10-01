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

typedef struct cDamageUnit {
    char unk00[0x3C];
    cDamageNode *nodes;         /* 0x3C list head, 0 when empty */
} cDamageUnit;

#define CDAMAGE_SHAPE_SETRADIUS  3      /* vt[3] of cCollisionShape */

#endif
