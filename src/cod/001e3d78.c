/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot2.h"

extern void displayScrollLayer(int a0, int a1);
extern void func_003735E0(void *a0, int a1, float f12, float f13);

__attribute__((section(".text.func_001E3D78")))
void func_001E3D78(void *a0, int a1, int a2) {
    *(short *)((char *)a0 + 0x4A8) = 0;
    if (a2) {
        *(unsigned short *)((char *)a0 + 0x4A8) = 0x8000;
    }
    if (a1) {
        *(unsigned short *)((char *)a0 + 0x4A8) = *(unsigned short *)((char *)a0 + 0x4A8) | 0x4000;
        displayScrollLayer(*(int *)((char *)a0 + 0x430), 1);
    } else {
        displayScrollLayer(*(int *)((char *)a0 + 0x430), 0);
    }
}

/* Slot2 line mark 1: set its flag word (bit 15 = start lit, bit 14 = on) and
 * show or hide the line layer. */
__attribute__((section(".text.func_001E6C80")))
void func_001E6C80(Slot2 *self, int on, int lit) {
    self->markFlag[1] = 0;
    if (lit) {
        self->markFlag[1] = 0x8000;
    }
    if (on) {
        self->markFlag[1] = self->markFlag[1] | 0x4000;
        displayScrollLayer(self->lineLayer, 1);
    } else {
        displayScrollLayer(self->lineLayer, 0);
    }
}

/* Slot2 line mark 2, same as mark 1 for the next flag word. */
__attribute__((section(".text.func_001E6D48")))
void func_001E6D48(Slot2 *self, int on, int lit) {
    self->markFlag[2] = 0;
    if (lit) {
        self->markFlag[2] = 0x8000;
    }
    if (on) {
        self->markFlag[2] = self->markFlag[2] | 0x4000;
        displayScrollLayer(self->lineLayer, 1);
    } else {
        displayScrollLayer(self->lineLayer, 0);
    }
}

/* Slot2 line mark 3, same again for the next flag word. */
__attribute__((section(".text.func_001E6E10")))
void func_001E6E10(Slot2 *self, int on, int lit) {
    self->markFlag[3] = 0;
    if (lit) {
        self->markFlag[3] = 0x8000;
    }
    if (on) {
        self->markFlag[3] = self->markFlag[3] | 0x4000;
        displayScrollLayer(self->lineLayer, 1);
    } else {
        displayScrollLayer(self->lineLayer, 0);
    }
}

__attribute__((section(".text.func_003AE188")))
int func_003AE188(int a0, int a1, ...) {
    return func_003AB158(a0, a1, (char*)__builtin_next_arg(a1) - 0x30);
}

__attribute__((section(".text.func_002CD500")))
void func_002CD500(void *a0, int a1, float f) {
    *(int *)((char *)a0 + 0x98) |= a1;
    *(float *)((char *)a0 + 0xC8) = f;
    func_003735E0(a0, -1, 0.01f, f);
}
