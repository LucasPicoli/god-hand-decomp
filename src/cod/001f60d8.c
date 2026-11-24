/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/globals.h"

extern void SlotList_selectPrev(void *self);
extern void func_001F6AF8(void *self);

#define POOLOBJ_FREE_MASK   0x201
#define POOLOBJ_FREE_VALUE  0x1
#define POOLOBJ_SUB_OFFSET  0xE0

typedef struct SubVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, int arg);
} SubVtEnt;

typedef struct SubVtEnt0 {
    short delta;
    short index;
    void (*pfn)(void *self);
} SubVtEnt0;

typedef struct SubVt {
    char unk00[0x38];
    SubVtEnt setA;                      /* 0x38 method 7 */
    char unk40[0x10];
    SubVtEnt0 setB;                     /* 0x50 method 10, takes no argument */
} SubVt;

typedef struct PoolVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, void *obj);
} PoolVtEnt;

typedef struct PoolVt {
    char unk00[0x30];
    PoolVtEnt release;                  /* 0x30 method 6 */
} PoolVt;

typedef struct Pool {
    char unk00[0x18];
    PoolVt *vt;                         /* 0x18 */
} Pool;

typedef struct PoolObj {
    unsigned int flags;                 /* 0x00 */
    char unk04[0x30];
    void *owner;                        /* 0x34 */
    char unk38[0xA8];
    int state;                          /* 0xE0 first word of the sub-object */
    char unkE4[0x1C];
    SubVt *subVt;                       /* 0x100 */
} PoolObj;


extern PoolObj *create(Pool *pool, int flag);
extern void func_002B8A70(PoolObj *obj, int arg);
extern PoolObj *cCollisionShape_construct(PoolObj *sub, int a, int b, int c);   /* returns this */

/* Takes a free object from the pool and builds it: base init, the embedded sub-object (method table D_0044BB20), state 4, the zeroed vectors at 0x1F0 and 0x200, then setter 7 with the last argument and method 10. When the taken record is not free it goes back through the pool's method 6. Returns the object, or 0. */
__attribute__((section(".text.Pool_createObjWithVt")))
PoolObj *Pool_createObjWithVt(Pool *pool, int arg, int a, int b, int c, int last)
{
    PoolObj *obj = create(pool, 4);
    PoolObj *sub;
    if (obj == 0) {
        return 0;
    }
    if (((obj->flags & POOLOBJ_FREE_MASK) ^ POOLOBJ_FREE_VALUE) != 0) {
        pool->vt->release.pfn((char *)pool + pool->vt->release.delta, obj);
        return 0;
    }
    func_002B8A70(obj, arg);
    sub = (PoolObj *)((char *)obj + POOLOBJ_SUB_OFFSET);
    cCollisionShape_construct(sub, a, b, c);
    sub->subVt = (SubVt *)D_0044BB20;
    VU0_SQC2_VF0(obj, 0x1F0);
    VU0_SQC2_VF0(obj, 0x200);
    obj->state = 4;
    sub->subVt->setA.pfn((char *)sub + sub->subVt->setA.delta, last);
    sub->subVt->setB.pfn((char *)sub + sub->subVt->setB.delta);
    obj->owner = sub;
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
