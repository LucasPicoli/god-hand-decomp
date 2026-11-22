/* cygnus-2.96: func_00340970, stores the four distances of a (-127..127) pan pair from both ends of the
 * range; out-of-range or missing handles report an error. */
#include "godhand/globals.h"
#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct {
    char pad0[0x1C];
    int d[4]; /* 0x1C */
} PanWork;
extern void func_00340450(char *msg);

__attribute__((section(".text.func_00340970")))
void func_00340970(PanWork *w, int x, int y)
{
    if (w == 0) {
        func_00340450(D_00456F90);
        return;
    }
    if (x < -127 || x > 127 || y < -127 || y > 127) {
        func_00340450(D_00456FB8);
        return;
    }
    w->d[0] = ABS(x + 127);
    w->d[1] = ABS(x - 127);
    w->d[2] = ABS(y + 127);
    w->d[3] = ABS(y - 127);
}
