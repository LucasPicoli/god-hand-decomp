/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern void func_002CFF90(cBgmData *);
extern void func_002CD4E0(cSndBgmNode *, float, float);
extern float GetSequenceBlendWeight_373938(cSndBgmNode *, int);
extern void UpdateSequenceNodeWeighted_373560(cSndBgmNode *, int, float);
extern void func_002CD4A8(cSndBgmNode *, float);

__attribute__((section(".text.func_002CF218")))
int func_002CF218(void *self, short a, short b, int c)
{
    if (func_00374CB8(a, b, c) == -1)
        return -1;
    return 0;
}

/* Fade the nodes of one bgm request (or all when reqNo is -1). */
__attribute__((section(".text.cSnd_BgmEvFadeSet")))
void cSnd_BgmEvFadeSet(cSnd *self, int bgmPt, int reqNo, float time, float level, float weight)
{
    cSndBgmNode *node;
    for (node = self->bgmHead; node != 0; node = node->next) {
        if (reqNo == -1 || ((node->bank - 0x80) == bgmPt && node->reqNo == reqNo)) {
            if (0.0f <= weight) {
                float w = GetSequenceBlendWeight_373938(node, 0);
                UpdateSequenceNodeWeighted_373560(node, -1, w * weight);
            }
            func_002CD4E0(node, time, level);
        }
    }
}

/* Fade out every node of bgm part bgmPt except those of request keepReq. */
__attribute__((section(".text.cSnd_BgmFadeOutAll")))
void cSnd_BgmFadeOutAll(cSnd *self, int bgmPt, int keepReq, float time)
{
    cSndBgmNode *node;
    for (node = self->bgmHead; node != 0; node = node->next) {
        if ((node->bank - 0x80) == bgmPt && node->reqNo != keepReq) {
            if (func_00373A58(node) == 1)
                func_002CD4A8(node, 3.0f);
            else
                func_002CD4A8(node, time);
        }
    }
}

__attribute__((section(".text.func_002D1DD0")))
int func_002D1DD0(cSnd *self, int bgmPt, int reqNo)
{
    int node = func_002D22B0(self, bgmPt, reqNo);
    if (node != 0 && func_002CCA78(node) == 0)
        return 0;
    return 1;
}
