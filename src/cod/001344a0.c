/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cEm00.h"
#include "godhand/cEmSetParam.h"
#include "godhand/cTaskManager.h"
#include "godhand/cTaskWork.h"

extern int ClearField5B4IfFlagUnset_1B76B0(void *self);
extern void cDamageUnit_SetDamageCollActive(void *unit, int active);
extern void cModel_calcParts(void *self);
extern void func_001B6FB8(cOmBase *self);
extern void cOmBase_setMeshDispFromLayer(cOmBase *self, int layer, int hide);
extern int espSys_effDataRegist(void *table, int id, void *data);
extern char D_007419A0[];
extern cTaskManager D_00752C00;
extern void func_0013ED28(void *screen);
extern void func_0013EE58(void *screen);
extern void Forward2AAC28_13F070(void *screen);
extern void cTaskWork_exit(cTaskWork *task);
extern void cTaskWork_sleep(cTaskWork *task, int frames);

/* Per-frame update of an object with a hit record: clear the record and its collision, run the handler picked by the mode byte (one pointer-to-member record), rebuild the model parts and copy the live positions to the saved ones. */


#define OM_OFFSET_MODE  0x2F4           /* mode byte, read through the raw offset as retail does */
#define OM_MODE(s)      (*(unsigned char *)((s) + OM_OFFSET_MODE))

/* One pointer-to-member record, g++ 2.x layout: this adjust, vtable index (-1 for a plain function) and the vtable offset or function. */
typedef struct PhaseMemFn {
    short delta;
    short index;
    short vtOfs;
    short pad6;
} PhaseMemFn;

typedef struct { char b[8]; } PhaseTbl;

typedef struct cOmHitHolder {
    cOmBase base;
    char unk5E0[0x20];
    cDamageTake *take;                  /* 0x600 */
} cOmHitHolder;

extern PhaseTbl D_00429DD0;




__attribute__((section(".text.cOmBase_updateWithHitRecord")))
void cOmBase_updateWithHitRecord(cOmHitHolder *self)
{
    PhaseMemFn tbl[1];
    char *e;
    char *s0 = (char *)self;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0)
        return;
    if (self->take != 0) {
        self->take->kind = 0;
        self->take->power = 0;
        cDamageUnit_SetDamageCollActive(self->take, 0);
    }
    *(PhaseTbl *)tbl = D_00429DD0;
    i8 = OM_MODE(s0) * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[OM_MODE(s0)].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cModel_calcParts(self);
    cVec_copy3(&self->base.posA, self->base.pos);
    cVec_copy3(&self->base.posB, &self->base.posPrev);
}

/* Empty the node list: pop each node, run its virtual deleting destructor, count the node out. */
typedef struct VtEnt {
    short delta;
    short index;
    void *pfn;
} VtEnt;

typedef struct ListNode {
    struct ListNode *next;              /* 0x00 */
    char unk04[0x2C];
    VtEnt *vt;                          /* 0x30 */
} ListNode;

typedef struct NodeList {
    int unk00;
    int head;                           /* 0x04 first node (an address) */
} NodeList;

typedef struct NodeStats {
    int liveNodes;                      /* 0x00 */
} NodeStats;

extern NodeStats D_00460D18;

__attribute__((section(".text.NodeList_clear")))
void NodeList_clear(NodeList *self)
{
    if (self->head != 0) {
        do {
            ListNode *node = (ListNode *)self->head;
            int next = (int)node->next;
            if (node != 0) {
                ((void (*)(void *, int))node->vt[1].pfn)((char *)node + node->vt[1].delta, 3);
            }
            self->head = next;
            D_00460D18.liveNodes--;
        } while (self->head != 0);
    }
}

/* 1 when the enemy has no placement entry any more, or its entry is marked done. */
__attribute__((section(".text.cEmBase_checkDeadFlag")))
int cEmBase_checkDeadFlag(cEm00 *self)
{
    int entryNo = self->entryNo;
    cEmSetEntry *entry;
    int dead;
    if (entryNo == 0xFF) {
        return 0;
    }
    entry = cRoomSave_findEm(&D_005E8658, entryNo);
    if (entry == 0) {
        dead = 1;
    } else {
        dead = entry->done == EMSET_ENTRY_DONE;
    }
    return dead;
}

#define COMBASE_F2_BIT3  0x8            /* flags2 bit 3 */






/* Init of an object that owns effect data 0x241: base init, show layer 0, hide layer 0x40, register the data record. */
__attribute__((section(".text.cOmBase_initEffData241")))
int cOmBase_initEffData241(cOmBase *self)
{
    int res;
    func_001B6FB8(self);
    cOmBase_setMeshDispFromLayer(self, 0, 1);
    cOmBase_setMeshDispFromLayer(self, 0x40, 0);
    self->flags2 |= COMBASE_F2_BIT3;
    res = self->texKey;
    espSys_effDataRegist(D_007419A0, 0x241, (void *)(*(int *)(res + 0x10) + res));
    return 1;
}

#define NOWLOADING_SUB_OFFSET  0x3A0    /* the loading screen's record inside the game object */

extern char *D_003BD6E8;                /* game object */
extern unsigned char D_003C2554;        /* the loading task is running */
extern unsigned char D_003C2555;        /* the loading is finished */







/* Task body of the now-loading screen: set it up, then update and draw it every frame until the loading is finished, when the task exits. */
__attribute__((section(".text.cNowLoading_taskBody")))
void cNowLoading_taskBody(void)
{
    func_0013ED28(D_003BD6E8 + NOWLOADING_SUB_OFFSET);
    for (;;) {
        func_0013EE58(D_003BD6E8 + NOWLOADING_SUB_OFFSET);
        Forward2AAC28_13F070(D_003BD6E8 + NOWLOADING_SUB_OFFSET);
        if (D_003C2555 != 0 && D_003C2554 != 0) {
            D_003C2554 = 0;
            D_003C2555 = 0;
            cTaskWork_exit(D_00752C00.cur);
        }
        cTaskWork_sleep(D_00752C00.cur, 1);
    }
}
