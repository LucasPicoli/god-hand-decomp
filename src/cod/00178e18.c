/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmHitVolumeSetup.h"

/* newlib libc/stdio/vfscanf.c __sccl: build the scanset table for a %[...] conversion
 * and return the format pointer past the closing bracket. */

__attribute__((section(".text.func_003A79F8")))
char *func_003A79F8(char *tab, const char *fmt) {
    register int c, n, v;

    /* first `clear' the whole table */
    c = *fmt++;         /* first char hat => negated scanset */
    if (c == '^') {
        v = 1;          /* default => accept */
        c = *fmt++;     /* get new first char */
    } else
        v = 0;          /* default => reject */
    /* should probably use memset here */
    for (n = 0; n < 256; n++)
        tab[n] = v;
    if (c == 0)
        return (char *) (fmt - 1); /* format ended before closing ] */

    v = 1 - v;
    for (;;) {
        tab[c] = v;             /* take character c */
    doswitch:
        n = *fmt++;             /* and examine the next */
        switch (n) {

        case 0:                 /* format ended too soon */
            return (char *) (fmt - 1);

        case '-':
            n = *fmt;
            if (n == ']' || n < c) {
                c = '-';
                do { } while (0); /* its loop note aligns the range label, as retail */
                break;          /* resume the for(;;) */
            }
            fmt++;
            do {                /* fill in the range */
                tab[++c] = v;
            } while (c < n);
            goto doswitch;

        case ']':               /* end of scanset */
            return (char *) fmt;

        default:                /* just another character */
            c = n;
            break;
        }
    }
    /* NOTREACHED */
}

/* sn-2.95.3-136: hit volume with a 4.8 by 3.0 by 4.8 damage-take box, then the work defaults. */


#define HITVOL_FLAG2_BOX      0x800     /* flags2 bit this setup turns on */
#define HITVOL_UNIT_ACTIVE    1         /* bit 0 of the damage-take unit's first word */

/* Registers a box with a damage-take unit, marks the unit active and fills the tail of the record. */
__attribute__((section(".text.func_00178E18")))
int func_00178E18(cOmHitVolume *em)
{
    cVec v[4];             /* size twice, offset, rotation */
    cVec *ofs;
    cVec *rot;
    cVec *size;
    void *slot;
    int stage;             /* 0x5F6 value; a local so its store follows 0x5F4's, as retail */

    func_001B6FB8(em);
    size = &v[1];
    ofs = &v[2];
    v[0].x = 4.8f;
    v[0].y = 3.0f;
    v[0].z = 4.8f;
    v[1].y = 3.0f;
    v[0].w = 1.0f;
    v[1].x = 4.8f;
    v[1].z = 4.8f;
    size->w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    ofs->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)em, 2);
    em->damageTake = slot;
    if (slot != 0) {
        rot = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        rot->w = 1.0f;
        func_001FD9D8(slot, (const struct cMatrix *)((char *)em + 0x80), ofs, rot, size);
        *(unsigned int *)em->damageTake |= HITVOL_UNIT_ACTIVE;
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->table = em->tableData;
    em->count = 0x12;
    em->unk5E8 = 0;
    em->unk5EC = 0x11;
    stage = 5;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->unk5F4 = -1;
    em->unk5F6 = stage;
    em->base.flags2 |= HITVOL_FLAG2_BOX;
    func_001C28A0(em);
    return 1;
}
