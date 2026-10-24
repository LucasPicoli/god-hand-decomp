/* include/godhand/cSubScr.h - the sub screen manager and its menu screens (sn code at 0x160000..0x16Cxxx).
 *
 * D_003BD930 points at the one cSubScr. It runs a stack of sub screens (the
 * pause menu, the shop, and so on); each screen is a MenuScreen embedded in
 * it, and the selN fields are those screens' selection bytes (each at 0x64 in
 * its screen). Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CSUBSCR_H
#define GODHAND_CSUBSCR_H

/* A menu screen run by the phase dispatcher ModeObj_updatePhase. */
typedef struct MenuScreen {
    char unk00[0x60];
    int next;                           /* 0x60 screen to go to, -1 = stay */
    char unk64[0x130 - 0x64];
    short cursor;                       /* 0x130 0..3 */
    char unk132[2];
    unsigned short result;              /* 0x134 0 restarts the stage at choice's start point */
    short choice;                       /* 0x136 */
} MenuScreen;

typedef struct cSubScr {
    char pad000[0x48];
    int kind;                   /* 0x48 open screen, -1 when closed */
    char pad04C[4];
    short open;                 /* 0x50 */
    char pad052[0x374 - 0x52];
    unsigned char sel374;       /* 0x374 screen 1 selection */
    char pad375[0x684 - 0x375];
    unsigned char sel684;       /* 0x684 screen 2 selection */
    char pad685[0x794 - 0x685];
    unsigned char sel794;       /* 0x794 screen 0/3 selection */
    char pad795[0x8E4 - 0x795];
    unsigned char sel8E4;       /* 0x8E4 screen 4 selection */
    char pad8E5[0xA24 - 0x8E5];
    unsigned char selA24;       /* 0xA24 screen 5 selection */
    char padA25[0xB44 - 0xA25];
    unsigned char selB44;       /* 0xB44 screen 6 selection */
    char padB45[0xC04 - 0xB45];
    unsigned char selC04;       /* 0xC04 screen 8 selection */
    char padC05[0xCA4 - 0xC05];
    unsigned char selCA4;       /* 0xCA4 screen 7 selection */
    char padCA5[0xEDC - 0xCA5];
    unsigned char unkEDC;       /* 0xEDC */
    signed char mode;           /* 0xEDD panel layout of the menus: 0 = four rows, 1 = two */
    char padEDE[2];
    unsigned int saved5D8;      /* 0xEE0 GameWork flags5D8 while open */
    unsigned int saved5E0;      /* 0xEE4 GameWork flags5E0 while open */
    int stack[11];              /* 0xEE8 kinds opened, innermost last */
    char padF14;
    unsigned char depth;        /* 0xF15 */
} cSubScr;

/* The screen of kinds 0 and 3 (its selection byte is sel794). The screens are
 * not laid out in cSubScr yet, so this one is reached by its offset. */
#define SUBSCR_SCREEN03(ss)  ((MenuScreen *)((char *)(ss) + 0x730))

extern cSubScr *D_003BD930;
extern void cSubScr_SubScrOn(cSubScr *self, int kind, unsigned char sel, unsigned char arg);

#endif /* GODHAND_CSUBSCR_H */
