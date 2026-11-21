/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/DispMgr.h"

extern void Obj0000_Set_D_007474A0_Fields_5D8_5E0(void *self);
extern void AddToActiveList_138F40(void *list, int arg);
extern void pl00_SubscreenMode(void *player, int mode);
extern void Forward2D9458_2D98A0(void *p);
extern int cIDBase_release(void *idBase);
extern void func_00161590(void *self);
extern char D_00463050[];
extern char D_00604700[];
extern char **D_003C2384;

typedef struct PlayerRef {
    char unk000[0x100];
    cVec turnTo;                        /* 0x100 */
} PlayerRef;

/* The screen is itself a cIDBase and owns two more. */
typedef struct Screen1689E8 {
    char idBase[0xD0];                  /* 0x000 */
    char idBaseB[0x1D8 - 0xD0];         /* 0x0D0 */
    PlayerRef *player;                  /* 0x1D8 */
    char unk1DC[0x1F0 - 0x1DC];
    cVec target;                        /* 0x1F0 where the player is turned to */
    char unk200[0x10];
    char idBaseC[0x10];                 /* 0x210 */
} Screen1689E8;

/* Closes the casino screen: resets the casino game's bar data, hands the
 * player back, releases the three id bases and clears the host's two words. */
__attribute__((section(".text.Screen_closeCasino")))
void Screen_closeCasino(Screen1689E8 *self)
{
    char *host;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(self);
    func_00143A90(&Cockpit->gold);
    cCockPlBar_initData(&Cockpit->plBar);
    AddToActiveList_138F40(D_00463050, 0);
    cVec_copy3(&self->player->turnTo, &self->target);
    pl00_SubscreenMode(self->player, 0);
    Forward2D9458_2D98A0(D_00604700);
    cIDBase_release(self->idBaseC);
    cIDBase_release(self->idBaseB);
    cIDBase_release(self);
    host = *D_003C2384;
    *(int *)(host + 0x54) = 0;
    *(int *)(host + 0x50) = 0;
    func_00161590(self);
}
