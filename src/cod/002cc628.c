/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern void SetSequenceBlendWeight_3739A0(void *a0, int a1, float f);
extern void cSndBgmNode_Fade(void *a0);
extern void func_002CCD80(void *a0);
extern void cSndBgmNode_Run(void *a0);
extern void cSndBgmNode_Update(void *a0);
extern void func_00372CB0(void *a0);

/* sn-2.95.3-136 matched TU. */












extern cSnd D_005FEE00;
/* Runs one update of a used BGM node: blends its channels, steps its state machine, then clears its update flag. */
__attribute__((section(".text.func_002CC628")))
void func_002CC628(cSndBgmNode *node) {
    int i;
    if (func_002CC568(node) != 0) {
        if (func_00373A50(node) == 1) {
            for (i = 0; i < func_00373B30(node); i++)
                SetSequenceBlendWeight_3739A0(node, 0, D_005FEE00.f6C);
        }
        switch (node->state) {
        case 3:
            cSndBgmNode_Fade(node);
            break;
        case 2:
            func_002CCD80(node);
            break;
        case 1:
        case 5:
            cSndBgmNode_Run(node);
            break;
        case 4:
            cSndBgmNode_Update(node);
            break;
        case 0:
        default:
            break;
        }
        node->flags = node->flags & 0xFFFFFFFB;
        func_00372CB0(node);
    }
}
