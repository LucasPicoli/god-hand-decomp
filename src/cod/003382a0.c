/* cygnus-2.96: PS2RNA_SetTransSw, sets the transfer group's pause request; any request other than 1
 * stops every transfer in the group. */
#include "godhand/criStm.h"
extern void DTR_Stop(int dtr);

__attribute__((section(".text.PS2RNA_SetTransSw")))
void PS2RNA_SetTransSw(char *grp, int req)
{
    signed char n = grp[0x52];
    int i;

    if (D_003E0710 != 1 || D_003E0708 > 0) {
        grp[0x58] = req;
        if (req != 1) {
            for (i = 0; i < n; i++) {
                DTR_Stop(((int *)(grp + 0x10))[i]);
                grp[0x59] = 1;
                grp[0x58] = 0;
            }
        }
    }
}
