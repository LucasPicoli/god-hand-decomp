/* ee-2.9-991111 matched TU. */

extern void func_0031DFA8(long long *, void *);
extern void _waitIpuIdle(void);
extern long long _sceMpegWaitIpuIdle64(void *);
extern void func_003B63A0(void);
extern void func_003B63F0(void);

struct P { unsigned int cls; int sign; int exp; int pad; long long mant; };
__attribute__((section(".text.func_0031E978")))
int func_0031E978(long long a0) {
    long long aa; struct P r; long long m; int v0, shift;
    aa = a0;
    func_0031DFA8(&aa, &r);
    if ((r.cls ^ 2) == 0) return 0;
    if (r.cls < 2) return 0;
    if ((r.cls ^ 4) != 0) {
        if (r.exp < 0) return 0;
        if (r.exp < 31) goto normal;
    }
    return r.sign ? (int)0x80000000 : 0x7FFFFFFF;
normal:
    shift = 0x3C - r.exp;
    m = r.mant;
    v0 = (int)((unsigned long long)m >> shift);
    return r.sign ? -v0 : v0;
}

__attribute__((section(".text.func_0039EC20")))
void func_0039EC20(char *a0, unsigned int a1) {
    unsigned int v;
    _waitIpuIdle();
    v = a1 | 0x40000000;
    *(volatile unsigned int *)0x10002000 = v;
    v = v & 0xF0000000;
    *(int *)(a0 + 0x82C) = v;
    if (v == 0x20000000) {
        *(int *)(a0 + 0x828) = 0;
    } else if (v == 0x30000000) {
        *(int *)(a0 + 0x828) = 0;
    } else if (v == 0x40000000) {
        *(int *)(a0 + 0x828) = 0;
    } else {
        *(int *)(a0 + 0x828) = 1;
    }
    *(int *)(a0 + 0x848) = (int)_sceMpegWaitIpuIdle64(a0);
    *(int *)(a0 + 0x84C) = 0x20;
}

__attribute__((section(".text.func_003B2AC8")))
int func_003B2AC8(int a0) {
    int *s1;
    int count;
    int i;
    int cur;
    int newid;
    char *e;

    s1 = (int *)a0;
    func_003B63A0();
    count = s1[2];
    e = (char *)s1[1];
    for (i = 0; i < count; i++) {
        if ((*(int *)(e + 0x10) & 1) == 0) {
            *(int *)(e + 0x10) = (i << 16) | 5;
            cur = s1[0];
            s1[0] = cur + 1;
            if (cur + 1 == 1) {
                s1[0] = cur + 2;
                newid = 1;
            } else {
                newid = cur + 1;
            }
            *(int **)(e + 0x14) = (int *)e;
            *(int *)(e + 0x18) = newid;
            func_003B63F0();
            return (int)e;
        }
        e += 0x40;
    }
    func_003B63F0();
    return 0;
}
