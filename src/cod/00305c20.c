/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cArea.h"
#include "godhand/cEmManage.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

/* One hit region of an area list. */
typedef struct cAreaZone {
    char unk00[2];
    unsigned char bit;                  /* 0x02 bit of cAreaFx.inside this zone owns */
    char unk03;
    unsigned int flags;                 /* 0x04 AREAZONE_* */
    char unk08[0x18];
    cArea area;                         /* 0x20 */
} cAreaZone;                            /* 0x50 */

#define AREAZONE_TRIGGER  1             /* entering the zone sets cAreaFx.triggered */
#define AREAZONE_OUTSIDE  2             /* the zone's bit means the player is outside it */

typedef struct cAreaZoneList {
    unsigned int num;                   /* 0x00 */
    char unk04[0xC];
    cAreaZone zone[1];                  /* 0x10 */
} cAreaZoneList;

/* One effect of an area effect table: which zone bit gates it. */
typedef struct cAreaFxEntry {
    unsigned short no;                  /* 0x00 effect number */
    unsigned short bit;                 /* 0x02 zone bit, or 0xFFFF for none */
    unsigned short flags;               /* 0x04 bit 0 hides it in the light world, bit 1 in the dark world */
} cAreaFxEntry;

typedef struct cAreaFxTable {
    char unk00[4];
    unsigned int num;                   /* 0x04 */
    char unk08[8];
    int ofs[1];                         /* 0x10 offset of each entry, from 0x10 past the table */
} cAreaFxTable;

typedef struct cAreaFxData {
    char unk00[0x10];
    int tableOfs;                       /* 0x10 offset of the table, from 0x10 past the data */
} cAreaFxData;

/* An object that starts and stops numbered effects as the player moves through zones. */
typedef struct cAreaFx {
    char unk000[0x400];
    cAreaFxData *fx;                    /* 0x400 */
    cAreaZoneList *zones;               /* 0x404 */
    unsigned int enable;                /* 0x408 one bit per effect number */
    unsigned int zoneMask;              /* 0x40C zone bits the effects may use */
    unsigned int inside;                /* 0x410 one bit per zone the player is in */
    unsigned int started;               /* 0x414 effects already started, see func_00305E88 */
    int triggered;                      /* 0x418 */
} cAreaFx;

/* The two stack vectors: the test point and the lock-on point it is copied from. */
typedef struct cAreaFxFrame {
    cVec pos;
    cVec lockOn;
} cAreaFxFrame;

#define AREAFX_FRAME_OFFSET(field) ((int)&((cAreaFxFrame *)0)->field)

extern int cArea_HitCheck_1F83E8(cArea *self, float *pt);
extern void func_00305E88(cAreaFx *self, int no);
extern void func_00305F58(void *self, int no);

/* Update which zones the player's lock-on point is in, then start every effect
 * whose zone gate is open and stop the rest. */
__attribute__((section(".text.func_00305C20")))
void func_00305C20(cAreaFx *self)
{
    cAreaFxFrame f;
    cGameObj *player;
    cGameObjVt *vt;
    cVec *src;
    unsigned int flags;
    cAreaFxTable *table;
    cAreaFxEntry *ent;
    unsigned int i;
    unsigned int n;
    int hit;
    int dark;
    int no;
    unsigned int noMask;
    unsigned int mask;

    self->triggered = 0;
    if (self->zones != 0) {
        self->inside = 0;
        VU0_SQC2_VF0(&f.pos, 0);
        player = Getplayer();
        vt = cGameObj_vt(player);
        src = ((cVec *(*)(void *))vt->lockOn)((char *)player + vt->lockOnDelta);
        VU0_LQC2(4, src, 0);
        VU0_SQC2(4, &f, AREAFX_FRAME_OFFSET(lockOn));
        cVec_copy3(&f.pos, &f.lockOn);
        f.pos.y += 0.5f;
        for (i = 0; i < self->zones->num; i++) {
            hit = cArea_HitCheck_1F83E8(&self->zones->zone[i].area, &f.pos.x);
            if ((!(self->zones->zone[i].flags & AREAZONE_OUTSIDE) && hit == 1)
                || ((self->zones->zone[i].flags & AREAZONE_OUTSIDE) && hit == 0)) {
                self->inside |= 1 << self->zones->zone[i].bit;
            }
            flags = self->zones->zone[i].flags;
            if (!(flags & AREAZONE_OUTSIDE) && hit == 1 && (flags & AREAZONE_TRIGGER)) {
                self->triggered = hit;
            }
        }
    }
    if (self->fx != 0) {
        table = (cAreaFxTable *)((char *)self->fx + (self->fx->tableOfs + 0x10));
        dark = cEmManage_DarkWorldCk(&D_005864F0);
        for (n = 0; n < table->num; n++) {
            ent = (cAreaFxEntry *)((char *)table + (table->ofs[n] + 0x10));
            no = ent->no;
            noMask = 1 << no;
            mask = 1 << ent->bit;
            if ((dark == 0 ? ent->flags & 1 : ent->flags & 2)
                || !(self->enable & noMask)
                || (ent->bit != 0xFFFF && (!(self->zoneMask & mask) || !(self->inside & mask)))) {
                func_00305F58(self, no);
            } else {
                func_00305E88(self, no);
            }
        }
    }
}
