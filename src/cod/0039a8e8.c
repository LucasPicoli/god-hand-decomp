/* ee-2.9-991111 matched TU. */

extern void _sceMpegStopIpuDma(void);

__attribute__((section(".text.sceMpegGetPictureRAW8")))
int sceMpegGetPictureRAW8(void *m, unsigned int addr, int mode) {
    char *q;
    addr = (addr & 0x0FFFFFFFU) | 0x20000000U;
    q = (char *)*(int *)((char *)m + 0x40);
    *(int *)(q + 0xF8) = mode;
    *(int *)(q + 0xEC) = addr;
    *(int *)(q + 0xC4) = 0;
    *(int *)(q + 0xF4) = 0;
    *(int *)(q + 0xF0) = 0;
    return func_0039A140(m);
}

__attribute__((section(".text.sceMpegInit")))
int sceMpegInit(void) {
    int oldstat;
    oldstat = func_003B63A0();
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B000 = *(volatile unsigned int *)0x1000B000 & 0xFFFFFEFFU;
    *(volatile unsigned int *)0x1000B400 = *(volatile unsigned int *)0x1000B400 & 0xFFFFFEFFU;
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & 0xFFFEFFFFU;
    if (oldstat != 0) EIntr();
    *(volatile unsigned int *)0x1000B020 = 0;
    *(volatile unsigned int *)0x1000B420 = 0;
    func_003BAD80();
    return 1;
}

__attribute__((section(".text._sceMpegStopIpuDma")))
void _sceMpegStopIpuDma(void) {
    int oldstat;
    oldstat = func_003B63A0();
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B000 = 0;
    *(volatile unsigned int *)0x1000B400 = 0;
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & 0xFFFEFFFFU;
    if (oldstat != 0) EIntr();
    *(volatile unsigned int *)0x1000B020 = 0;
    *(volatile unsigned int *)0x1000B420 = 0;
    *(volatile unsigned int *)0x10002010 = 0x40000000;
}

__attribute__((section(".text._sceMpegWaitIpuIdle64")))
long long _sceMpegWaitIpuIdle64(void *m) {
    long long r;
    int cnt;
    unsigned int st;
    int cmd;
    int v;
    cnt = 0;
    r = *(volatile long long *)0x10002000;
    if (r < 0) {
        if ((*(volatile int *)0x10002010 & 0x4000) == 0) {
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
                if (cnt++ >= 0x1F5) {
                    func_0039AB98(*(int *)((char *)m + 0x868));
                    cnt = 0;
                    if (*(int *)((char *)m + 0x878) != 0) {
                    stop:
                        _sceMpegStopIpuDma();
                        break;
                    }
                }
                r = *(volatile long long *)0x10002000;
                if (r >= 0) break;
            } while ((*(volatile int *)0x10002010 & 0x4000) == 0);
        }
    }
    *(int *)((char *)m + 0x82C) = 0;
    return r;
}
