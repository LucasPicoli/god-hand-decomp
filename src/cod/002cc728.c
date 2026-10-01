/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern int D_005FEE00;
extern int cSnd_GetBgmData(int a0, int a1);
extern void cSndBgmNode_StepState(void *a0);
extern void cSndBgmNode_Link(void *a0);

/* sn-2.95.3-136 matched TU. */









/* Fills a BGM node from a start request and links it into the active list. Returns 0 for an empty request. */
__attribute__((section(".text.cSndBgmNode_Setup")))
int cSndBgmNode_Setup(cSndBgmNode *node, int bank, cSndBgmReq *req, int flags)
{
    int state;

    node->bank = bank + 0x80;
    node->data = cSnd_GetBgmData((int)&D_005FEE00, bank);
    node->reqNo = req->reqNo;
    state = req->state;
    node->state = state;
    node->param = req->param;
    node->flags = flags;

    switch (state) {
    default:
        break;
    case 3:
        node->matchWt = req->wordA;
        node->link = (int *)cSnd_GetBgmLinkPtr(&D_005FEE00, req->wordB);
        break;
    case 2:
        node->entry = (int *)cSnd_GetBgmEntryPtr(&D_005FEE00, req->wordA);
        node->link = (int *)cSnd_GetBgmLinkPtr(&D_005FEE00, req->wordB);
        break;
    case 1:
    case 4:
    case 5:
        node->wordA = req->wordA;
        node->wordB = req->wordB;
        break;
    case 0:
        node->state = 0;
        return 0;
    }
    cSndBgmNode_StepState(node);
    cSndBgmNode_Link(node);
    return 1;
}
