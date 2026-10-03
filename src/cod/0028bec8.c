#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int D_00747A78;
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern void cObjBase_SetSeqEffect(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void func_0028CEA8(void *a0);
extern void func_0028D7E8(void *a0);
extern void func_0028CB90(void *a0);

/* Phase machine on the step byte, 44 case labels. Calls func_002A8578, moveMotion,
 * cModel_calcNullPart, Add_nullspeed, cObjBase_SetSeqEffect, cModel_calcParts and 5 more. */
__attribute__((section(".text.func_0028BEC8"))) void func_0028BEC8(cEm00 *self)
{
    if ((D_00747A78 & 0x40000000) != 0)
        return;
    switch (self->step) {
        case 0: {
            float f;
            switch (self->entryNo % 15) {
                default:
                case 0:
                    f = 14.0f;
                    break;
                case 1:
                    f = 13.0f;
                    break;
                case 2:
                    f = 12.0f;
                    break;
                case 3:
                    f = 11.0f;
                    break;
                case 4:
                    f = 10.0f;
                    break;
                case 5:
                    f = 9.0f;
                    break;
                case 6:
                    f = 8.0f;
                    break;
                case 7:
                    f = 7.0f;
                    break;
                case 8:
                    f = 6.0f;
                    break;
                case 9:
                    f = 5.0f;
                    break;
                case 10:
                    f = 4.0f;
                    break;
                case 11:
                    f = 3.0f;
                    break;
                case 12:
                    f = 2.0f;
                    break;
                case 13:
                    f = 1.0f;
                    break;
                case 14:
                    f = 0.0f;
                    break;
            }
            switch (*(unsigned char *)((char *)self + 0x1540)) {
                default:
                case 0: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0x80), 0, f, 0, 0, 0);
                } break;
                case 1: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0x84), 0, f, 0, 0, 0);
                } break;
                case 2: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0x88), 0, f, 0, 0, 0);
                } break;
                case 3: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0x8C), 0, f, 0, 0, 0);
                } break;
                case 4: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0x90), 0, f, 0, 0, 0);
                } break;
                case 5: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0x94), 0, f, 0, 0, 0);
                } break;
                case 6: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0x98), 0, f, 0, 0, 0);
                } break;
                case 7: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0x9C), 0, f, 0, 0, 0);
                } break;
                case 8: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xA0), 0, f, 0, 0, 0);
                } break;
                case 9: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xA4), 0, f, 0, 0, 0);
                } break;
                case 10: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xA8), 0, f, 0, 0, 0);
                } break;
                case 11: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xAC), 0, f, 0, 0, 0);
                } break;
                case 12: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xB0), 0, f, 0, 0, 0);
                } break;
                case 13: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xB4), 0, f, 0, 0, 0);
                } break;
                case 14: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xB8), 0, f, 0, 0, 0);
                } break;
                case 15: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xBC), 0, f, 0, 0, 0);
                } break;
                case 16: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xC0), 0, f, 0, 0, 0);
                } break;
                case 17: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xC4), 0, f, 0, 0, 0);
                } break;
                case 18: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xC8), 0, f, 0, 0, 0);
                } break;
                case 19: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xCC), 0, f, 0, 0, 0);
                } break;
                case 20: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xD0), 0, f, 0, 0, 0);
                } break;
                case 21: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xD4), 0, f, 0, 0, 0);
                } break;
                case 22: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xD8), 0, f, 0, 0, 0);
                } break;
                case 23: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xDC), 0, f, 0, 0, 0);
                } break;
                case 24: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xE0), 0, f, 0, 0, 0);
                } break;
                case 25: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xE4), 0, f, 0, 0, 0);
                } break;
                case 26: {
                    int w = self->resource;
                    func_002A8578(self, EM_RES_REC(w, 0xE8), 0, f, 0, 0, 0);
                } break;
            }
            self->step++;
        }
        /* fallthrough */
        case 1:
            moveMotion(self);
            cModel_calcNullPart(self);
            Add_nullspeed(self);
            break;
        default:
            break;
    }
    cObjBase_SetSeqEffect(self);
    cModel_calcParts(self);
    IK_InverseKinematics(((char *)self + 0x448), self);
    cModel_calcWorldParts(self);
    func_0028CEA8(self);
    func_0028D7E8(self);
    func_0028CB90(self);
    {
        char *d = &self->posA;
        char *p = (char *)self->pos;
        if (d != p) {
            *(float *)(d + 0) = *(float *)(p + 0);
            *(float *)(d + 4) = *(float *)(p + 4);
            *(float *)(d + 8) = *(float *)(p + 8);
        }
    }
}
