/* include/godhand/cCockPrintData.h - cCockPrintData, the cockpit's gold
 * display, with a second display at 0xB0 drawn once per active slot.
 *
 * The class name is retail's: the vtable D_0041E668 holds func_00143598 and
 * func_00143998, and its type-info function (func_00143B20) registers
 * "14cCockPrintData" with base "9cCockBase". The DispMgr holds one at 0x1AE0,
 * and its constructor stores the vtable pointer at 0x80 (0x1419A0). The
 * method and field names are ours.
 */
#ifndef GODHAND_CCOCKPRINTDATA_H
#define GODHAND_CCOCKPRINTDATA_H

#include "godhand/cIDBase.h"

#define COCKPRINT_WORK_NUM  4
#define COCKPRINT_SLOT_NUM  16

typedef struct cCockPrintData {
    cIDBaseObj base;                        /* 0x000 */
    char unk048[0x80 - sizeof(cIDBaseObj)];
    void *vtable;                           /* 0x080 */
    char unk084[0x90 - 0x84];
    int gold;                               /* 0x090 the gold shown */
    cIDBaseEnt *work[COCKPRINT_WORK_NUM];   /* 0x094 work[0] shows the gold; 0 before setup */
    char unk0A4[0xB0 - 0xA4];
    cIDBaseObj base2;                       /* 0x0B0 drawn once per active slot */
    char unk0F8[0x100 - 0xF8];
    float posYOfs[COCKPRINT_SLOT_NUM];      /* 0x100 */
    unsigned int number[COCKPRINT_SLOT_NUM]; /* 0x140 the number each slot shows */
    char unk180[0x1A0 - 0x180];
    unsigned char alpha[COCKPRINT_SLOT_NUM]; /* 0x1A0 */
    unsigned char on[COCKPRINT_SLOT_NUM];   /* 0x1B0 1: the slot is drawn */
    char mode;                              /* 0x1C0 */
    char unk1C1[0x1D0 - 0x1C1];
} cCockPrintData;                           /* 0x1D0 */

typedef char cCockPrintData_vtable_check[((int)&((cCockPrintData *)0)->vtable == 0x80) ? 1 : -1];
typedef char cCockPrintData_on_check[((int)&((cCockPrintData *)0)->on == 0x1B0) ? 1 : -1];
typedef char cCockPrintData_size_check[(sizeof(cCockPrintData) == 0x1D0) ? 1 : -1];

#endif /* GODHAND_CCOCKPRINTDATA_H */
