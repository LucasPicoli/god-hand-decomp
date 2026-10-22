/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern void UpdateObjByIndexedOp_2FBE50(void *slot);
extern char D_005FEE00[];
extern void cOmBase_setMeshDispFromLayer(cOmBase *self, int layer, int on);
extern int SetEffect(int effNo, int kind, void *obj, int a3, int a4, unsigned int a5);
extern int cSnd_SeCall_2CBA48(void *snd, int a1, int a2, void *obj, int a4, int a5, int a6, int a7);
#include "godhand/objField.h"
extern void sceVu0ApplyMatrix(void *out, void *mtx, void *vec);
extern float LengthPositionToGivenLine(void *line, void *pos, void *dir, int *flag);
extern void func_003039E8(void *slot, int a0, int a1);

/* sn-2.95.3-136 */

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: slot paused */
extern int D_0071B8C0[];                /* bit set: slot hidden */
extern unsigned char D_0061B7C0[];      /* the 0x400 effect slots, 0x400 bytes each */

#define ESP_SLOT_NUM     0x400
#define ESP_SLOT_SIZE    0x400
#define ESP_SLOT_FLAGS   0x104          /* offset of the slot's flag word */
#define ESP_SLOT_GROUP   0x23A          /* offset of the slot's group number (short) */
#define ESP_SLOT_SUBGRP  0x23C          /* offset of the slot's sub group number (unsigned short) */

/* Run the kill handler of every effect slot that is in use, neither paused nor hidden, has flag 2 set and is not in group 0xD7. */
__attribute__((section(".text.Esp_killFlaggedExceptEvent")))
void Esp_killFlaggedExceptEvent(void) {
    unsigned char *p;
    int i;
    unsigned int bit;
    int w;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0) goto next;
        if ((D_0071B840[w] & bit) != 0) goto next;
        if ((D_0071B8C0[w] & bit) != 0) goto next;
        p = D_0061B7C0 + i * ESP_SLOT_SIZE;
        if ((*(int *)(p + ESP_SLOT_FLAGS) & 2) == 0) goto next;
        if (*(short *)(p + ESP_SLOT_GROUP) == 0xD7) goto next;
        UpdateObjByIndexedOp_2FBE50(p);
next: ;
    }
}

/* sn-2.95.3-136 */

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: slot paused */
extern int D_0071B8C0[];                /* bit set: slot hidden */
extern unsigned char D_0061B7C0[];      /* the 0x400 effect slots, 0x400 bytes each */

#define ESP_SLOT_NUM     0x400
#define ESP_SLOT_SIZE    0x400
#define ESP_SLOT_FLAGS   0x104          /* offset of the slot's flag word */
#define ESP_SLOT_GROUP   0x23A          /* offset of the slot's group number (short) */
#define ESP_SLOT_SUBGRP  0x23C          /* offset of the slot's sub group number (unsigned short) */

/* Run the kill handler of every effect slot that is in use, neither paused nor hidden, and whose group and sub group numbers match. */
__attribute__((section(".text.Esp_killByGroupPair")))
void Esp_killByGroupPair(int group, int subGroup) {
    unsigned char *p;
    int i;
    unsigned int bit;
    int w;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0) goto next;
        if ((D_0071B840[w] & bit) != 0) goto next;
        if ((D_0071B8C0[w] & bit) != 0) goto next;
        p = D_0061B7C0 + i * ESP_SLOT_SIZE;
        if (*(short *)(p + ESP_SLOT_GROUP) != group) goto next;
        if (*(unsigned short *)(p + ESP_SLOT_SUBGRP) != subGroup) goto next;
        UpdateObjByIndexedOp_2FBE50(p);
next: ;
    }
}

/* sn-2.95.3-136 */







