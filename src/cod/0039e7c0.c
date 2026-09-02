/* ee-2.9-991111 matched TU. */

extern void _sceMpegStopIpuDma(void);

__attribute__((section(".text._sceMpegWaitIpuIdle")))
void _sceMpegWaitIpuIdle(void *m) {
    int cnt;
    unsigned int st;
    int cmd;
    int v;
    cnt = 0;
    if ((*(volatile unsigned int *)0x10002010 & 0x80004000) == 0x80000000) {
        do {
            st = *(volatile unsigned int *)0x10002020;
            cmd = *(int *)((char *)m + 0x82C);
            v = (int)((((st & 0xFF00) >> 1) + ((st & 0x30000) >> 9)) - (st & 0x7F));
            if (cmd == 0x20000000 || cmd == 0x30000000 || cmd == 0x40000000) {
                if ((unsigned int)v < 0x20) {
                    if (*(volatile int *)0x1000B420 == 0) {
                        func_0039AB98(*(int *)((char *)m + 0x868));
                        cnt = 0;
                        if (*(int *)((char *)m + 0x878) != 0) goto stop;
                    }
                }
            }
            if (cnt++ >= 0x1389) {
                func_0039AB98(*(int *)((char *)m + 0x868));
                cnt = 0;
                if (*(int *)((char *)m + 0x878) != 0) {
                stop:
                    _sceMpegStopIpuDma();
                    break;
                }
            }
        } while ((*(volatile unsigned int *)0x10002010 & 0x80004000) == 0x80000000);
    }
    *(int *)((char *)m + 0x82C) = 0;
}
