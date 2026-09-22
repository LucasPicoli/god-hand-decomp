/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */

extern void func_001D4D80(void *o);
extern void InitNode_1D0C78(void *o);

__attribute__((section(".text.BlackJack__ctor")))
void *BlackJack__ctor(char *self)
{
    char *p;
    int *q;
    int *r;
    short *u;
    short *w;
    int i;
    int j;
    int k;
    int m;
    int n;
    int val;

    func_001D4D80(self);
    p = self + 0x1634;
    i = 0x33;
    do {
        InitNode_1D0C78(p);
        p += 8;
    } while (--i != -1);
    *(int *)(self + 0x1800) = 0;
    *(int *)(self + 0x1804) = 0;
    *(int *)(self + 0x1808) = 0;
    *(int *)(self + 0x181C) = 0;
    *(int *)(self + 0x1814) = 0;
    *(int *)(self + 0x1818) = 0;
    q = (int *)(self + 0x17D4);
    r = (int *)(self + 0x17E8);
    u = (short *)(self + 0x1822);
    w = (short *)(self + 0x182C);
    for (j = 4; j >= 0; j--) q[j] = 0;
    for (k = 4; k >= 0; k--) r[k] = 0;
    val = 0x34;
    for (m = 4; m >= 0; m--) u[m] = val;
    val = 0x34;
    for (n = 4; n >= 0; n--) w[n] = val;
    *(char *)(self + 0x1820) = 0;
    return self;
}
