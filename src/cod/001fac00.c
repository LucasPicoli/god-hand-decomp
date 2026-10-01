/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cCoreSave.h"

extern int D_00747A2C;

__attribute__((section(".text.cCoreSave_shiftGodItem")))
/* Drop the first god item and shift the rest down (not with the 0x80000 cheat). */
void cCoreSave_shiftGodItem(cCoreSave *self) {
    unsigned int i;
    if ((D_00747A2C & 0x80000) == 0) {
        i = 0;
        do {
            unsigned int j = i + 1;
            unsigned char item = self->data->godItem[j];
            self->data->godItem[i] = item;
            i = j;
        } while (i < 5);
        self->data->godItem[5] = 0;
    }
}
