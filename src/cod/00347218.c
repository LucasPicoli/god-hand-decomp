#include "godhand/globals.h"
extern int GetField0OrZero_346828(void *a0);
extern int func_00346C48(int a0);
extern void func_0035FC60(int h, int a1, int a2);
extern void SetField_4_35FC78(int h, int v);
extern void MWSFSVM_Error(char *msg);

__attribute__((section(".text.func_00347218")))
void func_00347218(int a0, int a1, int a2, int a3)
{
    int h;

    if (GetField0OrZero_346828((void *)a0) != 1) {
        MWSFSVM_Error(D_00458B50);
        return;
    }
    h = func_00346C48(a0);
    func_0035FC60(h, a1, a2);
    SetField_4_35FC78(h, a3);
}
