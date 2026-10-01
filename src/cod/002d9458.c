/* sn-2.95.3-136 matched TU. */
#include "godhand/cWorldLight.h"

typedef struct {
    int a[5];
} T20;

/* Copies the whole light state (settings, lights, extra records) from src to dst. */
__attribute__((section(".text.func_002D9458")))
void *func_002D9458(cWorldLight *dst, cWorldLight *src) {
    cWorldLightRec *di;
    cWorldLightRec *si;
    cWorldLightExtra *dq;
    cWorldLightExtra *sq;
    int i;
    int j;
    int k;

    dst->head.b[0x0] = src->head.b[0x0];
    dst->head.b[0x1] = src->head.b[0x1];
    dst->head.b[0x2] = src->head.b[0x2];
    dst->head.b[0x3] = src->head.b[0x3];
    dst->head.b[0x4] = src->head.b[0x4];
    dst->head.b[0x5] = src->head.b[0x5];
    dst->head.b[0x6] = src->head.b[0x6];
    dst->head.b[0x7] = src->head.b[0x7];
    dst->head.b[0x8] = src->head.b[0x8];
    dst->head.b[0x9] = src->head.b[0x9];
    dst->head.b[0xA] = src->head.b[0xA];
    dst->head.b[0xB] = src->head.b[0xB];
    dst->head.b[0xC] = src->head.b[0xC];
    dst->head.b[0xD] = src->head.b[0xD];
    dst->head.b[0xE] = src->head.b[0xE];
    dst->head.b[0xF] = src->head.b[0xF];
    dst->f10[0] = src->f10[0];
    dst->f10[1] = src->f10[1];
    dst->f10[2] = src->f10[2];
    dst->f10[3] = src->f10[3];
    dst->f10[4] = src->f10[4];
    dst->f10[5] = src->f10[5];
    {
        float *sv = src->v30;
        float *dv = dst->v30;
        if (dv != sv) {
            dv[0] = sv[0];
            dv[1] = sv[1];
            dv[2] = sv[2];
        }
    }
    {
        float *dv = dst->ambient;
        float *sv = src->ambient;
        if (dv != sv) {
            dv[0] = sv[0];
            dv[1] = sv[1];
            dv[2] = sv[2];
        }
    }
    {
        float *dv = dst->v50;
        float *sv = src->v50;
        if (dv != sv) {
            dv[0] = sv[0];
            dv[1] = sv[1];
            dv[2] = sv[2];
        }
    }
    dst->b60.b[0] = src->b60.b[0];
    dst->b60.b[1] = src->b60.b[1];
    dst->b60.b[2] = src->b60.b[2];
    dst->b60.b[3] = src->b60.b[3];
    dst->f64 = src->f64;
    dst->f68 = src->f68;
    dst->b6C.b[0] = src->b6C.b[0];
    dst->b6C.b[1] = src->b6C.b[1];
    dst->b6C.b[2] = src->b6C.b[2];
    dst->b6C.b[3] = src->b6C.b[3];
    dst->f70 = src->f70;
    dst->f74 = src->f74;
    dst->lightNum = src->lightNum;

    di = dst->light;
    i = 0xFF;
    si = src->light;
    do {
        di->state = si->state;
        di->id = si->id;
        di->unk04 = si->unk04;
        {
            float *dv = di->v10;
            float *sv = si->v10;
            if (dv != sv) {
                dv[0] = sv[0];
                dv[1] = sv[1];
                dv[2] = sv[2];
            }
        }
        {
            float *dv = di->v20;
            float *sv = si->v20;
            if (dv != sv) {
                dv[0] = sv[0];
                dv[1] = sv[1];
                dv[2] = sv[2];
            }
        }
        {
            float *dv = di->v30;
            float *sv = si->v30;
            if (dv != sv) {
                dv[0] = sv[0];
                dv[1] = sv[1];
                dv[2] = sv[2];
            }
        }
        di->f40 = si->f40;
        di->f44 = si->f44;
        di->f48 = si->f48;
        {
            int *dw = &di->ownerIdx;
            int *sw;
            j = 1;
            sw = &si->ownerIdx;
            do {
                *dw = *sw;
                sw++;
                dw++;
                j--;
            } while (j != -1);
        }
        di->key = si->key;
        di->flags = si->flags;
        di->f5C = si->f5C;
        di->f5E = si->f5E;
        di->f60 = si->f60;
        di->f61 = si->f61;
        di->f62 = si->f62;
        di++;
        si++;
        i--;
    } while (i != -1);

    dq = dst->extra;
    sq = src->extra;
    k = 0x2F;
    do {
        *dq = *sq;
        dq++;
        sq++;
        k--;
    } while (k != -1);

    dst->extraNum = src->extraNum;
    return dst;
}
