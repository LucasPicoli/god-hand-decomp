/* sn-2.95.3-136 */
#include "godhand/cObjBase.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

/* The default effect parameters: white, unit scale and size, nothing set. */
static __inline__ void cEffectParam_init(cEffectParam *p)
{
    cVec_set4(&p->color, 1.0f, 1.0f, 1.0f, 1.0f);
    cVec_zero(&p->unk10);
    cVec_zero(&p->unk20);
    cVec_set4(&p->scale, 1.0f, 1.0f, 1.0f, 1.0f);
    p->size = 1.0f;
    p->unk4C = -1;
    p->unk4F = 0xFF;
    p->unk44 = 0;
    p->flags = 0;
    p->unk4D = 0;
    p->unk4E = 0;
    p->unk50 = 0;
    cVec_zero(&p->unk60);
}

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
