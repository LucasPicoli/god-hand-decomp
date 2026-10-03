/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern int Obj2B28_SetField34_To1_ReturnZero(void *);
extern int Obj2B28_SetField34_To2_ReturnZero(void *);
extern int Obj2B28_ReturnZero_F68(void *);
extern int Obj2B28_ReturnZero_F70(void *);
extern int Obj2B28_ReturnZero_F78(void *);
extern int Obj2B28_ReturnZero_FA8(void *);
extern int Obj2B28_ReturnZero_FD0(void *);
extern int Obj2B28_CopyU16_8C2_To38_ReturnZero(void *);
extern int Obj2B28_ReturnZero_FF0(void *);
extern int Obj2B28_ReturnZero_FF8(void *);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void Obj2810_ClearState_4(void *a0);
extern void SetBytes2F4Mode4_283240(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern int moveMotion(void *a0);
extern int irand(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern void func_0026DB00(void *a0, int a1, int a2);
extern char D_005FEE00[];

/* sn-2.95.3-136 candidate. */






























__attribute__((section(".text.func_002B2638")))
int func_002B2638(void *obj) {
    switch (**(unsigned short **)((char *)obj + 0x8C) & 0xFF00) {
    default:     return 2;
    case 0x8100: return func_002B2A30(obj);
    case 0x8200: return func_002B2A58(obj);
    case 0x8300: return func_002B2AE8(obj);
    case 0x8500: return func_002B2B08(obj);
    case 0xA600: return func_002B2B78(obj);
    case 0xA700: return func_002B2BA8(obj);
    case 0x8700: return Obj2B28_SetField34_To1_ReturnZero(obj);
    case 0x8A00: return Obj2B28_SetField34_To2_ReturnZero(obj);
    case 0xA100:
    case 0xA500: return 0;
    case 0xA200: return func_002B2F38(obj);
    case 0xE100: return Obj2B28_ReturnZero_F68(obj);
    case 0xE000: return Obj2B28_ReturnZero_F70(obj);
    case 0xE200: return Obj2B28_ReturnZero_F78(obj);
    case 0xE400: return func_002B2BD8(obj);
    case 0xE500: return func_002B2C98(obj);
    case 0xD300: return func_002B2F80(obj);
    case 0x8800: return Obj2B28_ReturnZero_FA8(obj);
    case 0x8B00: return func_002B2FB0(obj);
    case 0xD500: return Obj2B28_ReturnZero_FD0(obj);
    case 0xAC00: return Obj2B28_CopyU16_8C2_To38_ReturnZero(obj);
    case 0xD600: return Obj2B28_ReturnZero_FF0(obj);
    case 0xD700: return Obj2B28_ReturnZero_FF8(obj);
    case 0xD800: return func_002B3000(obj);
    case 0x8C00: return func_002B3008(obj);
    case 0x8E00: return func_002B3020(obj);
    case 0xAD00: return func_002B2D28(obj);
    case 0x8F00: return func_002B3038(obj);
    case 0xDA00: return func_002B3050(obj);
    case 0xE700: return func_002B2D88(obj);
    }
}

/* sn-2.95.3-136 matched TU. */

















/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, Obj2810_ClearState_4, SetBytes2F4Mode4_283240, StoreMotionParamsBoth_2609A8,
 * moveMotion and 7 more. */
__attribute__((section(".text.func_0024A768"))) void func_0024A768(cEm00 *self)
{
    self->emFlags |= 0x30400;
    switch (self->step) {
        case 0: {
            int nb;
            char *v1;

            self->unk1864 = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0x3D8C), EM_RES_REC((int)v1, 0x3D90), 0xA, 0.0f,
                          nb, 0);
            if ((void *)self->sub0 != 0)
                Obj2810_ClearState_4((void *)self->sub0);
            if ((void *)self->sub1 != 0)
                SetBytes2F4Mode4_283240((void *)self->sub1);
            if ((void *)self->sub2 != 0)
                SetBytes2F4Mode4_283240((void *)self->sub2);
            StoreMotionParamsBoth_2609A8(self, 0x32, 0x3B, 0x3E, -1, 0);
            self->timer = 0.0f;
            self->unk568 = 0;
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            self->emFlags |= 0x800000;
            if (moveMotion(self) != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) < 3) {
                    if ((irand() & 1) != 0) {
                        if (self->playerDist > 64.0f) {
                            self->mode = 0;
                            self->phase = 0x6C;
                            self->step = 0;
                            self->stepArg = 0;
                            break;
                        }
                    }
                }
                self->mode = 0;
                self->phase = 0xA1;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if ((self->moveFlags & 1) != 0) {
        float t = self->timer - self->speedRate;

        self->timer = t;
        if (t <= 0.0f) {
            self->timer = 35.0f;
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x1E, self, 0, 0, 0, 0);
            if ((irand() & 1) != 0) {
                func_0026BEF0(self, 0x19, 0);
                func_0026BEF0(self, 0x19, 2);
                if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                    func_0026BEF0(self, 0x19, 1);
                    func_0026BEF0(self, 0x19, 3);
                }
                self->unk568 = 1;
            } else {
                func_0026BEF0(self, 0x19, 4);
                func_0026BEF0(self, 0x19, 6);
                if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                    func_0026BEF0(self, 0x19, 5);
                    func_0026BEF0(self, 0x19, 7);
                }
                self->unk568 = 0;
            }
        }
        if ((self->moveFlags & 1) != 0) {
            func_0026DB00(self, 5, 0);
        }
    }
}
