/* cygnus-2.96: Sofdec handle destroy, releasing each sub-resource before clearing the handle (0x3443E0). */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern void func_003497F8(int on);
extern void func_00345DF0(MwsfdHn *self);
extern void func_00347370(MwsfdHn *self);
extern void Forward35FB88_346C30(void *p);
extern void func_00335500(void *p);
extern int Forward327D90_349AB8(void *p);
extern void func_00342B98(void *p);
extern void MWSFCRE_DestroySfd(void *sfd);
extern void func_00348870(MwsfdSlot *slot);
extern void func_00344710(MwsfdHn *self);
extern int func_00344790(MwsfdHn *self);
extern void *func_003A52F0(void *p, int c, int n);

__attribute__((section(".text.func_003443E0")))
void func_003443E0(MwsfdHn *self)
{
    if (self == 0) {
        return;
    }
    func_003497F8(1);
    func_00345DF0(self);
    self->used = 0;
    func_003497F8(0);
    func_00347370(self);
    if (self->unkA8 != 0) {
        Forward35FB88_346C30(self->unkA8);
    }
    if (self->stm != 0) {
        func_00335500(self->stm);
    }
    if (self->unk40 != 0) {
        Forward327D90_349AB8(self->unk40);
    }
    if (self->sub1C0 != 0) {
        self->sub1C0->vt->destroy(self->sub1C0);
    }
    if (self->sub1E0 != 0) {
        self->sub1E0->vt->destroy(self->sub1E0);
    }
    if (self->unk2D0 != 0) {
        func_00342B98(self->unk2D0);
    }
    if (self->sfd != 0) {
        MWSFCRE_DestroySfd(self->sfd);
    }
    func_00348870(&self->slot[0]);
    func_00348870(&self->slot[1]);
    func_00344710(self);
    if (func_00344790(self) != 0) {
        MWSFSVM_Error(D_004576A0);
    }
    func_003A52F0(self, 0, 0x304);
    self->used = 0;
}
