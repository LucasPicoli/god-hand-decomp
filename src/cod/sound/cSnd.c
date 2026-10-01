/* TU: cSnd [sound] - recovered C++ class. */
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"
#define CSND_HIT(s) (*(cBgmHit **)((char *)(s) + 0x24))
extern int func_002CB3A8(void *a0, int a1);
extern void *cSnd_GetSeEntry(void *a0, int a1);
extern int cSeData_IsAlive(void *p);
extern int cSeData_IsFailed(void *p);
extern int D_0044CE48[];
extern void *cSnd_AllocVoice(void *a0);
extern int cSndSeVoice_StartAtOrigin(void *p, short a1, int a2, int a3, int a4, int a5, int a6);
extern void cSndBgmNode_FadeOut(int a0, float f12);
extern void cSndBgmNode_FadeIn(int a0, float f12);
extern int cSnd_FindBgmNode(int a0, int a1, int a2);
extern void cSndBgmNode_Release(int a0);
extern int cSnd_AllocBgmNode(int a0);
extern int cSnd_BgmNodeSet(int a0, int a1, int a2, int a3, unsigned int a4, int a5, int a6);
extern void cSndBgmNode_Resume(int a0);
extern int cSnd_BgmNodeStart(int a0, int a1, int a2, int a3, unsigned int a4, int a5, int a6);
extern void SetSequenceParam_373A18(int a0, int a1);

void cSndBgmNode_SetFlagsFadeOut(int, int, float);
void cSndBgmNode_FadeTo(int, float, float);
void UpdateSequenceNodeWeighted_373560(int, int, float);
float GetSequenceBlendWeight_373938(int, int);
void cSndBgmNode_FadeOut(int, float);
void cSndBgmNode_FadeIn(int, float);

/* Plays a sound-effect slot on a free voice, at the origin or, with a matrix, at that position. */
__attribute__((section(".text.cSnd_SeCall")))
int cSnd_SeCall(cSnd *self, int slot, short key1, int mtx, int idA, int idB)
{
    cSndSeVoice *voice;

    if (cSeData_IsAlive(cSnd_GetSeEntry(self, slot)) == 0)
        return 0;
    voice = cSnd_AllocVoice(self);
    if (voice == 0)
        return 0;
    if (mtx == 0)
        return cSndSeVoice_StartAtOrigin(voice, (short)slot, key1, (short)idA, (short)idB, 0, 0);
    return cSndSeVoice_BindMtx(voice, (short)slot, key1, mtx, idA, idB);
}

/* Finds the first emergency-pool slot whose entry is alive, belongs to this owner and is not busy. */
__attribute__((section(".text.cSnd_EmSeCheck")))
int cSnd_EmSeCheck(cSnd *self, int objId)
{
    int owner;
    int *slot;
    unsigned int i;
    cSndSeEntry *e;

    owner = func_002CB3A8(self, objId);
    if (owner <= 0)
        owner = objId;

    slot = D_0044CE48;
    i = 0;
    do {
        e = cSnd_GetSeEntry(self, *slot);
        if (cSeData_IsAlive(e) != 0) {
            e = cSnd_GetSeEntry(self, *slot);
            if (e->owner == owner) {
                e = cSnd_GetSeEntry(self, *slot);
                if (cSeData_IsFailed(e) != 1)
                    return *slot;
            }
        }
        i++;
        slot++;
    } while (i < 0xC);

    return -1;
}
/* Plays a sound-effect slot on a free voice at the origin, with an id pair and two extra arguments. */
__attribute__((section(".text.cSnd_SeCall_2CB8A0")))
int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6)
{
    cSndSeVoice *voice;

    if (cSeData_IsAlive(cSnd_GetSeEntry(self, slot)) == 0)
        return 0;
    voice = cSnd_AllocVoice(self);
    if (voice == 0)
        return 0;
    return cSndSeVoice_StartAtOrigin(voice, slot, key1, idA, idB, a5, a6);
}
/* Fades a playing sound out; -1 if there is no handle. */
__attribute__((section(".text.cSnd_SeFadeOut")))
int cSnd_SeFadeOut(cSnd *self, int handle, short fade)
{
    if (handle == 0)
        return -1;
    return func_00375050(handle, fade);
}


/* True once no voice holds this handle any more. */
__attribute__((section(".text.cSnd_SeEndCk")))
int cSnd_SeEndCk(cSnd *self, int handle)
{
    return cSnd_FindVoiceByHandle(self, handle) == 0;
}


/* Pause every node that has not finished by raising pause flag 0x100000. */
__attribute__((section(".text.cSnd_BattleBgmAllPause")))
void cSnd_BattleBgmAllPause(cSnd *self, float time)
{
    cSndBgmNode *node;
    for (node = self->bgmHead; node != 0; node = node->next) {
        if (node->state2 != 2)
            cSndBgmNode_SetFlagsFadeOut((int)node, 0x100000, time);
    }
}


