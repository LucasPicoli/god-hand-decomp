/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef int         Sint32;

extern Sint32 strlen(const Sint8 *s);
extern Sint8 D_007588D0[32];

__attribute__((section(".text.ADXERR_ItoA")))
void ADXERR_ItoA(Sint32 val, Sint8 *str, Sint32 len)
{
    Sint32 ncol;
    Sint32 i;

    i = 0;
    while (i < 0x20) {
        str[i] = val % 10;
        val = val / 10;
        if (val == 0) {
            str[i] = 0;
            break;
        }
        i++;
    }
    ncol = strlen(D_007588D0);
    if (ncol >= len - 1) {
        ncol = len - 1;
    }
    for (i = 0; i < ncol; i++) {
        str[i] = D_007588D0[ncol - 1 - i];
    }
    str[i] = 0;
}
