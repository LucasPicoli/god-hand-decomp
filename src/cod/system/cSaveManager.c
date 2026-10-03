/* TU: cSaveManager [system] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSaveManager.h"

typedef struct { int q[4]; } Q16 __attribute__((aligned(16)));
typedef struct { Q16 m[0x14A0/16]; } Blk1;
typedef struct __attribute__((aligned(8))) { int m[0x9C30/4]; } Blk2;
typedef struct { char m[0x20]; } Blk3;
extern void func_0031C350(int, int);
extern cSaveRooms D_005E9CB8;
extern cSaveTail D_00755880;

extern int D_005E8658;

__attribute__((section(".text.cSaveManager_stageClear")))
void cSaveManager_stageClear(void) {
    cCoreSave_stageInit(&D_00569B70);
    cRoomSave_systemInit(&D_005E8658);
}


/* Take a checkpoint snapshot: the save record, the room pages and the tail block. */
__attribute__((section(".text.cSaveManager_setCheckPoint")))
void cSaveManager_setCheckPoint(cSaveSlot *dst, int a1, int a2, int a3)
{
    cCoreSave_snapshot(&D_00569B70, a1);
    func_0031C350(a2, a3);
    dst->core = *(cSaveCore *)D_00569B70.data;
    dst->rooms = D_005E9CB8;
    dst->tail = D_00755880;
}
