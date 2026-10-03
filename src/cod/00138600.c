#include "godhand/cCamera.h"

struct vtbl {
    char pad[0x10];
    short off;
    void (*fn)(int);
};

extern void cCamera_stepVib(struct cCamera *self);
extern void cCamera_update(struct cCamera *self);
/* One camera step: the subclass move method, the vibration, the update. */
__attribute__((section(".text.cCamera_move")))
void cCamera_move(struct cCamera *self) {
    cCamVt *vt = self->vt;
    vt->move((int)self + vt->moveDelta);
    cCamera_stepVib(self);
    cCamera_update(self);
}

__attribute__((section(".text.InitFiveSubstructs2ABA78_13D0B8")))
void InitFiveSubstructs2ABA78_13D0B8(char *a0)
{
    cIDBase_resetAnim(a0);
    cIDBase_resetAnim(a0 + 0x140);
    cIDBase_resetAnim(a0 + 0x190);
    cIDBase_resetAnim(a0 + 0xA0);
    cIDBase_resetAnim(a0 + 0xF0);
}

__attribute__((section(".text.InitFiveSubstructs2AABA0_13D100")))
void InitFiveSubstructs2AABA0_13D100(char *a0)
{
    cIDBase_stepJitter(a0);
    cIDBase_stepJitter(a0 + 0x140);
    cIDBase_stepJitter(a0 + 0x190);
    cIDBase_stepJitter(a0 + 0xA0);
    cIDBase_stepJitter(a0 + 0xF0);
}
