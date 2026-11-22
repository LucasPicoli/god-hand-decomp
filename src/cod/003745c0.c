/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern char D_003F2060[];
extern int SdeSystemOutModeGet(void);
extern void AIXP_SetTrackVol(int a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_003745C0")))
void func_003745C0(void *arg, int idx, int n, float val) {
    char *p = (char *)arg;
    float t;
    int i;

    if (*(int *)p == 0) {
        return;
    }
    t = val * D_005FEE00.unk00[idx] / 127.0f;
    t = t * D_005FEE00.unk0C[idx] / 127.0f;
    if (SdeSystemOutModeGet() == 2) {
        t = t * *(float *)(p + 0x44);
    }
    t = t * *(float *)(p + 0x3C);
    if (t >= 127.0f) {
        t = 127.0f;
    }
    if (n == -1) {
        for (i = 0; i < *(int *)(p + 0xC); i++) {
            AIXP_SetTrackVol(*(int *)p, i,
                          *(short *)(D_003F2060 + (int)t * 2));
            *(float *)(p + 0x14 + i * 4) = val;
        }
    } else {
        AIXP_SetTrackVol(*(int *)p, n, *(short *)(D_003F2060 + (int)t * 2));
        {
            int k = n * 4;
            *(float *)(p + k + 0x14) = val;
        }
    }
}
