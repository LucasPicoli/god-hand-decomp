/* cygnus-2.96 matched TU. */

#include "godhand/criCbTbl.h"

__attribute__((section(".text.SVM_GotoSvrBorder")))
void SVM_GotoSvrBorder(int i)
{
    void (*fn)(int);
    fn = D_00758860[i].fn;
    if (fn != 0) fn(D_00758860[i].arg);
}
