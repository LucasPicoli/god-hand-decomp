/* include/godhand/stageSet.h - stage set-data mesh placement (0x31D1B0..0x31D6E0).
 *
 * A set-data group holds a count at 0x08 and offsets to its records from
 * 0x10; each record starts with the offset of its mesh. func_0031D3D0 builds
 * one object per record. Records flagged 0x400000 also queue a mesh pair
 * (D_007558A8, count in GameWork.pairNum) that func_0031D2F8 later adds
 * to a model.
 */
#ifndef GODHAND_STAGESET_H
#define GODHAND_STAGESET_H

typedef struct MeshPair {
    int a;
    int b;
} MeshPair;

typedef struct SetData {
    char unk00[0x10];
    float pos[3];               /* 0x10 */
    float rot[3];               /* 0x1C */
    float scale[3];             /* 0x28 */
    unsigned int flags;         /* 0x34 */
    char unk38[0xB];
    unsigned char unk43;        /* 0x43 */
} SetData;

typedef struct BoundingBox {
    char unk00[0x20];
} BoundingBox;

extern MeshPair D_007558A8[];   /* 32 entries */

extern void func_0031D2B8(int a, int b);
extern void func_0031D3D0(SetData *set, int mesh, int idx, unsigned char hide);
extern int func_0031D658(char *grp, unsigned char hide);
extern char *GetActiveState_149310(void);
extern BoundingBox *cBoundingBox(BoundingBox *box);   /* C++ ctor, returns this */
extern void cBoundingBox__dtor(BoundingBox *box, int mode);
extern int func_00148420(char *state, int a, int b, int flags, int n, BoundingBox *box, int arg);
extern int func_001485A0(char *state, int a, int b, int flags, int n, BoundingBox *box, int arg);
extern void cModel_addMesh(char *model, char *mesh, BoundingBox *box);

#endif
