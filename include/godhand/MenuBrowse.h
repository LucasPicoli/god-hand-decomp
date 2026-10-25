/* include/godhand/MenuBrowse.h - the file-browser menu (sn code at 0x37E4C0).
 *
 * MenuBrowse shows a list of entries (g++ strings, 8 bytes each) ten at a
 * time. `cursor` is the picked entry, `top` the first entry of its page.
 * The pad moves the cursor up and down with wrap-around, and the shoulder
 * buttons step whole pages. `sub` is a second index from 0 to 9.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_MENUBROWSE_H
#define GODHAND_MENUBROWSE_H

#include "godhand/menuCtl.h"

#define MENUBROWSE_PAGE      10         /* entries per page */
#define MENUBROWSE_SUB_MAX   9
#define MENUBROWSE_STATE_PICKED  12     /* state: an entry was picked */

#define MENUBROWSE_TRG_SUB_UP    0x4
#define MENUBROWSE_TRG_SUB_DOWN  0x8
#define MENUBROWSE_TRG_PAGE_DOWN 0x2000
#define MENUBROWSE_TRG_PAGE_UP   0x8000

/* The entry list: a vector of 8-byte entries between begin and end. */
typedef struct MenuBrowseList {
    char unk00[0x14];
    char *begin;                        /* 0x14 */
    char *end;                          /* 0x18 one past the last entry */
} MenuBrowseList;

typedef struct MenuBrowse {
    unsigned char unk00, unk01;
    unsigned char state;                /* 0x02 */
    unsigned char unk03, unk04;
    unsigned char sub;                  /* 0x05 */
    char unk06[2];
    unsigned int top;                   /* 0x08 first entry of the shown page */
    unsigned int cursor;                /* 0x0C picked entry */
    MenuBrowseList *list;               /* 0x10 */
} MenuBrowse;

#endif
