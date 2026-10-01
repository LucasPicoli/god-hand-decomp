/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot2.h"
#include "godhand/cCoreSave.h"

extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void cCoreSave_addCasinoTicket(void *a0, int a1);
extern void cSnd_BgmEventStart(void *a0, int a1, int a2, int a3);
extern int Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0(void *a0);
extern void func_001E6ED8(void *a0, int a1, int a2);
extern void func_001E6D48(void *a0, int a1, int a2);
extern void func_001E7908(void *a0, int a1, int a2);
extern char D_003BD6E8[];
extern char D_00569B70[];
extern char D_005FEE00[];
extern char D_007474A0[];

/* sn-2.95.3-136 matched TU. */













#define GAMEWORK_PAD(g) (*(long *)((g) + 0x1A0))
#define GAMEWORK_FLAG(g) (*(int *)((g) + 0x56C))
#define GAMEWORK_STAGE(g) (*(unsigned short *)((g) + 0x5B0))
#define GAMEWORK_ANYBTN 0xF00000000L
#define SLOT2_CASINO_FLAG 0x8000000
/* Slot2 ticket exchange screen: pay the player a casino ticket, then show the
 * result and wait for a button before returning to the title state. */
__attribute__((section(".text.func_001E5F30")))
void func_001E5F30(Slot2 *self) {
    switch (self->phase) {
    case 0:
        self->timer = 0x78;
        self->phase = self->phase + 1;
        break;
    case 1:
        SetEffect(1, 2, 0, 0, -1, 0xFFFFFFFFU);
        func_001E6ED8(self, 1, 1);
        func_001E6D48(self, 1, 1);
        cSnd_BgmEventStart(D_005FEE00, 0x32, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        {
            int done;
            int t = self->timer;
            if (t != 0) {
                self->timer = t - 1;
                done = 0;
            } else {
                done = 1;
            }
            if ((unsigned char)done == 0) break;
        }
        {
            cCoreSaveData *save = *(cCoreSaveData **)D_00569B70;
            int f = save->flags;
            if ((f & SLOT2_CASINO_FLAG) == 0) {
                char *g = D_007474A0;
                save->flags = f | SLOT2_CASINO_FLAG;
                if (GAMEWORK_FLAG(g) == 0 ||
                    GAMEWORK_STAGE(g) == 5) {
                    func_001E7908(self->layer, 0x1001, 1);
                } else if (GAMEWORK_STAGE(g) == 6) {
                    func_001E7908(self->layer, 0x1001, 1);
                }
                self->phase = self->phase + 1;
            } else {
                self->phase = 4;
            }
        }
        cCoreSave_addCasinoTicket(D_00569B70, 1);
        *(int *)(*(char **)D_003BD6E8 + 0x1A10) =
            (short)Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0(D_00569B70);
        func_001E6ED8(self, 0, 0);
        func_001E6D48(self, 0, 0);
        break;
    case 3: {
        char *g = D_007474A0;
        if ((GAMEWORK_PAD(g) & GAMEWORK_ANYBTN) != 0) {
            self->timer = 0x1E;
            if (GAMEWORK_FLAG(g) == 0 ||
                GAMEWORK_STAGE(g) == 5) {
                func_001E7908(self->layer, 0x1001, 0);
            } else if (GAMEWORK_STAGE(g) == 6) {
                func_001E7908(self->layer, 0x1001, 0);
            }
            self->phase = self->phase + 1;
        }
        break;
    }
    case 4:
        if (Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0(D_00569B70) >= 9) {
            {
                int done;
                int t = self->timer;
                if (t != 0) {
                    self->timer = t - 1;
                    done = 0;
                } else {
                    done = 1;
                }
                if ((unsigned char)done == 0) break;
            }
            {
            char *g = D_007474A0;
            if (GAMEWORK_FLAG(g) == 0 ||
                GAMEWORK_STAGE(g) == 5) {
                func_001E7908(self->layer, 0x1002, 1);
            } else if (GAMEWORK_STAGE(g) == 6) {
                func_001E7908(self->layer, 0x1003, 1);
            }
            }
            self->phase = self->phase + 1;
        } else {
            self->phase = 6;
        }
        break;
    case 5: {
        char *g = D_007474A0;
        if ((GAMEWORK_PAD(g) & GAMEWORK_ANYBTN) != 0) {
            if (GAMEWORK_FLAG(g) == 0 ||
                GAMEWORK_STAGE(g) == 5) {
                func_001E7908(self->layer, 0x1002, 0);
            } else if (GAMEWORK_STAGE(g) == 6) {
                func_001E7908(self->layer, 0x1003, 0);
            }
            self->phase = self->phase + 1;
        }
        break;
    }
    case 6:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}
