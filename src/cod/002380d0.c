/* sn-2.95.3-136 matched TU. */

/* func_002380D0, 764 B, sn-2.95.3-136. Wave 2026-09-15 L5 near body + nested Duff do{}while(0) opened before the case 0 tail stores (a real insn between LOOP_BEG and the case 1 label keeps reorg from predicting the dispatch beq taken). */
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern char *Getplayer(void);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);
extern void func_002705D8(void *a0);
extern char D_00462FC0[];
extern char D_007474A0[];

/* Phase machine on the step byte, 9 case labels. Calls Getplayer, cCollisionSolidManage_SetActive,
 * func_002A8578, cCoreSave_getGameLevel, VU0_VADD_XYZ_IP, moveMotion and 4 more. */
__attribute__((section(".text.func_002380D0"))) void func_002380D0(cEm00 *self)
{
    char *s1 = Getplayer();
    char *p;
    char *q;
    int b;

    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    switch (self->step) {
        case 0:
            b = self->resource;
            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(b, 0x14A0), EM_RES_REC(b, 0x14A4), 0.0f, 0, 0, 0);
            *(short *)((char *)self + 0x56E) = 0xF;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
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
                self->unk568 = 0x19;
            }

            *(short *)((char *)self + 0x56A) = 0;
            self->step++;
            /* fallthrough */
        case 1:
            if (*(short *)((char *)self + 0x56E) == 0)
                goto join;
            (*(short *)((char *)self + 0x56E))--;
            p = (char *)self->pos;

            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        join:
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (*(short *)((char *)self + 0x56A) > 0) {
                (*(short *)((char *)self + 0x56A))--;
            } else {
                char *g;

                func_002DB770();
                g = D_007474A0;
                if (*(int *)(g + 8) & 0xF0)
                    self->unk568--;
                if (*(int *)(g + 8) & 0xF00000)
                    self->unk568 -= 4;
            }
            if (self->moveFlags & 0x10) {
                if (self->unk568 <= 0) {
                    *(unsigned char *)(s1 + 0x2F6) = 2;
                    self->step = 2;
                }
                *(short *)((char *)self + 0x56A) = 0x3E7;
            }
            break;
        case 2: {
            int p = self->resource;

            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC(p, 0x14A8), EM_RES_REC(p, 0x14AC), 0.0f, 0, 0, 0);
            *(short *)((char *)self + 0x56E) = 0xF;
            self->step++;
        }
        /* fallthrough */
        case 3:
            if (*(short *)((char *)self + 0x56E) != 0) {
                char *v = (char *)self->pos;
                char *w = s1 + 0x550;

                (*(short *)((char *)self + 0x56E))--;
                VU0_VADD_XYZ_IP(v, 0x0, w);
            }
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
