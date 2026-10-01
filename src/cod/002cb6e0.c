/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

extern int FindActiveSlot_2CC050(cSnd *self);
extern cSndSeEntry *GetIndexedEntry_2CC4B8(cSnd *self, int idx);
extern void cSnd_SeVoiceCallAll(cSnd *self, int idx, int flag);
extern void func_002CE430(cSndSeVoice *v);
extern void func_002CD890(cSndMemHeap *parent, int addr);

/* Returns the slot already playing this id; failing that, claims an active slot for it. -1 if none. */
__attribute__((section(".text.cSnd_ReserveSeSlot")))
int cSnd_ReserveSeSlot(cSnd *self, int id)
{
    int slot;
    slot = cSnd_FindSeSlotById(self, id);
    if (slot != -1)
        return slot;
    slot = FindActiveSlot_2CC050(self);
    if (slot != -1) {
        if (cSeData_LoadFromBuf(GetIndexedEntry_2CC4B8(self, slot), slot, id, 0x7FFFFFFF) == 0)
            return -1;
    }
    return slot;
}

/* Marks slot idx, then asks the slot's entry whether it has finished.
   The empty loop is a statement barrier: without it sched2 emits the two argument
   moves in the other order and the delay slot takes the wrong one. */
__attribute__((section(".text.cSndSeVoice_CheckEnd")))
int cSndSeVoice_CheckEnd(cSnd *self, int idx)
{
    cSnd_SeVoiceCallAll(self, idx, 1);
    do { } while (0);
    return func_002CFC98(GetIndexedEntry_2CC4B8(self, idx));
}

/* Fades out every voice with this key, or releases it if it has no live handle.
   The 1 is declared inside the loop: that placement keeps it in a register across the loop, as retail does. */
__attribute__((section(".text.cSnd_SeFadeVoicesByKey")))
void cSnd_SeFadeVoicesByKey(cSnd *self, short key, short fade)
{
    cSndSeVoice *v;
    for (v = self->voiceHead; v != 0; v = v->next) {
        int one = 1;
        if (v->key0 != key)
            continue;
        if ((v->flags & 1) == one)
            func_00375050(v->handle, fade);
        else
            func_002CE430(v);
    }
}

/* Shuts a heap down: gives its chunk back to the parent if it has one and marks it unused. */
__attribute__((section(".text.cSndMemHeap_Close")))
void cSndMemHeap_Close(cSndMemHeap *heap)
{
    if (heap->self != 0) {
        if (heap->base != 0)
            func_002CD890(heap->parent, heap->base);
        heap->self = 0;
    }
}
