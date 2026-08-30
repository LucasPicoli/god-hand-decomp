/* sn-2.95.3-136 matched TU. */

extern int cIDManager_getTexAddr_2ACE28(int a0, int a1);
extern int D_003C2388;
extern int D_00747A0C;

/* sn-2.95.3-136 */
#include "godhand/vu0.h"


extern void Gp_draw_polyFT4(void *a0, int a1, int a2, int a3, int a4, int a5,
                            void *a6, int a7, int a8);





static __inline__ void setv4(float *v, float x, float y, float z, float w) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}

static __inline__ void cpy3(float *d, float *s) {
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

__attribute__((section(".text.func_002B1300")))
void func_002B1300(void *a0, float px, float py, float sc) {
    unsigned char uv[0x50];
    float vt[16];
    float va[4];
    float vb[4];
    float vc[4];
    int tex;
#define FRAME ((char *)uv - 0x10)
    int i;
    float *p;
    float w;

    *(int *)uv = 0;
    tex = cIDManager_getTexAddr_2ACE28(D_003C2388, 0x18);
    if (D_00747A0C != 0) {
        py = py + 3.0f;
    }
    switch (*(unsigned short *)a0) {
    case 0:
        *(float *)(uv + 4) = 0.0f;   *(float *)(uv + 8) = 0.0f;
        *(float *)(uv + 0xC) = 0.25f; *(float *)(uv + 0x10) = 0.25f;
        break;
    case 1:
        *(float *)(uv + 4) = 0.25f;  *(float *)(uv + 8) = 0.0f;
        *(float *)(uv + 0xC) = 0.5f; *(float *)(uv + 0x10) = 0.25f;
        break;
    case 2:
        *(float *)(uv + 4) = 0.5f;   *(float *)(uv + 8) = 0.0f;
        *(float *)(uv + 0xC) = 0.75f; *(float *)(uv + 0x10) = 0.25f;
        break;
    case 3:
        *(float *)(uv + 4) = 0.75f;  *(float *)(uv + 8) = 0.0f;
        *(float *)(uv + 0xC) = 1.0f; *(float *)(uv + 0x10) = 0.25f;
        break;
    case 4:
        *(float *)(uv + 4) = 0.5f;   *(float *)(uv + 8) = 0.25f;
        *(float *)(uv + 0xC) = 0.75f; *(float *)(uv + 0x10) = 0.5f;
        break;
    case 5:
        *(float *)(uv + 4) = 0.0f;   *(float *)(uv + 8) = 0.25f;
        *(float *)(uv + 0xC) = 0.25f; *(float *)(uv + 0x10) = 0.5f;
        break;
    case 6:
        *(float *)(uv + 4) = 0.75f;  *(float *)(uv + 8) = 0.25f;
        *(float *)(uv + 0xC) = 1.0f; *(float *)(uv + 0x10) = 0.5f;
        break;
    case 7:
        *(float *)(uv + 4) = 0.25f;  *(float *)(uv + 8) = 0.25f;
        *(float *)(uv + 0xC) = 0.5f; *(float *)(uv + 0x10) = 0.5f;
        break;
    case 8:
        *(float *)(uv + 4) = 0.25f;  *(float *)(uv + 8) = 0.5f;
        *(float *)(uv + 0xC) = 0.5f; *(float *)(uv + 0x10) = 0.75f;
        break;
    case 9:
        *(float *)(uv + 4) = 0.0f;   *(float *)(uv + 8) = 0.5f;
        *(float *)(uv + 0xC) = 0.25f; *(float *)(uv + 0x10) = 0.75f;
        break;
    case 10:
        *(float *)(uv + 4) = 0.75f;  *(float *)(uv + 8) = 0.5f;
        *(float *)(uv + 0xC) = 1.0f; *(float *)(uv + 0x10) = 0.75f;
        break;
    case 11:
        *(float *)(uv + 4) = 0.5f;   *(float *)(uv + 8) = 0.5f;
        *(float *)(uv + 0xC) = 0.75f; *(float *)(uv + 0x10) = 0.75f;
        break;
    case 12:
        *(float *)(uv + 4) = 0.25f;  *(float *)(uv + 8) = 0.75f;
        *(float *)(uv + 0xC) = 0.5f; *(float *)(uv + 0x10) = 1.0f;
        break;
    case 13:
        *(float *)(uv + 4) = 0.0f;   *(float *)(uv + 8) = 0.75f;
        *(float *)(uv + 0xC) = 0.25f; *(float *)(uv + 0x10) = 1.0f;
        break;
    default:
        return;
    }
    *(int *)uv = 1;
    p = vt;
    for (i = 3; i != -1; i--) {
        VU0_SQC2_VF0(p, 0);
        p += 4;
    }
    VU0_SQC2_VF0(FRAME, 0xA0);
    VU0_SQC2_VF0(FRAME, 0xB0);
    setv4(vc, -1.0f, -1.0f, 0.0f, 1.0f);
    cpy3(va, vc);
    setv4(vc, 513.0f, 448.0f, 0.0f, 1.0f);
    cpy3(vb, vc);
    w = sc * 26.0f;
    setv4(&vt[0], px, py, 65535.0f, 1.0f);
    setv4(&vt[4], px + w, py, 65535.0f, 1.0f);
    setv4(&vt[8], px, py + w, 65535.0f, 1.0f);
    setv4(&vt[12], px + w, py + w, 65535.0f, 1.0f);
    Gp_draw_polyFT4(vt, 0x80808080, 1, tex, 0x3B00, 0x1CF0, uv, 6, 5);
}
