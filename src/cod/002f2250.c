/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cCamera.h"

extern void UpdateObjByIndexedOp_2FBE50(void *a0);
extern void func_002FBED0(int a0);
extern int func_002FB060(char *a0);
extern void *CopyVec16From20_B62E0(void *a0, char *a1);
extern void cNode_setLocalScale(int a0, int a1);
extern void *StoreVecFromFieldB0_2B6160(void *a0, void *a1);
extern void *func_002B60D0(void *a0, void *a1);
extern int func_00307118(void *p);
extern int cModel_getMeshNum(cModel *self);
extern float capVu0Sin(float f12);
extern float capVu0Cos(float f12);
extern void func_00148200(void *a0, float x, float y);
extern void func_00148250(void *a0, float a, float b);
extern void Mtx4_setRotZ(float *m, float a);
extern void MtxMultiply(void *dst, void *a, void *b);
extern void func_001491D0(void *a0, void *a1);

/* The object an effect follows. */
typedef struct espModelOwner {
    char unk00[0x250];
    int objFlags;                       /* 0x250 negative once the object is gone */
} espModelOwner;

/* The link from an effect to the object it follows. */
typedef struct espModelLink {
    char unk00[8];
    float alpha;                        /* 0x08 */
    espModelOwner *owner;               /* 0x0C */
    int flags;                          /* 0x10 bit 1: scale the effect's alpha by alpha */
} espModelLink;

/* An effect drawn with a model: a texture that scrolls, waves and turns. */
typedef struct espModel {
    char unk000[0x120];
    espModelLink *link;                 /* 0x120 */
    char unk124[0x188 - 0x124];
    float color[4];                     /* 0x188 */
    char unk198[0x24C - 0x198];
    unsigned char frameNum;             /* 0x24C */
    unsigned char frameNo;              /* 0x24D */
    char unk24E[0x2B0 - 0x24E];
    cModel *model;                      /* 0x2B0 */
    char unk2B4[0x2BC - 0x2B4];
    float uvSpeed[2];                   /* 0x2BC */
    float uvAmp[2];                     /* 0x2C4 */
    float uvWaveSpeed[2];               /* 0x2CC */
    float uvPhase[2];                   /* 0x2D4 */
    char unk2DC[0x2E9 - 0x2DC];
    unsigned char uvMode;               /* 0x2E9 1: the texture matrix is built */
    char unk2EA[2];
    float uvScale[2];                   /* 0x2EC */
    float uvRot;                        /* 0x2F4 */
    float uvRotSpeed;                   /* 0x2F8 */
} espModel;

/* Whether the object the effect follows is still there; drops the link once it is gone. */
static __inline__ int espModel_linkAlive(espModel *self)
{
    espModelLink *link = self->link;

    if (link != 0) {
        if (link->owner->objFlags >= 0) {
            if (func_00307118(link) == 1)
                return 1;
        } else {
            self->link = 0;
        }
    }
    return 0;
}

/* Moves the effect's model with it, fades it, and scrolls, waves and turns its texture. */
__attribute__((section(".text.func_002F2250")))
void func_002F2250(espModel *self)
{
    cVec scale;
    cVec v;
    float uvMtx[16];
    float pre[16];
    float rot[16];
    float post[16];
    float sc[16];
    float alpha;
    cModelNode *mesh;
    cModelNode *node;
    unsigned int n;
    unsigned int i;

    if (self->model == 0) {
        UpdateObjByIndexedOp_2FBE50(self);
        return;
    }
    func_002FBED0((int)self);
    if (func_002FB060((char *)self) != 0) {
        CopyVec16From20_B62E0(&scale, (char *)self);
        scale.z = scale.x;
        cNode_setLocalScale((int)self, (int)&scale);
        {
            cModel *model = self->model;

            StoreVecFromFieldB0_2B6160(&v, self);
            cVec_copy3(model->pos, &v);
        }
        func_002B60D0(&v, self);
        cVec_copy3(&self->model->rot, &v);
        cVec_copy3(&self->model->scale, &scale);
        alpha = 1.0f;
        if (self->frameNum != 0)
            alpha = (float)(self->frameNum - self->frameNo) / (float)self->frameNum;
        if (espModel_linkAlive(self) == 1 && (self->link->flags >> 1 & 1) != 0)
            alpha *= self->link->alpha;
        self->model->tint.x = self->color[0];
        self->model->tint.y = self->color[1];
        self->model->tint.z = self->color[2];
        self->model->tint.w = self->color[3];
        self->model->tint.w *= alpha;
        mesh = cModel_getMeshPtr(self->model, 0);
        mesh->uvScroll[0] += self->uvSpeed[0];
        mesh->uvScroll[1] += self->uvSpeed[1];
        if (self->uvWaveSpeed[0] != 0.0f) {
            mesh->uvScroll[0] += capVu0Sin(self->uvPhase[0]) * self->uvAmp[0];
            self->uvPhase[0] += self->uvWaveSpeed[0];
            self->uvPhase[0] = Adjust_theta(self->uvPhase[0]);
        }
        if (self->uvWaveSpeed[1] != 0.0f) {
            mesh->uvScroll[1] += capVu0Cos(self->uvPhase[1]) * self->uvAmp[1];
            self->uvPhase[1] += self->uvWaveSpeed[1];
            self->uvPhase[1] = Adjust_theta(self->uvPhase[1]);
        }
        if (mesh->uvScroll[0] > 2.0f)
            mesh->uvScroll[0] -= 2.0f;
        if (mesh->uvScroll[0] < -2.0f)
            mesh->uvScroll[0] += 2.0f;
        if (mesh->uvScroll[1] > 2.0f)
            mesh->uvScroll[1] -= 2.0f;
        if (mesh->uvScroll[1] < -2.0f)
            mesh->uvScroll[1] += 2.0f;
        if (self->uvMode == 1) {
            if (self->uvRot != 0.0f || self->uvRotSpeed != 0.0f) {
                self->uvRot += self->uvRotSpeed;
                self->uvRot = Adjust_theta(self->uvRot);
                func_00148200(pre, -0.5f, 0.5f);
                Mtx4_setRotZ(rot, self->uvRot);
                func_00148200(post, 0.5f, -0.5f);
                MtxMultiply(post, post, rot);
                MtxMultiply(uvMtx, post, pre);
                func_00148250(sc, self->uvScale[0], self->uvScale[1]);
                MtxMultiply(uvMtx, sc, uvMtx);
            } else {
                func_00148250(uvMtx, self->uvScale[0], self->uvScale[1]);
            }
            uvMtx[8] += mesh->uvScroll[0];
            uvMtx[9] += mesh->uvScroll[1];
            func_001491D0(mesh, uvMtx);
        }
        n = cModel_getMeshNum(self->model);
        if (n >= 2) {
            for (i = 1; i < n; i++) {
                node = cModel_getMeshPtr(self->model, i);
                if (self->uvMode == 1) {
                    func_001491D0(node, uvMtx);
                } else {
                    node->uvScroll[0] = mesh->uvScroll[0];
                    node->uvScroll[1] = mesh->uvScroll[1];
                }
            }
        }
    } else if (self->model != 0) {
        self->model->objFlags |= 2;
    }
}
