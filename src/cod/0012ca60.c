/* sn-2.95.3-136 matched TU. */

extern void cModel_calcParts(void *a0);
extern int cModel_getMeshPtr(void *a0, int a1);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *p);
extern int Obj293_IsByteSet_53C(void *p);
extern int D_005864F0;
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern int D_00462FC0;
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_00129718(void *a, void *b, int c);
extern int D_005FEA60;
extern int D_00568288;
extern int func_002C2B58(void *a0, int a1, float *a2, float *a3);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern void func_002DCA58(void);
extern void LookupSlotPopulateFieldsAndDispatch_1F7858(void *a0, int a1, int a2, int a3, void *t0, int t1, int t2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_002DC898(void *arg);

/* sn-2.95.3-136 matched TU. */

static inline int GetLayerObj(char *a0, int *frame, int idx)
{
    int b;

    *frame = b = *(unsigned char *)(a0 + 0x2B4);
    if (idx >= 0 && idx < b) {
        return *(int *)(*(int *)(a0 + 0x278) + idx * 4);
    }
    return 0;
}

__attribute__((section(".text.func_001B8720")))
int func_001B8720(char *a0)
{
    unsigned char frame[0x10];
    int e;

    e = GetLayerObj(a0, (int *)frame, 0);
    if (e == 0) {
        return *(int *)(a0 + 0xF0);
    }
    return *(int *)(e + 0xF0);
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_0027A0F0")))
int func_0027A0F0(char *a0)
{
    unsigned char frame[0x10];
    int e;

    e = GetLayerObj(a0, (int *)frame, 0);
    if (e != 0) {
        return *(int *)(e + 0xF0);
    }
    return *(int *)(a0 + 0xF0);
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_00279C20")))
void func_00279C20(char *a0)
{
    unsigned char frame[0x10];
    int e;
    int fl;

    e = GetLayerObj(a0, (int *)frame, 0);
    if (e != 0) {
        *(int *)(e + 0x148) = (int)a0;
    }
    *(float *)(a0 + 0x24C) = 1.0f;
    *(int *)(a0 + 0x250) = *(int *)(a0 + 0x250) & 0xFFFFFFEF;
    *(int *)(a0 + 0x1580) = 0;
    cModel_calcParts(a0);
}

/* sn-2.95.3-136 matched TU. */

static inline int GetLayerObj0(char *a0, int *frame)
{
    int b;

    *frame = b = *(unsigned char *)(a0 + 0x2B4);
    if (b != 0) {
        return *(int *)(*(int *)(a0 + 0x278));
    }
    return 0;
}

__attribute__((section(".text.func_0012CA60")))
int func_0012CA60(char *a0)
{
    unsigned char frame[0x10];
    int e;
    float x;

    if (*(int *)(a0 + 0x15F4) & 0x200000) {
        return 1;
    }
    e = GetLayerObj0(a0, (int *)frame);
    if (e == 0) {
        return 0;
    }
    x = *(float *)(*(int *)(a0 + 0xF0) + 4) + 0.8f;
    if (*(float *)(*(int *)(e + 0xF0) + 4) < x) {
        return 1;
    }
    return 0;
}

__attribute__((section(".text.func_0014D7D0")))
void func_0014D7D0(char *a0)
{
    char frame[0x10];
    char *m;
    char *p;
    int ok;

    m = (char *)cModel_getMeshPtr(a0, 0);
    *(int *)frame = (int)(p = *(char **)(m + 0x388));
    ok = *(unsigned short *)(p + 8) >= 2;
    if (ok) {
        *(unsigned char *)(a0 + 0x2BE) = 0x16;
    } else {
        *(unsigned char *)(a0 + 0x2BE) = 0x18;
    }
}

__attribute__((section(".text.func_002DC670")))
void func_002DC670(void *arg)
{
    char *s1;
    char *r;
    char *g;

    s1 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    r[0x2F5] = 0x17;
                    r[0x2F7] = 1;
                    r[0x2F4] = 0;
                    r[0x2F6] = 0;
                    *((float *) (r + 0x104)) = *((float *) (r + 0x104)) +
                        (Turn_dest(*((void **) (r + 0xF0)), *((void **) (s1 + 0xF0)),
                                   *((float *) (r + 0x104)), 3.14159274f) + 3.14159274f);
                    *((float *) (r + 0x104)) = Adjust_theta(*((float *) (r + 0x104)));
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DD6C0")))
void func_002DD6C0(void *arg)
{
    char *s0;
    char *r;
    char *g;

    s0 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (s0 == 0) {
        return;
    }
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    *((float *) (s0 + 0x54C)) = 30.0f;
                    if (*((float *) (s0 + 0x770)) > 0.0f) {
                        if (*((float *) (s0 + 0x770)) < 10.0f) {
                            *((float *) (s0 + 0x770)) = 10.0f;
                        }
                    }
                    s0[0x2F6] = 0;
                    s0[0x2F7] = 0;
                    s0[0x2F4] = 1;
                    s0[0x2F5] = 0x22;
                    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
                    func_00129718(r, s0, 0x22);
                }
            }
        }
    }
}

