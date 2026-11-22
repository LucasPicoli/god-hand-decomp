/* sn-2.95.3-136 matched TU. */
#include "godhand/globals.h"

extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];

#define PHASE_OBJ_STATE   0x2F4         /* state byte: index into the phase table */
#define PHASE_OBJ_RATE    0x5A8         /* speed rate float */

/* One phase entry: this-adjust, method index (or negative: inline handler), table offset in the object. */
typedef struct PhaseEnt {
    short adjust;                       /* 0x00 */
    short index;                        /* 0x02 */
    short tableOff;                     /* 0x04 */
    short unk06;
} PhaseEnt;
typedef struct PhaseTable { PhaseEnt e[1]; } PhaseTable;

extern PhaseTable D_003BDC50;

/* Phase tick: scale the global speed rate by D_00747A14 into the object, run the handler the state byte's table entry names (from a method table found through the object, or inline), then the shared post-update steps. */
__attribute__((section(".text.EmPhaseScroll_update")))
void EmPhaseScroll_update(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    float rate;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    rate = cEmManage_GetSpeedRate(D_005864F0) * D_00747A14;
    *(float *)(s0 + PHASE_OBJ_RATE) = rate;
    i8 = *(unsigned char *)(s0 + PHASE_OBJ_STATE) * 8;
    e = (char *)&D_003BDC50 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDC50 + i8 + 4);
    }
    f0 = D_003BDC50.e[*(unsigned char *)(s0 + PHASE_OBJ_STATE)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}
