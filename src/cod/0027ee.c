#include "godhand/vu0.h"
#include "godhand/globals.h"

extern int D_00448598;
extern void *func_0028EB00(void *self);

/* InitObjVtableAndTypeFull_27EE68: enemy constructor. Runs the cEm00 base constructor, sets the method
 * table and the kind name, clears five vectors of the derived tail. */
__attribute__((section(".text.InitObjVtableAndTypeFull_27EE68")))
void *InitObjVtableAndTypeFull_27EE68(char *self)
{
    func_0028EB00(self);
    *(int **)(self + 0x214) = &D_00448598;
    VU0_SQC2_VF0(self, 0x1530);
    VU0_SQC2_VF0(self, 0x1540);
    VU0_SQC2_VF0(self, 0x1550);
    VU0_SQC2_VF0(self, 0x1590);
    VU0_SQC2_VF0(self, 0x15A0);
    *(int **)(self + 0x4AC) = &D_004484B0;
    return self;
}
