#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void SetMotionStep(void *a0, float a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_0027DC50(void *a0, int a1);
extern char D_00462FC0[];

#include "godhand/vu0.h"

/* Phase machine on the step byte, 8 case labels. Calls Getplayer, SetMotionStep,
 * cCollisionSolidManage_SetActive, func_002A8578, func_0027DC50, VU0_VADD_XYZ_IP and 4 more. */
__attribute__((section(".text.func_0025DB70"))) void func_0025DB70(cEm00 *self)
{
    char *s1 = (char *)Getplayer();
    float v = *(float *)(s1 + 0x5A8);

    self->speedRate = v;
    SetMotionStep(self, v);
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    switch (self->step) {
        case 0: {
            int p;

            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x33EC), EM_RES_REC(p, 0x33F0), 0.0f, 0, 0, 0);
            if (*(void **)((char *)self + 0x740) != 0)
                func_0027DC50(*(void **)((char *)self + 0x740), 0);
            self->unk16EC = 0;
            *(short *)((char *)self + 0x56A) = 0;
            self->step++;
            goto tail13;
        }
        case 2:
            if (*(void **)((char *)self + 0x740) != 0)
                func_0027DC50(*(void **)((char *)self + 0x740), 1);
            self->step++;
            /* fallthrough */
        case 1:
        case 3:
        tail13:
            {
                char *q = s1 + 0x550;
                char *p = (char *)self->pos;

                self->hitFlash = 3.0f;
                VU0_VADD_XYZ_IP(p, 0, q);
            }
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            self->step = *(unsigned char *)(s1 + 0x2F6);
            break;
        case 4:
            if (*(void **)((char *)self + 0x740) != 0)
                func_0027DC50(*(void **)((char *)self + 0x740), 2);
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step++;
            /* fallthrough */
        case 5:
            self->hitFlash = 3.0f;
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *q;
                char *p;

                (*(short *)((char *)self + 0x56E))--;
                p = (char *)self->pos;
                q = s1 + 0x550;
                VU0_VADD_XYZ_IP(p, 0, q);
            }
            moveMotion(self);
            if (self->step != *(unsigned char *)(s1 + 0x2F6)) {
                if (self->vital > 0) {
                    self->step = 6;
                } else {
                    int k = 2;

                    self->vital = 0;
                    self->mode = k;
                    self->phase = k;
                    self->step = 0;
                    self->stepArg = 0;
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 6: {
            int p;

            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x3390), EM_RES_REC(p, 0x3394), 0.0f, 3, 0, 0);
            if (*(void **)((char *)self + 0x740) != 0)
                func_0027DC50(*(void **)((char *)self + 0x740), 3);
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step++;
        }
            /* fallthrough */
        case 7:
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *q;
                char *p;

                q = s1 + 0x550;
                (*(short *)((char *)self + 0x56E))--;
                p = (char *)self->pos;
                do {
                    VU0_VADD_XYZ_IP(p, 0, q);
                } while (0);
                self->hitFlash = 3.0f;
            }
            if (moveMotion(self) != 0)
                func_002705D8(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
}
