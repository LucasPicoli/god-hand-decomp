extern unsigned char D_0041D808[];

__attribute__((section(".text.cCollisionSolid__dtor")))
void cCollisionSolid__dtor(int *a0, int a1) {
    *(int *)((char *)a0 + 0x30) = (int)D_0041D808;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}
