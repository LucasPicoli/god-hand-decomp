/* sn-2.95.3-136: event movie play step: pause bgm and lock game flags, start the movie, wait for it to end, then restore and fade in (0x160FF0). */
#include "godhand/gameWork.h"
#include "godhand/classFADE.h"
#include "godhand/cMovie.h"
extern char D_005FEE00[];
extern char D_005E79D0[];
extern int D_00566E40;
extern int D_00566E44;

extern void KeyStop(void);
extern void cSnd_BattleBgmAllPause(void *, float);
extern void cSnd_BgmFlaggedNodeKick(void *, float);
/* Two lock-flag words of the game work: 0x5D8 (D_00747A78, the system flags) and 0x5E0
 * (D_00747A80). They are written through the address because retail addresses both from
 * the word at 0x5E0; as GameWork fields or as their own symbols the code changes. */
#define GW_SYSFLAGS   (*(int *)((char *)&D_007474A0 + 0x5D8))
#define GW_LOCKFLAGS  (*(int *)((char *)&D_007474A0 + 0x5E0))

/* The event that plays a movie. */
typedef struct cEvMovie {
    char unk000[0xB9C];
    signed char movieNo;                /* 0xB9C the movie played is movieNo + 2 */
} cEvMovie;

/* The step short at 0x52 is used through its address: as a cEvMovie field, gcc orders the
 * stores at the end of step 0 differently. */
#define EVMOVIE_STEP(self)  (*(short *)((char *)(self) + 0x52))

__attribute__((section(".text.func_00160FF0")))
int func_00160FF0(cEvMovie *self)
{
    int id;
    int *hp;

    switch (EVMOVIE_STEP(self)) {
    case 0:
        id = self->movieNo + 2;
        hp = &D_00566E40;
        KeyStop();
        cSnd_BattleBgmAllPause(D_005FEE00, 1.0f);
        GW_LOCKFLAGS |= 0x4000000;
        GW_LOCKFLAGS |= 0x2000000;
        GW_LOCKFLAGS |= 0x40000000;
        GW_LOCKFLAGS |= 0x80000000;
        GW_LOCKFLAGS |= 0x200000;
        GW_LOCKFLAGS |= 0x20000000;
        GW_LOCKFLAGS |= 0x10000000;
        GW_LOCKFLAGS |= 0x8000000;
        GW_SYSFLAGS |= 0x80000000;
        GW_SYSFLAGS |= 0x40000000;
        GW_SYSFLAGS |= 0x20000000;
        GW_SYSFLAGS |= 0x10000000;
        GW_SYSFLAGS |= 0x80000;
        GW_SYSFLAGS |= 0x40000;
        *hp = cMovie_Start(D_005E79D0, id, 0);
        D_00566E44 = 5;
        GW_LOCKFLAGS |= 0x2000000;
        EVMOVIE_STEP(self)++;
    case 1:
        if (--D_00566E44 > 0)
            return 0;
        cMovie_haltActive(D_005E79D0, D_00566E40);
        EVMOVIE_STEP(self)++;
    case 2:
        if (cMovie_GetStatus(D_005E79D0, D_00566E40))
            return 0;
        cMovie_Stop(D_005E79D0, D_00566E40);
        cSnd_BgmFlaggedNodeKick(D_005FEE00, 20.0f);
        GW_LOCKFLAGS &= ~0x4000000;
        GW_LOCKFLAGS &= ~0x2000000;
        GW_LOCKFLAGS &= ~0x40000000;
        GW_LOCKFLAGS &= ~0x80000000;
        GW_LOCKFLAGS &= ~0x200000;
        GW_LOCKFLAGS &= ~0x20000000;
        GW_LOCKFLAGS &= ~0x10000000;
        GW_LOCKFLAGS &= ~0x8000000;
        GW_SYSFLAGS &= ~0x80000000;
        GW_SYSFLAGS &= ~0x40000000;
        GW_SYSFLAGS &= ~0x20000000;
        GW_SYSFLAGS &= ~0x10000000;
        GW_SYSFLAGS &= ~0x80000;
        GW_SYSFLAGS &= ~0x40000;
        GW_SYSFLAGS &= ~0x2000000;
        classFADE_start(&D_00747470, 0, 10, 0, 0xFF000000, 0xFF000000, 0);
        EVMOVIE_STEP(self) = 0;
    }
    return 1;
}
