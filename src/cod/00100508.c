/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cIDBaseScreen.h"

extern char D_0041B6A0[];
extern char D_0041B730[];
extern void cActionButtonUnit_setOk(int x);
extern void ClearLinkedNodeList_12ECF0(void *p);

__attribute__((section(".text.GetNextAnimIndex_1451E0")))
short GetNextAnimIndex_1451E0(cIDBaseScreen *self) {
    int idx;
    int bound;
    if (self->phase == 3 && self->step == 0) {
        idx = self->cur + 1;
        bound = self->listNum;
        if (idx >= bound) {
            return self->item[0];
        }
        return self->item[idx];
    }
    if (self->phase != 0) {
        return -1;
    }
    return -2;
}

__attribute__((section(".text.InitVtableAndForwardSetup_100508")))
int InitVtableAndForwardSetup_100508(void *a0) {
    *(char**)((char*)a0+0x214) = D_0041B6A0;
    return cObjBase__dtor(a0);
}

__attribute__((section(".text.Forward100FB8_101E98")))
int Forward100FB8_101E98(void) {
    return func_00100FB8(1, 0xFFFF);
}

__attribute__((section(".text.InitAltVtableAndSetup_102128")))
int InitAltVtableAndSetup_102128(void *a0) {
    *(char**)((char*)a0+0x214) = D_0041B730;
    return cPlBase__dtor(a0);
}

__attribute__((section(".text.FreeFieldObject_1267F8")))
void FreeFieldObject_1267F8(char *a0) {
    if (*(int*)(a0 + 0x165C)) {
        cActionButtonUnit_setOk(*(int*)(a0 + 0x165C));
    }
}

__attribute__((section(".text.InitZeroAndSetup_12E800")))
void InitZeroAndSetup_12E800(int *a0) {
    int *v0 = a0;
    v0[0] = 0;
    v0[1] = 0;
    v0[2] = 0;
    v0[3] = 0;
    v0[4] = 0;
    v0[5] = 0;
    v0[6] = 0;
    v0[7] = 0;
    v0[8] = 0;
    ClearLinkedNodeList_12ECF0(v0);
}
