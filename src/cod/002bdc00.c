/* sn-2.95.3-136: func_002BDC00, step a pad vibration sequence (cPadVib). */
#include "godhand/gameWork.h"
typedef struct {
    int active;
    unsigned char *motor;
    void *seqA;
    void *seqB;
    char pad10[0x18 - 0x10];
    unsigned int flags;
    float speed;
    float time;
    unsigned int accum;
} PadVibSeq;

extern char D_005E8140[];
extern int func_002BDDE0(PadVibSeq *self, void *seq, int motor, float t);
extern int func_002BDD90(PadVibSeq *self);
extern void classPAD_WORK_Pad_act_set(char *o, unsigned int v, unsigned int w);
extern void cPadVib_stopSeq(PadVibSeq *self);

__attribute__((section(".text.func_002BDC00")))
void func_002BDC00(PadVibSeq *self)
{
    unsigned char big, small;
    int len;
    float t, end;

    if (self->active == 0 || self->motor == 0)
        return;
    big = func_002BDDE0(self, self->seqA, self->motor[0], self->time);
    small = func_002BDDE0(self, self->seqB, self->motor[1], self->time);
    classPAD_WORK_Pad_act_set(D_005E8140, (big << 16) | 0x2000000, (1 << D_007474A0.frameShift) << 16);
    self->accum += small;
    if (self->accum >= 0xFF) {
        self->accum -= 0xFF;
        classPAD_WORK_Pad_act_set(D_005E8140, 0x1000000, (1 << D_007474A0.frameShift) << 16);
    }
    self->time += self->speed;
    len = func_002BDD90(self);
    t = self->time;
    if (self->flags & 1) {
        end = (float)len - 1.0f;
        if (end <= t)
            self->time = t - end;
    } else if ((float)len - 1.0f < t) {
        cPadVib_stopSeq(self);
    }
}
