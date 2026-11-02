/* sn-2.95.3-136 */
#include "godhand/effModelObj.h"
#include "godhand/EspDataBank.h"
#include "godhand/espSys.h"
#include "godhand/player.h"
#include "godhand/cObjBase.h"

/* The error messages, one per failing step. */
extern char D_0044ED00[];               /* "esp20: model[%d] data not found." */
extern char D_0044ED28[];               /* "esp20: model create failed." */
extern char D_0044ED48[];               /* "esp20: model initial failed." */
extern char D_0044ED68[];               /* "esp20: TYPE invalid." */
extern char D_0044ED80[];               /* "esp20: EFF_TEX setup failed." */
extern char D_0044EDA0[];               /* "esp20: model setup failed." */

extern int cModel_setupModel(void *model, void *mdl, void *tex, int a3, int a4);
extern int SetEffect(int kind, int id, void *owner, cEffectParam *param, int handle, unsigned int follow);

/* Build the effect object's model: look up its model data, create the model
 * object and set it up (with the effect's T32 table in the modes that use
 * one), then start the effect group on it if there is one. Prints the error
 * and returns 0 when a step fails, releasing the model once it exists. */
__attribute__((section(".text.func_002F1B60")))
int func_002F1B60(EffModelObj *self)
{
    cEffectParam param;
    void *mdl;
    void *tex;

    if (func_00306C78(D_00741DC8.res, self->modelNo, &mdl, &tex) == 0) {
        func_002D9F68(self, (int)D_0044ED00, self->modelNo);
        return 0;
    }
    self->model = CreateObj(EFFOBJ_MODEL_KIND, EFFOBJ_MODEL_ID);
    if (self->model == 0) {
        func_002D9F68(self, (int)D_0044ED28);
        return 0;
    }
    if (self->model->vt->initial((char *)self->model + self->model->vt->initialDelta) == 0) {
        func_002D9F68(self, (int)D_0044ED48);
        ReleaseObj((char *)self->model);
        return 0;
    }
    if (self->mode >= EFFOBJ_MODE_MAX) {
        func_002D9F68(self, (int)D_0044ED68);
        ReleaseObj((char *)self->model);
        return 0;
    }
    if (self->mode & EFFOBJ_MODE_T32) {
        tex = espSys_getEffT32Addr(D_007419A0, self->rec->t32Kind, self->t32Idx);
        if (tex == 0) {
            func_002D9F68(self, (int)D_0044ED80);
            ReleaseObj((char *)self->model);
            return 0;
        }
    }
    if (cModel_setupModel(self->model, mdl, tex, 0, 0) == 0) {
        func_002D9F68(self, (int)D_0044EDA0);
        ReleaseObj((char *)self->model);
        return 0;
    }
    if (self->effGroup != 0) {
        cEffectParam_init(&param);
        param.flags = self->effFlags;
        param.unk74 = self->effGroup;
        param.size = self->size;
        param.unk70 = 0;
        param.unk72 = 0;
        param.unk78 = 0;
        SetEffect(self->effKind, self->effNo, self->model, &param, -1, 0xFFFFFFFF);
    }
    return 1;
}
