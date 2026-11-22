/* include/godhand/cCockGameOver.h - cCockGameOver, a cockpit cIDBase display
 * with 11 entries and a second display at 0xD0 driven by five CustomIDWorks.
 *
 * The class name is retail's: the vtable D_0041DF60 holds func_0013D400 and
 * func_0013D540, and its type-info function (func_0013DF20) registers
 * "13cCockGameOver" with base "9cCockBase". The constructor stores the
 * vtable pointer at 0x80 (0x1416D4). The method and field names are ours.
 */
#ifndef GODHAND_CCOCKGAMEOVER_H
#define GODHAND_CCOCKGAMEOVER_H

#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"

#define COCKGAMEOVER_ENT_NUM  11
#define COCKGAMEOVER_CW_NUM   5

typedef struct cCockGameOver {
    cIDBaseObj base;                        /* 0x000 */
    char unk048[0x80 - sizeof(cIDBaseObj)];
    void *vtable;                           /* 0x080 */
    char unk084[0x90 - 0x84];
    unsigned char on;                       /* 0x090 */
    char unk091;
    short unk92;                            /* 0x092 */
    cIDBaseEnt *ent[COCKGAMEOVER_ENT_NUM];  /* 0x094 */
    char unk0C0[0xD0 - 0xC0];
    cIDBaseObj base2;                       /* 0x0D0 */
    char unk118[0x120 - 0x118];
    CustomIDWork cw[COCKGAMEOVER_CW_NUM];   /* 0x120 */
    char unk38C;                            /* 0x38C */
} cCockGameOver;

typedef char cCockGameOver_vtable_check[((int)&((cCockGameOver *)0)->vtable == 0x80) ? 1 : -1];
typedef char cCockGameOver_cw_check[((int)&((cCockGameOver *)0)->cw == 0x120) ? 1 : -1];

#endif /* GODHAND_CCOCKGAMEOVER_H */
