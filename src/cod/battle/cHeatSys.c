/* TU: cHeatSys [battle] - recovered C++ class. */
#include "godhand/cHeatSys.h"
#include "include_asm.h"

extern int cCoreSave_getGameDifficulty(void *p);
extern void *D_00569B70;
extern unsigned int D_00747A50;       /* lhu -> u16 */
extern void *D_003BD6E8;

extern void cHeatSys_UpdateHeatLv(cHeatSys *self);
/* Add `heat` to the gauge (boosted by 1.25 for some players and in heat mode), clamp at max,
 * move the floor up by the gain, and refresh lv. Does nothing while heat mode is on and heat > 0,
 * unless a1 is set. */
__attribute__((section(".text.cHeatSys_AddHeatGage")))
void cHeatSys_AddHeatGage(cHeatSys *self, int a1, float heat)
{
    void *obj;
    float oldCur;
    float newFloor;
    float cur;
    unsigned short mode;

    oldCur = self->cur;

    if (a1 == 0 && self->mode != 0 && 0.0f < heat)
        return;

    obj = D_00569B70;
    if ((*(int *)((char *)obj + 0x14) & 0x04000000) == 0) {
        if (cCoreSave_getGameDifficulty(&D_00569B70) == 0)
            heat = heat * 1.25f;
    }

    if (120.0f <= heat) {
        void *p = D_003BD6E8;
        *(int *)((char *)p + 0x4F0) = *(int *)((char *)p + 0x4F0) | 0x01000000;
    }

    mode = (unsigned short)D_00747A50;
    if (mode == 0x801) {
        heat = heat * 1.25f;
    }

    cur = self->cur + heat;
    self->cur = cur;
    if (self->max < cur)
        self->cur = self->max;

    if (0.0f < heat) {
        newFloor = self->floor + (self->cur - oldCur);
        self->floor = newFloor;
        if (self->max < newFloor)
            self->floor = self->max;
    }

    cHeatSys_UpdateHeatLv(self);
}
