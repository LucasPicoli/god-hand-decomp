/* Enemy constructor: base setup, then its method table, three zeroed vectors and the type name. */
#include "godhand/vu0.h"
#include "godhand/globals.h"

#define EM_VEC_A_OFFSET   0x1530        /* first zeroed quadword */
#define EM_VEC_B_OFFSET   0x1540
#define EM_VEC_C_OFFSET   0x1550

typedef struct EnemyRec {
    char unk000[0x214];
    const void *vt;                     /* 0x214 method table of the second base */
    char unk218[0x294];
    const char *name;                   /* 0x4AC type name string */
} EnemyRec;

extern const unsigned char D_00447BA0[];    /* method table */
extern void *func_0028EB00(void *self);     /* enemy base constructor */

__attribute__((section(".text.EnemyBase_constructTriVec")))
EnemyRec *EnemyBase_constructTriVec(EnemyRec *self)
{
    func_0028EB00(self);
    self->vt = D_00447BA0;
    VU0_SQC2_VF0(self, EM_VEC_A_OFFSET);
    VU0_SQC2_VF0(self, EM_VEC_B_OFFSET);
    VU0_SQC2_VF0(self, EM_VEC_C_OFFSET);
    self->name = D_00447B88;
    return self;
}
