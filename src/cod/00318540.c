/* cygnus-2.96 matched TU. */

extern int D_003D8410;
extern volatile int D_003D8448;
extern void func_003A52F0(void *a0, int a1, int a2, int a3);
extern int D_003DA390;

__attribute__((section(".text.func_00318540")))
int func_00318540(void *a0) {
    int v1 = *(int*)((char*)a0+0x250);
    v1 |= 0x80000;
    *(char*)((char*)a0+0x2F4) = 0;
    *(int*)((char*)a0+0x250) = v1;
    *(char*)((char*)a0+0x2F5) = 0;
    *(char*)((char*)a0+0x2F6) = 0;
    *(char*)((char*)a0+0x2F7) = 0;
    *(int*)((char*)a0+0x4D0) = 0;
    *(int*)((char*)a0+0x4D4) = 0;
    return 1;
}

__attribute__((section(".text.func_00330FB8")))
void func_00330FB8(int a0, int a1, int a2, int a3) {
    int tmp = D_003D8448;
    (void)tmp;
    func_003A52F0(&D_003D8410, 0, 0x38, a3);
}

__attribute__((section(".text.func_00335218")))
void func_00335218(int a0) {
    if (a0 == 0) {
        D_003DA390 = 0x8001;
    } else if (a0 == 1) {
        D_003DA390 = a0;
    } else {
        D_003DA390 = 0x8001;
    }
}
