/* TU: cSaveManager [system] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cCoreSave.h"

typedef struct { int q[4]; } Q16 __attribute__((aligned(16)));
typedef struct { Q16 m[0x14A0/16]; } Blk1;
typedef struct __attribute__((aligned(8))) { int m[0x9C30/4]; } Blk2;
typedef struct { char m[0x20]; } Blk3;
extern void func_0031C350(int, int);
extern Blk2 D_005E9CB8;
extern Blk3 D_00755880;

extern int D_005E8658;

__attribute__((section(".text.cSaveManager_stageClear")))
void cSaveManager_stageClear(void) {
    cCoreSave_stageInit(&D_00569B70);
    cRoomSave_systemInit(&D_005E8658);
}


__attribute__((section(".text.cSaveManager_setCheckPoint")))
void cSaveManager_setCheckPoint(char *dst, int a1, int a2, int a3)
{
    cCoreSave_snapshot(&D_00569B70, a1);
    func_0031C350(a2, a3);
    *(Blk1 *)dst = *(Blk1 *)D_00569B70.data;
    *(Blk2 *)(dst + 0x14A0) = D_005E9CB8;
    *(Blk3 *)(dst + 0xB0D0) = D_00755880;
}
