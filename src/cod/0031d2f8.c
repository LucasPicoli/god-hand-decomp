/* sn-2.95.3-136: add a queued stage mesh pair to a model (0x31D2F8). */

#include "godhand/stageSet.h"

__attribute__((section(".text.func_0031D2F8")))
void func_0031D2F8(char *model, int idx)
{
    BoundingBox box;
    char *state;
    int a;
    int b;

    a = D_007558A8[idx].a;
    b = D_007558A8[idx].b;
    if (a == 0) {
        return;
    }
    if (b == 0) {
        return;
    }
    state = GetActiveState_149310();
    cBoundingBox(&box);
    func_00148420(state, a, b, 0x1001000, 1, &box, 0);
    func_001485A0(state, a, b, 0x1001000, 1, &box, *(int *)(model + 0x288));
    cModel_addMesh(model, state, &box);
    cBoundingBox__dtor(&box, 2);
}
