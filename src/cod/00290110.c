/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmManage.h"

extern unsigned int irand(void);
/* Three fields of D_00754C38 that reset clears; what they hold is not known. */
typedef struct D_00754C38_t {
    int unk0;
    unsigned char unk4;
    char unk5[3];
    int unk8;
    int unkC;
} D_00754C38_t;
extern D_00754C38_t D_00754C38;

/* Empties every slot and clears the room state: the list, the waits, the
 * kept actors and the flags. The speed rate goes back to 1.0 and unk53F
 * gets a new random number 0..4. */
__attribute__((section(".text.cEmManage_reset")))
void cEmManage_reset(cEmManage *self) {
    cEmSlot *end = &self->slot[EM_SLOT_NUM];
    cEmSlot *slot = self->slot;
    cEmActor **special;
    D_00754C38_t *d;
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
    d->unk4 = 0;
    d->unk8 = 0;
    d->unkC = 0;
    self->unk5B5 = 0;
}
