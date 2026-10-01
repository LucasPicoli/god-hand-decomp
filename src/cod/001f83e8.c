/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cArea.h"

extern void func_00380EB0(void);
extern void func_00381D60(void);

__attribute__((section(".text.func_00380E88")))
void func_00380E88(int a0, int *a1) {
    if (*(int*)((char*)a1 + 0x30) != 0) {
        func_00380EB0();
    }
}

__attribute__((section(".text.func_00381D38")))
void func_00381D38(int a0, int *a1) {
    if (*(int*)((char*)a1 + 0x20) != 0) {
        func_00381D60();
    }
}

extern int func_001F8488(cArea *self, float *pt);
extern int func_001F8550(cArea *self, float *pt);
/* Does the area contain the point? Picks the quad or circle test by area type. */
__attribute__((section(".text.cArea_HitCheck_1F83E8")))
int cArea_HitCheck_1F83E8(cArea *self, float *pt) {
    switch (self->type) {
    case CAREA_TYPE_QUAD:
        return func_001F8488(self, pt);
    case CAREA_TYPE_CIRCLE:
        return func_001F8550(self, pt);
    }
    return 0;
}

__attribute__((section(".text._IO_putc")))
int _IO_putc(int a0, int a1) {
    char *p = *(char **)(a1 + 0x14);
    char *end = *(char **)(a1 + 0x18);
    if ((unsigned int)p < (unsigned int)end) {
        *p = (char)a0;
        *(char **)(a1 + 0x14) = p + 1;
        return a0 & 0xFF;
    }
    return func_0038C3F0(a1, a0 & 0xFF);
}

__attribute__((section(".text.cCoreSave_getComboMax")))
int cCoreSave_getComboMax(cCoreSave *self, unsigned int set) {
    cCoreSaveData *data = self->data;
    if (data == 0) {
        return 0;
    }
    if (set >= CORESAVE_COMBO_SETS) {
        return 0;
    }
    return data->combo[set].max;
}

__attribute__((section(".text.func_002948C8")))
int func_002948C8(int a0, unsigned int a1) {
    if (a1 >= 2) {
        return 0;
    }
    return *(int *)(a0 + (a1 << 2) + 0x5AC);
}

__attribute__((section(".text.cMessage_getMessageAddr")))
int cMessage_getMessageAddr(int a0, unsigned int a1) {
    int v0;
    int v1;
    a1 = a1 & 0xFFFF;
    v0 = a1 >> 12;
    a1 = a1 & 0xFFF;
    a0 = a0 + v0 * 4;
    v1 = *(int *)a0;
    return v1 + *(int *)(v1 + (a1 << 3) + 4);
}
