#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern char D_007474A0[];
extern char *Getplayer(void);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);
extern void func_00274FE8(void *a0);

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"














/* Phase machine on the step byte, 16 case labels. Calls Getplayer, cCollisionSolidManage_SetActive,
 * func_002A8578, cCoreSave_getGameLevel, VU0_VADD_XYZ_IP, moveMotion and 4 more. */
__attribute__((section(".text.func_002367C0"))) void func_002367C0(cEm00 *self)
{
    char *s1;

    s1 = Getplayer();
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    switch (self->step) {
        case 0: {
            int w = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(w, 0x100C), EM_RES_REC(w, 0x1010), 0.0f, 0, 0, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
                default:
                case 0:
                    self->unk568 = 0x14;
                    break;
                case 1:
                    self->unk568 = 0x1E;
                    break;
                case 2:
                case 3:
                    self->unk568 = 0x28;
                    break;
                case 4:
                    self->unk568 = 0x32;
                    break;
            }
            *(short *)((char *)self + 0x56A) = 4;
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step++;
        }
        /* fallthrough */
        case 1: {
            char *g;
            char *p = (char *)self->pos;
            char *q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
            self->hitFlash = 3.0f;
            if (moveMotion(self))
                self->step = 2;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            func_002DB770();
            g = D_007474A0;
            if ((*(int *)(g + 8) & 0xF0) != 0)
                self->unk568 = self->unk568 - 1;
            if ((*(int *)(g + 8) & 0xF00000) != 0)
                self->unk568 = self->unk568 - 4;
            break;
        }
        case 2: {
            int w = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(w, 0xFF4), EM_RES_REC(w, 0xFF8), 0.0f, 0, 0, 0);
            self->step++;
        }
        /* fallthrough */
        case 3: {
            char *g;
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *p;
                char *q;
                *(short *)((char *)self + 0x56E) = *(unsigned short *)((char *)self + 0x56E) - 1;
                p = (char *)self->pos;

                q = s1 + 0x550;
                VU0_VADD_XYZ_IP(p, 0, q);
            }
            func_002DB770();
            g = D_007474A0;
            if ((*(int *)(g + 8) & 0xF0) != 0)
                self->unk568 = self->unk568 - 1;
            if ((*(int *)(g + 8) & 0xF00000) != 0)
                self->unk568 = self->unk568 - 4;
            self->hitFlash = 3.0f;
            if (moveMotion(self)) {
                self->step = 4;
                if (*(short *)(s1 + 0x54A) > 0) {
                    *(unsigned char *)(s1 + 0x2F6) = 4;
                } else {
                    *(unsigned char *)(s1 + 0x2F5) = 0;
                    *(unsigned char *)(s1 + 0x2F4) = 2;
                    *(unsigned char *)(s1 + 0x2F6) = 0;
                    *(unsigned char *)(s1 + 0x2F7) = 0;
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (*(short *)(s1 + 0x54A) > 0 && self->unk568 <= 0) {
                self->step = 6;
                *(unsigned char *)(s1 + 0x2F6) = 6;
            }
            break;
        }
        case 4: {
            int w = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(w, 0x1004), EM_RES_REC(w, 0x1008), 0.0f, 3, 0, 0);
            self->step++;
        }
        /* fallthrough */
        case 5:
            self->hitFlash = 3.0f;
            if (moveMotion(self)) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 6: {
            int w = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(w, 0xFFC), EM_RES_REC(w, 0x1000), 0.0f, 3, 0, 0);
            self->step++;
        }
        /* fallthrough */
        case 7:
            self->hitFlash = 3.0f;
            if (moveMotion(self)) {
                int hp = self->vital;
                int d = 0x14;
                switch (cCoreSave_getGameLevel(&D_00569B70)) {
                    default:
                    case 0:
                        break;
                    case 4:
                        d = 0x12;
                        break;
                    case 5:
                        d = 0xF;
                        break;
                }
                hp = hp - d;
                if (hp <= 0)
                    hp = 0;
                if (hp >= self->vitalMax)
                    self->vital = self->vitalMax;
                else
                    self->vital = hp;
                if (hp <= 0) {
                    self->mode = 2;
                    self->phase = 1;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    func_00274FE8(self);
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
}
