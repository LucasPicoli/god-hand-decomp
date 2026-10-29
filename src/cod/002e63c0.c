/* sn-2.95.3-136: create and set up the model object for a slot (0x2E63C0). */
#include "godhand/cGameObj.h"

extern int func_00306C78(void **table, unsigned int index, void *out1, void *out2);
extern void func_002D9F68(void *self, const char *fmt, ...);
extern cGameObj *CreateObj(int kind, int id);
extern int cModel_setupModel(void *obj, int data, int size, int a3, int a4);
extern void ReleaseObj(void *obj);
extern char D_00741DC8[];
extern char D_0044E3B0[];
extern char D_0044E3D8[];
extern char D_0044E3F8[];
extern char D_0044E418[];

__attribute__((section(".text.func_002E63C0")))
int func_002E63C0(char *self)
{
    int ptr;
    int size;
    cGameObj *obj;
    char *vt;

    if (func_00306C78(D_00741DC8, *(int *)(self + 0x2B4), &ptr, &size) == 0) {
        func_002D9F68(self, D_0044E3B0, *(int *)(self + 0x2B4));
        return 0;
    }
    obj = CreateObj(0x500, 0xFFFF);
    *(cGameObj **)(self + 0x2B0) = obj;
    if (obj == 0) {
        func_002D9F68(self, D_0044E3D8);
        return 0;
    }
    vt = (char *)obj->vtable;
    if ((*(int (**)(void *))(vt + 0x44))((char *)obj + *(short *)(vt + 0x40)) == 0) {
        func_002D9F68(self, D_0044E3F8);
        ReleaseObj(*(void **)(self + 0x2B0));
        return 0;
    }
    if (cModel_setupModel(*(void **)(self + 0x2B0), ptr, size, 0, 0) == 0) {
        func_002D9F68(self, D_0044E418);
        ReleaseObj(*(void **)(self + 0x2B0));
        return 0;
    }
    return 1;
}
