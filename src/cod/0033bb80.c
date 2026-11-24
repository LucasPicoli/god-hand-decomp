/* cygnus-2.96 matched TU. */

#include "godhand/criCbTbl.h"
extern void Forward33B568_33B658(void);
extern void Forward33B5C8_33B670(void);

__attribute__((section(".text.SVM_SetCbBdr")))
void SVM_SetCbBdr(int i, void (*fn)(int), int arg)
{
    Forward33B568_33B658();
    D_00758860[i].fn = fn;
    D_00758860[i].arg = arg;
    Forward33B5C8_33B670();
}
