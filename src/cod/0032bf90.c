/* cygnus-2.96: Sofdec stream-joint position feed (0x32BF90..0x32C1E0). */

#include "godhand/criSj.h"
#include "godhand/globals.h"

void func_0032C048(char *self);

__attribute__((section(".text.func_0032BF90")))
void func_0032BF90(char *self)
{
    void *sj = *(void **)(self + 4);
    int top = GetVia4_Obj33C8_GetField_28_7818_327818(sj);
    int size = func_00327830(sj);
    int end = GetVia4_Obj33C8_GetField_30_7860_327860(sj);
    int len;

    Forward33CFB8_327970(sj);
    len = end - top;
    Obj3270_SetField_40(sj, 0);
    *(int *)(self + 0x90) = len;
    Obj3270_SetField_3C(sj, len);
    Obj3270_SetField_44(sj, size);
    Obj3270_SetField_34(sj, top);
    Obj3270_SetField_48_4C(sj, func_0032C048, self);
}

__attribute__((section(".text.func_0032C048")))
void func_0032C048(char *self)
{
    void *sj = *(void **)(self + 4);
    SjObj *in = *(SjObj **)(self + 0x14);
    int top = GetVia4_Obj33C8_GetField_28_7818_327818(sj);
    int size = func_00327830(sj);
    int end = GetVia4_Obj33C8_GetField_30_7860_327860(sj);
    int len;
    SjChunk ck;

    if ((*(signed char *)(self + 2) == 2 || *(signed char *)(self + 2) == 3) &&
        *(signed char *)(self + 0x6C) == 0) {
        Obj3270_SetField_3C(*(void **)(self + 4), -1);
        return;
    }
    in->vt->getChunk(in, 1, *(int *)(self + 0x50), &ck);
    if (ck.len < *(int *)(self + 0x50)) {
        func_0033F130(D_00452890);
    }
    in->vt->putChunk(in, 0, &ck);
    Obj3270_SetField_40(sj, 0);
    len = end - top;
    *(int *)(self + 0x90) = len;
    Obj3270_SetField_3C(sj, len);
    Obj3270_SetField_44(sj, size);
    Obj3270_SetField_34(sj, top);
    if (*(signed char *)(self + 2) == 2) {
        in->vt->reset(in);
        in->vt->getChunk(in, 1, size, &ck);
        in->vt->putChunk(in, 0, &ck);
    }
    Forward33CFF8_327988(sj);
    *(int *)(self + 0x4C) += 1;
}
