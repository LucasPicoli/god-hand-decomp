/* include/godhand/cGame.h - cGame, the main game object.
 *
 * cGame owns the frame: gameLoop runs once per frame, steps the scene
 * (func_002A6FF8), handles the sub screen request, runs the object move
 * and draw passes and measures the frame time with the EE timer register.
 * Two short counters near the end of the record count frames down: one
 * (0x1B0) holds the sub screen back, the other (0x1B2) holds the active
 * heap release.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CGAME_H
#define GODHAND_CGAME_H

#define CGAME_TIMER_COUNT  0x10000800   /* EE timer 0 count register */

typedef struct cGame {
    char unk000[0x1B0];
    short subScrWait;                   /* 0x1B0 frames left before the sub screen may open */
    short heapWait;                     /* 0x1B2 frames left before the active heap is released */
} cGame;

#endif
