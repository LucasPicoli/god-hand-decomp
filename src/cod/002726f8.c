/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */

extern void MtxInitRotY(void *a0, float angle);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern int D_00747A0C;
extern char D_0042CA40[];
extern char D_0042CA48[];
extern char D_0042CA58[];
extern char D_0042CA60[];
extern char D_0042CA68[];
extern char D_0042CA78[];
extern char D_0042CA88[];
extern char D_0042CA90[];
extern char D_0042CA98[];
extern char D_0042CAA0[];
extern char D_0042CAA8[];
extern char D_004365A8[];
extern char D_004365B0[];
extern char D_00446600[];
extern char D_00446610[];
extern char D_00446620[];
extern char D_00446628[];
extern char D_00446638[];
extern char D_00446648[];
extern char D_00446650[];
extern char D_00446658[];
extern char D_00446660[];
extern char D_00446668[];
extern char D_00446670[];
extern char D_00446678[];
extern char D_00446680[];

#include "godhand/vu0.h"

__attribute__((section(".text.func_002726F8")))
void func_002726F8(void *a0)
{
    char frame[0x80];
    char *s3 = (char *)a0;
    char *m;
    char *tmp;
    char *r;
    char *q;
    int s2;
    int n;
    int b;
    int t;
    long ok;
    float *d;
    float *dst;
    float *src;

    if (D_00747A0C == 0 && (*(int *)(s3 + 0x564) ^ 0x244) != 0) {
        return;
    }
    if (*(int *)(s3 + 0x16D4) & 0x1000) {
        if ((*(int *)(s3 + 0x564) ^ 0x244) != 0) {
            return;
        }
    }
    switch (*(int *)(s3 + 0x564)) {
    case 0x200: case 0x201: case 0x202: case 0x203: case 0x204: case 0x205:
    case 0x207: case 0x216: case 0x224: case 0x227: case 0x228: case 0x229:
    case 0x22A: case 0x22B: case 0x23A: case 0x240: case 0x241: case 0x242:
    case 0x243: case 0x24A: case 0x24B:
        n = 0x1D;
        break;
    case 0x20A: case 0x20C: case 0x20D: case 0x218: case 0x244: case 0x245:
    case 0x246: case 0x247:
        n = 0x1E;
        break;
    case 0x206:
        n = 0x1F;
        break;
    default:
        return;
    }
    ok = 0;
    if ((*(int *)frame = b = *(unsigned char *)(s3 + 0x2B4), n >= (int)ok)) {
        t = n < b;
        ok = t;
    }
    if (ok & 0xFF) { do { s2 = *(int *)(*(int *)(s3 + 0x278) + n * 4); } while (0); } else s2 = 0;
    if (s2 == 0) {
        return;
    }
    *(int *)(s2 + 0x154) |= 0x218;
    VU0_SQC2_VF0(frame, 0x50);
    m = frame + 0x10;
    MtxInitRotY(m, *(float *)(s3 + 0x104));
    tmp = frame + 0x70;
    *(float *)(frame + 0x54) = 0.4f;
    *(float *)(frame + 0x58) = -0.1f;
    *(int *)(frame + 0x50) = 0;
    VU0_LQC2(4, frame + 0x50, 0);
    VU0_SQC2(4, frame, 0x70);
    sceVu0ApplyMatrix(tmp, m, tmp);
    VU0_LQC2(4, tmp, 0);
    VU0_SQC2(4, frame, 0x60);
    d = *(float **)(s2 + 0xD0);
    if (d != (float *)(frame + 0x60)) {
        d[0] = *(float *)(frame + 0x60);
        d[1] = *(float *)(frame + 0x64);
        d[2] = *(float *)(frame + 0x68);
    }
    dst = (float *)(s2 + 0x100);
    src = (float *)(s3 + 0x100);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    *(float *)(s3 + 0x130) = -0.5235988f;
    *(int *)(s3 + 0x134) = 0;
    *(int *)(s3 + 0x138) = 0;
    q = *(char **)(s3 + 0x178C);
    if (q != 0) {
        *(int *)(q + 0x380) |= 1;
    }
    q = *(char **)(s3 + 0x1790);
    if (q != 0) {
        *(int *)(q + 0x380) |= 1;
    }
    r = *(char **)(s3 + 0x1794);
    if (r != 0) {
        *(int *)(r + 0x380) &= 0xFFFFFFFE;
    }
    switch (*(int *)(s3 + 0x564)) {
    case 0x204:
        r = (char *)func_0014B730(s3, D_0042CA40);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CA48);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CA58);
        if (r != 0) { *(int *)(r + 0x380) &= 0xFFFFFFFE; }
        break;
    case 0x201:
    case 0x228:
        r = (char *)func_0014B730(s3, D_004365A8);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_004365B0);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        if (*(int *)(s3 + 0x16D4) & 8) {
            r = (char *)func_0014B730(s3, D_0042CA88);
            if (r != 0) { *(int *)(r + 0x380) |= 1; }
        } else {
            r = (char *)func_0014B730(s3, D_0042CA88);
            if (r != 0) { *(int *)(r + 0x380) &= 0xFFFFFFFE; }
        }
        break;
    case 0x240:
        r = (char *)func_0014B730(s3, D_0042CA60);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CA68);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CA78);
        if (r != 0) { *(int *)(r + 0x380) &= 0xFFFFFFFE; }
        break;
    case 0x243:
        r = (char *)func_0014B730(s3, D_0042CA98);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CAA0);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CA90);
        if (r != 0) { *(int *)(r + 0x380) &= 0xFFFFFFFE; }
        break;
    case 0x206:
        r = (char *)func_0014B730(s3, D_004365A8);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_004365B0);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        break;
    case 0x207:
        r = (char *)func_0014B730(s3, D_0042CA60);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CA68);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        break;
    case 0x244:
        r = (char *)func_0014B730(s3, D_0042CA98);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CAA0);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_0042CA90);
        if (r != 0) { *(int *)(r + 0x380) &= 0xFFFFFFFE; }
        r = (char *)func_0014B730(s3, D_0042CAA8);
        if (r != 0) { *(int *)(r + 0x380) &= 0xFFFFFFFE; }
        r = (char *)func_0014B730(s3, D_00446600);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446610);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        break;
    case 0x218:
        r = (char *)func_0014B730(s3, D_00446620);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        break;
    case 0x247:
        r = (char *)func_0014B730(s3, D_00446628);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446638);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446648);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446650);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446658);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446660);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446668);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446670);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446678);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        r = (char *)func_0014B730(s3, D_00446680);
        if (r != 0) { *(int *)(r + 0x380) |= 1; }
        q = *(char **)(s3 + 0x1794);
        if (q != 0) { *(int *)(q + 0x380) |= 1; }
        break;
    default:
        break;
    }
    *(int *)(s3 + 0x16D0) |= 0x40000000;
}
