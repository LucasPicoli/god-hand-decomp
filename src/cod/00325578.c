/* cygnus-2.96 matched TU. */

extern int CreateThread(void *);
extern void func_003B0BA8(int, int);
extern void ChangeThreadPriority(int, int);
extern void func_00325100(void);
extern int D_003CF9D8;
extern int D_003C80C8;
extern unsigned char D_003CB9D0[];
extern int D_00468CF0;
extern volatile int D_003C814C;

typedef struct {
    int status;
    void *func;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    int attr;
    int option;
} ThreadParam;

__attribute__((section(".text.func_00325578")))
void func_00325578(void) {
    ThreadParam param;
    param.func = (void *)func_00325100;
    param.stack = D_003CB9D0;
    param.stackSize = 0x2000;
    param.initPriority = D_003CF9D8;
    param.gpReg = &D_00468CF0;
    D_003C814C = CreateThread(&param);
    D_003C814C;
    func_003B0BA8(D_003C814C, 0);
    ChangeThreadPriority(D_003C814C, D_003C80C8);
    func_00325360(D_003C814C);
    D_003C814C;
}

__attribute__((section(".text.func_0035B9B0")))
int func_0035B9B0(char *a0) {
    int local0, local1;
    int a1val, s0, s1, r;
    char *p;
    a1val = *(int *)(a0 + 0x950);
    p = a0 + 0xD30;
    s1 = *(int *)(p + 0x27C);
    s0 = *(int *)(p + 0x280);
    if (a1val == 0) return 1;
    if (s1 == -5) return 0;
    func_0035AB98(a0, &local0, &local1);
    r = func_00366918(s1 + s0 * 2000 / 59940, s0, local0, local1);
    return r != 0;
}
