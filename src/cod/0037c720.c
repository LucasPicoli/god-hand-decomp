/* sn-2.95.3-136: func_0037C720, pan every item of a node's voice sequence: centred when the timing block's 0x14
 * flag is clear, otherwise from the node's angle (as -cos and -sin times 127) or from its 0x40 pan value. */
#include "godhand/seqNode.h"
#include "godhand/sndTiming.h"

extern int func_00373A68(int *a0);
extern int GetSequenceHandle_373B68(void *a0);
extern void UpdateSequenceState_373708(void *a0, int a1, int a2);
extern void ForwardSequenceItems_373690(void *a0, int a1, int a2);
extern float func_003A18F0(float x);    /* cos */
extern float func_003A19F8(float x);    /* sin */

__attribute__((section(".text.func_0037C720")))
void func_0037C720(SeqNode *self)
{
    int active;
    int n;
    int i;
    int pan;

    active = func_00373A68((int *)&D_0076A600[self->id]);
    n = GetSequenceHandle_373B68(&D_0076A600[self->id]);
    for (i = 0; i < n; i++) {
        if (D_0076A790.unk14 == 0) {
            if (active) {
                UpdateSequenceState_373708(&D_0076A600[self->id], 0, -0x7F);
            } else {
                ForwardSequenceItems_373690(&D_0076A600[self->id], 0, i);
            }
        } else if (active) {
            float x = -func_003A18F0(self->angle * 3.1415927f / 180.0f) * 127.0f;
            float y = -func_003A19F8(self->angle * 3.1415927f / 180.0f) * 127.0f;
            UpdateSequenceState_373708(&D_0076A600[self->id], (int)x, (int)y);
        } else if (n >= 2) {
            if (i == 0) {
                ForwardSequenceItems_373690(&D_0076A600[self->id], -15, 0);
            } else {
                ForwardSequenceItems_373690(&D_0076A600[self->id], 15, i);
            }
        } else {
            pan = self->unk40 / 4;
            if (pan >= 16) {
                pan -= 16;
            } else {
                pan -= 15;
            }
            ForwardSequenceItems_373690(&D_0076A600[self->id], pan, i);
        }
    }
}
