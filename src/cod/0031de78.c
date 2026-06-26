/* ee-2.9-991111 matched TU. */

typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef long long DItype;
typedef unsigned long long UDItype;
typedef int SItype;
typedef unsigned int USItype;
typedef double DFtype;

typedef UDItype fractype;
typedef USItype halffractype;
typedef DFtype FLO_type;

typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union { fractype ll; halffractype l[2]; } fraction;
} fp_number_type;

typedef union {
    FLO_type value;
    fractype value_raw;
    halffractype words[2];
    struct {
        fractype fraction : 52 __attribute__ ((packed));
        unsigned int exp : 11 __attribute__ ((packed));
        unsigned int sign : 1 __attribute__ ((packed));
    } bits;
} FLO_union_type;

static __inline__ int isnan(fp_number_type *x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
static __inline__ int isinf(fp_number_type *x) { return x->class == CLASS_INFINITY; }
static __inline__ int iszero(fp_number_type *x) { return x->class == CLASS_ZERO; }

__attribute__((section(".text.func_0031DE78")))
double func_0031DE78(fp_number_type *src) {
    FLO_union_type dst;
    fractype fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;

    if (isnan(src)) {
        exp = 0x7FF;
        if (src->class == CLASS_QNAN || 1) {
            fraction |= 0x8000000000000LL;
        }
    } else if (isinf(src)) {
        exp = 0x7FF;
        fraction = 0;
    } else if (iszero(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -1022) {
            int shift = -1022 - src->normal_exp;
            exp = 0;
            if (shift > 64 - 8) {
                fraction = 0;
            } else {
                fraction >>= shift;
            }
            fraction >>= 8;
        } else if (src->normal_exp > 1023) {
            exp = 0x7FF;
            fraction = 0;
        } else {
            exp = src->normal_exp + 1023;
            if ((fraction & 0xff) == 0x80) {
                if (fraction & (1 << 8))
                    fraction += 0x7f + 1;
            } else {
                fraction += 0x7f;
            }
            if (fraction >= (1LL << 61)) {
                fraction >>= 1;
                exp += 1;
            }
            fraction >>= 8;
        }
    }

    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;

    return dst.value;
}
