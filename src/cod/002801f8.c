/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern void func_0028FB08(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int D_00462FC0;
extern char D_005FEE00[];
extern unsigned int irand(void);
extern int GetSeqSEBase(void *a0);

/* Phase machine on the step byte, 4 case labels. Calls cCollisionSolidManage_SetActive,
 * func_002A8578, moveMotion, cModel_calcNullPart, Add_nullspeed, func_0028FB08 and 2 more. */
__attribute__((section(".text.func_00288178"))) void func_00288178(cEm00 *self)
{
    int res;
    float z;

    self->gotoFlags = self->gotoFlags | 0x10020;
    self->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x180), EM_RES_REC(res, 0x184), 3, 0.0f, 0, 0);
            self->step++;
        case 1:
            moveMotion(self);
            cModel_calcNullPart(self);
            Add_nullspeed(self);
            if ((self->gotoFlags & 8) != 0) {
                self->vital = 0;
                self->step = 2;
            }
            break;
        case 2:
            z = 0.0f;
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x188), EM_RES_REC(res, 0x18C), 3, z, 0, 0);
            func_0028FB08(self);
            cCoreSave_addKillNpcNum(&D_00569B70);
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x90), EM_RES_REC(res, 0x94), 5, z, 0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5F, self, 0, 0, 0, 0);
            self->step++;
        case 3:
            if (moveMotion(self) != 0) {
                self->step = 0;
                self->mode = 2;
                self->phase = 2;
                self->stepArg = 0;
            }
            cModel_calcNullPart(self);
            Add_nullspeed(self);
            break;
    }
}

/* Phase machine on the step byte, 7 case labels. Calls func_0026F1D8, irand, func_002A8578,
 * cSnd_SeCall_2CBA48, GetSeqSEBase, moveMotion. */
__attribute__((section(".text.func_002801F8"))) void func_002801F8(cEm00 *self)
{
    int s2 = (int)self->target;
    int res;

    switch (self->step) {
        case 0:
            if (func_0026F1D8(s2) != 0) {
                switch (irand() & 1) {
                    default:
                    case 0:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0x118), EM_RES_REC(res, 0x11C), 2, 0.0f,
                                      0, 0);
                        break;
                    case 1:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0x118), EM_RES_REC(res, 0x11C), 2, 0.0f,
                                      0, 0);
                        break;
                }
            } else {
                switch (irand() % 3) {
                    default:
                    case 0:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0xE8), EM_RES_REC(res, 0xEC), 2, 0.0f,
                                      0, 0);
                        break;
                    case 1:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0xE8), EM_RES_REC(res, 0xF4), 2, 0.0f,
                                      0, 0);
                        break;
                    case 2:
                        res = self->resource;
                        func_002A8578(self, EM_RES_REC(res, 0xE8), EM_RES_REC(res, 0xFC), 2, 0.0f,
                                      0, 0);
                        break;
                }
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            self->step++;
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
