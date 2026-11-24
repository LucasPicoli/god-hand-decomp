/* sn-2.95.3-136 matched TU. */

extern int D_00421FE8;
extern int InitFields_1B6E90(void *self);
extern void cIDBase_restartAnim(void *self);
extern void *D_003C23A4;
extern void *cMessage_getMessageAddr(void *mgr, int id);
extern void *cMessage_getRubyAddr(void *mgr, int id);

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cCockPrintData.h"




__attribute__((section(".text.func_0017E0F8")))
void *func_0017E0F8(void *a0) {
    char *p;
    unsigned int i;

    InitFields_1B6E90(a0);

    p = (char *)a0 + 0x610;
    *(int **)((char *)a0 + 0x214) = &D_00421FE8;

    VU0_SQC2_VF0(a0, 0x660);
    VU0_SQC2_VF0(a0, 0x670);
    VU0_SQC2_VF0(a0, 0x680);
    VU0_SQC2_VF0(a0, 0x690);
    VU0_SQC2_VF0(a0, 0x6A0);
    VU0_SQC2_VF0(a0, 0x6B0);
    VU0_SQC2_VF0(a0, 0x6C0);
    VU0_SQC2_VF0(a0, 0x6D0);
    VU0_SQC2_VF0(a0, 0x6E0);
    VU0_SQC2_VF0(a0, 0x6F0);
    VU0_SQC2_VF0(a0, 0x700);
    VU0_SQC2_VF0(a0, 0x710);
    VU0_SQC2_VF0(a0, 0x720);
    VU0_SQC2_VF0(a0, 0x730);

    *(char *)(p + 0x0) = 0;
    *(char *)(p + 0x1) = 0;
    *(char *)(p + 0x2) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
    *(int *)(p + 0x130) = 0;
    *(int *)(p + 0x134) = 0;
    *(int *)(p + 0x138) = 0;
    *(int *)(p + 0x13C) = 0;

    for (i = 0; i < 8; i++) {
        *(int *)(p + 0xC + i * 4) = 0;
    }

    VU0_SQC2_VF0(a0, 0x770);
    return a0;
}









__attribute__((section(".text.func_00143598")))
void func_00143598(cCockPrintData *self) {
    unsigned short i;

    cIDBase_restartAnim(self);
    self->base.playing = 1;
    self->gold = cCoreSave_getGold(&D_00569B70);

    for (i = 0; i < COCKPRINT_WORK_NUM; i++) {
        self->work[i] = cIDBase_getIDWork(&self->base, i);
    }
    for (i = 0; i < COCKPRINT_SLOT_NUM; i++) {
        self->on[i] = 0;
    }

    self->work[2]->flags |= IDENT_FLAG_NO_DRAW;
    self->work[0]->number = self->gold;
    cCoreSave_initAddGold(&D_00569B70);
    self->mode = 0;
}

typedef struct S2B21F0 {
    char pad00[0x24];
    unsigned short arr[3];
} S2B21F0;






__attribute__((section(".text.func_002B21F0")))
void func_002B21F0(void *self, unsigned short id) {
    char *s;
    char *msg;
    char *ruby;
    unsigned short fill;
    unsigned int i;

    s = (char *)self;
    msg = (char *)cMessage_getMessageAddr(D_003C23A4, id);
    ruby = (char *)cMessage_getRubyAddr(D_003C23A4, id);

    *(short *)(s + 0x94) = 0;
    *(unsigned short *)(s + 0x88) = 0xFFFF;
    *(int *)(s + 0x14) |= 2;
    *(char *)(s + 0x70) = 0;
    *(char *)(s + 0xA4) = 0;
    *(int *)(s + 0x34) = 0;

    fill = 0xFFFF;
    for (i = 0; i < 3; i++) {
        ((S2B21F0 *)self)->arr[i] = fill;
    }

    *(unsigned short *)(s + 0x64) = id;
    *(char **)(s + 0x8C) = msg;
    *(char **)(s + 0x7C) = msg;
    *(char **)(s + 0x74) = msg;
    *(float *)(s + 0x6C) = 1.0f;
    *(char *)(s + 0x30) = -1;
    *(int *)(s + 0x68) = 0;
    *(int *)(s + 0x90) = 0;
    *(int *)(s + 0x84) = 0;
    *(char **)(s + 0x78) = ruby;
    *(short *)(s + 0x38) = 0;
    *(char **)(s + 0x80) = ruby;
    *(char *)(s + 0x3C) = 0;
}
