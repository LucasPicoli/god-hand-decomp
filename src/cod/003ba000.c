/* cygnus-2.96 matched TU. */

extern char D_004608D8[];
extern void func_003B9DE0(char *a0);
extern void func_003BA058(void);
extern void func_003B9FB8(void *a0);

__attribute__((section(".text.func_003BA000")))
void func_003BA000(void *obj) {
    if (obj == 0) {
        func_003B9DE0(D_004608D8);
        return;
    }
    func_003BA058();
    func_003B9FB8(obj);
    *(int *)((char*)obj + 0x4) = 1;
}
