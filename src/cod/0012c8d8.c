/* sn-2.95.3-136 matched TU. */

extern void Obj0000_Set_Byte_157_If_Ptr_NonNull_1FC120(void *a0);
extern char *CreateObj(int a0, int a1);
extern int cCoreSave_getCostumeNo(void *a0);
extern int cOmWeapon_setParent();
extern char *D_00569B70;

/* sn-2.95.3-136 matched TU. */







#include "godhand/vu0.h"

__attribute__((section(".text.pl00_setPaper")))
void pl00_setPaper(void *a0) {
    char *s0 = (char *)a0;
    float buf[8];
    char *w;
    char *obj;

    if (*(int *)(s0 + 0x6A8) == 0) {
        w = (char *)&D_00569B70;
        Obj0000_Set_Byte_157_If_Ptr_NonNull_1FC120(w);
        obj = CreateObj(0x376, 0xFFFF);
        *(char **)(s0 + 0x6A8) = obj;
        if (obj != 0) {
            char *cls;
            int (*fn)(char *);
            short off;
            float *src;
            float *src2;
            float *dst;
            float *d490;
            int *p100;

            cls = *(char **)(obj + 0x214);
            fn = *(int (**)(char *))(cls + 0x44);
            off = *(short *)(cls + 0x40);
            fn(obj + off);

            dst = *(float **)(*(char **)(s0 + 0x6A8) + 0xF0);
            src = *(float **)(s0 + 0xF0);
            if (dst != src) {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
            src2 = *(float **)(s0 + 0xF0);
            d490 = (float *)(*(char **)(s0 + 0x6A8) + 0x490);
            if (d490 != src2) {
                d490[0] = src2[0];
                d490[1] = src2[1];
                d490[2] = src2[2];
            }
            p100 = (int *)(*(char **)(s0 + 0x6A8) + 0x100);
            p100[0] = 0;
            p100[1] = 0;
            p100[2] = 0;
            VU0_SQC2_VF0(buf, 0x0);
            VU0_SQC2_VF0(buf, 0x10);
            buf[0] = 0.0f;
            buf[1] = 0.047f;
            buf[2] = -0.14f;
            switch (cCoreSave_getCostumeNo(w)) {
            case 0:
            case 1:
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                buf[2] = -0.155f;
                break;
            case 6:
            case 7:
                break;
            }
            buf[4] = 0.0f;
            buf[5] = 0.0f;
            buf[6] = 0.0f;
            cOmWeapon_setParent(*(int *)(s0 + 0x6A8), s0, 2, buf, (char *)buf + 0x10);
        }
    }
}
