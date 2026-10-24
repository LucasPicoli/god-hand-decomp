/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmManage.h"
#include "godhand/sideCounter.h"

extern unsigned int irand(void);

/* Empties every slot and clears the room state: the list, the waits, the
 * kept actors and the flags. The speed rate goes back to 1.0 and unk53F
 * gets a new random number 0..4. */
__attribute__((section(".text.cEmManage_reset")))
void cEmManage_reset(cEmManage *self) {
    cEmSlot *end = &self->slot[EM_SLOT_NUM];
    cEmSlot *slot = self->slot;
    cEmActor **special;
    SideCounter *d;
    unsigned int i;

    do {
        cEmManage_clearSlot(slot);
        slot++;
    } while (slot < end);

    self->list.top = 0;
    self->list.last = 0;
    self->emNum = 0;
    self->kindNum = 0;
    self->nextNo = 0;
    self->speedRate = EM_SPEED_RATE_NORMAL;
    self->unk53F = irand() % 5;
    special = self->specialEm;
    self->unk53E = 0;
    self->unk540 = 0;
    self->unk541 = 0;
    self->unk560[0] = 0;
    self->unk560[1] = 0;
    self->unk560[2] = 0;
    self->unk560[3] = 0;
    self->unk560[4] = 0;
    self->unk588[0] = 0;
    self->unk588[1] = 0;
    self->unk588[2] = 0;
    self->unk588[3] = 0;
    for (i = 0; i < 2; i++) {
        self->unk5AC[i] = 0;
    }
    for (i = 0; i < EM_SPECIAL_NUM; i++) {
        special[i] = 0;
    }
    self->darkWorld = 0;
    d = &D_00754C38;
    d->on = 0;
    d->cnt = 0;
    d->unkC = 0;
    self->unk5B5 = 0;
}
