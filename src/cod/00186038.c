/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern float DoubleFloatMinusHalf_31D020(void);
extern float fRand0_1(void);
extern void Obj0000_Set_Byte_54(void *a0, int a1);
extern void Obj0000_Set_Field_50_173998(int *a0, int a1);
extern void ForwardVec3At30_147C60(void *a0, float *a1);
extern void func_00147C88(void *a0, void *a1, int a2);
extern void CopyVec3ToField20_173908(char *a0, float *a1);
extern void CopyVec3ToField30_173938(char *a0, float *a1);
extern void CopyVec3ToField40_173968(char *a0, float *a1);
extern char D_00747B00[];

__attribute__((section(".text.func_00186038")))
void func_00186038(char *a0, int a1)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1, obj2, obj3, obj4;
    int b1, b2, b3, b4;
    unsigned char ok1, ok2, ok3, ok4;
    char *elem;
    char *src;
    float neg;
    int off;
    int n;

    n = -1;
    switch (a1) {
    case 0:  n = 0x1E; break;
    case 1:  n = 0x8;  break;
    case 2:  n = 0x7;  break;
    case 3:  n = 0x9;  break;
    case 4:  n = 0xA;  break;
    case 5:  n = 0xB;  break;
    case 6:  n = 0xC;  break;
    case 7:  n = 0x23; break;
    case 8:  n = 0x17; break;
    case 9:  n = 0x18; break;
    case 10: n = 0x19; break;
    case 11: n = 0x1A; break;
    case 12: n = 0x1F; break;
    case 13: n = 0x21; break;
    case 14: n = 0x20; break;
    case 15: n = 0x22; break;
    case 16: n = 0x1;  break;
    case 17: n = 0x3;  break;
    case 18: n = 0x2;  break;
    case 19: n = 0x4;  break;
    case 20: break;
    }
    if (n == -1) return;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (n >= 0 && n < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + n * 4); else obj1 = 0;
    if (obj1 == 0) return;

    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (n >= 0 && n < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + n * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 8;

    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (n >= 0 && n < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + n * 4); else obj3 = 0;
    *(int *)(obj3 + 0x154) |= 0x10;

    VU0_LQC2(4, D_00747B00, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, D_00747B00, 0);
    VU0_SQC2(4, frame, 0x20);

    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.15f + 0.1f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.1f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.1f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.1f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (n >= 0 && n < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + n * 4); else obj4 = 0;

    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x670;
    neg = -0.016f;
    Obj0000_Set_Byte_54(elem, 1);
    Obj0000_Set_Field_50_173998((int *)elem, (int)src);
    ForwardVec3At30_147C60(elem, (float *)src);
    func_00147C88(elem + 0x10, src, 0);
    CopyVec3ToField20_173908(elem, (float *)(frame + 0x10));
    CopyVec3ToField30_173938(elem, (float *)(frame + 0x20));
    { float *v = (float *)(frame + 0x30);
      v[0] = 1.0f; v[1] = 1.0f; v[2] = 1.0f; v[3] = 1.0f;
      CopyVec3ToField40_173968(elem, v); }
    *(float *)(elem + 0x58) = neg;
}
