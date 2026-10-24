/* sn-2.95.3-136 */
#include "godhand/cWorldLight.h"
#include "godhand/cOmBase.h"
#include "godhand/cIDManager.h"
#include "godhand/criStm.h"
#include "godhand/gameWork.h"

extern int LightData_Load(cWorldLightBlob4 *data);
extern void Set_bg_mode(int mode, unsigned char r, unsigned char g, unsigned char b);
extern char D_0044D260[];
extern char D_0044D268[];

/* Resets the stage lighting: loads the area tables and light presets from the room pack, or,
 * when the room has none, sets the default sky, fog and an empty light list and fills every
 * preset from it; then sets the three default light directions and colours. */
__attribute__((section(".text.func_002D6F40")))
void func_002D6F40(cWorldLight *self)
{
    cWorldLightTbl *areaTbl = 0;
    cWorldLightTbl *tbl = 0;
    cWorldLightBlob4 *loaded = 0;
    char *far = (char *)self + WORLDLIGHT_FAR_BASE;
    int i;

    WORLDLIGHT_FAR_FIELD(far, int, unk16194) = 0;
    WORLDLIGHT_FAR_FIELD(far, unsigned char, unk1619C) = 0;
    if (D_007474A0.pack != 0) {
        areaTbl = SearchData(D_007474A0.pack, D_0044D260, 0);
        tbl = SearchData(D_007474A0.pack, D_0044D268, 0);
        {
            int j;

            for (j = 0; j < WORLDLIGHT_PRESET_NUM; j++) {
                self->slot[j] = 0;
                if (WORLDLIGHT_FAR_FIELD(far, cWorldLightRec *, preset[j].lights) != 0) {
                    WORLDLIGHT_FAR_FIELD(far, cWorldLightRec *, preset[j].lights) = 0;
                }
            }
        }
        loaded = LightData_Load(&self->lightDataHdr) != 0 ? &self->lightDataHdr : 0;
    }
    if (areaTbl != 0) {
        self->areaTbl = areaTbl;
    }
    if (tbl != 0) {
        self->tbl = tbl;
    }
    self->fadeSlot = 0xFF;
    self->flags = 0;
    if (loaded != 0) {
        unsigned int n;

        for (n = 0; n < WORLDLIGHT_PRESET_NUM; n++) {
            self->presetOrder[n] = n;
        }
    } else {
        cVec one;
        unsigned char k;

        cVec_set4(&one, 1.0f, 1.0f, 1.0f, 1.0f);
        cVec_copy3((cVec *)self->v30, &one);
        cVec_set4(&one, 1.0f, 1.0f, 1.0f, 1.0f);
        cVec_copy3((cVec *)self->ambient, &one);
        cVec_set4(&one, 1.0f, 1.0f, 1.0f, 1.0f);
        cVec_copy3((cVec *)self->v50, &one);
        self->head.b[0] = 0x84;
        self->head.b[1] = 0x7B;
        self->head.b[2] = 0x5B;
        self->head.b[3] = 0x80;
        Set_bg_mode(1, 0x84, 0x7B, 0x5B);
        self->head.b[4] = 0xFF;
        self->head.b[5] = 0xFF;
        self->head.b[6] = 0xFF;
        self->head.b[7] = 0x80;
        self->head.b[8] = 0xFF;
        self->head.b[9] = 0xFF;
        self->head.b[10] = 0xFF;
        self->head.b[11] = 0x80;
        self->head.b[12] = 0xFF;
        self->head.b[13] = 0xFF;
        self->head.b[14] = 0xFF;
        self->head.b[15] = 0x80;
        self->b6C.b[0] = 0xFF;
        self->b6C.b[1] = 0xFF;
        self->b6C.b[2] = 0xFF;
        self->b6C.b[3] = 0x80;
        self->lightNum = 0;
        self->f10[0] = 100.0f;
        self->f10[1] = 600.0f;
        self->f64 = 100.0f;
        self->f68 = 600.0f;
        self->f10[2] = 100.0f;
        self->f10[3] = 600.0f;
        self->f10[4] = 100.0f;
        self->f10[5] = 600.0f;
        self->f70 = 100.0f;
        self->f74 = 600.0f;
        func_003A52F0(self->light, 0, sizeof(self->light));
        for (i = WORLDLIGHT_LIGHT_NUM - 1; i >= 0; i--) {
            self->light[i].state = WORLDLIGHT_LIGHT_FREE;
        }
        for (i = 0; i < WORLDLIGHT_EXTRA_NUM; i++) {
            self->extra[i].w[0] = 0;
            self->extra[i].w[1] = 0;
            self->extra[i].w[2] = 0;
            self->extra[i].w[3] = 0;
            self->extra[i].b[0] = 0;
            self->extra[i].b[1] = 0;
            self->extra[i].b[2] = 0;
        }
        k = WORLDLIGHT_PRESET_NUM;
        do {
            self->slot[k - 1] = 0;
            cWorldLight_savePreset(self, &self->preset[k - 1], self);
        } while (--k != 0);
    }
    cVec_set4((cVec *)self->lightDir[0], -0.5f, -0.5f, -0.5f, 0.0f);
    cVec_set4((cVec *)self->lightDir[1], 0.5f, 0.5f, 0.5f, 0.0f);
    cVec_set4((cVec *)self->lightDir[2], 0.5f, -0.5f, 0.5f, 0.0f);
    cVec_set4((cVec *)self->lightCol[0], 1.0f, 1.0f, 1.0f, 1.0f);
    cVec_set4((cVec *)self->lightCol[1], 0.5f, 0.5f, 0.5f, 1.0f);
    cVec_set4((cVec *)self->lightCol[2], 0.8f, 0.8f, 0.8f, 1.0f);
    self->fogNear = self->f10[0];
    self->fogFar = self->f10[1];
    self->fogColor[0] = self->head.b[4];
    self->fogColor[1] = self->head.b[5];
    self->fogColor[2] = self->head.b[6];
    self->areaIdPrev = 0;
    self->unk1614C = 0xFF;
    self->unk16148 = 0xFF;
    self->unk16144 = 0xFF;
}
