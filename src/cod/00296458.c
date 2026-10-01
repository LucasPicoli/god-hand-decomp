/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cEvent.h"

extern unsigned int D_00747A84;
extern int D_00586B34;
extern char D_00747470[];
extern int D_00747A30;
extern char D_0044A920[];
extern char D_0044A940[];
extern char D_0044A958[];
extern char D_00583F20[];
extern int D_003C3CF0;
extern void func_003A6C58(void *a0, void *a1, void *a2);

extern int cDvd_ReadAlloc(void *, void *, void *, void *, int, int, int, int);
/* Start reading the cutscene entry unless the text is already linked in. */
__attribute__((section(".text.LoadResourceEntry_297378")))
void LoadResourceEntry_297378(cEvent *self) {
    unsigned long b = *(unsigned char *)&self->flags;
    int buf[16];
    if ((b >> 7) != 0) return;
    if ((D_00747A30 & 0x400) != 0) {
        func_003A6C58(buf, D_0044A920, D_0044A940);
    } else {
        func_003A6C58(buf, D_0044A958, D_0044A940);
    }
    /* raw stores: the typed members let the D_003C3CF0 load float above them */
    *(int *)((char *)self + CEVENT_OFFSET(resData)) = 0;
    *(int *)((char *)self + CEVENT_OFFSET(loadHandle)) =
        cDvd_ReadAlloc(D_00583F20, buf, &self->resData, (void *)D_003C3CF0, 0, 0, 0, 0);
}