/* Start bgm request reqNo on a free node (state 5, no limit). */
__attribute__((section(".text.cSnd_BgmEventSet")))
void cSnd_BgmEventSet(cSnd *self, int reqNo, int wordA, int wordB)
{
    int node;
    node = cSnd_AllocBgmNode((int)self);
    if (node != 0)
        cSnd_BgmNodeSet(node, 0, reqNo, 5, 0xFFFFFFFF, wordA, wordB);
}


extern void cSnd_BgmEventStop(cSnd *, int);

static __inline__ int nodeActive(cSndBgmNode *n)
{
    return (n->flags & 1) == 1;
}

/* Start bgm request reqNo: reuse its live node or claim a free one, then fade the rest. */
__attribute__((section(".text.cSnd_BgmEventStart")))
void cSnd_BgmEventStart(cSnd *self, int reqNo, int a2, int a3)
{
    cSndBgmNode *node = (cSndBgmNode *)cSnd_FindBgmNode(self, 0, reqNo);
    cSndBgmNode *other;
    int active;
    int *pin;

    if (node != 0 && (node->flags & 1) != 0) {
        cSndBgmNode_Resume(node);
    } else {
        node = cSnd_AllocBgmNode(self);
        if (node == 0) {
            cSnd_BgmEventStop(self, 0);
            return;
        }
        cSnd_BgmNodeStart(node, 0, reqNo, 5, 0xFFFFFFFF, a2, a3);
    }
    self->flagsB0 |= 0x10000000;
    self->flagsAC |= 0x10000000;
    if (node->started != 0)
        return;
    /* Taking the address of `active` keeps the constant 1 in a register for the test. */
    active = 1;
    for (other = self->bgmHead; other != 0; other = other->next) {
        if ((other->flags & 0x180000) == 0 && other != node && (other->flags & 1) != *(pin = &active)) {
            other->flags |= 0x1000;
            if (other->state2 != 2)
                cSndBgmNode_FadeOut(other, 10.0f);
        }
    }
}

/* Fade the node of request reqNo; a weight >= 0 also rescales its blend. */
__attribute__((section(".text.cSnd_BgmEventFade")))
void cSnd_BgmEventFade(cSnd *self, int reqNo, float time, float level, float weight)
{
    int node;
    node = cSnd_FindBgmNode((int)self, 0, reqNo);
    if (node != 0) {
        if (0.0f <= weight) {
            float w = GetSequenceBlendWeight_373938(node, 0);
            UpdateSequenceNodeWeighted_373560(node, -1, w * weight);
        }
        cSndBgmNode_FadeTo(node, level, time);
    }
}


/* Clear the event-running bit; stop event nodes unless keep is 1, pause-release the others. */
__attribute__((section(".text.cSnd_BgmEventStop")))
void cSnd_BgmEventStop(cSnd *self, int keep)
{
    cSndBgmNode *node;
    int flags;
    int rest;

    self->flagsB0 &= 0xEFFFFFFF;
    self->flagsAC &= 0xEFFFFFFF;
    for (node = self->bgmHead; node != 0; node = node->next) {
        if (node->state == 5) {
            if (keep != 1)
                cSndBgmNode_FadeOut((int)node, 0.0f);
        } else {
            flags = node->flags;
            if (flags & CSND_BGM_FLAG_PAUSE) {
                rest = flags & ~CSND_BGM_FLAG_PAUSE;
                node->flags = rest;
                if ((rest & 0x1FF00) == 0 && node->state2 != 2)
                    cSndBgmNode_FadeIn((int)node, 15.0f);
            }
        }
    }
}
/* Fade out the nodes of bank 1 that were started by request 0, then reset its data slot. */
__attribute__((section(".text.cSnd_BgmEvDataEnd")))
void cSnd_BgmEvDataEnd(cSnd *self)
{
    cSndBgmNode *node;
    int data;
    for (node = self->bgmHead; node != 0; node = node->next) {
        if (node->bank - 0x80 == 1)
            cSndBgmNode_FadeOut((int)node, 10.0f);
    }
    data = cSnd_GetBgmData((int)self, 1);
    cBgmData_Reset(data);
}


