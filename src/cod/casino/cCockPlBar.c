/* TU: cCockPlBar [casino] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/DispMgr.h"

/* Run the bar's hook method (vtable entry DISPMGR_SUB_HOOK) on it. */
__attribute__((section(".text.cCockPlBar_initData")))
void cCockPlBar_initData(cCockPlBar *self) {
    DispMgrSubMethod *vt = self->head.vt;
    vt[DISPMGR_SUB_HOOK].pfn((char *)self + vt[DISPMGR_SUB_HOOK].delta);
}
