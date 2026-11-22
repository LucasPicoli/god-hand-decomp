/* include/godhand/adxsjd.h - the ADX stream-joint decoder slots (cygnus code at 0x3265A8..).
 *
 * Sixteen slots of 0xAC bytes at D_003CF9F0. A slot is free while `used`
 * is 0. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_ADXSJD_H
#define GODHAND_ADXSJD_H

#include "godhand/criSj.h"

#define ADXSJD_SLOTS 16
#define ADXSJD_MAX_SJ 15        /* stream joints per slot, 0x0C..0x47 */

typedef struct AdxSjd {
    signed char used;           /* 0x00 1 while the slot is allocated */
    signed char unk01;          /* 0x01 */
    signed char nsj;            /* 0x02 number of stream joints */
    char unk03;
    void *adxb;                 /* 0x04 ADXB decoder handle */
    int owner;                  /* 0x08 creator argument */
    int sj[ADXSJD_MAX_SJ];      /* 0x0C stream joint handles */
    int unk48;                  /* 0x48 */
    int unk4C;                  /* 0x4C */
    int unk50;                  /* 0x50 */
    int unk54;                  /* 0x54 */
    char unk58[0xAC - 0x58];
} AdxSjd;

extern AdxSjd D_003CF9F0[ADXSJD_SLOTS];

/* The getters of a slot (AdxPly.sjd). */
extern int Obj3270_GetVia4_Obj33C8_14_7788(void *a0);
extern int Obj3270_GetVia4_0033CEF0_77B8(void *a0);
extern int Obj3270_GetVia4_Obj33C8_18_77E8(void *a0);

#endif
