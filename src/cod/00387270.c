/* sn-2.95.3-136 */
#include "godhand/sndCmd.h"

/* Queue the voice-parameter command for channel id, or for channels 0 and 1
 * in turn when id is -1, stopping when the queue is full; returns 0, or -1
 * when the queue is full. */
__attribute__((section(".text.func_00387270")))
int func_00387270(short id, short prm, short val, int mask)
{
    int i;

    if (id == -1) {
        for (i = 0; i < 2; i++) {
            if (func_00387328(i, prm, val, mask) == -1) {
                return -1;
            }
        }
        return 0;
    }
    return func_00387328(id, prm, val, mask);
}
