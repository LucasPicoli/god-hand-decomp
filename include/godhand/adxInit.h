/* include/godhand/adxInit.h - the init record of the ADX library start-up routines (CRI libadxe, src/cod/003290.c).
 *
 * Field names are ours, taken from the init routine; offsets are exact.
 */
#ifndef GODHAND_ADXINIT_H
#define GODHAND_ADXINIT_H

typedef struct AdxInitCfg {
    int fmt;                            /* 0x00 handed to func_00335248 */
    int mode;                           /* 0x04 handed to func_00335218 */
    int flagA;                          /* 0x08 nonzero turns Forward331C98_333F60 on */
    int flagB;                          /* 0x0C nonzero turns Forward331CE0_333F80 on */
} AdxInitCfg;

extern int Forward33F130_3292C0(int a0, int a1);
extern char D_00451F50[];
extern char D_00451F58[];
extern void func_00330E70(void *fn, int arg);
extern void func_00330318(char *name, void *fn, int arg);
extern void func_00330580(char *name);
extern void func_00335218(int mode);
extern void func_00335248(int fmt);
extern void Forward331C98_333F60(int on);
extern void Forward331CE0_333F80(int on);
extern int func_00336318();
extern int func_00333FA0();

#endif
