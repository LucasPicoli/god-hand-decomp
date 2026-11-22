/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void func_003B9DE0(char *a0);
extern void AC3CNV_Stop(void);
extern void ac3cnv_reset(void *a0);

__attribute__((section(".text.AC3CNV_Start")))
void AC3CNV_Start(void *obj) {
    if (obj == 0) {
        func_003B9DE0(D_004608D8);
        return;
    }
    AC3CNV_Stop();
    ac3cnv_reset(obj);
    *(int *)((char*)obj + 0x4) = 1;
}
