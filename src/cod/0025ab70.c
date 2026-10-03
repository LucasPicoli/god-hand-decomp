/* sn-2.95.3-136 matched TU. */

/* cEm00_stepMotionThenTimedEnd: an enemy that starts a motion picked by its enemy number,
 * waits out a 150 frame timer and then ends the step. */
#include "godhand/cEm00.h"
#include "godhand/vu0.h"

extern void cCollisionSolidManage_SetPriority(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00274238(void *a0, int a1);
extern void func_002705D8(void *a0);
extern int D_00462FC0;

__attribute__((section(".text.cEm00_stepMotionThenTimedEnd")))
void cEm00_stepMotionThenTimedEnd(cEm00 *self)
{
    float f[8];

    self->emFlags2 |= 0x40;
    switch (self->step) {
    case 0: {
        int s2v;
        int s1v;
        int nb;

        switch (self->emNo) {
        case 0x214: case 0x215: case 0x21a: case 0x21b: case 0x21c:
        case 0x21d: case 0x21e: case 0x225: case 0x22c: case 0x22d:
        case 0x22e: case 0x22f: case 0x248: case 0x249: case 0x24c:
        case 0x24d: case 0x24e: case 0x252: case 0x25a:
            {
                int b = self->resource;
                s2v = EM_RES_REC(b, 0x1124);
                s1v = EM_RES_REC(b, 0x1128);
            }
            break;
        case 0x20a: case 0x20b: case 0x20c: case 0x20d: case 0x20e:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24f:
        case 0x250: case 0x251: case 0x278: case 0x279:
            {
                int b = self->resource;
                s2v = EM_RES_REC(b, 0x894);
                s1v = EM_RES_REC(b, 0x898);
            }
            break;
        case 0x260:
            {
                int b = self->resource;
                s2v = EM_RES_REC(b, 0x894);
                s1v = EM_RES_REC(b, 0x898);
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        case 0x241:
            {
                int b = self->resource;
                s2v = EM_RES_REC(b, 0x15cc);
                s1v = EM_RES_REC(b, 0x15d0);
            }
            break;
        case 0x209: case 0x21f:
            {
                int b = self->resource;
                s2v = EM_RES_REC(b, 0x15cc);
                s1v = EM_RES_REC(b, 0x15d0);
            }
            break;
        case 0x220: case 0x221: case 0x222:
            {
                int b = self->resource;
                s2v = EM_RES_REC(b, 0x1bc0);
                s1v = EM_RES_REC(b, 0x1bc4);
            }
            break;
        case 0x223:
            {
                int b = self->resource;
                s2v = EM_RES_REC(b, 0x2e34);
                s1v = EM_RES_REC(b, 0x2e38);
            }
            break;
        case 0x200: case 0x27e: default:
            {
                int b = self->resource;
                s2v = EM_RES_REC(b, 0x11c);
                s1v = EM_RES_REC(b, 0x120);
            }
            break;
        }
        cCollisionSolidManage_SetPriority(&D_00462FC0, self, 0);
        {
            cVec *p;
            cVec *q;
            float *d;
            float *src = f;

            p = self->pos;
            q = &self->unk6D0;
            VU0_SQC2_VF0(f, 0x10);
            CEM00_REGALLOC_NUDGE(self);
            VU0_LQC2(4, q, 0);
            VU0_LQC2(5, p, 0);
            VU0_VSUB_XYZ(4, 4, 5);
            VU0_SQC2(4, f, 0x10);
            VU0_LQC2(4, f + 4, 0);
            VU0_SQC2(4, f, 0);
            d = &self->unk580.x;
            if (d != src) {
                float t0, t1, t2;
                t0 = src[0];
                t1 = src[1];
                self->unk580.x = t0;
                *(volatile float *)&d[1] = t1;
                t2 = *(volatile float *)&src[2];
                d[2] = t2;
            }
        }
        self->rot.y = self->unk6E0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        func_002A8578(self, s2v, s1v, 0.0f, 3, nb, 0);
        self->timer = 150.0f;
        self->step += 1;
    }
        /* fallthrough */
    case 1: {
        float t;

        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        t = self->timer - self->speedRate;
        self->timer = t;
        if (t <= 0.0f) {
            cCollisionSolidManage_SetPriority(&D_00462FC0, self, 5);
            if (self->unk17BB != 0 && self->unk1740 <= 0.0f) {
                func_00274238(self, 0);
            } else {
                func_002705D8(self);
            }
        }
        break;
    }
    }
}
