/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136, cloned from func_001B7EE0. */

#include "godhand/vu0.h"

extern void *Getplayer(void);
extern float capVu0LengthSq(void *a0);
extern float Adjust_theta(float angle);
extern int Dest_ck(void *a0, void *a1, float f12, float f13);
extern void cActionButton_set(void *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern void cOmBase_startCutTask(void);
extern char D_00568288;

typedef void *(*vfn)(void *);
typedef void (*vfn2)(void *, void *);

/* Method table slots (g++ 2.x: a this-adjust short, then the function). */
#define VT_SET_ROT      0x78
#define VT_LOCK_ON      0x80
#define VT_GET_SCALE    0x88
#define OBJ_VT          0x214
#define OBJ_PHASE       0x2F5
#define OBJ_WAIT        0x602           /* frames left in phase 2 */

#define SPIN_STEP       0.10471976f     /* 6 degrees a frame */
#define PROMPT_RADIUS_SQ 6.25f          /* 2.5 units */
#define PROMPT_MAX_ANGLE 1.3962634f     /* 80 degrees */

/* Per frame: spin the object by 6 degrees. Phase 0 offers the action button
 * when the player is within 2.5 units and faces it; phase 2 counts the wait
 * down and returns to phase 0. */
__attribute__((section(".text.func_001BF5E0")))
void func_001BF5E0(void *a0)
{
    char *s2 = (char *)a0;
    /* One object at $sp+0: the rotation at 0x00, the length argument at 0x10
     * and the difference at 0x20, so every quadword store is $sp-based. */
    char frame[0x30] __attribute__((aligned(16)));
    float *rot = (float *)frame;
    char *arg;
    void *sc;

    {
        char *vt0 = *(char **)(s2 + OBJ_VT);
        sc = (*(vfn *)(vt0 + VT_GET_SCALE + 4))(s2 + *(short *)(vt0 + VT_GET_SCALE));
    }
    VU0_LQC2(4, sc, 0x0);
    VU0_SQC2(4, frame, 0x0);
    rot[1] = rot[1] + SPIN_STEP;
    rot[1] = Adjust_theta(rot[1]);
    {
        char *vt1 = *(char **)(s2 + OBJ_VT);
        (*(vfn2 *)(vt1 + VT_SET_ROT + 4))(s2 + *(short *)(vt1 + VT_SET_ROT), rot);
    }
    switch (*(unsigned char *)(s2 + OBJ_PHASE)) {
    case 0: {
        void *o = Getplayer();
        char *vtp = *(char **)((char *)o + OBJ_VT);
        void *plPos = (*(vfn *)(vtp + VT_LOCK_ON + 4))((char *)o + *(short *)(vtp + VT_LOCK_ON));
        char *vt2 = *(char **)(s2 + OBJ_VT);
        void *selfPos = (*(vfn *)(vt2 + VT_LOCK_ON + 4))(s2 + *(short *)(vt2 + VT_LOCK_ON));

        arg = frame + 0x10;
        VU0_SQC2_VF0(frame, 0x20);
        VU0_LQC2(4, plPos, 0x0);
        VU0_LQC2(5, selfPos, 0x0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, frame, 0x20);
        VU0_LQC2(4, frame + 0x20, 0x0);
        VU0_SQC2(4, frame, 0x10);

        if (capVu0LengthSq(arg) < PROMPT_RADIUS_SQ) {
            void *plA = Getplayer();
            char *vta = *(char **)((char *)plA + OBJ_VT);
            void *plAt = (*(vfn *)(vta + VT_LOCK_ON + 4))((char *)plA + *(short *)(vta + VT_LOCK_ON));
            void *plB = Getplayer();
            char *vtb = *(char **)((char *)plB + OBJ_VT);
            void *plScale = (*(vfn *)(vtb + VT_GET_SCALE + 4))((char *)plB + *(short *)(vtb + VT_GET_SCALE));
            char *vtc = *(char **)(s2 + OBJ_VT);
            void *selfAt = (*(vfn *)(vtc + VT_LOCK_ON + 4))(s2 + *(short *)(vtc + VT_LOCK_ON));
            if (Dest_ck(plAt, selfAt, *(float *)((char *)plScale + 0x4), PROMPT_MAX_ANGLE) != 0) {
                cActionButton_set(&D_00568288, 4, 0x28, 0, (int)cOmBase_startCutTask, (int)s2, 0);
            }
        }
        break;
    }
    case 1:
        break;
    case 2:
        if (*(short *)(s2 + OBJ_WAIT) <= 0)
            *(unsigned char *)(s2 + OBJ_PHASE) = 0;
        *(short *)(s2 + OBJ_WAIT) = *(short *)(s2 + OBJ_WAIT) - 1;
        break;
    }
}
