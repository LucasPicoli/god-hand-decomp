/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmb2.h"
#include "godhand/cSnd.h"

extern void cOmSub_initMove1_pos(void *move, void *obj, int idx, int frames, cVec *pos, float a, float b);
extern void cOmSub_initMove3_y(void *move, void *obj, int idx, cVec *dir, float a, float b, float c);
extern int cOmSub_move(void *move);
extern void CustomIDWork_SetOffsetPosX(void *work, int x);
extern void CustomIDWork_SetMoveOffsetPosX(void *work, int from, int to, int frames);
extern void SetFlagOnEntries7C_1D51B8(void *obj, int entry, int on);
extern void CustomIDWork_ResetColorAnim(void *work);
extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *work, int from, int to, int frames);
extern void CustomIDWork_SetColorAnimNormal_2D6898(void *work, int color, int frames);
extern void CustomIDWork_SetNumber(void *work, int n);
extern void SetCustomIDDispOneOrAll_1F29C0(void *obj, int entry, int show);

#define SLIDE_FRAMES   0x1E             /* frames of the slide-in */
#define SLIDE_SE       0xBA             /* sound played when the slide starts */
#define SLIDE_EASE     0.2f
#define SLIDE_DECAY    (-0.02f)

typedef struct cOmb2Slide {
    cOmb2 base;                         /* 0x000 */
    char unk630[0x140];
    float slideY;                       /* 0x770 distance to slide along y */
    unsigned char done;                 /* 0x774 the slide has been played */
    unsigned char playing;              /* 0x775 */
    char unk776[2];
    int slideDown;                      /* 0x778 nonzero: slide the other way */
} cOmb2Slide;

/* Slide a door-like object once: phase 0 starts the move (straight in, or down when slideDown is set), plays the sound and goes to phase 1; phase 1 waits for the move to end, then marks it done and resets the state bytes. */
__attribute__((section(".text.cOmb2_updateSlide")))
void cOmb2_updateSlide(cOmb2Slide *self)
{
    cVec v;
    switch (self->base.base.phase) {
    case 0:
        if (self->done == 1) {
            return;
        }
        if (self->slideDown == 0) {
            v.x = 0.0f;
            v.y = self->slideY;
            v.z = 0.0f;
            v.w = 1.0f;
            cOmSub_initMove1_pos(self->base.move, self, -1, SLIDE_FRAMES, &v, SLIDE_EASE, SLIDE_EASE);
        } else {
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            v.w = 1.0f;
            cOmSub_initMove3_y(self->base.move, self, -1, &v, SLIDE_DECAY, -self->slideY, v.x);
        }
        cSnd_SeCall_2CB8A0(&D_005FEE00, 2, SLIDE_SE, -1, -1, 0, 0);
        self->base.base.step = 0;
        self->playing = 1;
        self->base.base.phase = 1;
        self->base.base.stepArg = 0;
        /* fallthrough */
    case 1:
        if (cOmSub_move(self->base.move) != 0) {
            return;
        }
        self->base.base.stepArg = 0;
        self->playing = 0;
        self->base.base.mode = 0;
        self->base.base.phase = 0;
        self->base.base.step = 0;
        self->done = 1;
        break;
    }
}

#define PANEL_WORK     0x6AC            /* the panel's CustomIDWork inside the object */
#define PANEL_HIDDEN_X (-0x140)         /* x offset with the panel slid out of view */
#define PANEL_SLIDE_FRAMES 0xA
#define PANEL_ENTRY_A  0xD              /* the three entry groups the panel switches */
#define PANEL_ENTRY_B  0xE
#define PANEL_ENTRY_C  0xF

/* Put the panel in one of four states: 0 slid out, 1 in with entry B shown, 2 sliding out with entry C shown, 3 sliding in with entries B and C shown (a mode of 0 or 4 and up is state 0). */
__attribute__((section(".text.IdPanel_setSlideState")))
void IdPanel_setSlideState(char *p, unsigned short mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(p + PANEL_WORK, PANEL_HIDDEN_X);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_A, 0);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_B, 0);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_C, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(p + PANEL_WORK, 0);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_A, 0);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_B, 1);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_C, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(p + PANEL_WORK, PANEL_HIDDEN_X, 0, PANEL_SLIDE_FRAMES);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_A, 0);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_B, 0);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_C, 1);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(p + PANEL_WORK, 0, PANEL_HIDDEN_X, PANEL_SLIDE_FRAMES);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_A, 0);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_B, 1);
    SetFlagOnEntries7C_1D51B8(p, PANEL_ENTRY_C, 1);
}

