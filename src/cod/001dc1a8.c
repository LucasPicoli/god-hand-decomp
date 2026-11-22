/* sn-2.95.3-136 matched TU. */

#include "godhand/cBgmData.h"
#include "godhand/globals.h"

extern void func_001DBF18(void *self, unsigned short *a, unsigned short *b, unsigned short *c, unsigned short *d);
extern void func_00297C88(void *ev, int id);
extern cBgmData *cSnd_GetBgmData(void *snd, int idx);
extern void cBgmData_LoadNamed(cBgmData *data, int slot, char *name);
extern int func_001C2328(void *obj);

extern void func_001DBFB8(void *self, unsigned short *x0, unsigned short *y0, unsigned short *x1, unsigned short *y1,
                          unsigned short *x2, unsigned short *y2, unsigned short *x3, unsigned short *y3,
                          unsigned short *x4, unsigned short *y4);

#define PART_NUM         5          /* parts held in the table */
#define PART_KIND_FOUND  5          /* kind value the first check looks for */
#define PART_FLAG_MARK   0x4

typedef struct Part {
    int unk00;
    unsigned int flags;                 /* 0x04 */
} Part;

typedef struct PartHolder {
    char unk0000[0x3004];
    Part *part[PART_NUM];               /* 0x3004 */
} PartHolder;

/* Mark every part when one of the four kinds the first lookup returns is PART_KIND_FOUND and the second lookup returns the sequence 0, 9, 10, 11, 12 in its x values. Returns 1 when it marked them. */
__attribute__((section(".text.PartHolder_markIfSequence")))
int PartHolder_markIfSequence(PartHolder *self)
{
    unsigned short kind[4];
    unsigned short x[5];
    unsigned short y[5];
    Part **p;
    int i;

    func_001DBF18(self, &kind[0], &kind[1], &kind[2], &kind[3]);
    if (kind[0] == PART_KIND_FOUND || kind[1] == PART_KIND_FOUND ||
        kind[2] == PART_KIND_FOUND || kind[3] == PART_KIND_FOUND) {
        func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
        if (x[0] == 0 && x[1] == 9 && x[2] == 10 && x[3] == 11 && x[4] == 12) {
            p = self->part;
            for (i = PART_NUM - 1; i >= 0; i--) {
                (*p++)->flags |= PART_FLAG_MARK;
            }
            return 1;
        }
    }
    return 0;
}

extern char D_00586AF0[];               /* cEvent */
extern char D_005FEE00[];               /* cSnd */



#define STAGE_NUM  3

/* Count the finished stages and start the BGM of that count: event 0x1001 plus its named track for one stage, 0x1002 for two, 0x1003 for three. */
__attribute__((section(".text.EventBgm_startByStageCount")))
void EventBgm_startByStageCount(void)
{
    int n;
    int i;

    n = 0;
    for (i = 0; i < STAGE_NUM; i++) {
        if (D_003C0548[i] != 0) {
            n++;
        }
    }
    switch (n) {
    case 1:
        func_00297C88(D_00586AF0, 0x1001);
        cBgmData_LoadNamed(cSnd_GetBgmData(D_005FEE00, 1), 1, D_0044AC00);
        break;
    case 2:
        func_00297C88(D_00586AF0, 0x1002);
        cBgmData_LoadNamed(cSnd_GetBgmData(D_005FEE00, 1), 1, D_0044AC08);
        break;
    case 3:
        func_00297C88(D_00586AF0, 0x1003);
        cBgmData_LoadNamed(cSnd_GetBgmData(D_005FEE00, 1), 1, D_0044AC10);
        break;
    }
}

typedef struct ObjList {
    char unk00[4];
    char **begin;                       /* 0x04 first object pointer */
    char **end;                         /* 0x08 one past the last */
} ObjList;

extern ObjList *D_00754C58;             /* the room's object list */

#define OBJ_FLAG_SKIP_A  0x8000
#define OBJ_FLAG_SKIP_B  0x80000000
#define ACTOR_ITEM_FIRST  0x300
#define ACTOR_ITEM_END    0x500
#define ACTOR_TARGET      0x3D1         /* the item actor this search looks for */

/* 1 when lo <= k < hi. */
static __inline__ long inrange(unsigned short k, int lo, int hi)
{
    long c;
    int t;
    c = 0;
    if (k >= lo) {
        t = (k < hi);
        c = t;
    }
    return c;
}

/* First live item object of actor 0x3D1 for which func_001C2328 answers nonzero, or 0. */
__attribute__((section(".text.ObjList_findActor3D1")))
char *ObjList_findActor3D1(void)
{
    char **p = D_00754C58->begin;
    char **end = D_00754C58->end;
    char **cur;
    char *obj;
    unsigned short k;

    for (; p != end; ) {
        cur = p++;
        obj = *cur;
        if (*(unsigned int *)(obj + 0x250) & OBJ_FLAG_SKIP_A) continue;
        if (*(unsigned int *)(obj + 0x250) & OBJ_FLAG_SKIP_B) continue;
        k = *(unsigned short *)(obj + 0x2FE);
        if (!(inrange(k, ACTOR_ITEM_FIRST, ACTOR_ITEM_END) & 0xFF)) continue;
        if ((k ^ ACTOR_TARGET) != 0) continue;
        if (func_001C2328(obj) != 0) return obj;
    }
    return 0;
}
