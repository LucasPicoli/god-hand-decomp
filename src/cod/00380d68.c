#include "godhand/menuCtl.h"

extern int GuardedCall_00329FD0_329F98(int);
extern void ADXT_Destroy(int);
extern void func_0031C900(int);

/* Stop a file slot's stream once it reports state 5, then free its buffer. */
__attribute__((section(".text.func_00380D68")))
void func_00380D68(int unused, SlotInfoB *slot)
{
    int buf;

    if (slot->handle == 0)
        return;
    if (GuardedCall_00329FD0_329F98(slot->handle) != 5)
        return;
    ADXT_Destroy(slot->handle);
    buf = slot->buf;
    slot->handle = 0;
    func_0031C900(buf);
}
