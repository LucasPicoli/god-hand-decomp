/* TU: cEmSetParam [enemy] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cEmSetParam.h"

INCLUDE_ASM("nonmatching", cEmSetParam_setEmAll);

INCLUDE_ASM("nonmatching", cEmSetParam_setEm);

extern cEmSetEntry *func_002BEF60();

/* Stores the heading f (radians) in the current entry, in room-file units. */
__attribute__((section(".text.cEmSetParam_updateSetDataRot")))
void cEmSetParam_updateSetDataRot(float f) {
    cEmSetEntry *entry = func_002BEF60(&D_005E8658);
    if (entry != 0) {
        entry->rot = (short)(int)(f * EMSET_ROT_PER_RAD);
    }
}


/* Stores how the current entry's enemy appears. */
__attribute__((section(".text.cEmSetParam_updateSetDataAppPattern")))
void cEmSetParam_updateSetDataAppPattern(int a, int b, unsigned char c) {
    cEmSetEntry *entry = func_002BEF60(&D_005E8658);
    c = c & 0xFF;
    if (entry != 0) {
        entry->appPattern = c;
    }
}


INCLUDE_ASM("nonmatching", cEmSetParam_getSetDataPos);
