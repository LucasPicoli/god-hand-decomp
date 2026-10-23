/* include/godhand/cOmSubGimmick.h - map gimmicks that run one cOmSub move when triggered.
 *
 * Each record has a forward step and a reverse step in two TUs: the double swing
 * (0017b0d8, 0017b2e0), the quarter turn (0017e2f8, 0017e4c8) and the flap
 * (001a47f8, 001a49a8). Field names are ours, taken from those steps.
 */
#ifndef GODHAND_COMSUBGIMMICK_H
#define GODHAND_COMSUBGIMMICK_H

#include "godhand/cOmBase.h"

extern void cOmSub_initMove1_ang(char *dst, char *obj, int idx, int a3, void *a4, float f12, float f13, int a5);
extern void cOmSub_setVibration(void *a0, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(char *a0);

/* A gimmick that swings two parts once when triggered. */
typedef struct cOmDoubleSwing {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    unsigned char triggered;            /* 0x600 set by the trigger, cleared when the swing ends */
    unsigned char swung;                /* 0x601 1 once the swing has run */
    char unk602[0x604 - 0x602];
    short timer;                        /* 0x604 frames to wait before and after the swing */
    char unk606[0x610 - 0x606];
    char moveA[0x770 - 0x610];          /* 0x610 cOmSub move work of entry 0 */
    char moveB[0x140];                  /* 0x770 cOmSub move work of entry 2 */
} cOmDoubleSwing;

/* A gimmick that turns a quarter turn once when triggered. */
typedef struct cOmQuarterTurn {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    unsigned char triggered;            /* 0x600 set by the trigger, cleared when the turn ends */
    unsigned char turned;               /* 0x601 1 once the turn has run */
    short timer;                        /* 0x602 frames to wait before and after the turn */
    char unk604[0x610 - 0x604];
    char move[0x140];                   /* 0x610 cOmSub move work */
} cOmQuarterTurn;

/* A gimmick that turns once between two angles when triggered; func_001A49A8 turns it back. */
typedef struct cOmFlap {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    char move[0x760 - 0x600];           /* 0x600 cOmSub move work */
    unsigned char triggered;            /* 0x760 set by the trigger, cleared when the turn ends */
    unsigned char turned;               /* 0x761 1 once the turn has run */
    char unk762[0x794 - 0x762];
    float angA;                         /* 0x794 angle at one end */
    float angB;                         /* 0x798 angle at the other end */
    short timer;                        /* 0x79C frames to wait before and after the turn */
} cOmFlap;

#endif
