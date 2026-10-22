/* sn-2.95.3-136: func_001DCEF0, static initializer (priority 0xFFFF) for two vectors, a five entry row of
 * offsets at D_00568170 and a two entry row at D_005681C0. */
#include "godhand/cOmBase.h"
extern cVec D_00568150;
extern cVec D_00568160;
extern cVec D_00568170[5];
extern cVec D_005681C0[2];

__attribute__((section(".text.func_001DCEF0")))
void func_001DCEF0(int owner, int code)
{
    cVec *p;
    cVec *q;

    if (code != 0xFFFF || owner == 0)
        return;
    cVec_set4(&D_00568150, 0.0f, 0.0f, 0.0f, 1.0f);
    cVec_set4(&D_00568160, 0.238f, 0.184f, 0.0f, 1.0f);
    p = D_00568170;
    cVec_set4(p, -0.278f, 0.024f, 0.0f, 1.0f);
    p++;
    cVec_set4(p, -0.139f, 0.024f, 0.0f, 1.0f);
    p++;
    cVec_set4(p, 0.0f, 0.024f, 0.0f, 1.0f);
    p++;
    cVec_set4(p, 0.139f, 0.024f, 0.0f, 1.0f);
    p++;
    cVec_set4(p, 0.278f, 0.024f, 0.0f, 1.0f);
    q = D_005681C0;
    cVec_set4(q, -0.1112f, 0.024f, 0.0f, 1.0f);
    q++;
    cVec_set4(q, 0.1112f, 0.024f, 0.0f, 1.0f);
}
