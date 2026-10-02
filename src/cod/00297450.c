/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cEvent.h"

extern void func_003A6C58(void *a0, void *a1, void *a2);
extern int D_00747A30;
extern unsigned char D_0044A920[];
extern unsigned char D_0044A940[];
extern unsigned char D_0044A958[];
extern unsigned char D_005E8640[];
extern void cRelSys_unlinkNoFree(void *a0, int a1);
extern void func_00297660(void);
extern void cEventConfig_setEventNo(void *a0, int a1);
extern unsigned char D_00586B30[];

extern int cRelSys_linkNoAlloc(void *, int, void *, int);
/* Link the loaded display text into the text system, once. */
__attribute__((section(".text.LoadDisplayText_297450")))
void LoadDisplayText_297450(cEvent *self) {
    char buf[0x40];
    unsigned long b = *(unsigned char *)&self->flags;
    int data;
    if ((b >> 7) == 0) {
        if (D_00747A30 & 0x400) {
            func_003A6C58(buf, D_0044A920, D_0044A940);
        } else {
            func_003A6C58(buf, D_0044A958, D_0044A940);
        }
        data = self->resData;
        if (data != 0) {
            cRelSys_linkNoAlloc(D_005E8640, data, buf, 2);
            self->flags = self->flags | CEVENT_F_TEXT_ON;
        }
    }
}

/* Unlink the display text if it is linked in. */
__attribute__((section(".text.ClearDisplayText_2974F0")))
void ClearDisplayText_2974F0(cEvent *self) {
    unsigned long v0 = *(unsigned char *)&self->flags;
    if (v0 >> 7) {
        cRelSys_unlinkNoFree(D_005E8640, 2);
        self->flags = self->flags & ~CEVENT_F_TEXT_ON;
    }
}

/* Start the cutscene numbered `no`, once per record. */
__attribute__((section(".text.cEvent_initEnv")))
void cEvent_initEnv(cEvent *self, int no) {
    unsigned long t = self->flags;
    if (((t >> 1) & 1) == 0) {
        func_00297660();
        self->dataNo = no;
        cEventConfig_setEventNo(D_00586B30, no);
        self->flags = self->flags | CEVENT_F_INITED;
    }
}
