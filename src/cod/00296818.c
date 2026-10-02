/* sn-2.95.3-136 matched TU. */
#include "godhand/cEvent.h"

extern void *Getplayer(void);
extern void pl00_reset(void *p);
extern void cEmManage_ReleaseEmAll(void *a0);
extern void cDataManager_clear(void *a0);
extern void cDataHolder_systemInit(void *a0);
extern int D_00586B30[];
extern char D_005864F0[];
extern int D_005864E0[];

/* sn-2.95.3-136 matched TU. */











/* CLEAR stage: reset the player, release the enemies, then clear the data
 * manager and its holders. Returns 1 once the stage hands over to CREATE. */
__attribute__((section(".text.func_00296818")))
int func_00296818(cEvent *self) {
    pl00_reset(Getplayer());
    if ((D_00586B30[1] & 1) == 0) {
        switch ((char)self->phase) {
        case 0:
            cEmManage_ReleaseEmAll(D_005864F0);
            self->phase = self->phase + 1;
            goto ret0;
        case 6:
            if (D_00586B30[1] & 0x400) {
                break;
            }
            /* fallthrough */
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
            self->phase = self->phase + 1;
            goto ret0;
        case 8:
            {
                int p;
                int i;
                cDataManager_clear(D_005864E0);
                p = D_005864E0[2];
                i = D_005864E0[1];
                if (p != 0) {
                    while (--i != -1) {
                        cDataHolder_systemInit((void *)(p + i * 0x5C));
                    }
                }
            }
            break;
        default:
            goto ret0;
        }
    }
    self->state = CEVENT_STATE_CREATE;
    self->phase = 0;
    self->unk06 = 0;
    self->unk07 = 0;
    return 1;
ret0:
    return 0;
}
