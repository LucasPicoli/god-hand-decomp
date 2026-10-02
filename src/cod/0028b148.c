/* sn-2.95.3-136 matched TU. */
#include "godhand/cScenario.h"

extern char D_0044A408[];
extern int MtxCopy();
extern int cTaskManager_execute_2D54F0(cTaskManager *task, void *entry, void *arg, int slot);
extern char D_0044CEE8[];
extern char D_0044E090[];

/* clone */




__attribute__((section(".text.func_0028B148")))
void func_0028B148(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_0044A408;
    func_0028BEA8(a0);
    func_0028EB88(a0, a1);
}

/* clone */


__attribute__((section(".text.func_0028CE70")))
void func_0028CE70(char *a0) {
    int v = *(int*)(a0 + 0x1630);
    if (v) {
        __builtin_vec_delete(v);
        *(int*)(a0 + 0x1630) = 0;
    }
}

/* clone */

__attribute__((section(".text.func_002AF6B8")))
void func_002AF6B8(char *arg0, int arg1) {
    if (arg1) {
        *(int *)(arg0 + 0x0) |= 1;
    } else {
        *(int *)(arg0 + 0x0) &= ~1;
    }
}

/* clone */

__attribute__((section(".text.func_002AF6E0")))
void func_002AF6E0(char *arg0, int arg1) {
    if (arg1) {
        *(int *)(arg0 + 0x0) |= 2;
    } else {
        *(int *)(arg0 + 0x0) &= ~2;
    }
}

/* clone */


__attribute__((section(".text.func_002B6350")))
void func_002B6350(void *a0) { MtxCopy((char *)a0 + 0xB0); }

/* clone */


__attribute__((section(".text.func_002BDBD0")))
void func_002BDBD0(int *a0) {
    unsigned char x = *(unsigned char *)((char *)a0 + 0x10);
    if (((x ^ 1) & 1) == 0) {
        func_002BDC00();
    }
}

/* clone */


__attribute__((section(".text.func_002BE858")))
void func_002BE858(void *a0, int a1) {
    void *p = (void *)(a1 * 8 + (int)a0);
    if (*(unsigned char *)((char *)p + 0x4) == 1)
        func_002BE5F0(p);
}

/* clone */



__attribute__((section(".text.cScenario_taskExec_2C38D8")))
/* Start entry(arg) as a script task in `slot`; returns its index or -1. */
int cScenario_taskExec_2C38D8(cScenario *self, void *entry, void *arg, int slot) {
    int no = cTaskManager_execute_2D54F0(&self->task, entry, arg, slot);
    do {
        cScenario_clearTaskData(self, no);
        return no;
    } while (0);
}

/* clone */



__attribute__((section(".text.cSndBgmNode_Dtor")))
int cSndBgmNode_Dtor(void *a0) {
    *(char**)((char*)a0+0x80) = D_0044CEE8;
    return func_00372C80(a0);
}

/* clone */



__attribute__((section(".text.func_002E16B0")))
int func_002E16B0(void *a0) {
    *(char**)((char*)a0+0xF0) = D_0044E090;
    return func_002FBE28(a0);
}
