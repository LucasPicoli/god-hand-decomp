#include "godhand/cOmBase.h"
#include "godhand/cVecType.h"
extern int *cRoomJump(void *a0);
extern unsigned char D_00583EC0[];

static inline void setVec4(cVec *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = 1.0f;
}

__attribute__((section(".text.func_002009E8")))
void func_002009E8(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init) {
            cVec *p;
            { unsigned char *b = D_00583EC0; cRoomJump(b + 0x34); }
            p = D_00583F00;
            setVec4(p, 0.66f, 0.01f, -52.4f);
            p++;
            setVec4(p, -48.0f, 0.25f, -57.3f);
        }
    }
}
