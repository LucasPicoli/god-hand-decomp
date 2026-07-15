/* sn-2.95.3-136 matched TU. */

extern int D_00747A2C;
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002C8AD8(void *a0);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_002CB128")))
void func_002CB128(void *a0) {
    char *p = (char *)a0;
    int *q;

    if (D_00747A2C < 0) {
        return;
    }
    if (*(int *)(p + 0x28) == 0) {
        return;
    }
    if (*(int *)(p + 0x2C) == 0) {
        return;
    }
    if (Obj0000_Get_D_00747A94_2DB6B0() == 0) {
        return;
    }

    q = *(int **)(p + 0x2C);
    do {
        func_002C8AD8(q);
        q = *(int **)q;
    } while (q != 0);
}
