/* sn-2.95.3-136 matched TU. */

#include "godhand/cOl21.h"
#include "godhand/ColiseumBattle.h"

extern void func_0012EC58(char *a0, void *a1);
extern char D_005CAE50[];
extern char D_00747470[];
extern unsigned char D_0074748C;
extern int D_00747A24[];
extern int D_00747A78;
extern char **D_003C2384;
extern void KeyStop(void);
extern void classFADE_kill(void *p);
extern void classFADE_start(void *p, int b, int c, int d, unsigned int e, unsigned int f, int g);
extern void ColiseumBattle_KillFade(ColiseumBattle *self);
extern void ColiseumBattle_StartFade(ColiseumBattle *self, unsigned char mode);
extern void func_001F28C0(void *ui);
extern void func_001F28F0(void *ui);
extern void func_001F2990(void *ui);
extern void func_001F3260(void *ui);
extern void NoOp_1F0490(ColiseumBattle *self);

/* Release every collision shape this object holds back to the collision manager. */
__attribute__((section(".text.cOl21_releaseShapes")))
void cOl21_releaseShapes(cOl21 *self) {
    int i;

    for (i = 0; i < COL21_SHAPE_NUM; i++) {
        if (self->shape[i] != 0) {
            func_0012EC58(D_005CAE50, self->shape[i]);
            self->shape[i] = 0;
        }
    }
    if (self->shapeExtra != 0) {
        func_0012EC58(D_005CAE50, self->shapeExtra);
        self->shapeExtra = 0;
    }
}

/* sn-2.95.3-136 */


















__attribute__((section(".text.ColiseumBattle_StepUiIntro")))
void ColiseumBattle_StepUiIntro(ColiseumBattle *self)
{
    int done;

    switch (self->state) {
    case 0:
        func_001F3260(self->ui);
        self->timer = 0x3C;
        self->state = self->state + 1;
        break;
    case 2:
        break;
    case 1:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        D_00747A24[0] = D_00747A24[0] | 8;
        self->state = self->state + 1;
        break;
    }
    NoOp_1F0490(self);
    func_001F28F0(self->ui);
    func_001F2990(self->ui);
}

/* sn-2.95.3-136 */


















__attribute__((section(".text.ColiseumBattle_ResetUi")))
void ColiseumBattle_ResetUi(ColiseumBattle *self)
{
    char *obj;

    func_001F28C0(self->ui);
    obj = *D_003C2384;
    *(int *)(obj + 0xAC) = 0;
    *(int *)(obj + 0xA8) = 0;
}

/* sn-2.95.3-136 */


















__attribute__((section(".text.ColiseumBattle_StepEnter")))
void ColiseumBattle_StepEnter(ColiseumBattle *self)
{
    switch (self->state) {
    case 0:
        if (((D_0074748C >> 2) & 1) != 0) {
            ColiseumBattle_ResetUi(self);
            ColiseumBattle_StartFade(self, 0);
            self->state = self->state + 1;
        }
        break;
    case 1:
        if (((D_0074748C >> 2) & 1) != 0) {
            self->flags = self->flags | COLISEUM_FLAG_ENTERED;
            ColiseumBattle_KillFade(self);
            self->state = self->state + 1;
        }
        break;
    case 2:
        break;
    }
}
