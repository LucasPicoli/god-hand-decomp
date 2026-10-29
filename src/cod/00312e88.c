/* sn-2.95.3-136 */
#include "godhand/cObj.h"
#include "godhand/criStm.h"
#include "godhand/heapArena.h"
#include "godhand/vu0.h"

/* The 0x360-byte actor whose vtable is D_00450CE8: a cObj with two vectors
 * and a flag byte. */
typedef struct cObjVec2 {
    cObj base;                          /* 0x000 */
    cVec unk310;                        /* 0x310 */
    char unk320[0xC];
    unsigned char unk32C;               /* 0x32C */
    char unk32D[0x13];
    cVec unk340;                        /* 0x340 */
    char unk350[0x10];
} cObjVec2;                             /* 0x360 */

#define OBJ_ALIGN  0x10

extern cVtEnt D_00450CE8[];
extern void *_MemoryAlloc(int a0, int a1, int a2);
extern cObj *cObj__ctor(cObj *self);

/* Allocate one from the D_00754C20 arena and construct it; 0 when the arena
 * is full. */
__attribute__((section(".text.func_00312E88")))
cObjVec2 *func_00312E88(void)
{
    cObjVec2 *self;

    self = _MemoryAlloc(sizeof(cObjVec2), OBJ_ALIGN, (int)&D_00754C20);
    if (self == 0) {
        return 0;
    }
    func_003A52F0(self, 0, sizeof(cObjVec2));
    cObj__ctor(&self->base);
    self->base.vtable = D_00450CE8;
    VU0_SQC2_VF0_AT(self->unk310);
    self->unk32C = 0;
    VU0_SQC2_VF0_AT(self->unk340);
    return self;
}
