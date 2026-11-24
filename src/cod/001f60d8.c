/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cDamageUnit.h"
#include "godhand/vu0.h"
#include "godhand/globals.h"

extern void SlotList_selectPrev(void *self);
extern void func_001F6AF8(void *self);


/* Take a free unit from the pool and build a box in it: the group, the shape (vtable D_0044BB20), the two vectors at 0x110 and 0x120 of the shape cleared, state 4, then the size through the shape's method 7 and its method 10. A unit that isn't free goes back through the pool's method 6. Returns the unit, or 0. */
__attribute__((section(".text.Pool_createObjWithVt")))
cCollisionUnit *Pool_createObjWithVt(cCollisionManager *pool, int group, const struct cMatrix *mtx,
                                     const cVec *ofs, const cVec *rot, const cVec *size)
{
    cCollisionUnit *obj = create(pool, CCOLLISION_SHAPE_RECTBOX);
    cCollisionShape *shape;
    if (obj == 0) {
        return 0;
    }
    if (((obj->flags & COLL_UNIT_FLAGS_READY_MASK) ^ COLL_UNIT_FLAGS_READY) != 0) {
        ((void (*)(void *, cCollisionUnit *))pool->vt[CCOLLISION_MANAGER_RELEASE].pfn)(
            (char *)pool + pool->vt[CCOLLISION_MANAGER_RELEASE].delta, obj);
        return 0;
    }
    func_002B8A70(obj, group);
    shape = &obj->body;
    cCollisionShape_construct(shape, mtx, ofs, rot);
    shape->vt = D_0044BB20;
    VU0_SQC2_VF0(obj, 0x1F0);
    VU0_SQC2_VF0(obj, 0x200);
    shape->state = CCOLLISION_SHAPE_RECTBOX;
    ((void (*)(void *, const cVec *))shape->vt[CCOLLISION_SHAPE_SETSIZE].pfn)(
        (char *)shape + shape->vt[CCOLLISION_SHAPE_SETSIZE].delta, size);
    ((void (*)(void *))shape->vt[CCOLLISION_SHAPE_UPDATE].pfn)(
        (char *)shape + shape->vt[CCOLLISION_SHAPE_UPDATE].delta);
    obj->shape = shape;
    return obj;
}





#define PAD_PAGE_PREV   0x8000000L
#define PAD_PAGE_NEXT   0x4000000L
#define PAD_FIRST       0x2000000L
#define PAD_LAST        0x1000000L
#define PAD_PREV_ALT    (0x8000L << 21)
#define PAD_NEXT_ALT    (0x8000L << 25)
#define MENU_SE_MOVE    0x15F

/* A menu cursor: mode byte at 1, step bytes at 2 and 3, entry word at 0x20. */
typedef struct MenuCursor {
    char unk00;
    unsigned char mode;                 /* 0x01 */
    unsigned char step;                 /* 0x02 */
    unsigned char stepArg;              /* 0x03 */
    char unk04[0x1C];
    int entry;                          /* 0x20 */
} MenuCursor;

/* Menu pad step: page keys turn the page, first/last jump the cursor; each plays the move sound. */
__attribute__((section(".text.MenuInput_stepPageKeys")))
void MenuInput_stepPageKeys(MenuCursor *self)
{
    long b = D_00747650;

    if (b & PAD_PAGE_PREV) {
        SlotList_selectPrev(self);
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    } else if (b & PAD_PAGE_NEXT) {
        func_001F6AF8(self);
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    } else if (b & PAD_FIRST) {
        self->mode = 1;
        self->entry = 0;
        self->step = 0;
        self->stepArg = 0;
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    } else if (b & PAD_LAST) {
        self->mode = 2;
        self->step = 0;
        self->stepArg = 0;
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    } else if (b & PAD_PREV_ALT) {
        SlotList_selectPrev(self);
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    } else if (b & PAD_NEXT_ALT) {
        func_001F6AF8(self);
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
    }
}
