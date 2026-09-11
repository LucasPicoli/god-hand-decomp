/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

extern int PatchIsNeeded(void);
extern void func_003B6668(int a0, int a1);
extern void func_003B6678(int a0, void *a1, int a2);

extern void FlushCache(int a0);
extern int D_003FB6C8[];
extern char D_003FAF20[];

__attribute__((section(".text.func_003B6738")))
void func_003B6738(void)
{
    int *t;
    int *p;
    unsigned int i;

    if (PatchIsNeeded()) {
        i = 2;
        t = D_003FB6C8;
        func_003B6668(t[0], t[1]);
        func_003B6678(0x80074000, D_003FAF20, 0x7A8);
        FlushCache(0);
        FlushCache(2);
        func_003B6668(t[2], t[3]);
        p = t + 4;
        for (; i < 3; i++) {
            int r = func_003B66C0(p[0]);
            func_003B6668(p[0], r);
            p = p + 2;
        }
    }
}
