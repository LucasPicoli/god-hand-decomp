/* sn-2.95.3-136 matched TU. */
#include "godhand/cPlCamera.h"
#include "godhand/pathRec.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

/* Pick the path area the player is in and ease the player camera's next pose toward it. */
__attribute__((section(".text.PathHost_easeCamera")))
void PathHost_easeCamera(PathHost *self, struct cPlCamera *cam)
{
    cVec ref;
    cVec rot;
    float pathTurn;
    float pathDist;
    cGameObj *player;
    PathRec *rec;
    float turn;
    float dist;

    player = Getplayer();
    PathHost_selectRecord(self, player->pos);
    rec = self->rec;
    turn = cam->nextPose.rotOfs.x;
    dist = cam->nextPose.dist;
    if (rec != 0) {
        switch (rec->kind) {
        case PATH_KIND_FIXED:
            turn += (rec->coneAngle - turn) * rec->rate;
            cam->nextPose.rotOfs.x = turn;
            cam->nextPose.dist = rec->endDist;
            cam->nextPose.ofs.y = self->ofsY;
            break;
        case PATH_KIND_CURVE:
            VU0_LQC2_SQC2_MEM(4, &ref, player->pos);
            VU0_LQC2_SQC2_MEM(4, &rot, &player->rot);
            PathHost_calcTurn(self, &pathTurn, &pathDist, &ref, &rot);
            turn += (pathTurn - turn) * rec->rate;
            dist += (pathDist - dist) * rec->rate;
            cam->nextPose.rotOfs.x = turn;
            cam->nextPose.dist = dist;
            cam->nextPose.ofs.y = self->ofsY;
            break;
        case PATH_KIND_FIXED_HEIGHT:
            turn += (rec->coneAngle - turn) * rec->rate;
            cam->nextPose.rotOfs.x = turn;
            cam->nextPose.dist = rec->endDist;
            cam->nextPose.ofs.y = rec->ofsY;
            break;
        }
    } else {
        turn += (self->turn - turn) * self->rate;
        dist += (self->startDist - dist) * self->rate;
        cam->nextPose.rotOfs.x = turn;
        cam->nextPose.dist = dist;
        cam->nextPose.ofs.y = self->ofsY;
    }
}
