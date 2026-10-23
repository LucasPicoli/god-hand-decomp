/* sn-2.95.3-136 */

extern const float D_0045A610[][2];

/* Look up the left/right gains for a pan angle; odd half-turns mirror the table. */
__attribute__((section(".text.func_003780F8")))
void func_003780F8(unsigned short angle, float *l, float *r)
{
    unsigned short deg = angle % 360;

    if ((angle / 360) & 1) {
        *l = D_0045A610[360 - deg][0];
        *r = -D_0045A610[360 - deg][1];
    } else {
        *l = D_0045A610[deg][0];
        *r = D_0045A610[deg][1];
    }
}
