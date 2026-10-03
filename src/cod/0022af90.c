#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void func_002812A8(void *a0, int a1, int a2);
extern void func_002831C8(void *a0, int a1, int a2);
extern void func_002495E0(void *a0, float f);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void *Getplayer(void);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern float Adjust_theta(float f12);
extern int cEmManage_CkPlCatched(void *a0);
extern void func_0026A638(void *a0, int a1);
extern void func_0026A838(void *a0, int a1);
extern char D_005864F0[];

/* Phase machine on the step byte, 4 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, func_002812A8, func_002831C8, moveMotion, cObjBase_addNullSpeed_Rotation and 3
 * more. */
__attribute__((section(".text.func_0024A518"))) void func_0024A518(cEm00 *self)
{
    int t0, b;
    float one;
    float f;

    self->emFlags = self->emFlags | 0x30400;
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            func_002A8578(self, EM_RES_REC(b, 0x3D7C), EM_RES_REC(b, 0x3D80), 0.0f, 10, t0, 0);
            if ((void *)self->sub0 != 0) {
                func_002812A8((void *)self->sub0, 1, 0);
            }
            if ((void *)self->sub1 != 0) {
                func_002831C8((void *)self->sub1, 1, 0);
            }
            self->step++;
        case 1:
            one = 1.0f;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (*(float *)((char *)self + 0x176C) <= 0.0f) {
                self->step++;
            }
            break;
        case 2:
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->resource;
            func_002A8578(self, EM_RES_REC(b, 0x3D84), EM_RES_REC(b, 0x3D88), 0.0f, 10, t0, 0);
            if ((void *)self->sub0 != 0) {
                func_002812A8((void *)self->sub0, 2, 0);
            }
            if ((void *)self->sub1 != 0) {
                func_002831C8((void *)self->sub1, 2, 0);
            }
            self->timer = 30.0f;
            self->step++;
        case 3:
            f = self->timer;
            if (0.0f < f) {
                self->timer = f - self->speedRate;
            } else {
                self->emFlags = self->emFlags & 0xFEFFFFFF;
            }
            func_002495E0(self, 0.0f);
            self->emFlags = self->emFlags | 0x800000;
            if (moveMotion(self) != 0) {
                self->emFlags = self->emFlags & 0xFEFFFFFF;
                func_002705D8(self);
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
}

/* Phase machine on the step byte, 4 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, Getplayer, Turn_dest, Turn_dest_dir, Adjust_theta and 7 more. */
__attribute__((section(".text.func_0022AF90"))) void func_0022AF90(cEm00 *self)
{
    char *s1 = (char *)self;
    char *v0;
    char *self;
    char *s2;
    int gb, b;
    float one;
    float th, d, ad, f, g;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0:
            *(int *)(s1 + 0x16D0) = (*(int *)(s1 + 0x16D0) | 2) & 0xFFFF7FFF;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            b = *(int *)(s1 + 0x304);
            func_002A8578(s1, EM_RES_REC(b, 0xCF8), EM_RES_REC(b, 0xCFC), 0.0f, 10, gb, 0);
            *(int *)(s1 + 0x5FC) = 0;
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 1:
            self = *(char **)(s1 + 0xF0);
            v0 = (char *)Getplayer();
            one = 1.0f;
            th = Turn_dest(self, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x1670), 0.5235988f);
            d = Turn_dest_dir(*(float *)(s1 + 0x104), Adjust_theta(th + *(float *)(s1 + 0x1670)),
                              *(float *)(s1 + 0x5A8) * 0.19634955f);
            *(float *)(s1 + 0x104) = *(float *)(s1 + 0x104) + d;
            moveMotion(s1);
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            if (*(short *)((char *)Getplayer() + 0x54A) <= 0) {
                return;
            }
            if (cEmManage_CkPlCatched(D_005864F0) != 0) {
                return;
            }
            f = *(float *)(s1 + 0x618);
            if (9.0f < f && f < 400.0f && *(float *)(s1 + 0x1714) <= 0.0f) {
                s2 = *(char **)(s1 + 0xF0);
                v0 = (char *)Getplayer();
                d = Turn_dest(s2, *(void **)(v0 + 0xF0), *(float *)(s1 + 0x104), 3.14159274f);
                if (d < 0.0f) {
                    f = -d;
                    ad = f;
                } else {
                    ad = d;
                }
                if (ad < 0.26179940f) {
                    *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
                }
            }
            if (*(float *)(s1 + 0x618) < 25.0f) {
                v0 = (char *)Getplayer();
                d = *(float *)(*(char **)(s1 + 0xF0) + 4) - *(float *)(*(char **)(v0 + 0xF0) + 4);
                if (d < 0.0f) {
                    f = -d;
                    ad = f;
                } else {
                    ad = d;
                }
                if (ad < 0.5f) {
                    func_002705D8(s1);
                }
            }
            break;
        case 2:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
            b = *(int *)(s1 + 0x304);
            func_002A8578(s1, EM_RES_REC(b, 0xDBC), EM_RES_REC(b, 0xDC0), 0.0f, 10, gb, 0);
            *(int *)(s1 + 0x5F0) = 0x64;
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        case 3:
            if (moveMotion(s1) != 0) {
                *(unsigned char *)(s1 + 0x2F6) = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s1, one);
            cObjBase_addNullSpeed(s1, one);
            if (*(unsigned short *)(s1 + 0x3AC) & 1) {
                if (*(unsigned char *)(s1 + 0x17C3) != 0) {
                    func_0026A638(s1, 1);
                } else {
                    func_0026A638(s1, 0);
                }
            }
            if (*(unsigned short *)(s1 + 0x3AC) & 2) {
                func_0026A838(s1, 0);
                func_0026A838(s1, 1);
            }
            break;
    }
    if (*(unsigned short *)(s1 + 0x3AC) & 3) {
        *(int *)(s1 + 0x5FC) = 1;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) = *(int *)(s1 + 0x16D4) & 0xFFFFFBFF;
    }
}
