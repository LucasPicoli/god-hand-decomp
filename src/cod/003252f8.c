/* cygnus-2.96 matched TU. */

extern const char D_00454C78[];
extern const char D_00454458[];
extern int ReferThreadStatus(int thid, struct THST *info);
extern int ResumeThread(int thid);

struct LSC { char f0; signed char f1; char pad[0x1A]; int f1C; int f20; int f24; };



__attribute__((section(".text.LSC_ResetEntry")))
void LSC_ResetEntry(struct LSC *p)
{
    if (p == 0) {
        func_00335D40(D_00454C78);
        return;
    }
    if (p->f1 != 0) return;
    p->f1C = 0;
    p->f20 = 0;
    p->f24 = 0;
}

__attribute__((section(".text.func_00332E68")))
int func_00332E68(int *hn)
{
    if (hn == 0) {
        func_00332808(hn, D_00454458);
        return 0;
    }
    return hn[3];
}

struct THST { int status; char pad[0x2C]; };



__attribute__((section(".text.adxm_ResumeThread")))
int adxm_ResumeThread(int thid)
{
    struct THST info;
    int ret = 0;
    if (thid != 0) {
        ReferThreadStatus(thid, &info);
        if (info.status == 8 || info.status == 0xC) ret = ResumeThread(thid);
    }
    return ret;
}
