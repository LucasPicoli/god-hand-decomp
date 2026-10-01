/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cOmBase.h"

extern int D_00747A84;
extern char D_005E8658[];
extern char D_005CAE50[];
extern char D_00462FC0[];
extern void func_002BECB0(void *a0, long a1);
extern void func_001331B8(void *a0, long a1, int a2);
extern void cCollisionSolidManage_ReleaseUnit(void *a0, void *a1);
extern void func_001B7BB8(void *a0);
extern int *D_003C2384;
extern void cIDBase_clear(int a0);
extern void cIDBase_resetAnim(int a0);

/* Retire the object: unhide it, release its model and collision, drop its item and mark it gone. */
__attribute__((section(".text.SetField5B0Bit2ClearBit8_1B7908")))
void SetField5B0Bit2ClearBit8_1B7908(cOmBase *self) {
    long v = (unsigned int)self->flags2;
    if ((v >> 9 & 1) == 0) {
        if ((D_00747A84 & 0x01000000) == 0) {
            self->flags2 = self->flags2 & ~COMBASE_FLAG_HIDDEN;
        }
    }
    func_002BECB0(D_005E8658, self->unk538);
    func_001331B8(D_005CAE50, self->modelHandle, 0);
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, self);
    func_001B7BB8(self);
    self->flags0 = (self->flags0 | COMBASE_F0_GONE) & ~8;
}

struct node {
    char pad0[4];
    struct node *prev;   /* 0x4 */
    struct node *next;   /* 0x8 */
    int c;               /* 0xC */
    int d;               /* 0x10 */
};

__attribute__((section(".text.UnlinkAndCoalesceNode_2A9680")))
void UnlinkAndCoalesceNode_2A9680(int a0, struct node *a1) {
    struct node *p;
    struct node *q;
    if (a1 != 0) {
        p = (struct node *)((char *)a1 - 0x20);
        q = p->prev;
        q->next = p->next;
        q->c = q->c + (p->d + p->c);
        p = p->next;
        if (p != 0) {
            p->prev = q;
        }
    }
}

/* Set or clear display flag bit 13 on every mesh node of one layer. */
__attribute__((section(".text.SetField380Bit2000ForTag_1B7300")))
void SetField380Bit2000ForTag_1B7300(void *model, int layer, int clear) {
    cMeshNode *node = (cMeshNode *)cModel_getMeshPtr(model, 0);
    if (node != 0) {
        do {
            if (node->layer == layer) {
                unsigned int v;
                if (clear == 1) {
                    v = node->dispFlags & 0xFFFFDFFF;
                } else {
                    v = node->dispFlags | 0x2000;
                }
                node->dispFlags = v;
            }
            node = node->next;
        } while (node != 0);
    }
}