/* Switch the object's display layers: hide layers 0x2E and 0x2F, then by mode show layer 0x2E (mode 0) or 0x2F (mode 1), or for mode 4 start effect 0x298 on it and play sound effect 0x113. */
__attribute__((section(".text.cOmBase_setDispModeLayers2E")))
void cOmBase_setDispModeLayers2E(cOmBase *self, int mode)
{
    cOmBase_setMeshDispFromLayer(self, 0x2E, 0);
    cOmBase_setMeshDispFromLayer(self, 0x2F, 0);
    switch (mode) {
    case 0:
        cOmBase_setMeshDispFromLayer(self, 0x2E, 1);
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(self, 0x2F, 1);
        break;
    case 4:
        SetEffect(0x298, 6, self, 0, -1, -1);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x113, self, 0, 0, 0, 0);
        break;
    }
}

/* sn-2.95.3-136 */







/* Switch the object's display layers: hide layers 0x1E and 0x1F, then by mode show layer 0x1E (mode 0) or 0x1F (mode 1), or for mode 4 start effect 0x298 on it and play sound effect 0x113. */
__attribute__((section(".text.cOmBase_setDispModeLayers1E")))
void cOmBase_setDispModeLayers1E(cOmBase *self, int mode)
{
    cOmBase_setMeshDispFromLayer(self, 0x1E, 0);
    cOmBase_setMeshDispFromLayer(self, 0x1F, 0);
    switch (mode) {
    case 0:
        cOmBase_setMeshDispFromLayer(self, 0x1E, 1);
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(self, 0x1F, 1);
        break;
    case 4:
        SetEffect(0x298, 3, self, 0, -1, -1);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x113, self, 0, 0, 0, 0);
        break;
    }
}

/* sn-2.95.3-136 */






/* True when the distance from the line, taken from the matrix position along its turned (0, h, 0) offset, is at most k0 + k1. */
__attribute__((section(".text.Mtx_checkLineDistanceSum")))
int Mtx_checkLineDistanceSum(void *line, void *mtx, float k0, float k1, float h)
{
    char buf[0x40] __attribute__((aligned(16)));
    float *v;
    float *d;

    VU0_SQC2_VF0(buf, 0x0);
    v = (float *)(buf + 0x10);
    *(int *)(buf + 0x10) = 0;
    *(float *)(buf + 0x14) = h;
    *(int *)(buf + 0x18) = 0;
    v[3] = 1.0f;
    ForwardVec3At30_147C60(buf, mtx);
    d = (float *)(buf + 0x30);
    VU0_LQC2(4, v, 0x0);
    VU0_SQC2(4, buf, 0x30);
    sceVu0ApplyMatrix(d, mtx, d);
    VU0_LQC2(4, d, 0x0);
    VU0_SQC2(4, buf, 0x20);
    {
        float x = *(float *)(buf + 0x20);
        float y = *(float *)(buf + 0x24);
        float z = *(float *)(buf + 0x28);

        *(float *)(buf + 0x10) = x;
        *(float *)(buf + 0x14) = y;
        *(float *)(buf + 0x18) = z;
    }
    return LengthPositionToGivenLine(line, buf, v, 0) <= k0 + k1;
}

/* sn-2.95.3-136 */
extern int D_00741940[];                /* bit set: slot in use */
extern int D_00741960[];                /* bit set: slot paused */
extern int D_00741980[];                /* bit set: slot hidden */
extern unsigned char D_0071B940[];      /* the 0x100 slots, 0x260 bytes each */


#define SLOT_NUM   0x100
#define SLOT_SIZE  0x260

/* Walk the 0x100 object slots; for each live, non-paused, visible slot run its handler with (a0, a1). */
__attribute__((section(".text.Slots_runHandlerForAll")))
void Slots_runHandlerForAll(int a0, int a1)
{
    char *p;
    int i;
    unsigned int mask;
    int w;

    for (i = 0; i < SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        mask = 0x80000000u >> (i & 0x1F);
        if ((D_00741940[w] & mask) == 0) goto next;
        if ((D_00741960[w] & mask) != 0) goto next;
        if ((D_00741980[w] & mask) != 0) goto next;
        p = (char *)D_0071B940 + i * SLOT_SIZE;
        func_003039E8(p, a0, a1);
next: ;
    }
}
