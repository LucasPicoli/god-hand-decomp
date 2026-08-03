/* cygnus-2.96 matched TU. */

__attribute__((section(".text.cObjSimple_SetRingFlag")))
void cObjSimple_SetRingFlag(char *arg0, int arg1) {
    arg0[0x2FF0] = arg1;
}

__attribute__((section(".text.cObjSimple_SetBustFlag")))
void cObjSimple_SetBustFlag(char *arg0, int arg1) {
    arg0[0x2FA0] = arg1;
}

__attribute__((section(".text.cScenario_SetRoomExitFunc")))
void cScenario_SetRoomExitFunc(void *a0, int a1, int a2) {
    *(int*)((char*)a0+0xEC) = a1;
    *(int*)((char*)a0+0xF0) = a2;
}

__attribute__((section(".text.cEmManage_DarkWorldCk")))
int cEmManage_DarkWorldCk(int a0) {
    return *(unsigned char*)((char*)a0 + 0x518) != 0;
}

__attribute__((section(".text.cEma2_ckKiss")))
int cEma2_ckKiss(void *a0) {
    return *(unsigned char*)((char*)a0+0x15B1) & 1;
}

__attribute__((section(".text.cOm53_setDownPos")))
void cOm53_setDownPos(void *a0, float x) { *(float *)((char *)a0 + 0x620) = x; }
