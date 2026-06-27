/* cygnus-2.96 matched TU. */

extern void func_003228C0(int a, int b, void *c, void *d, int e);
extern void func_00323AA0(void *a);
extern int D_003EB848;
extern void Forward33BC48_33BD18(void);
extern void Forward33BC48_33BD30(void);
extern void Forward33BC48_33BD48(void);
extern void Forward33BC48_33BD60(void);
extern void Forward33BC48_33BD90(void);
extern int MWSFD_GetUsePicUsr(void);
extern void func_003351C0(int a0, int *out);
extern void func_00334D68(int a0, int *p);
extern void PushGlobalD8478History_331C78(int);
extern void func_00331F50(int);
extern int D_003DA250;

__attribute__((section(".text.func_00323660")))
void *func_00323660(void *a0, void *a1) {
    void *p;
    func_003228C0(1, 0, a0, a1, -1);
    p = func_003234D0();
    if (p != 0) {
        if (func_00323568(p, a0, a1) < 0) {
            func_00323AA0(p);
            p = 0;
        }
    }
    func_003228C0(1, 1, a0, a1, -1);
    return p;
}

__attribute__((section(".text.func_00323960")))
void *func_00323960(void *a0, void *a1) {
    void *s0;
    func_003228C0(2, 0, a0, a1, -1);
    s0 = func_003234D0();
    if (s0 != 0) {
        if (func_00323840(s0, a0, a1) < 0) {
            func_00323AA0(s0);
            s0 = 0;
        }
    }
    func_003228C0(2, 1, a0, a1, -1);
    return s0;
}

__attribute__((section(".text.func_0033F720")))
int func_0033F720(void){
 int x;
 x = func_0033F850(D_003EB848);
 if (x == 1) {
 } else if (x >= 2) {
  switch (x) {
  case 2: Forward33BC48_33BD18(); break;
  case 3: Forward33BC48_33BD18(); Forward33BC48_33BD30(); Forward33BC48_33BD48(); Forward33BC48_33BD60(); Forward33BC48_33BD90(); break;
  }
 }
 return 0;
}

struct Inner { char *p; int n; };

struct Out { char pad[0x44]; int field_44; int field_48; };

__attribute__((section(".text.func_00344B28")))
void func_00344B28(char *a0, char *a1, struct Out *out) {
    struct Inner *q;
    char *p;
    int n;
    char *self;
    char *other;
    int ret;
    self = a0 + 0x160;
    other = *(char**)(a0 + 0x178);
    q = *(struct Inner**)(a1 + 0x38);
    p = q->p;
    n = q->n;
    ret = MWSFD_GetUsePicUsr();
    if (ret != 1 || other == self) {
        out->field_44 = 0;
        out->field_48 = 0;
    } else {
        if (p != 0 && n >= 5) {
            p = p + 4;
            n -= 4;
        }
        out->field_44 = (int)p;
        out->field_48 = n;
    }
}

__attribute__((section(".text.func_0034BCC0")))
int func_0034BCC0(int *d, int a1, int a2, int a3) {
    int diff;
    int r;
    diff = a2 - a3;
    d[0] = 0;
    d[2] = a1;
    d[3] = diff;
    if (diff <= 0) {
        return func_0034DD70(0, 0xFF00040C);
    }
    d[4] = a3;
    d[5] = 0;
    r = func_003395A0(a1, diff, a3);
    d[1] = r;
    if (r == 0) {
        return func_0034DD70(0, 0xFF00040A);
    }
    return 0;
}

__attribute__((section(".text.func_00334248")))
int func_00334248(int a0) {
    int local[4];
    int r;

    if (a0 == 0) return 0;
    func_003351C0(a0, local);
    if (local[1] == 0) {
        func_00334D68(a0, &D_003DA250);
        PushGlobalD8478History_331C78(0x4200);
        r = func_00331EE8(&D_003DA250, 1);
        PushGlobalD8478History_331C78(0x4201);
        if (r < 0) return 0;
        PushGlobalD8478History_331C78(0x4300);
        func_00331F50(r);
        PushGlobalD8478History_331C78(0x4301);
    }
        return 1;
}
