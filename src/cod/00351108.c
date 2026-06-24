/* cygnus-2.96 matched TU. */

typedef struct {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
} SfMpv;

__attribute__((section(".text.sfmpv_CalcDistance")))
unsigned int sfmpv_CalcDistance(SfMpv *p, unsigned int v) {
    unsigned int lo0 = p->f0;
    unsigned int r;
    if (v >= lo0 && v < lo0 + p->f4) {
        r = v - lo0;
    } else if (v >= p->f8 && v < p->f8 + p->fC) {
        r = (v - p->f8) + p->f4;
    } else {
        r = 0;
    }
    return r;
}
