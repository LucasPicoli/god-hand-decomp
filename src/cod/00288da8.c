/* sn-2.95.3-136: func_00288DA8, pick the 0/25/50 value from the actor id and enemy number, look up the model
 * and texture, swap textures for enemy 0x2A7 and set the model up. */
#include "godhand/cEm00.h"

#define TEXFLAG_EXCHANGE  0x10000000    /* texFlags: a texture exchange is active */
extern char D_00448C90[];
extern char D_00448C98[];

extern int GetEm00CharIndex(int type, int sub);
extern void Obj0000_Set_Field_424_1595E8(int *self, int v);
extern void *SearchData(void *pack, void *name, int which);
extern void cModel_setTextureExchange(void *model, void *texSet, void *tex, int arg);
extern int cModel_setupModel(void *model, void *mdl, void *tex, int a3, int t0);

__attribute__((section(".text.func_00288DA8")))
int func_00288DA8(cEm00 *self)
{
    int n;
    int idx;
    void *mdl;
    void *tex;
    char *pack;

    switch (self->actorId) {
    case 0x2A2:
    default:
        switch (self->emNo) {
        case 0x2A2:
        default:
            n = 0;
            break;
        case 0x2A3:
            n = 25;
            break;
        case 0x2A4:
            n = 50;
            break;
        }
        break;
    case 0x2A3:
        switch (self->emNo) {
        case 0x2A5:
        default:
            n = 0;
            break;
        case 0x2A6:
            n = 25;
            break;
        case 0x2A7:
            n = 50;
            break;
        }
        break;
    }
    idx = GetEm00CharIndex(self->actorId, self->emNo);
    Obj0000_Set_Field_424_1595E8(self, n);
    mdl = SearchData((void *)self->resource, D_00448C90, idx);
    tex = SearchData((void *)self->resource, D_00448C98, idx);
    if (self->emNo == 0x2A7 && (self->unk155C & 1)) {
        self->texFlags |= TEXFLAG_EXCHANGE;
        pack = (char *)self->resource;
        cModel_setTextureExchange(self, tex, (void *)EM_RES_REC((int)pack, 0x1C), 0);
    }
    if (tex != 0)
        return cModel_setupModel(self, mdl, tex, 0, 0);
    return 0;
}
