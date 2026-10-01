/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

extern char D_005FEE00[];
extern int cSnd_GetBgmData(void *snd, int bank);
extern void UpdateSequenceNode_373430(cSndBgmNode *node);
extern void ResetNodeData_3733C8(cSndBgmNode *node);
extern void func_002CC5E8(cSndBgmNode *node);

/* memset returns its pointer; declaring that keeps $v0 busy and puts the -1 in $v1 as retail does. */


/* Clears a BGM node and marks it as having no bank and no request.
   The store order is pre-rotated by one: the scheduler emits bank second. */
__attribute__((section(".text.cSndBgmNode_Init")))
void cSndBgmNode_Init(cSndBgmNode *node)
{
    func_003A52F0(node, 0, sizeof(cSndBgmNode));
    node->fadeTime = 0.0f;
    node->reqNo = -1;
    node->state = 0;
    node->saveWt = 0;
    node->prevWt = 0;
    node->bank = -1;
}

/* Clears a voice and marks both ids unused. */
__attribute__((section(".text.cSndSeVoice_Init")))
void cSndSeVoice_Init(cSndSeVoice *v)
{
    func_003A52F0(v, 0, sizeof(cSndSeVoice));
    v->idA = -1;
    v->idB = -1;
}

/* Starts a BGM request on a node, if the bank's data is valid and the request number is in range. */
__attribute__((section(".text.cSnd_BgmNodeStart")))
int cSnd_BgmNodeStart(cSndBgmNode *node, int bank, int reqNo, int state, unsigned int param, int wordA, int wordB)
{
    cSndBgmReq req;
    if (func_002CFF68((int *)cSnd_GetBgmData(D_005FEE00, bank)) == 0)
        return 0;
    if (reqNo >= 0x38)
        return 0;
    req.reqNo = reqNo;
    req.state = state;
    req.param = param;
    req.wordA = wordA;
    req.wordB = wordB;
    return func_002CC728(node, bank, &req, 0);
}

/* Tears down a used BGM node. */
__attribute__((section(".text.cSndBgmNode_Release")))
void cSndBgmNode_Release(cSndBgmNode *node)
{
    if (func_002CC568(node) != 0) {
        UpdateSequenceNode_373430(node);
        ResetNodeData_3733C8(node);
        func_002CC5E8(node);
    }
}
