/* sn-2.95.3-136 matched TU. */

#include "godhand/cHeatSys.h"

extern float cHeatSys_GetHeatRatio(cHeatSys *self);
extern void cHeatSys_UpdateHeatLv(cHeatSys *self);
extern void *Getplayer(void);
extern void KillEffect(void *eff, int a, int b);

/* Recompute lv (0, 1 or 2) from the cur / max ratio. */
__attribute__((section(".text.cHeatSys_UpdateHeatLv")))
void cHeatSys_UpdateHeatLv(cHeatSys *self)
{
    float ratio = cHeatSys_GetHeatRatio(self);
    if (ratio < HEATSYS_LV_LOW_RATIO) {
        self->lv = 0;
    } else {
        int lv = 2;
        if (ratio <= HEATSYS_LV_MID_RATIO)
            lv = 1;
        self->lv = lv;
    }
}

/* Set cur to `gage`, capped at max, and refresh lv. */
__attribute__((section(".text.cHeatSys_SetHeatGage")))
void cHeatSys_SetHeatGage(cHeatSys *self, float gage)
{
    if (self->max < gage)
        self->cur = self->max;
    else
        self->cur = gage;
    cHeatSys_UpdateHeatLv(self);
}

/* Set the heat mode flag; the floor becomes cur - threshold (not below 0). A nonzero mode also kills the effect from Obj0000_Get_D_00747A94. */
__attribute__((section(".text.cHeatSys_SetHeatMode")))
void cHeatSys_SetHeatMode(cHeatSys *self, unsigned char mode)
{
    float floor;
    self->mode = mode;
    floor = self->cur - self->threshold;
    self->floor = floor;
    if (floor < 0.0f)
        self->floor = 0.0f;
    if (mode)
        KillEffect(Getplayer(), 3, 2);
}

/* Drain cur by `amount`, not below floor, refresh lv. Returns 1 if cur sits on the floor. */
__attribute__((section(".text.cHeatSys_SubHeatGage")))
int cHeatSys_SubHeatGage(cHeatSys *self, int check, float amount)
{
    float cur = self->cur - amount;
    self->cur = cur;
    if (cur < self->floor)
        self->cur = self->floor;
    cHeatSys_UpdateHeatLv(self);
    if (check) {
        if (self->cur <= self->floor) {
            self->cur = self->floor;
            return 1;
        }
    }
    return 0;
}
