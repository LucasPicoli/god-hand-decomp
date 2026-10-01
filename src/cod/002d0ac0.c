/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern char D_003C3138[];
extern char D_005FEE00[];
extern void cSnd_SetBgmState(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */

typedef struct BgmEntry {
    /* 0x00 */ unsigned short id;
    /* 0x02 */ unsigned short pad;
    /* 0x04 */ int f04;
    /* 0x08 */ int f08;
    /* 0x0C */ int f0C;
    /* 0x10 */ int f10;
    /* 0x14 */ int f14;
} BgmEntry;





/* Store a bgm request into the stage table entry of a stage id, for one bgm state. */
__attribute__((section(".text.SetBgmTbl")))
void SetBgmTbl(unsigned short id, int val, int state) {
    cBgmStageEnt *found = 0;
    unsigned int i;

    for (i = 0; i < 44; i++) {
        if (((cBgmStageEnt *)D_003C3138)[i].id == id) {
            found = &((cBgmStageEnt *)D_003C3138)[i];
        }
    }

    if (found == 0) {
        return;
    }
    cSnd_SetBgmState(D_005FEE00, state);
    switch (state) {
    default:
    case 0:
        found->bgm[0] = val;
        break;
    case 1:
        found->bgm[1] = val;
        break;
    case 2:
        found->bgm[2] = val;
        break;
    case 3:
        found->bgm[3] = val;
        break;
    case 4:
        found->bgm[4] = val;
        break;
    }
}
