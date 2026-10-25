/* include/godhand/mwPlyOpen.h - the movie player handle as the open-by-name call sees it
 * (cygnus code at 0x32D868). Same object as MwPly in mwPly.h, which has no name pointer.
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_MWPLYOPEN_H
#define GODHAND_MWPLYOPEN_H

typedef struct MwPlyOpen {
    char unk000;
    unsigned char stat;         /* 0x001 1 once opened */
    char unk002[2];
    int adx;                    /* 0x004 the ADX decoder handle */
    char unk008[0x8C - 0x08];
    int sjDefault;              /* 0x08C */
    int sj;                     /* 0x090 the input joint, held as an int */
    char unk094[0x1B2 - 0x94];
    unsigned char unk1B2;       /* 0x1B2 */
    char unk1B3[0x1CC - 0x1B3];
    char *name;                 /* 0x1CC buffer the file name is copied into */
    char *nameSaved;            /* 0x1D0 the name pointer kept for the report */
    int unk1D4;                 /* 0x1D4 */
    int unk1D8;                 /* 0x1D8 */
    int unk1DC;                 /* 0x1DC */
    int ownSj;                  /* 0x1E0 */
} MwPlyOpen;

extern void Obj33F8_Tramp_0033F130_FCB0(char *msg);
extern void func_0032DBA0(MwPlyOpen *o);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);
extern char *func_003A57C4(char *dst, const char *src);
extern void func_0032F4B0(int adx, int sj);

#endif
