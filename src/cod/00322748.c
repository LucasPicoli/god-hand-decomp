/* ee-2.9-991111 matched TU. */

#include "godhand/MpsList.h"

/* The record array of a list. */
static __inline__ int *MpsList_items(MpsList *l)
{
    return l->item;
}

#define KEY(p) (((MpsKeyed *)(p))->key)

/* Walk the list once with a stack of indices. Each record that sorts below the one on top of the stack
 * is popped to the end of out and cleared in the list; then the cleared slots are squeezed out. */
__attribute__((section(".text.func_00322748")))
void func_00322748(MpsList *list, MpsList *out)
{
    unsigned int n = list->count;
    unsigned int links[n];
    unsigned int top = MPSLIST_NONE;
    unsigned int i;
    unsigned int cur;   /* the stack walk index, then the squeeze write index */

    for (i = 0; i < n; i++) {
        cur = top;
        while (cur != MPSLIST_NONE
               && KEY(MpsList_items(list)[i]) - KEY(list->item[cur]) < 0) {
            /* record-pointer typed so the moves sit in another alias set than links[]: retail loads links[cur] above them */
            ((MpsKeyed **)out->item)[out->count++] = ((MpsKeyed **)list->item)[cur];
            ((MpsKeyed **)list->item)[cur] = 0;
            cur = links[cur];
        }
        top = i;
        links[i] = cur;
    }
    cur = 0;
    for (i = 0; i < n; i++) {
        if (list->item[i] != 0) {
            list->item[cur++] = list->item[i];
        }
    }
    list->count = cur;
}
