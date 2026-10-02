/* sn-2.95.3-136 matched TU. */

#include "godhand/cRoomSave.h"

extern void cIDBase_initialize(void *p, int a, int b);
extern void cIDBase_restartAnim(void *p);
extern void *cIDBase_getIDWork(void *p, int i);
extern void CustomIDWork_Initialize(void *p, void *w);
extern void CustomIDWork_SetDisp(void *p, int f);
extern void SetCustomIDDispOneOrAll_1F4778(void *p, int n, int f);
extern void func_001ED7E0(void *p);
extern void func_001EDC28(void *p, int n);
extern void func_001ED700(void *p, int n, int f);
extern void func_001EE2A8(void *p, int n);
extern void func_001EE2C8(void *p, int n);
extern void SetCustomIDDispOneOrAll_1EE1C0(void *p, int n, int f);
extern void CustomIDWork_SetMessNo(void *p, int n);
extern void func_001ECE30(void *p, int a, int b);
extern void func_001ED490(void *p, int a);
extern void func_003A52F0(void *dst, int val, int n);
extern cRoomSaveData D_005E9CB8[ROOMSAVE_PAGE_NUM];

/* Build the 0x6F custom-ID works of a UI object, then show all of them. */







__attribute__((section(".text.func_001F4648")))
void func_001F4648(char *p)
{
    int i;

    cIDBase_initialize(p + 0x10, 0x15, 0);
    cIDBase_restartAnim(p + 0x10);
    for (i = 0; i < 0x6F; i++) {
        CustomIDWork_Initialize(p + 0x60 + i * 0x7C, cIDBase_getIDWork(p + 0x10, i));
    }
    SetCustomIDDispOneOrAll_1F4778(p, 0x6F, 0);
}

/* Build the 6 custom-ID works of a UI object, then run its three setup steps. */









__attribute__((section(".text.func_001ED5B8")))
void func_001ED5B8(char *p)
{
    int i;

    cIDBase_initialize(p + 0x10, 0x14, 2);
    cIDBase_restartAnim(p + 0x10);
    for (i = 0; i < 6; i++) {
        CustomIDWork_Initialize(p + 0x60 + i * 0x7C, cIDBase_getIDWork(p + 0x10, i));
    }
    func_001ED7E0(p);
    func_001EDC28(p, 0);
    func_001ED700(p, 6, 0);
}

/* Build the 0x1D custom-ID works of a UI object, run its setup steps, then show all of them. */









__attribute__((section(".text.func_001EDEA8")))
void func_001EDEA8(char *p)
{
    int i;

    cIDBase_initialize(p + 0x10, 0x14, 1);
    cIDBase_restartAnim(p + 0x10);
    for (i = 0; i < 0x1D; i++) {
        CustomIDWork_Initialize(p + 0x60 + i * 0x7C, cIDBase_getIDWork(p + 0x10, i));
    }
    func_001EE2A8(p, 0);
    func_001EE2C8(p, 0);
    CustomIDWork_SetDisp(p + 0x60, 0);
    SetCustomIDDispOneOrAll_1EE1C0(p, 0x1D, 0);
}

/* Build the 0x2D custom-ID works of a UI object, set four message numbers, hide the first work and run two setup steps. */









__attribute__((section(".text.func_001ECAF0")))
void func_001ECAF0(char *p)
{
    int i;

    cIDBase_initialize(p + 0x10, 0x14, 0);
    cIDBase_restartAnim(p + 0x10);
    for (i = 0; i < 0x2D; i++) {
        CustomIDWork_Initialize(p + 0x60 + i * 0x7C, cIDBase_getIDWork(p + 0x10, i));
    }
    CustomIDWork_SetMessNo(p + 0xE6C, 0x101A);
    CustomIDWork_SetMessNo(p + 0x1534, 0x101A);
    CustomIDWork_SetMessNo(p + 0xEE8, 0x101B);
    CustomIDWork_SetMessNo(p + 0x15B0, 0x101B);
    CustomIDWork_SetDisp(p + 0x440, 0);
    func_001ECE30(p, 0x2D, 0);
    func_001ED490(p, 0);
}

/* Boot reset: clear the seven pages, the spare page, and forget the current page. */
__attribute__((section(".text.cRoomSave_systemInit")))
void cRoomSave_systemInit(cRoomSave *self) {
    func_003A52F0(D_005E9CB8, 0, sizeof(D_005E9CB8));
    func_003A52F0(&self->spare, 0, sizeof(self->spare));
    self->data = 0;
}
