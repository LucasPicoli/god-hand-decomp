/* sn-2.95.3-136 matched TU. */

#include "godhand/cTaskWork.h"
#include "godhand/cTaskManager.h"
#include "godhand/vu0.h"

extern int D_00747A34;
extern char D_00754C10[];
extern int D_00450B28;
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *region);
extern void func_003A52F0(void *dst, int val, int len);
extern void cObjBase(void *a0);
extern void func_002D58E8(void *work, void *entry, int arg);
extern void func_002D5440(cTaskManager *self, int index);
extern void InitFields_1B6E90(void *);
extern void Obj0000_Set_Byte_54(void *, int);
extern int D_00428778;
extern char D_003BC7B0[];
extern char D_003BC7B8[];

/* Allocate and zero a 0x4D0-byte object, run the base constructor and set its vtable pointer; 0 if the allocator is locked or full. */







__attribute__((section(".text.CreateObjectWithVtableC")))
void *CreateObjectWithVtableC(void) {
    char *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = EnsureInitThenForward_2A9538_30EE08(0x4D0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x4D0);
    cObjBase(s0);
    *(int **)(s0 + 0x214) = &D_00450B28;
    return s0;
}

/* Find the room entry whose id byte (+0x13) equals a1 and set its dead flag (+0x14); return 1 if found. */



__attribute__((section(".text.cRoomSave_setEmDeadFlag")))
int cRoomSave_setEmDeadFlag(void *a0, int a1) {
    int i;
    unsigned char *e;
    for (i = 0; (unsigned int)i < func_002BEDD8(a0); i++) {
        e = cRoomSave_getEm(a0, i);
        if (e != 0 && e[0x13] == a1) {
            e[0x14] = 1;
            return 1;
        }
    }
    return 0;
}

/* Take a free task record, start entry(arg) in it, and return its index (-1 if full). */
__attribute__((section(".text.func_002D5580")))
int func_002D5580(cTaskManager *self, void *entry, int arg, int allocArg)
{
    int index = self->vt->allocSlot((char *)self + self->vt->allocDelta, allocArg);
    if (index != TASKMGR_NONE) {
        func_002D58E8(self->works + index * TASKMGR_WORK_SIZE, entry, arg);
    }
    func_002D5440(self, index);
    return index;
}

/* Object constructor: base init, vtable at 0x214, zero 8 VU0 sub-blocks, then clear the trailing fields. */






__attribute__((section(".text.InitVuBlockObject")))
void *InitVuBlockObject(void *a0){
  char *s0; int i;
  InitFields_1B6E90(a0);
  s0 = (char*)a0 + 0x660;
  *(int*)((char*)a0+0x600) = 0;
  *(int**)((char*)a0+0x214) = &D_00428778;
  i = 7;
  do {
    VU0_SQC2_VF0(s0, 0x0);
    VU0_SQC2_VF0(s0, 0x10);
    VU0_SQC2_VF0(s0, 0x20);
    VU0_SQC2_VF0(s0, 0x30);
    VU0_SQC2_VF0(s0, 0x40);
    Obj0000_Set_Byte_54(s0, 0);
    s0 += 0x60;
    i--;
  } while(i != -1);
  *(int*)((char*)a0+0x64C) = 0;
  *(int*)((char*)a0+0x650) = 0;
  *(int*)((char*)a0+0x654) = 0;
  *(int*)((char*)a0+0x658) = 0;
  *(int*)((char*)a0+0x648) = 0;
  return a0;
}

/* Dispatch the current action: pick the table entry for state byte +0x2F5 (reset to 0 when out of range) and call its handler. */


__attribute__((section(".text.DispatchActionTableA")))
void DispatchActionTableA(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 1) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BC7B0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BC7B0 + i8 + 4);
    }
    f0 = *(short *)(D_003BC7B0 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

/* Dispatch the current action: pick the table entry for state byte +0x2F5 (reset to 0 when out of range) and call its handler. */


__attribute__((section(".text.DispatchActionTableB")))
void DispatchActionTableB(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 1) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BC7B8 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BC7B8 + i8 + 4);
    }
    f0 = *(short *)(D_003BC7B8 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}
