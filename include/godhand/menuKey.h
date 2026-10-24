/* include/godhand/menuKey.h - the menu keys in the pad words of D_007474A0 (trg, rep)
 * and the menu sound effects.
 *
 * Each direction sets one bit for the pad and one for the stick. The options panels
 * (00166bb8.c, 00167908.c) move through their rows with UP and DOWN and change the
 * picked setting with LEFT and RIGHT, which is how these names were assigned.
 */
#ifndef GODHAND_MENUKEY_H
#define GODHAND_MENUKEY_H

#define MENU_KEY_UP         0x0001000001000000L
#define MENU_KEY_DOWN       0x0002000002000000L
#define MENU_KEY_LEFT       0x0004000008000000L
#define MENU_KEY_RIGHT      0x0008000004000000L
#define MENU_KEY_LEFTRIGHT  (MENU_KEY_LEFT | MENU_KEY_RIGHT)
#define MENU_KEY_OK         0x10000000L
#define MENU_KEY_BACK       0x20000000L
#define MENU_KEY_CLOSE      0x200000L

#define MENU_SE_MOVE        0x15F
#define MENU_SE_OK          0x15E
#define MENU_SE_BACK        0x161

#endif
