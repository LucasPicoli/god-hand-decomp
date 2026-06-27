/* sn-2.95.3-136 matched TU. */

typedef struct Entry { int f0; unsigned int f4; int f8; } Entry;



__attribute__((section(".text.func_00394348")))
int func_00394348(Entry *a0, int count, int kind) {
    unsigned int i;
    for (i = (unsigned int)(count - 1); i != 0xFFFFFFFFu; i--) {
        unsigned int w;
        w = a0->f4;
        if ((w >> 8) == (unsigned int)kind) {
            if (func_00394328(a0->f0, w & 0xFF) == 0) {
                return 0;
            }
        }
        a0++;
    }
    return 1;
}
