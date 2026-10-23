/* sn-2.95.3-136 */

#define PI_F 3.1415927f
#define ABS_F(x) (0.0f < (x) ? (x) : -(x))

extern float func_003A1648(float x);

/* Signed yaw step from cur toward the XZ direction from -> to, clamped to max. */
__attribute__((section(".text.Turn_dest")))
float Turn_dest(float *from, float *to, float cur, float max)
{
    float dx;
    float dz;
    float ang;
    float d;
    float sign;

    dx = to[0] - from[0];
    dz = to[2] - from[2];
    if (dx == 0.0f && dz == 0.0f)
        return 0.0f;
    if (dz != 0.0f) {
        ang = func_003A1648(dx / dz);
        if (dz < 0.0f)
            ang -= PI_F;
    } else {
        ang = -1.5707964f;
        if (0.0f < dx)
            ang = 1.5707964f;
    }
    d = ang - cur;
    if (PI_F < d)
        d -= 2.0f * PI_F;
    if (d < -PI_F)
        d += 2.0f * PI_F;
    sign = -1.0f;
    if (0.0f < d)
        sign = 1.0f;
    d = max < ABS_F(d) ? max : ABS_F(d);
    return d * sign;
}
