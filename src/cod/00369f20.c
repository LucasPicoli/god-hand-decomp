/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

__attribute__((section(".text.func_00369F20")))
int func_00369F20(MpvHandle *hn, int code) {
    if (hn == 0) {
        func_00369F70(&D_003F1AA0, code);
    } else {
        func_00369F70(&hn->err, code);
    }
    return code;
}
