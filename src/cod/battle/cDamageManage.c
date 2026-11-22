/* TU: cDamageManage [battle] - recovered C++ class. */
#include "godhand/cDamageManage.h"

__attribute__((section(".text.cDamageManage_CreateDamageGive")))
cDamageGive *cDamageManage_CreateDamageGive(cDamageManage *self, int kind, struct cGameObj *owner) {
    cDamageGive *p = func_001FE1E0(self);
    if (p == 0) return 0;
    if (SetObjTargetAndActivate_1FD2C0(p, kind, owner) == 0) p = 0;
    return p;
}

__attribute__((section(".text.cDamageManage_ReleaseDamageGive")))
int cDamageManage_ReleaseDamageGive(cDamageManage *self, cDamageGive *give) {
    if (give == 0) {
        return 0;
    }
    cDvd_releaseAll(give);
    func_001FCDB8(give);
    return 1;
}
