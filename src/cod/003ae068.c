/* sn-2.95.3-136 matched TU. */

extern int read(int, char *, int);
extern int D_0077DB88;

__attribute__((section(".text.func_003AE068")))
int func_003AE068(int *errp, int fd, char *buf, int n) {
    int ret;
    D_0077DB88 = 0;
    ret = read(fd, buf, n);
    if (ret == -1) {
        int e;
        e = D_0077DB88;
        if (e != 0) {
            *errp = e;
        }
    }
    return ret;
}
