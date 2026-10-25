/* sn-2.95.3-136 */
#include "godhand/sndRamp.h"

/* Move r one step toward its target, clamped there, and count the step. */
__attribute__((section(".text.func_00378070")))
void func_00378070(SndRamp *r)
{
    int result = r->cur + r->step;

    if (r->step > 0)
        result = r->target < result ? r->target : result;
    else
        result = result < r->target ? r->target : result;
    r->cur = result;
    r->count++;
}
