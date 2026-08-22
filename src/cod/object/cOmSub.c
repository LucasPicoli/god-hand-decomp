/* TU: cOmSub [object] - recovered C++ class. */
#include "include_asm.h"

struct cOmSub_move_entry { short off; short pad; int (*fn)(); };
extern struct cOmSub_move_entry D_00429D80[3];

extern void func_001C6968(void *a0, int a1, int a2);
extern void func_001C6A60(void *a0, int a1, int a2, int a3);

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
void cOmSub_initMove1_pos(char *dst, char *obj, int idx, int a3, int a4)
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
    func_001C6968(dst, a3, a4);
}

__attribute__((section(".text.cOmSub_initMove1_ang")))
void cOmSub_initMove1_ang(char *dst, char *obj, int idx, int a3, int a4, int a5)
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
    func_001C6A60(dst, a3, a4, a5);
}

INCLUDE_ASM("nonmatching", cOmSub_setEndPos);

INCLUDE_ASM("nonmatching", cOmSub_setReverse);
