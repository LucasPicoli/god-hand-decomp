/* sn-2.95.3-136 */
#include "godhand/cSnd.h"
#include "godhand/sceVu0.h"

extern cSnd D_005FEE00;
extern float capVu0Atan2(float y, float x);
extern float capVu0LengthAB(void *a0, void *a1);

/* The sound system object. */
static __inline__ cSnd *sndSys(void)
{
    return &D_005FEE00;
}

/* Pan angle and distance of a sound at `pos` as the listener hears it. *pan
 * gets the angle in degrees (0..359); *dist the distance, made up to 2.04
 * times longer for sounds behind the listener, clamped to 0..32000. Either
 * output may be 0. self, the sound's owner, is not read. */
__attribute__((section(".text.cSnd_CalcListenerPanDist")))
void cSnd_CalcListenerPanDist(void *self, cVec *pos, short *dist, short *pan)
{
    cVecQuad v;
    float scale;
    float ang;
    float d;
    int behind;

    scale = 1.0f;
    if (pan != 0) {
        sceVu0ApplyMatrix(&v, sndSys()->listenMtx, pos);
        ang = capVu0Atan2(v.z, v.x);
        if (ang < 0.0f) {
            ang += 6.2831855f;
        }
        ang *= 57.295776f;
        *pan = (int)(ang + 0.5f);
        *pan = *pan % 360;
        if (sndSys()->f110 == 0) {
            behind = (*pan + 270) % 360;
            if (behind > 50 && behind < 310) {
                if (behind <= 180) {
                    scale += (behind - 50) * 0.008f;
                } else {
                    scale += (310 - behind) * 0.008f;
                }
            }
        }
    }
    if (dist != 0) {
        d = capVu0LengthAB(&sndSys()->listenPos, pos) * scale;
        if (d > 32000.0f) {
            d = 32000.0f;
        }
        if (d < 0.0f) {
            d = 0.0f;
        }
        *dist = (int)d;
    }
}
