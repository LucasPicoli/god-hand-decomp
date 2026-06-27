/* sn-2.95.3-136 matched TU. */

extern char D_0045E588[];
extern int D_0077DB88;

typedef struct {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
} S0039;




__attribute__((section(".text.func_0039ADE0")))
int func_0039ADE0(void *a0, S0039 *a1, unsigned int a2, unsigned int a3) {
    unsigned int q, sz;
    q = (a1->f8 + a3 - 1) / a3;
    sz = q * a3;
    if (a1->f0 + a1->f4 < sz + a2) {
        func_0039C390(a0, D_0045E588);
        return 0;
    }
    a1->f8 = sz + a2;
    return sz;
}

__attribute__((section(".text.func_003ADF50")))
int func_003ADF50(int *a0, int a1)
{
    int v1;
    D_0077DB88 = 0;
    v1 = func_003B0388(a1);
    if (v1 == -1) {
        if (D_0077DB88 != 0) {
            *a0 = D_0077DB88;
        }
    }
    return v1;
}
