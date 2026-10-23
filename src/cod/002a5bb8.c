/* sn-2.95.3-136: func_002A5BB8, game start-up step: wait for the boot flag, load the two system resource blocks and initialise the ID, pad, menu, display and object managers. */
#include "godhand/gameWork.h"
#include "godhand/cSubScr.h"
extern char D_004664A0[];
extern void **D_003C2384;
extern void *D_003C2388;
extern char D_0044AD58[];
extern void *D_003C264C;
extern char D_005E80E0[];
extern void *D_003C2380;
extern void *D_003C23A4;
extern char D_00586AF0[];
extern void *D_003BD6E8;
extern char D_00583EC0[];
extern void *D_003C2648;
extern char D_00580D20[];
extern char D_005864E0[];
extern char D_00754220[];
extern char D_005FEC58[];

extern int func_00150C10(void *a0, void *blk, int a2);
extern void *SearchData(void *data, char *name, int a2);
extern void cIDManager_systemInit(void *mgr, void *data);
extern void WorkArea_clear(void *p);
extern void cPadVib_init(void *p);
extern void func_002A4970(void *p);
extern void cMenu_loadDataTables(void *p);
extern void func_0015FD98(char *self);
extern void ResetObjectState_2962B0(void *p);
extern void DispMgr_reset(void *p);
extern void NoOp_1FFE00(void *p);
extern void func_002BF130(void *p);
extern void ResetSlotArray_1FE6C8(void *p, void *slots);
extern int func_002C8EF8(void *p);

__attribute__((section(".text.func_002A5BB8")))
void func_002A5BB8(unsigned char *step)
{
    GameWork *sys;

    while (!(D_00747A24 & 0x2000))
        cTaskWork_sleep(D_00752C00.task, 1);
    sys = &D_007474A0;
    func_00150C10(D_004664A0, (void *)(sys->effData->block1 + (int)sys->effData), 1);
    func_00150C10(D_004664A0, (void *)(sys->effData->block2 + (int)sys->effData), 1);
    *D_003C2384 = D_003C2388;
    cIDManager_systemInit(D_003C2388, SearchData(sys->langData, D_0044AD58, 0));
    WorkArea_clear(D_003C264C);
    cPadVib_init(D_005E80E0);
    func_002A4970(D_003C2380);
    cMenu_loadDataTables(D_003C23A4);
    func_0015FD98((char *)D_003BD930);
    ResetObjectState_2962B0(D_00586AF0);
    DispMgr_reset(D_003BD6E8);
    NoOp_1FFE00(D_00583EC0);
    func_002BF130(D_003C2648);
    ResetSlotArray_1FE6C8(D_00580D20, 0);
    ResetSlotArray_1FE6C8(D_005864E0, D_00754220);
    func_002C8EF8(D_005FEC58);
    *step = 2;
}
