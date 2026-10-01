/* sn-2.95.3-136 matched TU. */

#include "godhand/JukeBox.h"
#include "godhand/cSnd.h"

extern int D_003C2388;
extern int *D_003C2384;
extern char D_0042C000[];
extern char D_00583F20[];
extern char D_00754220[];
extern char D_007474A0[];
extern int D_00747A24[];
extern void cIDManager_getLocalFileName(int a0, void *a1, void *a2, int a3);
extern int cDvd_ReadAlloc(void *a0, void *a1, void *a2, void *a3, int t0, int t1, int t2, int t3);
extern void cDvd_CheckWait(void *a0, int a1);
extern void cIDManager_setIDData(int a0, int a1, int a2);
extern int cIDBase_initialize(void *id, int no, int flag);
extern int cIDBase_setPackedMessData(void *id, int no, int flag);
extern void func_001F6A80(JukeBoxObj *self);
extern cSnd D_005FEE00;
extern void SetSequenceFlags_373810(cSndBgmNode *node, int bits);
extern void ClearFlagBits_373858(cSndBgmNode *node, int bits);
extern void cSndBgmNode_FadeOut(cSndBgmNode *node, float time);
extern void UpdateSequenceNodeSetFlag_373488(cSndBgmNode *node);
extern int GetSequenceResult_373770(cSndBgmNode *node);
extern void cSndBgmNode_Unlink(cSndBgmNode *node);
extern void cSndBgmNode_FadeIn(cSndBgmNode *node, float time);

/* sn-2.95.3-136 */

















__attribute__((section(".text.JukeBox_Load")))
int JukeBox_Load(JukeBoxObj *self)
{
    char name[0x40];
    char *id;
    int h;
    char *game;  /* retail keeps the full address of D_007474A0 in one register */

    cIDManager_getLocalFileName(D_003C2388, name, D_0042C000, -1);
    id = self->idBase;
    h = cDvd_ReadAlloc(D_00583F20, name, &self->dataFile, D_00754220, 0, 0, 0, 0);
    cDvd_CheckWait(D_00583F20, h);
    cIDManager_setIDData(*D_003C2384, JUKEBOX_ID_NO, self->dataFile);
    if (cIDBase_initialize(id, JUKEBOX_ID_NO, 0) == 0
        || cIDBase_setPackedMessData(id, JUKEBOX_ID_NO, 1) == 0) {
        return 0;
    }
    game = D_007474A0;
    *(int *)(game + 0x10) = 1;
    self->bgmEvent = JUKEBOX_BGM_NONE;
    self->unk08 = 10;
    self->done = 0;
    self->unk0C = 1;
    self->unk20 = 0;
    self->unk05 = 0;
    if ((*(unsigned int *)(game + 0x588) & 0x8000000) != 0) {
        self->unk10 = 1;
    } else {
        self->unk10 = 0;
    }
    if ((D_00747A24[1] & 0x4000000) != 0) {
        self->unk14 = 1;
    } else {
        self->unk14 = 0;
    }
    if ((D_00747A24[1] & 0x2000000) != 0) {
        self->unk18 = 1;
    } else {
        self->unk18 = 0;
    }
    if ((D_00747A24[1] & 0x1000000) != 0) {
        self->unk1C = 1;
    } else {
        self->unk1C = 0;
    }
    func_001F6A80(self);
    self->unk00 = 0;
    self->unk01 = 0;
    self->unk02 = 0;
    self->unk03 = 0;
    return 1;
}

/* Runs one BGM node through its states: 0 start, 1 wait for the signal, 2 fade and wind down. */
__attribute__((section(".text.cSndBgmNode_Run")))
void cSndBgmNode_Run(cSndBgmNode *node)
{
    switch (node->state2) {
    case 0:
        if (cSndBgmNode_Start(node) == 0)
            return;
        if (node->wordA & 1) {
            SetSequenceFlags_373810(node, 8);
            node->wait = node->wordB;
        }
        node->state2 = 1;
        /* fall through */
    case 1:
        if ((cSnd_GetBgmAttr(&D_005FEE00) & node->param) == 0) {
            ClearFlagBits_373858(node, 8);
            cSndBgmNode_FadeOut(node, 0.0f);
            node->state2 = 2;
        }
        if ((node->flags & 0x180000) == 0)
            break;
        if (func_00373A58(node) != 0)
            break;
        node->fadeTime = node->fadeTime - 1.0f;
        if (node->fadeTime < 0.0f) {
            node->fadeTime = 0.0f;
            UpdateSequenceNodeSetFlag_373488(node);
        }
        break;
    case 2:
        break;
    default:
        return;
    }
    if (GetSequenceResult_373770(node) != 0)
        return;
    cSndBgmNode_Unlink(node);
}

/* Runs one BGM node's fade state machine: 0 idle, 1 playing, 2 fading out for a restart. */
__attribute__((section(".text.cSndBgmNode_Fade")))
void cSndBgmNode_Fade(cSndBgmNode *node)
{
    func_002CCB58(node);
    switch (node->state2) {
    case 0:
        if (node->saveWt != node->matchWt)
            return;
        if ((cSnd_GetBgmAttr(&D_005FEE00) & node->param) == 0)
            return;
        if (node->flags & 0x1FF00)
            return;
        if (cSndBgmNode_Start(node) == 0)
            return;
        SetSequenceFlags_373810(node, 8);
        node->state2 = 1;
        /* fall through */
    case 1:
        if (node->saveWt == node->matchWt) {
            if (cSnd_GetBgmAttr(&D_005FEE00) & node->param)
                return;
        }
        cSndBgmNode_FadeOut(node, 0.0f);
        node->wait = 0x3C;
        node->state2 = 2;
        return;
    case 2:
        if (func_00373A58(node) == 1) {
            if (node->wait == 0) {
                ClearFlagBits_373858(node, 8);
                node->state2 = 0;
            } else {
                node->wait--;
            }
        }
        if ((cSnd_GetBgmAttr(&D_005FEE00) & node->param) == 0)
            return;
        if (node->saveWt != node->matchWt)
            return;
        cSndBgmNode_FadeIn(node, 60.0f);
        node->wait = 0;
        node->state2 = 1;
        return;
    }
}
