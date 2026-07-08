/* cygnus-2.96 matched TU. */

extern void Forward33B658_3389F8(void);
extern void func_0033A730(void *a0, int a1, int a2, int a3);
extern void Forward33B670_338A10(void);
extern void func_0033A8D0(void *a0, int a1, int a2);
extern void func_0033AA48(void *a0, int a1, int a2);
extern void Forward33B658_3403C8(void);
extern void func_00340970(void *a0, int a1, int a2);
extern void Forward33B670_3403E0(void);
extern void (*D_003E9D50)(void);
extern void Obj33F8_ResetLock_FB20(void *a0);
extern void func_00345090(void);
extern int SFD_SetCond(void *a0, int a1, int a2);

__attribute__((section(".text.func_0033A6D0")))
void func_0033A6D0(void *a0, int a1, int a2, int a3) {
    Forward33B658_3389F8();
    func_0033A730(a0, a1, a2, a3);
    Forward33B670_338A10();
}

__attribute__((section(".text.func_0033A880")))
void func_0033A880(void *a0, int a1, int a2) {
    Forward33B658_3389F8();
    func_0033A8D0(a0, a1, a2);
    Forward33B670_338A10();
}

__attribute__((section(".text.func_0033A9F8")))
void func_0033A9F8(void *a0, int a1, int a2) {
    Forward33B658_3389F8();
    func_0033AA48(a0, a1, a2);
    Forward33B670_338A10();
}

__attribute__((section(".text.func_00340920")))
void func_00340920(void *a0, int a1, int a2) {
    Forward33B658_3403C8();
    func_00340970(a0, a1, a2);
    Forward33B670_3403E0();
}

__attribute__((section(".text.func_0033D230")))
void func_0033D230(void *obj) {
    if (*(int *)((char*)obj + 0xE8) != 0) {
        D_003E9D50();
    }
    Obj33F8_ResetLock_FB20(*(void **)((char*)obj + 0x8));
    *(int *)((char*)obj + 0x4) = 0;
}

__attribute__((section(".text.func_00345040")))
void func_00345040(void *obj) {
    int s1 = *(int *)((char*)obj + 0x3C);
    SFD_SetCond((void*)s1, 0x4B, (int)func_00345090);
    SFD_SetCond((void*)s1, 0x4C, (int)obj);
}
