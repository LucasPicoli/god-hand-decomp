/* cygnus-2.96: mpvm2v_CopyPicAtr, reads back the device status block and counters into the object. */
#include "godhand/devObj.h"
extern void func_0036CE68(int dev, DevStat *stat);
extern void func_0036CE90(int dev, int *a);
extern void func_0036CEB8(int dev, int *b, int *c, int *x);
extern void func_0036CEE0(int dev, int *d, int *e);

__attribute__((section(".text.mpvm2v_CopyPicAtr")))
void mpvm2v_CopyPicAtr(DevObj *obj)
{
    DevStat stat;
    int a, b, c, x, d, e;

    func_0036CE68(obj->dev, &stat);
    func_0036CE90(obj->dev, &a);
    func_0036CEB8(obj->dev, &b, &c, &x);
    func_0036CEE0(obj->dev, &d, &e);
    obj->stat = stat;
    obj->a = a;
    obj->blocks = b / 2048;
    obj->c = c;
    obj->d = d;
    obj->e = e;
}
