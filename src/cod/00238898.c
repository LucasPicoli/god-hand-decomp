#include "godhand/cEm00.h"

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

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"














/* Phase machine on the step byte, 13 case labels. Calls Getplayer, func_002A8578,
 * cCoreSave_getGameLevel, cCollisionSolidManage_SetActive, VU0_VADD_XYZ_IP, moveMotion and 4 more.
 */
__attribute__((section(".text.func_00238898"))) void func_00238898(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    switch (self->step) {
        case 0: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x3224), EM_RES_REC(p, 0x3228), 0.0f, 0, 0, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    self->unk568 = 0x1E;
                    break;
                case 2:
                    self->unk568 = 0x23;
                    break;
                case 3:
                case 4:
                    self->unk568 = 0x28;
                    break;
                case 5:
                    self->unk568 = 0x2D;
                    break;
            }
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step++;
        }
            /* fallthrough */
        case 1:
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *q;
                int p0;

                (*(short *)((char *)self + 0x56E))--;
                q = s1 + 0x550;
                p0 = (int)self->pos;
                VU0_VADD_XYZ_IP(p0, 0, q);
            }
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                self->step = 2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x322C), EM_RES_REC(p, 0x3230), 0.0f, 0, 0, 0);
            self->step++;
        }
            /* fallthrough */
        case 3:
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                *(unsigned char *)(s1 + 0x2F6) = 4;
                self->step = 4;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (*(short *)(s1 + 0x54A) > 0) {
                char *g;

                func_002DB770();
                g = D_007474A0;
                if ((*(int *)(g + 8) & 0xF0) != 0) {
                    self->unk568--;
                }
                if ((*(int *)(g + 8) & 0xF00000) != 0) {
                    self->unk568 -= 4;
                }
                if (self->unk568 <= 0) {
                    self->step = 6;
                    *(unsigned char *)(s1 + 0x2F6) = 6;
                }
            }
            break;
        case 4: {
            int p;

            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x3234), EM_RES_REC(p, 0x3238), 0.0f, 3, 0, 0);
            self->step++;
        }
            /* fallthrough */
        case 5:
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
            *(short *)((char *)self + 0x434) |= 8;
            self->hitFlash = 3.0f;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 6: {
            int p;

            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x323C), EM_RES_REC(p, 0x3240), 0.0f, 3, 0, 0);
            self->unk568 = 0x1E;
            self->step++;
        }
            /* fallthrough */
        case 7:
            if (self->unk568 != 0) {
                self->unk568--;
                cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
                self->hitFlash = 3.0f;
            }
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
