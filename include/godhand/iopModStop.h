/* include/godhand/iopModStop.h - the module stop path next to the matched loader (sn code at 0x394F20).
 *
 * A module record is the RegTbl of regTbl.h; its callback at 0x1C is the stop
 * hook the unloader runs after it unlinks the record. Field names are ours;
 * offsets are exact.
 */
#ifndef GODHAND_IOPMODSTOP_H
#define GODHAND_IOPMODSTOP_H

#include "godhand/regTbl.h"

#define IOPMOD_ERR_UNKNOWN   5      /* the record is not in the list */
#define IOPMOD_ERR_UNLINK    0xB    /* unlinking its symbols failed */

/* The stop hook, stored in what regTbl.h calls unk14 (bytes 0x14..0x2F). */
typedef struct IopModStop {
    char unk00[0x1C];
    void (*stop)(void);                 /* 0x1C */
} IopModStop;

extern int D_003F8528;
extern char D_0045DC00[];
extern int func_00394D00(RegTbl *m);
extern void func_003951C0(void);
extern int func_00394668(int name, unsigned short id);
extern void func_00395180(void);
extern void func_003951D0(void);
extern void func_003951B0(void);
extern int func_003A6A20(const char *fmt, ...);

#endif