/* Drop the live node of request reqNo (if any) and start it again on a free node. */
__attribute__((section(".text.cSnd_BgmEvSet")))
int cSnd_BgmEvSet(cSnd *self, int bgmPt, int reqNo)
{
    int node;
    node = cSnd_FindBgmNode((int)self, bgmPt, reqNo);
    if (node != 0)
        cSndBgmNode_Release(node);
    node = cSnd_AllocBgmNode((int)self);
    if (node == 0)
        return 0;
    return cSnd_BgmNodeSet(node, bgmPt, reqNo, 4, 0xFFFFFFFFu, 0, 0) != 0;
}
/* Start request reqNo of bgm part bgmPt: re-arm its live node, or claim a free node for it. */
__attribute__((section(".text.cSnd_BgmEvStart")))
int cSnd_BgmEvStart(cSnd *self, int bgmPt, int reqNo, int param)
{
    cSndBgmNode *node;
    node = (cSndBgmNode *)cSnd_FindBgmNode((int)self, bgmPt, reqNo);
    if (node != 0) {
        if (node->flags & 1)
            cSndBgmNode_Resume((int)node);
        return 1;
    }
    node = (cSndBgmNode *)cSnd_AllocBgmNode((int)self);
    if (node == 0)
        return 0;
    if (cSnd_BgmNodeStart((int)node, bgmPt, reqNo, 4, 0xFFFFFFFFu, 0, 0) == 0)
        return 0;
    SetSequenceParam_373A18((int)node, param);
    return 1;
}
/* Pause the running nodes of one bgm request (every request when reqNo is -1). */
__attribute__((section(".text.cSnd_BgmEvPause")))
void cSnd_BgmEvPause(cSnd *self, int bgmPt, int reqNo)
{
    cSndBgmNode *node;
    for (node = self->bgmHead; node != 0; node = node->next) {
        if ((reqNo == -1 || ((node->bank - 0x80) == bgmPt && node->reqNo == reqNo)) &&
            node->state == 4)
            UpdateSequenceNodeSetFlag_373488((int)node);
    }
}


/* Restart the paused nodes of one bgm request; param >= 0 also sets the sequence parameter. */
__attribute__((section(".text.cSnd_BgmEvReStart")))
void cSnd_BgmEvReStart(cSnd *self, int bgmPt, int reqNo, int param)
{
    cSndBgmNode *node;
    for (node = self->bgmHead; node != 0; node = node->next) {
        if ((reqNo == -1 || ((node->bank - 0x80) == bgmPt && node->reqNo == reqNo)) &&
            node->state == 4) {
            cSndBgmNode_Resume((int)node);
            if (param >= 0)
                SetSequenceParam_373A18((int)node, param);
        }
    }
}
/* Suspend every node: flag it and fade it out over time. */
__attribute__((section(".text.cSnd_BgmEvAllSuspend")))
void cSnd_BgmEvAllSuspend(cSnd *self, float time)
{
    cSndBgmNode *node;
    for (node = self->bgmHead; node != 0; node = node->next) {
        node->flags |= CSND_BGM_FLAG_SUSPEND;
        cSndBgmNode_FadeOut((int)node, time);
    }
}


/* Release the suspend flag; a node with no other hold left is brought back over time. */
__attribute__((section(".text.cSnd_BgmEvAllSignal")))
void cSnd_BgmEvAllSignal(cSnd *self, float time)
{
    cSndBgmNode *node;
    int flags;
    int rest;
    for (node = self->bgmHead; node != 0; node = node->next) {
        flags = node->flags;
        if (flags & CSND_BGM_FLAG_SUSPEND) {
            rest = flags & ~CSND_BGM_FLAG_SUSPEND;
            node->flags = rest;
            if ((rest & 0x1FF00) == 0 && node->state2 != 2)
                cSndBgmNode_FadeIn((int)node, time);
        }
    }
}


/* fields cSnd.h does not name yet; see cSnd_fields.h */

extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern int cBgmData_IsReady(cBgmData *);
extern int cBgmData_IsEmpty(cBgmData *);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern int cSnd_BgmEvIsReady(cSnd *, int, int);
extern void cBgmData_Reset(cBgmData *);
extern int cBgmData_LoadNumbered(cBgmData *, int, int);

extern int func_003A5678(cBgmHit *, char *);
extern char D_0044D100[];

/* Set or clear the hit flag of the hit table entries whose id matches. */
__attribute__((section(".text.cSnd_BgmHitBeSet")))
void cSnd_BgmHitBeSet(cSnd *self, int on, unsigned short id)
{
    cBgmHitEnt *ent;
    unsigned int i;

    if (CSND_HIT(self) == 0)
        return;
    if (func_003A5678(CSND_HIT(self), D_0044D100) != 0)
        return;
    if (CSND_HIT(self)->version != 1.3f)
        return;
    if (CSND_HIT(self)->entNum == 0)
        return;
    ent = CSND_HIT(self)->ent;
    for (i = 0; i < CSND_HIT(self)->entNum; i++) {
        if (ent->id == id) {
            if (on == 1)
                ent->flags |= 1;
            else
                ent->flags &= 0xFE;
        }
        ent++;
    }
}
