/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
extern char D_00741DC8[];
extern int func_00306C78(void **table, unsigned int index, void *out1, void *out2);
extern char *CreateObj(int a0, int a1);
extern char D_0044F110[], D_0044F130[];
extern void func_002D9F68(void *, int, ...);
extern int cModel_setupModel(void *a, void *b, void *c, int d, int e);
extern void ReleaseObj(void *a0);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
typedef struct {
    char pad0[0x104]; int field104; char pad108[0x23A-0x108];
    short effect; unsigned short variant; char pad23E[0x2B0-0x23E];
    void *model; unsigned int index; char pad2B8[0x24];
    unsigned char enabled; char pad2DD[3]; float scale;
} EffectOwner;
typedef struct {
    cVec color, pos, rotation, size;
    float scale; int field44, field48; signed char red; unsigned char green, blue, alpha; int field50;
    char pad54[12]; cVec vector; short field70, field72;
    unsigned char enabled; char pad75[3]; int field78;
} EffectParams;
static __inline__ void unitSize(cVec *size)
{
    size->x = 1.0f;
    size->y = 1.0f;
    size->z = 1.0f;
    size->w = 1.0f;
}
/* Create the model and attach its optional effect. */
__attribute__((section(".text.func_002F4290")))
int func_002F4290(EffectOwner *self)
{
    EffectParams params __attribute__((aligned(16)));
    void *modelData, *modelInfo;
    char *model;
    unsigned char enabled;
    if (!func_00306C78((void **)D_00741DC8, self->index, &modelData, &modelInfo) ||
        (self->model = model = CreateObj(0x500, 0xFFFF), !model)) {
        func_002D9F68(self, (int)D_0044F110);
        return 0;
    }
    if (!cModel_setupModel(model, modelData, modelInfo, 0, 0)) {
        func_002D9F68(self, (int)D_0044F130);
        ReleaseObj(self->model);
        return 0;
    }
    enabled = self->enabled;
    if (enabled) {
        params.color.x = 1.0f;
        params.color.y = 1.0f;
        params.color.z = 1.0f;
        params.color.w = 1.0f;
        VU0_SQC2_VF0(&params, 16);
        VU0_SQC2_VF0(&params, 32);
        unitSize(&params.size);
        params.scale = 1.0f;
        params.red = -1;
        params.alpha = 255;
        params.field44 = 0;
        params.field48 = 0;
        params.green = 0;
        params.blue = 0;
        params.field50 = 0;
        VU0_SQC2_VF0(&params, 96);
        params.field48 = self->field104;
        params.enabled = enabled;
        params.scale = self->scale;
        params.field70 = 0;
        params.field72 = 0;
        params.field78 = 0;
        SetEffect(self->effect, self->variant, self->model, (int)&params, -1, 0xFFFFFFFFU);
    }
    return 1;
}
