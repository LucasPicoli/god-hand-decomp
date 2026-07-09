/* ee-2.9-991111 matched TU. */

extern void func_0038C3A0(int *a0);
extern void WaitDma(void *a0);
extern void func_003B63A0(void);
extern void func_003B63F0(void);

/* MATCH via ee-2.9-991111. */


__attribute__((section(".text.func_0038E490")))
void func_0038E490(int *a0, int a1, int a2)
{
    int vt;
    void (*fn)(int *, int, int);
    if (a0[9] != 0)
        func_0038C3A0(a0);
    vt = a0[0x14];
    fn = (void (*)(int *, int, int))((int *)vt)[0x13];
    fn(a0, a1, a2);
}

/* MATCH via ee-2.9-991111. */



__attribute__((section(".text.func_003973E8")))
void func_003973E8(int *a0, int a1)
{
    int s1 = func_003970A0(a1);
    WaitDma(a0);
    if ((unsigned int)a0[0xC] != 0xFFFFFFFFU)
        a0[0xC] = s1;
    a0[8] = 0;
    a0[0] = (a0[0] & ~0xC) | 0x105;
}

/* MATCH via ee-2.9-991111. */



__attribute__((section(".text.func_003B35F8")))
int func_003B35F8(int *a0)
{
    int p;
    func_003B63A0();
    p = a0[3];
    if (p == 0) {
        a0[1] = 0;
    } else {
        a0[3] = ((int *)p)[0xF];
        a0[1] = 1;
    }
    func_003B63F0();
    return p;
}
