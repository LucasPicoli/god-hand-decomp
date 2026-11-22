/* include/godhand/PanelObj.h - the poker table's menu panel: a cIDBase of
 * on-screen ID elements (at 0x10) and the CustomIDWork that animates each
 * one. func_001DEC70 builds it: it clears word 0, constructs the cIDBase at
 * 0x10 and the 17 elements from 0x60, 0x7C bytes apart.
 *
 * The class name is ours. Offsets are exact; fields nobody has named stay as
 * unkNN padding.
 */
#ifndef GODHAND_PANELOBJ_H
#define GODHAND_PANELOBJ_H

#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"

#define PANEL_ELEM_NUM    0x11

typedef struct PanelObj {
    int unk00;                          /* 0x00 cleared by func_001DEC70 */
    char unk04[0x10 - 4];
    cIDBaseObj id;                      /* 0x10 the elements' display */
    char unk58[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[PANEL_ELEM_NUM];  /* 0x60 */
} PanelObj;                             /* 0x89C */

typedef char PanelObj_size_check[(sizeof(PanelObj) == 0x89C) ? 1 : -1];

#endif
