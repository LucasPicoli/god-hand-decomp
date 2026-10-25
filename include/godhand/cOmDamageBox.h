/* include/godhand/cOmDamageBox.h - cOmDamageBox, a cOmBase object with a damage box.
 *
 * The object owns a damage-take cylinder (what the player hits) and a
 * damage-give sphere (what hurts the player), and holds its pieces as
 * children from index 1 up. The setup routine (sn code at 0x18F218) sizes
 * the give sphere by the player's current power and hides the first mesh
 * layer.
 *
 * Offsets are exact; unknown spans stay unkNNN padding.
 */
#ifndef GODHAND_COMDAMAGEBOX_H
#define GODHAND_COMDAMAGEBOX_H

#include "godhand/cOmBreakable.h"

/* The power word of the player object that sizes the give sphere. */
typedef struct cOmDamageBoxPlayer {
    char unk000[0x600];
    float power;                        /* 0x600 */
} cOmDamageBoxPlayer;

typedef struct cOmDamageBox {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x74];
    void *dmgTake;                      /* 0x654 damage-take cylinder, 0 when none */
    void *dmgGive;                      /* 0x658 damage-give sphere, 0 when none */
    unsigned char unk65C;               /* 0x65C cleared at setup */
} cOmDamageBox;

typedef char cOmDamageBox_chk_take[((int)&((cOmDamageBox *)0)->dmgTake == 0x654) ? 1 : -1];

#endif
