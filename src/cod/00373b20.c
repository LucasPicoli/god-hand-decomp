/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_00373B20")))
int func_00373B20(void *o) {
    int v = *(int*)((char*)o + 0x58);
    int r = 1;
    return r < v;
}

__attribute__((section(".text.func_0039AA38")))
void func_0039AA38(void *o) {
    int v = *(int*)((char*)o + 0x40);
    *(int*)(v + 0x878) = 1;
}
