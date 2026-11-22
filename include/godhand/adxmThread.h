/* include/godhand/adxmThread.h - ADX/Sofdec server threads (cygnus code at 0x324EB0..).
 *
 * adxm_ResumeThread and WakeupThread are not declared here: the server loop at
 * 0x324EB0 compares their results as int, while the adxm.h callers were
 * compiled against other return types, so each TU keeps its own prototype.
 */
#ifndef GODHAND_ADXMTHREAD_H
#define GODHAND_ADXMTHREAD_H

/* Per-server stop request / acknowledge flags and wake counters. */
extern volatile long D_003C8158, D_003C8160;
extern volatile long D_003C8178, D_003C8180;
extern volatile long D_003C8188, D_003C8190;
extern volatile long D_003C8198, D_003C81A0;
extern volatile long D_003C8110, D_003C8118, D_003C8120;

extern volatile int D_003C80E4;         /* server busy */
extern volatile int D_003C80E8;
extern volatile int D_003C80F0;
extern volatile int D_003C80F4;
extern volatile int D_003C80FC;
extern volatile int D_003C8148, D_003C814C, D_003C8150;    /* server thread ids */
extern volatile int D_003C81C8;
extern unsigned short D_003C81C4;       /* GS BGCOLOR debug tint */

#define GS_BGCOLOR (*(volatile unsigned long *)0x120000E0)

struct ThreadParam {
    int status;
    void *entry;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    unsigned int attr;
    unsigned int option;
    int waitType;
    int waitId;
    int wakeupCount;
};

extern int ReferThreadStatus(int tid, struct ThreadParam *info);
extern void SleepThread_3252E0(void);
extern void ExitDeleteThread(void);

extern int adxm_SuspendThread(int thid);     /* server suspend */
extern void func_00325290(int thid);
extern void ADXPS2_WakeupMainThrd(void);
extern void func_00325FD8(void);
extern int GetD003C80A8_325610(void);
extern void Forward33BC48_33BD48(void);
extern int Forward33BC48_33BD78(void);
extern int Forward33BC48_33BDA8(void);
extern void Obj0000_Increment_D_003C8100_324E98(void);

#endif /* GODHAND_ADXMTHREAD_H */
