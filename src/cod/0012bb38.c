/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cEmManage.h"
#include "godhand/BlackJack.h"
#include "godhand/vu0.h"

extern int SetEffectParts(int kind, int id, void *owner, int part, float f12, float f13, float f14, float f15, int t0);
extern void KillEffect(void *owner, int id, int arg);
extern void cModel_calcParts(void *self);
extern void cModel_calcWorldParts(void *self);
extern cOmBase *Getplayer(void);
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(cOmBase *obj);
extern void func_002DB978(void);
extern void cActionButton_set(void *table, int kind, int lifeKind, int arg, void *callback, void *owner, int unused);
extern int D_00568288;
extern void CustomIDWork_SetOffsetPosX(void *work, int x);
extern void CustomIDWork_SetMoveOffsetPosX(void *work, int from, int to, int frames);
extern void SetFlagOnEntries7C_1D51B8(void *self, int entry, int on);
extern void ForwardVec3At30_147C60(void *dst, void *src);
extern void sceVu0ApplyMatrix(void *out, void *mtx, void *vec);
extern float LengthPositionToGivenLine(void *line, void *pos, void *dir, int *flag);

/* Keep effect 4 running while the object is in mode 1, phase 6 (read as one 64-bit state word); kill it when it leaves that state. */
#define FX_STATE_MASK    0xFFFF00000000L    /* mode (0x2F4) and phase (0x2F5) */
#define FX_STATE_ACTIVE  0x60100000000L     /* mode 1, phase 6 */
#define FX_F_RUNNING     0x40               /* fxFlags bit 6: effect 4 is running */
#define FX_ID            4

typedef struct FxObj {
    char unk000[0x2F0];
    long stateWord;                     /* 0x2F0 low word unknown, high word holds mode and phase */
    char unk2F8[0x12FC];
    int fxFlags;                        /* 0x15F4 */
} FxObj;




__attribute__((section(".text.FxObj_updateStateEffect")))
void FxObj_updateStateEffect(FxObj *self)
{
    if ((self->stateWord & FX_STATE_MASK) == FX_STATE_ACTIVE) {
        if ((self->fxFlags & FX_F_RUNNING) == 0) {
            self->fxFlags |= FX_F_RUNNING;
            SetEffectParts(0, FX_ID, self, 4, 0.0f, 0.0f, 0.0f, 1.0f, 4);
        }
    } else if ((self->fxFlags & FX_F_RUNNING) != 0) {
        self->fxFlags &= ~FX_F_RUNNING;
        KillEffect(self, FX_ID, 2);
    }
}

/* Run the handler picked by the phase byte (one pointer-to-member record per phase), then rebuild the model parts. */


/* One pointer-to-member record, g++ 2.x layout: this adjust, vtable index (-1 for a plain function) and the vtable offset or function. */
typedef struct PhaseMemFn {
    short delta;
    short index;
    short vtOfs;
    short pad6;
} PhaseMemFn;

typedef struct PhaseTbl {
    PhaseMemFn e[1];
} PhaseTbl;

extern PhaseTbl D_003BDC60;



__attribute__((section(".text.func_001ADD20")))
void func_001ADD20(cOmBase *self)
{
    char *s0 = (char *)self;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    i8 = self->phase * 8;
    e = (char *)&D_003BDC60 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDC60 + i8 + 4);
    }
    f0 = D_003BDC60.e[self->phase].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cModel_calcParts(self);
    cModel_calcWorldParts(self);
}

/* Show the action prompt of an object: only while the player is alive, its 0x15F4 bit 22 is clear and no slot wait is pending; prompt 8 when the target test passes, else prompt 7. */










/* The object that owns the prompt: its target pointer sits at 0xF0. */
typedef struct PromptOwner {
    char unk000[0xF0];
    void *target;                       /* 0xF0 */
} PromptOwner;

__attribute__((section(".text.PromptOwner_offerActionPrompt")))
void PromptOwner_offerActionPrompt(PromptOwner *owner)
{
    cOmBase *player = Getplayer();
    if (player->hp > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(player) == 0) {
            if (D_005864F0.slotWait <= 0) {
                if (owner != 0) {
                    if (func_002DB7E0(owner->target) != 0) {
                        cActionButton_set(&D_00568288, 8, 6, 0, (void *)func_002DB978, owner, 0);
                    } else {
                        cActionButton_set(&D_00568288, 7, 6, 0, (void *)func_002DB978, owner, 0);
                    }
                }
            }
        }
    }
}

