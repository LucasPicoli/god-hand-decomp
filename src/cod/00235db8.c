#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

/* func_00235DB8, 980 B, sn-2.95.3-136. Wave 2026-08-31 V1 E + block-local base per if/else arm with the argument sums in the arms (x, y at function scope). */
/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002DB770(void);
extern void func_002705D8(void *a0);
extern char D_00462FC0[];
extern char D_007474A0[];

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

/* Phase machine on the step byte, 11 case labels. Calls Getplayer, func_002A8578,
 * cCoreSave_getGameLevel, cCollisionSolidManage_SetActive, VU0_VADD_XYZ_IP, moveMotion and 4 more.
 */
__attribute__((section(".text.func_00235DB8"))) void func_00235DB8(cEm00 *self)
{
    int x;
    int y;
    char *s1 = (char *)Getplayer();

    switch (self->step) {
        case 0: {
            int p;
            int aa;
            int bb;
            int t = self->emNo;

            self->unk1864 = 0;
            if (t < 0x252) {
                if (t >= 0x250)
                    goto lo0;
            }
            {
                int pa = self->resource;
                x = EM_RES_REC(pa, 0xC68);
                y = EM_RES_REC(pa, 0xC6C);
            }
            goto lm0;
        lo0:
            {
                int pb = self->resource;
                x = EM_RES_REC(pb, 0x1A64);
                y = EM_RES_REC(pb, 0x1A68);
            }
        lm0:
            func_002A8578(self, x, y, 0.0f, 0, 0, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    self->unk568 = 0xF;
                    break;
                case 2:
                    self->unk568 = 0x14;
                    break;
                case 3:
                case 4:
                    self->unk568 = 0x19;
                    break;
                case 5:
                    self->unk568 = 0x1E;
                    break;
            }
            if (*(short *)(s1 + 0x54A) < 2) {
                self->unk568 = 0x3C;
            }
            *(short *)((char *)self + 0x56E) = 0xF;
            *(short *)((char *)self + 0x56A) = 0x1E;
            self->step++;
        }
            /* fallthrough */
        case 1:
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *q;
                int p0;

                (*(short *)((char *)self + 0x56E))--;
                p0 = (int)self->pos;

                q = s1 + 0x550;
                VU0_VADD_XYZ_IP(p0, 0, q);
            }
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                self->step = 2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (*(short *)((char *)self + 0x56A) > 0) {
                char *g;

                (*(short *)((char *)self + 0x56A))--;
                func_002DB770();
                g = D_007474A0;
                if ((*(int *)(g + 8) & 0xF0) != 0) {
                    self->unk568--;
                }
                if ((*(int *)(g + 8) & 0xF00000) != 0) {
                    self->unk568 -= 4;
                }
                if (self->unk568 <= 0) {
                    self->step = 4;
                    *(unsigned char *)(s1 + 0x2F6) = 4;
                }
            }
            break;
        case 2: {
            int p;
            int aa;
            int bb;
            int t = self->emNo;

            self->unk1864 = 0;
            if (t < 0x252) {
                if (t >= 0x250)
                    goto lo2;
            }
            {
                int pa = self->resource;
                x = EM_RES_REC(pa, 0xC70);
                y = EM_RES_REC(pa, 0xC74);
            }
            goto lm2;
        lo2:
            {
                int pb = self->resource;
                x = EM_RES_REC(pb, 0x1A6C);
                y = EM_RES_REC(pb, 0x1A70);
            }
        lm2:
            func_002A8578(self, x, y, 0.0f, 3, 0, 0);
            self->step++;
        }
            /* fallthrough */
        case 3:
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
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
        case 4: {
            int p;
            int aa;
            int bb;
            int t = self->emNo;

            self->unk1864 = 0;
            if (t < 0x252) {
                if (t >= 0x250)
                    goto lo4;
            }
            {
                int pa = self->resource;
                x = EM_RES_REC(pa, 0xC78);
                y = EM_RES_REC(pa, 0xC7C);
            }
            goto lm4;
        lo4:
            {
                int pb = self->resource;
                x = EM_RES_REC(pb, 0x1A74);
                y = EM_RES_REC(pb, 0x1A78);
            }
        lm4:
            func_002A8578(self, x, y, 0.0f, 3, 0, 0);
            self->unk568 = 0x1E;
            self->step++;
        }
            /* fallthrough */
        case 5:
            if (self->unk568 != 0) {
                self->unk568--;
                cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
                self->hitFlash = 3.0f;
            }
            if (moveMotion(self) != 0) {
                func_002705D8(self);
                break;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
}
