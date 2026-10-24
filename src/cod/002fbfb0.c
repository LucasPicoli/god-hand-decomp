/* sn-2.95.3-136 */
#include "godhand/espSys.h"
#include "godhand/gameWork.h"

void UpdateObjByIndexedOp_2FBE50(void *a0);
int func_002FC1A0(EspAnim *self);

#define ESP_VCALL(self, n, type) CVCALL_FN(self, n, type)(CVCALL_THIS(self, n))

/* One tick of a frame-driven effect: advances the frame timer, ends the
 * effect at its last frame, otherwise runs the step methods and moves it by
 * its velocity (only on a new key when the clock drives it). */
__attribute__((section(".text.func_002FBFB0")))
void func_002FBFB0(EspAnim *self)
{
    if ((self->data->flags & ESP_DATA_PAUSE) == 0 && (self->lockFlags & 1) != 0) {
        func_002FA350(&self->frameT);
    } else if ((D_007474A0.flags5E4 & SYSFLAG_SLOWMO) != 0) {
        func_002FA350(&self->frameT);
    } else {
        self->frameT = self->frameT + 1.0f;
    }
    self->frameIdx = self->frameT;
    if (self->frameEnd != 0 && self->frameIdx >= self->frameEnd) {
        UpdateObjByIndexedOp_2FBE50(self);
        return;
    }
    if (EspAnim_step(self)) {
        return;
    }
    if (ESP_VCALL(self, 9, int (*)(void *))) {
        return;
    }
    if (func_002FC1A0(self)) {
        return;
    }
    ESP_VCALL(self, 11, void (*)(void *));
    ESP_VCALL(self, 12, void (*)(void *));
    ESP_VCALL(self, 13, void (*)(void *));
    ESP_VCALL(self, 14, void (*)(void *));
    if (!(((self->data->flags & ESP_DATA_PAUSE) == 0 && (self->lockFlags & 1) != 0)
          || (D_007474A0.flags5E4 & SYSFLAG_SLOWMO) != 0)
        || self->keyPrev != self->key) {
        self->pos[0] += self->vel[0];
        self->pos[1] += self->vel[1];
        self->pos[2] += self->vel[2];
    }
    ESP_VCALL(self, 15, void (*)(void *));
    ESP_VCALL(self, 10, void (*)(void *));
    self->keyPrev = self->key;
}
