/* sn-2.95.3-136 matched TU. */
/* This TU declares the constructor cObjBase (DispMgr.h reaches cObjBase.h through cObjSimple.h). */
#define COBJBASE_NO_TYPEDEF
#include "godhand/objFactory.h"
#include "godhand/DispMgr.h"
#include "godhand/globals.h"

extern void cIDBase_initialize(void *a0, int a1, int a2);
extern void func_002B2580(char *self);
extern void cSndSeTrack_switchSoundData(char *self);
extern int D_00747A34;
extern char D_00754C10[];
extern void *_MemoryAlloc(int size, int align, void *region);
extern void func_003A52F0(void *dst, int val, int len);
extern void cObjBase(void *a0);

/* Slot1 end-of-game stage: on the first call run the end hook, then flag the game as over. */
#define SLOT_STEP(s)     (*(int *)((s) + 0x08))
#define SLOT_END_FLAG(s) (*(unsigned int *)((s) + 0x54))




__attribute__((section(".text.Slot1_endGameStep")))
void Slot1_endGameStep(char *self) {
    switch (SLOT_STEP(self)) {
    case 0:
        func_00143A90(&Cockpit->gold);
        SLOT_STEP(self)++;
        /* fallthrough */
    case 1:
        SLOT_END_FLAG(self) |= 1;
        break;
    }
}

/* Set up the count display, cache its two entries in ent and forget the ticket. */



__attribute__((section(".text.InitTwoIdWorks")))
void InitTwoIdWorks(cCockItem *self) {
    unsigned short i;
    cIDBase_initialize(self, 1, 0x1F);
    i = 0;
    do {
        self->ent[i] = cIDBase_getIDWork(&self->base, i);
        i = i + 1;
    } while (i < COCKITEM_ENT_NUM);
    self->ticket = 0;
}

/* PLAY stage of a two-phase scene: start it on phase 0, step it until it ends, then fall back to the next stage. */




__attribute__((section(".text.UpdatePlayStage")))
int UpdatePlayStage(char *self) {
    int ret;
    switch (*(unsigned char *)(self + 0xD)) {
    case 0:
        func_002B2580(self);
        *(unsigned char *)(self + 0xD) = *(unsigned char *)(self + 0xD) + 1;
    case 1:
        if (ScriptRun_runChannel(self)) {
            cSndSeTrack_switchSoundData(self);
            ret = 1;
            *(unsigned char *)(self + 0xF) = 0;
            *(unsigned char *)(self + 0xD) = 0;
            *(unsigned char *)(self + 0xE) = 0;
            *(unsigned char *)(self + 0xC) = ret;
            return ret;
        }
        return 0;
    }
}

/* Allocate and zero a 0x4E0-byte object, run the base constructor and set its vtable pointer; 0 if the allocator is locked or full. */







__attribute__((section(".text.CreateObjectWithVtableA")))
void *CreateObjectWithVtableA(void) {
    char *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x4E0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x4E0);
    cObjBase(s0);
    *(int **)(s0 + 0x214) = &D_0044B840;
    return s0;
}

/* Allocate and zero a 0x4D0-byte object, run the base constructor and set its vtable pointer; 0 if the allocator is locked or full. */







__attribute__((section(".text.CreateObjectWithVtableB")))
void *CreateObjectWithVtableB(void) {
    char *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x4D0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x4D0);
    cObjBase(s0);
    *(int **)(s0 + 0x214) = &D_00450B98;
    return s0;
}
