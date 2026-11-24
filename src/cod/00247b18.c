/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/globals.h"
#include "godhand/cObjBase.h"

extern void *Getplayer(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int moveMotion(void *a0);
extern void cEm00_attachToTarget(void *a0, void *a1);

extern void cCamManager_setPartsCamera(void *cam, int mode);
extern void cPartsCamera_SetParts(void *parts, void *obj, int a2, int a3);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void ReleaseObj(void *a0);
extern void func_00275DA8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int D_00463050;


/* Phase machine on the step byte, 4 case labels. Calls Getplayer,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, cEm00_attachToTarget, cModel_getMeshPtr_14B730,
 * cCamManager_setPartsCamera and 9 more. */
__attribute__((section(".text.func_00247B18"))) void func_00247B18(cEm00 *self)
{
    char *s1 = (char *)self;
    char *s2;
    int spill[2];
    cEffectParam s;
    char *v;
    char *base;
    char *parts;
    int nb, b, lim, a2v, a3v;
    float one;
    float *fp;

    s2 = (char *)Getplayer();
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x40000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0:
            *(char *)(s1 + 0x1864) = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            b = *(int *)(s1 + 0x304);
            func_002A8578(s1, EM_RES_REC(b, 0x38B0), EM_RES_REC(b, 0x38B4), 0, 0.0f, nb, 0);
            if (*(void **)(s1 + 0x744) != 0) {
                cEm00_attachToTarget(*(void **)(s1 + 0x744), s1);
            }
            *(float *)(s1 + 0x1768) = 600.0f;
            v = cModel_getMeshPtr_14B730(s1, &D_0042CAD0);
            if (v != 0) {
                *(int *)(v + 0x380) = *(int *)(v + 0x380) & 0xFFFFFFFE;
            }
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 1:
            *(float *)(s1 + 0x54C) = 3.0f;
            base = (char *)&D_00463050;
            cCamManager_setPartsCamera(base, 0);
            parts = base + 0x920;
            b = *(unsigned char *)(s1 + 0x2B4);
            spill[0] = b;
            lim = 0x24;
            if (lim < b) {
                a2v = *(int *)(*(int *)(s1 + 0x278) + 0x90);
            } else {
                a2v = 0;
            }
            b = *(unsigned char *)(s1 + 0x2B4);
            spill[0] = b;
            lim = 0x25;
            if (lim < b) {
                a3v = *(int *)(*(int *)(s1 + 0x278) + 0x94);
            } else {
                a3v = 0;
            }
            cPartsCamera_SetParts(parts, s1, a2v, a3v);
            *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x800000;
            if (moveMotion(s1) != 0) {
                pl00_clearMotionCam(s2, 0, 1);
                if (*(void **)(s1 + 0x744) != 0) {
                    ReleaseObj(*(void **)(s1 + 0x744));
                    *(int *)(s1 + 0x744) = 0;
                    func_00275DA8(s1);
                }
                fp = &s.color.x;
                s.color.x = 1.0f;
                fp[1] = 1.0f;
                fp[2] = 1.0f;
                fp[3] = 1.0f;
                VU0_SQC2_VF0(spill, 0x20);
                VU0_SQC2_VF0(spill, 0x30);
                {
                    float *q = &s.scale.x;
                    s.scale.x = 1.0f;
                    q[1] = 1.0f;
                    q[2] = 1.0f;
                    q[3] = 1.0f;
                }
                fp[0x10] = 1.0f;
                s.unk44 = 0;
                s.flags = 0;
                ((signed char *)fp)[0x4C] = -1;
                s.unk4D = 0;
                s.unk4E = 0;
                ((unsigned char *)fp)[0x4F] = 0xFF;
                s.unk50 = 0;
                VU0_SQC2_VF0(spill, 0x70);
                s.size = *(float *)(s1 + 0x114);
                s.unk70 = 0;
                s.unk72 = 0;
                s.unk74 = 0;
                s.unk78 = 0;
                SetEffect(0xBD, 0x19, (cObj *)self, &s, 1, EFFECT_FOLLOW_OWNER);
                *(int *)(s1 + 0x16D4) = *(int *)(s1 + 0x16D4) | 0x20000000;
                *(char *)(s1 + 0x186C) = 2;
                *(unsigned char *)(s1 + 0x2F6) = 2;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            break;
        case 2:
            *(char *)(s1 + 0x1864) = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            b = *(int *)(s1 + 0x304);
            func_002A8578(s1, EM_RES_REC(b, 0x3778), EM_RES_REC(b, 0x377C), 3, 0.0f, nb, 0);
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 3:
            if (moveMotion(s1) != 0) {
                *(unsigned char *)(s1 + 0x2F4) = 0;
                *(unsigned char *)(s1 + 0x2F5) = 0x9C;
                *(unsigned char *)(s1 + 0x2F6) = 0;
                *(unsigned char *)(s1 + 0x2F7) = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            break;
    }
}
