/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

extern void ClearFlagBits_373858(cSndBgmNode *node, int bits);
extern int IsSequenceFlagSet_3737C8(cSndBgmNode *node, int bits);
extern int GetSequenceResult_373770(cSndBgmNode *node);
extern void func_002CC5E8(cSndBgmNode *node);
extern void UpdateSequenceNode_373430(cSndBgmNode *node);
extern void ResetNodeData_3733C8(cSndBgmNode *node);
extern int cBgmData_GetHeadPtr(int data);
extern int SetSequenceEntry_373158(cSndBgmNode *node, int reqNo);
extern int UpdateSequenceEntry_373298(cSndBgmNode *node, int reqNo);
extern void UpdateSequenceNodeWeighted_373560(cSndBgmNode *node, int a1, float w);
extern void func_002CD470(cSndBgmNode *node, float time);
extern void func_0030A538(float *pos, int mtx);

/* Moves a fresh node from state 0 to 1, then releases it once its sequence has finished. */
__attribute__((section(".text.func_002CD310")))
void func_002CD310(cSndBgmNode *node)
{
    if (node->state2 == 0) {
        if (func_002CD398(node) == 0)
            return;
        if (node->wordA == 0)
            ClearFlagBits_373858(node, 8);
        node->state2 = 1;
    }
    if (IsSequenceFlagSet_3737C8(node, 8) != 0)
        return;
    if (GetSequenceResult_373770(node) != 0)
        return;
    func_002CC5E8(node);
}

/* Starts a node's sequence from its bank and request. Returns 1 once it is running, 0 if it cannot start.
   Every failure after the first test jumps to one shared return 0, as retail lays it out. */
__attribute__((section(".text.func_002CD398")))
int func_002CD398(cSndBgmNode *node)
{
    int ok;
    float zero;
    if (node->flags & 0x100)
        return 0;
    if (func_00373A50(node) == 1) {
        UpdateSequenceNode_373430(node);
        ResetNodeData_3733C8(node);
    }
    if (func_00373118(node, node->bank, cBgmData_GetHeadPtr(node->data), 0) == 0) {
ng:
        return 0;
    }
    if (node->flags & 1)
        ok = SetSequenceEntry_373158(node, node->reqNo);
    else
        ok = UpdateSequenceEntry_373298(node, node->reqNo);
    if (ok == 0)
        goto ng;
    zero = 0.0f;
    UpdateSequenceNodeWeighted_373560(node, -1, zero);
    func_002CD470(node, zero);
    node->wait = 0;
    return 1;
}

/* The object and part classes are not typed yet; +0xF0 holds their matrix. */
#define OBJ_MTX_OFFSET 0xF0




/* Binds a free voice to an object or part, places it at that object's position, then starts it. */
__attribute__((section(".text.func_002CDD18")))
int func_002CDD18(cSndSeVoice *v, short key0, short key1, char *obj, char *part, int a5, int a6)
{
    if (func_002CDA38(v) == 1)
        return 0;
    v->obj = obj;
    v->part = part;
    if (obj == 0) {
        v->kind = 0;
        v->scale = 1.0f;
        v->pos[0] = 0;
        v->pos[1] = 0;
        v->pos[2] = 0;
    } else {
        v->kind = 2;
        if (part == 0)
            func_0030A538(v->pos, *(int *)(obj + OBJ_MTX_OFFSET));
        else
            func_0030A538(v->pos, *(int *)(part + OBJ_MTX_OFFSET));
        v->pos[1] += 1.3f;
    }
    return func_002CDFF0(v, key0, key1, a5, a6);
}

/* Binds a free voice to a fixed matrix (0 = the global origin), places it there, then starts it. */
__attribute__((section(".text.func_002CDE28")))
int func_002CDE28(cSndSeVoice *v, short key0, short key1, int mtx, int a5, int a6)
{
    if (func_002CDA38(v) == 1)
        return 0;
    v->obj = 0;
    v->part = 0;
    if (mtx == 0) {
        v->kind = 0;
        v->scale = 1.0f;
        v->pos[0] = 0;
        v->pos[1] = 0;
        v->pos[2] = 0;
    } else {
        v->kind = 2;
        func_0030A538(v->pos, mtx);
        v->pos[1] += 1.3f;
    }
    return func_002CDFF0(v, key0, key1, a5, a6);
}
