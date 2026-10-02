/* sn-2.95.3-136 matched TU. */

#include "godhand/cMc.h"

extern void func_0();
extern char cEvent_nullStr00[];
extern unsigned int D_00747A30;
extern char D_0044B0B0[];
extern char D_0044B0E8[];
extern char D_00583F20[];
extern char D_00754230[];
extern cMcTaskRef D_00752C00;
extern void func_003A6C58(char *dst, char *src);
extern int cDvd_ReadAlloc(void *dvd, char *name, void **out, void *heap, int a, int b, int c, int d);
extern int cDvd_Check(void *dvd, int id);
extern void cMc_Move(cMc *self);
extern void cMc_Trans(cMc *self);
extern void cTaskWork_sleep(void *task, int frames);

extern void cMc_DllRelease(cMc *self);

/* Load the memory card module from disc into a heap block and link it.
 * With `pump` set the frame keeps running (move and draw) while the read
 * is pending. A failed link releases it again. The task reference is a typed
 * global: through a char array the address setup and the loop branch differ. */
__attribute__((section(".text.cMc_DllLoad")))
void cMc_DllLoad(cMc *self, int pump) {
    char name[0x80];
    int req;
    if (self->loaded == 1) return;
    if ((D_00747A30 & 0x400) != 0) {
        func_003A6C58(name, D_0044B0B0);
    } else {
        func_003A6C58(name, D_0044B0E8);
    }
    req = cDvd_ReadAlloc(D_00583F20, name, &self->dll, D_00754230, 0, 0, 0, 0);
    if (req == 0) return;
    while (cDvd_Check(D_00583F20, req) != 0) {
        if (pump == 1) {
            cMc_Move(self);
            cMc_Trans(self);
        }
        cTaskWork_sleep(D_00752C00.task, 1);
    }
    if (func_00394DD8(self->dll, 0) != 0) {
        cMc_DllRelease(self);
        return;
    }
    self->loaded = 1;
    func_0(cEvent_nullStr00);
}
