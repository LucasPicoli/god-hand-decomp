/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cObjBase.h"

extern void *Getplayer(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int moveMotion(void *a0);
extern void cCamManager_setPartsCamera(void *cam, int mode);
extern void cPartsCamera_SetParts(void *parts, void *obj, int a2, int a3);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void Obj1D00_ClearState_9(void *a0);
extern int D_00463050;


/* Phase machine on the step byte, 15 case labels. Calls Getplayer, VU0_SQC2_VF0,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, func_002705D8 and 7 more. */
__attribute__((section(".text.func_00212C08"))) void func_00212C08(cEm00 *self)
{
    char *s1 = (char *)self;
    cEffectParam s;
    void *s2;
    char *base;
    char *parts;
    int a2v;
    int a3v;
    int b;
    int lim;
    int nb;
    int spill[2];

    s2 = Getplayer();
    s.color.x = 1.0f;
    s.color.y = 1.0f;
    s.color.z = 1.0f;
    s.color.w = 1.0f;
    VU0_SQC2_VF0(&s, 0x10);
    VU0_SQC2_VF0(&s, 0x20);
    {
        float *q = &s.scale.x;
        s.scale.x = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    s.size = 1.0f;
    s.unk4C = -1;
    s.unk4F = 0xFF;
    s.unk44 = 0;
    s.flags = 0;
    s.unk4D = 0;
    s.unk4E = 0;
    s.unk50 = 0;
    VU0_SQC2_VF0(&s, 0x60);
    s.unk70 = 0;
    s.size = *(float *)(s1 + 0x114);
    s.unk72 = 0;
    s.unk74 = 0;
    s.unk78 = 0;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            switch (*(int *)(s1 + 0x564)) {
                case 0x220:
                case 0x221:
                case 0x222:
                default: {
                    int v0 = *(int *)(s1 + 0x304);
                    func_002A8578(s1, EM_RES_REC(v0, 0x1D08), EM_RES_REC(v0, 0x1D0C), 3, 0.0f, nb,
                                  0);
                } break;
                case 0x223: {
                    int v0 = *(int *)(s1 + 0x304);
                    func_002A8578(s1, EM_RES_REC(v0, 0x2E4C), EM_RES_REC(v0, 0x2E50), 3, 0.0f, nb,
                                  0);
                } break;
                case 0x209: {
                    int v0 = *(int *)(s1 + 0x304);
                    func_002A8578(s1, EM_RES_REC(v0, 0x34F4), EM_RES_REC(v0, 0x34F8), 3, 0.0f, nb,
                                  0);
                } break;
            }
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 1:
            if (moveMotion(s1) != 0) {
                func_002705D8(s1);
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            return;
        case 2:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            {
                int v0 = *(int *)(s1 + 0x304);
                func_002A8578(s1, EM_RES_REC(v0, 0x1D78), EM_RES_REC(v0, 0x1D7C), 0, 0.0f, nb, 0);
            }
            *(unsigned char *)(s1 + 0x616) = 1;
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 3:
            base = (char *)&D_00463050;
            cCamManager_setPartsCamera(base, 0);
            parts = base + 0x920;
            b = *(unsigned char *)(s1 + 0x2B4);
            spill[0] = b;
            lim = 0x1B;
            if (lim < b) {
                a2v = *(int *)(*(int *)(s1 + 0x278) + 0x6C);
            } else {
                a2v = 0;
            }
            b = *(unsigned char *)(s1 + 0x2B4);
            spill[0] = b;
            lim = 0x1C;
            if (lim < b) {
                a3v = *(int *)(*(int *)(s1 + 0x278) + 0x70);
            } else {
                a3v = 0;
            }
            cPartsCamera_SetParts(parts, s1, a2v, a3v);
            *(float *)(s1 + 0x54C) = 3.0f;
            if (moveMotion(s1) != 0) {
                pl00_clearMotionCam(s2, 0, 1);
                func_002705D8(s1);
                *(unsigned char *)(s1 + 0x616) = 0;
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            return;
        case 4:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            {
                int v0 = *(int *)(s1 + 0x304);
                func_002A8578(s1, EM_RES_REC(v0, 0x2EE4), EM_RES_REC(v0, 0x2EE8), 0, 0.0f, nb, 0);
            }
            SetEffect(0x7B, 0xB9, (cObj *)self, 0, -1, EFFECT_FOLLOW_OWNER);
            *(unsigned char *)(s1 + 0x616) = 1;
            if (*(int *)(s1 + 0x6F4) != 0) {
                Obj1D00_ClearState_9(*(void **)(s1 + 0x6F4));
            }
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 5:
            *(float *)(s1 + 0x54C) = 3.0f;
            if (moveMotion(s1) != 0) {
                SetEffect(0x7B, 0xB7, (cObj *)self, &s, 1, EFFECT_FOLLOW_OWNER);
                func_002705D8(s1);
                *(unsigned char *)(s1 + 0x616) = 0;
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            return;
        case 6:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            {
                int v0 = *(int *)(s1 + 0x304);
                func_002A8578(s1, EM_RES_REC(v0, 0x3418), EM_RES_REC(v0, 0x341C), 3, 0.0f, nb, 0);
            }
            *(unsigned char *)(s1 + 0x616) = 1;
            *(float *)(s1 + 0x600) = 30.0f;
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 7:
            *(float *)(s1 + 0x54C) = 3.0f;
            moveMotion(s1);
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            *(float *)(s1 + 0x600) = *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
            if (*(float *)(s1 + 0x600) <= 0.0f) {
                *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
            }
            break;
        case 8:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            {
                int v0 = *(int *)(s1 + 0x304);
                func_002A8578(s1, EM_RES_REC(v0, 0x3420), EM_RES_REC(v0, 0x3424), 3, 0.0f, nb, 0);
            }
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 9:
            *(float *)(s1 + 0x54C) = 3.0f;
            if (moveMotion(s1) != 0) {
                func_002705D8(s1);
                *(unsigned char *)(s1 + 0x616) = 0;
            }
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            break;
    }
}
