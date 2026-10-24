/* sn-2.95.3-136: func_0028AC58, sets up an enemy model from its data pack: looks up the model and texture blocks
 * for the character index, applies the kind's alternate textures picked by the 0x155C flags, then builds the model. */
#include "godhand/cEm00.h"

#define TEXFLAG_EXCHANGE  0x10000000    /* texFlags: a texture exchange is active */

extern char D_00448E10[];
extern char D_00448E18[];
extern int GetEm00CharIndex(int id, int kind);
extern void Obj0000_Set_Field_424_1595E8(int *self, int v);
extern void *SearchData(void *pack, char *name, int index);
extern void cModel_setTextureExchange(void *model, void *tex, void *alt, int slot);
extern int cModel_setupModel(void *model, void *mdl, void *tex, int a3, int a4);

#define TEX_EXCHANGE(self, tex, off, slot) \
    ((self)->texFlags |= TEXFLAG_EXCHANGE, \
     cModel_setTextureExchange((self), (tex), (void *)EM_RES_REC((self)->resource, (off)), (slot)))

__attribute__((section(".text.func_0028AC58")))
int func_0028AC58(cEm00 *self)
{
    int idx;
    void *mdl;
    void *tex;

    idx = GetEm00CharIndex(self->actorId, self->emNo);
    Obj0000_Set_Field_424_1595E8((int *)self, 0);
    mdl = SearchData((void *)self->resource, D_00448E10, idx);
    tex = SearchData((void *)self->resource, D_00448E18, idx);
    switch (self->emNo) {
    case 0x2A7:
        if (self->unk155C & 1)
            TEX_EXCHANGE(self, tex, 0x44, 0);
        break;
    case 0x2A9:
        if (self->unk155C & 1)
            TEX_EXCHANGE(self, tex, 0x48, 0);
        break;
    case 0x2AB:
        if (self->unk155C & 1)
            TEX_EXCHANGE(self, tex, 0x4C, 0);
        if (self->unk155C & 2)
            TEX_EXCHANGE(self, tex, 0x4C, 1);
        break;
    }
    if (tex != 0)
        return cModel_setupModel(self, mdl, tex, 0, 0);
    return 0;
}
