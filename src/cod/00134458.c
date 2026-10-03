/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

extern char D_00462FC0[];
extern void cCollisionSolidManage_ReleaseUnit(void *manager, void *unit);
extern void cOmBase_dieCommon(void *obj);
extern void __builtin_delete(void *p);
extern cSndSeEntry *cSnd_GetSeData(cSnd *self, int idx);
extern int cSndSeVoice_CheckEnd(cSnd *self, int idx);
extern char D_0044EE38[];
extern unsigned short *cMessage_getMessageAddr(void *table, int id);

/* Destroy hook of the enemy class with vtable D_004481A8: release the collision unit, then the owned child object. */
typedef struct EnemyOwner {
    char unk000[0x15B0];
    void *child;                        /* 0x15B0 owned object, dies with its owner */
} EnemyOwner;





__attribute__((section(".text.func_0027BB30")))
void func_0027BB30(EnemyOwner *self)
{
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, self);
    if (self->child != 0) {
        cOmBase_dieCommon(self->child);
        self->child = 0;
    }
}

/* Deleting destructor of the node list holder: empty the list, then free the holder when the delete flag is set. */
typedef struct NodeList {
    int unk00;
    void *head;                         /* 0x04 first node */
} NodeList;

extern void func_001344A0(NodeList *self);


__attribute__((section(".text.func_00134458")))
void func_00134458(NodeList *self, int flags)
{
    func_001344A0(self);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

/* Check whether the sound slot has ended; a slot owned by an enemy object (id 0x200..0x2FF) takes the same check (two plain calls, so jump2 keeps both arms). */
__attribute__((section(".text.func_002CB340")))
void func_002CB340(cSnd *self, int slot)
{
    unsigned int owner = cSnd_GetSeData(self, slot)->owner;
    if (owner - 0x200 < 0x100) {
        cSndSeVoice_CheckEnd(self, slot);
    } else {
        cSndSeVoice_CheckEnd(self, slot);
    }
}

/* Destroy hook of the object with vtable D_0044EE38: hide and release the owned object, then run the base destroy. */
typedef struct OwnedObj {
    char unk000[0x250];
    unsigned int objFlags;              /* 0x250 */
} OwnedObj;

typedef struct HolderObj {
    char unk000[0xF0];
    void *vt;                           /* 0xF0 */
    char unkF4[0x1BC];
    OwnedObj *owned;                    /* 0x2B0 */
} HolderObj;

#define OBJ_F_HIDE  0x2                 /* objFlags bit 1 */


extern void ReleaseObj(OwnedObj *obj);
extern void func_002FBE28(HolderObj *self, int flag);

__attribute__((section(".text.func_002F27E8")))
void func_002F27E8(HolderObj *self, int flag)
{
    self->vt = D_0044EE38;
    if (self->owned != 0) {
        self->owned->objFlags |= OBJ_F_HIDE;
        ReleaseObj(self->owned);
    }
    func_002FBE28(self, flag);
}

/* 1 when the character code is one of the 10 codes listed in message 4, else 0. */
#define MESS_BREAK_LIST_ID   4
#define MESS_BREAK_LIST_NUM  10

extern void *D_003C23A4;                /* message table */


__attribute__((section(".text.func_002B0EB8")))
int func_002B0EB8(void *unused, unsigned short *code)
{
    unsigned short *list = cMessage_getMessageAddr(D_003C23A4, MESS_BREAK_LIST_ID);
    unsigned short c = *code;
    unsigned int i;
    for (i = 0; i < MESS_BREAK_LIST_NUM; i++) {
        if (c == list[i]) {
            return 1;
        }
    }
    return 0;
}
