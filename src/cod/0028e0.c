#include "godhand/vu0.h"
#include "godhand/cEm00.h"

/* cEm00 field not named in cEm00.h yet: 0x4AC pointer to the class name string. */
#define CEM00_TYPENAME(self) (*(void **)((char *)(self) + 0x4AC))

extern int D_0044A528;
extern int D_0044A510;
extern void *func_0028EB00(void *obj);

/* Enemy constructor: run the base constructor, set the vtable at +0x214, clear one quadword, set the flag byte at +0x1541 and the type name at +0x4AC. */
__attribute__((section(".text.cEm00_construct_ad")))
void *cEm00_construct_ad(cEm00 *self)
{
    unsigned char *flags;

    func_0028EB00(self);
    flags = (unsigned char *)self + 0x1510;
    self->vtable = (cVtEnt *)&D_0044A528;
    VU0_SQC2_VF0(self, 0x1520);
    flags[0x31] = 0xFF;
    CEM00_TYPENAME(self) = (void *)&D_0044A510;
    return self;
}
