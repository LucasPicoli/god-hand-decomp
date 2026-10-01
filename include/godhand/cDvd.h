/* include/godhand/cDvd.h - the disc read queue.
 *
 * cDvd owns 32 read jobs of 0x88 bytes each, one running job pointer in front
 * of them, and a counter that hands out job ids. A caller gets an id back from
 * ReadAlloc and later asks Check or CheckWait whether that id is still
 * pending. State 1 on a job means it is queued.
 *
 * Method names come from the retail symbol table. Field names are ours, taken
 * from the methods that read and write them. Offsets are exact. A field we
 * can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_CDVD_H
#define GODHAND_CDVD_H

#define CDVD_JOB_NUM   32

typedef struct cDvdJob {
    int state;                          /* 0x00 0 = free, 1 = queued */
    int id;                             /* 0x04 handed back to the caller */
    int fileNo;                         /* 0x08 index of the file on the disc */
    char unk0C[0x60];                   /* 0x0C file lookup key */
    int arg6C;                          /* 0x6C */
    int arg70;                          /* 0x70 */
    int blockNum;                       /* 0x74 size in 0x800-byte blocks */
    int size;                           /* 0x78 size in bytes */
    int align;                          /* 0x7C buffer alignment argument */
    void *buf;                          /* 0x80 where the data lands */
    void *heap;                         /* 0x84 owner of buf, 0 if none */
} cDvdJob;                              /* 0x88 */

typedef struct cDvd {
    cDvdJob *cur;                       /* 0x000 job being read, 0 = idle */
    cDvdJob job[CDVD_JOB_NUM];          /* 0x004 */
    int idCounter;                      /* 0x1104 last id handed out */
    int queueNum;                       /* 0x1108 */
} cDvd;

extern cDvdJob *func_002017A8(cDvd *self);               /* take a free job */
extern int func_00201788(cDvd *self);                    /* next job id */
extern void func_00201228(cDvd *self, cDvdJob *job);     /* give a job back */
extern void func_00201290(cDvd *self);                   /* start the next job */
extern void func_00324008(void *heap);                   /* free the heap block */
extern void FreeObjectSlot_2018F0(cDvd *self);

#endif
