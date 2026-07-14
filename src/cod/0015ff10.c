/* sn-2.95.3-136 matched TU. */

extern int D_00747A84;
extern void *Obj0000_Call_func_0015FD18_Field_48_161288(void);

__attribute__((section(".text.func_0015FF10")))
void func_0015FF10(void *obj) {
    char *s0 = (char *)obj;
    char *h;
    char *g;
    void *o;
    int v;
    int old;
    int i;
    int fill;

    if ((D_00747A84 & 0x8000000) != 0) {
        o = Obj0000_Call_func_0015FD18_Field_48_161288();
        if (o != 0) {
            char *vt = *(char **)((char *)o + 0x70);
            short off = *(short *)(vt + 0x18);
            void (*fn)(void *) = *(void (**)(void *))(vt + 0x1C);
            fn((char *)o + off);
        }
        v = *(int *)(s0 + 0xEE0);
        *(int *)(s0 + 0x48) = -1;
        h = (char *)&D_00747A84;
        g = h - 0x5E4;
        *(int *)(g + 0x5D8) = v;
        old = *(int *)(h - 0x4);
        *(int *)(g + 0x5E0) = *(int *)(s0 + 0xEE4);
        if ((old & 0x40000) != 0) {
            *(int *)(h - 0x4) |= 0x40000;
        } else {
            *(int *)(h - 0x4) &= 0xFFFBFFFF;
        }
        fill = -1;
        D_00747A84 &= 0xF7FFFFFF;
        *(char *)(s0 + 0xED4) = 0;
        *(short *)(s0 + 0x50) = 0;
        for (i = 8; i >= 0; i--) {
            *(int *)(s0 + 0xEE8 + i * 4) = fill;
        }
        *(char *)(s0 + 0xF15) = 0;
    }
}
