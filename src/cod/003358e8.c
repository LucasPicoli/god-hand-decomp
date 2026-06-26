/* cygnus-2.96 matched TU. */

extern void func_00335D40();
extern void func_00335950();
extern const char D_00454CA8[];
extern void sfadxt_WtPause(void *, void *, int);
extern struct FnEntry D_007588A0;
extern volatile int D_003E9948;
extern volatile int D_003E994C;

__attribute__((section(".text.func_003358E8")))
void func_003358E8(void *a0) {
    void *s0;
    int v;

    s0 = a0;
    if (s0 == 0) {
        func_00335D40(D_00454CA8);
        return;
    }
    if (*(signed char *)((char *)s0 + 1) != 0) {
        func_00335950(s0);
    }
    v = *(int *)((char *)s0 + 0x24);
    if (v > 0) {
        *(signed char *)((char *)s0 + 1) = 2;
    } else {
        *(signed char *)((char *)s0 + 1) = 1;
    }
}

typedef signed char   Sint8;
typedef signed int    Sint32;

Sint32 ADXT_IsEndcode(Sint8 *adr, Sint32 siz, Sint32 *endsiz);

__attribute__((section(".text.sfadxt_AdjDiscard")))
Sint32 sfadxt_AdjDiscard(Sint8 *buf, Sint32 size, Sint32 *pFound) {
    Sint32 endsiz;
    Sint32 i;
    *pFound = 0;
    for (i = 0; i < size; i += 18) {
        if (!ADXT_IsEndcode(buf, 18, &endsiz)) {
            buf += 18;
            continue;
        }
        *pFound = 1;
        break;
    }
    return i;
}

__attribute__((section(".text.func_0034B3E0")))
void func_0034B3E0(void *a0, int a1) {
    void *v1;
    int v0;
    void *a0new;
    void *a0call;

    v0 = a1;
    v1 = *(void **)((char *)a0 + 0x2004);
    a0new = (char *)a0 + 0x1020;
    *(int *)((char *)v1 + 0x2C) = v0;
    a0call = *(void **)v1;
    if (v0 == 0) {
        if (*(int *)((char *)a0 + 0x50) == 1) {
            return;
        }
    }
    sfadxt_WtPause(a0call, a0new, v0);
}

struct FnEntry {
    void (*fn)(int);
    int arg;
};





__attribute__((section(".text.func_0033B568")))
void func_0033B568(int a0) {
    void (*fn)(int);
    fn = D_007588A0.fn;
    if (fn) {
        fn(D_007588A0.arg);
        if (D_003E9948 == 0) {
            D_003E994C = a0;
        }
        D_003E9948++;
    }
}
