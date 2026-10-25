/* sn-2.95.3-136: func_0012A578, pos + s * (pos - unk630): the point (1 + s) times as far from the player's unk630 point as the player is. */
#include "godhand/cVec.h"
#include "godhand/pl00.h"

__attribute__((section(".text.func_0012A578")))
cVec *func_0012A578(cVec *out, pl00 *pl, float s)
{
    cVec d;

    CVEC_ZERO(d);
    CVEC_SET_SUB(d, pl->base.pos, &pl->unk630);
    CVEC_MUL_SCALAR(d, s);
    CVEC_ADD_TO(d, pl->base.pos);
    CVEC_STORE(out, d);
    return out;
}
