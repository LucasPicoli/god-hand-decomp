/* cygnus-2.96 matched TU. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(void *a0);
extern void func_0034DD70(int a0, unsigned int a1, void *a2, void *a3);
extern void func_00350528(void *a0, void *a1);

__attribute__((section(".text.func_003504A0")))
void func_003504A0(void *a0, void *a1, void *a2, void *a3) {
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0) {
        func_0034DD70(0, 0xFF000185, a2, a3);
        return;
    }
    func_00350528(a0, a1);
}
