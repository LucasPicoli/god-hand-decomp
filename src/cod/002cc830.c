/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern int D_005FEE00;

/* Like func_002CC728 for a node that already has its bank and state: stores flags and the request's values. */
__attribute__((section(".text.func_002CC830")))
int func_002CC830(cSndBgmNode *node, cSndBgmReq *req, int flags)
{
    int param;
    int state;

    param = req->param;
    state = node->state;
    node->flags = flags;
    node->param = param;

    switch (state) {
    default:
        break;
    case 3:
        node->matchWt = req->wordA;
        node->link = (int *)func_002D0578(&D_005FEE00, req->wordB);
        break;
    case 2:
        node->entry = (int *)func_002D0598(&D_005FEE00, req->wordA);
        node->link = (int *)func_002D0578(&D_005FEE00, req->wordB);
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
    return 1;
}
