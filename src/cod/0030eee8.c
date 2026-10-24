/* sn-2.95.3-136: Move, the per-frame game update: runs every subsystem's move in order and records the elapsed
 * timer-0 counts of the first step and of the whole frame. */
#include "godhand/cScenario.h"
#include "godhand/cSubScr.h"
#include "godhand/cEmManage.h"
#include "godhand/cDataManager.h"

#define T0_COUNT (*(volatile int *)0x10000800)

extern int D_00752CF0;
extern int D_00752CFC;
extern int D_00752D44;
extern int D_00747A78;
extern void *D_003C2648;
extern void *D_003C23A4;
extern void *D_003BD6E8;
extern char D_005E8040[];
extern char D_005CAE50[];
extern char D_0061A990[];
extern char D_00586AF0[];
extern char D_00463050[];
extern char D_00604700[];
extern char D_00574380[];
extern char D_00462FC0[];
extern char D_00583EC0[];
extern int *D_00754C50[];
extern char D_00747B20[];
extern char D_005FEE00[];

extern void func_002B9D58(void *p);
extern void ListOwner_updateFollowFocus(void *p);
extern void func_002D9BE0(void *p);
extern void func_00296530(void *p);
extern void cScenario_moveFrame(void *p);
extern void func_00138F98(void *p);
extern void cWorldLight_Move(void *p);
extern void func_001FDFD8(void *p);
extern void MoveObj(void);
extern void NoOp_1352F0(void *p);
extern void func_002BF2D0(char *p);
extern void func_001601D8(void *p);
extern void MoveEffect(void);
extern void func_001FFE10(void *p);
extern void cCamManager_update(void *p);
extern void ForwardListEntries_2C5470(int **p);
extern void func_00307B28(void *p);
extern void cMessage_updateAll(void *p);
extern void func_00140E58(void *p);
extern void func_001FE748(void *p);
extern void InitSubsystemGroup_2CA518(void *p);

__attribute__((section(".text.Move")))
void Move(void)
{
    D_00752D44 = D_00752CF0;
    D_00752CFC = T0_COUNT;
    func_002B9D58(D_005E8040);
    D_00752CFC -= T0_COUNT;
    ListOwner_updateFollowFocus(D_005CAE50);
    func_002D9BE0(D_0061A990);
    func_00296530(D_00586AF0);
    cScenario_moveFrame(D_003C2F84);
    func_00138F98(D_00463050);
    cEmManage_Main(&D_005864F0);
    cWorldLight_Move(D_00604700);
    func_001FDFD8(D_00574380);
    MoveObj();
    NoOp_1352F0(D_00462FC0);
    func_002BF2D0(D_003C2648);
    func_001601D8(D_003BD930);
    MoveEffect();
    func_001FFE10(D_00583EC0);
    cScenario_move(D_003C2F84);
    cCamManager_update(D_00463050);
    if (!(D_00747A78 & 0x20000))
        ForwardListEntries_2C5470(D_00754C50);
    func_00307B28(D_00747B20);
    cMessage_updateAll(D_003C23A4);
    func_00140E58(D_003BD6E8);
    func_001FE748(&D_00580D20);
    func_001FE748(&D_005864E0);
    InitSubsystemGroup_2CA518(D_005FEE00);
    D_00752D44 -= T0_COUNT;
}
