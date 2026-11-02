/* Byte-identical to RE4 PS2 (SLUS-21134) 0x0029EEF0 — shared engine code.
 * mod = a0->0x24 % a0->0x18; stores mod+1 back to 0x24; returns
 * a0->0x14 + (mod << 6). The return value is computed before the store-back so
 * the shift is emitted before the increment, matching retail's scheduling. */

#include "godhand/sif.h"

__attribute__((section(".text.func_003B2B90")))
void *func_003B2B90(sceSifRpcState *s) {
    int mod = s->rdataTableIdx % s->rdataTableLen;
    char *r = (char *)s->rdataTable + (mod << 6);
    s->rdataTableIdx = mod + 1;
    return r;
}
