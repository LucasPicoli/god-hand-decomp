/* sn-2.95.3-136 matched TU. */

extern int cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern void SetField380Bit2000ForTag_1B7300(void *a0, int a1, int a2);
extern void cModel_calcParts(void *a0);
extern void func_001797B8(char *a0, int a1, float *a2, float *a3);
extern void func_0017A528(char *a0, int a1, float *a2, float *a3);
extern void func_0017CE38(char *a0, int a1, float *a2, float *a3);
extern void func_00182040(char *a0, int a1, float *a2, float *a3);
extern void func_001871B0(char *a0, int a1, float *a2, float *a3);
extern void func_0018D6B8(char *a0, int a1, float *a2, float *a3);
extern void func_0018E470(char *a0, int a1, float *a2, float *a3);
extern void func_0018FC10(char *a0, int a1, float *a2, float *a3);
extern void func_0019CDA0(char *a0, int a1, float *a2, float *a3);
extern void func_001A5B28(char *a0, int a1, float *a2, float *a3);
extern void func_001B6218(char *a0, int a1, float *a2, float *a3);

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_001799F8")))
void func_001799F8(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x650);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 6; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_001797B8(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_0017A778")))
void func_0017A778(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x650);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 9 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 9; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_0017A528(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_0017D078")))
void func_0017D078(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x650);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 6; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_0017CE38(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_00182280")))
void func_00182280(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x650);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 6; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_00182040(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_001873F0")))
void func_001873F0(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x650);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 6; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_001871B0(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_0018D8F8")))
void func_0018D8F8(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x650);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 6; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_0018D6B8(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_0018E6B0")))
void func_0018E6B0(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x650);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 6; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_0018E470(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_0018FE60")))
void func_0018FE60(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x654);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 7 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 7; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_0018FC10(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_0019CFE0")))
void func_0019CFE0(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x650);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 6; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_0019CDA0(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_001A5D68")))
void func_001A5D68(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x624);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 7 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 7; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_001A5B28(p, j, (float *)(frame + 0x10), v);
    }
}

/* sn-2.95.3-136 */







#include "godhand/vu0.h"

__attribute__((section(".text.func_001B6458")))
void func_001B6458(char *p)
{
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int i, j, n;
    int obj1, obj2;
    int b1, b2;
    int lo, m1, m2;
    unsigned char ok1, ok2;
    float fa, fb;
    float *v;
    char *mesh;
    void *dmg;

    dmg = *(void **)(p + 0x600);
    if (dmg != 0) cDamageUnit_SetDamageCollActive(dmg, 0);
    mesh = p + 0x5C0;
    cOmBase_setMeshDispFromLayer(p, 0, 0);
    cOmBase_setMeshDispFromLayer(p, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    v = (float *)(frame + 0x20);
    i = 1;
    *(int *)(p + 0x250) |= 0x10000;

    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        m1 = -9;
        m2 = -17;
        n = 1;
        do { } while (0);
    loop:
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) &= m1;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) &= m2;
        i++;
        n++;
        if (i < 6 && *(unsigned char *)(p + 0x2B4) != i) goto loop;
    }

    cModel_calcParts(p);
    VU0_LQC2(4, mesh, 0);
    VU0_SQC2(4, frame, 0x10);
    *(float *)(frame + 0x20) = 0.0f;
    *(float *)(frame + 0x24) = 0.0f;
    *(float *)(frame + 0x28) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    do { } while (0);
    fb = 0.01f;
    VU0_LQC2(4, frame, 0x10);
    VU0_LOAD_SCALAR(5, fb);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, frame, 0x10);
    fa = *(float *)(frame + 0x14);
    fb = 0.099999994f;
    fa = fa + fb;
    *(float *)(frame + 0x14) = fa;

    for (j = 1; j < 6; j++) {
        if (*(unsigned char *)(p + 0x2B4) == j) break;
        func_001B6218(p, j, (float *)(frame + 0x10), v);
    }
}
