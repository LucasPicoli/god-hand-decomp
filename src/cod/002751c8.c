/* cygnus-2.96 matched TU. */

__attribute__((section(".text.cSceAtManager_SetDoorFunc")))
void cSceAtManager_SetDoorFunc(int u, unsigned char *p, int a, int b) {
    if (p != 0) {
        if (p[0x35] == 1) {
            *(int *)(p + 0x74) = a;
            *(int *)(p + 0x70) = b;
        }
    }
}

__attribute__((section(".text.cEm00_setR302Switch")))
void cEm00_setR302Switch(unsigned char *p) {
    int v = 0x8F;
    if ((*(int *)(p + 0x564) ^ 0x252) == 0) {
        p[0x2F7] = 0;
        p[0x2F4] = 0;
        p[0x2F6] = 0;
        p[0x2F5] = v;
    }
}
