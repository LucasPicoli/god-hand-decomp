/* cEventConfig_setEventNo — points a0->0x0 at event record a1 (0xC-byte stride
 * from D_003C0550) and copies the record's field 0x4 into a0->0x4. sn-2.95.3-136. */
#include "godhand/globals.h"

__attribute__((section(".text.cEventConfig_setEventNo")))
void cEventConfig_setEventNo(void *a0, int a1) {
    char *p = D_003C0550 + a1 * 0xC;
    *(char **)a0 = p;
    *(int *)((char *)a0 + 0x4) = *(int *)(p + 0x4);
}
