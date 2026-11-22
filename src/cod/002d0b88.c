#include "godhand/ColiseumBattle.h"
#include "godhand/cSnd.h"

extern cSndKindEnt D_003C3138[44];

__attribute__((section(".text.func_002D0B88")))
cSndKindEnt *func_002D0B88(unsigned short id)
{
    cSndKindEnt *found;
    unsigned int i;
    int kind, v;

    found = 0;
    for (i = 0; i < 44; i++) {
        if (D_003C3138[i].id == id) {
            found = &D_003C3138[i];
        }
    }
    if (found == 0) {
        kind = id >> 8;
        v = (unsigned char)(kind - 1) < 8 ? kind + 1 : 2;
        D_003C3120.id = id;
        D_003C3120.param[0] = v;
        D_003C3120.param[1] = v;
        D_003C3120.param[2] = v;
        D_003C3120.param[3] = v;
        D_003C3120.param[4] = v;
        found = &D_003C3120;
    }
    return found;
}

static inline unsigned char SndIsEnemyKind(int kind)
{
    return kind >= COLISEUM_EM_KIND_FIRST && kind < COLISEUM_EM_KIND_END;
}

static inline unsigned char SndIsBossKind(int kind)
{
    return kind >= COLISEUM_EM_KIND_BOSS && kind < COLISEUM_EM_KIND_END;
}

