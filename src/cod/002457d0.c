#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */







/* Phase machine on the step byte, 9 case labels. Calls func_002A8578, moveMotion,
 * cObjBase_addNullSpeed_Rotation, cObjBase_addNullSpeed, func_002705D8. */
__attribute__((section(".text.func_002457D0"))) void func_002457D0(cEm00 *self)
{
    self->objFlags |= 0x10000;
    switch (self->step) {
        case 0: {
            char *v0 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v0, 0x23D8), EM_RES_REC((int)v0, 0x23DC), 0.0f, 3,
                          0, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            self->hitFlash = 3.0f;
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            char *v0 = (char *)self->resource;
            int flags;
            func_002A8578(self, EM_RES_REC((int)v0, 0x23E0), EM_RES_REC((int)v0, 0x23E4), 0.0f, 0,
                          0, 0);
            *(unsigned char *)((char *)self + 0x17BE) =
                *(unsigned char *)((char *)self + 0x17BE) + 1;
            flags = self->emFlags2 & 0xFFFEFC7F;
            self->emFlags2 = flags;
            *(unsigned char *)((char *)self + 0x17BE) =
                (unsigned int)*(unsigned char *)((char *)self + 0x17BE) % 3;
            switch (*(unsigned char *)((char *)self + 0x17BE)) {
                case 0:
                    break;
                case 1:
                    self->emFlags2 = flags | 0x80;
                    if (self->emNo == 0x276) {
                        self->emFlags2 = flags | 0x280;
                    }
                    break;
                case 2:
                    self->emFlags2 = flags | 0x100;
                    if (self->emNo == 0x276) {
                        self->emFlags2 = flags | 0x300;
                    }
                    break;
            }
            *(unsigned char *)((char *)self + 0x1869) = 4;
            *(int *)((char *)self + 0x17A8) = 0;
            self->step += 1;
        }
            /* fallthrough */
        case 3:
            self->hitFlash = 2.0f;
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 4: {
            char *v0 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v0, 0x2388), EM_RES_REC((int)v0, 0x238C), 0.0f, 0,
                          0, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 5:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}
