/* sn-2.95.3-136 */
#include "godhand/cObjBase.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

/* Start an effect at pos with the default parameters and the given size. */
__attribute__((section(".text.SetEffectPos")))
void SetEffectPos(int kind, int id, void *owner, cVec *pos, int handle, float size)
{
    cEffectParam param;

    cEffectParam_init(&param);
    param.unk70 = 0;
    param.unk72 = 0;
    param.unk74 = 0;
    param.unk78 = 0;
    cVec_copy3(&param.unk20, pos);
    param.size = size;
    SetEffect(kind, id, owner, &param, handle, 0xFFFFFFFF);
}
