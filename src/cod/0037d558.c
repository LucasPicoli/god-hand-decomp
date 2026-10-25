/* sn-2.95.3-136 */
#include "godhand/seqNode.h"

/* Split a node's volume into left and right levels from its pan. */
__attribute__((section(".text.func_0037D558")))
void func_0037D558(SeqNode *self)
{
    float l, r;

    self->unk4E = self->unk4C = (short)self->weight >> 1;
    switch (Obj0000_Get_D_0076A7A4_3756F0()) {
    case 0:
        break;
    case 1:
        if (self->pan > 0x40) {
            self->unk4C = self->unk4C * (0x7F - self->pan) / 64;
        } else if (self->pan < 0x40) {
            self->unk4E = self->unk4E * self->pan / 64;
        }
        break;
    case 2:
        func_003780F8(self->pan, &l, &r);
        self->unk4C = (int)(self->unk4C * l) & 0x7FFF;
        self->unk4E = (int)(self->unk4E * r) & 0x7FFF;
        break;
    }
}
