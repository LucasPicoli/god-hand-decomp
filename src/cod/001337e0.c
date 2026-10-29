extern unsigned char D_0041D5A8[];

__attribute__((section(".text.cCollisionScrollSolid__dtor")))
void cCollisionScrollSolid__dtor(int *a0, int a1) {
    *(int *)((char *)a0 + 0x5C) = (int)D_0041D5A8;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}
