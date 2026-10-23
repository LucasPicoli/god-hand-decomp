/* sn-2.95.3-136 */
/* func_002C9950: cocktail-sort the list's order indices by the key of the item each one selects (sn-2.95.3-136) */

typedef struct SortItem {
    char pad0[0x14];
    short key;                  /* 0x14 */
    char pad16[0x24 - 0x16];
} SortItem;

typedef struct SortList {
    SortItem *items;            /* 0x00 */
    char pad4[0x10 - 4];
    unsigned int count;         /* 0x10 */
    signed char order[0];       /* 0x14 count item indices */
} SortList;

__attribute__((section(".text.func_002C9950")))
void func_002C9950(SortList *s)
{
    unsigned int i;
    int swapped;
    signed char t;

    if (s->items == 0 || s->count == 0)
        return;
    do {
        swapped = 0;
        for (i = 0; i < s->count - 1; i++) {
            if (s->items[s->order[i]].key > s->items[s->order[i + 1]].key) {
                t = s->order[i];
                s->order[i] = s->order[i + 1];
                swapped = 1;
                s->order[i + 1] = t;
            }
        }
        if (!swapped)
            break;
        for (; i >= 2; i--) {
            if (s->items[s->order[i]].key < s->items[s->order[i - 1]].key) {
                t = s->order[i];
                s->order[i] = s->order[i - 1];
                swapped = 1;
                s->order[i - 1] = t;
            }
        }
    } while (swapped);
}
