/* cSceAtManager_addUnitData — fill in an AT unit (a1): store the work pointer
 * (a3@0x48), the sign-extended id t0 (@0x4C) and the index a2 (@0x39), then
 * register it in the manager's slot array (a0 + a2*4 + 0x20) via cSceAtManager_linkUnit.
 * Offset computed as (a2*4 + 0x20) + a0 to match retail's addiu/addu order.
 * sn-2.95.3-136. */

extern void cSceAtManager_linkUnit(void *, void *, void *);

__attribute__((section(".text.cSceAtManager_addUnitData")))
void cSceAtManager_addUnitData(void *a0, void *a1, int a2, int a3, short t0) {
    int off;
    if (!a1)
        return;
    *(int *)((char *)a1 + 0x48) = a3;
    *(short *)((char *)a1 + 0x4C) = t0;
    *(signed char *)((char *)a1 + 0x39) = a2;
    off = a2 * 4 + 0x20;
    cSceAtManager_linkUnit(a0, (char *)a0 + off, a1);
}
