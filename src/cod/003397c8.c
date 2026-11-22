/* cygnus-2.96: stream reset; reports a null handle or a closed stream, else rewinds and clears counters. */
#include "godhand/globals.h"
extern int D_00455A80;
extern int D_00455AB0;
extern int func_00339458(void *a0, void *a1);

typedef struct {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
} Stream38;

__attribute__((section(".text.func_003397C8")))
void func_003397C8(Stream38 *a0) {
    if (a0 == 0) {
        func_00339458(&D_00455AD0, &D_00455A80);
        return;
    }
    if (a0->field_4 == 0) {
        func_00339458(&D_00455AE0, &D_00455AB0);
        return;
    }
    a0->field_10 = a0->field_20;
    a0->field_C = 0;
    a0->field_14 = 0;
    a0->field_18 = 0;
    a0->field_28 = 0;
    a0->field_2C = 0;
    a0->field_30 = 0;
    a0->field_34 = 0;
}
