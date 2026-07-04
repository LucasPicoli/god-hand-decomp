/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_0038EAE0")))
int func_0038EAE0(void *arg0) {
    unsigned char *p = *(unsigned char **)((char *)arg0 + 4);
    int c;

    if (p >= *(unsigned char **)((char *)arg0 + 8)) {
        c = func_0038C688(arg0);
    } else {
        c = *p;
        *(unsigned char **)((char *)arg0 + 4) = p + 1;
    }
    return c;
}
