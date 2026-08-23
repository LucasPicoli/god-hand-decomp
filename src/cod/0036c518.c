/* cygnus-2.96 matched TU. */

extern unsigned char D_00766CE8[];

typedef struct { char pad[0x54]; int n; char *p; } S0036C518;


__attribute__((section(".text.func_0036C518")))
void func_0036C518(int idx, int val) {
    int n = ((S0036C518 *)D_00766CE8)->n;
    char *p = ((S0036C518 *)D_00766CE8)->p;
    if (n > 0) {
        int off = idx * 4 + 0x190;
        do {
            if (*(int *)(p + 0x188) == 2) *(int *)(p + off) = val;
            p += 0x440;
        } while (--n);
    }
}
