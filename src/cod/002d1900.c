/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern void cBgmData_Reset(cBgmData *);
extern void cSnd_BgmEvFadeSet(cSnd *, int, int, float, float, float);

/* Fade a bgm request over 15 with the default weight. */
__attribute__((section(".text.cSnd_BgmEvFadeDefault")))
void cSnd_BgmEvFadeDefault(cSnd *self, int bgmPt, int reqNo)
{
    cSnd_BgmEvFadeSet(self, bgmPt, reqNo, 0.0f, 15.0f, -1.0f);
}

/* Reset bgm data slot 1 and prime it with the given value. */
__attribute__((section(".text.cSnd_BgmEvDataInit")))
void cSnd_BgmEvDataInit(cSnd *self, int arg)
{
    cBgmData_Reset(cSnd_GetBgmData(self, 1));
    cBgmData_LoadNumbered(cSnd_GetBgmData(self, 1), 1, arg);
}

/* Is bgm data slot 1 free or loaded? */
__attribute__((section(".text.cSnd_BgmEvDataCheck")))
int cSnd_BgmEvDataCheck(cSnd *self)
{
    if (cBgmData_IsEmpty(cSnd_GetBgmData(self, 1)) == 1)
        return 1;
    return cBgmData_IsReady(cSnd_GetBgmData(self, 1));
}

/* 1 when every table entry cut as reqNo is ready, 0 at the first that is not. */
__attribute__((section(".text.cSnd_BgmEvCutCheck")))
int cSnd_BgmEvCutCheck(cSnd *self, int reqNo)
{
    cBgmHead *head;
    unsigned int i;

    if (!cBgmData_IsReady(cSnd_GetBgmData(self, 1)))
        return 1;
    head = cBgmData_GetHeadPtr(cSnd_GetBgmData(self, 1));
    for (i = 0; i < head->tblNum; i++) {
        cBgmTbl *tbl = cBgmData_GetTblPtr(cSnd_GetBgmData(self, 1), i);
        if (tbl != 0 && tbl->type != 0x80 && tbl->reqNo == reqNo) {
            if (cSnd_BgmEvIsReady(self, 1, i) != 1)
                return 0;
        }
    }
    return 1;
}
