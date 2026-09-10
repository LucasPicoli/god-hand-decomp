/* cygnus-2.96 matched TU. */

typedef struct Src { int f0; int f4; int f8; short fC; short fE; } Src;
typedef struct Dst { int f0; int f4; int f8; int fC; int f10; int f14; } Dst;

extern void SFD_CalcYccPlane(int a, int b, int c, Src *out);
extern void func_00344E58(Src *s, Dst *d);

__attribute__((section(".text.mwPlyCalcYccPlane")))
void mwPlyCalcYccPlane(int a, int b, int c, Dst *out)
{
    Src tmp;

    SFD_CalcYccPlane(a, b, c, &tmp);
    func_00344E58(&tmp, out);
}
