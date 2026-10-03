#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int Getplayer(void);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern char D_00462FC0[];

#include "godhand/vu0.h"

/* Phase machine on the step byte, 2 case labels. Calls Getplayer, cCollisionSolidManage_SetActive,
 * func_002A8578, VU0_VADD_XYZ_IP, moveMotion, cObjBase_addNullSpeed_Rotation and 1 more. */
__attribute__((section(".text.func_0023A010"))) void func_0023A010(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x1054), EM_RES_REC(p, 0x1058), 0.0f, 0, 0, 0);
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step++;
        }
            /* fallthrough */
        case 1:
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *p;
                char *q;

                (*(short *)((char *)self + 0x56E))--;
                p = (char *)self->pos;
                q = s1 + 0x550;
                VU0_VADD_XYZ_IP(p, 0, q);
            }
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
}

#include "godhand/vu0.h"

/* Phase machine on the step byte, 2 case labels. Calls Getplayer, cCollisionSolidManage_SetActive,
 * func_002A8578, VU0_VADD_XYZ_IP, moveMotion, cObjBase_addNullSpeed_Rotation and 1 more. */
__attribute__((section(".text.func_00236D98"))) void func_00236D98(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x2EF8), EM_RES_REC(p, 0x2EFC), 0.0f, 0, 0, 0);
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step++;
        }
            /* fallthrough */
        case 1:
            self->objFlags |= 0x40000;
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *p;
                char *q;

                (*(short *)((char *)self + 0x56E))--;
                p = (char *)self->pos;
                q = s1 + 0x550;
                VU0_VADD_XYZ_IP(p, 0, q);
            }
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
}