#define GLOW_WORK     0xEE8             /* the glow's CustomIDWork inside the object */
#define GLOW_ENTRY    0x1E              /* entry group the glow switches */

/* Set the three colour bytes of c to 0x80 one at a time. Retail keeps every step, so the result does not depend on c. */
#define GREY(c) (((((((c) & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080)

/* Set the glow state: 0 stops the colour animation and hides the entry group; 1 fades from the grey built from c2 to the grey built from c1 (flagged 0x40) over 2 frames and shows the group; 2 sets the grey built from c3 over 2 frames and shows it; any other mode does nothing. */
__attribute__((section(".text.IdGlow_setState")))
void IdGlow_setState(char *p, unsigned char mode, int c1, int c2, int c3)
{
    switch (mode) {
    case 0:
        CustomIDWork_ResetColorAnim(p + GLOW_WORK);
        SetFlagOnEntries7C_1D51B8(p, GLOW_ENTRY, 0);
        break;
    case 1:
        CustomIDWork_SetColorAnimNormal_2D68D8(p + GLOW_WORK,
            GREY(c2) & ~0xFF000000,
            (GREY(c1) & ~0xFF000000) | 0x40000000,
            2);
        SetFlagOnEntries7C_1D51B8(p, GLOW_ENTRY, 1);
        break;
    case 2:
        CustomIDWork_SetColorAnimNormal_2D6898(p + GLOW_WORK, GREY(c3) & ~0xFF000000, 2);
        SetFlagOnEntries7C_1D51B8(p, GLOW_ENTRY, 1);
        break;
    }
}

#define NUM_WORK_A     0x3C4            /* the three number works and the label work */
#define NUM_WORK_B     0x440
#define NUM_WORK_C     0x4BC
#define LABEL_WORK     0x538
#define NUM_LOW_MAX    10
#define COLOR_FRAMES   1

/* Set three numbers and switch the entries 7 to 10 on or off; when the flag is set, the first number is 0 and the second is below 10, tint the three number works and the label. The colour is built from an uninitialised stack word by mask steps that retail keeps, so it is always 0x8041268A. */
__attribute__((section(".text.IdNumbers_setAndTint")))
void IdNumbers_setAndTint(char *p, int show, int n0, int n1, int n2, int flag)
{
    int cbuf[1];
    int color;
    char *wa = p + NUM_WORK_A;
    char *wb;
    char *wc;
    CustomIDWork_SetNumber(wa, n0);
    wb = p + NUM_WORK_B;
    CustomIDWork_SetNumber(wb, n1);
    wc = p + NUM_WORK_C;
    CustomIDWork_SetNumber(wc, n2);
    SetCustomIDDispOneOrAll_1F29C0(p, 7, show);
    SetCustomIDDispOneOrAll_1F29C0(p, 8, show);
    SetCustomIDDispOneOrAll_1F29C0(p, 9, show);
    SetCustomIDDispOneOrAll_1F29C0(p, 0xA, show);
    if (flag != 0 && n0 == 0 && n1 < NUM_LOW_MAX) {
        color = (((((cbuf[0] & -0x100) | 0x8A) & ~0xFF00) | 0x2600) & 0x268A);
        color |= 0x410000;
        color |= 0x80000000;
        CustomIDWork_SetColorAnimNormal_2D6898(wa, color, COLOR_FRAMES);
        CustomIDWork_SetColorAnimNormal_2D6898(wb, color, COLOR_FRAMES);
        CustomIDWork_SetColorAnimNormal_2D6898(wc, color, COLOR_FRAMES);
        CustomIDWork_SetColorAnimNormal_2D6898(p + LABEL_WORK, color, COLOR_FRAMES);
    }
}
