/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern cBgmData *cSnd_GetBgmData(cSnd *, int);
extern cBgmHead *cBgmData_GetHeadPtr(cBgmData *);
extern cBgmTbl *cBgmData_GetTblPtr(cBgmData *, int);
extern void func_002CFF90(cBgmData *);
extern void func_002CD548(cSndBgmNode *, int, int, float);
extern char D_0044D100[];
extern void func_002CC578(int);

/* Fire func_002CD548 on every live node whose flag 0x100000 is set. */
__attribute__((section(".text.func_002D14F8")))
void func_002D14F8(cSnd *self, float arg)
{
    cSndBgmNode *node;
    for (node = self->bgmHead; node != 0; node = node->next) {
        if (node->state2 != 2 && (node->flags & 0x100000) != 0)
            func_002CD548(node, 0x400000, 0x100000, arg);
    }
}

/* fields cSnd.h does not name yet; see cSnd_fields.h */
#define CSND_HIT(s) (*(cBgmHit **)((char *)(s) + 0x24))













/* Scale of the hit table, or the default when it is missing or not v1.3. */
__attribute__((section(".text.func_002D2CF0")))
float func_002D2CF0(cSnd *self)
{
    if (CSND_HIT(self) != 0 && func_003A5678(CSND_HIT(self), D_0044D100) == 0 && CSND_HIT(self)->version == 1.3f)
        return CSND_HIT(self)->scale;
    return 0.018f;
}

/* Claim the first unused bgm node slot out of 16 and return it, or 0. */
__attribute__((section(".text.func_002D2228")))
int func_002D2228(cSnd *self)
{
    int i;
    for (i = 0; i < 0x10; i++) {
        if (func_002CC568(func_002D2DB0(self, i)) == 0) {
            func_002CC578(func_002D2DB0(self, i));
            return func_002D2DB0(self, i);
        }
    }
    return 0;
}
