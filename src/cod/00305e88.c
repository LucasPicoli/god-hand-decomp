/* sn-2.95.3-136 */
#include "godhand/cObjBase.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

#define FXONCE_KIND    3
#define FXONCE_HANDLE  0x2200
#define FXONCE_PARAM   0x40             /* flags bit these effects ask for */

/* An object that starts each of its numbered effects only once. */
typedef struct cFxOnce {
    char unk00[0x414];
    unsigned int started;               /* 0x414 one bit per effect number */
} cFxOnce;

/* Start effect `no` unless it has already been started. */
__attribute__((section(".text.func_00305E88")))
void func_00305E88(cFxOnce *self, int no)
{
    cEffectParam param;

    if (self->started & (1 << no)) {
        return;
    }
    self->started |= 1 << no;
    cEffectParam_init(&param);
    param.flags |= FXONCE_PARAM;
    param.unk70 = 0;
    param.unk72 = 0;
    param.unk74 = 0;
    param.unk78 = 0;
    SetEffect(FXONCE_KIND, no, 0, &param, no + FXONCE_HANDLE, 0xFFFFFFFF);
}
