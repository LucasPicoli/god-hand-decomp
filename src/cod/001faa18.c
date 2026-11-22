/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cObj21C0.h"
#include "godhand/cGameObj.h"
#include "godhand/globals.h"

extern char D_00447E68[];
extern int NoOp_279E70();
extern char D_004483A8[];
extern int cCollisionSolidManage_ReleaseUnit_27E088();

/* clone */

__attribute__((section(".text.cCoreSave_addKeyNum")))
/* Add to the key count, clamped to 0..9. */
void cCoreSave_addKeyNum(cCoreSave *self, int n) {
    if (!self->data)
        return;
    self->data->keyNum += n;
    if (self->data->keyNum >= 0xA)
        self->data->keyNum = 9;
    if (self->data->keyNum < 0)
        self->data->keyNum = 0;
}

/* clone */

__attribute__((section(".text.func_0026E7A8")))
void func_0026E7A8(char *a0, float *a1) {
    float *p = (float*)(a0 + 0x1660);
    if (p == a1) return;
    *(float*)(a0 + 0x1660) = a1[0];
    p[1] = a1[1];
    p[2] = a1[2];
}

/* clone */


__attribute__((section(".text.func_002714B0")))
void func_002714B0(char *a0) {
    int v = *(int*)(a0 + 0x1860);
    if (v) {
        __builtin_vec_delete(v);
        *(int*)(a0 + 0x1860) = 0;
    }
}

/* clone */



__attribute__((section(".text.func_00276980")))
void func_00276980(void *a0, int flags) {
    *(char**)((char*)a0+0x214) = D_00447AD0;
    cGameObj__dtor(a0, flags);
}

/* clone */




__attribute__((section(".text.func_00279D40")))
void func_00279D40(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_00447E68;
    NoOp_279E70(a0);
    func_0028EB88(a0, a1);
}

/* clone */



__attribute__((section(".text.func_0027A2F8")))
void func_0027A2F8(void *a0, int flags) {
    *(char**)((char*)a0+0x214) = D_00447F70;
    cGameObj__dtor(a0, flags);
}

/* clone */



__attribute__((section(".text.func_0027ADE8")))
void func_0027ADE8(void *a0, int flags) {
    *(char**)((char*)a0+0x214) = D_00448028;
    cGameObj__dtor(a0, flags);
}

/* clone */




__attribute__((section(".text.func_0027DE18")))
void func_0027DE18(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_004483A8;
    cCollisionSolidManage_ReleaseUnit_27E088(a0);
    func_0028EB88(a0, a1);
}

/* clone */



__attribute__((section(".text.func_00283660")))
void func_00283660(void *a0, int flags) {
    *(char**)((char*)a0+0x214) = D_00448890;
    cGameObj__dtor(a0, flags);
}

/* clone */



__attribute__((section(".text.func_00284040")))
void func_00284040(void *a0, int flags) {
    *(char**)((char*)a0+0x214) = D_00448948;
    cGameObj__dtor(a0, flags);
}
