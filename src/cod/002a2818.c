/* sn-2.95.3-136 matched TU. */

extern char D_0059ACC8[];
extern char D_0059AFB0[];
extern char D_0059B228[];
extern char D_0059B4A0[];
extern char D_0059B718[];
extern char D_0059B990[];
extern char D_0059BC08[];

/* sn-2.95.3-136 matched TU. */









typedef struct { int w[25]; } B100;

__attribute__((section(".text.func_002A2818")))
void *func_002A2818(void *a0, int n)
{
    char *d = D_0059ACC8;
    char *s = 0;

    switch (n) {
    case 0: s = D_0059B228; break;
    case 1: s = D_0059B4A0; break;
    case 2: s = D_0059B718; break;
    case 3: s = D_0059B990; break;
    case 4: s = D_0059BC08; break;
    case 5: s = D_0059AFB0; break;
    }

    *(long *)(d + 0x0) = *(long *)(s + 0x0);
    *(B100 *)(d + 0x78) = *(B100 *)(s + 0x8);
    *(B100 *)(d + 0xDC) = *(B100 *)(s + 0x6C);
    *(B100 *)(d + 0x140) = *(B100 *)(s + 0xD0);
    *(B100 *)(d + 0x1A4) = *(B100 *)(s + 0x134);
    *(B100 *)(d + 0x274) = *(B100 *)(s + 0x198);
    *(B100 *)(d + 0x14) = *(B100 *)(s + 0x1FC);

    *(unsigned char *)(d + 0x26C) = *(unsigned char *)(s + 0x268);
    *(unsigned char *)(d + 0x10) = *(unsigned char *)(s + 0x26A);
    *(unsigned char *)(d + 0x26D) = *(unsigned char *)(s + 0x269);
    *(float *)(d + 0x8) = *(float *)(s + 0x260);
    *(float *)(d + 0xC) = *(float *)(s + 0x264);
    *(unsigned short *)(d + 0x26E) = *(unsigned short *)(s + 0x26C);
    *(unsigned short *)(d + 0x270) = *(unsigned short *)(s + 0x26E);
    *(unsigned short *)(d + 0x272) = *(unsigned short *)(s + 0x270);

    return s;
}
