/* sn-2.95.3-136 */
#include "godhand/cSnd.h"
#include "godhand/cSubScr.h"

/* View of the bgm override record D_00586B28 points at. */
typedef struct BgmOverride {
    int flags;                  /* 0x00 bit 0: use bgm */
    char pad04[4];
    unsigned short bgm;         /* 0x08 */
} BgmOverride;

extern BgmOverride *D_00586B28;
extern unsigned short D_00583EEC;
extern unsigned char D_005CB010;

/* No screen is stacked on the open sub screen. */
static __inline__ unsigned char subScr_isIdle(cSubScr *m)
{
    if (m->stack[0] != 0) {
        return 0;
    }
    return 1;
}

/* Pick the bgm request for a stage from the override, the enemies present and the bgm state. */
__attribute__((section(".text.cSnd_GetStageBgmReq")))
int cSnd_GetStageBgmReq(cSnd *self, unsigned short stage)
{
    cSubScr *m = D_003BD930;
    cSndKindEnt *e;
    unsigned short id;
    int r;

    if ((m->kind == 3 || m->kind == 12) && !subScr_isIdle(m)) {
        if (D_00586B28->flags & 1) {
            id = D_00586B28->bgm;
        } else {
            id = D_00583EEC;
        }
        return func_002D0B88(stage != 0x21 ? id : 0x100)->param[0];
    }
    if (D_005CB010 != 0) {
        return 10;
    }
    e = func_002D0B88(stage);
    if (self->bgmState == 1) {
        return e->param[1];
    }
    r = cSnd_BgmReqFromEnemies(self);
    if (r != -2) {
        return r;
    }
    switch (self->bgmState) {
    case 2:
        return e->param[2];
    case 3:
        return e->param[3];
    case 4:
        return e->param[4];
    case 0:
    default:
        return e->param[0];
    }
}
