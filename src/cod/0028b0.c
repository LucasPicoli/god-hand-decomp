/* cEma6 constructor: base setup, then its method table, aim lock byte, three zeroed vectors and the type name. */
#include "godhand/vu0.h"

#define CEMA6_VEC_A_OFFSET   0x1520     /* cEma6.vecA, for the VU0 store */
#define CEMA6_VEC_B_OFFSET   0x1590     /* cEma6.vecB */
#define CEMA6_VEC_C_OFFSET   0x1610     /* cEma6.vecC */
#define CEMA6_AIM_FREE       0xFF       /* aim.target: no target */

/* The aim block at 0x1510. */
typedef struct cEma6Aim {
    char unk00[0x10];
    float vec[4];                       /* 0x10 zeroed with one quadword store */
    char unk20[0x11];
    unsigned char target;               /* 0x31 */
} cEma6Aim;

/* The derived part of the enemy record: only the fields this constructor sets. */
typedef struct cEma6 {
    char unk000[0x214];
    const void *vt;                     /* 0x214 method table of the second base */
    char unk218[0x294];
    const char *name;                   /* 0x4AC type name string */
    char unk4B0[0x1060];
    cEma6Aim aim;                       /* 0x1510 */
} cEma6;

extern const unsigned char D_0044A408[];    /* method table */
extern const char D_00448F30[];             /* "cEma6" */
extern void *func_0028EB00(void *self);     /* enemy base constructor */

__attribute__((section(".text.Obj28B0_Setup_Field_214_Field_4AC_28B0F0")))
cEma6 *Obj28B0_Setup_Field_214_Field_4AC_28B0F0(cEma6 *self)
{
    cEma6Aim *aim;
    func_0028EB00(self);
    self->vt = D_0044A408;
    aim = &self->aim;
    VU0_SQC2_VF0(self, CEMA6_VEC_A_OFFSET);
    aim->target = CEMA6_AIM_FREE;
    VU0_SQC2_VF0(self, CEMA6_VEC_B_OFFSET);
    VU0_SQC2_VF0(self, CEMA6_VEC_C_OFFSET);
    self->name = D_00448F30;
    return self;
}
