/* TU: cOmSub [object] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cOmSub.h"

struct cOmSub_move_entry { short off; short pad; int (*fn)(); };
extern struct cOmSub_move_entry D_00429D80[3];

extern void func_001C6968(void *a, int n, void *v, float w, float h);
extern void func_001C6A60(void *a, int n, void *v, float w, float h, int fl);

__attribute__((section(".text.cOmSub_move")))
int cOmSub_move(char *a0) {
    struct cOmSub_move_entry tbl[3];
    int idx;
    if (*(int *)(a0 + 0x8) == 0) return 0;
    memcpy(tbl, D_00429D80, 0x18);
    idx = *(unsigned char *)(a0 + 0x2);
    return tbl[idx].fn(a0 + tbl[idx].off);
}

__attribute__((section(".text.cOmSub_initMove1_pos")))
void cOmSub_initMove1_pos(char *dst, char *obj, int idx, int a3, void *a4, float w, float h)
{
    char hold[16];
    char *e;

    if (obj != 0) {
        if (idx >= 0) {
            int cnt;
            char *r;

            cnt = *((unsigned char *) (obj + 0x2B4));
            *((int *) hold) = cnt;
            if (idx < cnt) {
                r = *((char **) (*((char **) (obj + 0x278)) + idx * 4));
            } else {
                r = 0;
            }
            e = r;
        } else {
            e = obj;
        }
        if (e != 0) {
            float *d;
            float *s;

            *((int *) (dst + 0x4)) = (int) obj;
            *((int *) (dst + 0x8)) = (int) e;
            if (idx >= 0) {
                *((int *) (dst + 0x40)) = *((int *) (e + 0xD0));
            } else {
                *((int *) (dst + 0x40)) = *((int *) (e + 0xF0));
            }
            s = *((float **) (dst + 0x40));
            d = (float *) (dst + 0x70);
            if (d != s) {
                *((float *) (dst + 0x70)) = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            d = (float *) (dst + 0x80);
            s = (float *) (e + 0x100);
            if (d != s) {
                *((float *) (dst + 0x80)) = *((float *) (e + 0x100));
                d[1] = s[1];
                d[2] = s[2];
            }
        }
    }
    func_001C6968(dst, a3, a4, w, h);
}

__attribute__((section(".text.cOmSub_initMove1_ang")))
void cOmSub_initMove1_ang(char *dst, char *obj, int idx, int a3, void *a4, float w, float h, int a5)
{
    char hold[16];
    char *e;

    a5 |= 2;
    if (obj != 0) {
        if (idx >= 0) {
            int cnt;
            char *r;

            cnt = *((unsigned char *) (obj + 0x2B4));
            *((int *) hold) = cnt;
            if (idx < cnt) {
                r = *((char **) (*((char **) (obj + 0x278)) + idx * 4));
            } else {
                r = 0;
            }
            e = r;
        } else {
            e = obj;
        }
        if (e != 0) {
            float *d;
            float *s;

            *((int *) (dst + 0x4)) = (int) obj;
            *((int *) (dst + 0x8)) = (int) e;
            if (idx >= 0) {
                *((int *) (dst + 0x40)) = *((int *) (e + 0xD0));
            } else {
                *((int *) (dst + 0x40)) = *((int *) (e + 0xF0));
            }
            s = *((float **) (dst + 0x40));
            d = (float *) (dst + 0x70);
            if (d != s) {
                *((float *) (dst + 0x70)) = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            d = (float *) (dst + 0x80);
            s = (float *) (e + 0x100);
            if (d != s) {
                *((float *) (dst + 0x80)) = *((float *) (e + 0x100));
                d[1] = s[1];
                d[2] = s[2];
            }
        }
    }
    func_001C6A60(dst, a3, a4, w, h, a5);
}

INCLUDE_ASM("nonmatching", cOmSub_setEndPos);

/* Set the walking direction of the move record (1 = backwards): store the
 * flag, load the current pair from the end pair (swapped when reversed), run
 * the two recompute steps, then recalculate the model parts. */

extern void func_001C7138(cOmSub *self);
extern void func_001C7310(cOmSub *self);
extern void cModel_calcParts(void *model);

__attribute__((section(".text.cOmSub_setReverse")))
void cOmSub_setReverse(cOmSub *self, int reverse) {
    unsigned int i;
    void **part;
    if (reverse == COMSUB_REVERSED)
        self->reverse = reverse;
    else
        self->reverse = 0;
    self->mode = 0;
    if (reverse == COMSUB_REVERSED) {
        self->curA = self->endB;
        self->curB = self->endA;
    } else {
        self->curA = self->endA;
        self->curB = self->endB;
    }
    func_001C7138(self);
    func_001C7310(self);
    if (self->obj != 0) {
        cModel_calcParts(self->obj);
        part = self->part;
        for (i = 0; i < COMSUB_PART_COUNT; i++, part++) {
            if (*part != 0)
                cModel_calcParts(*part);
        }
    }
}
