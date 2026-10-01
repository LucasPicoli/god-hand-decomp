/* TU: cDvd [system] - recovered C++ class. */
#include "godhand/cDvd.h"
extern char D_00580D40[];
extern int cDvd_Check(int a0, int a1);

/* Queue a read of a named file. Returns the job id, 0 on failure. t1 overrides the size in bytes. */
__attribute__((section(".text.cDvd_ReadAlloc")))
int cDvd_ReadAlloc(cDvd *self, char *name, int *outBuf, int a3, int id, int t1, int arg70, int arg6C)
{
    cDvdJob *job;

    *outBuf = 0;
    job = func_002017A8(self);
    if (job == 0)
        return 0;

    {
        int fileNo = FindEntryValue_1FF9C0(D_00580D40, name, &job->size, job->unk0C);
        job->fileNo = fileNo;
        job->align = a3;
        job->blockNum = (unsigned int)(job->size + 0x7FF) >> 11;
        if (fileNo < 0)
            return 0;
    }

    job->state = 1;
    if (id == 0)
        job->id = func_00201788(self);
    else
        job->id = id;

    job->arg6C = arg6C;
    job->arg70 = arg70;
    job->buf = 0;
    if (t1 != 0)
        job->blockNum = (unsigned int)(t1 + 0x7FF) >> 11;

    {
        void *r = EnsureInitThenForward_2A9538_30EE08(job->blockNum << 11, 0x80, a3);
        job->buf = r;
        if (r == 0) {
            func_00201228(self, job);
            return 0;
        }
        *outBuf = (int)r;
    }

    if (self->cur == 0)
        func_00201290(self);
    return job->id;
}
extern int FindEntryValue_1FF9C0(char *table, char *name, int *size, char *key);
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, int a2);
extern void func_00200B20(cDvd *self);
/* Wait until the job with the given id is no longer pending. */
__attribute__((section(".text.cDvd_CheckWait")))
void cDvd_CheckWait(cDvd *self, int id)
{
    while (cDvd_Check(self, id))
        func_00200B20(self);
}
