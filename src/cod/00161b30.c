/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cOm1f.h"

extern int cOm5a_setCloseFix();
extern int cOm5a_setOpenFix();
extern int ClearAndResetFields_1FE278();
extern char D_00420328[];
extern char D_00574380[];
extern int ResetField214FreeField180_1C2820();
extern char D_00420920[];
extern int InitField214WithPtr429420_1BD650();

/* clone */

__attribute__((section(".text.cCoreSave_setKeyNum")))
void cCoreSave_setKeyNum(cCoreSave *self, int num) {
    if (!self->data)
        return;
    self->data->keyNum = num;
    if (self->data->keyNum > CORESAVE_KEY_MAX)
        self->data->keyNum = CORESAVE_KEY_MAX;
    if (self->data->keyNum < 0)
        self->data->keyNum = 0;
}

/* clone */

__attribute__((section(".text.cMessage_searchWorkId")))
void *cMessage_searchWorkId(void *a0, int a1) {
    void *v1 = *(void**)((char*)a0 + 0x10);
    unsigned short w = (unsigned short)(a1 & 0xFFFF);
    while (v1 != 0) {
        if (*(unsigned short*)((char*)v1 + 0x0) == w) return v1;
        v1 = *(void**)((char*)v1 + 8);
    }
    return 0;
}

/* clone */

/* Copy x, y and z of the new home point (w is left alone). */
__attribute__((section(".text.cOm1f_setHomePos")))
void cOm1f_setHomePos(cOm1f *self, float *pos) {
    float *p = self->homePos;
    if (p == pos) return;
    self->homePos[0] = pos[0];
    p[1] = pos[1];
    p[2] = pos[2];
}

/* clone */

__attribute__((section(".text.cOm5a_setClose")))
void cOm5a_setClose(unsigned char *a0)
{
    unsigned char v = a0[0x60D];
    if (v == 1) {
        a0[0x60E] = v;
        a0[0x2F4] = 2;
        a0[0x2F5] = 0;
        a0[0x2F6] = 0;
        a0[0x2F7] = 0;
    }
}

/* clone */



__attribute__((section(".text.cOm5a_setOpenType")))
void cOm5a_setOpenType(int a0, int a1) {
    if (*(int *)((char *)a0 + 0x600) == a1) {
        return;
    }
    if (*(unsigned char *)((char *)a0 + 0x60D) == 1) {
        cOm5a_setCloseFix(a0);
        *(int *)((char *)a0 + 0x600) = a1;
        cOm5a_setOpenFix(a0);
    } else {
        *(int *)((char *)a0 + 0x600) = a1;
    }
}

/* clone */

__attribute__((section(".text.func_00161B30")))
int func_00161B30(int a0)
{
    int v0;
    switch (*(unsigned char *)((char *)a0 + 0x64)) {
    default:
        v0 = -0x1;
        break;
    case 0:
        v0 = 10;
        *(int *)((char *)a0 + 0x60) = v0;
        break;
    case 1:
        v0 = -0x1;
        *(int *)((char *)a0 + 0x60) = v0;
        break;
    }
    return v0;
}

/* clone */

__attribute__((section(".text.func_00162720")))
int func_00162720(int a0)
{
    int v0;
    switch (*(unsigned char *)((char *)a0 + 0x64)) {
    default:
        v0 = -0x1;
        break;
    case 0:
        v0 = 10;
        *(int *)((char *)a0 + 0x60) = v0;
        break;
    case 1:
        v0 = -0x1;
        *(int *)((char *)a0 + 0x60) = v0;
        break;
    }
    return v0;
}

/* clone */

__attribute__((section(".text.func_00167328")))
void func_00167328(int a0)
{
    int **p = (int **)((char *)a0 + 0x80);
    unsigned int i = 0;
    do {
        int *q = *p;
        i++;
        p++;
        *(int *)((char *)q + 0x2C) |= 0x08000000;
    } while (i < 24);
}

/* clone */





__attribute__((section(".text.func_0016FD08")))
void func_0016FD08(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00420328;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */



__attribute__((section(".text.func_00170F38")))
int func_00170F38(void *a0) {
    *(char**)((char*)a0+0x214) = D_00420920;
    return InitField214WithPtr429420_1BD650(a0);
}
