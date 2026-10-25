/* cygnus-2.96: read a text file into fixed-width line slots: check the arguments, read the file and
 * split it into lines; returns the bytes used. */
#define WORK_SIZE  0x1000

extern char D_007563C0[WORK_SIZE];
typedef struct DevTblEnt {
    void *unk0;                         /* 0x00 */
    int unk4;                           /* 0x04 */
    int unk8;                           /* 0x08 */
    int unkC;                           /* 0x0C */
} DevTblEnt;

extern DevTblEnt D_003D9DC0;            /* the open table; Tramp_003A52F0_00333AD8 clears it */
extern char D_004545E0[];
extern char D_00454610[];
extern char D_00454640[];
extern char D_00454668[];

extern void *func_003A52F0(void *dst, int c, int n);
extern void Tramp_003A52F0_00333AD8(void);
extern void LogPrintf(char *fmt, ...);
extern int func_003336F8(char *name, char *work);
extern void func_00332808(void *dev, char *msg);
extern int func_00333560(void *buf, char *work, int size, unsigned int num, int unit);
extern int FileList_resolveAll(void *buf, int n);

__attribute__((section(".text.func_00333CE0")))
unsigned int func_00333CE0(char *name, void *buf, unsigned int size, int unit)
{
    unsigned int per;

    func_003A52F0(D_007563C0, 0, WORK_SIZE);
    if (D_003D9DC0.unk0 != 0)
        Tramp_003A52F0_00333AD8();
    if (name == 0 || buf == 0 || size == 0)
        Tramp_003A52F0_00333AD8();
    if (name == 0)
        return 0;
    if (buf == 0) {
        LogPrintf(D_004545E0, 0);
        return 0;
    }
    if (size == 0) {
        LogPrintf(D_00454610, 0);
        return 0;
    }
    func_003A52F0(buf, 0, size);
    if (func_003336F8(name, D_007563C0) == 0) {
        LogPrintf(D_00454640, name);
        func_00332808(0, D_00454668);
        return 0;
    }
    per = unit + 9;
    return (size / per) * 8
         + FileList_resolveAll(buf, func_00333560(buf, D_007563C0, WORK_SIZE, size / per, unit)) * (unit + 1);
}
