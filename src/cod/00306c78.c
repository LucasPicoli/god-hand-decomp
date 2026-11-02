#include "godhand/EspDataBank.h"
#include "godhand/vu0.h"

extern int func_003069E8(void *, int, void *, void *);

__attribute__((section(".text.func_00306C78")))
int func_00306C78(void **table, unsigned int index, void *out1, void *out2)
{
    void *slot;
    *(int *)out1 = 0;
    *(int *)out2 = 0;
    if (index >= 0x40)
        return 0;
    slot = *(void **)((char *)table + (index << 2));
    if (slot == 0)
        return 0;
    return func_003069E8(slot, (int)index, out1, out2) != 0;
}
