/* sn-2.95.3-136 matched TU. */

#include "godhand/cEma2.h"
#include "godhand/vu0.h"

extern cGameObj *Getplayer(void);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* The stack record starts at the first local, which sits above ChkLine's 0x30 bytes of
 * outgoing arguments; the vector stores want the stack pointer as their base. */
#define FRAME ((char *)&from - 0x30)

/* Line test from just above this enemy to just above the player: 1 when
 * nothing blocks it. */
__attribute__((section(".text.cEma2_ckLineToPlayer")))
int cEma2_ckLineToPlayer(cEma2 *self)
{
    cVec from;
    cVec to;
    cVec *start = &from;
    int n;

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    cVec_copy3(start, self->base.pos);
    from.y += 1.0f;
    cVec_copy3(&to, Getplayer()->pos);
    to.y += 1.0f;
    n = 1;
    if (ChkLine(start, &to, 0, 0, 1, 0x18, 0, 0, 0, 0, 0, 0, n) == n)
        n = 0;
    return n;
}
