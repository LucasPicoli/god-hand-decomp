/* sn-2.95.3-136 matched TU. */

#include "godhand/cWorldLight.h"

/* Restores the lights from the backup copy. */
__attribute__((section(".text.Forward2D9458_2D98A0")))
void Forward2D9458_2D98A0(cWorldLight *self)
{
    func_002D9458(self, self->backup);
}

/* Fills preset dst from the live settings (src); every slot of its light array gets light 0. */
__attribute__((section(".text.cWorldLight_savePreset")))
void cWorldLight_savePreset(cWorldLight *self, cWorldLightPreset *dst, cWorldLight *src)
{
    float *dv;
    float *sv;
    int i;

    dv = dst->v30;
    sv = src->v30;
    if (dv != sv) {
        dv[0] = sv[0];
        dv[1] = sv[1];
        dv[2] = sv[2];
    }
    dv = dst->ambient;
    sv = src->ambient;
    if (dv != sv) {
        dv[0] = sv[0];
        dv[1] = sv[1];
        dv[2] = sv[2];
    }
    dst->head.w[0] = src->head.w[0];
    dst->head.w[1] = src->head.w[1];
    dst->head.w[2] = src->head.w[2];
    dst->head.w[3] = src->head.w[3];
    dst->f10[0] = src->f10[0];
    dst->f10[1] = src->f10[1];
    dst->f10[2] = src->f10[2];
    dst->f10[3] = src->f10[3];
    dst->f10[4] = src->f10[4];
    dst->f10[5] = src->f10[5];
    dst->b60 = src->b60;
    dst->f64 = src->f64;
    dst->f68 = src->f68;
    dst->b6C = src->b6C;
    dst->f70 = src->f70;
    dst->f74 = src->f74;
    dst->lightNum = src->lightNum;
    for (i = 0; i < dst->lightNum; i++) {
        if (dst->lights != 0) {
            dst->lights[i] = src->light[0];
        }
    }
}

/* Looks up entry id in the table at 0x16130 and returns its value, or 1.0
 * when there is no table or no match. vp walks the value fields, so the
 * entry id is the byte two before it. The union keeps the result in an
 * integer register, as retail does. */
__attribute__((section(".text.cWorldLight_getTblValue")))
float cWorldLight_getTblValue(cWorldLight *self, int id)
{
    union { float f; int i; } r;
    cWorldLightTbl *tbl = self->tbl;
    float *vp;
    unsigned int i;
    unsigned int n;

    if (tbl == 0 || id == 0) {
        return 1.0f;
    }
    r.f = 1.0f;
    vp = &tbl->ent[0].value;
    n = tbl->num;
    for (i = 0; i < n; i++) {
        if (*((unsigned char *)vp - 2) == id) {
            r.f = *vp;
            break;
        }
        vp += sizeof(cWorldLightTblEnt) / sizeof(float);
    }
    return r.f;
}
