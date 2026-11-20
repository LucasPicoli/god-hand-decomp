/* sn-2.95.3-136: func_002E0B78, vprintf a message into the shared buffer at a given glyph size. */
#include "godhand/fileBuf.h"

extern int func_002E0AD8(int);
extern int func_002E0AE0(int);
extern int func_003A7AE8(char *buf, const char *fmt, char *args);
extern int func_002E0B18(int, int);

__attribute__((section(".text.func_002E0B78")))
void func_002E0B78(int w, int h, int a0, int a1, int a2, int a3, int a4, const char *fmt, char *args)
{
    int n;

    if (func_002E0AD8(a3) != 0) {
        return;
    }
    if (func_002E0AE0(a1) != 0) {
        return;
    }
    Moji_size_set(w & 0xFF, h & 0xFF);
    n = func_003A7AE8(D_0061B298, fmt, args);
    if (n + 1 >= 0x200) {
        *(int *)0x11111111 = 0;
    }
    if (func_002E0B18(a0, n) != 0) {
        return;
    }
    func_002E0F18(D_0061B298, a0, a1, a2, a4);
    Moji_size_set(0, 0);
}
