/* sn-2.95.3-136 */

/* Build the rotation matrix m of the unit quaternion q (x, y, z, w). */
__attribute__((section(".text.MtxInitRotQuaternion")))
void MtxInitRotQuaternion(float m[4][4], float q[4])
{
    float xx, yy, zz, xy, yz, zx, xw, yw, zw;

    xx = 2.0f * (q[0] * q[0]);
    yy = 2.0f * (q[1] * q[1]);
    zz = 2.0f * (q[2] * q[2]);
    xy = 2.0f * (q[0] * q[1]);
    yz = 2.0f * (q[1] * q[2]);
    zx = 2.0f * (q[2] * q[0]);
    xw = 2.0f * (q[0] * q[3]);
    yw = 2.0f * (q[1] * q[3]);
    zw = 2.0f * (q[2] * q[3]);
    m[0][0] = 1.0f - yy - zz;
    m[0][1] = xy + zw;
    m[0][2] = zx - yw;
    m[1][0] = xy - zw;
    m[1][1] = 1.0f - zz - xx;
    m[1][2] = yz + xw;
    m[2][0] = zx + yw;
    m[2][1] = yz - xw;
    m[2][2] = 1.0f - xx - yy;
    m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}
