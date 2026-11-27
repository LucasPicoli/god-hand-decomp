/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern int moveMotion(void *a0);
extern void func_0012C540(void *a0, int a1);

/* sn-2.95.3-136 candidate. */









__attribute__((section(".text.func_0011A660")))
void func_0011A660(void *a0)
{
    cGameObj *s0 = a0;

    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    s0->hitFlash = 2.0f;
    switch (s0->step) {
    case 0:
    {
        int b = *(int *)((char *)s0 + 0x304);

        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        func_002A8578(s0, *(int *)(b + 0x6F0) + b, *(int *)(b + 0x6F4) + b,
                      3, 0.0f, 0, 0);
        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        s0->step = s0->step + 1;
    }
    case 1:
        if (moveMotion(s0) == 0) {
            return;
        }
        func_0012C540(s0, 1);
        s0->step = s0->step + 1;
        s0->objFlags = s0->objFlags | 2;
        {
            char *p = *(char **)((char *)s0 + 0x68C);

            if (p != 0) {
                *(int *)(p + 0x250) = *(int *)(p + 0x250) | 2;
            }
        }
        break;
    case 2:
    {
        int b = *(int *)((char *)s0 + 0x304);

        func_002A8578(s0, *(int *)(b + 0x28) + b, *(int *)(b + 0x2C) + b,
                      3, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    }
    case 3:
        moveMotion(s0);
        *(int *)((char *)s0 + 0x15F4) = *(int *)((char *)s0 + 0x15F4) | 0x1000;
        s0->objFlags = s0->objFlags | 2;
        {
            char *p = *(char **)((char *)s0 + 0x68C);

            if (p != 0) {
                *(int *)(p + 0x250) = *(int *)(p + 0x250) | 2;
            }
        }
        break;
    case 4:
    {
        int b = *(int *)((char *)s0 + 0x304);

        *(short *)((char *)s0 + 0x5E0) = 0;
        *(short *)((char *)s0 + 0x5E2) = 0;
        func_002A8578(s0, *(int *)(b + 0x6F8) + b, *(int *)(b + 0x6FC) + b,
                      0, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    }
    case 5:
        if (moveMotion(s0) == 0) {
            return;
        }
        s0->mode = 0;
        s0->phase = 0;
        s0->step = 0;
        s0->stepArg = 0;
        break;
    }
}
