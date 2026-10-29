/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/vecInline.h"

#define PL_THROWN_KIND 0x3BE            /* CreateObj kind of the thrown object (cOmbe) */

/* Create the object the player throws for move type `type`: place it 1.3 above and to the side of
 * the player (or at the hand part for 0x2F), aim its speed along the player's heading with a side
 * slant picked by `side` for 0x2D, and start it. */
__attribute__((section(".text.func_0012BC00")))
void func_0012BC00(cGameObj *self, int type, unsigned int side)
{
    float mtx[16];
    cVec pos;
    cVec speed;
    int frame[3];
    cGameObj *obj;
    cOmBase *hand;

    obj = CreateObj(PL_THROWN_KIND, 0xFFFF);
    if (obj == 0)
        return;
    cVec_zero(&pos);
    cVec_zero(&speed);
    speed.x = 0.0f;
    speed.y = 0.0f;
    switch (type) {
    case 0x29:
    default:
        speed.z = 0.8f;
        MtxInitRotY(mtx, self->rot[1]);
        cVec_applyMatrix(&speed, mtx);
        pos.x = 0.0f;
        pos.y = 1.3f;
        pos.z = 0.0f;
        cVec_applyMatrix(&pos, self->mtx);
        break;
    case 0x2A:
        speed.z = 0.8f;
        MtxInitRotY(mtx, self->rot[1]);
        cVec_applyMatrix(&speed, mtx);
        pos.x = 1.0f;
        pos.y = 1.3f;
        pos.z = 0.0f;
        cVec_applyMatrix(&pos, self->mtx);
        break;
    case 0x2B:
        speed.z = 0.8f;
        MtxInitRotY(mtx, self->rot[1]);
        cVec_applyMatrix(&speed, mtx);
        pos.x = -1.0f;
        pos.y = 1.3f;
        pos.z = 0.0f;
        cVec_applyMatrix(&pos, self->mtx);
        break;
    case 0x2F:
        speed.z = 1.5f;
        MtxInitRotY(mtx, self->rot[1]);
        cVec_applyMatrix(&speed, mtx);
        pos.x = -1.0f;
        pos.y = 1.3f;
        pos.z = 0.0f;
        cVec_applyMatrix(&pos, self->mtx);
        hand = cOmBase_childAt((cOmBase *)self, frame, 10);
        if (hand != 0)
            cVec_copy3(&pos, hand->pos);
        break;
    case 0x2C:
        /* the same as 0x2E; retail keeps separate jump-table entries */
        speed.z = 1.5f;
        MtxInitRotY(mtx, self->rot[1]);
        cVec_applyMatrix(&speed, mtx);
        pos.x = 0.0f;
        pos.y = 1.3f;
        pos.z = 0.0f;
        cVec_applyMatrix(&pos, self->mtx);
        break;
    case 0x2D:
        switch (side) {
        case 0:
        default:
            speed.x = 0.0f;
            break;
        case 1:
            speed.x = 0.1f;
            break;
        case 2:
            speed.x = -0.1f;
            break;
        }
        speed.z = 1.5f;
        MtxInitRotY(mtx, self->rot[1]);
        cVec_applyMatrix(&speed, mtx);
        pos.x = 0.0f;
        pos.y = 1.3f;
        pos.z = 0.0f;
        cVec_applyMatrix(&pos, self->mtx);
        break;
    case 0x2E:
        speed.z = 1.5f;
        MtxInitRotY(mtx, self->rot[1]);
        cVec_applyMatrix(&speed, mtx);
        pos.x = 0.0f;
        pos.y = 1.3f;
        pos.z = 0.0f;
        cVec_applyMatrix(&pos, self->mtx);
        break;
    }
    obj->vt->initial((char *)obj + obj->vt->initialDelta);
    cVec_copy3(obj->pos, &pos);
    cVec_copy3(&obj->posA, obj->pos);
    vec3_set(obj->rot, 0.0f, 0.0f, 0.0f);
    cOmbe_SetSpeed(obj, self, &speed, type);
}
