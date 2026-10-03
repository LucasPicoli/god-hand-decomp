#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0027DBF8(int a0, int a1);
extern void func_00281500(int a0, int a1);
extern void func_002833D8(int a0, int a1);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void KillEffect(void *a0, int a1, int a2);

/* sn-2.95.3-136 candidate. */

















/* Phase machine on the step byte, 169 case labels. Calls ReleaseField6ECByTag564_26B1E8,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation,
 * cObjBase_addNullSpeed and 9 more. */
__attribute__((section(".text.func_002580B8"))) void func_002580B8(cEm00 *self)
{
    int s2;
    int s1;
    int s3;

    if (self->step == 0) {
        switch (self->emNo) {
            case 0x223:
            case 0x241:
            case 0x260:
            case 0x26A:
            case 0x275:
            case 0x276:
                self->step = 2;
                break;
            case 0x265:
                if ((self->emFlags2 & 0x20000000) != 0) {
                    self->step = 0xA;
                }
                break;
            case 0x264:
                self->step = 2;
                if ((self->emFlags2 & 0x10000000) != 0) {
                    self->step = 4;
                }
                break;
        }
    }

    switch (self->step) {
        case 0: {
            int nb;

            switch (self->emNo) {
                default: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x5F0);
                    s1 = EM_RES_REC(b, 0x5F4);
                } break;
                case 0x256:
                case 0x27E: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x2908);
                    s1 = EM_RES_REC(b, 0x290C);
                } break;
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
                case 0x279: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0xADC);
                    s1 = EM_RES_REC(b, 0xAE0);
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224:
                case 0x241: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x1770);
                    s1 = EM_RES_REC(b, 0x1774);
                } break;
                case 0x209:
                case 0x21F: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x1770);
                    s1 = EM_RES_REC(b, 0x1774);
                } break;
                case 0x20F:
                case 0x210:
                case 0x211:
                case 0x226:
                case 0x270:
                case 0x271:
                case 0x272:
                case 0x273:
                case 0x274: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0xF1C);
                    s1 = EM_RES_REC(b, 0xF20);
                } break;
                case 0x220:
                case 0x221:
                case 0x222: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x5F0);
                    s1 = EM_RES_REC(b, 0x5F4);
                } break;
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
                case 0x25A: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x1348);
                    s1 = EM_RES_REC(b, 0x134C);
                } break;
                case 0x265: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x38A8);
                    s1 = EM_RES_REC(b, 0x38AC);
                } break;
            }
            ReleaseField6ECByTag564_26B1E8(self);
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, s2, s1, 0.0f, 3, nb, 0);
            self->timerA = 1;
            self->unk16EC = 0;
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (func_0026F1D8(self) == 0) {
                self->step = 8;
            }
            break;
        case 2: {
            int nb;

            self->timer = 0.0f;
            switch (self->emNo) {
                default:
                case 0x270:
                case 0x271: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x2390);
                    s1 = EM_RES_REC(b, 0x2394);
                } break;
                case 0x223: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x2E54);
                    s1 = EM_RES_REC(b, 0x2E58);
                } break;
                case 0x260: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x31AC);
                    s1 = EM_RES_REC(b, 0x31B0);
                    self->timer = 30.0f;
                } break;
                case 0x264: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3380);
                    s1 = EM_RES_REC(b, 0x3384);
                    if (*(int *)((char *)self + 0x740) != 0) {
                        func_0027DBF8(*(int *)((char *)self + 0x740), 0);
                    }
                    self->timer = 30.0f;
                } break;
                case 0x241: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3AB4);
                    s1 = EM_RES_REC(b, 0x3AB8);
                } break;
                case 0x26A: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3DFC);
                    s1 = EM_RES_REC(b, 0x3E00);
                    if (self->sub0 != 0) {
                        func_00281500(self->sub0, 0);
                    }
                    if (self->sub1 != 0) {
                        func_002833D8(self->sub1, 0);
                    }
                    if (self->sub2 != 0) {
                        func_002833D8(self->sub2, 0);
                    }
                    self->timer = 60.0f;
                } break;
            }
            ReleaseField6ECByTag564_26B1E8(self);
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, s2, s1, 0.0f, 3, nb, 0);
            self->timerA = 1;
            self->emFlags2 |= 0x10000000;
            self->step += 1;
            self->unk16EC = 0;
        }
            /* fallthrough */
        case 3: {
            float d = self->timer;

            if (0.0f < d) {
                self->emFlags |= 0x800000;
                self->timer = d - self->speedRate;
            }
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
        } break;
        case 4: {
            int nb;

            switch (self->emNo) {
                default:
                case 0x270:
                case 0x271: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x2398);
                    s1 = EM_RES_REC(b, 0x239C);
                } break;
                case 0x223: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x2E5C);
                    s1 = EM_RES_REC(b, 0x2E60);
                } break;
                case 0x260: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x31B4);
                    s1 = EM_RES_REC(b, 0x31B8);
                } break;
                case 0x264: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3388);
                    s1 = EM_RES_REC(b, 0x338C);
                    if (*(int *)((char *)self + 0x740) != 0) {
                        func_0027DBF8(*(int *)((char *)self + 0x740), 1);
                    }
                } break;
                case 0x241: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3ABC);
                    s1 = EM_RES_REC(b, 0x3AC0);
                } break;
                case 0x26A: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3E04);
                    s1 = EM_RES_REC(b, 0x3E08);
                    if (self->sub0 != 0) {
                        func_00281500(self->sub0, 1);
                    }
                    if (self->sub1 != 0) {
                        func_002833D8(self->sub1, 1);
                    }
                    if (self->sub2 != 0) {
                        func_002833D8(self->sub2, 1);
                    }
                } break;
            }
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, s2, s1, 0.0f, 3, nb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 5:
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (func_0026F1D8(self) == 0) {
                self->step += 1;
            }
            break;
        case 6: {
            int nb;

            switch (self->emNo) {
                default:
                case 0x270:
                case 0x271: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x23A0);
                    s1 = EM_RES_REC(b, 0x23A4);
                } break;
                case 0x223: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x2E64);
                    s1 = EM_RES_REC(b, 0x2E68);
                } break;
                case 0x260: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x31BC);
                    s1 = EM_RES_REC(b, 0x31C0);
                } break;
                case 0x264: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3390);
                    s1 = EM_RES_REC(b, 0x3394);
                    if (*(int *)((char *)self + 0x740) != 0) {
                        func_0027DBF8(*(int *)((char *)self + 0x740), 2);
                    }
                } break;
                case 0x241: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3AC4);
                    s1 = EM_RES_REC(b, 0x3AC8);
                } break;
                case 0x26A: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3E0C);
                    s1 = EM_RES_REC(b, 0x3E10);
                    if (self->sub0 != 0) {
                        func_00281500(self->sub0, 1);
                    }
                    if (self->sub1 != 0) {
                        func_002833D8(self->sub1, 1);
                    }
                    if (self->sub2 != 0) {
                        func_002833D8(self->sub2, 1);
                    }
                } break;
            }
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, s2, s1, 0.0f, 3, nb, 0);
            self->timer = 30.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 7: {
            float d = self->timer;

            if (0.0f < d) {
                self->emFlags |= 0x800000;
                self->timer = d - self->speedRate;
            }
            if (moveMotion(self) != 0) {
                if (self->emNo == 0x26A) {
                    func_002705D8(self);
                    break;
                }
                self->step = 8;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
        } break;
        case 8:
            s3 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                default: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x98);
                    s1 = EM_RES_REC(b, 0x9C);
                } break;
                case 0x202:
                case 0x203:
                case 0x213:
                case 0x216:
                case 0x217:
                case 0x229:
                case 0x22A:
                case 0x24B: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x648);
                    s1 = EM_RES_REC(b, 0x64C);
                } break;
                case 0x242:
                case 0x243:
                case 0x244: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x35CC);
                    s1 = EM_RES_REC(b, 0x35D0);
                } break;
                case 0x256:
                case 0x27E: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x25AC);
                    s1 = EM_RES_REC(b, 0x25B0);
                } break;
                case 0x214:
                case 0x215:
                case 0x21A:
                case 0x21B:
                case 0x21C:
                case 0x21D:
                case 0x21E:
                case 0x22C:
                case 0x22D:
                case 0x22E:
                case 0x22F:
                case 0x248:
                case 0x249:
                case 0x24C:
                case 0x24E:
                case 0x25A: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x10A8);
                    s1 = EM_RES_REC(b, 0x10AC);
                } break;
                case 0x225:
                case 0x24D: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3C88);
                    s1 = EM_RES_REC(b, 0x3C8C);
                } break;
                case 0x252: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x24EC);
                    s1 = EM_RES_REC(b, 0x24F0);
                } break;
                case 0x20A:
                case 0x20B:
                case 0x20D:
                case 0x20E:
                case 0x218:
                case 0x245:
                case 0x246:
                case 0x247: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x828);
                    s1 = EM_RES_REC(b, 0x82C);
                } break;
                case 0x278:
                case 0x279: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x1FB0);
                    s1 = EM_RES_REC(b, 0x1FB4);
                } break;
                case 0x20C:
                case 0x24F: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x1EAC);
                    s1 = EM_RES_REC(b, 0x1EB0);
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x1560);
                    s1 = EM_RES_REC(b, 0x1564);
                } break;
                case 0x241: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3A00);
                    s1 = EM_RES_REC(b, 0x3A04);
                } break;
                case 0x209:
                case 0x21F: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3418);
                    s1 = EM_RES_REC(b, 0x341C);
                } break;
                case 0x250:
                case 0x251: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x18F0);
                    s1 = EM_RES_REC(b, 0x18F4);
                } break;
                case 0x260: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3038);
                    s1 = EM_RES_REC(b, 0x303C);
                } break;
                case 0x264: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x326C);
                    s1 = EM_RES_REC(b, 0x3270);
                } break;
                case 0x265: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x3724);
                    s1 = EM_RES_REC(b, 0x3728);
                    if (self->unk744 != 0) {
                        ForwardAnimParamPairByIndex_27EA50(self->unk744, 0);
                    }
                } break;
                case 0x20F:
                case 0x210:
                case 0x226:
                case 0x270:
                case 0x271:
                case 0x272:
                case 0x273:
                case 0x274: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0xCF8);
                    s1 = EM_RES_REC(b, 0xCFC);
                } break;
                case 0x211: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x244C);
                    s1 = EM_RES_REC(b, 0x2450);
                } break;
                case 0x220:
                case 0x221:
                case 0x222: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x1BC0);
                    s1 = EM_RES_REC(b, 0x1BC4);
                } break;
                case 0x223: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x2D38);
                    s1 = EM_RES_REC(b, 0x2D3C);
                } break;
                case 0x275:
                case 0x276: {
                    int b = self->resource;
                    s2 = EM_RES_REC(b, 0x2274);
                    s1 = EM_RES_REC(b, 0x2278);
                } break;
            }
            if (*(int *)((char *)self + 0x6EC) != 0) {
                int b = self->resource;
                s2 = EM_RES_REC(b, 0x44C);
                s1 = EM_RES_REC(b, 0x450);
            }
            func_002A8578(self, s2, s1, 0.0f, 0xA, s3, 0);
            self->timer = 15.0f;
            self->step += 1;
            /* fallthrough */
        case 9: {
            float d;

            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            d = self->timer - self->speedRate;
            self->timer = d;
            if (d <= 0.0f) {
                func_0026EE40(self, 0, 0);
                func_002705D8(self);
            }
        } break;
        case 10: {
            int nb;
            int b = self->resource;

            s2 = EM_RES_REC(b, 0x3978);
            s1 = EM_RES_REC(b, 0x397C);
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, s2, s1, 0.0f, 3, nb, 0);
            self->emFlags2 &= ~0x20000000;
            KillEffect(self, 1, 2);
            self->step += 1;
        }
            /* fallthrough */
        case 11:
            self->emFlags |= 0x800000;
            if (moveMotion(self) != 0) {
                self->step = 0xC;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 12: {
            int nb;
            int b = self->resource;

            s2 = EM_RES_REC(b, 0x3980);
            s1 = EM_RES_REC(b, 0x3984);
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, s2, s1, 0.0f, 3, nb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 13:
            if (moveMotion(self) != 0) {
                self->step = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (func_00274150(self) != 0 || 0.0f < *(float *)((char *)self + 0x1734)) {
        self->mode = 0;
        self->phase = 0x89;
        self->step = 0;
        self->stepArg = 0;
    }
}
