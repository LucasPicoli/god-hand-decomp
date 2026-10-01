/* TU: cOm4f [object] - recovered C++ class. */
#include "godhand/cOm4f.h"
extern void func_001A4BD0(void *);
#include "include_asm.h"

/* 1 while the door stands open. */
__attribute__((section(".text.cOm4f_isOpen")))
unsigned char cOm4f_isOpen(cOm4f *self) {
    return self->open;
}

/* Nonzero while a move is in progress. */
__attribute__((section(".text.cOm4f_isActive")))
unsigned int cOm4f_isActive(cOm4f *self) {
    return self->active;
}

/* Store the event mode byte. */
__attribute__((section(".text.cOm4f_setEventMode")))
void cOm4f_setEventMode(cOm4f *self, int mode) {
    self->eventMode = (char)mode;
}

/* Lock (1) or unlock (0) the door. */
__attribute__((section(".text.cOm4f_setLock")))
void cOm4f_setLock(cOm4f *self, int lock) {
    self->lock = (unsigned char)lock;
}

/* Remember the partner door that func_001A4F38 keeps in step. */
__attribute__((section(".text.cOm4f_connectDoor")))
void cOm4f_connectDoor(cOm4f *self, void *door) {
    self->door = door;
}

/* Start opening unless locked or already open. */
__attribute__((section(".text.cOm4f_setOpen")))
void cOm4f_setOpen(cOm4f *self) {
    if (self->lock == 1) {
        return;
    }
    if (self->open != 0) {
        return;
    }
    self->active = 1;
    func_001A4BD0(self);
    self->moveCmd = 1;
    self->unk2F5[0] = 0;
    self->unk2F5[1] = 0;
    self->unk2F5[2] = 0;
}


/* Start closing unless locked or already shut. */
__attribute__((section(".text.cOm4f_setClose")))
void cOm4f_setClose(cOm4f *self) {
    if (self->lock == 1) {
        return;
    }
    if (self->open != 1) {
        return;
    }
    self->active = 1;
    func_001A4BD0(self);
    self->moveCmd = 2;
    self->unk2F5[0] = 0;
    self->unk2F5[1] = 0;
    self->unk2F5[2] = 0;
}
