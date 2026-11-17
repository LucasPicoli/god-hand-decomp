#include "godhand/gameWork.h"
#include "godhand/libpad.h"
typedef struct PadVibSlot {
    unsigned char flags;
    char pad1[3];
    unsigned short wait;
    unsigned short count;
    char pad8[8];
} PadVibSlot;

typedef struct PadVibWork {
    char pad0[0x160];
    PadVibSlot vib[32];
    unsigned char act[2];
    char pad362[0x4B8 - 0x362];
    unsigned char enable;
} PadVibWork;

extern void classPAD_WORK_Pad_act_all_stop(PadVibWork *w);
extern void func_0031BC98(PadVibWork *w, int i);
extern void func_0031BD78(PadVibWork *w, int i);

__attribute__((section(".text.func_0031BB80")))
void func_0031BB80(PadVibWork *w)
{
    PadVibSlot *v = w->vib;
    unsigned int i;

    w->act[0] = 0;
    w->act[1] = 0;
    i = 0;
    if ((D_00747A2C.unk00 & 0x08000000) || w->enable == 0) {
        classPAD_WORK_Pad_act_all_stop(w);
    } else if (!(D_00747A2C.unk4C & 0x04000000)) {
        do {
            if (v->flags & 3) {
                if (v->wait != 0) {
                    v->wait--;
                } else if (v->count != 0) {
                    func_0031BC98(w, i);
                    v->count--;
                } else {
                    func_0031BD78(w, i);
                }
            }
            i++;
            v++;
        } while (i < 0x20);
    }
    if (!(D_00747A24 & 0x20000000))
        scePadSetActDirect(0, 0, w->act);
}
