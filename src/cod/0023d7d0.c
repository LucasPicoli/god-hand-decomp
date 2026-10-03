/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void Obj1D00_ClearState_6(int a0);
extern void Obj1D00_ClearState_7(int a0);
extern int Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(int a0);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern void func_001D0B30(int a0, float a1);
extern void func_00262980(void *a0);



extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);
extern unsigned char D_005FEE00[];

/* Fields cEm00.h does not name yet. Offsets are from the record start. */
#define EM_AT(T, self, off) (*(T *)((char *)(self) + (off)))
#define EM_CHILDREN_OFFSET 0x278     /* child object list */
#define EM_CHILDNUM_OFFSET 0x2B4     /* number of children */
#define EM_TURNTO_OFFSET 0x5D0       /* point the enemy turns toward (cVec) */
#define EM_TURNFRAMES_OFFSET 0x5F0   /* frames left to keep turning toward it */
#define EM_GRABLINK_OFFSET 0x698     /* the object holding or held by this one */
#define EM_FIELDOBJ_OFFSET 0x6EC     /* field object, released by tag */
#define EM_FX0_OFFSET 0x6F0          /* effect objects 0x6F0 to 0x708 */
#define EM_FX2_OFFSET 0x6F8
#define EM_FX3_OFFSET 0x6FC
#define EM_FX4_OFFSET 0x700
#define EM_FX5_OFFSET 0x704
#define EM_FX6_OFFSET 0x708
#define EM_UNK16DC_OFFSET 0x16DC
#define EM_UNK16E0_OFFSET 0x16E0
#define EM_SPECIALCOOL_OFFSET 0x16E4 /* float, 300.0 after the special step starts */
#define EM_UNK17CA_OFFSET 0x17CA     /* unsigned short, 30 before a motion ends */
#define EM_REACTFLAG_OFFSET 0x1864   /* unsigned char, cleared when a step starts */

/* The first and second motion records of an action are two offsets in the
 * resource blob, 4 bytes apart; the motion start takes both addresses. */
#define MOTION_PAIR(a, b) { int p = self->resource; recA = EM_RES_REC(p, a); recB = EM_RES_REC(p, b); }

/* Set the next action: the four state bytes in the order the move code writes them. */
#define SETACT(ph, arg) { self->mode = 0; self->phase = (ph); self->step = 0; self->stepArg = (arg); }

/* The idle step of an enemy: step 0 picks and starts the motion for the enemy number
 * (and its sound and turn target); step 1 waits for the motion to end, then picks the
 * next action from the enemy number, the game level and a few random rolls. */
