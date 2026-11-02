/* sn-2.95.3-136 */
#include "godhand/cEmManage.h"
#include "godhand/cEm00.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"

#define EM_LINEUP_PHASE  0x41
#define EM_LINEUP_TIME   300.0f

/* Send the five special enemies to points on a line in the player's frame
 * (x -2, z 12 to 20; 0x274 nearest, then 0x270..0x273) when at least two
 * of them are free to act and the line out to z 23 is clear. Returns 1
 * when they were sent. */
__attribute__((section(".text.func_00294488")))
int func_00294488(cEmManage *self)
{
    cVec slot[EM_SPECIAL_NUM];
    cVec from;
    cVec to;
    cEm00 *em;
    unsigned int i;
    unsigned int ready;

    if (cEmManage_CkPlCatched(&D_005864F0)) {
        return 0;
    }
    if (D_005CB010 != 0) {
        return 0;
    }
    ready = 0;
    for (i = 0; i < EM_SPECIAL_NUM; i++) {
        em = (cEm00 *)self->specialEm[i];
        if (em == 0 || em->vital <= 0) {
            continue;
        }
        if (Obj0000_IsSet_Field_16D4_Bit_4_26F308(em)) {
            return 0;
        }
        if (em->mode != 0) {
            return 0;
        }
        if (em->moveFlags & 0x90C) {
            return 0;
        }
        if (em->hitFlash > 0.0f) {
            return 0;
        }
        /* retail tests the 0x16D4 bit a second time */
        if (Obj0000_IsSet_Field_16D4_Bit_4_26F308(em)) {
            return 0;
        }
        if (func_00273EE0(em) == 0) {
            return 0;
        }
        ready++;
    }
    if (ready < 2) {
        return 0;
    }

    cVec_zero(&slot[0]);
    cVec_zero(&slot[1]);
    cVec_zero(&slot[2]);
    cVec_zero(&slot[3]);
    cVec_zero(&slot[4]);
    cVec_zero(&from);
    cVec_zero(&to);
    cVec_copy3(&from, Getplayer()->pos);
    from.y += 1.0f;
    to.x = -2.0f;
    to.y = 1.0f;
    to.z = 23.0f;
    cVec_applyMatrix(&to, Getplayer()->mtx);
    if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
        return 0;
    }
    slot[0].x = -2.0f;
    slot[0].y = 1.0f;
    slot[0].z = 12.0f;
    cVec_applyMatrix(&slot[0], Getplayer()->mtx);
    slot[1].x = -2.0f;
    slot[1].y = 1.0f;
    slot[1].z = 14.0f;
    cVec_applyMatrix(&slot[1], Getplayer()->mtx);
    slot[2].x = -2.0f;
    slot[2].y = 1.0f;
    slot[2].z = 16.0f;
    cVec_applyMatrix(&slot[2], Getplayer()->mtx);
    slot[3].x = -2.0f;
    slot[3].y = 1.0f;
    slot[3].z = 18.0f;
    cVec_applyMatrix(&slot[3], Getplayer()->mtx);
    slot[4].x = -2.0f;
    slot[4].y = 1.0f;
    slot[4].z = 20.0f;
    cVec_applyMatrix(&slot[4], Getplayer()->mtx);

    for (i = 0; i < EM_SPECIAL_NUM; i++) {
        em = (cEm00 *)self->specialEm[i];
        if (em == 0 || em->vital <= 0) {
            continue;
        }
        switch (em->emNo) {
        case 0x270:
        default:
            cVec_copy3(&em->unk580, &slot[1]);
            break;
        case 0x271:
            cVec_copy3(&em->unk580, &slot[2]);
            break;
        case 0x272:
            cVec_copy3(&em->unk580, &slot[3]);
            break;
        case 0x273:
            cVec_copy3(&em->unk580, &slot[4]);
            break;
        case 0x274:
            cVec_copy3(&em->unk580, &slot[0]);
            break;
        }
        em->phase = EM_LINEUP_PHASE;
        em->unk1720 = EM_LINEUP_TIME;
        em->mode = 0;
        em->step = 0;
        em->stepArg = 0;
        em->hitFlash = 3.0f;
    }
    return 1;
}
