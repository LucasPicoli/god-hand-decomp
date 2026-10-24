/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

typedef struct EmAimFrame {
    cVec ofs;
    int childNum;
} EmAimFrame;

/* cOmBase_childAt with the result in a local: the shared form loads the child straight
 * into its final register, where retail goes through a temporary. */
static __inline__ cOmBase *em_child(cOmBase *b, int *frame, int idx)
{
    int n;
    cOmBase *c;

    *frame = n = b->childNum;
    if (idx >= 0 && idx < n) {
        c = b->children[idx];
    } else {
        c = 0;
    }
    return c;
}

extern float capVu0MagnitudeSqXZ(void *a0, void *a1);

/* The point the player aims at on a multi-part enemy: the body, or the nearest marked part. */
__attribute__((section(".text.func_00275978")))
cVec *func_00275978(cEm00 *self)
{
    cGameObj *pl = Getplayer();
    EmAimFrame f;
    cOmBase *part;
    float best;

    VU0_SQC2_VF0_MEM(&f.ofs, 0);
    cVec_copy3(&self->aimPos, self->pos);
    switch (self->emNo) {
    case 0x264:
        part = em_child((cOmBase *)self, &f.childNum, 4);
        best = self->playerDist;
        if (part != 0) {
            best = capVu0MagnitudeSqXZ(pl->pos, part->pos);
            cVec_copy3(&self->aimPos, part->pos);
            self->aimPos.y = self->pos->y;
        }
        part = em_child((cOmBase *)self, &f.childNum, 0x25);
        if (part != 0 && capVu0MagnitudeSqXZ(pl->pos, part->pos) < best) {
            cVec_copy3(&self->aimPos, part->pos);
            self->aimPos.y = self->pos->y;
        }
        break;
    case 0x265:
        part = em_child((cOmBase *)self, &f.childNum, 2);
        if (part != 0) {
            cVec_copy3(&self->aimPos, part->pos);
            self->aimPos.y = self->pos->y;
        }
        if (self->unk744 != 0) {
            part = em_child((cOmBase *)self->unk744, &f.childNum, 3);
            if (part != 0 && capVu0MagnitudeSqXZ(pl->pos, part->pos) < self->playerDist) {
                cVec_copy3(&self->aimPos, part->pos);
                self->aimPos.y = self->pos->y;
            }
        }
        break;
    case 0x26A:
        part = em_child((cOmBase *)self, &f.childNum, 0x10);
        if (part != 0) {
            f.ofs.x = 0.0f;
            f.ofs.y = 0.2f;
            f.ofs.z = 0.0f;
            sceVu0ApplyMatrix(&f.ofs, part->mtx, &f.ofs);
            f.ofs.y = pl->pos->y;
            cVec_copy3(&self->aimPos, &f.ofs);
            capVu0MagnitudeSqXZ(pl->pos, &f.ofs);
        }
        if (self->emFlags & 0x1000000) {
            part = em_child((cOmBase *)self, &f.childNum, 9);
            if (part != 0) {
                f.ofs.x = 0.0f;
                f.ofs.y = 0.1f;
                f.ofs.z = 0.0f;
                sceVu0ApplyMatrix(&f.ofs, part->mtx, &f.ofs);
                f.ofs.y = pl->pos->y;
                cVec_copy3(&self->aimPos, &f.ofs);
            }
        }
        if (self->emFlags & 0x2000000) {
            part = em_child((cOmBase *)self, &f.childNum, 0xE);
            if (part != 0) {
                f.ofs.x = 0.0f;
                f.ofs.y = 0.1f;
                f.ofs.z = 0.0f;
                sceVu0ApplyMatrix(&f.ofs, part->mtx, &f.ofs);
                f.ofs.y = pl->pos->y;
                cVec_copy3(&self->aimPos, &f.ofs);
            }
        }
        break;
    }
    return &self->aimPos;
}
