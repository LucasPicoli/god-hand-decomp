/* sn-2.95.3-136: func_0030B728, game system start-up: clears the shared system block, initialises the subsystems and queues the boot tasks. */
#include "godhand/classFADE.h"
#include "godhand/gameWork.h"
#include "godhand/globals.h"
extern int cTaskManager_execute(void *task, void *entry, int slot);
extern char D_00586C00[];
extern char D_00754C80[];
extern void *D_003BD930;
extern char D_00569B70[];
extern char D_005E8658[];
extern void *D_003C2558;

extern int func_003A6A20(const char *fmt, ...);
extern void *func_003A52F0(void *p, int c, int n);
extern void func_00299348(void *p);
extern void func_0031A338(void *p);
extern void func_00306D10(void);
extern void func_0030CF10(void);
extern void func_003077B0(void *p);
extern void func_0015FD98(void *p);
extern void cCoreSave_systemInit(void *p);
extern void cRoomSave_systemInit(void *p);
extern void func_0031C348(void);
extern void ClearWordPair_201AD0(void *p);
extern void func_0030D358(void);
extern void func_002A5998(void);
extern void func_0030D5C8(int a0, int a1);
extern void Obj0000_Clear_Bytes_D_003C2554_D_003C2555_2B6598(void *p);

__attribute__((section(".text.func_0030B728")))
void func_0030B728(void)
{
    func_003A6A20(D_00450518);
    func_003A52F0(&D_007474A0.pack, 0, 0x68);
    D_007474A0.room = GAMEWORK_ROOM_NOPLAYER;
    D_007474A0.timeScale = 1.0f;
    func_00299348(D_00586C00);
    func_0031A338(D_00754C80);
    func_00306D10();
    func_0030CF10();
    func_003077B0(&D_00747470);
    func_0015FD98(D_003BD930);
    cCoreSave_systemInit(D_00569B70);
    cRoomSave_systemInit(D_005E8658);
    func_0031C348();
    if (D_007474A0.debugFlags & 0x800)
        ClearWordPair_201AD0(D_00585038);
    func_003A6A20(D_00450530);
    if (!(D_007474A0.flags & 0x80000)) {
        cTaskManager_execute(&D_00752C00, func_0030D358, 3);
    } else {
        cTaskManager_execute(&D_00752C00, func_002A5998, 0);
        cTaskManager_execute(&D_00752C00, func_0030D5C8, 3);
    }
    Obj0000_Clear_Bytes_D_003C2554_D_003C2555_2B6598(D_003C2558);
}
