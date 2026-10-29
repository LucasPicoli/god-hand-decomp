/* sn-2.95.3-136 matched TU. */

#include "godhand/cDoor.h"

extern void cDoor_setDoorJump(cDoor *self);
extern char D_00586AF0[];
extern int cEvent_getObjPtr(void *event, unsigned short kind, unsigned char no);

extern unsigned short D_00747A50;               /* room id the player is in */


/* A jump point equal to the current room id means none (0xFFFF). */
static __inline__ unsigned short cDoor_pointId(unsigned short id)
{
    if (id == D_00747A50)
        return 0xFFFF;
    return id;
}

/* Aim a door jump: set the landing point (position, heading, jump point id
 * and arguments) and start it. */
__attribute__((section(".text.cDoor_aimJump")))
void cDoor_aimJump(cDoor *self, unsigned short id, float *pos, float angle,
                   unsigned char arg, int arg2, unsigned char doorArg)
{
    self->point[0].id = cDoor_pointId(id);
    self->point[0].pos[0] = pos[0];
    self->point[0].pos[1] = pos[1];
    self->point[0].pos[2] = pos[2];
    self->point[0].angle = angle;
    self->point[0].kind = CDOOR_NO_KIND;
    self->point[0].arg = arg;
    self->point[0].arg2 = arg2;
    self->unk3A = doorArg;
    cDoor_setDoorJump(self);
}

#define NODE_FLAGS_KEEP  0xFFFFF9FC     /* clears bits 0, 1, 9 and 10 */
#define NODE_FREE_SIZE   0xC

/* A node: flag word at 0 and method table pointer at 8. */
typedef struct Node {
    unsigned int flags;                 /* 0x00 */
    int unk04;
    void *vt;                           /* 0x08 */
} Node;

extern char D_0042C320[];               /* method table of the base node */
extern void NoOp_1F7D18(Node *self, int size);

/* Destructor: reset the method table and clear the state bits; with bit 0
 * of flags set, hand the node back (size 0xC). */
__attribute__((section(".text.Node_dtor")))
void Node_dtor(Node *self, int flags)
{
    self->vt = D_0042C320;
    self->flags &= NODE_FLAGS_KEEP;
    if (flags & 1)
        NoOp_1F7D18(self, NODE_FREE_SIZE);
}

#define EVENT_KIND_A        0x605       /* kind whose objects may also be kind 0x600 */
#define EVENT_KIND_A_ALT    0x600
#define EVENT_KIND_B        0x3D6       /* kind whose objects may also be kind 0x668 */
#define EVENT_KIND_B_ALT    0x668




/* Look the object up under its kind, then under the alternate kind. */
static __inline__ int lookupWithFallback(unsigned char no, unsigned short kind, unsigned short alt)
{
    int obj = cEvent_getObjPtr(D_00586AF0, kind, no);

    if (obj != 0)
        return obj;
    return cEvent_getObjPtr(D_00586AF0, alt, no);
}

/* Find an event object from a packed id (kind in the high half, number in
 * the low byte). Kinds 0x605 and 0x3D6 fall back to their alternate kind
 * when the first lookup finds nothing. Returns 0 for a zero kind. */
__attribute__((section(".text.getEventObjPtr")))
int getEventObjPtr(unsigned int id)
{
    unsigned int kind = id >> 16;

    if (kind == 0)
        return 0;
    if (kind == EVENT_KIND_A)
        return lookupWithFallback(id, EVENT_KIND_A, EVENT_KIND_A_ALT);
    if (kind == EVENT_KIND_B)
        return lookupWithFallback(id, EVENT_KIND_B, EVENT_KIND_B_ALT);
    return cEvent_getObjPtr(D_00586AF0, kind, id & 0xFF);
}
