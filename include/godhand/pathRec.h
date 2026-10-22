/* include/godhand/pathRec.h - a path record and the object that follows it
 * (PathHost_calcTurn and the cone factor at 0x137E70).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_PATHREC_H
#define GODHAND_PATHREC_H

typedef struct PathRec {
    char unk00[0x38];
    float endY;                         /* 0x38 */
    char unk3C[3];
    unsigned char kind;                 /* 0x3F PATH_KIND_* */
    char unk40[0x10];
    char dir[0x10];                     /* 0x50 direction vector, copied as a blob */
    float coneAngle;                    /* 0x60 */
} PathRec;

typedef struct PathHost {
    char unk00[0x10];
    float startY;                       /* 0x10 */
    char unk14[0x1C];
    PathRec *rec;                       /* 0x30 */
} PathHost;

#endif /* GODHAND_PATHREC_H */
