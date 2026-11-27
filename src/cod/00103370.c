/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"

extern void *Getplayer(void);
extern void cSnd_DieDemoStart(void *a0);
extern void func_0012C348(void *a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern unsigned int D_00747A24;

__attribute__((section(".text.func_00103370")))
void func_00103370(void *a0)
{
    cGameObj *s2 = a0;
    char *s3;
    char *v0;
    int p1, p2;
    float one;

    s3 = (char *)Getplayer();
    s2->hitFlash = 30.0f;
    switch (s2->step) {
    case 0:
        v0 = s2->pack;
        p1 = *(int *)(v0 + 0x4C) + (int)v0;
        p2 = *(int *)(v0 + 0x50) + (int)v0;
        cSnd_DieDemoStart(&D_005FEE00);
        cCoreSave_dropLevelPoint(&D_00569B70);
        func_0012C348(s3, 3);
        func_002A8578(s2, p1, p2, 2, 0.0f, 0, 0);
        SetEffect(0, 0x53, a0, 0, -1, EFFECT_FOLLOW_OWNER);
        *(int *)((char *)s2 + 0x1490) = 0x82;
        s2->step = s2->step + 1;
    case 1:
        if (*(int *)((char *)s2 + 0x1490) != 0) {
            *(int *)((char *)s2 + 0x1490) = *(int *)((char *)s2 + 0x1490) - 1;
        } else {
            D_00747A24 = D_00747A24 | 8;
        }
        if (moveMotion(s2) != 0) {
            D_00747A24 = D_00747A24 | 8;
            s2->step = s2->step + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s2, one);
        cObjBase_addNullSpeed(s2, one);
        break;
    case 2:
        break;
    }
}
