/* TU: Slot2 - recovered C++ class. */
#include "include_asm.h"

extern void func_003A52F0(void *a0, int a1, int a2);
extern void InitStructSubfieldsAndFloat_1E8798(void *a0);
extern void InitStructZeroedFields_1E7960(void *a0);
extern void func_001E7118(void *a0);

__attribute__((section(".text.Slot2")))
void *Slot2(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    func_003A52F0(p, 0, 0x54);
    *(int *)(p + 0x54) = 0;

    q = p + 0x58;
    /* closes with bne against a -1 register -> i != -1, not i >= 0 */
    for (i = 2; i != -1; i--) {
        InitStructSubfieldsAndFloat_1E8798(q);
        q += 0xE8;
    }

    InitStructZeroedFields_1E7960(p + 0x310);
    func_001E7118(p + 0x400);

    *(unsigned short *)(p + 0x3D0) = 0xFFFF;
    *(unsigned short *)(p + 0xA80) = 0;
    *(int *)(p + 0x3DC) = 0;
    return p;
}
