/* cygnus-2.96 matched TU. */

typedef struct MvInf {
    int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c;
} MvInf;

extern void func_00366C50(void *dst, int val, int n);

__attribute__((section(".text.sfply_InitMvInf")))
void sfply_InitMvInf(MvInf *mv)
{
    func_00366C50(mv, 0, 0x10);
    mv->f0 = 0;
    mv->f4 = 0;
    mv->f8 = 0;
    mv->fc = 0;
    mv->f10 = 0;
    mv->f14 = 0;
    mv->f18 = 0;
    mv->f1c = 1;
    mv->f20 = 0;
    mv->f24 = -1;
    mv->f28 = -1;
    mv->f2c = -1;
}
