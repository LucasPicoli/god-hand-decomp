/* cygnus-2.96 matched TU. */

extern unsigned char D_00450FD8[];

__attribute__((section(".text.func_00373A68")))
int func_00373A68(int *a0) {
    return (*(int *)((char *)a0 + 0x4C) & 0x10) > 0;
}

__attribute__((section(".text.func_0034F4A8")))
int func_0034F4A8(int *a0) {
    int *p = *(int **)((char *)a0 + 0x1F7C);
    int v = *(int *)((char *)p + 0x20) + 1;
    *(int *)((char *)p + 0x20) = v;
    return v;
}

__attribute__((section(".text.func_0036A3A8")))
void func_0036A3A8(char *a0, int a1, int a2) {
    a0 += 0x3EC;
    *(int *)(a0 + 0x0) = a1;
    *(int *)(a0 + 0x4) = a2;
    *(int *)(a0 + 0x8) = 0;
}

__attribute__((section(".text.func_003537A8")))
void func_003537A8(char *a0, int a1, int *a2, int *a3) {
    a0 += 0xA0C;
    *a3 = *(int *)(a0 + 0xAC);
    *a2 = *(int *)(a0 + 0xA8);
}

__attribute__((section(".text.func_00356E80")))
int func_00356E80(char *a0) {
    char *p = *(char **)(a0 + 0x1FC0) + 0x1128;
    int v = *(int *)(p + 0xC) - 1;
    *(int *)(p + 0xC) = v;
    return v;
}

__attribute__((section(".text.func_0031F218")))
int *func_0031F218(int *a0, int a1, int a2)
{
    a0[0] = a1;
    a0[1] = (int)D_00450FD8;
    a0[2] = a2;
    return a0;
}
