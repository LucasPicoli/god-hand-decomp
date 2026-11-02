/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/cScenario.h"
#include "godhand/cSceAtManager.h"

extern void StoreVecFromFieldB0_2B6160(cVec *dst, void *obj);
extern void cNode_setLocalTranslation(void *self, cVec *v);
extern int ChkLine(cVec *from, cVec *to, cVec *hit, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
extern int D_007474A0;
extern int D_00747A2C;
extern cSceAtManager D_005FEA60;
extern char D_00568288[];
extern char *Getplayer(void);
extern void func_001F7360(void *p);

#define DROP_UP        1.0f
#define DROP_DEFAULT   10.0f        /* probe depth when the data record gives none */

/* The record a node reads its probe settings from. */
typedef struct ProbeData {
    char unk000[0x140];
    float lift;                 /* 0x140 added to the hit height */
    float depth;                /* 0x144 probe depth, 0 for the default */
} ProbeData;

/* A node with a method table at 0xF0 (index 10 is its refresh hook). */
typedef struct ProbeVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self);
} ProbeVtEnt;

typedef struct ProbeNode {
    char unk000[0xF0];
    ProbeVtEnt *vt;             /* 0xF0 */
    char unkF4[0x1C];
    ProbeData *data;            /* 0x110 */
} ProbeNode;

/* The probe depth, or the default when the record gives none. A helper keeps the loaded value and the result in
 * separate registers, as retail has them. */
static __inline__ float probeDepth(float v)
{
    if (v == 0.0f)
        return DROP_DEFAULT;
    return v;
}

/* The frame holds ChkLine's 0x30 bytes of outgoing arguments first; the vectors sit above them. */
#define FRAME ((char *)&pos - 0x30)

/* Refresh the node, then drop it onto the ground: cast a line from 1 above its position down by the probe depth plus
 * 1, and put the node at the hit point lifted by the data record's lift, or back at its own position on a miss.
 * Returns 1. */
__attribute__((section(".text.ProbeNode_dropToGround")))
int ProbeNode_dropToGround(ProbeNode *self)
{
    cVec pos;                           /* sp+0x30 */
    cVec from;                          /* sp+0x40 */
    cVec to;                            /* sp+0x50 */
    cVec hit;                           /* sp+0x60 */
    float depth;

    depth = probeDepth(self->data->depth);
    self->vt[10].pfn((char *)self + self->vt[10].delta);
    StoreVecFromFieldB0_2B6160(&pos, self);
    VU0_LQC2(4, &pos, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_LQC2(4, &pos, 0);
    VU0_SQC2(4, FRAME, 0x50);
    VU0_SQC2_VF0(FRAME, 0x60);
    from.y += DROP_UP;
    to.y -= depth + DROP_UP;
    if (ChkLine(&from, &to, &hit, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
        hit.y += self->data->lift;
    } else {
        cVec_copy3(&hit, &pos);
    }
    cNode_setLocalTranslation(self, &hit);
    return 1;
}

/* The script hook the scenario calls once a frame (field 0x104, not named in cScenario.h). */
#define SCENARIO_HOOK(s)  (*(void (**)(void))((char *)(s) + 0x104))

__attribute__((section(".text.cScenario_moveFrame")))
/* Every frame: track the player's death as cScenario_move does, then, unless the game is paused, reset the cursor
 * (unless a soft event runs), call the script hook and tick the screen object. */
void cScenario_moveFrame(cScenario *self)
{
    char *g = (char *)&D_007474A0;

    if (*(unsigned short *)(g + 0x5B0) != 0x20) {
        if (Getplayer() != 0) {
            long t = (unsigned int)self->task.flags;
            if (((t >> 1) & 1) == 0) {
                if (*(short *)(Getplayer() + 0x54A) <= 0) {
                    *(int *)&self->task.flags = self->task.flags | SCENARIO_F_PL_DEAD;
                    cScenario_endMess(D_003C2F84);
                    *(int *)(g + 0x5E0) = *(int *)(g + 0x5E0) | 0x100000;
                }
            } else {
                if (*(short *)(Getplayer() + 0x54A) > 0) {
                    self->task.flags = self->task.flags & ~SCENARIO_F_PL_DEAD;
                    *(int *)(g + 0x5E0) = *(int *)(g + 0x5E0) & 0xFFEFFFFF;
                }
            }
        }
    }

    if (*(int *)&D_00747A2C >= 0) {
        char *o = (char *)&D_00747A2C;
        unsigned long w8;
        if ((*(int *)(o + 0x58) & 0x8000000) == 0 &&
            (w8 = *(int *)(o - 0x8), ((w8 >> 3) & 1) == 0) &&
            (*(int *)(o + 0x4C) & 0x10000) == 0 &&
            (*(int *)(o + 0x4) & 1) == 0) {
            long t2;
            void (*fp)(void);

            *(int *)(o + 0x84) = 0xFFFF;
            t2 = (unsigned int)self->task.flags;
            if (((t2 >> 1) & 1) == 0)
                func_002C1540(&D_005FEA60);
            fp = SCENARIO_HOOK(self);
            if (fp)
                (*fp)();
            func_001F7360(D_00568288);
        }
    }
}
