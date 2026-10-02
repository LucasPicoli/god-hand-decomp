/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cSnd.h"

extern int D_00450FF0;
extern void NoOp_33E6A8(void);
extern void func_0032A720(int a0, int a1, int a2);
extern int NoOp_33E6B0(void);

__attribute__((section(".text.func_0031EEC8")))
void func_0031EEC8(int *a0, int a1)
{
	if (a0) {
		a0[0] = a1;
		a0[1] = (int)&D_00450FF0;
	}
}

/* Returns slot idx of the sound-effect table. */
__attribute__((section(".text.cSnd_GetSeData")))
cSndSeEntry *cSnd_GetSeData(cSnd *self, int idx) { return &self->seEntry[idx]; }

__attribute__((section(".text.func_0032A6D0")))
int func_0032A6D0(int a0, int a1, int a2)
{
    NoOp_33E6A8();
    func_0032A720(a0, a1, a2);
    return NoOp_33E6B0();
}
