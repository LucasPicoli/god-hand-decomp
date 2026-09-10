/* cygnus-2.96 matched TU. */

typedef struct Elem {
    char pad0[0x18];
    unsigned char id;
} Elem;

__attribute__((section(".text.searchStmId")))
Elem *searchStmId(void *sfh, int id)
{
    Elem *found;
    Elem *p;
    char *base;
    int i;

    found = 0;
    for (i = 0; i < 26; i++) {
        base = (char *)sfh + i * 64;
        p = (Elem *)(base + 0x180);
        if (p->id == id) {
            found = p;
            break;
        }
    }
    return found;
}
