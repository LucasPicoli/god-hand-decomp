/* cygnus-2.96 matched TU. */

extern int Forward349480_349468(int a0);
extern void func_0034CAF8(int, int *, int *);
extern long long func_0034CCB0(long long, int);
extern int GetArrayElemA0C_35A1C8(int a0, int a1);

/* MATCH via cygnus-2.96. */


__attribute__((section(".text.func_003492A0")))
int func_003492A0(int a0) {
    int r = 0;
    if (func_003492E8(a0) != 1) {
        r = Forward349480_349468(a0);
    }
    return r;
}

/* MATCH via cygnus-2.96. */


__attribute__((section(".text.func_0034FCE0")))
void func_0034FCE0(int *a0) {
    int buf[2];
    int v0 = *(int *)((char *)a0 + 0x1324);
    if (v0 != 0) {
        func_0034CAF8(v0, &buf[0], &buf[1]);
        *(long long *)((char *)a0 + 0x988) = func_0034CCB0(*(long long *)((char *)a0 + 0x988), buf[0]);
    }
}

/* MATCH via cygnus-2.96. */


__attribute__((section(".text.func_0034E268")))
int func_0034E268(int a0) {
    int e = **(int **)(a0 + 0x1F7C);
    int r55 = GetArrayElemA0C_35A1C8(a0, 0x55);
    int r56 = GetArrayElemA0C_35A1C8(a0, 0x56);
    return func_00366D28(e, r55, r56);
}
