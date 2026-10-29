extern unsigned char D_0041D7E0[];

__attribute__((section(".text.InitVtableField30Alt_133A80")))
void InitVtableField30Alt_133A80(int *a0, int a1) {
    *(int *)((char *)a0 + 0x30) = (int)D_0041D7E0;
    cCollisionSolid__dtor(a0, a1);
}