#include "godhand/vu0.h"

__attribute__((section(".text.SetActionJumpUp")))
void SetActionJumpUp(void)
{
    float buf[8];
    char *s0;
    char *g;
    float *p;
    float t;
    float at;

    s0 = Obj0000_Get_D_00747A94_2DB6B0();
    VU0_SQC2_VF0(buf, 0);
    if (*((short *) (s0 + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(s0) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    if (func_002C2B58(&D_005FEA60, *((int *) (s0 + 0xF0)), buf, buf + 4) != 0) {
                        t = Turn_dest_dir(*((float *) (s0 + 0x104)), buf[4], 3.14159274f);
                        if (t < 0.0f) {
                            at = -t;
                        } else {
                            at = t;
                        }
                        if (at > 1.30899692f) {
                            return;
                        }
                        p = (float *) (s0 + 0x660);
                        if (p != buf) {
                            *((float *) (s0 + 0x660)) = buf[0];
                            p[1] = buf[1];
                            p[2] = buf[2];
                        }
                        *((float *) (s0 + 0x670)) = buf[4];
                        t = 0.0f;
                        LookupSlotPopulateFieldsAndDispatch_1F7858(&D_00568288, 0x4, 0x8, 0, func_002DCA58, 0, 0);
                    }
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC740")))
void func_002DC740(void *arg)
{
    char *s1;
    char *r;
    char *g;
    float d;
    float ad;
    float t;
    float at;

    s1 = (char *) arg;
    r = Obj0000_Get_D_00747A94_2DB6B0();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (Obj293_IsByteSet_53C(g) == 0) {
                    if (capVu0MagnitudeSqXZ(*((void **) (s1 + 0xF0)),
                                            *((void **) (r + 0xF0))) > 4.0f) {
                        return;
                    }
                    d = *((float *) (*((char **) (r + 0xF0)) + 4)) -
                        *((float *) (*((char **) (s1 + 0xF0)) + 4));
                    if (d < 0.0f) {
                        ad = -d;
                    } else {
                        ad = d;
                    }
                    if (ad > 0.5f) {
                        return;
                    }
                    t = Turn_dest(*((void **) (r + 0xF0)), *((void **) (s1 + 0xF0)),
                                  *((float *) (r + 0x104)), 3.14159274f);
                    if (t < 0.0f) {
                        at = -t;
                    } else {
                        d = t;
                        at = d;
                    }
                    if (at > 0.785398185f) {
                        return;
                    }
                    LookupSlotPopulateFieldsAndDispatch_1F7858(&D_00568288, 0xA, 0x11, 0, func_002DC898, (int) s1, 0);
                }
            }
        }
    }
}
