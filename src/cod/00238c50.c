#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DCE8(char *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002705D8(void *a0);
extern char D_00462FC0[];

/* sn-2.95.3-136 matched TU. */













#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

/* Phase machine on the step byte, 9 case labels. Calls Getplayer, cCollisionSolidManage_SetActive,
 * func_002A8578, Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DCE8, VU0_VADD_XYZ_IP, moveMotion and 4 more.
 */
__attribute__((section(".text.func_00238C50"))) void func_00238C50(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    switch (self->step) {
        case 0: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x33CC), EM_RES_REC(p, 0x33D0), 0.0f, 0, 0, 0);
            if (*(void **)((char *)self + 0x740) != 0) {
                Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DCE8(*(char **)((char *)self + 0x740));
            }
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step++;
        }
            /* fallthrough */
        case 1:
            self->hitFlash = 3.0f;
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *q;
                int p0;

                (*(short *)((char *)self + 0x56E))--;
                q = s1 + 0x550;
                p0 = (int)self->pos;
                VU0_VADD_XYZ_IP(p0, 0, q);
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
        case 2: {
            int p;

            self->unk1864 = 0;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x33D4), EM_RES_REC(p, 0x33D8), 0.0f, 0, 0, 0);
            *(short *)((char *)self + 0x56E) = 0xF;
            self->hitFlash = 5.0f;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    *(float *)((char *)self + 0x16E4) = 180.0f;
                    break;
                case 2:
                    *(float *)((char *)self + 0x16E4) = 150.0f;
                    break;
                case 3:
                    *(float *)((char *)self + 0x16E4) = 120.0f;
                    break;
                case 4:
                    *(float *)((char *)self + 0x16E4) = 120.0f;
                    break;
                case 5:
                    *(float *)((char *)self + 0x16E4) = 90.0f;
                    break;
            }
            self->step++;
        }
            /* fallthrough */
        case 3:
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *q;
                int p0;

                (*(short *)((char *)self + 0x56E))--;
                q = s1 + 0x550;
                p0 = (int)self->pos;
                VU0_VADD_XYZ_IP(p0, 0, q);
            }
            if (moveMotion(self) != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) < 3) {
                    self->mode = 0;
                    self->phase = 0x6C;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    func_002705D8(self);
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
