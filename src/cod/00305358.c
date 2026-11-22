#include "godhand/globals.h"
extern void *SearchData(void *a0, void *a1, int a2);

__attribute__((section(".text.func_00305358")))
void func_00305358(int *out, void *key)
{
    void *table = D_0044FEA0;

    out[1] = (int)SearchData(key, table, 0);
    out[0] = (int)SearchData(key, table, 1);
}
