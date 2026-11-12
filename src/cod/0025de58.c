/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */

extern void *Getplayer(void);
extern void SetMotionStep(void *a0, float f12);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void ForwardAnimParamPairByIndex_27EA50(void *a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern float fRand1_1(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float a2);
extern char D_00462FC0[];
extern char D_005CB000[];

#include "godhand/vu0.h"
#include "godhand/motion.h"

/* Held-by-player phase of an enemy, stepped on its 0x2F6 sub-phase (0 to 5).
 * The enemy copies the player's motion step, plays three motion pairs from
 * its motion table (0x39A0, 0x39A8, 0x39B0) and rides the player's position
 * delta at 0x550; the last phase spawns effect 0x4F on a part, fires the
 * vtable hit at 0xA8 with damage 20 * the charge at 0x600, adds heat and
 * hands control back with phase 1/4/2. */
__attribute__((section(".text.func_0025DE58")))
void func_0025DE58(void *a0)
{
    char *s0 = (char *)a0;
    char *s2;
    unsigned char frame[0x10];
    float buf[4];
    void *m1;
    unsigned char *m2;

    s2 = (char *)Getplayer();
    {
        float v = *(float *)(s2 + 0x5A8);

        *(float *)(s0 + 0x5A8) = v;
        SetMotionStep(s0, v);
    }
    *(float *)(s0 + 0x54C) = 3.0f;
    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x39A0) + p, *(int *)(p + 0x39A4) + p,
                      0, 0.0f, 0, 0);
        if (*(int *)(s0 + 0x744) != 0) {
            ForwardAnimParamPairByIndex_27EA50(*(char **)(s0 + 0x744), 0x19);
        }
        *(int *)(s0 + 0x16EC) = 0;
        *(short *)(s0 + 0x56A) = 0;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
    {
        char *q;
        char *p;

        q = s2 + 0x550;
        p = *(char **)(s0 + 0xF0);
        VU0_LQC2(4, p, 0);
        VU0_LQC2(5, q, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, p, 0);
    }
        if (moveMotion(s0) != 0) {
            (*(unsigned char *)(s0 + 0x2F6))++;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 2:
    {
        int p;
        float z = 0.0f;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x39A8) + p, *(int *)(p + 0x39AC) + p,
                      0, z, 0, 0);
        if (*(int *)(s0 + 0x744) != 0) {
            ForwardAnimParamPairByIndex_27EA50(*(char **)(s0 + 0x744), 0x1A);
        }
        *(int *)(s0 + 0x5F0) = 1;
        *(float *)(s0 + 0x600) = z;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
    {
        char *p;
        char *q;

        p = *(char **)(s0 + 0xF0);
        q = s2 + 0x550;
        VU0_VADD_XYZ_IP(p, 0, q);
    }
        if (moveMotion(s0) != 0) {
            *(float *)(s0 + 0x600) = *(float *)(s0 + 0x600) + 1.0f;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s2 + 0x2F6);
        break;
    case 4:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x39B0) + p, *(int *)(p + 0x39B4) + p,
                      0, 0.0f, 0, 0);
        if (*(int *)(s0 + 0x744) != 0) {
            ForwardAnimParamPairByIndex_27EA50(*(char **)(s0 + 0x744), 0x1B);
        }
        *(int *)(s0 + 0x5F0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 5:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *p;
            char *q;

            (*(short *)(s0 + 0x56E))--;
            p = *(char **)(s0 + 0xF0);
            q = s2 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(s0) != 0) {
            unsigned char ok;
            int cnt;
            int idx = 4;
            char *s1;
            char *vt;
            int (*fp)();

            ok = ((*(int *)frame = cnt = *(unsigned char *)(s0 + 0x2B4)),
                  (idx < cnt));
            if (ok) s1 = *(char **)(*(int *)(s0 + 0x278) + idx * 4);
            else s1 = 0;
            if (s1 != 0) {
                VU0_SQC2_VF0(frame, 0x10);
                buf[0] = fRand1_1() * 0.1f;
                buf[1] = fRand1_1() * 0.1f + 0.1f;
                buf[2] = fRand0_1() * 0.1f + 0.2f;
                /* One pointer local per call, cleared after it: retail recomputes
                 * $sp+0x10 at each call instead of holding it in a saved register. */
                m1 = (void *)buf;
                sceVu0ApplyMatrix(m1, s1 + 0x80, m1);
                m1 = 0;
                m2 = frame + 0x10;
                SetEffectPos(0, 0x4F, 0, m2, -1, 1.0f);
                m2 = 0;
            }
            vt = *(char **)(s0 + 0x214);
            fp = *(int (**)())(vt + 0xAC);
            fp(s0 + *(short *)(vt + 0xA8),
               (int)(*(float *)(s0 + 0x600) * 20.0f), s2, 0, 0);
            cHeatSys_AddHeatGage(D_005CB000, 0, *(float *)(s0 + 0x600));
            *(char *)(s0 + 0x2F4) = 1;
            *(char *)(s0 + 0x2F5) = 4;
            *(char *)(s0 + 0x2F7) = 2;
            *(char *)(s0 + 0x2F6) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}