/* Slide the blackjack panel by mode: 0 jumps it to -0x140, 1 to 0, 2 and 3 scroll it over 10 frames; then clear display entry 5 and show entry 6 for any mode but 0. */


#define BLACKJACK_PANEL_WORK  0x2CC     /* CustomIDWork of the panel inside the display entries */
#define PANEL_X_HIDDEN        (-0x140)
#define PANEL_SLIDE_FRAMES    0xA





__attribute__((section(".text.BlackJack_slidePanel")))
void BlackJack_slidePanel(BlackJack *self, unsigned short mode)
{
    int m = mode;
    if (m == 1) {
        goto slideIn;
    }
    if (m < 2) {
        goto hidden;
    }
    if (m == 2) {
        goto scrollOut;
    }
    if (m == 3) {
        goto scrollIn;
    }
hidden:
    CustomIDWork_SetOffsetPosX((char *)self + BLACKJACK_PANEL_WORK, PANEL_X_HIDDEN);
    goto done;
slideIn:
    CustomIDWork_SetOffsetPosX((char *)self + BLACKJACK_PANEL_WORK, 0);
    goto done;
scrollOut:
    CustomIDWork_SetMoveOffsetPosX((char *)self + BLACKJACK_PANEL_WORK, PANEL_X_HIDDEN, 0, PANEL_SLIDE_FRAMES);
    goto done;
scrollIn:
    CustomIDWork_SetMoveOffsetPosX((char *)self + BLACKJACK_PANEL_WORK, 0, PANEL_X_HIDDEN, PANEL_SLIDE_FRAMES);
done:
    SetFlagOnEntries7C_1D51B8(self, 5, 0);
    SetFlagOnEntries7C_1D51B8(self, 6, m != 0);
}

/* True when the distance from the line, taken from the matrix position along its turned (0, h, 0) offset, is at most k. */






__attribute__((section(".text.Mtx_checkLineDistance")))
int Mtx_checkLineDistance(void *mtx, void *line, float k, float h)
{
    char buf[0x40] __attribute__((aligned(16)));
    float *v;
    float *d;

    VU0_SQC2_VF0(buf, 0x0);
    v = (float *)(buf + 0x10);
    *(int *)(buf + 0x10) = 0;
    *(float *)(buf + 0x14) = h;
    *(int *)(buf + 0x18) = 0;
    v[3] = 1.0f;
    ForwardVec3At30_147C60(buf, mtx);
    d = (float *)(buf + 0x30);
    VU0_LQC2(4, v, 0x0);
    VU0_SQC2(4, buf, 0x30);
    sceVu0ApplyMatrix(d, mtx, d);
    VU0_LQC2(4, d, 0x0);
    VU0_SQC2(4, buf, 0x20);
    {
        float x = *(float *)(buf + 0x20);
        float y = *(float *)(buf + 0x24);
        float z = *(float *)(buf + 0x28);

        *(float *)(buf + 0x10) = x;
        *(float *)(buf + 0x14) = y;
        *(float *)(buf + 0x18) = z;
    }
    return LengthPositionToGivenLine(line, buf, v, 0) <= k;
}

/* Drop a probe line from half a unit above the point to 20 units below it; if it hits ground, return the hit height, else the point's own height. */



extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

#define PROBE_UP    0.5f
#define PROBE_DOWN  20.0f

#define FRAME ((char *)&from - 0x30)

__attribute__((section(".text.Pos_getGroundY")))
float Pos_getGroundY(cVec *pos)
{
    cVec from;
    cVec to;
    cVec hit;
    cVec *start = &from;
    float y;
    int one;

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    y = pos->y;
    /* x is stored through the frame, z and y through the pointer local: retail's address pseudo covers only those two. */
    if (start != pos) {
        from.x = pos->x;
        start->z = pos->z;
        start->y = y;
    }
    cVec_copy3(&to, pos);
    one = 1;
    from.y += PROBE_UP;
    to.y -= PROBE_DOWN;
    if (ChkLine(&from, &to, &hit, 0, 2, 0, 0, 0, 0, 0, 0, 0, one) == one) {
        y = hit.y;
    }
    return y;
}
