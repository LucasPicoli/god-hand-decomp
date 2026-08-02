/* sn-2.95.3-136 matched TU. */

extern int a1();
extern int buffered__8stdiobufi();

/* clone */


__attribute__((section(".text.func_00386F38")))
void func_00386F38(short a0, short a1, short *a2)
{
    func_003A52F0(a2, 0, 0x60);
    a2[1] = a1;
    a2[0] = a0;
    *(unsigned short *)((char *)a2 + 0xE) = 0x8000;
}

/* clone */


__attribute__((section(".text.func_00389D50")))
void *func_00389D50(void *a0, void *(*a1)(void *)) {
    void *r = a1(a0);
    return r;
}

/* clone */


__attribute__((section(".text.func_003938E0")))
void func_003938E0(void *a0) { buffered__8stdiobufi((char *)a0 + 0x8); }

/* clone */


__attribute__((section(".text.func_00393BF8")))
void func_00393BF8(void *a0) { buffered__8stdiobufi((char *)a0 + 0x8); }

/* clone */

__attribute__((section(".text.func_003AEB38")))
int func_003AEB38(unsigned int x) {
    int k = 0;
    if (!(x & 0xffff0000)) { k = 16; x <<= 16; }
    if (!(x & 0xff000000)) { k += 8;  x <<= 8; }
    if (!(x & 0xf0000000)) { k += 4;  x <<= 4; }
    if (!(x & 0xc0000000)) { k += 2;  x <<= 2; }
    if (!(x & 0x80000000)) {
        k++;
        if (!(x & 0x40000000)) return 32;
    }
    return k;
}

/* clone */

__attribute__((section(".text.func_003AEBC0")))
int func_003AEBC0(unsigned int *y) {
    int k;
    unsigned int x = *y;

    if (x & 7) {
        if (x & 1)
            return 0;
        if (x & 2) {
            *y = x >> 1;
            return 1;
        }
        *y = x >> 2;
        return 2;
    }
    k = 0;
    if (!(x & 0xffff)) {
        k = 16;
        x >>= 16;
    }
    if (!(x & 0xff)) {
        k += 8;
        x >>= 8;
    }
    if (!(x & 0xf)) {
        k += 4;
        x >>= 4;
    }
    if (!(x & 0x3)) {
        k += 2;
        x >>= 2;
    }
    if (!(x & 1)) {
        k += 1;
        x >>= 1;
        if (!x)
            return 32;
    }
    *y = x;
    return k;
}
