/* include/godhand/motion.h - per-motion parameter lists.
 *
 * A motion carries nParam 12-byte parameter entries. The first word of each
 * packs the parameter kind, a sub id and the index of the handler in
 * D_003BD910 that evaluates it.
 */
#ifndef GODHAND_MOTION_H
#define GODHAND_MOTION_H

typedef struct MotionParam {
    int kind : 8;               /* 0x00 */
    unsigned int sub : 4;       /* bits 8..11, -1 matches any */
    unsigned int func : 4;      /* bits 12..15, index into D_003BD910 */
    unsigned int pad : 16;
    int unk04[2];
} MotionParam;                  /* 0x0C */

typedef struct MotionData {
    char pad00[6];
    unsigned char nParam;       /* 0x06 */
    char pad07;
    MotionParam param[1];       /* 0x08 */
} MotionData;

typedef float (*MotionParamFn)(MotionData *mot, MotionParam *prm);

extern MotionParamFn D_003BD910[];

int MotionIsHaveParam(MotionData *mot, int kind, int sub);
float MotionGetParam(MotionData *mot, int kind, int sub);

/* Step the object's motion; nonzero when it ended this frame (assembly). */
int moveMotion(void *obj);

/* Start motion motA..motB (addresses in obj's resource blob) on obj at frame
 * start; sel and keep are read as 16-bit values, and func_002A84A8 runs first
 * when keep is 0. */
void func_002A8578(int obj, int motA, int motB, int mode, float start, int sel, int keep);

#endif
