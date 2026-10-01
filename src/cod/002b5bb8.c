#include "godhand/cSnd.h"
__attribute__((section(".text.FreeEntrySlot_2B5BB8")))
void FreeEntrySlot_2B5BB8(int a0, int a1, int a2)
{
    int *s0;
    int v0;
    int v1;
    s0 = func_002B4FE8(a0, a2);
    v0 = s0[0];
    v1 = s0[1];
    if (v0 != 0) {
        UnlinkAndCoalesceNode_2A9680(v1, v0);
    }
    s0[0] = 0;
    s0[1] = 0;
}

__attribute__((section(".text.ClearStructFields_2C8EB0")))
void ClearStructFields_2C8EB0(int *a0) {
    a0[0] = 0;
    func_003A52F0((int)((char *)a0 + 0x4), 0, 0xC);
    func_003A52F0((int)((char *)a0 + 0x14), 0, 0x80);
}

/* Clears the active flag of a used BGM node and refreshes its state. */
__attribute__((section(".text.ClearActiveBit_2CCAC8")))
void ClearActiveBit_2CCAC8(cSndBgmNode *node) {
    if (func_002CC568(node)) {
        node->flags = node->flags & 0xFFFFFFFE;
        UpdateStateAndClearFlag_3734F0(node);
    }
}

__attribute__((section(".text.ClearFlagBits_373858")))
void ClearFlagBits_373858(void *a0, unsigned int a1) {
    if (func_00373A50(a0)) {
        *(int *)((char *)a0 + 0x4C) = *(int *)((char *)a0 + 0x4C) & ~a1;
    }
}
