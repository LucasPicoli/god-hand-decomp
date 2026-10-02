/* sn-2.95.3-136 matched TU. */

/* func_00214298: an enemy that picks its first motion from a table keyed by
 * its enemy number: step 0 turns toward a point, derives the motion and its
 * speed from the turn, then both steps run the move and a level-dependent
 * chance to end the action. */
#include "godhand/cEm00.h"

extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);

extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int cCoreSave_getGameLevel(void *a0);
extern char D_00569B70[];

__attribute__((section(".text.func_00214298")))
void func_00214298(cEm00 *self)
{
    int motion;
    int s1v;
    int s0v;
    float turn;
    float ad;
    int flag;
    int go;

    switch (self->step) {
    case 0:
        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        turn = Turn_dest(self->pos, &self->unk16A0, self->rot.y, 3.14159274f);
        flag = 0;
        if (0.0f < turn) {
            flag = 1;
        }
        ad = turn;
        if (self->unk17C3 != 0) {
            flag = flag ^ 1;
        }
        if (turn < 0.0f) {
            ad = -turn;
        }
        self->timer = ad * 0.63661975f;
        if (flag != 0) {
        switch (self->emNo) {
        default: case 0x200: case 0x201: case 0x204: case 0x212: case 0x219:
        case 0x220: case 0x221: case 0x222: case 0x227: case 0x228:
        case 0x22B: case 0x230: case 0x231: case 0x232: case 0x233:
        case 0x234: case 0x235: case 0x236: case 0x237: case 0x238:
        case 0x239: case 0x23A: case 0x23B: case 0x23C: case 0x23D:
        case 0x23E: case 0x23F: case 0x240: case 0x24A: case 0x253:
        case 0x254: case 0x255: case 0x257: case 0x258: case 0x259:
        case 0x25B: case 0x25C: case 0x25D: case 0x25E: case 0x25F:
        case 0x261: case 0x262: case 0x263: case 0x266: case 0x267:
        case 0x268: case 0x269: case 0x26A: case 0x26B: case 0x26C:
        case 0x26D: case 0x26E: case 0x26F: case 0x277: case 0x27A:
        case 0x27B: case 0x27C: case 0x27D:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0xE4);
                s0v = EM_RES_REC(b, 0xE8);
            }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217:
        case 0x229: case 0x22A: case 0x24B:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x684);
                s0v = EM_RES_REC(b, 0x688);
            }
            break;
        case 0x256: case 0x27E:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x25A4);
                s0v = EM_RES_REC(b, 0x25A8);
            }
            break;
        case 0x242: case 0x243: case 0x244:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0xE4);
                s0v = EM_RES_REC(b, 0xE8);
            }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C:
        case 0x21D: case 0x21E: case 0x22C: case 0x22D: case 0x22E:
        case 0x22F: case 0x248: case 0x249: case 0x24C: case 0x24E:
        case 0x252: case 0x25A:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x10D4);
                s0v = EM_RES_REC(b, 0x10D8);
            }
            break;
        case 0x225: case 0x24D:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x3CC0);
                s0v = EM_RES_REC(b, 0x3CC4);
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x864);
                s0v = EM_RES_REC(b, 0x868);
            }
            break;
        case 0x278: case 0x279:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x1FEC);
                s0v = EM_RES_REC(b, 0x1FF0);
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x159C);
                s0v = EM_RES_REC(b, 0x15A0);
            }
            break;
        case 0x241:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x3A38);
                s0v = EM_RES_REC(b, 0x3A3C);
            }
            break;
        case 0x209: case 0x21F:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x344C);
                s0v = EM_RES_REC(b, 0x3450);
            }
            break;
        case 0x20F:
            if (self->stepArg != 0) {
                int b = self->resource;

                s1v = EM_RES_REC(b, 0xD48);
                s0v = EM_RES_REC(b, 0xD4C);
            } else {
                int b = self->resource;

                s1v = EM_RES_REC(b, 0xD30);
                s0v = EM_RES_REC(b, 0xD34);
            }
            break;
        case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0xD48);
                s0v = EM_RES_REC(b, 0xD4C);
            }
            break;
        case 0x250: case 0x251:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x192C);
                s0v = EM_RES_REC(b, 0x1930);
            }
            break;
        case 0x260:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x3070);
                s0v = EM_RES_REC(b, 0x3074);
            }
            break;
        case 0x264:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x3284);
                s0v = EM_RES_REC(b, 0x3288);
            }
            break;
        case 0x265:
            if ((self->emFlags2 & 0x20000000) != 0) {
                int b = self->resource;

                s1v = EM_RES_REC(b, 0x38D8);
                s0v = EM_RES_REC(b, 0x38DC);
            } else {
                int b = self->resource;

                s1v = EM_RES_REC(b, 0x3750);
                s0v = EM_RES_REC(b, 0x3754);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x1D);
                }
                goto start;
            }
            break;
        case 0x275: case 0x276:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x22AC);
                s0v = EM_RES_REC(b, 0x22B0);
            }
            break;
        case 0x223:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x2D64);
                s0v = EM_RES_REC(b, 0x2D68);
            }
            break;

        }
        } else {
        switch (self->emNo) {
        default: case 0x200: case 0x201: case 0x204: case 0x212: case 0x219:
        case 0x220: case 0x221: case 0x222: case 0x227: case 0x228:
        case 0x22B: case 0x230: case 0x231: case 0x232: case 0x233:
        case 0x234: case 0x235: case 0x236: case 0x237: case 0x238:
        case 0x239: case 0x23A: case 0x23B: case 0x23C: case 0x23D:
        case 0x23E: case 0x23F: case 0x240: case 0x24A: case 0x253:
        case 0x254: case 0x255: case 0x257: case 0x258: case 0x259:
        case 0x25B: case 0x25C: case 0x25D: case 0x25E: case 0x25F:
        case 0x261: case 0x262: case 0x263: case 0x266: case 0x267:
        case 0x268: case 0x269: case 0x26A: case 0x26B: case 0x26C:
        case 0x26D: case 0x26E: case 0x26F: case 0x277: case 0x27A:
        case 0x27B: case 0x27C: case 0x27D:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0xDC);
                s0v = EM_RES_REC(b, 0xE0);
            }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217:
        case 0x229: case 0x22A: case 0x24B:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x67C);
                s0v = EM_RES_REC(b, 0x680);
            }
            break;
        case 0x256: case 0x27E:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x259C);
                s0v = EM_RES_REC(b, 0x25A0);
            }
            break;
        case 0x242: case 0x243: case 0x244:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0xDC);
                s0v = EM_RES_REC(b, 0xE0);
            }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C:
        case 0x21D: case 0x21E: case 0x22C: case 0x22D: case 0x22E:
        case 0x22F: case 0x248: case 0x249: case 0x24C: case 0x24E:
        case 0x252: case 0x25A:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x10CC);
                s0v = EM_RES_REC(b, 0x10D0);
            }
            break;
        case 0x225: case 0x24D:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x3CB8);
                s0v = EM_RES_REC(b, 0x3CBC);
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x85C);
                s0v = EM_RES_REC(b, 0x860);
            }
            break;
        case 0x278: case 0x279:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x1FE4);
                s0v = EM_RES_REC(b, 0x1FE8);
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x1594);
                s0v = EM_RES_REC(b, 0x1598);
            }
            break;
        case 0x241:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x3A30);
                s0v = EM_RES_REC(b, 0x3A34);
            }
            break;
        case 0x209: case 0x21F:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x3454);
                s0v = EM_RES_REC(b, 0x3458);
            }
            break;
        case 0x20F:
            if (self->stepArg != 0) {
                int b = self->resource;

                s1v = EM_RES_REC(b, 0xD40);
                s0v = EM_RES_REC(b, 0xD44);
            } else {
                int b = self->resource;

                s1v = EM_RES_REC(b, 0xD28);
                s0v = EM_RES_REC(b, 0xD2C);
            }
            break;
        case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0xD40);
                s0v = EM_RES_REC(b, 0xD44);
            }
            break;
        case 0x250: case 0x251:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x1924);
                s0v = EM_RES_REC(b, 0x1928);
            }
            break;
        case 0x260:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x3068);
                s0v = EM_RES_REC(b, 0x306C);
            }
            break;
        case 0x264:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x327C);
                s0v = EM_RES_REC(b, 0x3280);
            }
            break;
        case 0x265:
            if ((self->emFlags2 & 0x20000000) != 0) {
                int b = self->resource;

                s1v = EM_RES_REC(b, 0x38D0);
                s0v = EM_RES_REC(b, 0x38D4);
            } else {
                int b = self->resource;

                s1v = EM_RES_REC(b, 0x3748);
                s0v = EM_RES_REC(b, 0x374C);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x1C);
                }
                goto start;
            }
            break;
        case 0x275: case 0x276:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x22A4);
                s0v = EM_RES_REC(b, 0x22A8);
            }
            break;
        case 0x223:
            {
                int b = self->resource;
                s1v = EM_RES_REC(b, 0x2D5C);
                s0v = EM_RES_REC(b, 0x2D60);
            }
            break;

        }
        }
start:
        func_002A8578(self, s1v, s0v, 0.0f, 5, motion, 0);
        self->step = self->step + 1;
    case 1:
        self->emFlags2 = self->emFlags2 | 1;
        if (moveMotion(self) != 0) {
            if (func_00262AA8(self) != 0) {
                return;
            }
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, self->timer);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    if (self->stepArg != 0) {
        return;
    }
    go = 1;
    switch (cCoreSave_getGameLevel(D_00569B70)) {
    default:
        if (self->unk16D8 != 0) {
            go = 0;
        }
        break;
    case 1:
        if (self->unk16D8 != 0) {
            go = 0;
        }
        break;
    case 2:
        if (self->unk16D8 >= 2) {
            go = 0;
        }
        break;
    case 3:
        if (self->unk16D8 >= 3) {
            go = 0;
        }
        break;
    case 4:
        if (self->unk16D8 >= 3) {
            go = 0;
        }
        break;
    case 5:
        if (self->unk16D8 >= 100) {
            go = 0;
        }
        break;
    }
    if (go != 0) {
        func_00262AA8(self);
    }
}
