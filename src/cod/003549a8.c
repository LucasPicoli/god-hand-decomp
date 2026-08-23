/* cygnus-2.96 matched TU. */

extern int D_00766BA8[];
extern int D_00766BD0[];
extern int D_00766BD8[];

__attribute__((section(".text.func_003549A8")))
int func_003549A8(void) {
    int i;
    if ((unsigned int)(D_00766BA8[7] - 1) < 0x10) goto ok;
err:
    return -1;
ok:
    if (D_00766BA8[4] != 0) {
        if (D_00766BA8[8] != 0) goto ret0;
    }
    for (i = 0; i < 2; i++) {
        if (D_00766BD0[i] == 0) goto err;
    }
    for (i = 0; i < D_00766BA8[7]; i++) {
        if (D_00766BD8[i] == 0) goto err;
    }
ret0:
    return 0;
}
