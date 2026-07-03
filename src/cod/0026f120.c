/* sn-2.95.3-136 matched TU. */

extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int Forward30F348_31CFE0(void);
extern unsigned char D_005FEE00[];

__attribute__((section(".text.func_0026F120")))
int func_0026F120(void *this) {
    if (*(int *)((char *)this + 0x5B4) < 200)
        return 0;
    *(int *)((char *)this + 0x5B4) = 0;
    *(float *)((char *)this + 0x17CC) = 150.0f;
    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 140, this, 0, 0, 0, 0);
    *(char *)((char *)this + 0x621) = 0;
    switch (*(int *)((char *)this + 0x564)) {
        case 0x227: case 0x228: case 0x229: case 0x22a: case 0x22b:
        case 0x23a: case 0x243: case 0x24a: case 0x24b:
            if (Forward30F348_31CFE0() & 1)
                *(char *)((char *)this + 0x621) = 1;
            break;
        default:
            break;
    }
    return 1;
}
