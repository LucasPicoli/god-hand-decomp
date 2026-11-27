/* include/godhand/vblank.h - state shared with the vblank handler (func_0030B148). */
#ifndef GODHAND_VBLANK_H
#define GODHAND_VBLANK_H

/* Vblanks counted by the handler; the wait loop at 0x30AD7C reloads it each pass and
 * compares it unsigned (sltu). */
extern volatile unsigned int D_00753D80;
/* Nonzero while the packet waits to go. */
extern int D_00753D84;
/* The packet the handler sends to GIF (0x1000 bytes). */
extern char D_00752D80[];

#endif /* GODHAND_VBLANK_H */
