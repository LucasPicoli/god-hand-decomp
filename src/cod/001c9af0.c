/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmWeapon.h"
#include "godhand/cEmManage.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cVec.h"
#include "godhand/effectPos.h"

#define WEAPON_GRAVITY   0.013f
#define WEAPON_MIN_SPEED (-1.95f)
#define WEAPON_REST_OFS  0.15f
#define WEAPON_SPIN      0.5235988f

/* Set the object's mode, phase, step and step argument together. */
static __inline__ void setMoveState(cOmBase *self, unsigned char mode, unsigned char phase, unsigned char step, unsigned char stepArg)
{
    self->mode = mode;
    self->phase = phase;
    self->step = step;
    self->stepArg = stepArg;
}

/* A dropped weapon: falls (spinning its body) until it lands on the floor,
 * plays its landing sound and effect, then waits; kind 0x3AF goes back to
 * mode 1 when its countdown (fallVel) runs out. */
__attribute__((section(".text.func_001C9AF0")))
void func_001C9AF0(cOmWeapon *self)
{
    int frame[3]; /* 12 bytes at sp+0x30 for cOmBase_childAt's dead store (sw at 0x1C9B20); frame[1] is 1 word short */
    cVec to;
    cVec from;
    cVec hit;
    float rate;
    cOmBase *body;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    body = cOmBase_childAt(&self->base, frame, 0);
    if (self->parent != 0) {
        return;
    }
    CVEC_ZERO(to);
    CVEC_COPY(from, self->base.pos);
    CVEC_ZERO(hit);
    switch (self->base.step) {
    case 0:
        self->base.unk531 = 2;
        self->fallVel = 450.0f;
        self->base.step++;
        self->base.unk56A = 0;
        /* fall through */
    case 1:
        if (body != 0) {
            body->rot.x += rate * WEAPON_SPIN;
        }
        self->base.pos->y += self->fallSpeed * rate;
        self->fallSpeed -= rate * WEAPON_GRAVITY;
        if (self->fallSpeed < WEAPON_MIN_SPEED) {
            break;
        }
        CVEC_ASSIGN(to, self->base.pos);
        to.y -= 1.0f;
        from.y += 0.5f;
        if (ChkLine(&from, &to, &hit, 0, 2, 0x534, 0, 0, 0, 0, 0, 0, 1) != 0
            && self->base.pos->y < hit.y + WEAPON_REST_OFS) {
            self->base.pos->y = hit.y + WEAPON_REST_OFS;
            self->fallSpeed = 0.0f;
            switch (self->base.actorId) {
            case 0x361: /* retail's sound table starts at 0x361 */
            default:
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x115, (cObj *)self, 0, 0, 0, 0);
                break;
            case 0x362: case 0x36D: case 0x375: case 0x377: case 0x378:
            case 0x3A8: case 0x3A9: case 0x3AA: case 0x3AB: case 0x3AD:
            case 0x3AE: case 0x3B4:
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x116, (cObj *)self, 0, 0, 0, 0);
                break;
            case 0x363:
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x11E, (cObj *)self, 0, 0, 0, 0);
                break;
            case 0x380:
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xEA, (cObj *)self, 0, 0, 0, 0);
                break;
            case 0x3B7:
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x27, (cObj *)self, 0, 0, 0, 0);
                break;
            case 0x3AF:
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xD4, (cObj *)self, 0, 0, 0, 0);
                break;
            }
            SetEffect(0, 0x2D, (cObj *)self, 0, -1, EFFECT_FOLLOW_OWNER);
            self->base.step++;
            if (body != 0) {
                body->rot.x = 0.0f;
                body->rot.y = 0.0f;
                body->rot.z = 0.0f;
            }
        }
        LineObj_checkWaterHit(self);
        return;
    case 2:
        if (--self->base.unk56A <= 0) {
            self->base.unk56A = 60;
            SetEffectPos(0, 0x1B, 0, self->base.pos, 1.0f, -1);
        }
        self->unk664 = 1;
        self->base.pos->y += self->fallSpeed * rate;
        self->fallSpeed -= rate * WEAPON_GRAVITY;
        if (self->fallSpeed < WEAPON_MIN_SPEED) {
            break;
        }
        CVEC_ASSIGN(to, self->base.pos);
        to.y -= 1.0f;
        from.y += 0.5f;
        if (ChkLine(&from, &to, &hit, 0, 2, 0x534, 0, 0, 0, 0, 0, 0, 1) != 0
            && self->base.pos->y < hit.y + WEAPON_REST_OFS) {
            self->base.pos->y = hit.y + WEAPON_REST_OFS;
            self->fallSpeed = 0.0f;
        }
        if (self->base.actorId != 0x3AF) {
            return;
        }
        self->fallVel -= rate;
        if (self->fallVel <= 0.0f) {
            setMoveState(&self->base, 1, 0, 0, 0);
        }
        return;
    case 3:
        self->unk665 = 1;
        self->unk664 = 1;
        return;
    case 4:
        self->base.unk531 = -1;
        self->fallVel = 15.0f;
        self->base.step++;
        self->base.unk56A = 0;
        /* fall through */
    case 5:
        if (body != 0) {
            body->rot.x += rate * WEAPON_SPIN;
        }
        self->base.pos->y += self->fallSpeed * rate;
        self->fallVel -= rate;
        self->fallSpeed -= rate * WEAPON_GRAVITY;
        if (self->fallVel <= 0.0f) {
            setMoveState(&self->base, 1, 0, 0, 0);
        }
        return;
    default:
        return;
    }
    setMoveState(&self->base, 1, 0, 0, 0);
}
