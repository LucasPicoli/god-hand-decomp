/* cygnus-2.96: MPVM2V_DecodePicAtr, programs four 3-word channel params plus globals into the device, then commits. */
#include "godhand/devObj.h"
extern int Obj0000_Get_D_003F1FF0_36CCA8(void);
extern void func_0036CDC0(int dev, int idx, int a, int b, int c);
extern void func_0036CDE8(int dev, int p0, int p1);
extern int func_0036CE38(int dev, int arg);
extern void func_0036CE10(int dev, int zero, void *buf);
extern void mpvm2v_CopyPicAtr(DevObj *obj);

__attribute__((section(".text.MPVM2V_DecodePicAtr")))
int MPVM2V_DecodePicAtr(DevObj *obj, int arg)
{
    DevChParam *ch;
    int i;

    if (Obj0000_Get_D_003F1FF0_36CCA8() != 0) {
        i = 0;
        ch = obj->ch;
        do {
            func_0036CDC0(obj->dev, i, ch->a, ch->b, ch->c);
            i++;
            ch++;
        } while (i < 4);
        func_0036CDE8(obj->dev, obj->p0, obj->p1);
        if (func_0036CE38(obj->dev, arg) != 0)
            return -2;
        func_0036CE10(obj->dev, 0, obj->unk3F4);
        mpvm2v_CopyPicAtr(obj);
        return 0;
    }
    return -1;
}
