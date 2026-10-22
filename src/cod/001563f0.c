/* sn-2.95.3-136 */

/* Convert a float to a half float, rounding to nearest even and saturating large values. */
__attribute__((section(".text.F32toF16")))
unsigned short F32toF16(float f)
{
    unsigned int bits;
    unsigned int a;
    unsigned int sign;
    unsigned short h;
    unsigned int shift;

    bits = *(unsigned int *)&f;
    a = bits & 0x7FFFFFFF;
    sign = (bits >> 16) & 0x8000;
    if (a > 0x47FFEFFF) {
        h = sign | 0x7FFF;
    } else {
        if (a < 0x38800000) {
            shift = 113 - (a >> 23);
            a = ((a & 0x7FFFFF) | 0x800000) >> shift;
        } else {
            a += 0xC8000000;
        }
        h = sign | ((a + 0xFFF + ((a >> 13) & 1)) >> 13);
    }
    return h;
}
