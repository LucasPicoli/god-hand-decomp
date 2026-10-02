/* include/godhand/cMessCommon.h - cMessCommon, helpers shared by the message window code.
 *
 * Message text is a stream of 16-bit codes. A code below 0x8000 is a
 * printable character; from 0x8000 up the high byte says what the code is
 * (a control code). isPageEndCode answers whether a control code ends the
 * page, so the window stops there until the player continues.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail.
 */
#ifndef GODHAND_CMESSCOMMON_H
#define GODHAND_CMESSCOMMON_H

#define MESS_CODE_CONTROL   0x8000      /* codes from here up are control codes */
#define MESS_CODE_KIND_MASK 0xFF00      /* the high byte names the control code */

/* High bytes of the control codes that end a page. */
#define MESS_END_80   0x8000
#define MESS_END_81   0x8100
#define MESS_END_82   0x8200
#define MESS_END_83   0x8300
#define MESS_END_89   0x8900
#define MESS_END_90   0x9000
#define MESS_END_A1   0xA100
#define MESS_END_A5   0xA500
#define MESS_END_A6   0xA600
#define MESS_END_A7   0xA700
#define MESS_END_D2   0xD200
#define MESS_END_D9   0xD900
#define MESS_END_DA   0xDA00
#define MESS_END_E2   0xE200
#define MESS_END_E4   0xE400
#define MESS_END_E5   0xE500
#define MESS_END_E7   0xE700

#endif
