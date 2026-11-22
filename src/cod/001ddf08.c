/* sn-2.95.3-136 matched TU. */

#include "godhand/cEma2.h"
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cSnd.h"
#include "godhand/cOmBase.h"
#include "godhand/CustomIDWork.h"

extern unsigned short D_00747A50;
extern cEma2 *cEmManage_findEma2Near(cEmManage *self, cVec *pos, float radius);
extern void cEm00_setGoto(cEm00 *self, cVec *pos, int a2, int a3, float f);
extern char D_0061B7C0[];
extern int D_0071B7C0[];
extern int D_0071B840[];
extern int D_0071B8C0[];
extern void func_003A52F0(void *a0, int a1, int a2);
extern void *func_002FACA8(int slot, int a1);
extern void cSndSeVoice_Stop(cSndSeVoice *voice);
extern void cSndBgmNode_FadeOut(cSndBgmNode *node, float time);
extern void cSndBgmNode_SetFlagsFadeOut(cSndBgmNode *node, int flags, float time);
extern void func_002CB070(cSnd *self);
extern float frand(float lo, float hi);
extern void CustomIDWork_SetLocalPosXY(CustomIDWork *work, int x, int y);
extern void SetCustomIDDispOneOrAll_1DD258(void *self, int entry, int on);
extern void CustomIDWork_SetOffsetPosX(CustomIDWork *work, int x);
extern void CustomIDWork_SetMoveOffsetPosX(CustomIDWork *work, int from, int to, int frames);
extern void CustomIDWork_ResetColorAnim(CustomIDWork *work);
extern void CustomIDWork_SetNoDisp(CustomIDWork *work, int hide);
extern void CustomIDWork_SetChildNoDisp(CustomIDWork *work, int hide);
extern void CustomIDWork_SetColorAnimNormal_2D6898(CustomIDWork *work, int color, unsigned short frames);

#define ROOM_ARENA        0x501       /* D_00747A50 value of the room where this applies */
#define EM_FLAG_16D8_ANY  0           /* unk16D8 must be nonzero */
#define EM_F1644_ARMED    0x10000
#define FIND_RADIUS       10.0f
#define GOTO_MODE         0x10
#define GOTO_SPEED        300.0f
#define MGR_WAIT          10
#define PHASE_GOTO        0x13

/* In the arena room, when no slide runs and the enemy is armed, finds a
 * second enemy within 10 units and, if the manager allows, sends this one
 * to its position. Returns 1 when the goto was set up. */
__attribute__((section(".text.cEm00_startGotoToNearEma2")))
int cEm00_startGotoToNearEma2(cEm00 *self)
{
    cEma2 *target;

    if (D_00747A50 != ROOM_ARENA)
        return 0;
    if (0.0f < self->slideTime)
        return 0;
    if (self->unk16D8 == 0)
        return 0;
    if ((self->flags1644 & EM_F1644_ARMED) == 0)
        return 0;
    target = cEmManage_findEma2Near(&D_005864F0, self->pos, FIND_RADIUS);
    if (target == 0)
        return 0;
    if (func_00294A68(&D_005864F0) != 0)
        return 0;
    D_005864F0.unk540 = MGR_WAIT;
    cEm00_setGoto(self, target->base.pos, GOTO_MODE, 0, GOTO_SPEED);
    self->mode = 0;
    self->step = 0;
    self->phase = PHASE_GOTO;
    self->stepArg = 0;
    return 1;
}

#define ESP_SLOT_NUM   0x400    /* slots in the pool */
#define ESP_SLOT_SIZE  0x400    /* bytes in each slot */

/* Takes the first free slot of the effect pool (lowest index first): clears
 * its 0x400 bytes, asks func_002FACA8 to set it up for `a0`, and on success
 * marks the slot used in the first bit table and clear in the other two.
 * Returns the slot's record, or 0 when no slot is free or setup failed (a
 * failed setup does not try the next slot). */
__attribute__((section(".text.PullEsp")))
void *PullEsp(int a0)
{
    int i;
    int w;
    unsigned int bit;
    void *r;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000 >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0) {
            func_003A52F0(D_0061B7C0 + i * ESP_SLOT_SIZE, 0, ESP_SLOT_SIZE);
            r = func_002FACA8(i, a0);
            if (r == 0)
                return 0;
            D_0071B7C0[w] |= bit;
            D_0071B840[w] &= ~bit;
            D_0071B8C0[w] &= ~bit;
            return r;
        }
    }
    return 0;
}

