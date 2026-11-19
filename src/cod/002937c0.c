/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cCamera.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/capVu0.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"
#include "godhand/mtx.h"
#include "godhand/cVec.h"

/* Pairs em with one of the five special enemies for a joint attack. The
 * partner must be alive, ready, later in the room table, not flashing, idle
 * and not mid-motion; both lines of sight (from above the player out to 15
 * ahead, and from em's spot beside the player to 4 past it) must be clear.
 * em goes to EM_PAIR_LEAD_PHASE at the spot beside the player (x offset by
 * enemy number), the partner to EM_PAIR_MATE_PHASE 3 past it. Returns 1
 * when paired. */
__attribute__((section(".text.func_002937C0")))
int func_002937C0(cEmManage *self, cEm00 *em)
{
    cVec at;
    cVec mate;
    cVec from;
    cVec to;
    float rotY[16];
    cVec dir;
    CVEC_TEMPS;
    unsigned int i;
    cEm00 *other;
    cVec *plPos;
    float yaw;

    if (cEmManage_CkPlCatched(&D_005864F0))
        return 0;
    if (!func_00273EE0(em))
        return 0;
    if (D_005CB010)
        return 0;
    if (Obj0000_IsSet_Field_16D4_Bit_4_26F308(em))
        return 0;

    for (i = 0; i < EM_SPECIAL_NUM; i++) {
        other = (cEm00 *)self->specialEm[i];
        if (other == 0)
            continue;
        if (other->hp <= 0)
            continue;
        if (other == em)
            continue;
        if (!func_00273EB8(other))
            continue;
        if (other->entryNo <= em->entryNo)
            continue;
        if (other->hitFlash > 0.0f)
            continue;
        if (other->mode != 0)
            continue;
        if (other->seqFlags & 0x90C)
            continue;

        CVEC_ZERO(at);
        CVEC_ZERO(mate);
        CVEC_ZERO(from);
        CVEC_ZERO(to);
        CVEC_ASSIGN(from, Getplayer()->pos);
        from.y += 1.0f;
        to.x = -2.0f;
        to.y = 1.0f;
        to.z = 15.0f;
        cVec_applyMatrix(&to, Getplayer()->mtx);
        if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1))
            return 0;

        at.x = -2.0f;
        at.y = 1.0f;
        at.z = 12.0f;
        switch (em->emNo) {
        case 0x271:
            at.x += 1.0f;
            break;
        case 0x272:
            at.x += 2.0f;
            break;
        case 0x273:
            at.x += -1.0f;
            break;
        case 0x274:
            at.x += -2.0f;
            break;
        case 0x270:
        default:
            break;
        }
        cVec_applyMatrix(&at, Getplayer()->mtx);

        CVEC_ZERO(dir);
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

        mate.x = 0.0f;
        mate.y = 0.0f;
        mate.z = 3.0f;
        cVec_applyMatrix(&mate, rotY);
        CVEC_ADD_TO(mate, &at);

        cVec_copy3(&em->unk580, &at);
        em->mode = 0;
        em->phase = EM_PAIR_LEAD_PHASE;
        em->step = 0;
        em->stepArg = 0;
        em->foe = other;
        em->unk1720 = EM_JOINT_TIME;
        em->hitFlash = 30.0f;
        CVEC_ASSIGN_VEC(other->unk580, mate);
        other->mode = 0;
        other->phase = EM_PAIR_MATE_PHASE;
        other->step = 0;
        other->stepArg = 0;
        other->foe = em;
        other->unk1720 = EM_JOINT_TIME;
        other->hitFlash = 30.0f;
        return 1;
    }
    return 0;
}
