/* TU: ColiseumEmSelect [casino] - recovered C++ class. */
#include "godhand/ColiseumEmSelect.h"
extern char D_003BF0A8[];
#include "include_asm.h"

/* Call the handler picked by vtIndex through the g++ delta/pfn table. */
__attribute__((section(".text.ColiseumEmSelect_Main")))
void ColiseumEmSelect_Main(ColiseumEmSelect *self) {
    int i = self->vtIndex;
    short off = *(short *)(D_003BF0A8 + i * 8);
    void (*fn)() = *(void (**)())(D_003BF0A8 + i * 8 + 4);
    fn((char *)self + off);
}