#define CSND_FLAG_ADD       0x800000      /* set in both flag words */
#define CSND_FLAG_DROP_A    0xFFDFFFFF    /* bits cleared in both flag words */
#define CSND_FLAG_DROP_B    0xFFEFFFFF
#define CSND_FLAG_DROP_C    0xFFF7FFFF
#define CSND_KEY_NUM        0x34
#define CSND_FADE_FRAMES    10
#define CSND_VOICE_LIVE     0x1           /* cSndSeVoice.flags bit 0: handle is live */
#define CSND_BGM_NODE_START_RAW 0x5F      /* two node bytes that mark a started node; unnamed in cSnd.h */
#define CSND_BGM_NODE_START2    0x61
#define CSND_BGM_FADE_BIT   0x10000
#define CSND_BGM_FLAG_FREE  0x100
#define CSND_BGM_FLAG_FADE  0x100000
#define CSND_BGM_FADE_TIME  20.0f
#define CSND_F128_RESET     (-2)
#define CSND_BGM_BYTE(node, off)  (*(unsigned char *)((char *)(node) + (off)))

/* Quiets the sound manager: sets one flag and clears three in both flag
 * words, fades every sound key, stops each voice whose handle is not live,
 * and walks the BGM nodes: a started or fade-flagged node is faded out and
 * marked to free, any other is flagged to fade out. Resets the state word at
 * 0x128 and runs func_002CB070. */
__attribute__((section(".text.cSnd_quietAll")))
void cSnd_quietAll(cSnd *self)
{
    short key;
    cSndSeVoice *voice;
    cSndBgmNode *node;
    unsigned int add = CSND_FLAG_ADD;
    unsigned int dropA = CSND_FLAG_DROP_A;
    unsigned int dropB = CSND_FLAG_DROP_B;
    unsigned int dropC = CSND_FLAG_DROP_C;

    self->flagsB0 = ((self->flagsB0 | add) & dropA & dropB & dropC);
    self->flagsAC = ((self->flagsAC | add) & dropA & dropB & dropC);
    key = 0;
    do {
        cSnd_SeFadeVoicesByKey(self, key, CSND_FADE_FRAMES);
        key = key + 1;
    } while (key < CSND_KEY_NUM);
    for (voice = self->voiceHead; voice != 0; voice = voice->next) {
        if ((voice->flags & CSND_VOICE_LIVE) == 0)
            cSndSeVoice_Stop(voice);
    }
    for (node = self->bgmHead; node != 0; node = node->next) {
        if (CSND_BGM_BYTE(node, CSND_BGM_NODE_START_RAW) != 0
            || CSND_BGM_BYTE(node, CSND_BGM_NODE_START2) != 0
            || (node->flags & CSND_BGM_FADE_BIT) != 0) {
            cSndBgmNode_FadeOut(node, CSND_BGM_FADE_TIME);
            node->flags = node->flags | CSND_BGM_FLAG_FREE;
        } else {
            cSndBgmNode_SetFlagsFadeOut(node, CSND_BGM_FLAG_FADE, CSND_BGM_FADE_TIME);
        }
    }
    self->f128 = CSND_F128_RESET;
    func_002CB070(self);
}

extern char *func_001F0498(void *owner, int obj, cVec *pos, float angle);     /* create one piece */
typedef struct { int w[5]; } ConfettiIds;
extern ConfettiIds D_0042BEE0;                /* the five piece objects to pick from */

#define CONFETTI_NUM    10
#define CONFETTI_KINDS  5
#define CONFETTI_SPREAD 10.0f           /* half the square */
#define CONFETTI_SPIN   3.14f           /* spin range is plus or minus this */

/* Throws 10 pieces, each a random one of five objects, from random spots in
 * a 20 by 20 square, each with a random spin. */
