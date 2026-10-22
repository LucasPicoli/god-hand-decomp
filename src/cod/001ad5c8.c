/* sn-2.95.3-136: func_001AD5C8, two-phase gimmick move: on a trigger start the rise or the slide with its sound,
 * then run the move and reset the phase bytes when it ends. */
#include "godhand/cOmBase.h"
extern unsigned char D_005FEE00[];
extern char D_00747B00[];
extern void cOmSub_initMove3_y(char *mv, unsigned char *p, int a2, void *a3, float f12, float f13, float f14);
extern void cOmSub_initMove1_pos(char *mv, char *p, int a2, int a3, void *pos, float f12, float f13);
extern void cOmSub_setVibration(void *mv, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(char *mv);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, void *f, int g, int h);

static inline void *getPart(char *p, int i)
{
    int frame[3];

    return cOmBase_childAt((cOmBase *)p, frame, i);
}

static inline void movePart(char *p)
{
    float v[4];
    float z;

    v[0] = 0.0f;
    v[1] = *(float *)(p + 0x790);
    v[2] = 0.0f;
    v[3] = 1.0f;
    z = v[0];
    cOmSub_initMove1_pos(p + 0x630, p, -1, 0x3C, v, 0.2f, z);
    cOmSub_setVibration(p + 0x630, 0, 5, z, 1.0f, 2.0f);
}

static inline void resetPart(char *p)
{
    *(unsigned char *)(p + 0x2F4) = 0;
    *(unsigned char *)(p + 0x2F5) = 0;
    *(unsigned char *)(p + 0x2F6) = 0;
    *(unsigned char *)(p + 0x2F7) = 0;
}

__attribute__((section(".text.func_001AD5C8")))
void func_001AD5C8(char *p)
{
    switch (*(unsigned char *)(p + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(p + 0x60D) == 0) {
            resetPart(p);
            break;
        }
        *(unsigned char *)(p + 0x60E) = 1;
        if (*(int *)(p + 0x600) == 0) {
            cOmSub_initMove3_y(p + 0x630, p, -1, D_00747B00, -0.02f, -*(float *)(p + 0x790), 0.2f);
        } else {
            movePart(p);
        }
        *(int *)(p + 0x5B8) |= 0x100;
        if (getPart(p, 1))
            *(int *)((char *)getPart(p, 1) + 0x104) = 0;
        if (getPart(p, 2))
            *(int *)((char *)getPart(p, 2) + 0x104) = 0;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
        *(unsigned char *)(p + 0x2F5) = 1;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x82, p, 0, 0, 0, 0);
    case 1:
        if (cOmSub_move(p + 0x630))
            return;
        *(unsigned char *)(p + 0x60D) = 0;
        *(unsigned char *)(p + 0x60E) = 0;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x83, p, 0, 0, 0, 0);
        resetPart(p);
        break;
    }
}
