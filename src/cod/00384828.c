/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */

extern void func_002E0DE8(int, int, int, const char *, ...);
extern void func_00380720(int a0, int a1, int a2, int *a3, int *t0, int *t1, int *t2);
extern char D_0045CBC8[];
extern char D_0045CBD8[];
extern char D_0045CBE8[];
extern char D_0045CC18[];
extern char D_0045CC28[];
extern char D_0045CC60[];
extern char D_0045CCA0[];

__attribute__((section(".text.func_00384828")))
void func_00384828(int a0, char *a1)
{
    int q0;
    int q1;
    int q2;
    int q3;
    char *s0;
    int s1;
    int s2;

    if ((a1[3] & 2) != 0) {
        s0 = a1 + 0xCC;
        s2 = *(int *)(a1 + 0xCC);
        s1 = *(int *)(s0 + 4);
        func_002E0DE8(0x20, 0xF, 8, D_0045CBC8, *(int *)(s0 + 8));
        func_002E0DE8(0x20, 0x10, 8, D_0045CBD8, *(int *)(s0 + 0xC));
        func_002E0DE8(0x20, 0x11, 8, D_0045CBE8, *(int *)(s0 + 0x10));
    } else {
        s0 = a1 + 0x6C;
        s2 = *(int *)(a1 + 0x6C);
        s1 = *(int *)(s0 + 4);
        func_002E0DE8(0x20, 0xF, 8, D_0045CC18, *(int *)(s0 + 8));
        func_002E0DE8(0x20, 0x10, 8, D_0045CC28, *(int *)(s0 + 0xC));
    }
    func_00380720(a0, s1, s2, &q0, &q1, &q2, &q3);
    func_002E0DE8(3, 0x10, 8, D_0045CC60, q0, q1, q2, q3);
    func_002E0DE8(0x20, 0xE, 8, D_0045CCA0, s1);
}
