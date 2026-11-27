/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cCamera.h"
#include "godhand/player.h"
#include "godhand/vu0.h"
#include "godhand/capVu0.h"
#include "godhand/vecInline.h"
#include "godhand/fpu.h"

#define AIM_EM_NO      0x20D            /* only this enemy number aims its part */
#define AIM_PART       31               /* the child that turns */
#define AIM_FLAG2      0x20000          /* emFlags2 bit: aim at the player, else level out */
#define AIM_HEAD_UP    1.7f             /* the aim point above the player's position */
#define AIM_TURN_STEP  0.09817477f      /* pi/32 per frame at speed rate 1 */

/* The frame: the dead part count at 0, the aim direction, the aim point, a copy of the offset, the offset. */
typedef struct AimFrame {
    int count;
    char unk04[0xC];
    cVec dir;
    cVec at;
    cVec work;
    cVec diff;
} AimFrame;

#define AIMFRAME_OFFSET(field) ((int)&((AimFrame *)0)->field)

/* Turn child 31 of enemy 0x20D up or down toward the player's head, or back to level. */
__attribute__((section(".text.func_00274D18")))
void func_00274D18(cEm00 *self)
{
    AimFrame f;
    cGameObj *part;
    cVec *p;
    float target, step, cur, flat;

    if ((self->emNo ^ AIM_EM_NO) != 0)
        return;
    part = (cGameObj *)cOmBase_childAt((cOmBase *)self, &f.count, AIM_PART);
    if (part == 0)
        return;
    if (self->emFlags2 & AIM_FLAG2) {
        VU0_SQC2_VF0_MEM(&f.dir, 0);
        VU0_SQC2_VF0_MEM(&f.at, 0);
        p = Getplayer()->pos;
        vec3_copy(&f.at.x, &p->x);
        f.at.y += AIM_HEAD_UP;
        VU0_ZERO_VSUB_XYZ_TO(&f.diff, 0, &f.at, part->pos);
        VU0_LQC2(4, &f.diff, 0);
        VU0_SQC2(4, &f, AIMFRAME_OFFSET(work));
        f.dir.x = f.work.x;
        f.dir.y = f.work.y;
        f.dir.z = f.work.z;
        FPU_SQRT_S(flat, f.dir.x * f.dir.x + f.dir.z * f.dir.z);
        target = -capVu0Atan2(f.dir.y, flat);
        step = AIM_TURN_STEP;
        cur = part->rot.x;
        step = self->speedRate * step;
    } else {
        step = AIM_TURN_STEP;
        cur = part->rot.x;
        step = self->speedRate * step;
        target = 0.0f;
    }
    part->rot.x += Turn_dest_dir(cur, target, step);
    part->rot.x = Adjust_theta(part->rot.x);
}
