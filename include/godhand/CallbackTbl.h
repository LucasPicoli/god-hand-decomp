/* include/godhand/CallbackTbl.h - the [8][6] callback table of the CRI libadxe error/event hooks
 * (src/cod/0033b*.c). A group holds six registrations of three words each. Field names are
 * ours, from the matched registration routine; offsets are exact.
 */
#ifndef GODHAND_CALLBACKTBL_H
#define GODHAND_CALLBACKTBL_H

#define CALLBACK_GROUP_NUM 8
#define CALLBACK_SLOT_NUM  6

typedef struct CallbackEnt {
    void *func;                         /* 0x00 0 = free slot */
    void *obj;                          /* 0x04 argument handed to func */
    void *name;                         /* 0x08 label for diagnostics */
} CallbackEnt;                          /* 0x0C */

extern CallbackEnt D_00758620[CALLBACK_GROUP_NUM][CALLBACK_SLOT_NUM];
extern char D_00455EC8[];
extern char D_00455EF0[];
extern char D_00455EF8[];
extern void func_0033B790(const char *msg);

#endif
