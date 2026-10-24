/* sn-2.95.3-136: func_0030F348, Mersenne Twister genrand_int32 (N 624, M 397). */
extern unsigned int D_00754250[624];
extern int D_003C3D08;
extern unsigned int D_003C3D10[2];
extern void func_0030F2B0(unsigned int s);

__attribute__((section(".text.func_0030F348")))
unsigned int func_0030F348(void)
{
    unsigned int y;

    if (D_003C3D08 >= 624) {
        int kk;

        if (D_003C3D08 == 625)
            func_0030F2B0(5489);
        for (kk = 0; kk < 624 - 397; kk++) {
            y = (D_00754250[kk] & 0x80000000) | (D_00754250[kk + 1] & 0x7FFFFFFF);
            D_00754250[kk] = D_00754250[kk + 397] ^ (y >> 1) ^ D_003C3D10[y & 1];
        }
        for (; kk < 624 - 1; kk++) {
            y = (D_00754250[kk] & 0x80000000) | (D_00754250[kk + 1] & 0x7FFFFFFF);
            D_00754250[kk] = D_00754250[kk + (397 - 624)] ^ (y >> 1) ^ D_003C3D10[y & 1];
        }
        y = (D_00754250[623] & 0x80000000) | (D_00754250[0] & 0x7FFFFFFF);
        D_00754250[623] = D_00754250[396] ^ (y >> 1) ^ D_003C3D10[y & 1];
        D_003C3D08 = 0;
    }
    y = D_00754250[D_003C3D08++];
    y ^= y >> 11;
    y ^= (y << 7) & 0x9D2C5680;
    y ^= (y << 15) & 0xEFC60000;
    y ^= y >> 18;
    return y;
}
