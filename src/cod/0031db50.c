/* ee-2.9-991111 matched TU. */

extern int D_00755BC8;
extern void __do_global_ctors(void);
extern void func_0038C3A0(int);
extern void _sceMpegWaitIpuIdle(int);

__attribute__((section(".text.func_0031DB50")))
void func_0031DB50(void) {
    if (D_00755BC8 == 0) {
        D_00755BC8 = 1;
        __do_global_ctors();
    }
}

__attribute__((section(".text.func_0038D140")))
void func_0038D140(int a0) {
    if (*(int *)((char *)a0 + 0x30) != 0) {
        *(int *)((char *)a0 + 0x30) = 0;
    }
    if (*(int *)((char *)a0 + 0x24) != 0) {
        func_0038C3A0(a0);
    }
}

__attribute__((section(".text.func_003A0DE8")))
void func_003A0DE8(int a0) {
    if ((*(volatile unsigned int *)0x10002010 & 0x80004000) == 0x80000000) {
        _sceMpegWaitIpuIdle(a0);
    }
}
