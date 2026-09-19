/* cygnus-2.96 matched TU. */

extern void *D_003F1A98;
extern void func_00368EE0();

/* cygnus-2.96, -freorder-blocks dropped; clone of M2VERR_SetCode (src/cod/0036d8e8.c) with a pointer global. */




__attribute__((section(".text.MPSLIB_SetErr")))
void *MPSLIB_SetErr(char *a0, void *a1) {
    if (a0 == 0) {
        func_00368EE0(D_003F1A98);
    } else {
        func_00368EE0(a0 + 0x4);
    }
    return a1;
}

/* cygnus-2.96, -freorder-blocks dropped; CRI libadxe adx_baif.o ADXB_CheckAiff. */

typedef signed char Sint8;
typedef signed int  Sint32;

extern char D_00456918[];   /* "FORM" */
extern char D_00456920[];   /* "AIFF" */
extern int func_003A50B4(const void *a, const void *b, int n);   /* memcmp */

__attribute__((section(".text.func_0033E558")))
Sint32 func_0033E558(Sint8 *ibuf)
{
    if (func_003A50B4(ibuf, D_00456918, 4) == 0 && func_003A50B4(ibuf + 8, D_00456920, 4) == 0) {
        return 1;
    }
    return 0;
}

/* cygnus-2.96, -freorder-blocks dropped; CRI libadxe adx_baif.o ADXB_CheckAiff. */

typedef signed char Sint8;
typedef signed int  Sint32;

extern char D_00457040[];   /* "FORM" */
extern char D_00457048[];   /* "AIFF" */
extern int func_003A50B4(const void *a, const void *b, int n);   /* memcmp */

__attribute__((section(".text.func_00340E90")))
Sint32 func_00340E90(Sint8 *ibuf)
{
    if (func_003A50B4(ibuf, D_00457040, 4) == 0 && func_003A50B4(ibuf + 8, D_00457048, 4) == 0) {
        return 1;
    }
    return 0;
}
