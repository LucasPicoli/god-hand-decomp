#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int GetSeqSEBase(void *a0);
extern int D_005FEE00[];
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int irand(void);
extern void cModel_calcNullPart(void *a0);
extern char D_00462FC0[];
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern void Add_nullspeed(void *a0);

/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, cSnd_SeCall_2CBA48,
 * GetSeqSEBase, moveMotion. */
__attribute__((section(".text.func_002803F0"))) void func_002803F0(cEm00 *self)
{
    int res;
    unsigned long t0 = 0;
    switch (self->step) {
        case 0:
            if (self->stepArg) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x100), EM_RES_REC(res, 0x104), 0.0f, 2, t0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x100), EM_RES_REC(res, 0x104), 0.0f, 2, t0, 0);
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}

/* Phase machine on the step byte, 2 case labels. Calls cCollisionSolidManage_SetActive, irand,
 * func_002A8578, cSnd_SeCall_2CBA48, moveMotion, cModel_calcNullPart. */
__attribute__((section(".text.func_002887D0"))) void func_002887D0(cEm00 *self)
{
    int res;
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    self->gotoFlags = self->gotoFlags | 2;
    switch (self->step) {
        case 0:
            if (irand() & 1) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0xA8), EM_RES_REC(res, 0xAC), 0.0f, 10, 0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0xB0), EM_RES_REC(res, 0xB4), 0.0f, 10, 0, 0);
            }
            if (self->stepArg == 0)
                cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5C, self, 0, 0, 0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                if (self->gotoFlags & 0x80) {
                    self->phase = 7;
                    self->step = 0x12;
                    self->mode = 0;
                    self->stepArg = 0;
                    break;
                }
                self->mode = 0;
                self->phase = 2;
                self->step = 0;
                self->stepArg = 0;
            }
            cModel_calcNullPart(self);
            break;
    }
}

/* Phase machine on the step byte, 2 case labels. Calls irand, cSnd_SeCall_2CBA48, func_002A8578,
 * cGameObj_SetTgtTurn, moveMotion, cModel_calcNullPart and 1 more. */
__attribute__((section(".text.func_00288660"))) void func_00288660(cEm00 *self)
{
    int v0;
    switch (self->step) {
        case 0: {
            int s2, s1;
            if (irand() & 1) {
                int b = self->resource;
                s2 = EM_RES_REC(b, 0x50);
                s1 = EM_RES_REC(b, 0x54);
            } else {
                int b = self->resource;
                s2 = EM_RES_REC(b, 0x58);
                s1 = EM_RES_REC(b, 0x5C);
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5C, self, 0, 0, 0, 0);
            func_002A8578(self, s2, s1, 0.0f, 5, 0, 0);
            self->timerA = 10;
            self->step = self->step + 1;
        }
        case 1: {
            int t = self->timerA;
            if (t != 0) {
                int q = *(int *)((char *)self + 0x670);
                self->timerA = t - 1;
                v0 = *(int *)(q + 0x34);
                if (v0 != 0)
                    cGameObj_SetTgtTurn(self, *(int *)(v0 + 0xF0), self->speedRate * 0.39269909f);
            }
            if (moveMotion(self) != 0) {
                if (self->gotoFlags & 0x80) {
                    self->phase = 7;
                    self->step = 0x10;
                    self->mode = 0;
                    self->stepArg = 0;
                    break;
                }
                self->mode = 0;
                self->phase = 4;
                self->step = 0;
                self->stepArg = 0;
            }
            cModel_calcNullPart(self);
            Add_nullspeed(self);
            break;
        }
    }
}

/* Phase machine on the step byte, 7 case labels. Calls func_0026F1D8, irand, func_002A8578,
 * cSnd_SeCall_2CBA48, GetSeqSEBase, moveMotion. */
__attribute__((section(".text.func_00280000"))) void func_00280000(cEm00 *self)
{
    int res;
    void *s2 = (void *)self->target;
    switch (self->step) {
        case 0:
            if (func_0026F1D8(s2) != 0) {
                switch (irand() & 1) {
                    case 0:
                    default:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0x110), EM_RES_REC(res, 0x114), 0.0f, 2,
                                      0, 0);
                        break;
                    case 1:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0x110), EM_RES_REC(res, 0x114), 0.0f, 2,
                                      0, 0);
                        break;
                }
            } else {
                switch ((unsigned)irand() % 3) {
                    case 0:
                    default:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0xD0), EM_RES_REC(res, 0xD4), 0.0f, 2,
                                      0, 0);
                        break;
                    case 1:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0xD8), EM_RES_REC(res, 0xDC), 0.0f, 2,
                                      0, 0);
                        break;
                    case 2:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0xE0), EM_RES_REC(res, 0xE4), 0.0f, 2,
                                      0, 0);
                        break;
                }
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                if (func_0026F1D8(s2) != 0) {
                    self->phase = 0x10;
                    self->step = 2;
                    self->mode = 0;
                    self->stepArg = 0;
                } else {
                    self->mode = 0;
                    self->phase = 0;
                    self->step = 0;
                    self->stepArg = 0;
                }
            }
            break;
    }
}
