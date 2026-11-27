/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"
#include "godhand/cObj.h"

extern int cOmSub_move(void *a0);

extern void cOmSub_initMove1_ang(void *a0, void *a1, int a2, int a3, void *t0,
                                 float f12, float f13, int t1);




__attribute__((section(".text.func_001812B8")))
void func_001812B8(void *a0)
{
    cObj *s1 = a0;
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int b1, b2, b3;
    int i1, i2, i3;
    unsigned char ok1, ok2, ok3;
    int t;

    switch (s1->phase) {
    case 0:
        *(short *)((char *)s1 + 0x608) = 0xA;
        *(int *)((char *)s1 + 0x5B8) &= ~0x100;
        *(unsigned char *)((char *)s1 + 0x770) = 1;
        s1->phase = 1;
        s1->step = 0;
        s1->stepArg = 0;
        /* fallthrough */
    case 1: {
        cOmBase *t1a;
        if (*(short *)((char *)s1 + 0x608) >= 0)
            goto dec;
        {
            float *q = (float *)frame;
            *(int *)frame = 0;
            q[2] = 2.0943952f;
            q[3] = 1.0f;
            *(int *)(frame + 4) = 0;
            cOmSub_initMove1_ang((char *)s1 + 0x610, s1, 1, 0xA, frame, q[0], q[0], 0);
        }
        i1 = 1;
        ok1 = ((*(int *)(frame + 0x10) = b1 = s1->partNum), (i1 < b1));
        if (ok1) t1a = (*(cOmBase ***)((char *)s1 + 0x278))[i1]; else t1a = 0;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xDC, a0, 0, (cParts *)t1a, 0, 0);
        s1->phase = 2;
        s1->step = 0;
        s1->stepArg = 0;
        goto dec;
    }
    case 2: {
        char *s0 = (char *)s1 + 0x610;
        if (cOmSub_move(s0) != 0)
            break;
        {
            float *q = (float *)frame;
            *(int *)frame = 0;
            q[2] = -0.17453292f;
            q[3] = 1.0f;
            *(int *)(frame + 4) = 0;
            cOmSub_initMove1_ang(s0, s1, 1, 2, frame, q[0], q[0], 0);
        }
        s1->stepArg = 0;
        s1->phase = 3;
        goto zero_2F6;
    }
    case 3: {
        char *s0 = (char *)s1 + 0x610;
        cOmBase *t1b, *t1c;
        if (cOmSub_move(s0) != 0)
            goto dec;
        {
            float *q = (float *)frame;
            *(int *)frame = 0;
            q[2] = -1.5707964f;
            q[3] = 1.0f;
            *(int *)(frame + 4) = 0;
            cOmSub_initMove1_ang(s0, s1, 2, 6, frame, q[0], q[0], 0);
        }
        i2 = 2;
        ok2 = ((*(int *)(frame + 0x20) = b2 = s1->partNum), (i2 < b2));
        if (ok2) t1b = (*(cOmBase ***)((char *)s1 + 0x278))[i2]; else t1b = 0;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xDD, a0, 0, (cParts *)t1b, 0, 0);
        i3 = 2;
        ok3 = ((*(int *)(frame + 0x20) = b3 = s1->partNum), (i3 < b3));
        if (ok3) t1c = (*(cOmBase ***)((char *)s1 + 0x278))[i3]; else t1c = 0;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xDE, a0, 0, (cParts *)t1c, 0, 0);
        SetEffect(1, 1, a0, 0, -1, EFFECT_FOLLOW_OWNER);
        s1->phase = 4;
        s1->step = 0;
        s1->stepArg = 0;
    dec:
        t = *(unsigned short *)((char *)s1 + 0x608) - 1;
        *(short *)((char *)s1 + 0x608) = t;
        break;
    }
    case 4:
        if (cOmSub_move((char *)s1 + 0x610) != 0)
            break;
        *(unsigned char *)((char *)s1 + 0x771) = 1;
        s1->phase = 5;
        s1->stepArg = 0;
        goto zero_2F6;
    case 5:
        s1->stepArg = 0;
        s1->mode = 2;
        s1->phase = 0;
    zero_2F6:
        s1->step = 0;
        break;
    default:
        break;
    }
}
