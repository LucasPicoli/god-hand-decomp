/* cygnus-2.96 matched TU. */

extern int D_00450FC0;

__attribute__((section(".text.__rtti_class")))
void __rtti_class(int *p, int a, int b, int c) {
    if (p != 0) {
        /* SWEEP-BEGIN */
        p[3] = c;
        p[0] = a;
        p[2] = b;
        p[1] = (int)&D_00450FC0;
/* SWEEP-END */
    }
}

__attribute__((section(".text.is_open__3ios")))
int is_open__3ios(char *p) {
    int r = 0;
    char *q = *(char **)p;
    if (q != 0) {
        r = (*(int *)q & 0xC) != 0xC;
    }
    return r;
}
