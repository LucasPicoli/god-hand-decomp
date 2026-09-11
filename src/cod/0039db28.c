/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpc.o :: _motionVector */

extern void _waitIpuIdle(void *s);
extern long long _sceMpegWaitIpuIdle64(void *s);


#define VDEC(cmd, out)                                                  \
    {                                                                   \
        long long v_;                                                   \
        long long top_;                                                 \
        unsigned int bp_;                                               \
        _waitIpuIdle(s);                                                \
        *(volatile unsigned int *)0x10002000 = (cmd);                   \
        *(int *)(s + 0x828) = 0;                                        \
        *(int *)(s + 0x82C) = 0x30000000;                               \
        v_ = _sceMpegWaitIpuIdle64(s);                                  \
        bp_ = *(volatile unsigned int *)0x10002020;                     \
        top_ = *(volatile long long *)0x10002030;                       \
        *(int *)(s + 0x848) = (int)top_;                                \
        if (top_ < 0)                                                   \
            *(int *)(s + 0x84C) = (0 - (bp_ & 0x1F)) & 0x1F;            \
        else                                                            \
            *(int *)(s + 0x84C) = 0x20;                                 \
        *(int *)(s + 0x12C) = ((int)v_ == 0);                           \
        (out) = (short)v_;                                              \
    }

__attribute__((section(".text.func_0039DB28")))
void func_0039DB28(char *s, int *PMV, int *dmvector, int h_r_size, int v_r_size,
                   int dmv, int mvscale, int full_pel_vector)
{
    int motion_code;
    int motion_residual;

    VDEC(0x38000000, motion_code)
    if (h_r_size != 0 && motion_code != 0)
        motion_residual = func_0039EAA8(s, h_r_size);
    else
        motion_residual = 0;
    {
        int *p;
        int lim;
        int vec;
        p = &PMV[0];
        lim = 16 << h_r_size;
        vec = full_pel_vector ? (*p >> 1) : *p;
        if (motion_code > 0) {
            vec += ((motion_code - 1) << h_r_size) + motion_residual + 1;
            if (vec >= lim)
                vec -= lim + lim;
        } else if (motion_code < 0) {
            vec -= ((-motion_code - 1) << h_r_size) + motion_residual + 1;
            if (vec < -lim)
                vec += lim + lim;
        }
        *p = full_pel_vector ? (vec << 1) : vec;
    }
    if (dmv)
        VDEC(0x3C000000, dmvector[0])

    VDEC(0x38000000, motion_code)
    if (v_r_size != 0 && motion_code != 0)
        motion_residual = func_0039EAA8(s, v_r_size);
    else
        motion_residual = 0;
    if (mvscale)
        PMV[1] >>= 1;
    {
        int *p;
        int lim;
        int vec;
        p = &PMV[1];
        lim = 16 << v_r_size;
        vec = full_pel_vector ? (*p >> 1) : *p;
        if (motion_code > 0) {
            vec += ((motion_code - 1) << v_r_size) + motion_residual + 1;
            if (vec >= lim)
                vec -= lim + lim;
        } else if (motion_code < 0) {
            vec -= ((-motion_code - 1) << v_r_size) + motion_residual + 1;
            if (vec < -lim)
                vec += lim + lim;
        }
        *p = full_pel_vector ? (vec << 1) : vec;
    }
    if (mvscale)
        PMV[1] <<= 1;
    if (dmv)
        VDEC(0x3C000000, dmvector[1])
}
