/* sn-2.95.3-136 matched TU. */

#include "godhand/cDvd.h"

extern char D_00580D40[];
extern int FindEntryValue_1FF9C0(char *table, char *name, int *size, char *key);
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, int a2);

/* func_00201018: drop the running job, then give every queued job back. */


__attribute__((section(".text.func_00201018")))
void func_00201018(cDvd *self) {
    cDvdJob *job, *cur;
    int i;
    cur = self->cur;
    if (cur != 0) {
        if (cur->heap != 0) {
            func_00324008(cur->heap);
            FreeObjectSlot_2018F0(self);
        }
        self->cur = 0;
    }
    job = self->job;
    for (i = CDVD_JOB_NUM - 1; i >= 0; i--) {
        func_00201228(self, job);
        job++;
    }
    self->queueNum = 0;
}

/* func_00200F50: cancel the job with the given id, running or queued. Returns 1 if one was found. */


__attribute__((section(".text.func_00200F50")))
int func_00200F50(cDvd *self, int id) {
    cDvdJob *cur;
    cDvdJob *job;
    int ret = 0;
    cur = self->cur;
    if (cur == 0) return 0;
    if (cur->id == id) {
        if (cur->heap != 0) {
            func_00324008(cur->heap);
            FreeObjectSlot_2018F0(self);
        }
        self->cur = 0;
        func_00201290(self);
        ret = 1;
    } else {
        int *q, *end;
        job = self->job;
        q = &self->job[0].id;
        end = &self->job[CDVD_JOB_NUM].id;
        do {
            if (*q == id) {
                func_00201228(self, job);
                ret = 1;
            }
            job++;
            q = (int *)((char *)q + sizeof(cDvdJob));
        } while ((int)q < (int)end);
    }
    return ret;
}

/* func_00200DF8: queue a read of a named file into a heap block. Returns the job id, 0 on failure. */






__attribute__((section(".text.func_00200DF8")))
int func_00200DF8(cDvd *self, char *name, void **outBuf, int a3, int id, unsigned int *outSize, int arg70, int arg6C) {
    cDvdJob *job;
    void *buf;

    *outBuf = 0;
    job = func_002017A8(self);
    if (job == 0) return 0;
    job->fileNo = FindEntryValue_1FF9C0(D_00580D40, name, &job->size, job->unk0C);
    job->align = a3;
    job->blockNum = (unsigned int)(job->size + 0x7FF) >> 11;
    if (job->fileNo < 0) return 0;
    job->state = 1;
    if (id == 0) {
        job->id = func_00201788(self);
    } else {
        job->id = id;
    }
    job->arg6C = arg6C;
    job->arg70 = arg70;
    job->buf = 0;
    buf = EnsureInitThenForward_2A9538_30EE08(job->blockNum << 11, 0x80, a3);
    job->buf = buf;
    if (buf == 0) {
        func_00201228(self, job);
        return 0;
    }
    if (outSize != 0) {
        *outSize = job->blockNum << 11;
    }
    *outBuf = job->buf;
    if (self->cur == 0) {
        func_00201290(self);
    }
    return job->id;
}
