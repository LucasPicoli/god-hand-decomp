/* Byte-identical to RE4 PS2 (SLUS-21134) 0x002C7B18 — shared engine code.
 * Initialises a min/max-tracking struct: INT_MAX / LLONG_MAX sentinels in the
 * head fields, -1 and 0 elsewhere, then zeroes the 0x40..0x14C array via a
 * down-counted loop (which cc1 pads with the R5900 short-loop nops), and sets
 * three tail fields.
 *
 * The store statements are ordered to match ee-gcc's instruction scheduler:
 * the head-field order below is the scheduler pre-image that reproduces retail's
 * emission order, and the tail is written 0x154/0x158/0x150 so the scheduler
 * rotates 0x150 to the front and 0x154 into the jr delay slot. */

__attribute__((section(".text.sfmps_InitInf")))
void sfmps_InitInf(void *a0) {
    char *p = (char *)a0;
    int i;
    int *q;
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(long long *)(p + 0x10) = 0x7FFFFFFFFFFFFFFFLL;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x24) = 0x7FFFFFFF;
    *(int *)(p + 0x2C) = -1;
    *(int *)(p + 0x30) = -1;
    *(long long *)(p + 0x18) = 0x7FFFFFFFFFFFFFFFLL;
    *(int *)(p + 0x28) = 0x7FFFFFFF;
    *(int *)(p + 0x34) = -1;
    *(int *)(p + 0x38) = -1;
    *(int *)(p + 0x3C) = 0;
    for (i = 0x43, q = (int *)(p + 0x14C); i >= 0; i--) {
        *q = 0;
        q--;
    }
    *(int *)(p + 0x154) = 0;
    *(int *)(p + 0x158) = -1;
    *(int *)(p + 0x150) = 0;
}
