/* include/godhand/cCockActButton.h - cCockActButton, a cockpit id display
 * (kind 4) that keeps pointers to its 13 element entries; the first one's
 * position is mirrored at 0xA0.
 *
 * The class name is retail's: the vtable D_0041DC20 holds func_0013BC28 and
 * cCockActButton_refillEntries, and its type-info function (func_0013C1C8)
 * registers "14cCockActButton" with base "9cCockBase". The constructor
 * stores the vtable pointer at 0x80 (0x1418C0). The method and field names
 * are ours.
 */
#ifndef GODHAND_CCOCKACTBUTTON_H
#define GODHAND_CCOCKACTBUTTON_H

#include "godhand/cIDBase.h"

#define COCKACTBUTTON_WORK_NUM  13

typedef struct cCockActButton {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x80 - sizeof(cIDBaseObj)];
    void *vtable;                       /* 0x80 */
    char unk84[0x90 - 0x84];
    int unk90;                          /* 0x90 */
    unsigned char active;               /* 0x94 bit 0: the display runs */
    unsigned char step;                 /* 0x95 which element group is shown, 0..6 */
    char unk96[0xA];
    float x;                            /* 0xA0 */
    float y;                            /* 0xA4 */
    char unkA8[8];
    cIDBaseEnt *work[COCKACTBUTTON_WORK_NUM]; /* 0xB0 */
    int msg;                            /* 0xE4 message id for elements 7 and 8, -1 = none */
} cCockActButton;

typedef char cCockActButton_vtable_check[(int)&((cCockActButton *)0)->vtable == 0x80 ? 1 : -1];
typedef char cCockActButton_msg_check[(int)&((cCockActButton *)0)->msg == 0xE4 ? 1 : -1];

#endif /* GODHAND_CCOCKACTBUTTON_H */
