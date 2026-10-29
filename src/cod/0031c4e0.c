/* sn-2.95.3-136: player object creation at stage start (0x31C4E0). */
#include "godhand/gameWork.h"
#include "godhand/player.h"

void func_0031C5C0(void);
int func_0030F550(int size);
void *func_00107E40(int arg);

__attribute__((section(".text.func_0031C4E0")))
void func_0031C4E0(void)
{
    cGameObj *obj;
    cObjInitVt *vt;

    if (D_007474A0.room != GAMEWORK_ROOM_NOPLAYER) {
        if (!(D_007474A0.flags & GAMEWORK_PLAYER_READY)) {
            do {
                cTaskWork_sleep(D_00752C00.task, 1);
            } while (!(D_00747A24 & GAMEWORK_PLAYER_READY));
        }
        obj = CreateObj(0x100, 0xFFFF);
        D_007474A0.playerObj = obj;
        vt = (cObjInitVt *)obj->vtable;
        vt->init((char *)obj + vt->initDelta);
        func_0031C5C0();
    } else {
        D_007474A0.playerObj = func_00107E40(func_0030F550(0x1690));
    }
}
