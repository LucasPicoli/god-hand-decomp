#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_002DB770(void);
extern char D_00462FC0[];
extern char D_007474A0[];

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

/* Phase machine on the step byte, 13 case labels. Calls Getplayer, cCollisionSolidManage_SetActive,
 * func_002A8578, cCoreSave_getGameLevel, func_002DB770, VU0_VADD_XYZ_IP and 4 more. */
__attribute__((section(".text.func_002363E8"))) void func_002363E8(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);

    switch (self->step) {
        case 0: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x7E8), EM_RES_REC(p, 0x7EC), 0.0f, 0, 0, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    self->unk568 = 0x14;
                    break;
                case 2:
                    self->unk568 = 0x1E;
                    break;
                case 3:
                case 4:
                    self->unk568 = 0x28;
                    break;
                case 5:
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

            func_002DB770();
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *q;
                int p0;

                (*(short *)((char *)self + 0x56E))--;
                q = s1 + 0x550;
                p0 = (int)self->pos;
                VU0_VADD_XYZ_IP(p0, 0, q);
            }
            g = D_007474A0;
            if ((*(int *)(g + 8) & 0xF0) != 0) {
                self->unk568--;
            }
            if ((*(int *)(g + 8) & 0xF00000) != 0) {
                self->unk568 -= 4;
            }
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                self->step++;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 2: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x7D8), EM_RES_REC(p, 0x7DC), 0.0f, 0, 0, 0);
            self->step++;
        }
            /* fallthrough */
        case 3: {
            char *g;

            func_002DB770();
            g = D_007474A0;
            if ((*(int *)(g + 8) & 0xF0) != 0) {
                self->unk568--;
            }
            if ((*(int *)(g + 8) & 0xF00000) != 0) {
                self->unk568 -= 4;
            }
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                if (self->unk568 <= 0) {
                    self->step = 6;
                    *(unsigned char *)(s1 + 0x2F6) = 6;
                }
                (*(short *)((char *)self + 0x56A))--;
                if (*(short *)((char *)self + 0x56A) <= 0) {
                    self->step = 6;
                    *(unsigned char *)(s1 + 0x2F6) = 6;
                }
                if (*(short *)(s1 + 0x54A) <= 0) {
                    self->step = 4;
                    *(unsigned char *)(s1 + 0x2F6) = 4;
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 4: {
            int x;
            int y;

            self->unk1864 = 0;
            if (*(short *)(s1 + 0x54A) <= 0) {
                int p = self->resource;
                x = EM_RES_REC(p, 0x7F0);
                y = EM_RES_REC(p, 0x7F4);
            } else {
                int p = self->resource;
                x = EM_RES_REC(p, 0x7E0);
                y = EM_RES_REC(p, 0x7E4);
            }
            func_002A8578(self, x, y, 0.0f, 3, 0, 0);
            self->step++;
        }
            /* fallthrough */
        case 5:
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 6: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x7E0), EM_RES_REC(p, 0x7E4), 0.0f, 3, 0, 0);
            self->step++;
        }
            /* fallthrough */
        case 7:
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                func_002705D8(self);
                return;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
}
