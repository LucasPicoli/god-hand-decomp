#include "godhand/globals.h"
extern void *cIDParam(void *);
extern void *func_00309000(void *);

__attribute__((section(".text.func_002ACBE8")))
void func_002ACBE8(int init, int priority)
{
    if (priority == 0xFFFF && init) {
        cIDParam(D_005CB020);
        func_00309000(D_005CB300);
    }
}
