/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

extern void cSndSeVoice_Release(cSndSeVoice *v, short a1, int a2);
extern void cSndSeVoice_Init(cSndSeVoice *v);
extern int cSeData_IsAlive(cSndSeEntry *e);

/* Stops a voice, then remembers its handle in the first free stop slot. */
__attribute__((section(".text.cSnd_SeStop")))
void cSnd_SeStop(cSnd *self, int handle)
{
    unsigned int i;
    if (handle == 0)
        return;
    func_00375050(handle, 5);
    i = 0;
    while (i < CSND_SE_STOP_NUM) {
        if (self->seStop[i] == 0) {
            self->seStop[i] = handle;
            break;
        }
        i++;
    }
}

/* Forwards a short and an int to every playing voice. */
__attribute__((section(".text.cSnd_SeVoiceCallAll")))
void cSnd_SeVoiceCallAll(cSnd *self, int a1, int a2)
{
    cSndSeVoice *v;
    for (v = self->voiceHead; v != 0; v = v->next)
        cSndSeVoice_Release(v, (short)a1, a2);
}

/* Claims the first unused voice in the pool and returns it, or 0 if all are busy. */
__attribute__((section(".text.cSnd_AllocVoice")))
cSndSeVoice *cSnd_AllocVoice(cSnd *self)
{
    int i;
    for (i = 0; i < CSND_VOICE_NUM; i++) {
        if (cSndSeVoice_IsActive(cSnd_GetVoice(self, i)) == 0) {
            cSndSeVoice_Init(cSnd_GetVoice(self, i));
            return cSnd_GetVoice(self, i);
        }
    }
    return 0;
}

/* Finds the sound-effect slot in 0x14..0x33 that is alive and plays this id, or -1.
   The id read keeps integer address arithmetic: the typed &seEntry[i] form swaps the addu operands. */
__attribute__((section(".text.cSnd_FindSeSlotById")))
int cSnd_FindSeSlotById(cSnd *self, int id)
{
    int i;
    for (i = 0x14; i < 0x34; i++) {
        if (cSeData_IsAlive(&self->seEntry[i]) == 1 && ((cSndSeEntry *)((int)self->seEntry + (i << CSND_SE_ENTRY_SHIFT)))->id == id)
            return i;
    }
    return -1;
}
