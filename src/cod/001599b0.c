/* sn-2.95.3-136 matched TU. */

#include "godhand/cMessDrawFont.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern unsigned int cMessCommon_getCodeSize(unsigned int code);
extern void func_002B04C0(cMessDrawFont *self, unsigned short *text, void *arg);
extern float func_002B0908(cMessDrawFont *self, unsigned short *text, void *arg);
extern float func_002B0A58(cMessDrawFont *self, unsigned short *text, void *arg);
extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *unit, void *mtx, float *pos, float *dir, float *size);
extern void cOmDoor_setObjCollision(void *self);
extern int D_00574380;

/* Decode one record header: store the kind (bits 12..15 of the first word); kinds 1, 3 and 5 point the output at the record's table in the blob, reset it when the record has fewer than 2 entries, otherwise step to the first entry, read its first value and let func_00159DA0 start the decode; any other kind keeps the record's float. */
#define REC_KIND_BYTES   1
#define REC_KIND_SHORTS  3
#define REC_KIND_SHORTS2 5

typedef struct RecIn {
    unsigned int hdr;                   /* 0x00 bits 12..15 kind, bits 16..31 entry count */
    int dataOff;                        /* 0x04 */
    union {
        int off;                        /* 0x08 data offset from the blob */
        float value;
    } u;
} RecIn;

typedef struct RecOut {
    unsigned char kind;                 /* 0x00 */
    char unk01[3];
    char *src;                          /* 0x04 data block */
    char *cur;                          /* 0x08 current entry */
    unsigned short pos;                 /* 0x0C */
    unsigned short first;               /* 0x0E first entry value */
    union {
        int zero;
        float value;
    } u;                                /* 0x10 */
} RecOut;

extern void func_00159DA0(RecOut *out);

__attribute__((section(".text.func_001599B0")))
void func_001599B0(RecOut *out, char *blob, RecIn *in)
{
    int kind = (in->hdr >> 12) & 0xF;
    char *p;
    char *q;
    out->kind = kind;
    switch ((unsigned char)kind) {
    case REC_KIND_BYTES:
        p = blob + in->u.off;
        out->src = p;
        out->cur = p + 0xC;
        if (((unsigned short *)in)[1] < 2) {
            goto clear;
        }
        out->pos = 0;
        out->cur = p + 0x10;
        out->first = *(unsigned char *)(p + 0x10);
        func_00159DA0(out);
        break;
    case REC_KIND_SHORTS:
        p = blob + in->u.off;
        out->src = p;
        out->cur = p + 0x18;
        if (((unsigned short *)in)[1] < 2) {
            goto clear;
        }
        out->pos = 0;
        out->cur = p + 0x20;
        out->first = *(unsigned short *)(p + 0x20);
        func_00159DA0(out);
        break;
    case REC_KIND_SHORTS2:
        q = blob + in->u.off;
        out->cur = q;
        if (((unsigned short *)in)[1] < 2) {
            goto clear;
        }
        out->pos = 0;
        out->cur = q + 0x10;
        out->first = *(unsigned short *)(q + 0x10);
        func_00159DA0(out);
        break;
    clear:
        out->kind = 0;
        out->u.zero = 0;
        break;
    case 0:
    default:
        out->u.value = in->u.value;
        break;
    }
}

/* Measure a message string: walk the codes, add each plain code's advance to *width (a control code is run through func_002B04C0 and an end code stops the walk, handing back its position), take each code's glyph width and height from func_002B0908 and func_002B0A58, and keep the tallest in *height. */








__attribute__((section(".text.func_002B0700")))
unsigned short *func_002B0700(cMessDrawFont *self, unsigned short *text, void *arg, float *width, float *height)
{
    float w;
    float h;
    float z;
    *(int *)width = 0;
    *(int *)height = 0;
    z = *height;
    goto test;
plain:
    *width += self->unk2C[0] * self->zoomX;
glyph:
    do { w = func_002B0908(self, text, arg); } while (0);
    h = func_002B0A58(self, text, arg);
    if (w != z) {
        *width += w;
    }
    if (*height < h) {
        *height = h;
    }
    text += cMessCommon_getCodeSize(*text);
test:
    if ((*text >> 15) == 0) {
        goto plain;
    }
    func_002B04C0(self, text, arg);
    if (func_002AF068(*text) == 0) {
        goto glyph;
    }
    *width -= self->unk2C[0] * self->zoomX;
    return text;
}

#define COMBASE_F0_BIT2   0x04          /* flags0 bit 2 */

/* Start the knock step: aim the knock vector from the anchor body at the object, set mode 2 step 0, and flag the object active. */
__attribute__((section(".text.func_0019D248")))
void func_0019D248(cOmBase *self)
{
    cVec frame[2] __attribute__((aligned(16)));
    unsigned int f = self->flags0;
    long wide = f;
    long gone = (wide >> 1) & 1;
    if (gone) {
        return;
    }
    VU0_ZERO_VSUB_XYZ_MEM(frame, 0x10, self->pos, &self->posA);
    do { VU0_LQC2(4, &frame[1], 0); } while (0);
    VU0_SQC2(4, frame, 0);
    cVec_copy3(&self->knock, &frame[0]);
    self->mode = 2;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
    self->flags0 = (self->flags0 | COMBASE_F0_ACTIVE) & ~COMBASE_F0_BIT2;
}

/* Set up a door-like object: 1 life, a 1.45 by 3 by 0.2 hit box through the damage manager, the box size kept at 0x610, its collision object and the second body at 0x650. */


#define DOORBOX_RING_OFFSET  0x650      /* second body inside the object */

typedef struct DoorBoxObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damage;                       /* 0x600 */
    char unk604[0xC];
    float size[3];                      /* 0x610 */
    char unk61C[8];
    unsigned char hasBody;              /* 0x624 */
    char unk625[3];
    void *body;                         /* 0x628 */
} DoorBoxObj;

#define COMBASE_F2_BIT1  0x2            /* flags2 bit 1 */








__attribute__((section(".text.func_00192050")))
int func_00192050(DoorBoxObj *self)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;
    int hp;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.45f;
    cb = 3.0f;
    cc = 0.2f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[4] = ca;
    f[1] = cb;
    f[2] = cc;
    f[6] = cc;
    f[5] = cb;
    f[3] = one;
    t[3] = one;
    f[8] = f[0] * -0.5f;
    *(int *)&f[9] = 0;
    *(int *)&f[10] = 0;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damage = slot;
    if (slot != 0) {
        nv = &f[12];
        *(int *)&f[12] = 0;
        *(int *)&f[13] = 0;
        *(int *)&f[14] = 0;
        nv[3] = one;
        func_001FD9D8(slot, (char *)self + 0x80, m, nv, t);
    }
    hp = 1;
    self->base.hpMax = hp;
    self->base.hp = hp;
    cVec_copy3((cVec *)self->size, (cVec *)f);
    cOmDoor_setObjCollision(self);
    self->hasBody = hp;
    self->body = (char *)self + DOORBOX_RING_OFFSET;
    func_001BBF68(self);
    self->base.flags2 |= COMBASE_F2_BIT1;
    return 1;
}
