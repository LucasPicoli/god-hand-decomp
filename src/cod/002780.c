#include "godhand/vu0.h"
#include "godhand/globals.h"

/* The derived part of the enemy record: only the fields this constructor sets. */
typedef struct EmDerived {
    char unk000[0x214];
    const void *vt;                     /* 0x214 method table of the second base */
    char unk218[0x294];
    const char *name;                   /* 0x4AC type name string */
} EmDerived;

extern const unsigned char D_00447D48[];    /* method table */
extern void *func_0028EB00(void *self);     /* enemy base constructor */

/* Enemy constructor: base setup, method table, five zeroed vectors and the type name. */
__attribute__((section(".text.Em_construct278068")))
EmDerived *Em_construct278068(EmDerived *self)
{
    func_0028EB00(self);
    self->vt = D_00447D48;
    VU0_SQC2_VF0(self, 0x1530);
    VU0_SQC2_VF0(self, 0x1540);
    VU0_SQC2_VF0(self, 0x1550);
    VU0_SQC2_VF0(self, 0x1590);
    VU0_SQC2_VF0(self, 0x15A0);
    self->name = D_00447CB0;
    return self;
}
