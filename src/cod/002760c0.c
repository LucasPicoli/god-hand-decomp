/* sn-2.95.3-136 matched TU. */

extern int cCoreSave_getGameLevel(void *a0);
extern char D_004479A0[];
extern char D_00569B70[];

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.cEm00__offSunglass")))
void cEm00__offSunglass(void *a0) {
    char *s0 = (char *)a0;
    char *r;

    if ((*(int *)(s0 + 0x564) ^ 0x256) != 0) {
        return;
    }
    r = (char *)func_0014B730(a0, D_004479A0);
    if (r != 0) {
        *(int *)(r + 0x380) |= 1;
    }
    *(int *)(s0 + 0x174C) = 0;
    *(int *)(s0 + 0x16D4) |= 0x4000000;
    *(float *)(s0 + 0x1750) = 300.0f;
    switch (cCoreSave_getGameLevel(D_00569B70)) {
    default:
    case 1:
        *(float *)(s0 + 0x1750) = 300.0f;
        break;
    case 2:
        *(float *)(s0 + 0x1750) = 450.0f;
        break;
    case 3:
        *(float *)(s0 + 0x1750) = 600.0f;
        break;
    case 4:
        *(float *)(s0 + 0x1750) = 600.0f;
        break;
    case 5:
        *(float *)(s0 + 0x1750) = 600.0f;
        break;
    }
    *(unsigned char *)(s0 + 0x2F5) = 0x8D;
    *(unsigned char *)(s0 + 0x2F4) = 0;
    *(unsigned char *)(s0 + 0x2F6) = 0;
    *(unsigned char *)(s0 + 0x2F7) = 0;
}
