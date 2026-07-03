/* cygnus-2.96 matched TU. */

extern int D_004559B0;
extern int D_00455920;
extern int D_004559C0;
extern int D_00455950;
extern void func_00338A48(void *a0, void *a1);

typedef struct {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
} Struct20;







__attribute__((section(".text.func_00338EC8")))
void func_00338EC8(Struct20 *a0) {
    if (a0 == 0) {
        func_00338A48(&D_004559B0, &D_00455920);
        return;
    }
    if (a0->field_4 == 0) {
        func_00338A48(&D_004559C0, &D_00455950);
        return;
    }
    {
        int v = *(int *)((char *)a0 + 0x18);
        a0->field_10 = 0;
        a0->field_C = v;
    }
}
