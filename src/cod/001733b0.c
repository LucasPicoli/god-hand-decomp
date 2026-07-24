/* sn-2.95.3-136 matched TU. */

extern void func_001501D0(int a0, int a1);
extern float DoubleFloatMinusHalf_31D020(void);
extern float fRand0_1(void);
extern void Obj0000_Set_Byte_54(void *a0, int a1);
extern void Obj0000_Set_Field_50_173998(int *a0, int a1);
extern void ForwardVec3At30_147C60(void *a0, float *a1);
extern void func_00147C88(void *a0, void *a1, int a2);
extern void CopyVec3ToField20_173908(char *a0, float *a1);
extern void CopyVec3ToField30_173938(char *a0, float *a1);
extern void CopyVec3ToField40_173968(char *a0, float *a1);

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_001733B0")))
void func_001733B0(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.05f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.08f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x610;
    neg = -0.02f;
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

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_00176758")))
void func_00176758(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.05f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.08f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x610;
    neg = -0.02f;
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

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_00177DE0")))
void func_00177DE0(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.05f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.08f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x610;
    neg = -0.02f;
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

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_0018A130")))
void func_0018A130(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.05f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.08f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x610;
    neg = -0.02f;
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

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_001915D8")))
void func_001915D8(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.05f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.08f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x620;
    neg = -0.02f;
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

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_001971A8")))
void func_001971A8(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.05f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.08f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x610;
    neg = -0.02f;
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

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_001987D0")))
void func_001987D0(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.05f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.08f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x610;
    neg = -0.02f;
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

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_0019B780")))
void func_0019B780(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.2f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.2f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.2f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.1f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.1f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.1f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x610;
    neg = -0.02f;
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

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"










__attribute__((section(".text.func_001A20C8")))
void func_001A20C8(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3,obj4;
    int b1,b2,b3,b4;
    unsigned char ok1,ok2,ok3,ok4;
    char *elem;
    char *src;
    float neg;
    int off;

    ok1 = ((*(int *)frame = b1 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b1));
    if (ok1) obj1 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj1 = 0;
    *(int *)(obj1 + 0x154) |= 8;
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj2 = 0;
    *(int *)(obj2 + 0x154) |= 0x10;
    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;
    func_001501D0(obj3, *(int *)(a0 + 0x250));
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.05f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.05f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.08f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.08f;

    ok4 = ((*(int *)frame = b4 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b4));
    if (ok4) obj4 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj4 = 0;
    
    src = (char *)(obj4 + 0x80);
    off = a1 * 0x60;
    elem = a0 + off;
    elem = elem + 0x610;
    neg = -0.02f;
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
