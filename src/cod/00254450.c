/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int GetSeqSEBase(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void cEmManage_setBigHitEff(void *a0);
extern void func_002717D0(void *a0);



extern void func_00274FE8(void *a0);
extern void func_002705D8(void *a0);
extern void func_00270C78(void *a0);
extern void func_00274238(void *a0, int a1);



extern void func_0027DB50(int a0, int a1);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern void Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DB08(int a0);
extern unsigned char D_005FEE00[];
extern unsigned char D_005864F0[];
extern unsigned char D_005CB010;
extern unsigned char D_00747A2C[];

/* Fields cEm00.h does not name yet. Offsets are from the record start. */
#define EM_AT(T, self, off) (*(T *)((char *)(self) + (off)))
#define EM_HITCOUNT_OFFSET 0x1867   /* unsigned char, the hits taken in a row, at most 4 */
#define EM_UNK17C1_OFFSET 0x17C1    /* unsigned char, nonzero keeps the slow flinch of stepArg 3 */
#define EM_UNK17B9_OFFSET 0x17B9    /* unsigned char, nonzero lets the enemy start a counter attack */

/* The pad record at D_00747A2C: the held buttons at 0x10 and the pad id at 0x24. */
#define PAD_BUTTONS_OFFSET 0x10
#define PAD_ID_OFFSET 0x24

/* The stack frame as the base of the quadword moves: vecA sits at $sp+0x30. */
#define FRAME ((char *)&vecA - 0x30)

/* The first and second motion records of an action are two offsets in the
 * resource blob, 4 bytes apart; the motion start takes both addresses. */
#define MOTION_PAIR(a, b) { int p = self->resource; recA = EM_RES_REC(p, a); recB = EM_RES_REC(p, b); }

/* The hit reaction of an enemy. The step byte runs through it: step 0 sets the rise speed from
 * stepArg and the enemy number, then picks and starts the knock-back motion; step 1 lifts the body
 * and lets it fall until a ground check lands it (and sometimes decides on the dazed motion);
 * steps 2 and 3 play the get-up motion and hand over to the next action; steps 4 and 5 are the
 * dazed motion; steps 6 and 7 are the recovery, which waits out a random time and may start a
 * counter attack. A step 6 reaction is also forced for the enemies that always recover. */
__attribute__((section(".text.cEm00_hitReaction")))
void cEm00_hitReaction(void *a0)
{
    cEm00 *self = (cEm00 *)a0;
    cVec vecA, vecB, vecC, vecD;
    cVec *pos = self->pos;
    float startFrame = 0.0f;
    int recA, recB;
    unsigned int tb;
    int nb;

    VU0_LQC2(4, pos, 0);
    VU0_SQC2(4, FRAME, 0x30);
    VU0_LQC2(4, pos, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    switch (self->emNo) {
    case 0x260: case 0x264: case 0x265: case 0x26A:
        if (self->step == 0) {
            self->step = 6;
        }
        break;
    }
    switch (self->step) {
    case 0:
        self->unk1710 = 0;
        switch (self->stepArg) {
        case 0:
        default:
            self->home.y = 0.13f;
            break;
        case 1:
            self->home.y = 0.039f;
            if (D_005CB010 != 0) {
                self->home.y = 0.026f;
            }
            break;
        case 2:
            self->home.y = 0.234f;
            break;
        case 3:
            {
                float fv = 0.18200001f;
                if (EM_AT(unsigned char, self, EM_UNK17C1_OFFSET) != 0) {
                    fv = 0.13f;
                }
                self->home.y = fv;
            }
            break;
        case 4:
            self->home.y = 0.091000006f;
            break;
        case 5:
            self->home.y = 0.0195f;
            break;
        case 6:
            self->home.y = 0.065f;
            break;
        }
        {
            int sa = self->stepArg;
            if (sa < 5) {
                if (sa >= 3) {
                    cEmManage_setBigHitEff(D_005864F0);
                    func_002717D0(self);
                }
            }
        }
        if (self->stepArg != 4) {
            EM_AT(unsigned char, self, EM_HITCOUNT_OFFSET)++;
            if (EM_AT(unsigned char, self, EM_HITCOUNT_OFFSET) >= 5) {
                EM_AT(unsigned char, self, EM_HITCOUNT_OFFSET) = 4;
            }
        }
        if (self->stepArg < 5 || self->stepArg > 6) {
            switch (self->emNo) {
            case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271: case 0x272:
            case 0x273: case 0x274:
                self->home.y = self->home.y * 1.1f;
                break;
            case 0x250: case 0x251:
                {
                    char *pad = (char *)D_00747A2C;

                    if ((*(int *)(pad + PAD_BUTTONS_OFFSET) & 0x8000) != 0) {
                        goto padck;
                    }
                    if ((*(int *)(pad + PAD_BUTTONS_OFFSET) & 0x4000) != 0) {
                    padck:
                        if (*(unsigned short *)(pad + PAD_ID_OFFSET) == 0x45) {
                            int sb = self->stepArg;
                            if (sb < 4) {
                                if (sb >= 2) {
                                    self->home.y = 0.13f;
                                }
                            }
                            self->home.y = self->home.y * 0.7f;
                        }
                    }
                }
            case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218: case 0x245:
            case 0x246: case 0x247: case 0x24F: case 0x260: case 0x264: case 0x265: case 0x278:
            case 0x279:
                if (D_005CB010 == 0) {
                    self->home.y = self->home.y * 0.7f;
                }
                break;
            }
        }
        if (func_002740D8(self) != 0) {
            if (irand() & 1) {
                self->unk17C3 = 1;
            } else {
                self->unk17C3 = 0;
            }
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        self->timerB = 0;
        switch (self->emNo) {
        default: case 0x212: case 0x213: case 0x214: case 0x215: case 0x216: case 0x217:
        case 0x219: case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B: case 0x230:
        case 0x231: case 0x232: case 0x233: case 0x234: case 0x235: case 0x236: case 0x237:
        case 0x238: case 0x239: case 0x23A: case 0x23B: case 0x23C: case 0x23D: case 0x23E:
        case 0x23F: case 0x240: case 0x242: case 0x243: case 0x244: case 0x24A: case 0x24B:
        case 0x253: case 0x254: case 0x255: case 0x256: case 0x257: case 0x258: case 0x259:
        case 0x25B: case 0x25C: case 0x25D: case 0x25E: case 0x25F: case 0x261: case 0x262:
        case 0x263: case 0x266: case 0x267: case 0x268: case 0x269: case 0x26A: case 0x26B:
        case 0x26C: case 0x26D: case 0x26E: case 0x26F: case 0x275: case 0x276: case 0x277:
            if (irand() & 1) {
                MOTION_PAIR(0x5B8, 0x5BC)
            } else {
                MOTION_PAIR(0x5B8, 0x5BC)
            }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271: case 0x272:
        case 0x273: case 0x274:
            switch (self->stepArg) {
            case 1: case 4:
            default:
                MOTION_PAIR(0xEB4, 0xEB8)
                break;
            case 0: case 2: case 3:
                self->timerB = 1;
                MOTION_PAIR(0xEAC, 0xEB0)
                break;
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218: case 0x245:
        case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
            MOTION_PAIR(0xA68, 0xA6C)
            break;
        case 0x250: case 0x251:
            {
                int p = self->resource;
                recA = EM_RES_REC(p, 0xA68);
                recB = EM_RES_REC(p, 0xA6C);
                cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0, 0, 0);
            }
            break;
        case 0x260:
            MOTION_PAIR(0x3184, 0x3188)
            break;
        case 0x264:
            MOTION_PAIR(0x3300, 0x3304)
            break;
        case 0x265:
            MOTION_PAIR(0x3818, 0x381C)
            break;
        case 0x220: case 0x221: case 0x222:
            MOTION_PAIR(0x5B8, 0x5BC)
            break;
        case 0x223:
            MOTION_PAIR(0x2EA4, 0x2EA8)
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225: case 0x22C:
        case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C: case 0x24D:
        case 0x24E: case 0x252: case 0x25A:
            MOTION_PAIR(0x12D8, 0x12DC)
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x209: case 0x21F: case 0x224:
        case 0x241:
            MOTION_PAIR(0x1710, 0x1714)
            break;
        }
        func_002A8578(self, recA, recB, 3, 0.0f, nb, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
        {
            char *link = (char *)self->unk698;

            self->timerA = 0;
            if (link != 0) {
                cEm00 *watched = *(cEm00 **)(link + 0x34);

                if (watched != 0) {
                    self->timerA = 0xA;
                    cVec_copy3(&self->posB, watched->pos);
                }
            }
        }
        func_0026F120(self);
        self->step = self->step + 1;
        /* fallthrough */
    case 1:
        self->emFlags |= 0x10000;
        {
            int c = self->timerA;
            if (c != 0) {
                self->timerA = c - 1;
                cGameObj_SetTgtTurn(self, &self->posB, self->speedRate * 0.3926991f);
            }
        }
        self->pos->y = self->pos->y + self->home.y * self->speedRate;
        {
            float v = self->home.y;
            if (v <= 0.0f) {
                self->home.y = v - self->speedRate * 0.0078000003f;
            } else {
                self->home.y = v - self->speedRate * 0.013f;
            }
        }
        if (self->home.y <= 0.0f) {
            vecA.y += 0.5f;
            vecB.y = self->pos->y - 10.0f;
            if (ChkLine(&vecA, &vecB, &vecC, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                if (self->pos->y <= vecC.y + 0.01f) {
                    self->pos->y = vecC.y;
                    self->step = 2;
                    switch (self->emNo) {
                    case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
                    case 0x272: case 0x273: case 0x274:
                        break;
                    default: case 0x200: case 0x201: case 0x202: case 0x203: case 0x204:
                    case 0x205: case 0x206: case 0x207: case 0x208: case 0x209: case 0x20A:
                    case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x212: case 0x213:
                    case 0x214: case 0x215: case 0x216: case 0x217: case 0x218: case 0x219:
                    case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x21F:
                    case 0x220: case 0x221: case 0x222: case 0x223: case 0x224: case 0x225:
                    case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B: case 0x22C:
                    case 0x22D: case 0x22E: case 0x22F: case 0x230: case 0x231: case 0x232:
                    case 0x233: case 0x234: case 0x235: case 0x236: case 0x237: case 0x238:
                    case 0x239: case 0x23A: case 0x23B: case 0x23C: case 0x23D: case 0x23E:
                    case 0x23F: case 0x240: case 0x241: case 0x242: case 0x243: case 0x244:
                    case 0x245: case 0x246: case 0x247: case 0x248: case 0x249: case 0x24A:
                    case 0x24B: case 0x24C: case 0x24D: case 0x24E: case 0x24F: case 0x250:
                    case 0x251: case 0x252: case 0x253: case 0x254: case 0x255: case 0x256:
                    case 0x257: case 0x258: case 0x259: case 0x25A: case 0x25B: case 0x25C:
                    case 0x25D: case 0x25E: case 0x25F: case 0x260: case 0x261: case 0x262:
                    case 0x263: case 0x264: case 0x265: case 0x266: case 0x267: case 0x268:
                    case 0x269: case 0x26A: case 0x26B: case 0x26C: case 0x26D: case 0x26E:
                    case 0x26F: case 0x275: case 0x276: case 0x277: case 0x278: case 0x279:
                    case 0x27A: case 0x27B: case 0x27C: case 0x27D: case 0x27E:
                        if (self->vital > 0 && func_0026F1D8(self) == 0) {
                            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                            case 2:
                                if ((irand() & 7) == 0) {
                                    self->step = 4;
                                }
                                break;
                            case 3:
                                if ((irand() & 3) == 0) {
                                    self->step = 4;
                                }
                                break;
                            case 4:
                                if ((irand() & 3) == 0) {
                                    self->step = 4;
                                }
                                break;
                            case 5:
                                if ((irand() & 1) == 0) {
                                    self->step = 4;
                                }
                                break;
                            case 1:
                            default:
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        } else {
            VU0_SQC2_VF0(FRAME, 0x60);
            vecB.y = self->pos->y + 10.0f;
            if (ChkLine(&vecA, &vecB, &vecD, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                float t = vecD.y - 1.5f;
                if (t < self->pos->y) {
                    self->pos->y = t;
                    self->home.y = 0.0f;
                }
            }
        }
        if (self->timerB == 0) {
            self->unk434 |= 8;
        }
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
        if (func_002740D8(self) != 0) {
            if (irand() & 1) {
                self->unk17C3 = 1;
            } else {
                self->unk17C3 = 0;
            }
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        self->timer = 1.0f;
        switch (self->emNo) {
        default: case 0x212: case 0x213: case 0x214: case 0x215: case 0x216: case 0x217:
        case 0x219: case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B: case 0x230:
        case 0x231: case 0x232: case 0x233: case 0x234: case 0x235: case 0x236: case 0x237:
        case 0x238: case 0x239: case 0x23A: case 0x23B: case 0x23C: case 0x23D: case 0x23E:
        case 0x23F: case 0x240: case 0x242: case 0x243: case 0x244: case 0x24A: case 0x24B:
        case 0x253: case 0x254: case 0x255: case 0x256: case 0x257: case 0x258: case 0x259:
        case 0x25B: case 0x25C: case 0x25D: case 0x25E: case 0x25F: case 0x261: case 0x262:
        case 0x263: case 0x266: case 0x267: case 0x268: case 0x269: case 0x26A: case 0x26B:
        case 0x26C: case 0x26D: case 0x26E: case 0x26F: case 0x275: case 0x276: case 0x277:
            if (irand() & 1) {
                MOTION_PAIR(0x5C0, 0x5C4)
            } else {
                MOTION_PAIR(0x5C0, 0x5C4)
            }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271: case 0x272:
        case 0x273: case 0x274:
            MOTION_PAIR(0xEBC, 0xEC0)
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218: case 0x245:
        case 0x246: case 0x247: case 0x24F: case 0x250: case 0x251: case 0x278: case 0x279:
            self->timer = 1.5f;
            MOTION_PAIR(0xA70, 0xA74)
            break;
        case 0x260:
            self->timer = 1.5f;
            MOTION_PAIR(0x3174, 0x3178)
            break;
        case 0x264:
            {
                int p = self->resource;
                recA = EM_RES_REC(p, 0x3348);
                recB = EM_RES_REC(p, 0x334C);
                if (self->subA != 0) {
                    func_0027DB50(self->subA, 2);
                }
            }
            break;
        case 0x265:
            {
                int p = self->resource;
                recA = EM_RES_REC(p, 0x3860);
                recB = EM_RES_REC(p, 0x3864);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x2C);
                }
            }
            break;
        case 0x220: case 0x221: case 0x222:
            MOTION_PAIR(0x5C0, 0x5C4)
            break;
        case 0x223:
            MOTION_PAIR(0x2EAC, 0x2EB0)
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225: case 0x22C:
        case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C: case 0x24D:
        case 0x24E: case 0x252: case 0x25A:
            MOTION_PAIR(0x12E0, 0x12E4)
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x209: case 0x21F: case 0x224:
        case 0x241:
            MOTION_PAIR(0x1718, 0x171C)
            break;
        }
        func_002A8578(self, recA, recB, 3, 0.0f, nb, 0);
        self->step = self->step + 1;
        /* fallthrough */
    case 3:
        if (moveMotion(self) != 0) {
            if (self->vital <= 0) {
                if (self->emFlags2 & 0x100000) {
                    self->mode = 2;
                    self->step = 0;
                    self->phase = 2;
                    self->stepArg = 0;
                } else if (self->flags1644 & 0x800000) {
                    self->step = 0;
                    self->mode = 2;
                    self->phase = 3;
                    self->stepArg = 0;
                } else if (func_0025FE30(self, 0x01000000, 0) != 0) {
                    self->mode = 2;
                    self->step = 0;
                    self->phase = 2;
                    self->stepArg = 0;
                } else {
                    self->step = 0;
                    self->mode = 2;
                    self->phase = 1;
                    self->stepArg = 0;
                }
            } else {
                func_00274FE8(self);
            }
        } else {
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, self->timer);
            if ((self->moveFlags & 0x10) && self->vital <= 0) {
                if (self->emFlags2 & 0x100000) {
                    self->mode = 2;
                    self->step = 0;
                    self->phase = 2;
                    self->stepArg = 0;
                } else if (self->flags1644 & 0x800000) {
                    self->step = 0;
                    self->mode = 2;
                    self->phase = 3;
                    self->stepArg = 0;
                } else if (func_0025FE30(self, 0x01000000, 0) != 0) {
                    self->mode = 2;
                    self->step = 0;
                    self->phase = 2;
                    self->stepArg = 0;
                } else {
                    self->step = 0;
                    self->mode = 2;
                    self->phase = 1;
                    self->stepArg = 0;
                }
            }
        }
        break;
    case 4:
        if (func_002740D8(self) != 0) {
            if (irand() & 1) {
                self->unk17C3 = 1;
            } else {
                self->unk17C3 = 0;
            }
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->emNo) {
        default: case 0x212: case 0x213: case 0x214: case 0x215: case 0x216: case 0x217:
        case 0x219: case 0x220: case 0x221: case 0x222: case 0x227: case 0x228: case 0x229:
        case 0x22A: case 0x22B: case 0x230: case 0x231: case 0x232: case 0x233: case 0x234:
        case 0x235: case 0x236: case 0x237: case 0x238: case 0x239: case 0x23A: case 0x23B:
        case 0x23C: case 0x23D: case 0x23E: case 0x23F: case 0x240: case 0x242: case 0x243:
        case 0x244: case 0x24A: case 0x24B: case 0x253: case 0x254: case 0x255: case 0x256:
        case 0x257: case 0x258: case 0x259: case 0x25B: case 0x25C: case 0x25D: case 0x25E:
        case 0x25F: case 0x261: case 0x262: case 0x263: case 0x266: case 0x267: case 0x268:
        case 0x269: case 0x26A: case 0x26B: case 0x26C: case 0x26D: case 0x26E: case 0x26F:
        case 0x275: case 0x276: case 0x277:
            MOTION_PAIR(0x5C8, 0x5CC)
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271: case 0x272:
        case 0x273: case 0x274:
            recA = self->resource;
            /* fall through */
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218: case 0x245:
        case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
            recA = EM_RES_REC(self->resource, 0xA78);
            recB = EM_RES_REC(self->resource, 0xA7C);
            break;
        case 0x250: case 0x251:
            MOTION_PAIR(0xA78, 0xA80)
            break;
        case 0x260:
            MOTION_PAIR(0xA78, 0xA80)
            break;
        case 0x264:
            MOTION_PAIR(0x3300, 0x3304)
            break;
        case 0x265:
            MOTION_PAIR(0x3818, 0x381C)
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225: case 0x22C:
        case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C: case 0x24D:
        case 0x24E: case 0x252: case 0x25A:
            MOTION_PAIR(0x12E8, 0x12EC)
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
            MOTION_PAIR(0x1720, 0x1724)
            break;
        case 0x209: case 0x21F:
            MOTION_PAIR(0x1720, 0x1724)
            break;
        case 0x223:
            startFrame = 7.0f;
            MOTION_PAIR(0x2D6C, 0x2D70)
            break;
        }
        func_002A8578(self, recA, recB, 3, startFrame, nb, 0);
        self->hitFlash = 10.0f;
        self->step = self->step + 1;
        /* fallthrough */
    case 5:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 6:
        if (self->unk6EC != 0) {
            switch (self->emNo) {
            default: case 0x230: case 0x231: case 0x232: case 0x233: case 0x234: case 0x235:
            case 0x236: case 0x237: case 0x238: case 0x239: case 0x23B: case 0x23C: case 0x23D:
            case 0x23E: case 0x23F: case 0x240: case 0x241: case 0x242: case 0x243: case 0x244:
            case 0x245: case 0x246: case 0x247: case 0x248: case 0x249: case 0x24C: case 0x24D:
            case 0x24E: case 0x24F: case 0x250: case 0x251: case 0x252: case 0x253: case 0x254:
            case 0x255: case 0x256: case 0x257: case 0x258: case 0x259:
                if ((irand() & 3) == 0) {
                    ReleaseField6ECByTag564_26B1E8(self);
                }
                break;
            case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B: case 0x22C: case 0x22D:
            case 0x22E: case 0x22F: case 0x23A: case 0x24A: case 0x24B: case 0x25A:
                break;
            }
        }
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->emNo) {
        case 0x200: case 0x201: case 0x204: case 0x213: case 0x217: case 0x227: case 0x228:
        case 0x22B: case 0x23A: case 0x23B: case 0x240: case 0x242: case 0x243: case 0x244:
        case 0x24A: case 0x256: case 0x25B: case 0x27E:
            switch (irand() & 1) {
            case 0:
            default:
                MOTION_PAIR(0x2E0, 0x2E4)
                break;
            case 1:
                MOTION_PAIR(0x2E8, 0x2EC)
                break;
            }
            break;
        default: case 0x202: case 0x203: case 0x20F: case 0x210: case 0x211: case 0x212:
        case 0x216: case 0x219: case 0x226: case 0x229: case 0x22A: case 0x230: case 0x231:
        case 0x232: case 0x233: case 0x234: case 0x235: case 0x236: case 0x237: case 0x238:
        case 0x239: case 0x23C: case 0x23D: case 0x23E: case 0x23F: case 0x24B: case 0x253:
        case 0x254: case 0x255: case 0x257: case 0x258: case 0x259: case 0x25C: case 0x25D:
        case 0x25E: case 0x25F: case 0x261: case 0x262: case 0x263: case 0x266: case 0x267:
        case 0x268: case 0x269: case 0x26A: case 0x26B: case 0x26C: case 0x26D: case 0x26E:
        case 0x26F: case 0x270: case 0x271: case 0x272: case 0x273: case 0x274: case 0x277:
        case 0x27A: case 0x27B: case 0x27C: case 0x27D:
            switch (irand() & 1) {
            case 0:
            default:
                MOTION_PAIR(0x784, 0x788)
                break;
            case 1:
                MOTION_PAIR(0x78C, 0x790)
                break;
            }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
            if (irand() & 1) {
                MOTION_PAIR(0x1248, 0x124C)
            } else {
                MOTION_PAIR(0x1250, 0x1254)
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218: case 0x245:
        case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
            if (irand() & 1) {
                MOTION_PAIR(0x9D0, 0x9D4)
            } else {
                MOTION_PAIR(0x9D8, 0x9DC)
            }
            break;
        case 0x250: case 0x251:
            if (irand() & 1) {
                MOTION_PAIR(0x9D0, 0x9D4)
            } else {
                MOTION_PAIR(0x9D8, 0x9DC)
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0, 0, 0);
            break;
        case 0x260:
            MOTION_PAIR(0x3184, 0x3188)
            break;
        case 0x264:
            {
                int p = self->resource;
                recA = EM_RES_REC(p, 0x3318);
                recB = EM_RES_REC(p, 0x331C);
                if (self->subA != 0) {
                    Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DB08(self->subA);
                }
            }
            break;
        case 0x265:
            {
                int p = self->resource;
                recA = EM_RES_REC(p, 0x3818);
                recB = EM_RES_REC(p, 0x381C);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x23);
                }
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
            MOTION_PAIR(0x1690, 0x1694)
            break;
        case 0x209: case 0x21F:
            MOTION_PAIR(0x1690, 0x1694)
            break;
        case 0x220: case 0x221: case 0x222:
            MOTION_PAIR(0x1D08, 0x1D0C)
            break;
        case 0x223:
            MOTION_PAIR(0x2E4C, 0x2E50)
            break;
        case 0x275: case 0x276:
            MOTION_PAIR(0x2364, 0x2368)
            break;
        }
        if (self->unk6EC != 0) {
            int p = self->resource;
            recA = EM_RES_REC(p, 0x784);
            recB = EM_RES_REC(p, 0x788);
        }
        func_002A8578(self, recA, recB, 2, 0.0f, nb, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
        func_0026F120(self);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1:
        default:
            tb = irand() % 45U + 0x3C;
            break;
        case 2:
            tb = irand() % 45U + 0x2D;
            break;
        case 3:
            tb = irand() % 45U + 0x1E;
            break;
        case 4: case 5:
            tb = irand() % 45U + 0xF;
            break;
        }
        self->timerB = tb;
        do { } while (0);
        if (self->stepArg != 0) {
            self->timerB = 0x3E7;
        }
        self->stepArg = 0;
        if ((irand() % 3U) == 0 && func_0026F1D8(self) == 0 && D_005CB010 == 0) {
            self->timerB = 0x14;
            self->stepArg = 1;
        }
        {
            char *link = (char *)self->unk698;

            self->timerA = 0;
            if (link != 0) {
                cEm00 *watched = *(cEm00 **)(link + 0x34);

                if (watched != 0) {
                    self->timerA = 0xA;
                    cVec_copy3(&self->posB, watched->pos);
                }
            }
        }
        self->step = self->step + 1;
        /* fallthrough */
    case 7:
        {
            int c = self->timerA;
            if (c != 0) {
                self->timerA = c - 1;
                cGameObj_SetTgtTurn(self, &self->posB, self->speedRate * 0.3926991f);
            }
        }
        if (moveMotion(self) != 0) {
            if (func_0026F1D8(self) != 0) {
                func_00270C78(self);
            } else {
                func_002705D8(self);
            }
        }
        {
            int c = self->timerB;
            if (c != 0) {
                self->timerB = c - 1;
                goto ADDNULL;
            }
        }
        if (self->unk17BB != 0 && self->unk1740 <= 0.0f && self->stepArg != 0) {
            if (self->emNo == 0x20E && (irand() & 1)) {
                self->mode = 0;
                self->step = 0;
                self->phase = 0x28;
                self->stepArg = 0;
                break;
            }
            if ((irand() % 12U) == 0 && self->playerDist < 9.0f && D_005CB010 == 0) {
                func_00274238(self, 0);
                break;
            }
        }
        if (func_0026F1D8(self) == 0) {
            if ((irand() % 12U) == 0 && self->playerDist < 9.0f && D_005CB010 == 0
                && self->unk17BB != 0 && self->unk1740 <= 0.0f) {
                func_00274238(self, 0);
            } else if (EM_AT(unsigned char, self, EM_UNK17B9_OFFSET) != 0 && !(irand() & 3)
                       && func_00273C38(self) != 0) {
                self->mode = 0;
                self->step = 0;
                self->phase = 0xA;
                self->stepArg = 1;
            } else if (func_00262AA8(self) == 0) {
                goto ADDNULL;
            }
        } else {
        ADDNULL:
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
        }
        break;
    }
}
