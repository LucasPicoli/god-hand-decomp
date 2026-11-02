/* sn-2.95.3-136 */
#include "godhand/cObjBase.h"

extern int SetEffect(int kind, int id, void *owner, cEffectParam *param, int handle, unsigned int follow);

/* Start an effect on part `part` of owner at (x, y, z) with the default
 * parameters and the given size; returns SetEffect's result. */
__attribute__((section(".text.SetEffectParts")))
int SetEffectParts(int kind, int id, void *owner, int part, float x, float y, float z, float size, int handle)
{
    cEffectParam param;

    cEffectParam_init(&param);
    param.unk4C = part;
    param.unk20.x = x;
    param.unk20.y = y;
    param.unk20.z = z;
    param.size = size;
    param.unk70 = 0;
    param.unk72 = 0;
    param.unk74 = 0;
    param.unk78 = 0;
    return SetEffect(kind, id, owner, &param, handle, 0xFFFFFFFF);
}
