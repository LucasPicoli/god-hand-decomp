/* sn-2.95.3-136 matched TU. */

#include "godhand/cEvent.h"

extern void func_0();

/* Number of the current cut. */
__attribute__((section(".text.func_00297B98")))
int func_00297B98(void) {
    return cEvent_work.cutNo;
}

/* Clear the first byte of the current cut's entry. */
__attribute__((section(".text.func_00297BF8")))
void func_00297BF8(void) {
    cEvent_work.cutTable[cEvent_work.cutNo * 16] = 0;
}

/* Look up an object for the cutscene by id: forward to the stripped finder. */
__attribute__((section(".text.cEvent_getObjPtr")))
int cEvent_getObjPtr(void *unusedThis, unsigned short id, unsigned char type) {
    return cEvent_nullHookI(cEvent_nullStr00, id, type);
}

/* Free the cutscene work: run the three stripped release hooks, but only
 * when the record says it owns a work area (flags byte 1, bit 0). */
__attribute__((section(".text.cEvent_releaseWork")))
void cEvent_releaseWork(cEvent *self) {
    if (CEVENT_FLAG_BYTE(self, 1) & 1) {
        func_0(cEvent_nullStr00);
        func_0(cEvent_nullStr00);
        func_0(cEvent_nullStr01);
    }
}
