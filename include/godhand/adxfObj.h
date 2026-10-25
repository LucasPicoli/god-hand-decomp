/* include/godhand/adxfObj.h - the 0x44-byte slots of the ADXF object pool (CRI libadxe).
 *
 * D_003EAEC8 holds 16 slots. func_00323478 hands out the first slot whose
 * first byte is 0. Field names are ours, taken from the constructor; offsets
 * are exact. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_ADXFOBJ_H
#define GODHAND_ADXFOBJ_H

#define ADXFOBJ_NUM        16
#define ADXFOBJ_STRIDE     0x44
#define ADXFOBJ_BUF_LEN    0x100
#define ADXFOBJ_STATE_USED 1
#define ADXFOBJ_DEF_PARAM  0x200

typedef struct AdxfObj {
    signed char used;                   /* 0x00 0 = free slot */
    signed char kind;                   /* 0x01 */
    signed char flag02;                 /* 0x02 */
    signed char flag03;                 /* 0x03 */
    void *buf;                          /* 0x04 allocated ADXFOBJ_BUF_LEN bytes */
    int unk08;                          /* 0x08 */
    char unk0C[0xC];
    int unk18;                          /* 0x18 */
    int unk1C;                          /* 0x1C */
    int unk20;                          /* 0x20 */
    char unk24[8];
    int param;                          /* 0x2C */
    char unk30[0x14];
} AdxfObj;                              /* 0x44 */

extern AdxfObj *func_00323478(void);
extern void *func_00327D00(int a, int len);
extern void func_0033F130(const char *msg);
extern char D_004515E8[];
extern char D_00451620[];

#endif
