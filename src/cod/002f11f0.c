/* sn-2.95.3-136 matched TU. */

extern char D_007419A0[];
extern void func_002D9F68(void *, int, ...);
extern int D_0061B674;
extern unsigned char D_003C3BB0;
extern int D_003C3BB4;
extern unsigned char D_0061B670;
extern int D_0044EC08;
extern int D_0044EC28;
extern void Tramp_func_0030A548_00147528(void *mtx, void *src);
extern void sceVu0ApplyMatrix(void *dst, void *m, void *src);
extern char *D_005CAFF0;
extern void cNode_setLocalTranslation(void *this, void *v);
extern void func_002FBED0(void *this);

/* sn-2.95.3-136 */











__attribute__((section(".text.func_002F11F0")))
int func_002F11F0(char *p)
{
    char *q;
    int *r;

    q = *(char **)(p + 0x110);
    *(int *)(p + 0x2B0) = *(unsigned char *)(q + 0x16C);
    *(int *)(p + 0x2B4) = *(unsigned char *)(q + 0x170);
    D_0061B674 = *(int *)(q + 0x174);
    r = func_00306030(D_007419A0, *(int *)(p + 0x2B0), *(int *)(p + 0x2B4) + 1);
    if (r == 0) {
        func_002D9F68(p, (int)&D_0044EC08, *(int *)(p + 0x2B0), *(int *)(p + 0x2B4));
        return 0;
    }
    if (*r != 0x545345) {
        func_002D9F68(p, (int)&D_0044EC28, *(int *)(p + 0x2B0), *(int *)(p + 0x2B4));
        return 0;
    }
    D_003C3BB0 = 0;
    D_003C3BB4 = 0;
    D_0061B674 = 0;
    D_0061B670 = 0;
    return 1;
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002F3020")))
int func_002F3020(char *this) {
    char *p = *(char **)(this + 0x110);

    *(float *)(this + 0x2B8) = *(float *)(p + 0x13C) + 0.5f;
    *(float *)(this + 0x2BC) = 0.7f - *(float *)(p + 0x140);
    *(int *)(this + 0x2B0) = *(unsigned char *)(p + 0x18C) + 1;
    *(int *)(this + 0x2B4) = *(int *)(this + 0x220);
    return 1;
}

/* sn-2.95.3-136, no extra flags. Widening target (0x2B4/0x278 screen). */
#include "godhand/vu0.h"




__attribute__((section(".text.func_002F4DC8")))
void func_002F4DC8(char *p, float *dst)
{
    char buf[0x70];
    char *obj;
    char *e;
    float *s;
    char *q2;
    int idx;
    int lo;
    int b;
    unsigned char ok;

    lo = 0;
    obj = *(char **)(p + 0x2C0);
    if (obj != 0) {
        idx = *(unsigned char *)(p + 0x2BF);
        ok = ((*(int *)(buf + 0x40) = b = *(unsigned char *)(obj + 0x2B4)), (idx >= lo && idx < b));
        if (ok) {
            e = (char *) *(int *)(*(int *)(obj + 0x278) + idx * 4);
        } else {
            e = 0;
        }
        Tramp_func_0030A548_00147528(buf, e + 0x80);
        q2 = buf + 0x60;
        VU0_LQC2(4, p + 0x2D0, 0);
        VU0_SQC2(4, buf, 0x60);
        sceVu0ApplyMatrix(q2, buf, q2);
        VU0_LQC2(4, q2, 0);
        VU0_SQC2(4, buf, 0x50);
        s = (float *) (buf + 0x50);
        if (dst != s) {
            float t0 = *(float *)(buf + 0x50);
            float t1 = *(float *)(buf + 0x54);
            float t2 = *(float *)(buf + 0x58);
            dst[0] = t0;
            dst[1] = t1;
            dst[2] = t2;
        }
    } else {
        s = (float *) (p + 0x2D0);
        if (dst != s) {
            dst[0] = s[0];
            dst[1] = s[1];
            dst[2] = s[2];
        }
    }
}

/* sn-2.95.3-136 matched TU. */




#include "godhand/vu0.h"
__attribute__((section(".text.func_002F6BB8")))
void func_002F6BB8(char *this) {
    char frame[0x50];
    char *p;
    char *q;
    char *s;
    char *u;
    float t;

    VU0_LQC2(4, D_005CAFF0 + 0x210, 0);
    VU0_SQC2(4, frame, 0x0);
    p = this + 0x2B0;
    q = frame + 0x10;
    VU0_SQC2_VF0(frame, 0x20);
    VU0_LQC2(4, frame, 0x0);
    VU0_LQC2(5, p, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x20);
    VU0_LQC2(4, frame + 0x20, 0);
    VU0_SQC2(4, frame, 0x10);
    t = *(float *)(this + 0x2C0);
    s = frame + 0x40;
    VU0_LQC2(4, q, 0);
    VU0_SQC2(4, frame, 0x40);
    VU0_LQC2(4, frame, 0x40);
    VU0_LOAD_SCALAR(5, t);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x40);
    VU0_LQC2(4, s, 0);
    VU0_SQC2(4, frame, 0x30);
    u = frame + 0x30;
    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, frame, 0x40);
    VU0_LQC2(4, frame, 0x40);
    VU0_LQC2(5, u, 0);
    VU0_VADD_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x40);
    VU0_LQC2(4, s, 0);
    VU0_SQC2(4, frame, 0x20);
    *(float *)(frame + 0x24) = *(float *)(this + 0x2B4);
    cNode_setLocalTranslation(this, frame + 0x20);
    func_002FBED0(this);
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002F9D30")))
int func_002F9D30(char *this) {
    {
        char *p = *(char *volatile *)(this + 0x110);
        float v = *(float *)(p + 0x13C);
        if (v == 0.0f) { *(float *)(this + 0x2B0) = 30.0f; }
        else { *(float *)(this + 0x2B0) = v; }
    }
    {
        char *p = *(char *volatile *)(this + 0x110);
        float v = *(float *)(p + 0x148);
        if (v == 0.0f) { *(float *)(this + 0x2B8) = 3.0f; }
        else { *(float *)(this + 0x2B8) = v; }
    }
    {
        char *p = *(char *volatile *)(this + 0x110);
        float w = *(float *)(p + 0x14C);
        *(float *)(this + 0x2BC) = (w != 0.0f) ? *(float *)(p + 0x148) : 40.0f;
    }
    {
        char *p = *(char *volatile *)(this + 0x110);
        *(int *)(this + 0x2B4) = *(signed char *)(p + 0x18C);
    }
    return 1;
}
