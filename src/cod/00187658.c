/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/PanelObj.h"

extern void func_001DEE60(PanelObj *self, int element, int show);

/* Show or hide the two arrow elements: mode 0 hides the first and shows the second, mode 1 shows both, any other mode leaves them. */
__attribute__((section(".text.PanelObj_setArrowMode")))
void PanelObj_setArrowMode(PanelObj *self, unsigned char mode)
{
    switch (mode) {
    case 0:
        func_001DEE60(self, PANEL_ELEM_UP, 0);
        func_001DEE60(self, PANEL_ELEM_DOWN, 1);
        break;
    case 1:
        func_001DEE60(self, PANEL_ELEM_UP, 1);
        func_001DEE60(self, PANEL_ELEM_DOWN, 1);
        break;
    }
}

/* sn-2.95.3-136 */



/* Start the knock step: aim the knock vector from the anchor body at the object, set mode 2 step 0, and flag the object active. */
__attribute__((section(".text.cOmBase_startKnockStepB")))
void cOmBase_startKnockStepB(cOmBase *self)
{
    cVec frame[2] __attribute__((aligned(16)));
    unsigned int f = self->flags0;
    long wide = f;
    long gone = (wide >> 1) & 1;
    if (gone) {
        return;
    }
    VU0_ZERO_VSUB_XYZ_MEM(frame, 0x10, self->pos, &self->posA);
    do { VU0_LQC2(4, &frame[1], 0); } while (0);
    VU0_SQC2(4, frame, 0);
    cVec_copy3(&self->knock, &frame[0]);
    self->mode = 2;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
    self->flags0 = self->flags0 | COMBASE_F0_ACTIVE;
}

/* sn-2.95.3-136 */



#define COMBASE_F0_BIT2   0x04          /* flags0 bit 2 */

/* Start the knock step: aim the knock vector from the anchor body at the object, set mode 2 step 0, and flag the object active. */
__attribute__((section(".text.func_00187658")))
void func_00187658(cOmBase *self)
{
    cVec frame[2] __attribute__((aligned(16)));
    unsigned int f = self->flags0;
    long wide = f;
    long gone = (wide >> 1) & 1;
    if (gone) {
        return;
    }
    VU0_ZERO_VSUB_XYZ_MEM(frame, 0x10, self->pos, &self->posA);
    do { VU0_LQC2(4, &frame[1], 0); } while (0);
    VU0_SQC2(4, frame, 0);
    cVec_copy3(&self->knock, &frame[0]);
    self->mode = 2;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
    self->flags0 = (self->flags0 | COMBASE_F0_ACTIVE) & ~COMBASE_F0_BIT2;
}

/* sn-2.95.3-136 */



#define COMBASE_F0_BIT2   0x04          /* flags0 bit 2 */

/* Start the knock step: aim the knock vector from the anchor body at the object, set mode 2 step 0, and flag the object active. */
__attribute__((section(".text.cOmBase_startKnockStepC")))
void cOmBase_startKnockStepC(cOmBase *self)
{
    cVec frame[2] __attribute__((aligned(16)));
    unsigned int f = self->flags0;
    long wide = f;
    long gone = (wide >> 1) & 1;
    if (gone) {
        return;
    }
    VU0_ZERO_VSUB_XYZ_MEM(frame, 0x10, self->pos, &self->posA);
    do { VU0_LQC2(4, &frame[1], 0); } while (0);
    VU0_SQC2(4, frame, 0);
    cVec_copy3(&self->knock, &frame[0]);
    self->mode = 2;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
    self->flags0 = (self->flags0 | COMBASE_F0_ACTIVE) & ~COMBASE_F0_BIT2;
}

/* sn-2.95.3-136 */



#define COMBASE_F0_BIT2   0x04          /* flags0 bit 2 */

/* Start the knock step: aim the knock vector from the anchor body at the object, set mode 2 step 0, and flag the object active. */
__attribute__((section(".text.cOmBase_startKnockStepD")))
void cOmBase_startKnockStepD(cOmBase *self)
{
    cVec frame[2] __attribute__((aligned(16)));
    unsigned int f = self->flags0;
    long wide = f;
    long gone = (wide >> 1) & 1;
    if (gone) {
        return;
    }
    VU0_ZERO_VSUB_XYZ_MEM(frame, 0x10, self->pos, &self->posA);
    do { VU0_LQC2(4, &frame[1], 0); } while (0);
    VU0_SQC2(4, frame, 0);
    cVec_copy3(&self->knock, &frame[0]);
    self->mode = 2;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
    self->flags0 = (self->flags0 | COMBASE_F0_ACTIVE) & ~COMBASE_F0_BIT2;
}

/* sn-2.95.3-136 */



#define COMBASE_F0_BIT2   0x04          /* flags0 bit 2 */

/* Start the knock step: aim the knock vector from the anchor body at the object, set mode 2 step 0, and flag the object active. */
__attribute__((section(".text.cOmBase_startKnockStepE")))
void cOmBase_startKnockStepE(cOmBase *self)
{
    cVec frame[2] __attribute__((aligned(16)));
    unsigned int f = self->flags0;
    long wide = f;
    long gone = (wide >> 1) & 1;
    if (gone) {
        return;
    }
    VU0_ZERO_VSUB_XYZ_MEM(frame, 0x10, self->pos, &self->posA);
    do { VU0_LQC2(4, &frame[1], 0); } while (0);
    VU0_SQC2(4, frame, 0);
    cVec_copy3(&self->knock, &frame[0]);
    self->mode = 2;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
    self->flags0 = (self->flags0 | COMBASE_F0_ACTIVE) & ~COMBASE_F0_BIT2;
}
