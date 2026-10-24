/* sn-2.95.3-136 */

#define PI_F 3.1415927f
#define ABS_F(x) (0.0f < (x) ? (x) : -(x))

extern float func_003A1648(float x);

/* Returns 0 when the XZ direction from -> to is at least max away from yaw cur, 1 when it is within max. */
__attribute__((section(".text.Dest_ck")))
int Dest_ck(float *from, float *to, float cur, float max)
{
    float dx;
    float dz;
    float ang;
    float d;

    dz = to[2] - from[2];
    dx = to[0] - from[0];
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
    d = max < ABS_F(d) ? max : ABS_F(d);
    return d != max;
}
