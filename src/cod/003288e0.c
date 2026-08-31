/* cygnus-2.96 matched TU. */

extern void Obj3290_Tramp_0033E678_9028();
extern void Obj3290_Tramp_0033E690_9040(void);
extern void func_00330AD0(int a0);
extern void func_0033F1A8(int a0, int a1);
extern void func_00330BB0(int a0, int a1, int a2);
extern void func_003280D8(int a0, int a1);
extern void func_003284B8(void *a0);
extern int D_00451ED0;
extern int D_00451F00;

__attribute__((section(".text.func_003288E0")))
void func_003288E0(void *a0)
{
    char *s0 = (char *)a0;
    int s1;
    int s2;

    if (*(char *)(s0 + 0x2) == 0) {
        if (*(char *)(s0 + 0x48) == 1) {
            *(char *)(s0 + 0x48) = 0;
            if (*(char *)(s0 + 0x47) == 0) {
                *(char *)(s0 + 0x1) = 1;
            }
        }
        if (*(char *)(s0 + 0x46) == 1) {
            int t = *(int *)(s0 + 0x8);
            if (t != 0) {
                *(int *)(s0 + 0x8) = 0;
                func_00330AD0(t);
            }
            Obj3290_Tramp_0033E678_9028();
            *(char *)(s0 + 0x46) = 0;
            *(char *)(s0 + 0x49) = 0;
            Obj3290_Tramp_0033E690_9040();
        }
        Obj3290_Tramp_0033E678_9028();
        s1 = 0;
        if (*(char *)(s0 + 0x45) == 1) {
            if (*(char *)(s0 + 0x49) == 0) {
                *(char *)(s0 + 0x49) = 1;
                Obj3290_Tramp_0033E690_9040();
                s1 = 1;
                if (*(int *)(s0 + 0x8) == 0) {
                    int r = func_00330780(*(int *)(s0 + 0x50), *(int *)(s0 + 0x54), 0);
                    *(int *)(s0 + 0x8) = r;
                    if (r == 0) {
                        func_0033F1A8((int)&D_00451ED0, *(int *)(s0 + 0x50));
                        *(char *)(s0 + 0x1) = 4;
                        *(char *)(s0 + 0x49) = 0;
                        *(char *)(s0 + 0x45) = 0;
                        return;
                    }
                }
            }
            if (*(char *)(s0 + 0x49) == 1) {
                if (s1 == 0) {
                    Obj3290_Tramp_0033E690_9040();
                }
                if ((*(int *)(s0 + 0x44) & 0xFFFF00) == 0x10100) {
                    return;
                }
                {
                    int v1;
                    func_00330BB0(*(int *)(s0 + 0x8), 0, 2);
                    s1 = func_00330B48(*(int *)(s0 + 0x8));
                    s2 = s1 << 11;
                    if (*(int *)(s0 + 0x54) == 0) {
                        s2 = func_00330D58(*(int *)(s0 + 0x50));
                    }
                    func_00330BB0(*(int *)(s0 + 0x8), 0, 0);
                    if (*(int *)(s0 + 0x10) == 0x7FFFF800) {
                        *(int *)(s0 + 0x10) = s2;
                        *(int *)(s0 + 0x14) = s1;
                    }
                    v1 = *(int *)(s0 + 0xC);
                    if (s1 < v1) {
                        *(int *)(s0 + 0xC) = s1;
                        v1 = s1;
                    }
                    if (s1 < *(int *)(s0 + 0x14) + v1) {
                        *(int *)(s0 + 0x14) = s1 - v1;
                        *(int *)(s0 + 0x10) = (s1 - v1) << 11;
                    }
                    func_003280D8((int)s0, 0);
                    *(char *)(s0 + 0x45) = 0;
                    if (func_00330CF0(*(int *)(s0 + 0x8)) == 3) {
                        int t2;
                        func_0033F1A8((int)&D_00451F00, *(int *)(s0 + 0x50));
                        t2 = *(int *)(s0 + 0x8);
                        if (t2 != 0) {
                            *(int *)(s0 + 0x8) = 0;
                            func_00330AD0(t2);
                        }
                        *(char *)(s0 + 0x49) = 0;
                        *(char *)(s0 + 0x1) = 4;
                        *(char *)(s0 + 0x45) = 0;
                        return;
                    }
                }
            }
        } else {
            Obj3290_Tramp_0033E690_9040();
        }
        if (*(char *)(s0 + 0x47) == 1) {
            *(char *)(s0 + 0x47) = 0;
        }
    }
    if (*(char *)(s0 + 0x1) == 2) {
        if (*(char *)(s0 + 0x49) == 1) {
            if (*(char *)(s0 + 0x45) == 0) {
                return func_003284B8(s0);
            }
        }
    }
}
