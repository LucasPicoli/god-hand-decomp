/* sn-2.95.3-136: player restart point save/restore and setPlayerPos (0x31C350..). */
#include "godhand/player.h"

__attribute__((section(".text.func_0031C350")))
void func_0031C350(cVec *pos, float *rot)
{
    cGameObj *pl = Getplayer();

    if (pos == 0) {
        D_00755880.pos[0] = pl->pos->x;
        D_00755880.pos[1] = pl->pos->y;
        D_00755880.pos[2] = pl->pos->z;
    } else {
        D_00755880.pos[0] = pos->x;
        D_00755880.pos[1] = pos->y;
        D_00755880.pos[2] = pos->z;
    }
    if (rot == 0) {
        D_00755880.rot[0] = pl->rot.x;
        D_00755880.rot[1] = pl->rot.y;
        D_00755880.rot[2] = pl->rot.z;
    } else {
        D_00755880.rot[0] = rot[0];
        D_00755880.rot[1] = rot[1];
        D_00755880.rot[2] = rot[2];
    }
    D_00755880.heatMax = D_005CB000.max;
    D_00755880.heat = D_005CB000.cur;
}

__attribute__((section(".text.func_0031C438")))
void func_0031C438(void)
{
    cGameObj *pl = Getplayer();

    pl->pos->x = D_00755880.pos[0];
    pl->pos->y = D_00755880.pos[1];
    pl->pos->z = D_00755880.pos[2];
    pl->posA.x = D_00755880.pos[0];
    pl->posA.y = D_00755880.pos[1];
    pl->posA.z = D_00755880.pos[2];
    pl->rot.x = D_00755880.rot[0];
    pl->rot.y = D_00755880.rot[1];
    pl->rot.z = D_00755880.rot[2];
    cHeatSys_UpdateHeatMax(&D_005CB000, D_00755880.heatMax);
    cHeatSys_SetHeatGage(&D_005CB000, D_00755880.heat);
}

__attribute__((section(".text.setPlayerPos")))
void setPlayerPos(cVec *pos, float angle)
{
    cGameObj *pl = Getplayer();
    cPlayerVt *vt;
    cPlayerLink *link;
    cVec rot;

    ((cPlayerVt *)pl->vtable)->setPos((char *)pl + ((cPlayerVt *)pl->vtable)->setPosDelta, pos);
    vt = (cPlayerVt *)pl->vtable;
    {
        void *self = (char *)pl + vt->setRotDelta;

        rot.w = 1.0f;
        rot.y = angle;
        rot.x = 0.0f;
        rot.z = 0.0f;
        vt->setRot(self, &rot);
    }
    link = *(cPlayerLink **)((char *)pl + 0x68C);
    ((cGameObjHead *)pl)->pos.x = pos->x;
    ((cGameObjHead *)pl)->pos.y = pos->y;
    ((cGameObjHead *)pl)->pos.z = pos->z;
    if (link != 0) {
        link->flags |= 1;
    }
}
