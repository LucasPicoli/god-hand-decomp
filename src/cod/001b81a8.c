/* sn-2.95.3-136 matched TU. */

#include "godhand/cModel.h"
#include "godhand/cOmBase.h"
#include "godhand/CustomIDWork.h"

extern void func_00294898(void *a, void *self);
extern cMeshNode *cModel_getMeshPtr_14B730(void *self, void *name);
extern char D_005864F0[];
extern char D_00428AF0[];
extern void *SearchData(void *pack, void *name, int which);
extern int D_007474A0;
extern char D_0044B100[];
extern char *D_003C23A4;
extern void CustomIDWork_SetNumber(CustomIDWork *work, int number);
extern void CustomIDWork_setDispAllButEight(void *self, int id, int on);

/* An actor with two state bytes at 0x600 and a handle word at 0x608 past cOmBase. */
typedef struct MeshHideObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    char state0;                        /* 0x600 */
    char state1;                        /* 0x601 */
    char unk602[6];
    int handle;                         /* 0x608 */
} MeshHideObj;

/* Hide the actor, clear its two state bytes, then hide the mesh D_00428AF0 (CMODEL_NODE_HIDE) and clear the handle. Returns 1. */
__attribute__((section(".text.cObj_hideAndFlagMesh")))
int cObj_hideAndFlagMesh(MeshHideObj *self) {
    cMeshNode *mesh;
    int flags;
    func_001B6FB8(self);
    flags = self->base.objFlags;
    self->state0 = 0;
    self->state1 = 0;
    self->base.objFlags = flags | CMODEL_F_HIDDEN;
    func_00294898(D_005864F0, self);
    mesh = cModel_getMeshPtr_14B730(self, D_00428AF0);
    if (mesh != 0) {
        mesh->dispFlags |= CMODEL_NODE_HIDE;
    }
    self->handle = 0;
    return 1;
}

#define MSG_WIN_NUM  16

/* A message window as a node of the used and free lists. */
typedef struct MsgNode {
    unsigned short id;                  /* 0x00 */
    short val;                          /* 0x02 */
    struct MsgNode *prev;               /* 0x04 */
    struct MsgNode *next;               /* 0x08 */
    char unk0C[0xB0];
} MsgNode;                              /* 0xBC */

/* The window manager: list heads at 0x10 (used) and 0x14 (free), then the window pool. */
typedef struct MsgMgr {
    char unk00[0x10];
    MsgNode *used;                      /* 0x10 */
    MsgNode *freeList;                  /* 0x14 */
    MsgNode win[MSG_WIN_NUM];           /* 0x18 */
    short winOpen;                      /* 0xBD8 */
} MsgMgr;

#define WORLD_PACK(g)   (*(void **)((g) + 0x5AC))   /* the room data pack of D_007474A0 */
#define WORLD_ROOM(g)   (*(int *)((g) + 0x56C))

extern void func_002B22E8(MsgNode *node, MsgNode *prev, MsgNode *next, short val, unsigned short id);

/* Look up the message pack, chain the 16 windows into one free list and start with the first one free. */
__attribute__((section(".text.cMessage_initWinList")))
void cMessage_initWinList(MsgMgr *self) {
    MsgNode *node;
    MsgNode *next;
    char *g = (char *)&D_007474A0;
    int i;
    *(void **)(D_003C23A4 + 4) = SearchData(WORLD_PACK(g), D_0044B100, WORLD_ROOM(g));
    node = &self->win[0];
    for (i = MSG_WIN_NUM - 2; i >= 0; i--) {
        next = node + 1;
        func_002B22E8(node, 0, next, 0, 0);
        node = next;
    }
    func_002B22E8(next, 0, 0, 0, 0);
    self->freeList = &self->win[0];
    self->used = 0;
    self->winOpen = 1;
}

/* An ID screen with a number element at 0xFE0 and a count at 0x162C. */
typedef struct IdCountScreen {
    char unk000[0xFE0];
    CustomIDWork number;                /* 0xFE0 */
    char unk105C[0x5D0];
    int count;                          /* 0x162C */
} IdCountScreen;

#define ARROW_PREV  0x22
#define ARROW_NEXT  0x23

/* Show min(count, limit) in the number element and switch the two arrow displays by whether it is empty, at the limit, or in between. */
__attribute__((section(".text.CustomID_setArrowDisp")))
void CustomID_setArrowDisp(IdCountScreen *self, int limit) {
    int n = self->count;
    if (n >= limit) {
        n = limit;
    }
    CustomIDWork_SetNumber(&self->number, n);
    if (n <= 0) {
        CustomIDWork_setDispAllButEight(self, ARROW_PREV, 1);
        CustomIDWork_setDispAllButEight(self, ARROW_NEXT, 0);
    } else if (limit >= self->count) {
        CustomIDWork_setDispAllButEight(self, ARROW_PREV, 0);
        CustomIDWork_setDispAllButEight(self, ARROW_NEXT, 1);
    } else {
        CustomIDWork_setDispAllButEight(self, ARROW_PREV, 1);
        CustomIDWork_setDispAllButEight(self, ARROW_NEXT, 1);
    }
}
