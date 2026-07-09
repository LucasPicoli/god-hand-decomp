/* cygnus-2.96 matched TU. */

extern int GetArrayElemA0C_35A1C8(int a0, int a1);

struct buf { unsigned char b; char _p[7]; long long v8; long long v10; };
__attribute__((section(".text.func_0034E790")))
void func_0034E790(int a0, int a1, long long a2) {
    struct buf s;
    unsigned char bv = a1 & 0xFF;
    long long v10;
    int (*fn)(int, struct buf *) = (int (*)(int, struct buf *))GetArrayElemA0C_35A1C8(a0, 0x5B);
    if (fn == 0) return;
    v10 = *(long long *)((char *)a0 + 0x990);
    s.b = bv;
    s.v8 = a2;
    s.v10 = v10;
    fn(GetArrayElemA0C_35A1C8(a0, 0x5C), &s);
}
