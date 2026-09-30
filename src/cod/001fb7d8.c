/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_003BA550")))
void func_003BA550(void *a0) {
    char *p = *(char **)((char *)a0 + 0x8);
    unsigned int t;
    p[0] = 0x72;
    p[1] = -8;
    p[2] = 0x1F;
    p[3] = 0x4E;
    p[4] = 1;
    p[5] = *(unsigned char *)((char *)a0 + 0x38);
    t = *(int *)((char *)a0 + 0x34) * 8;
    t = t & 0xFFFF;
    p[6] = (char)t;
    p[7] = (char)(t >> 8);
}

__attribute__((section(".text.ESLib_ESHermite")))
float ESLib_ESHermite(float t, float p0, float p1, float m0, float m1)
{
    float t2 = t * t;
    float t3 = t2 * t;
    float a = t2 * 3.0f;
    float b = t3 + t3;
    float c = t3 - t2;
    float h00 = b - a;
    float h01 = -b + a;
    float h10 = (c - t2) + t;
    return (h00 * p0 + p0) + p1 * h01 + m0 * h10 + m1 * c;
}

__attribute__((section(".text.cCoreSave_setCombo")))
void cCoreSave_setCombo(cCoreSave *self, unsigned int set, unsigned int slot, int id, int lv)
{
    char v = (char)lv;
    if (self->data == 0) return;
    if (slot >= CORESAVE_COMBO_LEN) return;
    if (set >= CORESAVE_COMBO_SETS) return;
    self->data->combo[set].id[slot] = id;
    self->data->combo[set].lv[slot] = v;
}
