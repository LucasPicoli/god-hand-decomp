/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern void SetField380Bit2000ForTag_1B7300(void *a0, int a1, int a2);
extern void func_001733B0(char *a0, int a1, float *a2, float *a3, int a4);
extern unsigned char D_00420FA8[];
extern void func_00176758(char *a0, int a1, float *a2, float *a3, int a4);
extern unsigned char D_00421290[];
extern void func_00177DE0(char *a0, int a1, float *a2, float *a3, int a4);
extern unsigned char D_004213A0[];
extern void func_001915D8(char *a0, int a1, float *a2, float *a3, int a4);
extern unsigned char D_00424010[];
extern void func_001971A8(char *a0, int a1, float *a2, float *a3, int a4);
extern unsigned char D_00424ED0[];
extern void func_001987D0(char *a0, int a1, float *a2, float *a3, int a4);
extern unsigned char D_00424FE0[];
extern void func_001A20C8(char *a0, int a1, float *a2, float *a3, int a4);
extern unsigned char D_00426F30[];
extern void func_0018A130(char *a0, int a1, float *a2, float *a3);
extern unsigned char D_004236C0[];
extern void func_0019B780(char *a0, int a1, float *a2, float *a3);
extern unsigned char D_004258D8[];

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_001736A8")))
void func_001736A8(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    int bits;
    float fa, fb;
    float *v;
    char *mesh;

    bits = (int)p + 0xD90;
    *(unsigned int *)((layer >> 5) * 4 + bits) |= 0x80000000 >> (layer & 0x1F);
    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.02f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_00420FA8);
    do { } while (0);
    goto cond;
loop:
    func_001733B0(p, i, (float *)frame, (float *)(frame + 0x10), idx);
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_00420FA8)
          + *(unsigned char *)((int)D_00420FA8 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_00176A50")))
void func_00176A50(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    int bits;
    float fa, fb;
    float *v;
    char *mesh;

    bits = (int)p + 0xD30;
    *(unsigned int *)((layer >> 5) * 4 + bits) |= 0x80000000 >> (layer & 0x1F);
    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.02f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_00421290);
    do { } while (0);
    goto cond;
loop:
    func_00176758(p, i, (float *)frame, (float *)(frame + 0x10), idx);
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_00421290)
          + *(unsigned char *)((int)D_00421290 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_001780D8")))
void func_001780D8(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    int bits;
    float fa, fb;
    float *v;
    char *mesh;

    bits = (int)p + 0xD30;
    *(unsigned int *)((layer >> 5) * 4 + bits) |= 0x80000000 >> (layer & 0x1F);
    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.02f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_004213A0);
    do { } while (0);
    goto cond;
loop:
    func_00177DE0(p, i, (float *)frame, (float *)(frame + 0x10), idx);
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_004213A0)
          + *(unsigned char *)((int)D_004213A0 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_001918D0")))
void func_001918D0(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    int bits;
    float fa, fb;
    float *v;
    char *mesh;

    bits = (int)p + 0xF80;
    *(unsigned int *)((layer >> 5) * 4 + bits) |= 0x80000000 >> (layer & 0x1F);
    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.02f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_00424010);
    do { } while (0);
    goto cond;
loop:
    func_001915D8(p, i, (float *)frame, (float *)(frame + 0x10), idx);
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_00424010)
          + *(unsigned char *)((int)D_00424010 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_001974A0")))
void func_001974A0(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    int bits;
    float fa, fb;
    float *v;
    char *mesh;

    bits = (int)p + 0x9D0;
    *(unsigned int *)((layer >> 5) * 4 + bits) |= 0x80000000 >> (layer & 0x1F);
    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.02f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_00424ED0);
    do { } while (0);
    goto cond;
loop:
    func_001971A8(p, i, (float *)frame, (float *)(frame + 0x10), idx);
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_00424ED0)
          + *(unsigned char *)((int)D_00424ED0 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_00198AC8")))
void func_00198AC8(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    int bits;
    float fa, fb;
    float *v;
    char *mesh;

    bits = (int)p + 0x9D0;
    *(unsigned int *)((layer >> 5) * 4 + bits) |= 0x80000000 >> (layer & 0x1F);
    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.02f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_00424FE0);
    do { } while (0);
    goto cond;
loop:
    func_001987D0(p, i, (float *)frame, (float *)(frame + 0x10), idx);
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_00424FE0)
          + *(unsigned char *)((int)D_00424FE0 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_001A23C0")))
void func_001A23C0(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    int bits;
    float fa, fb;
    float *v;
    char *mesh;

    bits = (int)p + 0xD90;
    *(unsigned int *)((layer >> 5) * 4 + bits) |= 0x80000000 >> (layer & 0x1F);
    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.02f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_00426F30);
    do { } while (0);
    goto cond;
loop:
    func_001A20C8(p, i, (float *)frame, (float *)(frame + 0x10), idx);
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_00426F30)
          + *(unsigned char *)((int)D_00426F30 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_0018A3E8")))
void func_0018A3E8(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    float fa, fb;
    float *v;
    char *mesh;

    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.02f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_004236C0);
    do { } while (0);
    goto cond;
loop:
    func_0018A130(p, i, (float *)frame, (float *)(frame + 0x10));
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_004236C0)
          + *(unsigned char *)((int)D_004236C0 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_0019BA08")))
void func_0019BA08(char *p, unsigned int layer, int idx)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int i;
    int lay2;
    float fa, fb;
    float *v;
    char *mesh;

    lay2 = layer | 0x40;
    cOmBase_setMeshDispFromLayer(p, layer, 0);
    cOmBase_setMeshDispFromLayer(p, lay2, 1);
    SetField380Bit2000ForTag_1B7300(p, layer, 0);
    SetField380Bit2000ForTag_1B7300(p, lay2, 0);
    *(int *)(p + 0x250) |= 0x10000;
    mesh = p + 0x5C0;
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0);
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0);


    i = *(unsigned char *)(idx * 2 + (int)D_004258D8);
    do { } while (0);
    goto cond;
loop:
    func_0019B780(p, i, (float *)frame, (float *)(frame + 0x10));
    i++;
cond:
    if (i < *(unsigned char *)(idx * 2 + (int)D_004258D8)
          + *(unsigned char *)((int)D_004258D8 + idx * 2 + 1)) {
        if (*(unsigned char *)(p + 0x2B4) != i) goto loop;
    }
}
