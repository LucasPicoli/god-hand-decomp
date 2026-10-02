/* include/godhand/cOm53.h - cOm53, a lift that carries enemies.
 *
 * cOm53 builds on the cOmBase record (0x5E0 bytes). Its riders sit in a
 * ring of 16 one-byte slots at 0x600 (0xFF = empty) that starts at `head`.
 * setGetOnEm puts an enemy id in the first empty slot and counts it,
 * setGetOffEm adds to the count of riders that got off.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_COM53_H
#define GODHAND_COM53_H

#include "godhand/cOmBase.h"

#define COM53_RIDER_NUM    0x10
#define COM53_RIDER_NONE   0xFF

/* The handle of a released rider on the stack: the enemy number in byte 0,
 * resolved to the actor by the cEmWrap methods. */
typedef struct cOm53Wrap {
    unsigned char em;                   /* 0x00 */
    char unk01[3];
    void *actor;                        /* 0x04 */
} cOm53Wrap;

typedef struct cOm53 {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    unsigned char rider[COM53_RIDER_NUM]; /* 0x600 enemy id per slot, COM53_RIDER_NONE = empty */
    unsigned char head;                 /* 0x610 first slot of the ring */
    char unk611;
    unsigned char riderNum;             /* 0x612 riders on board */
    char unk613[2];
    unsigned char getOffNum;            /* 0x615 riders that got off */
    char unk616[0xA];
    float downPos;                      /* 0x620 */
    char unk624[4];
    int riseWaitTime;                   /* 0x628 */
} cOm53;

typedef char cOm53_size_check[(sizeof(cOm53) == 0x630) ? 1 : -1];

#endif
