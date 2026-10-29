/* sn-2.95.3-136. */

typedef struct {
    char b[0x30];
} SoundBlk48;

#include "godhand/sndBank.h"

extern void InitSoundBlock_374D98(short a0, short a1, short *a2);
extern void InitSoundEntry_375B90(short a0, short a1, short *a2);

__attribute__((section(".text.SdeIssTblGet")))
int SdeIssTblGet(short a0, short a1, short *a2)
{
    SndBank *b;
    char *src;

    b = &D_0076DF10[a0];
    if (a1 < (short)b->id) {
        src = b->data;
        src = src + (a1 * 0x30);
        if (((*((unsigned short *)(src + 0xE))) & 0x8000) == 0) {
            *((SoundBlk48 *)a2) = *((SoundBlk48 *)src);
            a2[0] = a0;
            a2[1] = a1;
            return 0;
        }
    }
    InitSoundBlock_374D98(a0, a1, a2);
    return -1;
}

__attribute__((section(".text.func_00375AB0")))
int func_00375AB0(short a0, short a1, short *a2)
{
    SndBank *b;
    char *src;

    b = &D_0076EA50[a0];
    if (a1 < (short)b->num) {
        src = b->tbl2;
        src = src + (a1 * 0x30);
        if (((*((unsigned short *)(src + 0xE))) & 0x8000) == 0) {
            *((SoundBlk48 *)a2) = *((SoundBlk48 *)src);
            a2[0] = a0;
            a2[1] = a1;
            return 0;
        }
    }
    InitSoundEntry_375B90(a0, a1, a2);
    return -1;
}
