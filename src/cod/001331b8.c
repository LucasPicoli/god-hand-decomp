/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionScroll.h"

/* Pack up to COLLSCROLL_NAME_LEN characters of a name into one word, low byte first. */
static __inline__ long CollScroll_packName(signed char *s)
{
    long packed = 0;
    int i = 0;
    signed char *p;

    if (*s != 0) {
        p = s;
        do {
            packed |= (long)*p << (i * 8);
            i++;
            p++;
            if (i >= COLLSCROLL_NAME_LEN)
                break;
        } while (*p != 0);
    }
    return packed;
}

/* cCollisionScroll::SetCollEnable by packed name: find the layer whose name packs to `name` and
 * clear (on) or set (off) COLLSCROLL_ENTRY_OFF in each of its entries. */
__attribute__((section(".text.cCollisionScroll_SetCollEnableByName")))
void cCollisionScroll_SetCollEnableByName(cCollisionScroll *self, long name, int on)
{
    unsigned int i;

    if (self->data == 0)
        return;
    for (i = 0; i < self->data->numLayers; i++) {
        if (name == CollScroll_packName(self->layers[i].name)) {
            ScrollLayer *ly = COLLSCROLL_LAYER_AT(self->layers, i);
            unsigned int n = ly->count;
            int j = 0;
            int first = ly->first;

            for (n--; n != (unsigned int)-1; j++, n--) {
                if (on != 0)
                    self->entries[first + j].flags &= ~COLLSCROLL_ENTRY_OFF;
                else
                    self->entries[first + j].flags |= COLLSCROLL_ENTRY_OFF;
            }
            return;
        }
    }
}
