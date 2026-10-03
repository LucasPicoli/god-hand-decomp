/* sn-2.95.3-136 matched TU. */

#include "godhand/cEma2.h"

extern void *Getplayer(void);
extern unsigned int func_0031ED08(float f12);
extern void func_002A8578(void *obj, int a1, int a2, float f, int a3, int t0, int t1);

/* Starts a motion on the player from the data block of this enemy's model:
 * the two tables at 0x160 and 0x164 give the motion's start and end. */
__attribute__((section(".text.cEma2_startPlayerMotion")))
void cEma2_startPlayerMotion(cEma2 *self, float f12, float f13)
{
    void *player = Getplayer();
    char *data = self->base.motionData;
    int start = *(int *)(data + 0x160) + (int)data;
    int end = *(int *)(data + 0x164) + (int)data;

    func_002A8578(player, start, end, f13, func_0031ED08(f12), 0, 0);
}
