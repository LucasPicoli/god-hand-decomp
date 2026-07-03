/* cygnus-2.96 matched TU. */

extern short D_00755BC0;

__attribute__((section(".text.func_0031D9F0")))
void func_0031D9F0(int a0, int a1) {
    if (a1 != 0xFFFF) return;
    if (a0 == 0) return;
    {
    char *p = (char*)&D_00755BC0;
    *(char*)(p+2) = 0x14;
    *(short*)(p+4) = 0x3E8;
    }
}
