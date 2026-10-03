/* sn-2.95.3-136 matched TU. */

extern int D_00747A2C;
extern int Getplayer(void);
extern void SeEmitter_update(void *a0);

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
    if (Getplayer() == 0) {
        return;
    }

    q = *(int **)(p + 0x2C);
    do {
        SeEmitter_update(q);
        q = *(int **)q;
    } while (q != 0);
}
