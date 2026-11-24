/* sn-2.95.3-136 matched TU. */

#include "godhand/cObjBase.h"
#include "godhand/vu0.h"

extern void SetCustomIDDispOneOrAll_1F4778(void *self, int id, int on);
extern void CustomIDOwner_setAllShown(void *self, int on);
extern void func_001F4928(void *self, int on);
extern void Effect_killByModeB(int a0, int a1);
extern int EffEventIsCutDataExist(unsigned int id);

#define DISP_ALL  0x6F                  /* id that stands for every element */

/* Opens the display: hides everything, shows elements 0..9 one by one, then starts the two animations. */
__attribute__((section(".text.DispMenu_open")))
void DispMenu_open(void *self) {
    SetCustomIDDispOneOrAll_1F4778(self, DISP_ALL, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 1, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 2, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 3, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 4, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 5, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 6, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 7, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 8, 1);
    SetCustomIDDispOneOrAll_1F4778(self, 9, 1);
    CustomIDOwner_setAllShown(self, 1);
    func_001F4928(self, 1);
}

#define EFFECT_CUT_KIND     6
#define EFFECT_CUT_HANDLE   0x2500
#define EFFECT_PARAM_CUT    0xE         /* flags bits the cut effect asks for */

/* Starts the event cut effect for id when its cut data exists. */
__attribute__((section(".text.SetEventCutEffect")))
void SetEventCutEffect(unsigned int id) {
    cEffectParam param;
    cVec *scale;

    Effect_killByModeB(4, 2);
    if (EffEventIsCutDataExist(id) == 1) {
        param.color.x = 1.0f;
        param.color.y = 1.0f;
        param.color.z = 1.0f;
        param.color.w = 1.0f;
        VU0_SQC2_VF0(&param, 0x10);
        VU0_SQC2_VF0(&param, 0x20);
        scale = &param.scale;
        param.scale.x = 1.0f;
        scale->y = 1.0f;
        scale->z = 1.0f;
        scale->w = 1.0f;
        param.size = 1.0f;
        param.unk4C = -1;
        param.unk4F = 0xFF;
        param.unk44 = 0;
        param.flags = 0;
        param.unk4D = 0;
        param.unk4E = 0;
        param.unk50 = 0;
        VU0_SQC2_VF0(&param, 0x60);
        param.flags |= EFFECT_PARAM_CUT;
        param.unk70 = 0;
        param.unk72 = 0;
        param.unk74 = 0;
        param.unk78 = 0;
        SetEffect(EFFECT_CUT_KIND, id + 1, 0, &param, id + EFFECT_CUT_HANDLE, EFFECT_FOLLOW_OWNER);
    }
}

extern float func_003A19F8(float x);    /* sin */
extern float func_003A18F0(float x);    /* cos */

/* Builds the quaternion q = (x, y, z, w) of an X, Y, Z euler rotation (radians, euler[0..2]). */
__attribute__((section(".text.Quaternion_SetEulerXYZ")))
void Quaternion_SetEulerXYZ(float *q, float *euler) {
    float hx = euler[0] * 0.5f;
    float hy = euler[1] * 0.5f;
    float hz = euler[2] * 0.5f;
    float sx = func_003A19F8(hx);
    float cx = func_003A18F0(hx);
    float sy = func_003A19F8(hy);
    float cy = func_003A18F0(hy);
    float sz = func_003A19F8(hz);
    float cz = func_003A18F0(hz);

    q[0] = sx * cy * cz - cx * sy * sz;
    q[1] = cx * cz * sy + sx * sz * cy;
    q[2] = cx * cy * sz - sx * sy * cz;
    q[3] = cx * cz * cy + sx * sz * sy;
}
