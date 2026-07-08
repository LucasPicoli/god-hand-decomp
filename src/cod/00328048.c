/* cygnus-2.96 matched TU. */

extern void func_00347498(void);
extern void func_003475F0(void *a0);
extern void func_00359848(void);
extern void func_00359CB8(void *a0);
extern void func_0035F1D0(void *a0, int a1, int a2, int a3);
extern void func_0035F418(void *a0, int a1, int a2);
extern void func_00328368(void *obj);
extern void func_00327FA8(void *obj);
extern void func_0033F590(void);
extern void Obj33F8_Tramp_0033B658_FC70(void *obj);
extern void func_003A52F0(void *obj, int a1, int a2);
extern void Obj33F8_Tramp_0033B670_FC88(void);

__attribute__((section(".text.func_00347450")))
void func_00347450(void *obj) {
    if (*(int *)((char*)obj + 0x17C) != 0) {
        func_00347498();
        func_003475F0(obj);
    }
}

__attribute__((section(".text.func_00359800")))
void func_00359800(void *obj) {
    if (*(int *)((char*)obj + 0x36B0) != 0) {
        func_00359848();
        func_00359CB8(obj);
    }
}

__attribute__((section(".text.func_0035F3C8")))
void func_0035F3C8(void *obj, int a1, int a2) {
    func_0035F1D0(obj, a1, a2, 0);
    func_0035F418(obj, a1, a2);
}

__attribute__((section(".text.func_00328048")))
void func_00328048(void *obj) {
    func_00328368(obj);
    func_00327FA8(obj);
    while (*(signed char *)((char*)obj + 0x49) != 0) {
        func_0033F590();
    }
}

__attribute__((section(".text.func_0032F428")))
void func_0032F428(void *obj) {
    Obj33F8_Tramp_0033B658_FC70(obj);
    if (obj != 0) {
        func_003A52F0(obj, 0, 0x1964);
    }
    Obj33F8_Tramp_0033B670_FC88();
}
