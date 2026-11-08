/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136: scenario step kind 5 (0x2BF568). Runs when the step is not blocked by the pause bit: clears the step record, fades the event bgm out, then jumps to the room stored in the game work block. */
#include "godhand/player.h"
#include "godhand/ScenarioStep.h"

extern unsigned char D_0074748C;        /* pause state, bit 2 = menu open */
extern int D_00747A84;         /* GameWork flags5E4: system flags; the other work words are reached from its address as in the older TUs */
extern int D_003C264C;
extern char D_00583EC0[];               /* the door jump record */
extern int D_005FEE00[];                /* the sound system */

extern void func_002BF800(ScenarioStep *step);
extern void Obj0000_Set_D_00747A80_Field_70_2BF780(ScenarioStep *step);
extern void cSnd_BgmEventFade(void *snd, int reqNo, float time, float level, float weight);
extern void func_002C0840(int a0);
extern int func_001FFF30(void *door, unsigned short room, float *pos, unsigned char a3, float angle, int t0, unsigned char t1);

#define SYS_STEP_HOLD 0x40000000

__attribute__((section(".text.ScenarioStep_runJumpKind")))
void ScenarioStep_runJumpKind(ScenarioStep *step)
{
    char *h;
    char *g;
    int one;

    if (D_0074748C == 0 || ((D_0074748C >> 2) & 1) != 0) {
        step->state = 0;
        one = 1;
        h = (char *)&D_00747A84;
        *(unsigned int *)(h + 4) &= 0xBFFFFFFF;
        func_002BF800(step);
        Obj0000_Set_D_00747A80_Field_70_2BF780(step);
        step->kind = 0;
        step->step = 0;
        step->unk02 = 0;
        step->unk03 = 0;
        if (step->mode == one) {
            *(int *)(h - 0x60) |= 0x40;
            cSnd_BgmEventFade(D_005FEE00, 0, 10.0f, 0.0f, -1.0f);
            g = h - 0x5E4;
            D_005FEE00[0xB0 / 4] |= 0x200000;
            D_005FEE00[0xAC / 4] |= 0x200000;
            D_00747A84 &= -0x4001;
            if (*(unsigned short *)(g + 0x5B4) == 0x100) {
                func_002C0840(D_003C264C);
                func_001FFF30(D_00583EC0, *(unsigned short *)(g + 0x5B4), Getplayer()->pos, 1, Getplayer()->rot.y, 0x80000000, 1);
            } else {
                func_001FFF30(D_00583EC0, *(unsigned short *)(g + 0x5B4), Getplayer()->pos, 0, Getplayer()->rot.y, 0x80000000, 0);
            }
        }
    }
}
