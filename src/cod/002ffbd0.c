/* sn-2.95.3-136 matched TU. */

extern int Setup_Fields_2B0_2F56C0();
extern int Setup_Field_2B0_2F61C8();
extern char D_0044FCF8[];
extern int UnlinkAndCoalesceNode_2A9680();

/* clone */


__attribute__((section(".text.func_002FFBD0")))
void *func_002FFBD0(void *a0) {
    void *r = a0;
    if (r)
        r = func_002E81D8(a0);
    return r;
}

/* clone */


__attribute__((section(".text.func_002FFBF8")))
void *func_002FFBF8(void *a0) {
    void *r = a0;
    if (r)
        r = func_002E9B68(a0);
    return r;
}

/* clone */


__attribute__((section(".text.func_002FFC60")))
void *func_002FFC60(void *a0) {
    void *r = a0;
    if (r)
        r = func_002EBF08(a0);
    return r;
}

/* clone */


__attribute__((section(".text.func_002FFF90")))
void *func_002FFF90(void *a0) {
    void *r = a0;
    if (r)
        r = Setup_Fields_2B0_2F56C0(a0);
    return r;
}

/* clone */


__attribute__((section(".text.func_002FFFB8")))
void *func_002FFFB8(void *a0) {
    void *r = a0;
    if (r)
        r = Setup_Field_2B0_2F61C8(a0);
    return r;
}

/* clone */


__attribute__((section(".text.func_00300088")))
void *func_00300088(void *a0) {
    void *r = a0;
    if (r)
        r = func_002F7CD8(a0);
    return r;
}

/* clone */


__attribute__((section(".text.func_00304D48")))
void *func_00304D48(void *a0) {
    void *r = a0;
    if (r)
        r = func_00302790(a0);
    return r;
}

/* clone */



__attribute__((section(".text.func_00304F58")))
int func_00304F58(void *a0) {
    *(char**)((char*)a0+0xF0) = D_0044FCF8;
    return func_003028E8(a0);
}

/* clone */


__attribute__((section(".text.func_0030F5C8")))
void func_0030F5C8(int *a0) {
    if (a0) {
        UnlinkAndCoalesceNode_2A9680(*(int*)((char*)a0 - 0x20), a0);
    }
}
