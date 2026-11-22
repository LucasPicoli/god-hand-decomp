/* cygnus-2.96 matched TU. */
#include "godhand/criStm.h"
#include "godhand/globals.h"

extern int DTX_CallUrpc(int a0, int a1, int a2, void *a3, int t0);

__attribute__((section(".text.PS2RNA_ShutdownDolby")))
void PS2RNA_ShutdownDolby(void) {
    int buf[4];
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return;
        }
    }
    if (D_003E0738 != 0) {
        DTX_CallUrpc(0xF, 0, 0, buf, 2);
        D_003E0748[0] = buf[0];
        D_003E0748[1] = buf[1];
        D_003E0738 = 0;
    }
}
