/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj293_IsByteSet_53C(void *a0);
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern char D_005864F0[];
extern char D_00568288;
extern void func_002DD270();
extern void func_002DD300();
extern void func_002DD3C0();
extern void func_002DD480();
extern void func_002DD540();
extern void func_002DD600();
extern void func_002DD6C0();
extern void func_002DD7B0();
extern void func_002DD870();
extern void func_002DD930();
extern void func_002DD9F0();

/* sn-2.95.3-136 matched TU. */






extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void LookupSlotPopulateFieldsAndDispatch_1F7858(void *a0, int a1, int a2,
                                                       int a3, void *t0,
                                                       void *t1, int t2);














#include "godhand/vu0.h"

typedef void *(*vfn)(void *);

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_002DCD50")))
void func_002DCD50(void *a0)
{
    float va[4], vb[4];
    char *s1 = (char *)a0;
    char *o;
    char *g;
    float th;

    o = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    g = D_005864F0;
    if (Obj293_IsByteSet_53C(g) != 0) {
        return;
    }
    if (*(short *)(o + 0x54A) <= 0) {
        return;
    }
    if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(o) != 0) {
        return;
    }
    if (*(int *)(g + 0x514) > 0) {
        return;
    }
    if (Obj293_IsByteSet_53C(g) != 0) {
        return;
    }

    switch (*(int *)(s1 + 0x564)) {
    default:
        th = 4.0f;
        if (*(unsigned char *)(s1 + 0x620) != 0) {
            th = 9.0f;
        }
        break;
    case 0x264:
    case 0x265:
        th = 25.0f;
        if (*(unsigned char *)(s1 + 0x620) != 0) {
            th = 49.0f;
        }
        break;
    case 0x26A:
        th = 100.0f;
        if (*(unsigned char *)(s1 + 0x620) != 0) {
            th = 144.0f;
        }
        break;
    }
    {
        char *vt = *(char **)(s1 + 0x214);
        void *p1 = (*(vfn *)(vt + 0x6C))(s1 + *(short *)(vt + 0x68));

        if (th < capVu0MagnitudeSqXZ(p1, *(void **)(o + 0xF0))) {
            return;
        }
    }
    th = 0.0f;
    {
        char *vt = *(char **)(s1 + 0x214);
        void *p2 = (*(vfn *)(vt + 0x6C))(s1 + *(short *)(vt + 0x68));
        char *fp = *(char **)(o + 0xF0);
        float t = *(float *)(fp + 4) - *(float *)((char *)p2 + 4);
        float d;

        if (t < th) {
            d = -t;
        } else {
            d = t;
        }
        if (0.5f < d) {
            return;
        }
        {
            char *vt2 = *(char **)(s1 + 0x214);
            void *p3 = (*(vfn *)(vt2 + 0x6C))(s1 + *(short *)(vt2 + 0x68));
            float ta = Turn_dest(fp, *(float *)(o + 0x104), 3.1415927f, p3);
            float da;

            if (ta < th) {
                da = -ta;
            } else {
                da = ta;
            }
            if (0.7853982f < da) {
                return;
            }
            ta = 0.0f;
        }
        t = 0.0f;
    }

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);

    switch (*(int *)(s1 + 0x564)) {
    default: {
        char *q = *(char **)(o + 0xF0);
        char *vt;
        void *p4;

        {
            float *dp = va;

            if (dp != (float *)q) {
                dp[0] = ((float *)q)[0];
                dp[1] = ((float *)q)[1];
                dp[2] = ((float *)q)[2];
            }
        }
        vt = *(char **)(s1 + 0x214);
        p4 = (*(vfn *)(vt + 0x6C))(s1 + *(short *)(vt + 0x68));
        if (vb != (float *)p4) {
            vb[0] = ((float *)p4)[0];
            vb[1] = ((float *)p4)[1];
            vb[2] = ((float *)p4)[2];
        }
        va[1] = va[1] + 0.5f;
        vb[1] = vb[1] + 0.5f;
        if (ChkLine(va, vb, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
            return;
        }
        break;
    }
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26A:
        break;
    }

    {
        int w = *(int *)(s1 + 0x564);

        *(unsigned char *)(s1 + 0x620) = 1;
        switch (w) {
        default:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0xD, 0, (void *)&func_002DD300, s1, 0);
            break;
        case 0x20F:
        case 0x210:
        case 0x211:
        case 0x226:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0xF, 0, (void *)&func_002DD3C0, s1, 0);
            break;
        case 0x20A:
        case 0x20B:
        case 0x20C:
        case 0x20D:
        case 0x20E:
        case 0x245:
        case 0x247:
        case 0x24F:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x10, 0, (void *)&func_002DD480, s1, 0);
            break;
        case 0x246:
            switch (*(unsigned char *)(s1 + 0x621)) {
            default:
            case 0:
                LookupSlotPopulateFieldsAndDispatch_1F7858(
                    &D_00568288, 0xA, 0x26, 0, (void *)&func_002DD540, s1, 0);
                break;
            case 1:
                LookupSlotPopulateFieldsAndDispatch_1F7858(
                    &D_00568288, 0xA, 0x12, 0, (void *)&func_002DD270, s1, 0);
                break;
            }
        case 0x218:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x12, 0, (void *)&func_002DD270, s1, 0);
            break;
        case 0x278:
        case 0x279:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x26, 0, (void *)&func_002DD540, s1, 0);
            break;
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24D:
        case 0x24E:
        case 0x252:
        case 0x25A:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x1A, 0, (void *)&func_002DD6C0, s1, 0);
            break;
        case 0x209:
        case 0x213:
        case 0x214:
        case 0x215:
        case 0x217:
        case 0x21F:
        case 0x220:
        case 0x221:
        case 0x222:
        case 0x223:
        case 0x241:
        case 0x250:
        case 0x251:
        case 0x256:
        case 0x275:
        case 0x276:
        case 0x27E:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x12, 0, (void *)&func_002DD270, s1, 0);
            break;
        case 0x227:
        case 0x228:
        case 0x229:
        case 0x22A:
        case 0x22B:
        case 0x23A:
        case 0x243:
        case 0x244:
        case 0x24A:
        case 0x24B:
        case 0x25B:
            switch (*(unsigned char *)(s1 + 0x621)) {
            default:
            case 0:
                LookupSlotPopulateFieldsAndDispatch_1F7858(
                    &D_00568288, 0xA, 0xD, 0, (void *)&func_002DD300, s1, 0);
                break;
            case 1:
                LookupSlotPopulateFieldsAndDispatch_1F7858(
                    &D_00568288, 0xA, 0x12, 0, (void *)&func_002DD270, s1, 0);
                break;
            }
            break;
        case 0x260:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x12, 0, (void *)&func_002DD7B0, s1, 0);
            break;
        case 0x264:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x12, 0, (void *)&func_002DD870, s1, 0);
            break;
        case 0x265:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x12, 0, (void *)&func_002DD930, s1, 0);
            break;
        case 0x26A:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x12, 0, (void *)&func_002DD9F0, s1, 0);
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
            LookupSlotPopulateFieldsAndDispatch_1F7858(
                &D_00568288, 0xA, 0x16, 0, (void *)&func_002DD600, s1, 0);
            break;
        }
    }
}
