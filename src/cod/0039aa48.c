/* ee-2.9-991111 matched TU. */

extern int iStartTimerCounter(int);
extern int D_003FAEE4;
extern int D_00460108;
extern int CreateSema();
extern void _clearEach();

__attribute__((section(".text.func_003B7380")))
int func_003B7380(int a0) {
    int r1, r2;
    r1 = func_003B63A0(a0);
    r2 = iStartTimerCounter(a0);
    if (r1 != 0)
        func_003B63F0();
    return r2;
}

typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    int attr;
    int option;
} SemaParam;





__attribute__((section(".text.func_003B3E70")))
void func_003B3E70(void) {
    SemaParam s;
    if (D_003FAEE4 == -1) {
        s.max_count = s.init_count = 1;
        s.option = (int)&D_00460108;
        D_003FAEE4 = CreateSema(&s);
    }
}

__attribute__((section(".text.func_003BA9F0")))
void func_003BA9F0(int a0) {
    int r = func_003B63A0();
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B400 = a0;
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & 0xFFFEFFFF;
    if (r != 0) {
        func_003B63F0();
    }
}

__attribute__((section(".text.func_003BAD08")))
void func_003BAD08(int a0) {
    int r = (int)func_003B63A0();
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B400 = a0;
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & 0xFFFEFFFF;
    if (r != 0) {
        func_003B63F0();
    }
}

__attribute__((section(".text.func_0039AA48")))
int func_0039AA48(int a0) {
    int *s0 = *(int **)(a0 + 0x40);
    int v1;
    *(int *)((char *)s0 + 0x878) = 0;
    s0[0] = 0;
    s0[1] = 0;
    s0[2] = 0;
    *(int *)(a0 + 8) = 0;
    *(int *)((char *)s0 + 0xC0) = 0;
    *(int *)((char *)s0 + 0x98) = -1;
    _clearEach(s0);
    *(int *)((char *)s0 + 0x128) = 0;
    *(int *)((char *)s0 + 0x858) = 0;
    v1 = *(volatile int *)0x10002010;
    *(volatile int *)0x10002010 = (v1 & 0xFF7FFFFF) | 0x800000;
    return 1;
}
