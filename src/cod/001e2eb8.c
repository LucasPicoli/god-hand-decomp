/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/effectPos.h"
#include "godhand/cGameObj.h"

extern void LayerScreen_hideLayers(char *a0, int a1);
extern void Slot2_selectMark(char *a0, int a1, int a2, int a3);
extern void MarkObj_setMarkFlag(char *a0, int a1, int a2);
extern void displayScrollLayer(int a0, int a1);

__attribute__((section(".text.func_001E2EB8")))
void func_001E2EB8(char *a0)
{
    long v;
    int done;

    switch (*(int *)(a0 + 0xC)) {
    case 0:
        v = *(unsigned int *)(a0 + 0x54);
        *(short *)(a0 + 0x4C2) = 0xA;
        if (((v >> 8) & 1) == 0) {
            LayerScreen_hideLayers(a0, 1);
            *(int *)(a0 + 0x54) |= 0x100;
        }
        *(int *)(a0 + 0xC) += 1;
        break;
    case 1:
        Slot2_selectMark(a0, *(unsigned short *)(a0 + 0x494), 1, 1);
        MarkObj_setMarkFlag(a0, 0, 1);
        *(int *)(a0 + 0x10) = 0x78;
        *(int *)(a0 + 0xC) += 1;
        break;
    case 2:
        if (*(int *)(a0 + 0x10) != 0) {
            *(int *)(a0 + 0x10) -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            Slot2_selectMark(a0, *(unsigned short *)(a0 + 0x494), 0, 0);
            *(int *)(a0 + 0xC) += 1;
        }
        break;
    case 3:
        *(int *)(a0 + 0x4) = 0;
        *(int *)(a0 + 0x8) = 0;
        *(int *)(a0 + 0xC) = 0;
        break;
    }
}

__attribute__((section(".text.func_001E4610")))
void func_001E4610(char *a0)
{
    long v;

    if (*(int *)(a0 + 0x4B0) == 0)
        return;
    if (*(int *)(a0 + 0x4B4) == 0)
        return;
    v = *(unsigned int *)(a0 + 0x54);
    if (((v >> 9) & 1) == 0)
        return;

    *(float *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) -= 1.0f;
    *(float *)(*(int *)(*(int *)(a0 + 0x4B4) + 0xF0)) -= 1.0f;

    if (*(float *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) < -130.0f) {
        *(int *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) = 0;
        *(int *)(*(int *)(*(int *)(a0 + 0x4B4) + 0xF0)) = 0;
    }

    if (*(float *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) < -50.0f &&
        *(float *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) > -60.0f) {
        displayScrollLayer(*(int *)(a0 + 0x458), 1);
        displayScrollLayer(*(int *)(a0 + 0x488), 1);
    } else {
        displayScrollLayer(*(int *)(a0 + 0x458), 0);
        displayScrollLayer(*(int *)(a0 + 0x488), 0);
    }
}

__attribute__((section(".text.func_0027BDD8")))
void func_0027BDD8(cGameObj *a0)
{
    long v;
    int obj;
    int b, lim;
    int spill[2];

    if (a0->emNo == 0x263)
        return;
    if (a0->hp <= 0)
        return;
    if (*(int *)((char *)a0 + 0x670) == 0)
        return;
    v = *(unsigned int *)(*(int *)((char *)a0 + 0x670) + 0x60);
    if ((v & 1) == 0)
        return;
    if (0.0f < a0->hitFlash)
        return;

    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, (cObj *)a0, 0, 0, 0, 0);

    b = a0->partNum;
    spill[0] = b;
    lim = 4;
    if (lim < b)
        obj = *(int *)(*(int *)((char *)a0 + 0x278) + 0x10);
    else
        obj = 0;
    if (obj != 0)
        SetEffectPos(0x58, 0x10, 0, (void *)*(int *)(obj + 0xF0), 1.0f, -1);

    a0->hitFlash = 3.0f;
    if (a0->hpMax <= 0)
        a0->hp = *(unsigned short *)((char *)a0 + 0x548);
    else
        a0->hp = 0;
    *(char *)((char *)a0 + 0x2F4) = 2;
    *(char *)((char *)a0 + 0x2F5) = 0;
    *(char *)((char *)a0 + 0x2F6) = 0;
    *(char *)((char *)a0 + 0x2F7) = 0;
}
