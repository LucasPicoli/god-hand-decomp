/* cygnus-2.96 matched TU. */
#include "godhand/cObjSimple.h"
#include "godhand/cScenario.h"

/* Turn the ring physics on or off. */
__attribute__((section(".text.cObjSimple_SetRingFlag")))
void cObjSimple_SetRingFlag(cObjSimple *self, int on) {
    self->ringFlag = on;
}

/* Turn the bust physics on or off. */
__attribute__((section(".text.cObjSimple_SetBustFlag")))
void cObjSimple_SetBustFlag(cObjSimple *self, int on) {
    self->bustFlag = on;
}

__attribute__((section(".text.cScenario_SetRoomExitFunc")))
/* Set the callback run once when the room is left. */
void cScenario_SetRoomExitFunc(cScenario *self, void (*func)(void *), void *arg) {
    self->roomExitFunc = func;
    self->roomExitArg = arg;
}

__attribute__((section(".text.cEmManage_DarkWorldCk")))
int cEmManage_DarkWorldCk(int a0) {
    return *(unsigned char*)((char*)a0 + 0x518) != 0;
}

__attribute__((section(".text.cEma2_ckKiss")))
int cEma2_ckKiss(void *a0) {
    return *(unsigned char*)((char*)a0+0x15B1) & 1;
}

__attribute__((section(".text.cOm53_setDownPos")))
void cOm53_setDownPos(void *a0, float x) { *(float *)((char *)a0 + 0x620) = x; }
