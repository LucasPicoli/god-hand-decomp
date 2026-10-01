/* sn-2.95.3-136 matched TU. */
#include "godhand/cObjSimple.h"

extern void *SearchData(void *a, void *b, int c);
extern void cModel_setTextureExchange(void *self, void *tex, int tbl, int n);
extern char D_0044B4A8[];
extern char D_0044B4B0[];

/* sn-2.95.3-136 matched TU. */






/* Address of the texture table at `off` in the model data: the entry holds its offset from the model. */
#define COBJSIMPLE_MODEL_TBL(self, off) \
    (*(int *)((char *)(self)->model + (off)) + (int)(self)->model)

/* Find a texture-change mesh in the model (the second name if the first is missing) and,
 * for the object ids that have a table, start the texture exchange with `n`. */
__attribute__((section(".text.cObjSimple__SetTexChange")))
void cObjSimple__SetTexChange(cObjSimple *self, int n) {
    void *m;
    int val;

    if (self->texChangeOn == 0) {
        m = SearchData(self->model, &D_0044B4A8, 0);
        if (m == 0) {
            m = SearchData(self->model, &D_0044B4B0, 0);
        }
    } else {
        m = SearchData(self->model, &D_0044B4A8, self->texChangeIdx);
        if (m == 0) {
            m = SearchData(self->model, &D_0044B4B0, self->texChangeIdx);
        }
    }
    switch (self->objId) {
    case 0x227:
        val = COBJSIMPLE_MODEL_TBL(self, 0x44);
        break;
    case 0x228:
        val = COBJSIMPLE_MODEL_TBL(self, 0x48);
        break;
    case 0x229:
        val = COBJSIMPLE_MODEL_TBL(self, 0x4C);
        break;
    case 0x22A:
        val = COBJSIMPLE_MODEL_TBL(self, 0x50);
        break;
    case 0x22B:
        val = COBJSIMPLE_MODEL_TBL(self, 0x54);
        break;
    case 0x22C:
        val = COBJSIMPLE_MODEL_TBL(self, 0x58);
        break;
    case 0x22D:
        val = COBJSIMPLE_MODEL_TBL(self, 0x78);
        break;
    case 0x22E:
        val = COBJSIMPLE_MODEL_TBL(self, 0x70);
        break;
    case 0x243:
        val = COBJSIMPLE_MODEL_TBL(self, 0x80);
        break;
    case 0x24A:
        val = COBJSIMPLE_MODEL_TBL(self, 0x64);
        break;
    case 0x24B:
        val = COBJSIMPLE_MODEL_TBL(self, 0x6C);
        break;
    case 0x24C:
        val = COBJSIMPLE_MODEL_TBL(self, 0x74);
        break;
    case 0x24D:
        val = COBJSIMPLE_MODEL_TBL(self, 0x7C);
        break;
    case 0x24E:
        val = COBJSIMPLE_MODEL_TBL(self, 0x88);
        break;
    case 0x271:
    case 0x272:
    case 0x273:
        val = COBJSIMPLE_MODEL_TBL(self, 0x5C);
        break;
    default:
        val = 0;
        break;
    }
    if (m != 0) {
        if (val != 0) {
            self->drawFlags = self->drawFlags | 0x10000000;
            cModel_setTextureExchange(self, m, val, n);
        }
    }
}
