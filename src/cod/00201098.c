/* sn-2.95.3-136 matched TU. */
#include "godhand/cDvd.h"
#include "godhand/cWorldLight.h"


extern char D_00580D40[];
extern int FindEntryValue_1FF9C0(char *table, char *name, int *size, char *key);
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, int a2);
extern void func_00200B20(cDvd *self);
/* 2 if id is the running job, 1 if it is queued, 0 if unknown. */
__attribute__((section(".text.cDvd_Check")))
int cDvd_Check(cDvd *self, int id)
{
    cDvdJob *job;
    cDvdJob *end;
    int *jobId;

    if (id == 0) {
        return 0;
    }
    end = &self->job[CDVD_JOB_NUM];
    if (self->cur != 0) {
        if (self->cur->id == id) {
            return 2;
        }
    }
    job = self->job;
    jobId = &self->job[0].id;
    do {
        if (job->state != 0) {
            if (*jobId == id) {
                return 1;
            }
        }
        job++;
        jobId = (int *)((char *)jobId + sizeof(cDvdJob));
    } while ((int)job < (int)end);
    return 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0037AD08")))
int func_0037AD08(char *a0) {
    int old;
    int t;
    t = *(unsigned char *)(a0 + 0x26);
    old = *(signed char *)(a0 + 0x26);
    if ((*(int *)(a0 + 0x2C) & 0x80) != 0) {
        return 0;
    }
    if ((*(int *)(a0 + 0x38) & 0x1000) != 0) {
        *(char *)(a0 + 0x26) = t - 1;
    }
    if ((*(int *)(a0 + 0x38) & 0x4000) != 0) {
        *(char *)(a0 + 0x26) = *(unsigned char *)(a0 + 0x26) + 1;
    }
    if (*(signed char *)(a0 + 0x26) < 0) {
        *(char *)(a0 + 0x26) = 6;
    }
    if (*(signed char *)(a0 + 0x26) >= 7) {
        *(char *)(a0 + 0x26) = 0;
    }
    return (*(signed char *)(a0 + 0x26) ^ old) != 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


extern unsigned int D_00747A84;
/* Starts a fade toward preset `slot` over `frames` frames (an instant fade
 * while the game flag is set). Ignored while a fade is already running. */
__attribute__((section(".text.func_002D8E18")))
void func_002D8E18(cWorldLight *self, int slot, short frames)
{
    int n;
    if ((self->flags & WORLDLIGHT_FLAG_FADING) != 0) {
        return;
    }
    n = 0;
    if ((D_00747A84 & 0x20000000) == 0) {
        n = frames;
    }
    self->fadeSlot = slot;
    self->fadeFrame = 0;
    self->fadeFrames = n;
    if (n <= 0) {
        self->fadeT = 1.0f;
    } else {
        self->fadeT = 0.0f;
    }
    self->flags = (self->flags | WORLDLIGHT_FLAG_FADING) & ~WORLDLIGHT_FLAG_FADED;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002A9708")))
void func_002A9708(char *a0) {
    int align;
    int size;
    int pad;
    int blk;
    int n;
    int sz2;
    char *p;
    char *q;
    char *e;
    char *t;
    align = *(int *)(a0 + 0xC);
    size = *(int *)(a0 + 0x4);
    pad = align + 7;
    blk = (size + pad) & -align;
    n = *(int *)(a0 + 0x8);
    p = *(char **)(a0 + 0x0);
    if (n != 0) {
        do {
            q = p + *(int *)(a0 + 0x4);
            n--;
            *(char **)(q + 0x0) = q - blk;
            *(char **)(q + 0x4) = q + blk;
            p += blk;
        } while (n != 0);
    }
    sz2 = *(int *)(a0 + 0x4);
    e = *(char **)(a0 + 0x0) + sz2;
    *(int *)e = 0;
    t = *(char **)(a0 + 0x0) + blk * (*(int *)(a0 + 0x8) - 1) + *(int *)(a0 + 0x4);
    *(int *)(t + 0x4) = 0;
    *(char **)(a0 + 0x10) = e;
    *(int *)(a0 + 0x14) = 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002AABA0")))
void func_002AABA0(char *a0) {
    int i;
    char *p;
    if (*(unsigned char *)(a0 + 0x1C) == 0) return;
    for (i = 0; i < *(int *)(a0 + 0xC); i++) {
        p = *(char **)(a0 + 0x4) + i * 0xAC;
        if (p != 0) {
            *(unsigned short *)(p + 0xA0) = *(unsigned short *)(p + 0xA0) + 1;
            *(unsigned short *)(p + 0xA2) = *(unsigned short *)(p + 0xA2) + 1;
            *(unsigned short *)(p + 0xA6) = *(unsigned short *)(p + 0xA6) + 1;
            *(unsigned short *)(p + 0xA8) = *(unsigned short *)(p + 0xA8) + 1;
            *(unsigned short *)(p + 0xA4) = *(unsigned short *)(p + 0xA4) + 1;
        }
    }
}
