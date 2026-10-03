/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"
#include "godhand/cDataManager.h"

extern cSndSeVoice *cSnd_GetVoice(cSnd *self, int idx);
extern void cSndSeVoice_Init(cSndSeVoice *voice);
extern void *cSnd_GetSeData(cSnd *self, int idx);
extern void cSeData_Release(void *data);
extern void cSndBgmNode_Init(cSndBgmNode *node);
extern cBgmData *cSnd_GetBgmData(cSnd *self, int idx);
extern void cBgmData_Reset(cBgmData *data);

/* Reset the whole sound manager: drop the playing-voice list and re-init all 0x40 voices, release all 0x34 sound-effect slots, drop the BGM node list and re-init all 0x10 nodes, and reset both BGM data records. */



#define CSND_BGM_DATA_NUM  2










__attribute__((section(".text.cSnd_resetAll")))
void cSnd_resetAll(cSnd *self)
{
    int i;
    self->voiceHead = 0;
    for (i = 0; i < CSND_VOICE_NUM; i++)
        cSndSeVoice_Init(cSnd_GetVoice(self, i));
    for (i = 0; i < CSND_SE_ENTRY_NUM; i++)
        cSeData_Release(cSnd_GetSeData(self, i));
    self->bgmHead = 0;
    for (i = 0; i < CSND_BGM_NODE_NUM; i++)
        cSndBgmNode_Init(func_002D2DB0(self, i));
    for (i = 0; i < CSND_BGM_DATA_NUM; i++)
        cBgmData_Reset(cSnd_GetBgmData(self, i));
}

/* Count the slots whose load has finished (state ready). */


__attribute__((section(".text.cDataManager_countReady")))
int cDataManager_countReady(cDataManager *self)
{
    int count = 0;
    int i;
    cDataSlot *base = self->slot;
    for (i = 0; i < self->slotNum; i++) {
        if (UpdateStateReady_1FF238(&base[i]) == 1)
            count++;
    }
    return count;
}

/* Kind of the nth ready slot (counting ready slots only), or 0xFFFF when there are fewer than n + 1. */


__attribute__((section(".text.cDataManager_getReadyKind")))
int cDataManager_getReadyKind(cDataManager *self, int n)
{
    int count = 0;
    int i;
    cDataSlot *base = self->slot;
    for (i = 0; i < self->slotNum; i++) {
        if (UpdateStateReady_1FF238(&base[i]) == 1) {
            if (count == n)
                return base[i].kind;
            count++;
        }
    }
    return 0xFFFF;
}
