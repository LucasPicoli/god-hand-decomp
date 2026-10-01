/* TU: DogRace - recovered C++ class. */
#include "godhand/DogRace.h"
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

/* Looks the scroll layer named by `str` up in the layer table. The name is
packed into a 64-bit key one byte at a time. Each call site inlines this
helper; the argument copy it emits is what makes retail's register use
reproduce. */
/* Looks up the 15 scroll layers the race screen uses. */
__attribute__((section(".text.DogRace_Initialize")))
void DogRace_Initialize(DogRace *self) {
    displayScrollLayer(1, 0);
    self->scroll[(0x1EC - 0x1C4) / 4] = Find(D_00754C38, D_0042BBC0);
    self->scroll[(0x1F0 - 0x1C4) / 4] = Find(D_00754C38, D_0042BBC8);
    self->scroll[(0x1F4 - 0x1C4) / 4] = Find(D_00754C38, D_0042BBD0);
    self->scroll[(0x1F8 - 0x1C4) / 4] = Find(D_00754C38, D_0042BBD8);
    self->scroll[(0x1FC - 0x1C4) / 4] = Find(D_00754C38, D_0042BBE0);
    self->scroll[0] = Find(D_00754C38, D_0042BBE8);
    self->scroll[1] = Find(D_00754C38, D_0042BBF8);
    self->scroll[2] = Find(D_00754C38, D_0042BC08);
    self->scroll[3] = Find(D_00754C38, D_0042BC18);
    self->scroll[4] = Find(D_00754C38, D_0042BC28);
    self->scroll[5] = Find(D_00754C38, D_0042BC38);
    self->scroll[6] = Find(D_00754C38, D_0042BC48);
    self->scroll[7] = Find(D_00754C38, D_0042BC58);
    self->scroll[8] = Find(D_00754C38, D_0042BC68);
    self->scroll[9] = Find(D_00754C38, D_0042BC78);
}
