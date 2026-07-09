/* cygnus-2.96 matched TU. */

extern void func_003228C0(int a, int b, void *c, void *d, int e);
extern char D_004518B0[];
extern char D_004518D8[];
extern void func_00323F18(void *a0);
extern void func_0033F130(int a0);
extern void func_00328368(int a0);
extern void Forward33B658_33E678(void);
extern void func_00328448(int a0, int a1);
extern void func_00328E38(void *a0, int a1);
extern void func_00328DD8(void *a0, int a1);
extern void func_003280D8(int a0, int a1);
extern void Forward33B670_33E690(void);
extern void func_00326780(int a0, int a1);
extern void func_00326830(int a0);
extern int D_003C7418;
extern void func_0033C088(int a0);

__attribute__((section(".text.func_003242B0")))
int func_003242B0(void *a0, int a1, int a2) {
    func_003228C0(6, 0, a0, (void *)a1, a2);
    if (a0 == 0) {
        func_0033F130((int)D_004518B0);
        return -3;
    }
    if (*(signed char *)((char *)a0 + 1) == 2)
        func_00323F18(a0);
    if (a2 == 0) {
        *(int *)((char *)a0 + 0x14) = a1;
    } else if (a2 == 1) {
        *(int *)((char *)a0 + 0x14) = *(int *)((char *)a0 + 0x14) + a1;
    } else if (a2 == 2) {
        *(int *)((char *)a0 + 0x14) = *(int *)((char *)a0 + 0xC) + a1;
    } else {
        func_0033F130((int)D_004518D8);
        return -3;
    }
    if (*(int *)((char *)a0 + 0x14) < 0)
        *(int *)((char *)a0 + 0x14) = 0;
    else if (*(int *)((char *)a0 + 0xC) < *(int *)((char *)a0 + 0x14))
        *(int *)((char *)a0 + 0x14) = *(int *)((char *)a0 + 0xC);
    func_003228C0(6, 1, a0, (void *)a1, a2);
    return *(int *)((char *)a0 + 0x14);
}

__attribute__((section(".text.func_00323BE0")))
int func_00323BE0(void *a0, int a1, int a2) {
    int diff, clamped, result;
    if (func_00328098(*(int *)((char *)a0 + 4)) != 1)
        func_00328368(*(int *)((char *)a0 + 4));
    Forward33B658_33E678();
    diff = *(int *)((char *)a0 + 0xC) - *(int *)((char *)a0 + 0x14);
    *(int *)((char *)a0 + 0x20) = 0;
    clamped = (a1 < diff) ? a1 : diff;
    *(int *)((char *)a0 + 0x18) = *(int *)((char *)a0 + 0x30) + *(int *)((char *)a0 + 0x14);
    *(int *)((char *)a0 + 0x1C) = clamped;
    if (clamped == 0) {
        *(char *)((char *)a0 + 1) = 3;
        result = 0;
    } else {
        func_00328448(*(int *)((char *)a0 + 4), -1);
        func_00328E38(*(int *)((char *)a0 + 4), a2);
        func_00328CE8(*(int *)((char *)a0 + 4), *(int *)((char *)a0 + 0x2C));
        *(char *)((char *)a0 + 1) = 2;
        *(char *)((char *)a0 + 3) = 0;
        func_00328DD8(*(int *)((char *)a0 + 4), 0);
        func_003280D8(*(int *)((char *)a0 + 4), *(int *)((char *)a0 + 0x14));
        func_00328240(*(int *)((char *)a0 + 4), *(int *)((char *)a0 + 0x1C));
        result = *(int *)((char *)a0 + 0x1C);
    }
    Forward33B670_33E690();
    return result;
}

__attribute__((section(".text.func_00329B60")))
void func_00329B60(void *a0, int a1) {
    int i = 0;
    if (*(signed char *)((char *)a0 + 3) > 0) {
        void **p = (void **)((char *)a0 + 0x18);
        do {
            void *o = *p++;
            (*(void (**)(void *))(*(char **)o + 0x14))(o);
            i++;
        } while (i < *(signed char *)((char *)a0 + 3));
    }
    func_00326780(*(int *)((char *)a0 + 4), a1);
    *(int *)((char *)a0 + 0x14) = a1;
    func_00326830(*(int *)((char *)a0 + 4));
    *(char *)((char *)a0 + 1) = 1;
    *(int *)((char *)a0 + 0x8C) = 0x7FFFFFFF;
    *(int *)((char *)a0 + 0x90) = -1;
    *(int *)((char *)a0 + 0x4C) = 0;
    *(char *)((char *)a0 + 0x71) = 0;
    *(int *)((char *)a0 + 0x9C) = 0;
    *(int *)((char *)a0 + 0xA4) = 0;
    *(int *)((char *)a0 + 0xA0) = D_003C7418;
    *(int *)((char *)a0 + 0xC4) = 0;
    if (*(signed char *)((char *)a0 + 2) == 4)
        func_0032B188((int)a0, 0);
    if (*(int *)((char *)a0 + 0x74) != 0)
        func_0033C088(*(int *)((char *)a0 + 0x74));
}
