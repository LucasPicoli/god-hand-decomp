/* cygnus-2.96 matched TU. */

extern struct D0076A590 {
    char pad[0x40];
    int n;
    char *tbl;
} D_0076A590;

__attribute__((section(".text.func_0036D630")))
void func_0036D630(int idx, int val)
{
    char *p;
    char *q;
    int n;

    n = D_0076A590.n;
    p = D_0076A590.tbl;
    if (n <= 0) return;
    q = p + idx * 4 + 0x18;
    do {
        if (*(int *)p == 2) *(int *)q = val;
        p += 0x640;
        n--;
        q += 0x640;
    } while (n != 0);
}
