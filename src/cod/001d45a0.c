/* sn-2.95.3-136 matched TU. */

extern int Forward30F348_31CFE0(void);

__attribute__((section(".text.func_001D45A0")))
void func_001D45A0(char *a0, int *a1, unsigned short a2)
{
    int buf[52];
    int *p;
    int n;
    int i;
    char *elem;
    unsigned int *flag;
    long f;

    i = 0;
    n = 0;
    elem = a0 + 0x1634;
    flag = (unsigned int *)(a0 + 0x1638);
    p = buf;
    for (; i < 0x34; i += 2, i -= 1) {
        f = *flag;
        if ((f & 1) == 0) {
        } else {
            *p = (int)elem;
            n++;
            p++;
        }
        elem += 8;
        flag += 2;
    }
    if (n != 0) {
        if (a2 == 0xFFFF) {
            *a1 = buf[(unsigned int)Forward30F348_31CFE0() % (unsigned int)n];
        } else {
            *a1 = (int)(a0 + 0x1634 + a2 * 8);
        }
        *(int *)(*a1 + 4) &= ~1;
    }
}
