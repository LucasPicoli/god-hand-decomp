/* TU: DogRace - recovered C++ class. */
/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern char D_00754C38[];
extern signed char D_0042BBC0[];
extern signed char D_0042BBC8[];
extern signed char D_0042BBD0[];
extern signed char D_0042BBD8[];
extern signed char D_0042BBE0[];
extern signed char D_0042BBE8[];
extern signed char D_0042BBF8[];
extern signed char D_0042BC08[];
extern signed char D_0042BC18[];
extern signed char D_0042BC28[];
extern signed char D_0042BC38[];
extern signed char D_0042BC48[];
extern signed char D_0042BC58[];
extern signed char D_0042BC68[];
extern signed char D_0042BC78[];
extern int cScrArray_SearchScroll(char *arr, long mask);
extern void displayScrollLayer(int a0, int a1);

/* The name string is packed into a 64-bit key one byte at a time, then looked
   up.  Each call site inlines this helper; the argument copy it emits is what
   makes retail's register use reproduce. */
static inline int Find(char *tbl, signed char *str) {
    signed char *s;
    long acc = 0;
    int i = 0;
    if (str[0] != 0) {
        s = str;
        do {
            acc |= (long)*s << (i * 8);
            i++;
            s++;
            if (i >= 8) break;
        } while (*s != 0);
    }
    return cScrArray_SearchScroll(tbl, acc);
}

__attribute__((section(".text.DogRace_Initialize")))
void DogRace_Initialize(char *p) {
    displayScrollLayer(1, 0);
    *(int *)(p + 0x1EC) = Find(D_00754C38, D_0042BBC0);
    *(int *)(p + 0x1F0) = Find(D_00754C38, D_0042BBC8);
    *(int *)(p + 0x1F4) = Find(D_00754C38, D_0042BBD0);
    *(int *)(p + 0x1F8) = Find(D_00754C38, D_0042BBD8);
    *(int *)(p + 0x1FC) = Find(D_00754C38, D_0042BBE0);
    *(int *)(p + 0x1C4) = Find(D_00754C38, D_0042BBE8);
    *(int *)(p + 0x1C8) = Find(D_00754C38, D_0042BBF8);
    *(int *)(p + 0x1CC) = Find(D_00754C38, D_0042BC08);
    *(int *)(p + 0x1D0) = Find(D_00754C38, D_0042BC18);
    *(int *)(p + 0x1D4) = Find(D_00754C38, D_0042BC28);
    *(int *)(p + 0x1D8) = Find(D_00754C38, D_0042BC38);
    *(int *)(p + 0x1DC) = Find(D_00754C38, D_0042BC48);
    *(int *)(p + 0x1E0) = Find(D_00754C38, D_0042BC58);
    *(int *)(p + 0x1E4) = Find(D_00754C38, D_0042BC68);
    *(int *)(p + 0x1E8) = Find(D_00754C38, D_0042BC78);
}
