/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/cSnd.h"

extern float DoubleFloatMinusHalf_31D020(void);
extern float fRand0_1(void);
extern void Obj0000_Set_Byte_54(void *a0, int a1);
extern void Obj0000_Set_Field_50_173998(int *a0, int a1);
extern void ForwardVec3At30_147C60(void *a0, float *a1);
extern void func_00147C88(void *a0, void *a1, int a2);
extern void CopyVec3ToField20_173908(char *a0, float *a1);
extern void CopyVec3ToField30_173938(char *a0, float *a1);
extern void CopyVec3ToField40_173968(char *a0, float *a1);
extern void *GetIndexedEntry_2CC4B8(void *a0, int a1);
extern int D_0044CE48[];
extern int cSaveLoad_openSave(void *p, int a1);
extern char D_00747A24[];
extern char D_00747A2C[];
extern char D_00747A88[];
extern char D_003C2648[];
extern void func_00381D38(void);
extern void func_003A6A20(char *a0);
extern void func_0031C900(int a0);
extern char D_0045C7A0[];
extern char D_0045C7D0[];
extern void CustomIDWork_SetLocalPosY(char *a0, int a1);
extern int ChangeThreadPriority(int tid, int prio);
extern int SignalSema(int sema);
extern void ExitDeleteThread(void);

/* sn-2.95.3-136 matched TU. */












__attribute__((section(".text.func_001BCB38")))
void func_001BCB38(char *a0, int a1, float *a2, float *a3)
{
    unsigned char frame[0x40] __attribute__((aligned(16)));
    int obj1,obj2,obj3;
    int b1,b2,b3;
    unsigned char ok1,ok2,ok3;
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
    VU0_LQC2(4, a2, 0);
    VU0_SQC2(4, frame, 0x10);
    VU0_LQC2(4, a3, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x10) += DoubleFloatMinusHalf_31D020() * 0.2f;
    *(float *)(frame + 0x14) += fRand0_1() * 0.3f;
    *(float *)(frame + 0x18) += DoubleFloatMinusHalf_31D020() * 0.2f;
    *(float *)(frame + 0x20) += DoubleFloatMinusHalf_31D020() * 0.2f;
    *(float *)(frame + 0x24) += DoubleFloatMinusHalf_31D020() * 0.2f;
    *(float *)(frame + 0x28) += DoubleFloatMinusHalf_31D020() * 0.2f;

    ok3 = ((*(int *)frame = b3 = *(unsigned char *)(a0 + 0x2B4)), (a1 >= 0 && a1 < b3));
    if (ok3) obj3 = *(int *)(*(int *)(a0 + 0x278) + a1 * 4); else obj3 = 0;

    src = (char *)(obj3 + 0x80);
    elem = (char *)a1; elem = (char *)((int)elem * 0x60); elem = elem + *(int *)(a0 + 0x628);
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

/* Like cSnd_EmSeCheck, but it skips entries that are not yet loaded instead of dead ones. */
__attribute__((section(".text.func_002CB4E8")))
int func_002CB4E8(cSnd *self, int objId)
{
    int owner;
    int *slot;
    unsigned int i;
    cSndSeEntry *e;

    owner = func_002CB3A8(self, objId);
    if (owner <= 0)
        owner = objId;

    slot = D_0044CE48;
    i = 0;
    do {
        e = GetIndexedEntry_2CC4B8(self, *slot);
        if (func_002CFC78(e) != 1) {
            e = GetIndexedEntry_2CC4B8(self, *slot);
            if (e->owner == owner) {
                e = GetIndexedEntry_2CC4B8(self, *slot);
                if (func_002CFC88(e) != 1)
                    return *slot;
            }
        }
        i++;
        slot++;
    } while (i < 0xC);

    return -1;
}

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_00160E78")))
int func_00160E78(char *p)
{
    char *g;
    unsigned long fx;
    unsigned long bit;
    int st;

    g = D_00747A2C;
    if ((*(int *)(g + 0x8) & 0x800) != 0) return 1;
    fx = *(int *)(g + 0xC);
    if ((long)fx < 0) return 1;
    bit = (fx >> 6) & 1;
    if (bit) return 1;

    st = *(short *)(p + 0x52);
    if (st == 0) goto zero;
    if (st == 1) goto chk;
    goto clr;
zero:
    cSaveLoad_openSave(*(void **)D_003C2648, 0);
    *(unsigned short *)(p + 0x52) = *(unsigned short *)(p + 0x52) + 1;
chk:
    if ((*(int *)D_00747A88 & 0x40000000) != 0) return 0;
clr:
    *(int *)D_00747A24 = *(int *)D_00747A24 & -3;
    *(short *)(p + 0x52) = 0;
    return 1;
}

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_00381B38")))
int func_00381B38(int a0, int a1) {
    int *s0 = (int *)a1;
    int r;
    func_00381D38();
    r = func_0031C890(0x8C6D0);
    s0[0x24/4] = r;
    if (r == 0) {
        func_003A6A20(D_0045C7A0);
        return 1;
    }
    r = func_0032D340(4, 2, r, 0x8C6D0);
    s0[0x20/4] = r;
    if (r == 0) {
        func_003A6A20(D_0045C7D0);
        func_0031C900(s0[0x24/4]);
        return 2;
    }
    return 0;
}

/* sn-2.95.3-136 matched TU. */

typedef struct { int w[5]; } Blk1EE;
extern Blk1EE D_0042BDD8;


__attribute__((section(".text.func_001EE6C8")))
void func_001EE6C8(char *a0, unsigned short a1) {
    Blk1EE buf;
    if (a1 < 5) {
        buf = D_0042BDD8;
        CustomIDWork_SetLocalPosY(a0 + 0xDF0, buf.w[a1]);
    }
}

/* sn-2.95.3-136 matched TU. */
struct s_002D5A48 {
    int *field_0;
    int field_4;
    int pad_8;
    short field_C;
};




__attribute__((section(".text.func_002D5990")))
void func_002D5990(struct s_002D5A48 *a0)
{
    a0->field_C = 2;
    if (a0->field_4 != -1) {
        ChangeThreadPriority(a0->field_4, 1);
        SignalSema(a0->field_0[10]);
        a0->field_4 = -1;
        ExitDeleteThread();
    }
}
