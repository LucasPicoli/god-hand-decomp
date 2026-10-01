/* sn-2.95.3-136 matched TU. */
#include "godhand/ColiseumBattle.h"

extern float cEmManage_GetSpeedRate(void *a0);
extern void func_001F2B80(void *a0, void *a1, int a2, int a3, int t0, int t1);
extern int D_005864F0;

/* sn-2.95.3-136 matched TU. */





/* Counts the battle clock down by the game speed and shows it as
* minutes, seconds and hundredths. */
__attribute__((section(".text.ColiseumBattle_UpdateCountdown")))
void ColiseumBattle_UpdateCountdown(ColiseumBattle *self, void *a1) {
    float d;
    float t;
    int mins;
    int secs;
    int hund;

    d = self->countdown - cEmManage_GetSpeedRate(&D_005864F0);
    self->countdown = d;
    if (d < 0.0f) {
        self->countdown = 0.0f;
    }
    t = self->countdown;
    mins = (int)(t / 1800.0f);
    t = t - (float)(mins * 1800);
    secs = (int)(t / 30.0f);
    t = t - (float)(secs * 30);
    hund = (int)(t / 30.0f * 100.0f);
    func_001F2B80(self->ui, a1, mins, secs, hund, 1);
}
