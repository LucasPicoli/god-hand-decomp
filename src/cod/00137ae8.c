#include "godhand/cModel.h"

/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_00466448[];
extern void func_002A9790(void *p);
extern void ForwardGlobalIfFlagSet_149550(int a0, int a1);
extern int D_00747A80;
extern int D_00747AA8;
extern void InitStructDefaults_137AA0(void);
extern void *memcpy(void *, const void *, unsigned int);

__attribute__((section(".text.Forward1494F8_149350")))
int Forward1494F8_149350(int a0) {
    return func_001494F8(D_00466448, a0);
}

__attribute__((section(".text.ForwardGlobalIfFlagSet_149550")))
void ForwardGlobalIfFlagSet_149550(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_002A9790(D_00466448);
    }
}

__attribute__((section(".text.Forward149550_149580")))
void Forward149550_149580(void) {
    ForwardGlobalIfFlagSet_149550(1, 0xFFFF);
}

extern int func_001F8AD8(cBox *box, float *mtx);
/* True when the model should be drawn: forced on by the render state or the
 * model, never when it is hidden, else whether its box is in view. */
__attribute__((section(".text.IsTargetVisible_14B470")))
int IsTargetVisible_14B470(cModel *self) {
    int flags;
    if (D_00747A80 & 0x800000) {
        return 1;
    }
    flags = self->objFlags;
    if (flags & CMODEL_F_SHOWN) {
        return 1;
    }
    if (flags & CMODEL_F_HIDDEN) {
        return 0;
    }
    return func_001F8AD8(&self->box, self->mtx) == 0;
}

extern int func_00148BD8(cModelNode *node, int prio, int arg, int mode);
extern int func_00148D30(cModelNode *node, int prio);
/* Hand the node to the special-pass material when its mesh asks for it and the
 * pass is on; else to the plain one. */
__attribute__((section(".text.ForwardAttackByMode_14B5D8")))
int ForwardAttackByMode_14B5D8(cModel *self, cModelNode *node) {
    if (node->info->flags & CMODEL_MESH_SPECIAL) {
        int pass = D_00747AA8;
        if (pass) {
            return func_00148BD8(node, self->drawPrio, pass, 0);
        }
    }
    return func_00148D30(node, self->drawPrio);
}

__attribute__((section(".text.cAreaCamManager_SetData")))
int cAreaCamManager_SetData(int a0, int a1)
{
    if (a1 == 0) goto fail;
    memcpy((void *)(a0 + 4), (void *)a1, 0x2C);
    if (*(int *)(a0 + 4) != 0x444341) goto fail;
    if (*(int *)(a0 + 8) == 1) {
        *(int *)(a0 + 0) = a1 + 0x18;
        *(float *)(a0 + 0x1C) = 1.06f;
    } else {
        *(int *)(a0 + 0) = a1 + 0x2C;
    }
    return 1;
fail:
    InitStructDefaults_137AA0();
    return 0;
}
