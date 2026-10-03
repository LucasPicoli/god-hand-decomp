/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_00271148(void *a0);

extern void func_002705D8(void *a0);
extern void func_00129718(void *a0, void *a1, int a2);
extern unsigned char D_00462FC0[];
#include "godhand/vu0.h"
#define FRAME ((char *)va)
/* Phase machine of the enemy that charges the player: it turns toward the player, derives a charge
 * vector from the player's matrix, slides along it until the timer runs out, then plays its end
 * motions. */
__attribute__((section(".text.cEm00_stepChargePlayer"))) void cEm00_stepChargePlayer(cEm00 *self)
{
    float va[4], vb[4], vc[4];
    int gb;
    int p;

    VU0_SQC2_VF0(FRAME, 0);
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x1034), EM_RES_REC(p, 0x1038), 5, 0.0f, gb, 0);
            self->step += 1;
            /* fallthrough */
        case 1:
            cGameObj_SetTgtTurn(self, *(void **)(Getplayer() + 0xF0),
                                self->speedRate * 0.19634955f);
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            float z = 0.0f;
            char *d;
            char *sv;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x103C), EM_RES_REC(p, 0x1040), 3, z, gb, 0);
            self->timer = 5.0f;
            va[2] = -0.6f;
            va[0] = z;
            va[1] = z;
            sceVu0ApplyMatrix(va, Getplayer() + 0x80, va);
            d = &self->unk580;
            if (d != (char *)va) {
                float t0 = va[0];
                float t1 = va[1];
                *(float *)(d + 0) = t0;
                *(float *)(d + 4) = t1;
                do {
                } while (0);
                *(float *)(d + 8) = va[2];
            }
            sv = (char *)vb;
            {
                char *b = (char *)self->pos;
                VU0_SQC2_VF0(FRAME, 0x20);
                VU0_LQC2(4, d, 0);
                VU0_LQC2(5, b, 0);
            }
            VU0_VSUB_XYZ(4, 4, 5);
            VU0_SQC2(4, FRAME, 0x20);
            CEM00_REGALLOC_NUDGE(self);
            VU0_LQC2(4, (char *)vc, 0);
            VU0_SQC2(4, FRAME, 0x10);
            {
                char *e = &self->unk590;
                if (e != sv) {
                    float t0 = vb[0];
                    float t1 = vb[1];
                    *(float *)(e + 0) = t0;
                    *(float *)(e + 4) = t1;
                    do {
                    } while (0);
                    *(float *)(e + 8) = vb[2];
                }
            }
            self->unk590.y = z;
            {
                float k = 1.0f / self->timer;
                VU0_LQC2(4, self, 0x590);
                VU0_LOAD_SCALAR(5, k);
            }
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, self, 0x590);
            cGameObj_SetTgtTurn(self, d, 3.14159274f);
            self->step += 1;
        }
            /* fallthrough */
        case 3:
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
            moveMotion(self);
            {
                float k = self->speedRate;
                float t;
                char *q;
                char *cp = (char *)vc;
                VU0_LQC2(4, &self->unk590, 0);
                VU0_SQC2(4, FRAME, 0x20);
                VU0_LQC2(4, FRAME, 0x20);
                VU0_LOAD_SCALAR(5, k);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, FRAME, 0x20);
                VU0_LQC2(4, cp, 0);
                VU0_SQC2(4, FRAME, 0x10);
                if ((char *)va != (char *)vb) {
                    float x = vb[0];
                    float y = vb[1];
                    float w = vb[2];
                    va[0] = x;
                    va[1] = y;
                    va[2] = w;
                }
                q = (char *)self->pos;
                VU0_VADD_XYZ_IP(q, 0, FRAME);
                t = self->timer - self->speedRate;
                self->timer = t;
                if (t <= 0.0f)
                    self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 4:
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x1044), EM_RES_REC(p, 0x1048), 3, 0.0f, gb, 0);
            self->step += 1;
            /* fallthrough */
        case 5:
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            func_00271148(self);
            break;
        case 6:
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            p = self->resource;
            func_002A8578(self, EM_RES_REC(p, 0x104C), EM_RES_REC(p, 0x1050), 3, 0.0f, gb, 0);
            self->step += 1;
            /* fallthrough */
        case 7:
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
            cGameObj_SetTgtTurn(self, *(void **)(Getplayer() + 0xF0),
                                self->speedRate * 0.19634955f);
            if (moveMotion(self) != 0) {
                if (func_00270DB0(self) != 0) {
                    char *r = Getplayer();
                    self->mode = 0;
                    self->step = 0;
                    self->stepArg = 0;
                    self->phase = 100;
                    func_00129718(r, self, 9);
                } else {
                    func_002705D8(self);
                }
                break;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            func_00271148(self);
            break;
    }
}
