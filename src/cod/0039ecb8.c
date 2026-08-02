/* ee-2.9-991111 matched TU. */

extern int _sceMpegWaitIpuIdle();

/* clone */


__attribute__((section(".text._waitIpuIdle")))
void _waitIpuIdle(int a0) {
    if ((*(volatile unsigned int *)0x10002010 & 0x80004000) == 0x80000000) {
        _sceMpegWaitIpuIdle(a0);
    }
}
