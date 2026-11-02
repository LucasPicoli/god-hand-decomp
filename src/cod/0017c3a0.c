/* sn-2.95.3-136 matched TU. */

#include "godhand/CustomIDWork.h"
#include "godhand/cGameObj.h"
#include "godhand/cSnd.h"
#include "godhand/cScenario.h"

extern void CustomIDWork_SetMoveOffsetPosYSin(CustomIDWork *self, int amp, unsigned short frames);
extern void CustomIDWork_ResetMoveOffsetPos(CustomIDWork *self);
extern void SetCustomIDDispOneOrAll_1F29C0(void *self, int sel, int on);
extern void func_0017C028(void *self, int pos, void *rot);
extern int cSnd_SeFadeOut(cSnd *self, int handle, short fade);
extern char D_0044C2B8[];
extern char D_0044C2C0[];
extern cSnd D_005FEE00;
extern unsigned int D_00747A30;
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, int d, int e, int f, int g, int h);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, int a3, int t0, int t1, int t2);

/* Two CustomIDWork elements sit at 0x10D8 and 0x1154 of the owner. */
#define OWNER_IDW_A(self) ((CustomIDWork *)((char *)(self) + 0x10D8))
#define OWNER_IDW_B(self) ((CustomIDWork *)((char *)(self) + 0x1154))



/* CustomIDOwner_setBob: with sel set, start the 16-frame sine bob on both elements (-3 and +3); otherwise reset their offsets. */
__attribute__((section(".text.CustomIDOwner_setBob")))
void CustomIDOwner_setBob(void *self, int sel)
{
    if (sel != 0) {
        CustomIDWork_SetMoveOffsetPosYSin(OWNER_IDW_A(self), -3, 16);
        CustomIDWork_SetMoveOffsetPosYSin(OWNER_IDW_B(self), 3, 16);
    } else {
        CustomIDWork_ResetMoveOffsetPos(OWNER_IDW_A(self));
        CustomIDWork_ResetMoveOffsetPos(OWNER_IDW_B(self));
    }
}

typedef struct IdOwner {
    int flags;                 /* 0x000 bit 1: the ID display is shown */
    char unk04[0x91C];
    int unk920;                /* 0x920 */
    int unk924;                /* 0x924 */
} IdOwner;

/* CustomIDOwner_setShown: show or hide the ID display (flag bit 1) and clear the two 0x920 counters. */
__attribute__((section(".text.CustomIDOwner_setShown")))
void CustomIDOwner_setShown(IdOwner *self, int on)
{
    SetCustomIDDispOneOrAll_1F29C0(self, 2, on);
    self->unk920 = 0;
    self->unk924 = 0;
    if (on != 0) {
        self->flags |= 2;
    } else {
        self->flags &= ~2;
    }
}

/* cGameObj_setPosAndRefresh: store a new position in posA, copy it to the live position, then refresh the
 * pose from the live position and the rotation. */
__attribute__((section(".text.cGameObj_setPosAndRefresh")))
void cGameObj_setPosAndRefresh(cGameObj *self, cVec *pos)
{
    cVec_copy3(&self->posA, pos);
    cVec_copy3(self->pos, &self->posA);
    func_0017C028(self, (int)self->pos, &self->rot);
}

/* cSnd_SeFadeOutHeldVoices: fade out (10 frames) every voice whose bit 3 is set. */
__attribute__((section(".text.cSnd_SeFadeOutHeldVoices")))
void cSnd_SeFadeOutHeldVoices(cSnd *self)
{
    cSndSeVoice *v = self->voiceHead;
    unsigned long fl;
    unsigned long bit;
    long t;
    if (v != 0) {
        do {
            fl = v->flags;
            bit = fl >> 3;
            t = bit & 1;
            if (t != 0) {
                cSnd_SeFadeOut(self, v->handle, 10);
            }
            v = v->next;
        } while (v != 0);
    }
}

/* One row of the object-kind table: a 4-byte tag and the high byte pattern it answers to. */
typedef struct ScenarioKind {
    char tag[4];
    int kind;           /* matches objId & 0xFF00 */
} ScenarioKind;

extern ScenarioKind D_003C2F88[5];




/* cScenario_getStrFromObjId: write the name of an object id into buf, as the tag of its kind plus the
 * low byte, or the fallback string when no kind matches. Returns the writer's result. */
__attribute__((section(".text.cScenario_getStrFromObjId")))
int cScenario_getStrFromObjId(cScenario *self, char *buf, int objId)
{
    unsigned int i;
    for (i = 0; i < 5; i++) {
        if ((objId & 0xFF00) == D_003C2F88[i].kind) {
            return func_003A6C58(buf, D_0044C2B8, D_003C2F88[i].tag, objId & 0xFF);
        }
    }
    return func_003A6C58(buf, D_0044C2C0);
}

/* cSnd_SeCallGlobal: play a sound effect on the global sound manager unless bit 1 of D_00747A30 is set;
 * with a nonzero a3 it takes the fixed-voice call, otherwise the default-voice call. */
__attribute__((section(".text.cSnd_SeCallGlobal")))
void cSnd_SeCallGlobal(int unused, int id, short slot, int voice)
{
    unsigned long fl;
    unsigned long bit;
    long t;
    fl = D_00747A30;
    bit = fl >> 1;
    t = bit & 1;
    if (t == 0) {
        if (voice != 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, id, slot, voice, 0, 0, 0, 0);
        } else {
            cSnd_SeCall_2CB8A0(&D_005FEE00, id, slot, -1, -1, 0, 0);
        }
    }
}
