/* ee-2.9-991111 matched TU. */

typedef struct SlotTable {
    int base;                   /* 0x00 */
    char unk04[0x14];
    long entry[40];             /* 0x18 per-slot value, 8 bytes each */
    char unk158[0x29C - 0x158];
    signed char kind[1];        /* 0x29C per-slot kind: 1 value, 2 link to another slot */
} SlotTable;

/* Follows link slots (kind 2) to a value slot (kind 1) and returns base plus its value; otherwise falls to the fallback. */
__attribute__((section(".text.func_00320948")))
int func_00320948(int slot, SlotTable *t)
{
    while (t->kind[slot] == 2) {
        slot = (int)t->entry[slot];
    }
    if (t->kind[slot] == 1) {
        return t->base + (int)t->entry[slot];
    }
    return func_003A7B48();
}
