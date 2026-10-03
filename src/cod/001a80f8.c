/* cygnus-2.96 matched TU. */
#include "godhand/cObjSimple.h"
#include "godhand/cScenario.h"
#include "godhand/cEmManage.h"
#include "godhand/cEma2.h"

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

/* 1 while the dark world is on. */
__attribute__((section(".text.cEmManage_DarkWorldCk")))
int cEmManage_DarkWorldCk(cEmManage *self) {
    return self->darkWorld != 0;
}

/* Bit 8 of flags (EMA2_F_KISS), read as the low bit of byte 1. */
__attribute__((section(".text.cEma2_ckKiss")))
int cEma2_ckKiss(cEma2 *self) {
    return ((unsigned char *)&self->flags)[1] & 1;
}

__attribute__((section(".text.cOm53_setDownPos")))
void cOm53_setDownPos(void *a0, float x) { *(float *)((char *)a0 + 0x620) = x; }
