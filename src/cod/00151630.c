#include "godhand/cRoomSave.h"

/* sn-2.95.3-136 matched TU. */

extern char D_0076C8C0[];

typedef struct {
    unsigned long k;
    unsigned long f8;
} Slot;

/* slot[0].used. The member form picks other registers; only the raw sum matches. */

#define ROOMSAVE_SLOT0_USED_OFS 0x618

/* Is the one-shot slot named by `key` already used? Search the page's 256
 * slots for the key; 0 when the key is 0 or not found. */
__attribute__((section(".text.func_002BED08")))
int func_002BED08(cRoomSave *self, unsigned long key)
{
    cRoomSaveData *base;
    cRoomSaveSlot *t;
    unsigned int i;

    if (key == 0) return 0;
    base = self->data;
    t = base->slot;
    for (i = 0; i < ROOMSAVE_SLOT_NUM; i++) {
        if (t[i].key == key) {
            return *(unsigned char *)((char *)base + i * sizeof(cRoomSaveSlot) + ROOMSAVE_SLOT0_USED_OFS) == 1;
        }
    }
    return 0;
}

__attribute__((section(".text.func_0037D0A8")))
void *func_0037D0A8(int key)
{
    char *p;
    int i;

    p = D_0076C8C0;
    for (i = 0; i < 0x33; i++) {
        if (*(unsigned short *)p != 0 && (p[5] & 1) == 0 && *(int *)(p + 0x14) == key)
            return p;
        p += 0x20;
    }
    return 0;
}

__attribute__((section(".text.cDamageUnit_SetDamageCollFlashActive")))
void cDamageUnit_SetDamageCollFlashActive(char *self, int active, short val)
{
    char *p;
    char *c;

    p = *(char **)(self + 0x3C);
    while (p != 0) {
        c = *(char **)(p + 0x28);
        if (active == 1) {
            *(int *)c = *(int *)c | 2;
        } else {
            *(int *)c = *(int *)c & 0xFFFFFFFD;
        }
        *(short *)(p + 0x30) = val;
        p = *(char **)(p + 0x24);
    }
}

__attribute__((section(".text.cPadVib_setSeq")))
void cPadVib_setSeq(char *self, int seq, int a2, float f)
{
    char *base;
    char *p;
    char *q;
    unsigned int n0;

    base = *(char **)self;
    q = base + 4;
    n0 = *(unsigned short *)base;
    p = q + seq * 4;
    *(char **)(self + 4) = p;
    q += n0 * 4;
    q += *(unsigned short *)(p + 2) * 4;
    *(char **)(self + 8) = q;
    q += *(unsigned char *)p * 4;
    *(int *)(self + 0x14) = seq;
    *(int *)(self + 0x18) = a2;
    *(float *)(self + 0x1C) = f;
    *(char **)(self + 0xC) = q;
    *(int *)(self + 0x20) = 0;
    *(int *)(self + 0x24) = 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00151630")))
int func_00151630(char *a0) {
    if (a0[0] == 0x54) {
        if (a0[3] == 0x33) return a0[5] == 6;
        if (a0[3] == 0x32) return 0;
        if (a0[1] == 0x4D) return 3;
    }
    return 2;
}
