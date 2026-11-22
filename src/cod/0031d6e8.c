/* sn-2.95.3-136: __malloc_alloc_template<0>::_S_oom_malloc (0x31D6E8). */

#include "godhand/stlAlloc.h"
#include "godhand/globals.h"

static inline void *ostream_manip(void *os, void *(*manip)(void *))
{
    return manip(os);
}

__attribute__((section(".text.func_0031D6E8")))
void *func_0031D6E8(size_t n)
{
    void (*handler)(void);
    void *result;

    for (;;) {
        handler = D_003C4070;
        if (handler == 0) {
            ostream_manip(__ls__7ostreamPCc(D_003F3D60, D_00450F38), endl__FR7ostream);
            func_0031DB70(1);
        }
        handler();
        result = func_003A7C70(n);
        if (result != 0) {
            return result;
        }
    }
}
