/* cygnus-2.96 matched TU. */

extern unsigned char D_00766CE8[];

typedef struct {
    unsigned char pad0[0x54];
    int count;
    char *ptr;
} Root766CE8;



__attribute__((section(".text.func_0036C2A0")))
void *func_0036C2A0(void) {
    int n = ((Root766CE8 *)D_00766CE8)->count;
    char *p = ((Root766CE8 *)D_00766CE8)->ptr;
    int i;
    for (i = 0; i < n; i++) {
        if (*(int *)(p + 0x188) == 1) return p;
        p += 0x440;
    }
    return 0;
}
