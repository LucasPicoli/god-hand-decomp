/* TU: cScenario [event] - recovered C++ class. */
#include "godhand/cScenario.h"

extern int func_002D5580(cTaskManager *task, void *entry, void *arg, int slot);
extern void cTaskWork_sleep(cTaskWork *work, int a1);
extern int SearchCameraData(const char *name);

extern void *cObjBaseArray_SearchOM(char *arr, long mask);

extern int D_00747A84;
extern char D_00754C58[];
extern char D_00583EC0[];
extern int D_003C264C;
extern int D_00747A24;
extern char D_005E8658[];
extern int ForwardCheckedRequest_2BED60();

__attribute__((section(".text.cScenario_waitEventStartOk")))
/* Sleep the script task until an event may start. */
void cScenario_waitEventStartOk(cScenario *self) {
    cTaskManager *task = &self->task;
    while (cScenario_isEventStartOk(self) == 0) {
        cTaskWork_sleep(task->cur, 1);
    }
}

__attribute__((section(".text.cScenario_setCam")))
/* Start the camera move stored under `name`. */
int cScenario_setCam(cScenario *self, const char *name) {
    return cScenario_startCamMotion(self, SearchCameraData(name));
}
#include "include_asm.h"
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cScenario_taskExec")))
/* Start entry(arg) as a script task in `slot`; returns its index or -1. */
int cScenario_taskExec(cScenario *self, void *entry, void *arg, int slot) {
    int no = func_002D5580(&self->task, entry, arg, slot);
    do {
        cScenario_clearTaskData(self, no);
        return no;
    } while (0);
}
__attribute__((section(".text.cScenario_isEventStartOk")))
/* 0 while events are locked out or the player cannot take one. */
int cScenario_isEventStartOk(cScenario *self)
{
    if (D_00747A84 & 0x40000000)
        return 0;
    return func_0012BAF0(Getplayer()) != 0;
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
    int *flags;
    func_002C0038(D_003C264C);
    D_00747A24 = D_00747A24 & 0xF7FFFFFF;
    /* An int view of save flags: the struct-typed load is scheduled above
     * the D_00747A24 store. */
    flags = (int *)&D_00569B70.data->flags;
    *flags = *flags & ~0x04000000;
}


INCLUDE_ASM("nonmatching", cScenario_beginKurohukuBattle);

INCLUDE_ASM("nonmatching", cScenario_endKurohukuBattle);

/* The object name is packed into a 64-bit key one byte at a time, then looked
   up.  The table base must be bound at block top: it stays live across the
   loop, and no call intervenes. */
__attribute__((section(".text.cScenario_isOmBreak_2C5168")))
/* isOmBreak for the object with this name. */
int cScenario_isOmBreak_2C5168(cScenario *self, const char *name)
{
    char *arr = D_00754C58;
    long acc = 0;
    int i = 0;
    if (*name != 0) {
        do {
            acc |= (long)*name << (i * 8);
            i++;
            name++;
            if (i >= 8) break;
        } while (*name != 0);
    }
    return cScenario_isOmBreak(self, cObjBaseArray_SearchOM(arr, acc));
}

__attribute__((section(".text.cScenario_isOmBreak_2C5220")))
/* Break-list check of entry `no` under this name. */
int cScenario_isOmBreak_2C5220(cScenario *self, unsigned short no, const char *name)
{
    char *arr = D_005E8658;
    long acc = 0;
    int i = 0;
    if (*name != 0) {
        do {
            acc |= (long)*name << (i * 8);
            i++;
            name++;
            if (i >= 8) break;
        } while (*name != 0);
    }
    return ForwardCheckedRequest_2BED60(arr, no, acc);
}

__attribute__((section(".text.cScenario_isOmBreak_2C5288")))
/* Break-list check of entry `no` under a packed name. */
int cScenario_isOmBreak_2C5288(cScenario *self, unsigned short no, long name)
{
    return ForwardCheckedRequest_2BED60(D_005E8658, no, name);
}

