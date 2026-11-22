/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"

/* ee-2.9-991111 */

__attribute__((section(".text.scePadInfoMode")))
int scePadInfoMode(int port, int slot, int term, int offs)
{
    PadData fr;

    if (D_0077C110[port][slot].open == 0)
        return 0;
    scePadGetDmaStr(port, slot, &fr);
    if (fr.ok != 1)
        return 0;
    if (fr.reqState == 2)
        return 0;
    switch (term) {
    case 1:
        if (fr.modeCurId == 0xF3)
            return 0;
        return fr.modeCurId >> 4;
    case 2:
        if (fr.modeConfig == 1)
            return 0;
        return fr.modeTable[fr.modeCurOffs];
    case 3:
        if (fr.modeConfig == 1)
            return 0;
        return fr.modeCurOffs;
    case 4:
        if (fr.modeConfig == 1)
            return 0;
        if (offs == -1)
            return fr.nrOfModes;
        if (offs >= fr.nrOfModes)
            return 0;
        return fr.modeTable[offs];
    }
    return 0;
}
