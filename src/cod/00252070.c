/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"

extern unsigned int irand(void);
extern void *Getplayer(void);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int GetSeqSEBase(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCB8(int a0, int a1);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern void func_00273D30(void *a0);
extern void func_00273630(void *a0);
extern int cEmBase_checkDeadFlag(void *a0);
extern void func_0028FB08(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, float f12, int t0);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void func_00262750(void *a0, int a1);
extern unsigned char D_005FEE00[];

/* Fields cEm00.h does not name yet. Offsets are from the record start. */
#define EM_AT(T, self, off) (*(T *)((char *)(self) + (off)))
#define EM_GRABLINK_OFFSET 0x698    /* the object holding or held by this one */
#define EM_UNK1710_OFFSET 0x1710    /* int, cleared when the step starts */
#define EM_FLAGS1644_OFFSET 0x1644  /* int flag word, bit 0x800000 keeps the body down */
#define EM_SUBA_OFFSET 0x740        /* child object started with a variant number */
#define EM_TURNTO_OFFSET 0x5D0      /* cVec: where the body is thrown from */
#define EM_STEPVEC_OFFSET 0x5E0     /* cVec: per-frame step of the throw */
#define EM_VEC(self, off) ((cVec *)((char *)(self) + (off)))


/* The stack frame as the base of the quadword moves: vecA sits at $sp+0x30. */
#define FRAME ((char *)&vecA - 0x30)

/* The first and second motion records of an action are two offsets in the
 * resource blob, 4 bytes apart; the motion start takes both addresses. */
#define MOTION_PAIR(a, b) { int p = self->resource; recA = EM_RES_REC(p, a); recB = EM_RES_REC(p, b); }

/* The blown-away step of an enemy: step 0 picks the motion for the enemy number, starts it and
 * plays the launch sounds; step 1 flies the body and ends in a ground check; steps 2 and 3 slide
 * it along the throw vector and pick the next action. */
__attribute__((section(".text.func_00252070")))
void func_00252070(void *a0)
{
    cEm00 *self = (cEm00 *)a0;
    cVec vecA, vecB, hitPos;
    cVec *pA;     /* &vecA, computed before the zero stores of step 3 */
    float rate;
    char *pB;     /* &vecB, computed once before the first quadword move */
    int recA, recB;
    int nb;

    self->emFlags |= 0x21020;
    switch (self->step) {
    case 0:
        ReleaseField6ECByTag564_26B1E8(self);
        {
            char *link = EM_AT(char *, self, EM_GRABLINK_OFFSET);

            EM_AT(int, self, EM_UNK1710_OFFSET) = 0;
            if (link != 0) {
                char *tgt = *(char **)(link + 0x34);

                self->stepArg = 0;
                if (tgt != 0) {
                    float d = Turn_dest(self->pos, self->rot.y, 3.14159274f, *(void **)(tgt + 0xF0));

                    if (d < 0.0f) {
                        d = -d;
                    }
                    if (tgt == Getplayer()) {
                        self->rot.y = Adjust_theta(((cEm00 *)Getplayer())->rot.y + 3.14159274f);
                    } else {
                        cGameObj_SetTgtTurn(self, *(void **)(tgt + 0xF0), 3.14159274f);
                    }
                    if (d > 1.57079637f) {
                        self->stepArg = 1;
                        self->rot.y = Adjust_theta(self->rot.y + 3.14159274f);
                    }
                }
            }
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->emNo) {
        case 0x27E:
        default:
            switch (irand() % 5) {
            case 0:
            default:
                MOTION_PAIR(0x310, 0x314)
                break;
            case 1:
                MOTION_PAIR(0x318, 0x31C)
                break;
            case 2:
                MOTION_PAIR(0x320, 0x324)
                break;
            case 3:
                MOTION_PAIR(0x328, 0x32C)
                break;
            case 4:
                MOTION_PAIR(0x330, 0x334)
                break;
            }
            break;
        case 0x214:
        case 0x215:
            switch (irand() % 3) {
            case 0:
            default:
                MOTION_PAIR(0x1B68, 0x1B6C)
                break;
            case 1:
                MOTION_PAIR(0x1B70, 0x1B74)
                break;
            case 2:
                MOTION_PAIR(0x1B78, 0x1B7C)
                break;
            }
            break;
        case 0x256:
            switch (irand() % 3) {
            case 0:
            default:
                MOTION_PAIR(0x2C04, 0x2C08)
                break;
            case 1:
                MOTION_PAIR(0x2C0C, 0x2C10)
                break;
            case 2:
                MOTION_PAIR(0x2C14, 0x2C18)
                break;
            }
            break;
        case 0x20F:
        case 0x210:
        case 0x211:
        case 0x226:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            switch (irand() % 5) {
            case 0:
            default:
                MOTION_PAIR(0xED4, 0xED8)
                break;
            case 1:
                MOTION_PAIR(0xEDC, 0xEE0)
                break;
            case 2:
                MOTION_PAIR(0xEE4, 0xEE8)
                break;
            case 3:
                MOTION_PAIR(0xEEC, 0xEF0)
                break;
            case 4:
                MOTION_PAIR(0xEF4, 0xEF8)
                break;
            }
            break;
        case 0x20A:
        case 0x20B:
        case 0x20C:
        case 0x20D:
        case 0x20E:
        case 0x218:
        case 0x245:
        case 0x246:
        case 0x247:
        case 0x24F:
        case 0x250:
        case 0x251:
        case 0x278:
        case 0x279:
            switch (irand() % 5) {
            case 0:
            default:
                MOTION_PAIR(0xA94, 0xA98)
                break;
            case 1:
                MOTION_PAIR(0xA9C, 0xAA0)
                break;
            case 2:
                MOTION_PAIR(0xAA4, 0xAA8)
                break;
            case 3:
                MOTION_PAIR(0xAAC, 0xAB0)
                break;
            case 4:
                MOTION_PAIR(0xAB4, 0xAB8)
                break;
            }
            break;
        case 0x260:
            switch (irand() % 3) {
            case 0:
            default:
                MOTION_PAIR(0x318C, 0x3190)
                break;
            case 1:
                MOTION_PAIR(0x3194, 0x3198)
                break;
            case 2:
                MOTION_PAIR(0x3194, 0x31A0)
                break;
            }
            break;
        case 0x264:
            switch (irand() % 3) {
            case 0:
            default:
                MOTION_PAIR(0x3368, 0x336C)
                if (EM_AT(int, self, EM_SUBA_OFFSET) != 0) {
                    Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCB8(EM_AT(int, self, EM_SUBA_OFFSET), 0);
                }
                break;
            case 1:
                MOTION_PAIR(0x3370, 0x3374)
                if (EM_AT(int, self, EM_SUBA_OFFSET) != 0) {
                    Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCB8(EM_AT(int, self, EM_SUBA_OFFSET), 1);
                }
                break;
            case 2:
                MOTION_PAIR(0x3378, 0x337C)
                if (EM_AT(int, self, EM_SUBA_OFFSET) != 0) {
                    Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCB8(EM_AT(int, self, EM_SUBA_OFFSET), 2);
                }
                break;
            }
            break;
        case 0x265:
            if (self->emFlags2 & 0x20000000) {
                switch (irand() & 1) {
                case 0:
                default:
                    MOTION_PAIR(0x3790, 0x3794)
                    break;
                case 1:
                    MOTION_PAIR(0x3798, 0x379C)
                    break;
                }
            } else if (irand() & 1) {
                MOTION_PAIR(0x3780, 0x3784)
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x30);
                }
            } else {
                MOTION_PAIR(0x3788, 0x378C)
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x31);
                }
            }
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
        case 0x241:
            switch (irand() % 3) {
            case 0:
            default:
                MOTION_PAIR(0x1738, 0x173C)
                break;
            case 1:
                MOTION_PAIR(0x1740, 0x1744)
                break;
            case 2:
                MOTION_PAIR(0x1748, 0x174C)
                break;
            }
            break;
        case 0x209:
        case 0x21F:
            switch (irand() % 3) {
            case 0:
            default:
                MOTION_PAIR(0x1738, 0x173C)
                break;
            case 1:
                MOTION_PAIR(0x1740, 0x1744)
                break;
            case 2:
                MOTION_PAIR(0x1748, 0x174C)
                break;
            }
            break;
        case 0x220:
        case 0x221:
        case 0x222:
            switch (irand() % 5) {
            case 0:
            default:
                MOTION_PAIR(0x1D18, 0x1D1C)
                break;
            case 1:
                MOTION_PAIR(0x1D20, 0x1D24)
                break;
            case 2:
                MOTION_PAIR(0x1D28, 0x1D2C)
                break;
            case 3:
                MOTION_PAIR(0x1D30, 0x1D34)
                break;
            case 4:
                MOTION_PAIR(0x1D38, 0x1D3C)
                break;
            }
            break;
        case 0x223:
            switch (irand() % 5) {
            case 0:
            default:
                MOTION_PAIR(0x2EBC, 0x2EC0)
                break;
            case 1:
                MOTION_PAIR(0x2EBC, 0x2EC0)
                break;
            case 2:
                MOTION_PAIR(0x2EBC, 0x2EC0)
                break;
            case 3:
                MOTION_PAIR(0x2EBC, 0x2EC0)
                break;
            case 4:
                MOTION_PAIR(0x2EBC, 0x2EC0)
                break;
            }
            break;
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24D:
        case 0x24E:
        case 0x252:
        case 0x25A:
            switch (irand() % 5) {
            case 0:
            default:
                MOTION_PAIR(0x1300, 0x1304)
                break;
            case 1:
                MOTION_PAIR(0x1308, 0x130C)
                break;
            case 2:
                MOTION_PAIR(0x1310, 0x1314)
                break;
            case 3:
                MOTION_PAIR(0x1318, 0x131C)
                break;
            case 4:
                MOTION_PAIR(0x1320, 0x1324)
                break;
            }
            break;
        case 0x275:
        case 0x276:
            switch (irand() % 3) {
            case 0:
            default:
                MOTION_PAIR(0x23C0, 0x23C4)
                break;
            case 1:
                MOTION_PAIR(0x23C8, 0x23CC)
                break;
            case 2:
                MOTION_PAIR(0x23D0, 0x23D4)
                break;
            }
            break;
        }
        func_002A8578(self, recA, recB, 5, 0.0f, nb, 0);
        if (self->stepArg == 0) {
            self->home.x = 0.0f;
            self->home.y = 0.0f;
            self->home.z = -1.5f;
            self->home.w = 1.0f;
        } else {
            self->home.x = 0.0f;
            self->home.y = 0.0f;
            self->home.z = 1.5f;
            self->home.w = 1.0f;
        }
        self->timerB = 0;
        self->home.y = 0.75f;
        self->timerA = 0x28;
        cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0xC), self, 0, 0, 0, 0);
        switch (self->emNo) {
        default:
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x2B, self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x2E, self, 0, 0, 0, 0);
            break;
        case 0x20F:
        case 0x210:
        case 0x211:
        case 0x226:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x1E, self, 0, 0, 0, 0);
            break;
        }
        InitRenderStruct_2A8608(self, 0x58, 8, 0, 2, 0);
        cVec_copy3(EM_VEC(self, EM_TURNTO_OFFSET), (cVec *)self->pos);
        if (self->vital <= 0 && !(self->emFlags2 & 0x1000)
            && (func_00273D30(self), (self->emNo != 0x21F || !(self->emFlags2 & 0x100000)))) {
            func_00273630(self);
            if (cEmBase_checkDeadFlag(self) == 0 && self->entryNo != 0xFF) {
                cCoreSave_addKillEmNum(&D_00569B70);
                func_0028FB08(self);
            }
        }
        self->step++;
    case 1:
        self->emFlags |= 0x10000;
        moveMotion(self);
        rate = self->speedRate;
        pB = (char *)&vecB;
        VU0_LQC2(4, &self->home, 0);
        VU0_SQC2(4, FRAME, 0x40);
        VU0_LQC2(4, FRAME, 0x40);
        VU0_LOAD_SCALAR(5, rate);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, FRAME, 0x40);
        VU0_LQC2(4, pB, 0);
        VU0_SQC2(4, FRAME, 0x30);
        cVec_copy3(&self->stepVec, &vecA);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (--self->timerA <= 0) {
            VU0_SQC2_VF0(FRAME, 0x30);
            cVec_copy3(&vecA, self->pos);
            vecA.y += 1.0f;
            SetEffectPos(0x58, 9, 0, &vecA, 1.0f, -1);
            self->animRate = 0.0f;
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x2C, self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x35, self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xDA, self, 0, 0, 0, 0);
            if ((EM_AT(int, self, EM_FLAGS1644_OFFSET) & 0x800000) || self->vital > 0
                || (self->emFlags2 & 0x1000)) {
                self->step++;
                break;
            }
            self->mode = 2;
            self->phase = 2;
            self->stepArg = 1;
            self->step = 0;
        }
        VU0_SQC2_VF0(FRAME, 0x30);
        VU0_SQC2_VF0(FRAME, 0x40);
        VU0_SQC2_VF0(FRAME, 0x50);
        cVec_copy3(&vecA, &self->posA);
        cVec_copy3(&vecB, self->pos);
        vecA.y += 1.0f;
        vecB.y += 1.0f;
        if (ChkLine(&vecA, &vecB, &hitPos, 0, 7, 0x1A4, 0, 0, 0, 0, 0, 0, 1) == 1) {
            SetEffectPos(0, 0x10, 0, &hitPos, 1.0f, -1);
        }
        self->hitFlash = 3.0f;
        func_00262750(self, 1);
        break;
    case 2:
        self->timer = 30.0f;
        VU0_ZERO_VSUB_XYZ_MEM(FRAME, 0x40, EM_VEC(self, EM_TURNTO_OFFSET), self->pos);
        VU0_LQC2(4, &vecB, 0);
        VU0_SQC2(4, FRAME, 0x30);
        cVec_copy3(EM_VEC(self, EM_STEPVEC_OFFSET), &vecA);
        VU0_VSCALE_XYZ_MEM(self, 0x5E0, 1.0f / self->timer);
        self->step++;
    case 3:
        self->emFlags |= 0x20000;
        self->emFlags |= 0x10000;
        self->hitFlash = 3.0f;
        VU0_VADD_XYZ_PTR(self->pos, self->pos, EM_VEC(self, EM_STEPVEC_OFFSET));
        pA = &vecA;
        VU0_SQC2_VF0(FRAME, 0x30);
        VU0_SQC2_VF0(FRAME, 0x40);
        VU0_SQC2_VF0(FRAME, 0x50);
        cVec_copy3(pA, &self->posA);
        cVec_copy3(&vecB, self->pos);
        vecA.y += 1.0f;
        vecB.y += 1.0f;
        if (ChkLine(&vecB, pA, &hitPos, 0, 7, 0x1A4, 0, 0, 0, 0, 0, 0, 1) == 1) {
            SetEffectPos(0, 0x10, 0, &hitPos, 1.0f, -1);
        }
        self->timer -= 1.0f;
        if (self->timer <= 0.0f) {
            if (self->vital <= 0) {
                switch (self->emNo) {
                case 0x260:
                case 0x264:
                case 0x265:
                    self->phase = 0;
                    self->step = 0;
                    self->mode = 2;
                    self->stepArg = 0;
                    return;
                }
            }
            self->mode = 1;
            self->phase = 8;
            self->step = 2;
            self->stepArg = 0;
        }
        break;
    }
}
