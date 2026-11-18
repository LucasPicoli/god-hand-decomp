/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cCamera.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/capVu0.h"
#include "godhand/player.h"
#include "godhand/rand.h"
#include "godhand/sceVu0.h"
#include "godhand/mtx.h"
#include "godhand/cVec.h"

/* Sends the special enemies into a joint attack when at least two are alive
 * and all of those are idle, ready and not flashing. The spot is 12 ahead of
 * the player at a random sideways offset; the line of sight from above the
 * player to 15 ahead and the lines from the spot 4 out to either side must be
 * clear. Two more spots lie 3 out to either side and two halfway between.
 * Formation 1 hands the spots out in table order, the first enemy leading
 * the others; any other value gives each enemy number its own spot. Returns
 * 1 when the attack starts. */
__attribute__((section(".text.func_00293C40")))
int func_00293C40(cEmManage *self, int formation)
{
    cVec at;
    cVec side1;
    cVec side2;
    cVec mid1;
    cVec mid2;
    cVec from;
    cVec to;
    float rotY[16];
    cVec dir;
    CVEC_TEMPS;
    unsigned int i;
    unsigned int alive;
    cEm00 *em;
    cVec *plPos;
    float yaw;

    if (cEmManage_CkPlCatched(&D_005864F0))
        return 0;
    if (D_005CB010)
        return 0;

    alive = 0;
    for (i = 0; i < EM_SPECIAL_NUM; i++) {
        em = (cEm00 *)self->specialEm[i];
        if (em == 0)
            continue;
        if (em->hp <= 0)
            continue;
        if (Obj0000_IsSet_Field_16D4_Bit_4_26F308(em))
            return 0;
        if (em->mode != 0)
            return 0;
        if (em->seqFlags & 0x90C)
            return 0;
        if (em->hitFlash > 0.0f)
            return 0;
        if (Obj0000_IsSet_Field_16D4_Bit_4_26F308(em))
            return 0;
        if (!func_00273EE0(em))
            return 0;
        alive++;
    }
    if (alive < 2)
        return 0;

    /* cVec_zero, not CVEC_ZERO: the macro here changes the register allocation */
    cVec_zero(&at);
    CVEC_ZERO(side1);
    CVEC_ZERO(side2);
    CVEC_ZERO(mid1);
    CVEC_ZERO(mid2);
    CVEC_ZERO(from);
    CVEC_ZERO(to);
    CVEC_ZERO(dir);
    CVEC_ASSIGN(from, Getplayer()->pos);
    from.y += 1.0f;
    to.x = -2.0f;
    to.y = 1.0f;
    to.z = 15.0f;
    cVec_applyMatrix(&to, Getplayer()->mtx);
    if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1))
        return 0;

    at.x = fRand1_1() * 5.0f + -2.0f;
    at.y = 1.0f;
    at.z = 12.0f;
    cVec_applyMatrix(&at, Getplayer()->mtx);

    plPos = Getplayer()->pos;
    CVEC_SUB(&at, plPos);
    dir.x = ret_.x;
    dir.z = ret_.z;
    dir.y = 0.0f;
    yaw = Adjust_theta(capVu0Atan2(dir.x, dir.z) - 1.5707964f);
    MtxInitRotY(rotY, yaw);
    CVEC_ASSIGN(from, &at);
    to.x = 0.0f;
    to.y = 0.0f;
    to.z = 4.0f;
    cVec_applyMatrix(&to, rotY);
    CVEC_ADD_TO(to, &at);
    if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1))
        return 0;
    side1.x = 0.0f;
    side1.y = 0.0f;
    side1.z = 3.0f;
    cVec_applyMatrix(&side1, rotY);
    CVEC_ADD_TO(side1, &at);

    plPos = Getplayer()->pos;
    CVEC_SUB(&at, plPos);
    dir.x = ret_.x;
    dir.z = ret_.z;
    dir.y = 0.0f;
    yaw = Adjust_theta(capVu0Atan2(dir.x, dir.z) + 1.5707964f);
    MtxInitRotY(rotY, yaw);
    CVEC_ASSIGN(from, &at);
    to.x = 0.0f;
    to.y = 0.0f;
    to.z = 4.0f;
    cVec_applyMatrix(&to, rotY);
    CVEC_ADD_TO(to, &at);
    if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1))
        return 0;
    side2.x = 0.0f;
    side2.y = 0.0f;
    side2.z = 3.0f;
    cVec_applyMatrix(&side2, rotY);
    CVEC_ADD_TO(side2, &at);

    CVEC_ADD(&at, &side1);
    mid1.x = ret_.x;
    mid1.y = ret_.y;
    mid1.z = ret_.z;
    CVEC_MUL_SCALAR(mid1, 0.5f);
    CVEC_ADD(&at, &side2);
    mid2.x = ret_.x;
    mid2.y = ret_.y;
    mid2.z = ret_.z;
    CVEC_MUL_SCALAR(mid2, 0.5f);

    switch (formation) {
    case 0:
    default:
        for (i = 0; i < EM_SPECIAL_NUM; i++) {
            em = (cEm00 *)self->specialEm[i];
            if (em == 0)
                continue;
            if (em->hp <= 0)
                continue;
            switch (em->emNo) {
            case 0x270:
            default:
                CVEC_ASSIGN_VEC(em->unk580, side1);
                break;
            case 0x271:
                CVEC_ASSIGN_VEC(em->unk580, side2);
                break;
            case 0x272:
                CVEC_ASSIGN_VEC(em->unk580, mid1);
                break;
            case 0x273:
                CVEC_ASSIGN_VEC(em->unk580, mid2);
                break;
            case 0x274:
                cVec_copy3(&em->unk580, &at);
                break;
            }
            em->mode = 0;
            em->phase = EM_SURROUND_PHASE;
            em->step = 0;
            em->stepArg = 0;
            em->unk1720 = EM_JOINT_TIME;
            em->hitFlash = 3.0f;
        }
        return 1;
    case 1: {
        unsigned int n = 0;
        cEm00 *leader = 0;

        for (i = 0; i < EM_SPECIAL_NUM; i++) {
            em = (cEm00 *)self->specialEm[i];
            if (em == 0)
                continue;
            if (em->hp <= 0)
                continue;
            em->hitFlash = 3.0f;
            switch (n) {
            case 0:
            default:
                cVec_copy3(&em->unk580, &at);
                leader = em;
                em->phase = EM_FORMATION_PHASE;
                em->mode = 0;
                em->step = 0;
                em->stepArg = 0;
                em->foe = 0;
                break;
            case 1:
                CVEC_ASSIGN_VEC(em->unk580, side1);
                em->phase = EM_FORMATION_PHASE;
                em->stepArg = 1;
                em->mode = 0;
                em->step = 0;
                em->foe = leader;
                break;
            case 2:
                CVEC_ASSIGN_VEC(em->unk580, side2);
                em->phase = EM_FORMATION_PHASE;
                em->stepArg = 2;
                em->mode = 0;
                em->step = 0;
                em->foe = leader;
                break;
            case 3:
                CVEC_ASSIGN_VEC(em->unk580, mid1);
                em->phase = EM_FORMATION_PHASE;
                em->stepArg = 3;
                em->mode = 0;
                em->step = 0;
                em->foe = leader;
                break;
            case 4:
                CVEC_ASSIGN_VEC(em->unk580, mid2);
                em->phase = EM_FORMATION_PHASE;
                em->stepArg = 4;
                em->mode = 0;
                em->step = 0;
                em->foe = leader;
                break;
            }
            em->unk568 = 0;
            if (n + 1 == alive)
                em->unk568 = 1;
            em->unk1720 = EM_JOINT_TIME;
            n++;
        }
        return 1;
    }
    }
}
