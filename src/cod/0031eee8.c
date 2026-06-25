/* ee-2.9-991111 matched TU. */

extern void func_003B3E70(void);
extern int D_003FAEE4;
extern int WaitSema(int sema);
extern const signed char D_004519F0[];
extern void func_0033F130();
extern char D_00452088[];
extern char D_00452288[];
extern char D_004522E8[];
extern char D_004524D0[];

__attribute__((section(".text.func_003A4AC8")))
int func_003A4AC8(void *a0) {
    long long p;
    p = *(long long *)((char *)a0 + 0x8);
    func_0031E870(p, p);
    return 0;
}

int type_info___eq(void *a0, void *a1);

__attribute__((section(".text.func_0031EEE8")))
void *func_0031EEE8(void *a0, void *a1, void *a2, void *a3) {
    void *p = a3;
    if (!type_info___eq(a0, a1)) {
        p = 0;
    }
    return p;
}

__attribute__((section(".text.func_003B3EC8")))
int func_003B3EC8(void) {
    func_003B3E70();
    WaitSema(D_003FAEE4);
    return 0;
}

__attribute__((section(".text.func_00324500")))
int func_00324500(signed char *a0)
{
    if (a0 == 0) {
        func_0033F130(D_004519F0);
        return -3;
    }
    return a0[1];
}

__attribute__((section(".text.func_00329FD0")))
int func_00329FD0(char *a0) {
    if (a0 == 0) {
        func_0033F130(D_00452088);
        return -1;
    }
    return a0[1];
}

__attribute__((section(".text.func_0032A9C0")))
int func_0032A9C0(short *a0) {
    if (a0 == 0) {
        func_0033F130(D_00452288);
        return 0;
    }
    return *(short *)((char *)a0 + 0x46);
}

__attribute__((section(".text.func_0032AAD8")))
int func_0032AAD8(short *a0) {
    if (a0 == 0) {
        func_0033F130(D_004522E8);
        return 0;
    }
    return *(short *)((char *)a0 + 0x40);
}

__attribute__((section(".text.func_0032B0E8")))
int func_0032B0E8(short *a0) {
    if (a0 == 0) {
        func_0033F130(D_004524D0);
        return -1;
    }
    return *(short *)((char *)a0 + 0x60);
}
