/* cygnus-2.96 matched TU. */

extern unsigned char D_0076A590[];

typedef struct {
    unsigned char pad0[0x40];
    int count;
    char *ptr;
} Root76A590;



__attribute__((section(".text.func_0036D410")))
void *func_0036D410(void) {
    int n = ((Root76A590 *)D_0076A590)->count;
    char *p = ((Root76A590 *)D_0076A590)->ptr;
    int i;
    for (i = 0; i < n; i++) {
        if (*(int *)p == 1) return p;
        p += 0x640;
    }
    return 0;
}
