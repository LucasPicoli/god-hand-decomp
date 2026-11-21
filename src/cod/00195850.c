/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageManage.h"

extern void *Getplayer(void);
extern char D_00426F88[];
extern void SetField214PtrThenInit_1B6F38(void *self, void *a1);

/* Follow the hit position of a linked collision record: when the object has a
 * link (0x604) whose record (looked up with the key at 0x60C) has the type
 * bits 0x203 equal to 3, take the position from its shape (virtual call 8 on
 * the shape at 0x34 of the record, vtable at 0x100), copy it to 0x620, lower
 * the height by 2 and keep it at least 0.5 above the player's feet position
 * (virtual call 16). Returns the position at 0x620. Without a link return the
 * object's own virtual call 16. */
typedef struct VtEnt {
    short delta;                        /* added to the object before the call */
    short index;
    void *(*pfn)(void *self);
} VtEnt;

typedef struct VObj {
    char unk000[0x214];
    VtEnt *vt;                          /* 0x214 */
} VObj;

typedef struct ShapeRec {
    char unk000[0x100];
    VtEnt *vt;                          /* 0x100 */
} ShapeRec;

typedef struct HitRec {
    unsigned int type;                  /* 0x00 */
    char unk04[0x30];
    ShapeRec *shape;                    /* 0x34 */
} HitRec;

typedef struct FollowObj {
    char unk000[0x214];
    VtEnt *vt;                          /* 0x214 */
    char unk218[0x3EC];
    void *link;                         /* 0x604 */
    char unk608[4];
    int key;                            /* 0x60C */
    char unk610[0x10];
    float pos[3];                       /* 0x620 */
} FollowObj;

#define HIT_TYPE_MASK   0x203
#define HIT_TYPE_BOTH   0x3
#define VT_SHAPE_POS    8
#define VT_OBJ_POS      16
#define DROP_HEIGHT     2.0f
#define FLOOR_OFFSET    0.5f




__attribute__((section(".text.FollowObj_getHitPos")))
void *FollowObj_getHitPos(FollowObj *self)
{
    HitRec *hit;
    float *src;
    float *dst;
    float floor;
    if (self->link != 0) {
        hit = func_001FD8D8(self->link, self->key);
        if (hit != 0 && ((hit->type & HIT_TYPE_MASK) ^ HIT_TYPE_BOTH) == 0) {
            ShapeRec *shape = hit->shape;
            VtEnt *ent = &shape->vt[VT_SHAPE_POS];
            dst = self->pos;
            src = (float *)ent->pfn((char *)shape + ent->delta);
            if (dst != src) {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
            self->pos[1] = self->pos[1] - DROP_HEIGHT;
            floor = FLOOR_OFFSET;
            {
                VObj *pl = (VObj *)Getplayer();
                VtEnt *pe = &pl->vt[VT_OBJ_POS];
                src = (float *)pe->pfn((char *)pl + pe->delta);
            }
            if (self->pos[1] < src[1] + floor) {
                VObj *pl = (VObj *)Getplayer();
                VtEnt *pe = &pl->vt[VT_OBJ_POS];
                src = (float *)pe->pfn((char *)pl + pe->delta);
                self->pos[1] = src[1] + floor;
            }
            return dst;
        }
    }
    {
        VtEnt *e = &self->vt[VT_OBJ_POS];
        return e->pfn((char *)self + e->delta);
    }
}

/* Destructor of the object with vtable D_00426F88: set the vtable, release the
 * two owned objects at 0x600 and 0x604, then run the base destructor. */





typedef struct OwnerObj {
    char unk000[0x214];
    void *vt;                           /* 0x214 */
    char unk218[0x3E8];
    void *owned[2];                     /* 0x600 */
} OwnerObj;

__attribute__((section(".text.OwnerObj_destroyOwnedPair")))
void OwnerObj_destroyOwnedPair(OwnerObj *self, void *a1) {
    void **p = self->owned;
    int i;
    self->vt = D_00426F88;
    for (i = 1; i >= 0; i--, p++) {
        if (*p != 0) {
            ClearAndResetFields_1FE278(&D_00574380, *p);
            *p = 0;
        }
    }
    do { SetField214PtrThenInit_1B6F38(self, a1); } while (0);   /* loop note raises a1's reference count */
}
