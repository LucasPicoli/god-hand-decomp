/* ee-2.9-991111 matched TU. */

extern char D_0045E720[];
extern void func_0039C390(void *s, char *msg);
extern char D_0045E770[];
extern void _waitIpuIdle(void *s);
extern long long _sceMpegWaitIpuIdle64(void *s);
extern unsigned int func_0039EB90(void *s, int n);
extern void func_0039ECF0(void *s, int n);
extern void func_0039C3E8(void *s, char *msg, int a);

/* ee-2.9-991111 matched TU.
 * func_0039ECF8 @ 0x0039ECF8, 188 B. sce302_libmpeg/mpc.o :: _skipMB0
 * (LOCAL symbol in the donor object, so the retail definition is static).
 * Donor base: .o .text offset 0x28C8 + 0x0039C430 = 0x0039ECF8.
 *
 * func_0039C390 is _sceMpegError; D_0045E720 is its asciz message.
 * Store order: p3[1] then p3[0] in source emits 0($a3) then 4($a3)
 * (store-rotation-by-one).
 */




__attribute__((section(".text.func_0039ECF8")))
int func_0039ECF8(void *s, int *b, int *p2, int *p3, int *p4)
{
    int ret;
    int flag;

    ret = 1;
    *(int *)((char *)s + *(int *)((char *)s + 0x820) * 0x140 + 0x6DC) = 1;
    *(int *)((char *)s + 0x1C0) = 1;
    if (*(int *)((char *)s + 0x160) == 2) {
        b[5] = 0;
        b[4] = 0;
        b[1] = 0;
        b[0] = 0;
    }
    if (*(int *)((char *)s + 0x184) == 3) {
        *p2 = 2;
    } else {
        *p2 = 1;
        flag = (*(int *)((char *)s + 0x184) == 2);
        p3[1] = flag;
        p3[0] = flag;
    }
    if (*(int *)((char *)s + 0x160) == 1) {
        func_0039C390(s, D_0045E720);
        ret = 0;
    }
    *p4 = *p4 & -2;
    return ret;
}

/* ee-2.9-991111 matched TU.
 * func_0039E648 @ 0x0039E648, 376 B
 * sce302_libmpeg/mpc.o :: _sceMpegMbAddressIncrement (GLOBAL symbol).
 * Donor base: .o .text offset 0x2218 + 0x0039C430 = 0x0039E648.
 *
 * func_0039EB90 is _sceMpegPeepBit, func_0039ECF0 is _flushBuf
 * (a j to _sceMpegFlushBuf), func_0039C3E8 is _sceMpegError1.
 * D_0045E770 is the asciz message.
 *
 * Three source decisions are load-bearing and each was measured:
 *  1. `cmd` holds 0x30000000 in a local, so the 0x10002000 address pseudo
 *     sits next to its use. Its loop lifetime is then 1, not 2, and
 *     loop.c's `threshold * savings * lifetime >= insn_count` test fails,
 *     so the address is NOT hoisted. Inlining the constant costs one
 *     extra callee-saved register (380 B, frame 0x80 against 0x70).
 *  2. `switch ((unsigned int)code)` emits retail's `sltiu` range test.
 *     A signed index emits `slti`.
 *  3. In `case 0x23`, `again = 1;` comes BEFORE `total += 0x21;`, so the
 *     delay-slot filler takes `addiu $s2,$s2,0x21`. The reverse order
 *     cross-jumps the arm onto case 0x22 and costs 3 words.
 */








__attribute__((section(".text.func_0039E648")))
int func_0039E648(void *s)
{
    long long v;
    long long top;
    unsigned int bp;
    unsigned int r;
    int code;
    int total;
    int again;
    unsigned int cmd;

    total = 0;
    do {
        _waitIpuIdle(s);
        cmd = 0x30000000;
        *(volatile unsigned int *)0x10002000 = cmd;
        *(int *)((char *)s + 0x82C) = cmd;
        *(int *)((char *)s + 0x828) = 0;
        v = _sceMpegWaitIpuIdle64(s);
        bp = *(volatile unsigned int *)0x10002020;
        top = *(volatile long long *)0x10002030;
        *(int *)((char *)s + 0x848) = (int)top;
        if (top < 0) {
            *(int *)((char *)s + 0x84C) = (0x20 - (bp & 0x1F)) & 0x1F;
        } else {
            *(int *)((char *)s + 0x84C) = 0x20;
        }
        *(int *)((char *)s + 0x12C) = ((int)v == 0);
        code = (short)v;
        switch ((unsigned int)code) {
        case 0x22:
            again = 1;
            break;
        case 0x23:
            again = 1;
            total += 0x21;
            break;
        case 0:
            r = func_0039EB90(s, 0xB);
            if (*(int *)((char *)s + 0x858) != 0 && r == 0xF) {
                func_0039ECF0(s, 0xB);
                again = 1;
                break;
            }
            func_0039C3E8(s, D_0045E770, code);
            *(int *)((char *)s + 0x12C) = 1;
            return 1;
        default:
            total += code;
            again = 0;
            break;
        }
    } while (again);
    return total;
}
