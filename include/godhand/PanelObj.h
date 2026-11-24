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
#define PANEL_ELEM_LEFT   2     /* the two cursor elements (PanelObj_setCursorMode) */
#define PANEL_ELEM_RIGHT  3
#define PANEL_ELEM_UP     4     /* the two arrow elements (PanelObj_setArrowMode) */
#define PANEL_ELEM_DOWN   5

typedef struct PanelObj {
    int unk00;                          /* 0x00 cleared by func_001DEC70 */
    char unk04[0x10 - 4];
    cIDBaseObj id;                      /* 0x10 the elements' display */
    char unk58[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[PANEL_ELEM_NUM];  /* 0x60 */
} PanelObj;                             /* 0x89C */

typedef char PanelObj_size_check[(sizeof(PanelObj) == 0x89C) ? 1 : -1];

/* Show or hide the two cursor elements: mode 0 hides the first and shows the
 * second, mode 1 shows both, any other mode leaves them. */
void PanelObj_setCursorMode(PanelObj *self, unsigned char mode);
/* The same for the two arrow elements. */
void PanelObj_setArrowMode(PanelObj *self, unsigned char mode);
/* Set element 8's local x to its left (left != 0) or right x for the language. */
void func_001DF7D0(PanelObj *self, int left);

#endif
