#include "godhand/vu0.h"
#include "godhand/globals.h"

/* The derived part of the cEm66 record: only the fields this constructor sets. */
typedef struct cEm66 {
    char unk000[0x214];
    const void *vt;                     /* 0x214 method table */
    char unk218[0x294];
    const char *name;                   /* 0x4AC type name string */
} cEm66;

#define CEM66_SLOT_OFFSET 0x1630        /* first of the zeroed slots */
#define CEM66_SLOT_NUM    0x2C
#define CEM66_SLOT_SIZE   0xA0

extern cEm66 *func_0028EB00(cEm66 *self);       /* enemy base constructor */
extern const char D_004483A8[];                 /* method table */

/* cEm66 constructor: base setup, method table, zeroed vectors, then the zeroed slot array and the type name. */
__attribute__((section(".text.cEm66_construct")))
cEm66 *cEm66_construct(cEm66 *self) {
    char *slot;
    int i;

    func_0028EB00(self);
    self->vt = D_004483A8;
    VU0_SQC2_VF0(self, 0x1530);
    VU0_SQC2_VF0(self, 0x1540);
    VU0_SQC2_VF0(self, 0x1550);
    VU0_SQC2_VF0(self, 0x1590);
    VU0_SQC2_VF0(self, 0x15A0);
    VU0_SQC2_VF0(self, 0x1610);
    slot = (char *)self + CEM66_SLOT_OFFSET;
    for (i = CEM66_SLOT_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(slot, 0x00);
        VU0_SQC2_VF0(slot, 0x10);
        VU0_SQC2_VF0(slot, 0x30);
        VU0_SQC2_VF0(slot, 0x40);
        VU0_SQC2_VF0(slot, 0x50);
        VU0_SQC2_VF0(slot, 0x80);
        slot += CEM66_SLOT_SIZE;
    }
    self->name = D_004482B0;
    return self;
}
