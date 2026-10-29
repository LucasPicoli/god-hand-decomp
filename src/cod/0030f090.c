/* sn-2.95.3-136 */
#include "godhand/cGame.h"
#include "godhand/cGameObj.h"
#include "godhand/debugPrint.h"
#include "godhand/ptrVec.h"
#include "godhand/sideCounter.h"

#define SYSFLAG_NO_OBJ_MOVE 0x20000      /* D_00747A78: objects don't move */
#define SYSFLAG_PAUSE       0x8000000    /* D_00747A78: the game is paused */

extern int D_00747A78;                  /* system flags */
extern int D_00752CF8;                  /* timer-0 counts MoveObj took */
extern char D_00450AF8[];               /* "obj     %d" */

/* Move every registered object that isn't suspended or skipped and clear the
 * low two bits of its unk2F0, then step the side counter; time it all with
 * timer 0 and print the object count. */
__attribute__((section(".text.MoveObj")))
void MoveObj(void)
{
    PtrVec *v;
    void **it;
    void **end;

    D_00752CF8 = *(volatile int *)CGAME_TIMER_COUNT;
    if (!(D_00747A78 & SYSFLAG_PAUSE))
        D_00754C38.unk10 = 1.0f;
    if (!(D_00747A78 & SYSFLAG_NO_OBJ_MOVE)) {
        v = D_00754C30.v;
        end = v->end;
        it = v->begin;
        while (it != end) {
            void **cur = it++;
            cGameObj *obj = *cur;

            if (obj->objFlags & GAMEOBJ_OBJ_SUSPEND)
                continue;
            if (obj->objFlags & GAMEOBJ_OBJ_SKIP)
                continue;
            cGameObj_vt(obj)->move((char *)obj + cGameObj_vt(obj)->moveDelta);
            /* retail reads the entry again after the move */
            ((cGameObj *)*cur)->unk2F0 &= ~3;
        }
    }
    if (!(D_00747A78 & SYSFLAG_PAUSE))
        cScrArray_move(&D_00754C38);
    D_00752CF8 -= *(volatile int *)CGAME_TIMER_COUNT;
    printf_2E0DA8(100, 0x7C, 0, 4, D_00450AF8, D_00754C30.v ? D_00754C30.v->end - D_00754C30.v->begin : 0);
}
