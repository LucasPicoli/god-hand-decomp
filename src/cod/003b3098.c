/* ee-2.9-991111 matched TU. */

extern void func_003B0A40(int a);

/* compiler: ee-2.9-991111 ; extra keys: none */


__attribute__((section(".text._request_call")))
void _request_call(char *p) {
    char *r;
    char *q;
    int t0;
    int t1;
    r = *(char **)(p + 0x34);
    q = *(char **)(r + 0x40);
    if (*(int *)(q + 0xC) == 0) {
        *(int *)(q + 0xC) = (int)r;
    } else {
        *(int *)(*(int *)(q + 0x10) + 0x3C) = (int)r;
    }
    *(int *)(q + 0x10) = (int)r;
    t0 = *(int *)(p + 0x14);
    t1 = *(int *)(p + 0x1C);
    *(int *)(r + 0x20) = t0;
    *(int *)(r + 0x1C) = t1;
    *(int *)(r + 0x24) = *(int *)(p + 0x20);
    *(int *)(r + 0xC) = *(int *)(p + 0x24);
    *(int *)(r + 0x28) = *(int *)(p + 0x28);
    *(int *)(r + 0x2C) = *(int *)(p + 0x2C);
    *(int *)(r + 0x30) = *(int *)(p + 0x30);
    *(int *)(r + 0x34) = *(int *)(p + 0x10);
    if (*(int *)(q + 0x0) >= 0) {
        if (*(int *)(q + 0x4) == 0) {
            func_003B0A40(*(int *)(q + 0x0));
        }
    }
}
