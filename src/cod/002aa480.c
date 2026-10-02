/* sn-2.95.3-136 matched TU. */
#include "godhand/cIDBase.h"
#include "godhand/cScenario.h"

extern char D_005E7910[];
extern char *D_00754C58;

/* Resolve each entry's parent: an entry whose parentRef (0x29) names the id
 * (0x28) of another entry points `parent` at that entry. */
__attribute__((section(".text.cIDBase_linkParents")))
void cIDBase_linkParents(cIDBaseObj *self) {
    int i;
    int j;
    int c;
    int o1, o2, o3;
    cIDBaseEnt *ent;
    cIDBaseEnt *q;
    cIDBaseEnt *r;

    for (i = 0; i < self->entNum; i++) {
        o1 = i * IDBASE_ENT_SIZE;
        ent = (cIDBaseEnt *)(o1 + (int)self->ent);
        c = ent->parentRef;
        if (c < 0) {
            ent->parent = 0;
            continue;
        }
        if (c == ent->b28) {
            ent->parent = 0;
            return;
        }
        for (j = 0; j < self->entNum; j++) {
            if (i == j) {
                continue;
            }
            o2 = i * IDBASE_ENT_SIZE;
            o3 = j * IDBASE_ENT_SIZE;
            q = (cIDBaseEnt *)(o2 + (int)self->ent);
            r = (cIDBaseEnt *)(o3 + (int)self->ent);
            if (q->parentRef == r->b28) {
                q->parent = r;
            }
        }
    }
}

typedef struct {
    int b[0x2F];
} Blk0BC;

__attribute__((section(".text.func_002B2080")))
void func_002B2080(void *dst) {
    *(Blk0BC *)dst = *(Blk0BC *)D_005E7910;
}

__attribute__((section(".text.cScenario_setOmSuspend")))
/* Hold (1) or release (0) every placed object of id 0x300..0x4FF. */
void cScenario_setOmSuspend(cScenario *self, int suspend) {
    char **cur;
    char *o;
    long ok;
    int tmp;
    int st1;
    int st2;
    long t;

    cur = *(char ***)(D_00754C58 + 4);
    while ((unsigned int)cur < *(unsigned int *)(D_00754C58 + 8)) {
        o = *cur;
        st1 = *(unsigned short *)(o + 0x2FE);
        st2 = *(unsigned short *)(o + 0x2FE);
        ok = 0;
        if (st1 >= 0x300) {
            tmp = st2 < 0x500;
            ok = tmp;
        }
        if (ok & 0xFF) {
            if (suspend == 1) {
                t = *(unsigned int *)(o + 0x5B8);
                if (((t >> 6) & 1) == 0) {
                    *(int *)(o + 0x250) = *(int *)(o + 0x250) | 0x8000;
                }
            } else {
                *(int *)(o + 0x250) = *(int *)(o + 0x250) & ~0x8000;
            }
        }
        cur++;
    }
}
