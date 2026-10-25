/* cygnus-2.96 matched TU. */

#include "godhand/SfdHn.h"

extern void SFD_SetCond(void *sfd, int id, int val);
extern void func_003502D8(void *sfd, int a, int b);

/* Set the Sofdec playback conditions for a picture of `w` x `h`: the rate (a count of the frame
 * pixels rounded to the nearest, 1000 per pixel) and the fixed defaults. */
__attribute__((section(".text.func_00343C18")))
void func_00343C18(SfdHn *hn, int unused, int w, int h)
{
    void *sfd = hn->sfd;
    int count = 1;
    float x;
    int n;

    SFD_SetCond(sfd, 8, 0);
    SFD_SetCond(sfd, 1, 1);
    SFD_SetCond(sfd, 0, 0);
    SFD_SetCond(sfd, 0x17, 4);
    x = (float)(w * h * 1000) + 0.5f;
    n = (int)x;
    if (!(x < (float)n)) {
        count = 0;
    }
    count = n - count;
    SFD_SetCond(sfd, 0x2D, count);
    SFD_SetCond(sfd, 0x2C, count);
    SFD_SetCond(sfd, 0x2A, count);
    SFD_SetCond(sfd, 0xF, 2);
    SFD_SetCond(sfd, 0x33, 0);
    SFD_SetCond(sfd, 0xE, 0);
    SFD_SetCond(sfd, 0x1C, 0);
    func_003502D8(sfd, 5, 0);
}
