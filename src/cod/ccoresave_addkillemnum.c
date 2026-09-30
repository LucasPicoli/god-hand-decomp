/* cCoreSave_addKillEmNum - count one enemy kill against the current game
 * level, in both the per-stage and the whole-game tables. Taking the row
 * address first and indexing it second matches retail's address forming. */
#include "godhand/cCoreSave.h"

extern int cCoreSave_getGameLevel(cCoreSave *self);

__attribute__((section(".text.cCoreSave_addKillEmNum")))
void cCoreSave_addKillEmNum(cCoreSave *self) {
    int lv, idx;
    char *stage, *all;
    short *p1, *p2;
    if (!self->data)
        return;
    lv = cCoreSave_getGameLevel(self);
    idx = lv - 1;
    if (idx < 0)
        return;
    if (idx >= CORESAVE_LEVEL_NUM)
        return;
    stage = (char *)self->data->killEmNum;
    p1 = (short *)(stage + idx * 2);
    *p1 += 1;
    all = (char *)self->data->allKillEmNum;
    p2 = (short *)(all + idx * 2);
    *p2 += 1;
}
