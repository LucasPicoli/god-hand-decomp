/* cygnus-2.96 matched TU. */

extern void Thunk_func_0033B658(void *p);
extern void Thunk_func_0033B670(void *p);
extern void func_0032B300(int x, int a1);
extern int CreateThread(void *);
extern void func_003B0BA8(int, int);
extern void ChangeThreadPriority(int, int);
extern int D_003CF9D8;
extern int D_003C80C0;
extern unsigned char D_003CA9D0[];
extern int D_00468CF0;
extern void func_00325010(void);
extern volatile int D_003C8144;
extern void *getElemInfPtr(void *, int);
extern int isEnableVidFtr(int, void *);
extern char D_003DA4D8[];
extern void (*D_003DA4D0)(int, void *);
extern int D_003DA4D4;
extern void func_00324F08(void);
extern char D_003C99D0[];
extern int D_003C80BC;
extern volatile int D_003C8140;
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *);

__attribute__((section(".text.func_0034CDF8")))
void func_0034CDF8(char *base, int delta) {
    int local[4]; int *region; int sum; int count;
    region = (int *)(base + 0xD30);
    Thunk_func_0033B658(local);
    sum = region[0x59] + delta;
    region[0x59] = sum;
    count = region[0x5A];
    count = count + 1;
    *(int *)(base + 0xE9C + (count % 32) * 4) = sum;
    region[0x5A] = count;
    Thunk_func_0033B670(local);
}

__attribute__((section(".text.func_0032EF68")))
void func_0032EF68(void *a0, int a1) {
    int i;
    int *p;
    i = 0;
    if ((int)((signed char *)a0)[3] > 0) {
        p = (int *)((char *)a0 + 0xC);
        do {
            int x;
            x = *p;
            p++;
            if (x != 0) {
                func_0032B300(x, a1);
            }
            i++;
        } while (i < (int)((signed char *)a0)[3]);
    }
}

typedef struct {
    int status;
    void *entry;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    int attr;
    int option;
} ThreadParamB;











__attribute__((section(".text.func_003254F0")))
void func_003254F0(void) {
    ThreadParamB tp;
    tp.entry = (void *)func_00325010;
    tp.stack = D_003CA9D0;
    tp.stackSize = 0x1000;
    tp.initPriority = D_003CF9D8;
    tp.gpReg = &D_00468CF0;
    D_003C8144 = CreateThread(&tp);
    (void)D_003C8144;
    func_003B0BA8(D_003C8144, 0);
    ChangeThreadPriority(D_003C8144, D_003C80C0);
}

__attribute__((section(".text.func_0035E758")))
int func_0035E758(void *arg0, int arg1, int *arg2) {
    int b;
    unsigned char *p;
    int v;
    b = arg1 & 0xFF;
    *arg2 = -1;
    p = (unsigned char *)getElemInfPtr(arg0, b);
    if (p == 0) {
        return 0;
    }
    if (isEnableVidFtr(b, p) == 0) {
        return 0;
    }
    v = p[0x25];
    *arg2 = v;
    if (v >= 0x40) {
        *arg2 = -1;
    }
    return 1;
}

__attribute__((section(".text.func_00335D40")))
void func_00335D40(void *fmt, ...) {
    func_003A7AE8(D_003DA4D8, fmt, (char *)__builtin_next_arg(fmt) - 0x38);
    if (D_003DA4D0)
        D_003DA4D0(D_003DA4D4, D_003DA4D8);
}

__attribute__((section(".text.func_00350390")))
int func_00350390(char *obj, int *arr, unsigned int nbytes) {
    void *h;
    int n;
    int i;

    h = *(void **)(*(char **)(obj + 0x1FC0));
    if (h == 0)
        return 0;
    n = nbytes >> 2;
    if ((unsigned int)n >= 0x11)
        n = 0x10;
    for (i = 0; i < n; i++) {
        func_0036C568(h, i, &arr[i]);
    }
    return n;
}

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











__attribute__((section(".text.func_00325468")))
void func_00325468(void) {
    ThreadParam param;
    param.func = func_00324F08;
    param.stack = D_003C99D0;
    param.stackSize = 0x1000;
    param.initPriority = D_003CF9D8;
    param.gpReg = &D_00468CF0;
    D_003C8140 = CreateThread(&param);
    D_003C8140;
    func_003B0BA8(D_003C8140, 0);
    ChangeThreadPriority(D_003C8140, D_003C80BC);
}

__attribute__((section(".text.func_00359B60")))
int func_00359B60(char *p, int x, int y) {
    int r;
    char *q;
    r = Obj34D8_SetGlobalEE0B8_IfField48(p);
    if (r != 0) {
        return func_0034DD70(0, 0xFF00015A);
    }
    q = *(char **)(p + 0x36B0);
    if (q == 0) {
        return r;
    }
    *(int *)(q + 0xDC8) = x;
    *(int *)(q + 0xDCC) = y;
    func_00359DF0(p);
    return r;
}

__attribute__((section(".text.func_0035E7E0")))
int func_0035E7E0(void *arg0, int arg1, int *arg2) {
    int b;
    unsigned char *p;
    int v;
    b = arg1 & 0xFF;
    *arg2 = -1;
    p = (unsigned char *)getElemInfPtr(arg0, b);
    if (p == 0) {
        return 0;
    }
    if (isEnableVidFtr(b, p) == 0) {
        return 0;
    }
    v = p[0x26];
    *arg2 = v;
    if (v >= 0x40) {
        *arg2 = -1;
    }
    return 1;
}
