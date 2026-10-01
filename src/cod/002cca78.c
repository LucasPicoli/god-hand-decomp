/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

extern int GetSequenceResult_373770(cSndBgmNode *node);
extern void func_003735E0(cSndBgmNode *node, float to, float time, int a2);
extern void UpdateStateAndClearFlag_3734F0(cSndBgmNode *node);

/* A node counts as done when it is unused, flagged active, or its sequence result is past 2.
   The 2 lives in a local: a literal folds the compare into slti/xori, retail keeps slt against a register. */
__attribute__((section(".text.cSndBgmNode_IsDone")))
int cSndBgmNode_IsDone(cSndBgmNode *node)
{
    int two = 2;
    if (func_002CC568(node) == 0 || (node->flags & 1))
        return 1;
    return two < GetSequenceResult_373770(node);
}

/* Fades a node up to full volume over the given time, unless its flags say it is held (0x100). */
__attribute__((section(".text.cSndBgmNode_FadeIn")))
void cSndBgmNode_FadeIn(cSndBgmNode *node, float time)
{
    if ((node->flags & 0x100) == 0)
        func_003735E0(node, 1.0f, time, -1);
}

/* Fades a node down to silence. A node with flag 4 uses its own stored volume as the time. */
__attribute__((section(".text.cSndBgmNode_FadeOut")))
void cSndBgmNode_FadeOut(cSndBgmNode *node, float time)
{
    if (node->flags & 4)
        time = node->volume;
    func_003735E0(node, 0.0f, time, -1);
}

/* Stores a fade time, sets and clears node flags, resets the node state if the sequence reports 1, then fades in. */
__attribute__((section(".text.cSndBgmNode_SetFlagsFade")))
void cSndBgmNode_SetFlagsFade(cSndBgmNode *node, float time, unsigned int setBits, unsigned int clearBits)
{
    node->fadeTime = time;
    node->flags = (node->flags | setBits) & ~clearBits;
    if (func_00373A58(node) == 1)
        UpdateStateAndClearFlag_3734F0(node);
    func_003735E0(node, 1.0f, time, -1);
}
