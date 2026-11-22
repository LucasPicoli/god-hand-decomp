/* cygnus-2.96 matched TU. */
#include "godhand/CriTrackSet.h"
#include "godhand/globals.h"

extern void Obj33F8_Tramp_0033F130_FCB0(void *a0);
extern int ForwardField3ByOffset_32ED48(void *a0, int a1, int a2);

/* Needs c_flags_drop -f=-freorder-blocks (like 0032dd18.c / 0032b7.c):
   with the global flag the self == 0 block is moved to the end. */
/* Set the level of track trno and pass base + track level to its handle. */
__attribute__((section(".text.CriTrackSet_setTrackLevel")))
void CriTrackSet_setTrackLevel(CriTrackSet *self, int trno, int level) {
    if (self == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452FB0);
        return;
    }
    if (trno > CRI_TRNO_MAX) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452FD8);
        return;
    }
    self->trackLevel[trno] = level;
    ForwardField3ByOffset_32ED48(self, trno, self->baseLevel + level);
}
