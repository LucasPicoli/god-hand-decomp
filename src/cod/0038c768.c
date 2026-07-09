/* ee-2.9-991111 matched TU. */

extern void WaitDma(void *);
extern void func_0038C3A0(int *);
extern void UpdateGlobalPtrWithParam_3A7CC0(int);

__attribute__((section(".text.func_003974D0")))
void func_003974D0(int *o, int a1, int a2) {
    int s1 = func_003970A0(a1);
    int f;
    WaitDma(o);
    if ((unsigned int)o[4] != 0xFFFFFFFFU)
        o[4] = s1;
    o[8] = a2;
    f = o[0] & ~0xC;
    o[0] = (f & ~1) | 0x100;
}

__attribute__((section(".text.func_0038E3F0")))
int func_0038E3F0(int *o, long a1, int a2, int a3) {
    if (o[9] != 0) {
        if (a2 == 1 && (o[0] & 0x100))
            a1 -= (o[2] - o[1]);
        func_0038C3A0(o);
    }
    return (*(int (**)(int *, long, int, int))(((int *)o[0x14]) + 0x11))(o, a1, a2, a3);
}

__attribute__((section(".text.func_0038C768")))
void func_0038C768(int *o, int a1, int a2, int a3) {
    int f;
    if (o[7] != 0 && (o[0] & 1) == 0)
        UpdateGlobalPtrWithParam_3A7CC0(o[7]);
    f = o[0];
    o[7] = a1;
    o[8] = a2;
    if (a3 != 0)
        o[0] = f & ~1;
    else
        o[0] = f | 1;
}