__attribute__((section(".text.ColiseumBattle_throwConfettiMixed")))
void ColiseumBattle_throwConfettiMixed(void *self)
{
    ConfettiIds ids;
    cVec pos;
    cVec *q = &pos;
    int i;

    ids = D_0042BEE0;
    for (i = CONFETTI_NUM - 1; i >= 0; i--) {
        int *slot = &ids.w[(int)frand(0.0f, (float)CONFETTI_KINDS)];
        float x = frand(-CONFETTI_SPREAD, CONFETTI_SPREAD);
        float z = frand(-CONFETTI_SPREAD, CONFETTI_SPREAD);

        pos.x = x;
        pos.y = 0.0f;
        pos.z = z;
        q->w = 1.0f;
        func_001F0498(self, *slot, q, frand(-CONFETTI_SPIN, CONFETTI_SPIN));
    }
}

typedef struct { int xy[5][2]; } PosTable;       /* five x, y pairs */
extern PosTable D_0042B628;                       /* positions of the first element, by kind */
extern PosTable D_0042B650;                       /* positions of the second element */

#define CARD_KIND_NUM    5
#define CARD_WORK_A      0x162C   /* two CustomIDWork records inside the owner, not typed yet */
#define CARD_WORK_B      0x16A8
#define CARD_DISP_A      0x2D
#define CARD_DISP_B      0x2E

/* Places the two elements of card display `kind` (0 to 4) from the position
 * tables and shows or hides both. Does nothing for a kind of 5 or more. */
__attribute__((section(".text.CustomIDOwner_placeCardKind")))
void CustomIDOwner_placeCardKind(void *self, unsigned char kind, int on)
{
    PosTable first;
    PosTable second;

    if (kind >= CARD_KIND_NUM)
        return;
    first = D_0042B628;
    second = D_0042B650;
    CustomIDWork_SetLocalPosXY((CustomIDWork *)((char *)self + CARD_WORK_A), second.xy[kind][0], second.xy[kind][1]);
    CustomIDWork_SetLocalPosXY((CustomIDWork *)((char *)self + CARD_WORK_B), first.xy[kind][0], first.xy[kind][1]);
    SetCustomIDDispOneOrAll_1DD258(self, CARD_DISP_A, on);
    SetCustomIDDispOneOrAll_1DD258(self, CARD_DISP_B, on);
}

#define PANEL_WORK(self)   ((CustomIDWork *)((char *)(self) + 0x980))   /* the owner is not typed yet */
#define PANEL_OFFSET_OUT   0x258    /* x offset of the panel when it is off screen */
#define PANEL_SLIDE_FRAMES 10
#define PANEL_COLOR_NORMAL 0x80000000
#define PANEL_COLOR_FRAMES 8

/* Puts the panel's ID element into one of four states: 1 shown at rest,
 * 2 sliding in from off screen, 3 shown with the normal colour, anything
 * else parked off screen and hidden. The parked arm is written first, with
 * an explicit case 0, so the compare tree is rooted at 1 as in retail. */
__attribute__((section(".text.CustomIDOwner_setPanelState")))
void CustomIDOwner_setPanelState(void *self, unsigned short mode)
{
    CustomIDWork *work;

    switch (mode) {
    default:
    case 0:
        work = PANEL_WORK(self);
        CustomIDWork_SetOffsetPosX(work, PANEL_OFFSET_OUT);
        CustomIDWork_ResetColorAnim(work);
        CustomIDWork_SetNoDisp(work, 1);
        CustomIDWork_SetChildNoDisp(work, 1);
        break;
    case 1:
        work = PANEL_WORK(self);
        CustomIDWork_SetOffsetPosX(work, 0);
        CustomIDWork_ResetColorAnim(work);
        CustomIDWork_SetNoDisp(work, 0);
        CustomIDWork_SetChildNoDisp(work, 0);
        break;
    case 2:
        work = PANEL_WORK(self);
        CustomIDWork_SetMoveOffsetPosX(work, PANEL_OFFSET_OUT, 0, PANEL_SLIDE_FRAMES);
        CustomIDWork_SetNoDisp(work, 0);
        CustomIDWork_SetChildNoDisp(work, 0);
        break;
    case 3:
        work = PANEL_WORK(self);
        CustomIDWork_SetColorAnimNormal_2D6898(work, PANEL_COLOR_NORMAL, PANEL_COLOR_FRAMES);
        CustomIDWork_SetNoDisp(work, 0);
        CustomIDWork_SetChildNoDisp(work, 0);
        break;
    }
}
