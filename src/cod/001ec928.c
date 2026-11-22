#include "godhand/cOmBase.h"
#include "godhand/cVecType.h"

static inline void setVec4(cVec *v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

__attribute__((section(".text.func_001EC928")))
void func_001EC928(int owner, int code)
{
    if (code != 0xFFFF || owner == 0)
        return;
    setVec4(&D_005681E0, 0.45f, -0.21f, 0.95f, 1.0f);
    setVec4(&D_005681F0, 0.0f, -0.20944f, 0.0f, 1.0f);
    setVec4(&D_00568200, 0.0f, 0.0f, 3.0f, 1.0f);
    setVec4(&D_00568210, 0.0f, 0.0f, 0.0f, 1.0f);
    setVec4(&D_00568220, -25.84f, 1.59f, -9.72f, 1.0f);
    setVec4(&D_00568230, -33.13f, 0.22f, -5.92f, 1.0f);
}
