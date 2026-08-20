/* sn-2.95.3-136 matched TU. */

extern int D_003BF160[];
extern int cCoreSave_getGameLevel(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001FA080")))
float func_001FA080(void *a0)
{
    int level;
    int hi;
    int lo;
    int num;
    float den;

    if (*(int *)a0 == 0) {
        return 0.0f;
    }
    level = cCoreSave_getGameLevel(a0);
    hi = D_003BF160[level - 1];
    if (level - 1 <= 0) {
        lo = 0;
    } else {
        lo = D_003BF160[level - 2];
    }
    den = (float)(hi - lo);
    num = *(short *)(*(int *)a0 + 0x1C) - lo;
    if (den <= 0.0f) {
        den = 1000.0f;
    }
    return (float)num / den;
}
