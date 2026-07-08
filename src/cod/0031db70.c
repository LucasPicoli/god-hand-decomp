/* ee-2.9-991111 matched TU. */

extern void _IO_init_marker(void *obj);
extern void func_003B6818(void *obj);
extern void KExit(void *obj);
extern void __do_global_dtors(void *obj);
extern void func_003A62B0(void);
extern void func_00100248(void *obj);

__attribute__((section(".text.func_0038B578")))
void *func_0038B578(void *obj) {
    _IO_init_marker(obj);
    return obj;
}

__attribute__((section(".text.func_003B6820")))
void func_003B6820(void *obj) {
    func_003B6818(obj);
    KExit(obj);
}

__attribute__((section(".text.func_0031DB70")))
void func_0031DB70(void *obj) {
    __do_global_dtors(obj);
    func_003A62B0();
    func_00100248(obj);
}
