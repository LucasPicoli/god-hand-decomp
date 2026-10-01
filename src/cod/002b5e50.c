/* cygnus-2.96 matched TU. */
#include "godhand/CustomIDWork.h"

extern void Obj3290_Tramp_0033E6A8_9070(void *);
extern void func_00328488(void *, void *);
extern void Obj3290_Tramp_0033E6B0_9088(void);
extern void NoOp_33E6A8(void *);
extern void func_0032B340(void *, void *);
extern void NoOp_33E6B0(void);
extern void func_003A57C4(void *, void *);
extern void func_003A53A8(void *, void *);
extern void Forward33B790_340AE8(void *);

__attribute__((section(".text.func_002B5E50")))
int func_002B5E50(void *a0) {
    return *(int *)((char *)a0 + 4);
}

__attribute__((section(".text.func_00373A50")))
int func_00373A50(void *a0) {
    return *(int *)((char *)a0 + 0x48);
}

/* Stops the colour animation and restores the resting colour. */
__attribute__((section(".text.CustomIDWork_ResetColorAnim")))
void CustomIDWork_ResetColorAnim(CustomIDWork *self) {
    CustomIDObj *obj;
    int rest;

    obj = self->obj;
    if (obj == 0) {
        return;
    }
    rest = *(int *)self->restColor;
    self->colorFlags = 0;
    *(int *)obj->color = rest;
}

__attribute__((section(".text.func_00328448")))
void func_00328448(void *a0, void *a1) {
    Obj3290_Tramp_0033E6A8_9070(a0);
    func_00328488(a0, a1);
    Obj3290_Tramp_0033E6B0_9088();
}

__attribute__((section(".text.func_0032B300")))
void func_0032B300(void *a0, void *a1) {
    NoOp_33E6A8(a0);
    func_0032B340(a0, a1);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_0033A048")))
void func_0033A048(void *a0, void *a1) {
    char buf[0x40];
    func_003A57C4(buf, a0);
    func_003A53A8(buf, a1);
    Forward33B790_340AE8(buf);
}
