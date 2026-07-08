/* cygnus-2.96 matched TU. */

extern int Obj34D8_SetGlobalEE0B8_IfField48(void *obj);
extern void func_0034DD70(int a0, unsigned int a1);

__attribute__((section(".text.func_00356EF8")))
int func_00356EF8(void *obj) {
    if (Obj34D8_SetGlobalEE0B8_IfField48(obj)) {
        func_0034DD70(0, 0xFF000141);
        return 0;
    }
    return *(int *)((char*)obj + 0x50);
}
