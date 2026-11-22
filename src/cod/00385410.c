#include "godhand/vu0.h"

extern void ADXT_SetOutBalance(void *obj, int counter);

__attribute__((section(".text.func_00385410")))
void func_00385410(char *self, char *ctrl)
{
    char *sub = self + 0x484;
    int c;
    void *obj;

    if ((*(int *)(ctrl + 0x38) & 0x8000) != 0) {
        c = *(int *)(sub + 0x20);
        if (c < -0xE)
            *(int *)(sub + 0x20) = 0xF;
        else
            *(int *)(sub + 0x20) = c - 1;
        obj = *(void **)(sub + 0x30);
        if (obj != 0)
            ADXT_SetOutBalance(obj, *(int *)(sub + 0x20));
    }
    if ((*(int *)(ctrl + 0x38) & 0x2000) != 0) {
        c = *(int *)(sub + 0x20);
        if (c < 0xF)
            *(int *)(sub + 0x20) = c + 1;
        else
            *(int *)(sub + 0x20) = -0xF;
        obj = *(void **)(sub + 0x30);
        if (obj != 0)
            ADXT_SetOutBalance(obj, *(int *)(sub + 0x20));
    }
}

void BlockOwner_dtor(char *self, void *arg);
