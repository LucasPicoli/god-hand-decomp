/* sn-2.95.3-136 matched TU. */

extern void KillEffect(void *a0, int a1, int a2);
extern int D_00747A84;
extern void func_002000F8(void *a0);
extern int D_00747A2C;
extern void cSaveManager_setCheckPoint(char *dst, int a1, int a2, int a3);

__attribute__((section(".text.func_00305F58")))
void func_00305F58(void *a0, int a1) {
    char *p = (char *)a0;
    int m = 1 << a1;
    int f = *(int *)(p + 0x414);
    if ((f & m) != 0) {
        *(int *)(p + 0x414) = f & ~m;
        KillEffect(0, a1 + 0x2200, 2);
    }
}

__attribute__((section(".text.func_001FFE10")))
void func_001FFE10(void *a0) {
    char *p = (char *)a0;
    if (*(short *)p != 0) {
        *(short *)p = *(unsigned short *)p - 1;
    }
    if ((D_00747A84 & 0x2000000) != 0) {
        func_002000F8(p);
    }
}

__attribute__((section(".text.func_002BF8F8")))
void func_002BF8F8(char *a0) {
    char *p = (char *)&D_00747A2C;
    if ((*(int *)(p + 0x8) & 0x800) != 0) {
        return;
    }
    if ((*(int *)(p - 0x8) & 0x8000000) != 0) {
        return;
    }
    cSaveManager_setCheckPoint(a0, 0, 0, 0);
}
