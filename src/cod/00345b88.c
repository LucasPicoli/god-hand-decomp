/* cygnus-2.96 matched TU. */

extern int MWSFSVM_Error(char *a0, int a1);
extern char D_00457EC8[];

__attribute__((section(".text.func_00345B88")))
int func_00345B88(void *a0) {
    int h = *(int *)((char *)a0 + 0x3C);
    int r;
    int ret;
    if (h == 0) {
        return 0;
    }
    r = func_00356EF8(h);
    if (r == 0) {
        ret = 0;
        goto out;
    }
    if (r == 1) {
        ret = 1;
        goto out;
    }
    MWSFSVM_Error(D_00457EC8, r);
    ret = 0;
out:
    return ret;
}
