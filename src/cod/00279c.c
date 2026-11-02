#include "godhand/vu0.h"
#include "godhand/cEm00.h"

/* cEm00 field not named in cEm00.h yet: 0x4AC pointer to the class name string. */
#define CEM00_TYPENAME(self) (*(void **)((char *)(self) + 0x4AC))

extern int D_00447E68;
extern int D_00447E50;
extern void *func_0028EB00(void *obj);

/* Enemy constructor: run the base constructor, set the vtable at +0x214, clear five quadwords, set the type name at +0x4AC. */
__attribute__((section(".text.Init_Vtable214_TypeName4AC_279CE8")))
void *Init_Vtable214_TypeName4AC_279CE8(cEm00 *self)
{
    func_0028EB00(self);
    self->vtable = (cVtEnt *)&D_00447E68;
    VU0_SQC2_VF0(self, 0x1530);
    VU0_SQC2_VF0(self, 0x1540);
    VU0_SQC2_VF0(self, 0x1550);
    VU0_SQC2_VF0(self, 0x1590);
    VU0_SQC2_VF0(self, 0x15A0);
    CEM00_TYPENAME(self) = (void *)&D_00447E50;
    return self;
}
