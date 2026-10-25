/* cygnus-2.96 matched TU. */

#include "godhand/StageBuf.h"

extern unsigned int strlen(const char *s);
extern void func_00336330(void *h, char *msg);
extern long long Forward3A9228_336360(char *s, char **end, int base);

/* Read the mapped file header: return the first base-16 field, store the second one through avail. */
__attribute__((section(".text.func_003363F8")))
char *func_003363F8(char *map, int *avail)
{
    char *end;
    char *first;

    if (strlen(map) >= 0x12)
        func_00336330(0, 0);
    end = map;
    first = func_00336378(map, &end, 16);
    if (*end != 0)
        end++;
    if (avail != 0)
        *avail = Forward3A9228_336360(end, &end, 16);
    return first;
}

/* Clear the record and carve three windows out of the 32-byte aligned buffer. */
__attribute__((section(".text.func_0035FAD8")))
void func_0035FAD8(StageBuf *self, int buf, int size)
{
    int base;

    func_003A52F0(self, 0, STAGEBUF_SIZE);
    base = (buf + STAGEBUF_ALIGN - 1) & -STAGEBUF_ALIGN;
    self->unk04 = 0;
    self->unk08 = 0;
    self->unk0C = 0;
    self->one28 = 1;
    self->unk2C = 0;
    self->unk34 = 0;
    self->base = base;
    self->win[0] = base + STAGEBUF_WIN_LEN;
    self->win[1] = base + STAGEBUF_WIN_LEN * 2;
    self->win[2] = base + STAGEBUF_WIN_LEN * 3;
    self->srcBuf = buf;
    self->srcSize = size;
    self->id = -1;
    self->unk64 = 0;
    self->active = 1;
}
