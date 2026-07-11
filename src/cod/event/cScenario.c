/* TU: cScenario [event] - recovered C++ class. */
extern void *func_002D5580(void *);
extern void func_002C3968(void *, void *);
extern void SetFieldsCESignalSemaSleep_2D5AA0(int a0, int a1);

extern int D_00747A84;
extern char D_00583EC0[];
extern int D_003C264C;
extern int D_00747A24;
extern int D_00569B70;
extern char D_005E8658[];

__attribute__((section(".text.cScenario_waitEventStartOk")))
void cScenario_waitEventStartOk(void *a0) {
    char *s0 = (char *)a0;
    char *s1 = s0 + 0x1C;
    while (cScenario_isEventStartOk(s0) == 0) {
        SetFieldsCESignalSemaSleep_2D5AA0(*(int *)(s1 + 4), 1);
    }
}

__attribute__((section(".text.cScenario_setCam")))
int cScenario_setCam(void *a0, int a1) {
    return LoadScreenOverlay_2C3F10(a0, SearchCameraData(a1));
}
#include "include_asm.h"

__attribute__((section(".text.cScenario_taskExec")))
void *cScenario_taskExec(void *a0) {
    void *v0 = func_002D5580((char *)a0 + 0x1C);
    do {
        func_002C3968(a0, v0);
        return v0;
    } while (0);
}
__attribute__((section(".text.cScenario_isEventStartOk")))
int cScenario_isEventStartOk(void *a0)
{
    if (D_00747A84 & 0x40000000)
        return 0;
    return func_0012BAF0(Obj0000_Get_D_00747A94_2DB6B0()) != 0;
}


__attribute__((section(".text.cScenario_beginRoomJump")))
void cScenario_beginRoomJump(int a0, unsigned char a1, unsigned char a2, int a3, unsigned char a4)
{
    SetColorRgba_1FFE60(D_00583EC0, a1, a2, a3, a4);
}


INCLUDE_ASM("nonmatching", cScenario_beginCasinoBattle);

__attribute__((section(".text.cScenario_endCasinoBattle")))
void cScenario_endCasinoBattle(void)
{
    int *p;
    func_002C0038(D_003C264C);
    D_00747A24 = D_00747A24 & 0xF7FFFFFF;
    p = (int *)D_00569B70;
    p[5] = p[5] & 0xFBFFFFFF;
}


INCLUDE_ASM("nonmatching", cScenario_beginKurohukuBattle);

INCLUDE_ASM("nonmatching", cScenario_endKurohukuBattle);

INCLUDE_ASM("nonmatching", cScenario_isOmBreak_2C5168);

INCLUDE_ASM("nonmatching", cScenario_isOmBreak_2C5220);

__attribute__((section(".text.cScenario_isOmBreak_2C5288")))
int cScenario_isOmBreak_2C5288(int a0, unsigned short a1)
{
    return ForwardCheckedRequest_2BED60(D_005E8658, a1);
}