__attribute__((section(".text.cEm00_idleChooseNext")))
void cEm00_idleChooseNext(void *a0)
{
    char hold[16];              /* the frame object at $sp+0: the child count is stored through it */
    cEm00 *self = (cEm00 *)a0;
    int recB;
    int recA;
    int rId = 0x4E2;
    int rCount = 1;
    int four = 4;
    int rFlag = 0;
    int rObj = 0;
    int nextPhase;

    self->emFlags |= 0x400;
    switch (self->step) {
    case 0:
        EM_AT(unsigned char, self, EM_REACTFLAG_OFFSET) = 0;
        switch (self->emNo) {
        default:
            MOTION_PAIR(0x3BC, 0x3C0)
            break;
        case 0x214: case 0x215:
            MOTION_PAIR(0x1B90, 0x1B94)
            break;
        case 0x242: case 0x243: case 0x244:
            MOTION_PAIR(0x36A8, 0x36AC)
            break;
        case 0x256: case 0x27E:
            MOTION_PAIR(0x2BB0, 0x2BB4)
            break;
        case 0x20A: case 0x20D: case 0x20E: case 0x245: case 0x247: case 0x278:
            MOTION_PAIR(0xB64, 0xB68)
            break;
        case 0x218: case 0x246: case 0x279:
            MOTION_PAIR(0x3C2C, 0x3C30)
            ReleaseField6ECByTag564_26B1E8(self);
            break;
        case 0x20B:
            MOTION_PAIR(0x1E44, 0x1E48)
            break;
        case 0x20C: case 0x24F:
            MOTION_PAIR(0x1F90, 0x1F94)
            break;
        case 0x250: case 0x251:
            MOTION_PAIR(0x1A28, 0x1A2C)
            break;
        case 0x260:
            MOTION_PAIR(0x1A28, 0x1A2C)
            break;
        case 0x264:
            MOTION_PAIR(0x326C, 0x3270)
            break;
        case 0x265:
            MOTION_PAIR(0x3724, 0x3728)
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            MOTION_PAIR(0x17E8, 0x17EC)
            break;
        case 0x241:
            MOTION_PAIR(0x3B0C, 0x3B10)
            break;
        case 0x209:
            MOTION_PAIR(0x346C, 0x3470)
            break;
        case 0x21F:
            if (irand() & 1) {
                MOTION_PAIR(0x346C, 0x3470)
            } else {
                MOTION_PAIR(0x355C, 0x3560)
                StoreMotionParamsBoth_2609A8(self, 0x14, 0x1A, 0x37, 0, 0xF0);
                rId = 0x77;
                rCount = 0xE;
                rFlag = 2;
                rObj = EM_AT(int, self, EM_FX5_OFFSET);
            }
            break;
        case 0x220: case 0x221: case 0x222:
            MOTION_PAIR(0x1D60, 0x1D64)
            break;
        case 0x223:
            MOTION_PAIR(0x2EC4, 0x2EC8)
            break;
        case 0x275: case 0x276:
            MOTION_PAIR(0x23B8, 0x23BC)
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
            MOTION_PAIR(0x13C8, 0x13CC)
            break;
        }
        {
            int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, recA, recB, 1, 0.0f, nb, 0);
        }
        if (EM_AT(int, self, EM_FX0_OFFSET) != 0) {
            Obj1D00_ClearState_6(EM_AT(int, self, EM_FX0_OFFSET));
        }
        if (EM_AT(int, self, EM_FX6_OFFSET) != 0) {
            Obj1D00_ClearState_7(EM_AT(int, self, EM_FX6_OFFSET));
        }
        {
            char *e;
            int cnt = EM_AT(unsigned char, self, EM_CHILDNUM_OFFSET);
            *(int *)hold = cnt;
            if (four < cnt) {
                e = EM_AT(char **, self, EM_CHILDREN_OFFSET)[4];
            } else {
                e = 0;
            }
            if (e != 0) {
                SetEffectPos(0x58, 0x11, 0, *(void **)(e + 0xF0), -1, 1.0f);
            }
        }
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xF6, self, 0, 0, 0, 0);
        {
            int t = self->emNo;
            if (t >= 0x205 && (t < 0x208 || t == 0x224)) {
                if (EM_AT(int, self, EM_FX2_OFFSET) != 0) {
                    func_001D0B30(EM_AT(int, self, EM_FX2_OFFSET), 20.0f);
                }
                if (EM_AT(int, self, EM_FX3_OFFSET) != 0) {
                    func_001D0B30(EM_AT(int, self, EM_FX3_OFFSET), 20.0f);
                }
            }
        }
        func_00262980(self);
        EM_AT(int, self, EM_TURNFRAMES_OFFSET) = 0;
        {
            int h = EM_AT(int, self, EM_GRABLINK_OFFSET);
            if (h != 0) {
                int k = *(int *)(h + 0x34);
                if (k != 0) {
                    char *d = (char *)self + EM_TURNTO_OFFSET;
                    int src;
                    EM_AT(int, self, EM_TURNFRAMES_OFFSET) = 0xA;
                    src = *(int *)(k + 0xF0);
                    if (d != (char *)src) {
                        *(float *)((char *)self + EM_TURNTO_OFFSET) = *(float *)(src + 0x0);
                        *(float *)(d + 0x4) = *(float *)(src + 0x4);
                        *(float *)(d + 0x8) = *(float *)(src + 0x8);
                    }
                }
            }
        }
        if ((rId ^ 0x4E2) != 0) {
            InitRenderStruct_2A8608(self, rId, rCount, 0, rFlag, rObj);
        }
        self->step = self->step + 1;
        /* fallthrough */
    case 1:
        {
            int c = EM_AT(int, self, EM_TURNFRAMES_OFFSET);
            if (c != 0) {
                EM_AT(int, self, EM_TURNFRAMES_OFFSET) = c - 1;
                cGameObj_SetTgtTurn(self, (char *)self + EM_TURNTO_OFFSET, self->speedRate * 0.3926991f);
            }
        }
        if (moveMotion(self) != 0 || (self->moveFlags & 0x10) != 0) {
            EM_AT(unsigned short, self, EM_UNK17CA_OFFSET) = 0x1E;
            func_0026EE40(self, 0, 0);
            if ((irand() & 3) != 0 || func_00268068(self, 1) == 0) {
                switch (self->emNo) {
                case 0x200: case 0x201: case 0x202: case 0x203: case 0x204:
                case 0x213: case 0x214: case 0x215: case 0x216: case 0x217: case 0x218:
                case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B:
                case 0x23A: case 0x23B: case 0x240: case 0x242: case 0x243: case 0x244:
                case 0x246: case 0x247: case 0x24A: case 0x24B: case 0x256: case 0x25B:
                case 0x27E:
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    case 2: case 3: case 4:
                        if (irand() % 6 == 0) {
                            SETACT(0xA, 1);
                            return;
                        }
                        if ((irand() & 3) != 0) {
                            break;
                        }
                        if ((irand() & 7) != 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (EM_AT(int, self, EM_FIELDOBJ_OFFSET) != 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (func_00270D00(self) != 0) {
                            SETACT(0x4B, 0);
                            return;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 5:
                        if (irand() % 6 == 0) {
                            SETACT(0xA, 1);
                            return;
                        }
                        if ((irand() & 7) == 0 && EM_AT(int, self, EM_FIELDOBJ_OFFSET) == 0 && func_00270D00(self) != 0) {
                            SETACT(0x4B, 0);
                            return;
                        }
                        if (irand() % 6 == 0) {
                            break;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 1:
                    default:
                        break;
                    }
                    break;
                case 0x275: case 0x276:
                    if ((self->emFlags2 & 0x10380) != 0) {
                        SETACT(0x15, 0);
                        return;
                    }
                    if ((irand() & 1) != 0) {
                        SETACT(0x16, 0);
                        return;
                    }
                    SETACT(0x15, 0);
                    return;
                case 0x278: case 0x279:
                    if (irand() % 6 == 0) {
                        SETACT(0xA, 1);
                        return;
                    }
                    if ((irand() & 7) == 0 && EM_AT(int, self, EM_FIELDOBJ_OFFSET) == 0 && func_00270D00(self) != 0) {
                        SETACT(0x4B, 0);
                        return;
                    }
                    if (self->playerDist < 9.0f) {
                        SETACT(0x15, 1);
                        return;
                    }
                    break;
                case 0x20C: case 0x24F:
                    if (irand() % 6 == 0) {
                        SETACT(0xA, 1);
                        return;
                    }
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    case 2: case 3: case 4:
                        if ((irand() & 3) != 0) {
                            break;
                        }
                        if ((irand() & 7) != 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (EM_AT(int, self, EM_FIELDOBJ_OFFSET) != 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (func_00270D00(self) != 0) {
                            SETACT(0x4B, 0);
                            return;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 5:
                        if ((irand() & 7) == 0 && EM_AT(int, self, EM_FIELDOBJ_OFFSET) == 0 && func_00270D00(self) != 0) {
                            SETACT(0x4B, 0);
                            return;
                        }
                        if (irand() % 6 == 0) {
                            break;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 1:
                    default:
                        break;
                    }
                    break;
                case 0x20B:
                    if (irand() % 6 == 0) {
                        SETACT(0xA, 1);
                        return;
                    }
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    case 2: case 3: case 4:
                        if ((irand() & 3) != 0) {
                            break;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 5:
                        if (irand() % 6 == 0) {
                            break;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 1:
                    default:
                        break;
                    }
                    break;
                case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
                case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
                case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    case 2: case 3: case 4:
                        if (irand() % 6 == 0) {
                            SETACT(0xA, 1);
                            return;
                        }
                        if ((irand() & 3) != 0) {
                            break;
                        }
                        if ((irand() & 7) != 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (EM_AT(int, self, EM_FIELDOBJ_OFFSET) != 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (func_00270D00(self) != 0) {
                            SETACT(0x4B, 0);
                            return;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 5:
                        if (irand() % 6 == 0) {
                            SETACT(0xA, 1);
                            return;
                        }
                        if ((irand() & 7) == 0 && EM_AT(int, self, EM_FIELDOBJ_OFFSET) == 0 && func_00270D00(self) != 0) {
                            SETACT(0x4B, 0);
                            return;
                        }
                        if (irand() % 6 == 0) {
                            break;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 1:
                    default:
                        break;
                    }
                    break;
                case 0x205: case 0x206: case 0x207: case 0x224:
                    if ((irand() & 1) != 0) {
                        SETACT(0x16, 0);
                        return;
                    }
                    if ((irand() & 1) != 0) {
                        goto L148;
                    }
                    SETACT(0xA, 1);
                    return;
                case 0x208:
                    if (EM_AT(float, self, EM_SPECIALCOOL_OFFSET) <= 0.0f && (irand() & 3) == 0) {
                        SETACT(0x2D, 0);
                        EM_AT(float, self, EM_SPECIALCOOL_OFFSET) = 300.0f;
                        return;
                    }
                    if ((irand() & 1) != 0 && EM_AT(int, self, EM_FX4_OFFSET) != 0 &&
                        Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(EM_AT(int, self, EM_FX4_OFFSET)) == 0) {
                        SETACT(0x16, 0);
                        return;
                    }
                    if ((irand() & 1) != 0) {
                        goto L148;
                    }
                    SETACT(0xA, 1);
                    return;
                case 0x209: case 0x21F:
                    if ((irand() & 1) != 0) {
                        SETACT(0x16, 0);
                        return;
                    }
                    if ((irand() & 1) != 0) {
                    L148:
                        EM_AT(int, self, EM_UNK16DC_OFFSET) = 0;
                        EM_AT(int, self, EM_UNK16E0_OFFSET) = 0;
                        if (func_00262AA8(self) == 0) {
                            func_002705D8(self);
                        }
                        return;
                    }
                    SETACT(0xA, 1);
                    return;
                case 0x250: case 0x251:
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    case 1: case 2:
                    default:
                        if (self->emNo == 0x251 && (irand() & 3) == 0) {
                            SETACT(0x22, 0);
                            return;
                        }
                        if ((irand() & 7) == 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (irand() % 3 == 0) {
                            SETACT(0x20, 1);
                            return;
                        }
                        if (irand() % 6 == 0) {
                            SETACT(0xA, 1);
                            return;
                        }
                        break;
                    case 3: case 4: case 5:
                        if (self->emNo == 0x251 && (irand() & 3) == 0) {
                            SETACT(0x22, 0);
                            return;
                        }
                        if (irand() % 3 == 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (irand() % 3 == 0) {
                            SETACT(0x20, 1);
                            return;
                        }
                        if (irand() % 6 == 0) {
                            SETACT(0xA, 1);
                            return;
                        }
                        break;
                    }
                    break;
                case 0x260:
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    case 1: case 2:
                    default:
                        if ((irand() & 7) == 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (irand() % 6 == 0) {
                            SETACT(0xA, 1);
                            return;
                        }
                        break;
                    case 3: case 4: case 5:
                        if (irand() % 3 == 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        if (irand() % 6 == 0) {
                            SETACT(0xA, 1);
                            return;
                        }
                        break;
                    }
                    break;
                case 0x220: case 0x222:
                    if (irand() % 6 == 0) {
                        SETACT(0x12, 1);
                        return;
                    }
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    case 2: case 3: case 4:
                        if ((irand() & 3) != 0) {
                            SETACT(0x15, 0);
                            return;
                        }
                        SETACT(0x16, 0);
                        return;
                    case 5:
                        if (irand() % 6 != 0) {
                            SETACT(0x16, 0);
                            return;
                        }
                        SETACT(0x15, 0);
                        return;
                    case 1:
                    default:
                        break;
                    }
                    /* fallthrough */
                case 0x223:
                    SETACT(0x15, 0);
                    return;
                default:
                    break;
                }
                if (EM_AT(int, self, EM_FIELDOBJ_OFFSET) != 0) {
                    SETACT(0x47, 0);
                    return;
                }
                if ((irand() & 7) == 0 && EM_AT(int, self, EM_FIELDOBJ_OFFSET) == 0) {
                    if (func_00270D00(self) != 0) {
                        SETACT(0x4B, 0);
                        return;
                    }
                }
                self->mode = 0;
                self->phase = 0x15;
                self->step = 0;
                self->stepArg = 0;
                goto L199;
            }
        } else {
        L199:
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
        default:
            if (self->emNo == 0x21F) {
                func_00260B30(self);
            }
            return;
        }
        break;
    }
}
