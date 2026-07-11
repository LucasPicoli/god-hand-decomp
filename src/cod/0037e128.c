/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_0037E128")))
void func_0037E128(void *a0, void *a1) {
    int r = 1;
    switch (*(unsigned char *)a0) {
    case 0: r = func_0037E200(a0, a1); break;
    case 1: r = func_0037E368(a0, a1); break;
    case 2: r = func_003808A0(a0, a1); break;
    case 3: r = func_00381940(a0, a1); break;
    case 4: r = func_00382D30(a0, a1); break;
    case 5: r = func_00384CA0(a0, a1); break;
    }
    if (r == 0) *(unsigned char *)((char *)a1 + 4) = 1;
}
