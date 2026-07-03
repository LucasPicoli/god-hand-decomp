/* sn-2.95.3-136 matched TU. */

extern int D_003C1180;
extern unsigned char D_0061B288;
extern char D_0061B298[];

__attribute__((section(".text.func_002E0B18")))
int func_002E0B18(int a0, int a1) {
    int v1;
    int v0;
    if (a0 >= D_003C1180) goto ret1;
    a0 = D_003C1180 - a0;
    v1 = D_0061B288;
    v0 = a1 * v1;
    if (a0 >= v0) goto ret0;
    a0 = a0 / v1;
    if (a0 >= 0) goto positive;
ret1:
    return 1;
positive:
    D_0061B298[a0] = 0;
ret0:
    return 0;
}
