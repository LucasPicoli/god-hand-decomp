/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"
#include "godhand/cEm00.h"

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);


extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern unsigned char D_005FEE00[];
extern unsigned char D_005CB010;
extern unsigned char D_00747A2C[];

#define FRAME ((char *)va - 0x30)

/* The record the target link at 0x698 points to; only the enemy pointer is named. */
typedef struct cEmLink {
    char unk00[0x34];
    cEm00 *target;                          /* 0x34 the enemy being watched */
} cEmLink;
/* A jumping enemy. Step 0 starts the jump motion chosen by the enemy number and
 * aims at the linked enemy. Step 1 applies gravity and waits for the floor. Step 2
 * starts the fall motion. Step 3 falls until the line check hits the floor, then
 * picks the next state from the game level. */
__attribute__((section(".text.func_00255EB0")))
void func_00255EB0(cEm00 *self)
{
    float va[4], vb[4], vc[4], vd[4];
    cVec *p = self->pos;
    int ma;
    int mb;
    int gb;

    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x30);
    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    self->emFlags |= 0x10000;
    switch (self->step) {
    case 0:
        if (self->unk6EC != 0) {
            switch (self->emNo) {
            case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B:
            case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x23A:
            case 0x24A: case 0x24B: case 0x25A:
                break;
            default:
                if ((irand() & 3) == 0) {
                    ReleaseField6ECByTag564_26B1E8(self);
                }
                break;
            }
        }
        self->home.y = -0.39000002f;
        self->unk1710 = 0;
        if (func_002740D8(self) != 0) {
            if ((irand() & 1) != 0) {
                self->unk17C3 = 1;
            } else {
                self->unk17C3 = 0;
            }
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->emNo) {
        default:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x628);
            mb = EM_RES_REC(b, 0x62C);
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270:
        case 0x271: case 0x272: case 0x273: case 0x274:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0xF74);
            mb = EM_RES_REC(b, 0xF78);
        }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x278: case 0x279:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0xB4C);
            mb = EM_RES_REC(b, 0xB50);
        }
            break;
        case 0x250: case 0x251:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0xB4C);
            mb = EM_RES_REC(b, 0xB50);
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0, 0, 0);
        }
            break;
        case 0x260:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0xB4C);
            mb = EM_RES_REC(b, 0xB50);
        }
            break;
        case 0x264:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x326C);
            mb = EM_RES_REC(b, 0x3270);
        }
            break;
        case 0x265:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x3818);
            mb = EM_RES_REC(b, 0x381C);
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        case 0x241:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x17C0);
            mb = EM_RES_REC(b, 0x17C4);
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x17C0);
            mb = EM_RES_REC(b, 0x17C4);
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x628);
            mb = EM_RES_REC(b, 0x62C);
        }
            break;
        case 0x223:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x2E34);
            mb = EM_RES_REC(b, 0x2E38);
        }
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x22F:
        case 0x248: case 0x249: case 0x24C: case 0x24D: case 0x24E:
        case 0x252: case 0x25A:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x13A0);
            mb = EM_RES_REC(b, 0x13A4);
        }
            break;
        }
        func_002A8578(self, ma, mb, 0.0f, 3, gb, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
        self->timerA = 0;
        {
            cEmLink *q = self->unk698;

            if (q != 0) {
                cEm00 *r = q->target;

                if (r != 0) {
                    cVec *d = &self->posB;
                    cVec *e;

                    self->timerA = 0xA;
                    e = r->pos;
                    if (d != e) {
                        self->posB.x = e->x;
                        d->y = e->y;
                        d->z = e->z;
                    }
                }
            }
        }
        self->timerB = 0;
        self->step += 1;
        /* fallthrough */
    case 1:
    {
        int c = self->timerA;
        float one;
        cVec *q;

        if (c != 0) {
            self->timerA = c - 1;
            cGameObj_SetTgtTurn(self, &self->posB, self->speedRate * 0.3926991f);
        }
        self->pos->y = self->pos->y + self->home.y * self->speedRate;
        q = self->pos;
        self->home.y = self->home.y - self->speedRate * 0.013f;
        va[1] = va[1] + 0.5f;
        vb[1] = q->y - 10.0f;
        if (ChkLine(va, vb, vc, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) == 1) {
            cVec *r = self->pos;

            if (r->y <= vc[1] + 0.01f) {
                r->y = vc[1];
                self->timerB |= 2;
            }
        }
        self->unk434 |= 8;
        if (moveMotion(self) != 0) {
            self->timerB |= 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        if (self->timerB == 3) {
            self->step += 1;
        }
        break;
    }
    case 2: {
        float v = 0.156f;

        self->unk1710 = 0;
        if (self->stepArg != 0) {
            v = 0.208f;
        }
        *(volatile float *)&self->home.y = v;
        switch (*(volatile int *)&self->emNo) {
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270:
        case 0x271: case 0x272: case 0x273: case 0x274:
            self->home.y = self->home.y * 1.1f;
            break;
        case 0x250: case 0x251:
        {
            char *pad = (char *)D_00747A2C;

            if ((*(int *)(pad + 0x10) & 0x8000) != 0) {
                goto padck;
            }
            if ((*(int *)(pad + 0x10) & 0x4000) != 0) {
            padck:
                if (*(unsigned short *)(pad + 0x24) == 0x45) {
                    self->home.y = 0.1092f;
                }
            }
        }
            if (D_005CB010 == 0) {
                self->home.y = self->home.y * 0.8f;
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x260: case 0x264: case 0x265: case 0x278: case 0x279:
            if (D_005CB010 == 0) {
                self->home.y = self->home.y * 0.8f;
            }
            break;
        default:
            break;
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->emNo) {
        default:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x630);
            mb = EM_RES_REC(b, 0x634);
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270:
        case 0x271: case 0x272: case 0x273: case 0x274:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0xF7C);
            mb = EM_RES_REC(b, 0xF80);
        }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x250: case 0x251: case 0x278: case 0x279:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0xB54);
            mb = EM_RES_REC(b, 0xB58);
        }
            break;
        case 0x260:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0xB54);
            mb = EM_RES_REC(b, 0xB58);
        }
            break;
        case 0x264:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x326C);
            mb = EM_RES_REC(b, 0x3270);
        }
            break;
        case 0x265:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x3818);
            mb = EM_RES_REC(b, 0x381C);
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        case 0x241:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x17C8);
            mb = EM_RES_REC(b, 0x17CC);
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x17C8);
            mb = EM_RES_REC(b, 0x17CC);
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x630);
            mb = EM_RES_REC(b, 0x634);
        }
            break;
        case 0x223:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x2EA4);
            mb = EM_RES_REC(b, 0x2EA8);
        }
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x248:
        case 0x249: case 0x24C: case 0x24D: case 0x24E: case 0x252:
        {
            int b = self->resource;
            ma = EM_RES_REC(b, 0x13A8);
            mb = EM_RES_REC(b, 0x13AC);
        }
            break;
        }
        func_002A8578(self, ma, mb, 0.0f, 0, gb, 0);
        self->step += 1;
    }
        /* fallthrough */
    case 3:
    {
        int c = self->timerA;

        if (c != 0) {
            self->timerA = c - 1;
            cGameObj_SetTgtTurn(self, &self->posB, self->speedRate * 0.3926991f);
        }
        if (self->moveFlags & 4) {
            cVec *q;
            float vy;

            q = self->pos;
            q->y = q->y + self->home.y * self->speedRate;
            vy = self->home.y;
            if (vy <= 0.0f) {
                self->home.y = vy - self->speedRate * 0.0078000003f;
            } else {
                self->home.y = vy - self->speedRate * 0.013f;
            }
            if (self->home.y <= 0.0f) {
                cVec *t = self->pos;

                va[1] = va[1] + 0.5f;
                vb[1] = t->y - 10.0f;
                if (ChkLine(va, vb, vc, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    cVec *r = self->pos;

                    if (r->y <= vc[1] + 0.01f) {
                        r->y = vc[1];
                        self->mode = 1;
                        self->phase = 8;
                        self->step = 2;
                        self->stepArg = 0;
                        switch (self->emNo) {
                        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
                        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
                        case 0x250: case 0x251: case 0x260: case 0x264: case 0x265:
                        case 0x278: case 0x279:
                            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                            case 2: case 3: case 4:
                                if (irand() % 3 != 0) {
                                    break;
                                }
                                /* fallthrough */
                            case 5:
                                if (self->vital > 0) {
                                    if (func_0026F1D8(self) == 0) {
                                        self->mode = 1;
                                        self->phase = 8;
                                        self->step = 4;
                                        self->stepArg = 0;
                                    }
                                }
                                break;
                            case 1:
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }
                    }
                }
            } else {
                cVec *t;

                VU0_SQC2_VF0(FRAME, 0x60);
                t = self->pos;
                vb[1] = t->y + 10.0f;
                if (ChkLine(va, vb, vd, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    cVec *r = self->pos;
                    float h = vd[1] - 1.5f;

                    if (h < r->y) {
                        r->y = h;
                        self->home.y = 0.0f;
                    }
                }
            }
        }
        self->unk434 |= 8;
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    }
}
