/* include/godhand/cOm5a.h - cOm5a, a breakable object with a face that opens.
 *
 * cOm5a is a cOmBase with a lock record, an open type, a face state, a hit
 * shake, and one take and one give from the damage manager, 0x7A0 bytes in
 * all. func_001ABE80 sets it up: the take is a sphere on the first child, the
 * give a box, and the open type follows the lock's type.
 *
 * Method names are the game's own. Field names are ours, taken from the
 * methods that read and write them. Offsets are exact: every body that uses
 * this header builds byte-identical to retail.
 */
#ifndef GODHAND_COM5A_H
#define GODHAND_COM5A_H

#include "godhand/cOmBase.h"
#include "godhand/cDamageGive.h"

/* The lock state that decides the open type. */
typedef struct cOm5aLock {
    char unk00[0x2C];
    unsigned char type;                 /* 0x2C 1: open */
} cOm5aLock;

typedef struct cOm5a {
    cOmBase base;                       /* 0x000 */
    cOm5aLock *lock;                    /* 0x5E0 */
    char unk5E4[0x600 - 0x5E4];
    int openType;                       /* 0x600 */
    float unk604;                       /* 0x604 cleared by cOm5a_setFaceOpen and setFaceClose */
    int faceState;                      /* 0x608 1 open (cOm5a_setFaceOpen), 2 closed (setFaceClose) */
    char unk60C;
    unsigned char open;                 /* 0x60D what cOm5a::isOpen returns; func_001AD0D0 sets it, func_001AD5C8 clears it */
    unsigned char active;               /* 0x60E what cOm5a::isActive returns */
    char unk60F;
    short shakeTimer;                   /* 0x610 frames of hit shake left (cOmShake_updateHeight) */
    char unk612[0x624 - 0x612];
    cDamageTake *take;                  /* 0x624 */
    cDamageGive *give;                  /* 0x628 */
    char unk62C[0x790 - 0x62C];
    float unk790;                       /* 0x790 set by func_001ADA70 */
    char unk794[0x7A0 - 0x794];
} cOm5a;                                /* 0x7A0: _MemoryAlloc(0x7A0) at 0x315ED4 */

typedef char cOm5a_size_check[(sizeof(cOm5a) == 0x7A0) ? 1 : -1];

/* Sets the open type. While open, it runs cOm5a_setCloseFix before the
 * change and cOm5a_setOpenFix after it. */
void cOm5a_setOpenType(cOm5a *self, int type);
/* Opens the face: unk604 to 0, faceState to 1. */
void cOm5a_setFaceOpen(cOm5a *self);
/* Stores x in unk790. */
void func_001ADA70(cOm5a *self, float x);

#endif
