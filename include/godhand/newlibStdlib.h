/* include/godhand/newlibStdlib.h - newlib string conversions, multibyte decoding and ctype table (sn code at 0x3A7C28..).
 *
 * Names are newlib's.
 */
#ifndef GODHAND_NEWLIBSTDLIB_H
#define GODHAND_NEWLIBSTDLIB_H

struct _reent;

extern unsigned char D_0045F039[];      /* _ctype_ + 1: bit 1 upper, 2 lower, 4 digit, 8 space */
extern int D_003FAE28;                  /* __mb_cur_max */

int func_003A7C28(int a0);                                                              /* atof, as defined in 00150078.c */
double func_003A80E8(struct _reent *ptr, const char *s, char **endptr);                 /* _strtod_r */
int func_003A8FE0(int a0, int a1);                                                      /* strtod, as defined in 00150048.c */
unsigned long func_003A9018(struct _reent *rptr, const char *nptr, char **endptr, int base);  /* _strtoul_r */
int func_003A9228(int a0, int a1, int a2);                                              /* strtoul, as defined in 0014e598.c */
long func_003ACE90(struct _reent *rptr, const char *nptr, char **endptr, int base);     /* _strtol_r */
int func_003AD0C0(int a0, int a1, int a2);                                              /* strtol, as defined in 0014e598.c */

#endif /* GODHAND_NEWLIBSTDLIB_H */
