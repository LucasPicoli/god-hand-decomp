/* cygnus-2.96 matched TU. */

__attribute__((section(".text.Forward36C920_344BC0")))
int Forward36C920_344BC0(int a0, int a1, int a2) {
    return func_0036C920(a0, a1, a2 * 1000);
}

__attribute__((section(".text.func_0034CA00")))
void func_0034CA00(char *a0, int a1, int a2) {
    if (a1 != 8) {
        char *p = a0 + a1*0x74;
        *(int*)(p + 0x1318) = a2;
    }
}

__attribute__((section(".text.func_0034CA68")))
void func_0034CA68(char *a0, int a1, int a2) {
    if (a1 != 8) {
        char *p = a0 + a1*0x74;
        *(int*)(p + 0x131C) = a2;
    }
}

__attribute__((section(".text.func_00376CF8")))
void func_00376CF8(void *a0, void *a1) {
    *(unsigned short*)((char*)a1+0x16) = *(unsigned short*)((char*)a0+0x16);
    *(unsigned short*)((char*)a1+0x18) = *(unsigned short*)((char*)a0+0x24);
    *(unsigned short*)((char*)a1+0x1A) = *(unsigned short*)((char*)a0+0x26);
    *(unsigned short*)((char*)a1+0x1C) = *(unsigned short*)((char*)a0+0x28);
    *(unsigned short*)((char*)a1+0x1E) = *(unsigned short*)((char*)a0+0x2A);
}

__attribute__((section(".text.func_00380870")))
unsigned int func_00380870(unsigned int a0) {
    unsigned int a1 = a0 << 8;
    unsigned int v0 = a0 << 24;
    unsigned int v1 = a0 >> 8;
    a1 = a1 & 0x00FF0000;
    v1 = v1 & 0xFF00;
    v0 = v0 | a1;
    a0 = a0 >> 24;
    v0 = v0 | v1;
    return v0 | a0;
}
