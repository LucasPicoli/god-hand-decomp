/* cCoreSave_setKeyCardNum - set the key-card count, clamped to [0, 9]. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_setKeyCardNum")))
void cCoreSave_setKeyCardNum(cCoreSave *self, int num) {
    if (!self->data)
        return;
    self->data->keyCardNum = num;
    if (self->data->keyCardNum > CORESAVE_KEY_MAX)
        self->data->keyCardNum = CORESAVE_KEY_MAX;
    if (self->data->keyCardNum < 0)
        self->data->keyCardNum = 0;
}
