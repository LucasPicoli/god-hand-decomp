/* sn-2.95.3-136 matched TU. */
#include "godhand/sndTiming.h"
#include "godhand/cSnd.h"

/* Set the default system volumes, then copy master and sub channels into the two triples. */
__attribute__((section(".text.func_002C9E78")))
void func_002C9E78(cSnd *self)
{
    SndSystemVol vol;
    float master0;
    float master1;
    float sub1;
    float sub2;

    SdeSystemOutModeSet(1);
    vol.master[0] = 0x7F;
    vol.master[1] = 0x7F;
    vol.unk4 = 0;
    vol.sub[0] = 0x5A;
    vol.sub[1] = 0x5A;
    vol.sub[2] = 0x7F;
    vol.sub[3] = 0x7F;
    vol.sub[4] = 0x7F;
    SdeSystemVolSet(&vol);
    SdePlayVolReset(7);
    master0 = vol.master[0];
    master1 = vol.master[1];
    sub1 = vol.sub[1];
    sub2 = vol.sub[2];
    self->unk00[0] = master0;
    self->unk0C[0] = sub1;
    self->unk00[1] = master1;
    self->unk0C[1] = sub2;
    self->unk00[2] = master0;
    self->unk0C[2] = sub1;
    func_00375380();
    func_00375500();
}
