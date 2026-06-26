/* sn-2.95.3-136 matched TU. */

extern void func_0014FF00(void *, void *, void *, void *);
extern int D_007476B0;

__attribute__((section(".text.func_0031A650")))
void func_0031A650(void *a0, int a1, void *a2, void *a3, void *a4)
{
    int flags;
    int idx;

    if (a1 >= 10) {
        return;
    }
    flags = D_007476B0;
    if (a4 == (void *)0) {
        a4 = a3;
    }
    idx = (flags & 1) * 4 + a1 * 8;
    func_0014FF00(*(void **)((char *)a0 + idx + 0xB00), a2, a3, a4);
}
