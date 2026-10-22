/* sn-2.95.3-136: func_00144C90, set up the 5 x 5 table of ID works and place each entry on its column and row. */
#include "godhand/cObjSimple.h"
typedef struct IdTblEnt {
    char pad0[0x1C];
    struct IdTblEnt *link;
    char pad20[4];
    int f24;
    char pad28[4];
    unsigned int flags;
    char pad30[8];
    float x;
    float y;
    int f40;
    int f44;
    char pad48[4];
    int col;
    int f50;
    char pad54[0x14];
    float w;
} IdTblEnt;

typedef struct {
    char pad0[0x1C];
    unsigned char f1C;
    char pad1D[0x33];
} IdWorkView;

typedef struct {
    char pad0[0x94];
    IdTblEnt *tbl[5][5];
    char padF8[8];
    IdWorkView ids[5];
    cObjSimpleVec3 pos;
    char pad29C[8];
    int f2A4;
    int cols[5];
    char pad2BC[0x80];
    float ys[5];
    float xs[5];
    int f364;
    int f368;
    char pad36C[0xB2];
    short f41E;
    short f420;
} IdTblScreen;

/* ids[j].f1C, spelled as raw bytes: the typed self->ids[j].f1C changes the address arithmetic. */
#define IDWORK_F1C(self, j) (*((unsigned char *)(self) + (j) * 0x50 + 0x11C))

extern cObjSimpleVec3 D_003BD880;
extern float D_0041E880[];
extern void cIDBase_initIDWork(void *w, int id);
extern void cIDBase_restartAnim(void *w);
extern IdTblEnt *cIDBase_getIDWork(void *w, int id);
extern void cIDBase_move(void *w);

static inline void vcpy(cObjSimpleVec3 *d, cObjSimpleVec3 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

__attribute__((section(".text.func_00144C90")))
void func_00144C90(IdTblScreen *self)
{
    unsigned short i;
    unsigned short j;
    unsigned short k;
    IdTblEnt *e;
    float sc;

    vcpy(&self->pos, &D_003BD880);
    self->pos.x = 155.0f;
    self->pos.y = -59.0f;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cIDBase_initIDWork(&self->ids[j], i);
            cIDBase_restartAnim(&self->ids[j]);
            IDWORK_F1C(self, j) = 0;
            self->tbl[j][i] = cIDBase_getIDWork(&self->ids[j], i);
        }
    }
    for (i = 0; i < 4; i++) {
        if (i == 1) {
            self->tbl[1][0]->col = self->tbl[1][0]->link->f50;
        } else {
            self->tbl[i][0]->col = 0x50808080;
        }
        sc = D_0041E880[i];
        self->tbl[i][1]->f24 = self->cols[i];
        self->tbl[i][0]->f40 = 0;
        self->tbl[i][0]->f44 = 0;
        self->tbl[i][0]->x = self->tbl[i][0]->x + self->pos.x + (self->tbl[i][0]->w * sc - self->tbl[i][0]->w) * 0.5f;
        self->tbl[i][0]->y = self->tbl[i][0]->y + self->pos.y + (float)(i * 32);
        self->tbl[i][1]->f40 = 0;
        self->tbl[i][1]->f44 = 0;
        self->ys[i] = self->tbl[i][0]->y;
        self->xs[i] = self->tbl[i][0]->x;
    }
    self->tbl[4][1]->f24 = self->cols[i];  /* i is 4 here; cols[4] does not match */
    self->tbl[4][0]->f40 = 0;
    self->tbl[4][0]->f44 = 0;
    self->tbl[4][1]->f40 = 0;
    self->tbl[4][1]->f44 = 0;
    self->tbl[4][0]->x = self->tbl[4][0]->x + self->pos.x - self->tbl[4][0]->w * 0.5f;
    self->tbl[4][0]->y = self->tbl[3][0]->y;
    e = self->tbl[4][0];
    self->xs[4] = e->x;
    self->ys[4] = e->y;
    e->flags |= 8;
    self->f41E = 1;
    self->f420 = 0;
    self->f2A4 = 0;
    self->f364 = 0x80808080;
    self->f368 = 0x80808080;
    for (k = 0; k < 5; k++) {
        cIDBase_move(&self->ids[k]);
    }
}
