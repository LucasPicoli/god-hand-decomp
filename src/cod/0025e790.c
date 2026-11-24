#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int moveMotion(void *a0);
extern void Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0(int a0, int a1);
extern void KillEffect(void *a0, int a1, int a2);
extern int cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cObjBase.h"

















/* Phase machine on the step byte, 58 case labels. Calls VU0_SQC2_VF0, fp,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, irand, cSnd_SeCall_2CBA48, GetSeqSEBase and 9 more. */
__attribute__((section(".text.func_0025E790"))) void func_0025E790(cEm00 *self)
{
    char *s3 = (char *)self;
    cEffectParam s;
    int s2;
    int s1;
    int nb;
    void *s5;

    s.color.x = 1.0f;
    s.color.y = 1.0f;
    s.color.z = 1.0f;
    s.color.w = 1.0f;
    VU0_SQC2_VF0(&s, 0x10);
    VU0_SQC2_VF0(&s, 0x20);
    s.scale.x = 1.0f;
    {
        float *q = &s.scale.x;
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
    s.size = *(float *)(s3 + 0x114);
    s.unk72 = 0;
    s.unk74 = 0;
    s.unk78 = 0;
    {
        int *vt = *(int **)(s3 + 0x214);
        short off = *(short *)((char *)vt + 0xB0);
        void *(*fp)() = *(void *(**)())((char *)vt + 0xB4);
        s5 = fp(s3 + off);
    }
    switch (*(unsigned char *)(s3 + 0x2F6)) {
        case 0:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
            switch (*(int *)(s3 + 0x564)) {
                default:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x340);
                        s1 = EM_RES_REC(b, 0x344);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x338);
                        s1 = EM_RES_REC(b, 0x33C);
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
                case 0x278:
                case 0x279:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xACC);
                        s1 = EM_RES_REC(b, 0xAD0);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xAD4);
                        s1 = EM_RES_REC(b, 0xAD8);
                    }
                    break;
                case 0x250:
                case 0x251:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xACC);
                        s1 = EM_RES_REC(b, 0xAD0);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xAD4);
                        s1 = EM_RES_REC(b, 0xAD8);
                    }
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(s3) + 0x23), (cObj *)self, 0, 0,
                                       0, 0);
                    break;
                case 0x260:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x31A4);
                        s1 = EM_RES_REC(b, 0x31A8);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x31A4);
                        s1 = EM_RES_REC(b, 0x31A8);
                    }
                    break;
                case 0x264:
                    if ((*(int *)(s3 + 0x16D4) & 0x10000000) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        int o = *(int *)(s3 + 0x740);
                        s2 = EM_RES_REC(b, 0x33A8);
                        s1 = EM_RES_REC(b, 0x33AC);
                        if (o != 0) {
                            Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0(o, 1);
                        }
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        int o = *(int *)(s3 + 0x740);
                        s2 = EM_RES_REC(b, 0x33B0);
                        s1 = EM_RES_REC(b, 0x33B4);
                        if (o != 0) {
                            Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCD0(o, 0);
                        }
                    }
                    break;
                case 0x265: {
                    int b = *(int *)(s3 + 0x304);
                    s2 = EM_RES_REC(b, 0x3988);
                    s1 = EM_RES_REC(b, 0x398C);
                    KillEffect(s3, 1, 2);
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224:
                case 0x241:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1768);
                        s1 = EM_RES_REC(b, 0x176C);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1760);
                        s1 = EM_RES_REC(b, 0x1764);
                    }
                    break;
                case 0x209:
                case 0x21F:
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1768);
                        s1 = EM_RES_REC(b, 0x176C);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1760);
                        s1 = EM_RES_REC(b, 0x1764);
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
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xF0C);
                        s1 = EM_RES_REC(b, 0xF10);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0xF14);
                        s1 = EM_RES_REC(b, 0xF18);
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
                    if ((irand() & 1) != 0) {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1340);
                        s1 = EM_RES_REC(b, 0x1344);
                    } else {
                        int b = *(int *)(s3 + 0x304);
                        s2 = EM_RES_REC(b, 0x1338);
                        s1 = EM_RES_REC(b, 0x133C);
                    }
                    break;
            }
            func_002A8578(s3, s2, s1, 5, 0.0f, nb, 0);
            if ((*(int *)(s3 + 0x1644) & 0x800000) == 0) {
                if (func_0025FE30(s3, 0, 0) != 0) {
                    cDamageUnit_SetDamageCollActive(s5, 0);
                }
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(s3) + 8), (cObj *)self, 0, 0, 0, 0);
            switch (*(int *)(s3 + 0x564)) {
                case 0x207:
                case 0x240:
                case 0x249:
                case 0x24A:
                case 0x24E:
                    SetEffect(0x58, 0x9F, (cObj *)self, &s, -1, EFFECT_FOLLOW_OWNER);
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(s3) + 0x22), (cObj *)self, 0, 0,
                                       0, 0);
                    break;
            }
            *(unsigned char *)(s3 + 0x2F6) += 1;
            /* fallthrough */
        case 1:
            *(float *)(s3 + 0x54C) = 3.0f;
            *(unsigned short *)(s3 + 0x434) |= 8;
            if (moveMotion(s3) != 0) {
                if ((*(int *)(s3 + 0x1644) & 0x800000) != 0) {
                    *(signed char *)(s3 + 0x2F4) = 2;
                    *(signed char *)(s3 + 0x2F5) = 3;
                    *(signed char *)(s3 + 0x2F6) = 0;
                    *(signed char *)(s3 + 0x2F7) = 0;
                } else {
                    *(signed char *)(s3 + 0x2F4) = 2;
                    *(signed char *)(s3 + 0x2F5) = 2;
                    *(signed char *)(s3 + 0x2F6) = 0;
                    *(signed char *)(s3 + 0x2F7) = 0;
                }
            } else {
                cObjBase_addNullSpeed_Rotation(s3, 1.0f);
                cObjBase_addNullSpeed(s3, 1.0f);
            }
            break;
    }
}
