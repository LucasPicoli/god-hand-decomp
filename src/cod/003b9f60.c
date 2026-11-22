/* cygnus-2.96: ac3cnv_alloc_hndl, return the first free slot of D_003FC7B8, or 0. The table has one slot;
 * retail still loops over it. */
typedef struct WordSlot {
    int word;
    char pad[0x3C - 4];
} WordSlot;

extern WordSlot D_003FC7B8[];

__attribute__((section(".text.ac3cnv_alloc_hndl")))
WordSlot *ac3cnv_alloc_hndl(void)
{
    WordSlot *p;
    int i;

    for (i = 0; i < 1; i++) {
        p = &D_003FC7B8[i];
        if (p->word == 0)
            break;
    }
    return i != 1 ? p : 0;
}
