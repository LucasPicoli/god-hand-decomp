/* TU: cEm00 [enemy] - recovered C++ class. */

__attribute__((section(".text.cEm00_setAlphaMode")))
void cEm00_setAlphaMode(void *a0, char a1) {
    *(char *)((char *)a0 + 0x1868) = a1;
}

__attribute__((section(".text.cEm00_setDevilEventFlag")))
void cEm00_setDevilEventFlag(void *a0) {
    *(int *)((char *)a0 + 0x1644) |= 0x800000;
}

__attribute__((section(".text.cEm00_ckBananaDance")))
int cEm00_ckBananaDance(void *a0) {
    if (*(int *)((char *)a0 + 0x16D4) & 0x2000000) return 1;
    return 0;
}

__attribute__((section(".text.cEm00_setR608EventEnd")))
void cEm00_setR608EventEnd(void *a0) {
    *(unsigned char *)((char *)a0 + 0x2F5) = 0x68;
    *(unsigned char *)((char *)a0 + 0x2F6) = 0x4;
    *(unsigned char *)((char *)a0 + 0x2F4) = 0;
    *(unsigned char *)((char *)a0 + 0x2F7) = 0;
}

__attribute__((section(".text.cEm00_setNeckMoveOff")))
void cEm00_setNeckMoveOff(void *a0) {
    *(int *)((char *)a0 + 0x16D4) |= 0x80000000;
}

__attribute__((section(".text.cEm00_setNeckMoveOn")))
void cEm00_setNeckMoveOn(void *a0) {
    *(int *)((char *)a0 + 0x16D4) &= 0x7FFFFFFF;
}

