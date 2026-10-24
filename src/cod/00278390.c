/* sn-2.95.3-136: func_00278390, enemy per-frame update: player distance, run the current phase handler,
 * show one of the two linked parts by moveFlags bit 15, update the model and IK and keep the follow
 * position in step with the root. */
#include "godhand/cObjBase.h"
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"
#include "godhand/player.h"
#include "godhand/vecInline.h"

#define SYS_FLAG_FREEZE   0x40000000    /* D_00747A78: enemies skip their update */
#define MOVE_F_PART_B     0x8000        /* moveFlags: show part B rather than part A */
#define PART_F_HIDE       1             /* bit of a part's flag word at 0x380 */

/* This enemy keeps two part objects at 0x156C and 0x1570, read as pointers as 001236e8.c does;
 * cEm00.h has a cVec at 0x1570 from other enemies, so these stay raw reads. */
#define EM_PART_A(self)     (*(char **)((char *)(self) + 0x156C))
#define EM_PART_B(self)     (*(char **)((char *)(self) + 0x1570))
#define PART_FLAGS(part)    (*(unsigned int *)((part) + 0x380))

extern unsigned int D_00747A78;         /* system flags */
extern char D_00462FC0[];
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_00278570(char *self);
extern void cObjBase_SetSeqEffect(cObjBase *a0);
extern void func_00279B20(char *self);
extern void cModel_calcParts(cModel *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(cModel *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);

extern EmPhaseTable D_003BFB00;

__attribute__((section(".text.func_00278390")))
void func_00278390(cEm00 *self)
{
    if (D_00747A78 & SYS_FLAG_FREEZE)
        return;
    self->playerDist = capVu0MagnitudeSqXZ(Getplayer()->pos, self->pos);
    func_00278570((char *)self);
    self->unk1560 &= ~2u;
    EM_PHASE_RUN(&D_003BFB00, self, self->mode);

    if (self->moveFlags & MOVE_F_PART_B) {
        if (EM_PART_A(self) != 0)
            PART_FLAGS(EM_PART_A(self)) &= ~PART_F_HIDE;
        if (EM_PART_B(self) != 0)
            PART_FLAGS(EM_PART_B(self)) |= PART_F_HIDE;
    } else {
        if (EM_PART_A(self) != 0)
            PART_FLAGS(EM_PART_A(self)) |= PART_F_HIDE;
        if (EM_PART_B(self) != 0)
            PART_FLAGS(EM_PART_B(self)) &= ~PART_F_HIDE;
    }

    cObjBase_SetSeqEffect(self);
    func_00279B20((char *)self);
    cModel_calcParts(self);
    IK_InverseKinematics(self->ik, self);
    cModel_calcWorldParts(self);
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    vec3_copy(&self->posA.x, &self->pos->x);
}
