/* TU: cMc - recovered C++ class. */
extern void *D_003C23A4;
extern void ObjTrans(void);
extern void func_002AF028(void *);
#include "include_asm.h"

INCLUDE_ASM("nonmatching", cMc_Move);

__attribute__((section(".text.cMc_Trans")))
void cMc_Trans(void) {
    ObjTrans();
    func_002AF028(D_003C23A4);
}
