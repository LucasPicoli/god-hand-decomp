/* include/godhand/adxm.h - the ADX manager threads (cygnus code at 0x324C90..).
 *
 * Prototypes match the definitions in 003252f8.c.
 */
#ifndef GODHAND_ADXM_H
#define GODHAND_ADXM_H

extern int adxm_ResumeThread(int thid);
extern int adxm_SuspendThread(int thid);     /* server suspend */
extern void func_00325290(int thid);
extern void SVM_CallErr1(const char *msg);

extern int D_003C80B0;                  /* ADX thread priority */
extern int D_003C80E0;                  /* lock nesting count */
extern volatile int D_003C80E4;         /* server busy */
extern volatile int D_003C814C, D_003C8140, D_003C8138;    /* server thread ids */
extern int D_003CF9D0;                  /* caller's priority before the lock */
extern int D_003CF9D4;                  /* caller's thread id */

/* One ADX decoder slot (four of them at D_003D1E70). */
typedef struct AdxDecSlot {
    signed char used;           /* 0x00 */
    signed char unk01;          /* 0x01 */
    signed char n;              /* 0x02 */
    signed char unk03;          /* 0x03 */
    signed char unk04;          /* 0x04 */
    char unk05[0x17];
    int arg;                    /* 0x1C */
    int h[(0x1964 - 0x20) / 4]; /* 0x20 */
} AdxDecSlot;

extern AdxDecSlot D_003D1E70[4];

#endif
