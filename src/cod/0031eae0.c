/* ee-2.9-991111 matched TU. */
#include "godhand/sceDma.h"

extern void func_0031DFA8(void *a0, void *a1);
extern float func_0031EDA0(int class, unsigned int sign, int exp, unsigned int frac);

struct fp32 { int a; int b; int c; int d; long long e; long long f; };

__attribute__((section(".text.dptofp")))
float dptofp(double a0)
{
    struct fp32 buf;
    long long frac;
    unsigned int sffrac;
    func_0031DFA8(&a0, &buf);
    frac = buf.e;
    sffrac = (unsigned int)(frac >> 30);
    if (frac & 0x3FFFFFFF)
        sffrac |= 1;
    return func_0031EDA0(buf.a, buf.b, buf.c, sffrac);
}

__attribute__((section(".text.sceDmaSendN")))
void sceDmaSendN(sceDmaChan *chan, void *addr, int qwc)
{
    unsigned int src = CheckAddress((unsigned int)addr);
    WaitDma(chan);
    if ((unsigned int)chan->madr != 0xFFFFFFFFU)
        chan->madr = (void *)src;
    chan->qwc = qwc;
    chan->chcr = (chan->chcr & ~0xC) | 0x101;
}
