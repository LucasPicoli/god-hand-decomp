/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmManage.h"

/* Keeps one of the five numbered enemies (emNo 0x270..0x274) by its number. */
__attribute__((section(".text.func_00293760")))
void func_00293760(cEmManage *self, cEmActor *em) {
    if (em == 0) {
        return;
    }
    switch (em->emNo) {
    case 0x270:
        self->specialEm[1] = em;
        break;
    case 0x271:
        self->specialEm[2] = em;
        break;
    case 0x272:
        self->specialEm[3] = em;
        break;
    case 0x273:
        self->specialEm[4] = em;
        break;
    case 0x274:
        self->specialEm[0] = em;
        break;
    }
}
