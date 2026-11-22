/* TU: cDoor - recovered C++ class. */
#include "godhand/cDoor.h"
#include "godhand/globals.h"

extern cDoorWorld D_007474A0;
extern void *SearchData(void *name, void *table, int which);

__attribute__((section(".text.cDoor_getJumpData")))
int cDoor_getJumpData(cDoor *self, unsigned char idx, unsigned char arg, unsigned char arg2,
                      int mode, unsigned char kind3A)
{
    cDoorTbl *tbl;
    cDoorRec *rec;
    int ret;

    tbl = SearchData(D_007474A0.pack, D_0042C768, 0);
    ret = 0;
    if (tbl != 0 && idx < tbl->num) {
        rec = &tbl->rec[idx];
        if (mode == 1) {
            self->point[0].id = rec->id;
        } else {
            self->point[0].id = rec->id == D_007474A0.room ? 0xFFFF : rec->id;
        }
        ret = 1;
        self->point[0].pos[0] = rec->pos[0] * 0.01f;
        self->point[0].pos[1] = rec->pos[1] * 0.01f;
        self->point[0].pos[2] = rec->pos[2] * 0.01f;
        self->point[0].angle = rec->angle * CDOOR_DEG2RAD;
        self->point[0].kind = rec->kind;
        self->point[0].arg = arg;
        self->point[0].arg2 = arg2;
        self->unk3A = kind3A;
    }
    return ret;
}
