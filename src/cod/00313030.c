/* sn-2.95.3-136 matched TU. */

#include "godhand/cPlObj14C0.h"
#include "godhand/vu0.h"

extern int D_00747A34;
extern char D_00754C10[];
extern void *_MemoryAlloc(int size, int align, void *region);
extern void cPlBase(void *self);

/* sn-2.95.3-136, cloned from CreateObjectWithVtableA. */






extern char D_0041B730[];               /* method table of this class */




/* Allocates and zeroes a 0x14C0-byte player object, runs the cPlBase
 * constructor, sets its method table and zeroes its two vectors. 0 when the
 * allocator is locked or full. */
__attribute__((section(".text.ObjFactory_create103")))
void *ObjFactory_create103(void)
{
    cPlObj14C0 *obj;
    cPlObj14C0 *self;
    float (*v)[4];
    int i;

    if (D_00747A34 & CPLOBJ14C0_NO_NEW)
        goto none;
    obj = _MemoryAlloc(CPLOBJ14C0_SIZE, CPLOBJ14C0_ALIGN, D_00754C10);
    if (obj == 0)
        goto none;
    func_003A52F0(obj, 0, CPLOBJ14C0_SIZE);
    self = obj;
    cPlBase(self);
    self->vt = D_0041B730;
    v = self->vec;
    for (i = CPLOBJ14C0_VEC_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(v, 0);
        v++;
    }
    return obj;
none:
    /* Dead store: it puts self's last reference after obj's, so cse keeps
     * self for the constructor and obj for the return, as retail does. The
     * early-return form without it merges the two registers. */
    self = 0;
    return 0;
}

/* sn-2.95.3-136. */

extern int func_003A5678(const char *a, const char *b);   /* strcmp */

/* The table: a count, `count` offset words, then `count` 4-byte tags.
 * Finds the nth entry (0-based) whose tag equals key and returns the data
 * its offset word points at, or 0. */
__attribute__((section(".text.SearchData")))
unsigned int *SearchData(unsigned int *table, const char *key, unsigned int nth)
{
    unsigned int count;
    unsigned int i;
    unsigned int seen;
    const char *tag;

    if (table == 0)
        return 0;
    count = table[0];
    seen = 0;
    tag = (const char *)(table + count);
    for (i = 1; i <= count; i++) {
        tag += 4;
        if (func_003A5678(tag, key) == 0) {
            if (seen++ == nth)
                return (unsigned int *)(table[i] + (unsigned int)table);
        }
    }
    return 0;
}
