/* ee-2.9-991111 matched TU. */

extern char D_007817C0[];
extern int D_003FAEF4;
extern void _waitIpuIdle(void *);
extern long long _sceMpegWaitIpuIdle64(void *);

__attribute__((section(".text.func_003B58E0")))
int func_003B58E0(void) {
    int r; int status; int i;
    for (;;) {
        r = func_003B2F48(D_007817C0, 0x80000003u, 0);
        if (r < 0) return -1;
        status = *(int *)((char *)D_007817C0 + 0x24);
        if (status != 0) { D_003FAEF4 = 0; break; }
        for (i = 0x100000; i != -1; i--) { }
    }
    return 0;
}

__attribute__((section(".text.func_0039EB90")))
unsigned int func_0039EB90(void *a0, int n) {
    if (*(int *)((char *)a0 + 0x828) != 0 || *(int *)((char *)a0 + 0x84C) < n) {
        _waitIpuIdle(a0);
        *(volatile int *)0x10002000 = 0x40000000;
        *(int *)((char *)a0 + 0x828) = 0;
        *(int *)((char *)a0 + 0x82C) = 0x40000000;
        *(int *)((char *)a0 + 0x848) = (int)_sceMpegWaitIpuIdle64(a0);
        *(int *)((char *)a0 + 0x84C) = 0x20;
    }
    return (unsigned int)*(int *)((char *)a0 + 0x848) >> (-n);
}
