/* include/godhand/adxbObj.h - the ADXB decoder object seen by the format dispatcher (CRI libadxe, 0x33D720..0x33DBD8).
 *
 * The same 0x104-byte object as ADX_BASIC in criStm.h, but named from the
 * decode-step side: 0x98 holds the stream format id that picks the parser and
 * 0xFC an optional hook run after the parse. Field names are ours, taken from
 * the matched dispatcher; offsets are exact. A field nobody has named yet
 * stays as unkNNN padding.
 */
#ifndef GODHAND_ADXBOBJ_H
#define GODHAND_ADXBOBJ_H

#define ADXB_FMT_NONE    0     /* header not parsed yet */
#define ADXB_FMT_AIFF    1
#define ADXB_FMT_ADX_A   2
#define ADXB_FMT_ADX_B   3
#define ADXB_FMT_AIX     4
#define ADXB_FMT_WAV     0xA
#define ADXB_FMT_SOFDEC  0xF

typedef struct AdxbDisp {
    char unk00[0x98];
    short fmt;                          /* 0x98 stream format id, ADXB_FMT_* */
    char unk9A[0xFC - 0x9A];
    void *hook;                         /* 0xFC non-null: run the scaled field call */
    char unk100[4];
} AdxbDisp;                             /* 0x104 */

extern void func_0033D720(AdxbDisp *adx);
extern void Tramp_003E9D30_0033C4C0(AdxbDisp *adx);
extern void func_0033DBD8(AdxbDisp *adx);
extern void func_00341458(AdxbDisp *adx);
extern void func_00341EC0(AdxbDisp *adx);
extern void func_0033E5C0(AdxbDisp *adx);
extern void func_0033C2C0(AdxbDisp *adx);
extern void Obj0000_Call_FnFC_Field_100_94_90_Scaled(AdxbDisp *adx);

#endif
