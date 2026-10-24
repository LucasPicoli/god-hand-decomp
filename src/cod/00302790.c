/* sn-2.95.3-136 */
#include "godhand/cNode.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* Draw settings embedded at 0x1A0 of cDrawNode. */
typedef struct cNodeDrawState {
    cVec unk00;                         /* 0x00 */
    cVec unk10;                         /* 0x10 */
    cVec unk20;                         /* 0x20 */
    cVec unk30;                         /* 0x30 */
    float unk40;                        /* 0x40 */
    int unk44;
    int unk48;
    signed char unk4C;                  /* 0x4C */
    unsigned char unk4D;
    unsigned char unk4E;
    unsigned char unk4F;                /* 0x4F */
    int unk50;
    char unk54[0xC];
    cVec unk60;                         /* 0x60 */
    short unk70;
    short unk72;
    unsigned char unk74;
    char unk75[3];
    int unk78;
    char unk7C[4];
} cNodeDrawState;                       /* 0x80 */

typedef struct cDrawNode {
    cNode base;                         /* 0x000 */
    char unkF4[0x10];
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    char unk118[4];
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    short unk184;
    short unk186;
    short unk188;
    short unk18A;
    char unk18C[2];
    short unk18E;
    unsigned char unk190;
    char unk191[0xF];
    cNodeDrawState draw;                  /* 0x1A0 */
    char unk220[0xC];
    float unk22C;                       /* 0x22C */
    unsigned char unk230;               /* 0x230 */
} cDrawNode;

extern cNode *cNode_construct(cNode *self, int name, cNode *parent);
extern char D_0044FD58[];

/* Zeroes a quadword vector with one VU0 store. */
static __inline__ void cVec_zero(cVec *v)
{
    VU0_SQC2_VF0_MEM(v, 0);
}

/* Default settings: unit scales, zero offsets, unk4C -1, unk4F 0xFF. */
static __inline__ void cNodeDrawState_init(cNodeDrawState *d)
{
    cVec_set4(&d->unk00, 1.0f, 1.0f, 1.0f, 1.0f);
    cVec_zero(&d->unk10);
    cVec_zero(&d->unk20);
    cVec_set4(&d->unk30, 1.0f, 1.0f, 1.0f, 1.0f);
    d->unk40 = 1.0f;
    d->unk4C = -1;
    d->unk4F = 0xFF;
    d->unk44 = 0;
    d->unk48 = 0;
    d->unk4D = 0;
    d->unk4E = 0;
    d->unk50 = 0;
    cVec_zero(&d->unk60);
}

/* The base settings plus a cleared tail. */
static __inline__ void cNodeDrawState_initAll(cNodeDrawState *d)
{
    cNodeDrawState_init(d);
    d->unk70 = 0;
    d->unk72 = 0;
    d->unk74 = 0;
    d->unk78 = 0;
}

/* Constructs a cDrawNode: base node, cleared fields, default draw settings. */
__attribute__((section(".text.func_00302790")))
cDrawNode *func_00302790(cDrawNode *self)
{
    cNode_construct(&self->base, 0, 0);
    self->base.vt = D_0044FD58;
    self->unk104 = 0;
    self->unk108 = 0;
    self->unk10C = 0;
    self->unk110 = 0;
    self->unk114 = 0;
    self->unk11C = 0;
    self->unk120 = 0;
    self->unk124 = 0;
    self->unk128 = 0;
    self->unk12C = 0;
    self->unk130 = 0;
    self->unk134 = 0;
    self->unk138 = 0;
    self->unk13C = 0;
    self->unk140 = 0;
    self->unk144 = 0;
    self->unk148 = 0;
    self->unk14C = 0;
    self->unk150 = 0;
    self->unk154 = 0;
    self->unk158 = 0;
    self->unk15C = 0;
    self->unk160 = 0;
    self->unk164 = 0;
    self->unk168 = 0;
    self->unk16C = 0;
    self->unk170 = 0;
    self->unk174 = 0;
    self->unk178 = 0;
    self->unk17C = 0;
    self->unk180 = 0;
    self->unk184 = 0;
    self->unk186 = 0;
    self->unk188 = 0;
    self->unk18A = 0;
    self->unk18E = 0;
    self->unk190 = 0;
    cNodeDrawState_initAll(&self->draw);
    self->unk22C = 1.0f;
    self->unk170 = 0;
    self->unk174 = 0;
    self->unk178 = 0;
    self->unk230 = 0;
    return self;
}
