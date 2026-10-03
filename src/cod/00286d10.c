#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern void func_002A74E0(void *a0, void *a1, int a2);
extern void func_002A7CA0(void *a0, void *a1);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int irand(void);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern int D_007476B0;
extern char D_005FEE00[];
/* Phase machine on the step byte, 8 case labels. Calls capVu0MagnitudeSqXZ, func_002A74E0,
 * func_002A7CA0, func_002A8578, irand, cSnd_SeCall_2CBA48 and 4 more. */
__attribute__((section(".text.func_00286D10"))) void func_00286D10(cEm00 *self)
{
    char *s1 = &self->unk1590;
    float f20;
    int v0;
    f20 = capVu0MagnitudeSqXZ(s1, *((void **)(((char *)self + 0xF0))));
    *((int *)(((char *)self + 0x15B0))) = (*((int *)(((char *)self + 0x15B0)))) & 0xFFFFFFFE;
    if ((D_007476B0 & 7) == ((*((unsigned char *)(((char *)self + 0x2FC)))) & 7)) {
        func_002A74E0(self, s1, 1);
        func_002A7CA0(self, &self->unk1570);
    }
    switch (*((unsigned char *)(((char *)self + 0x2F6)))) {
        case 0:
            if ((*((short *)(((char *)self + 0x54A)))) < (*((short *)(((char *)self + 0x548))))) {
                switch (*((int *)(((char *)self + 0x564)))) {
                    default:
                        v0 = *((int *)(((char *)self + 0x304)));
                        func_002A8578(self, (*((int *)(v0 + 0xB8))) + v0,
                                      (*((int *)(v0 + 0xBC))) + v0, 0.0f, 10, 0, 0);
                        break;

                    case 0x2A7:

                    case 0x2AB:
                        v0 = *((int *)(((char *)self + 0x304)));
                        func_002A8578(self, (*((int *)(v0 + 0x40))) + v0,
                                      (*((int *)(v0 + 0x44))) + v0, 0.0f, 10, 0, 0);
                        break;
                }

            } else {
                switch (*((int *)(((char *)self + 0x564)))) {
                    default:
                        if (irand() & 1) {
                            v0 = *((int *)(((char *)self + 0x304)));
                            func_002A8578(self, (*((int *)(v0 + 0x38))) + v0,
                                          (*((int *)(v0 + 0x3C))) + v0, 0.0f, 10, 0, 0);
                        } else {
                            v0 = *((int *)(((char *)self + 0x304)));
                            func_002A8578(self, (*((int *)(v0 + 0x40))) + v0,
                                          (*((int *)(v0 + 0x44))) + v0, 0.0f, 10, 0, 0);
                        }
                        break;

                    case 0x2A7:

                    case 0x2AB:
                        v0 = *((int *)(((char *)self + 0x304)));
                        func_002A8578(self, (*((int *)(v0 + 0x38))) + v0,
                                      (*((int *)(v0 + 0x3C))) + v0, 0.0f, 10, 0, 0);
                        break;
                }
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5A, self, 0, 0, 0, 0);
            *((unsigned char *)(((char *)self + 0x2F6))) =
                (*((unsigned char *)(((char *)self + 0x2F6)))) + 1;

        case 1:
            cGameObj_SetTgtTurn(self, &self->unk1570, 0.098174773f);
            if ((((((moveMotion(self) != 0) &&
                    (((*((int *)(((char *)self + 0x15B0)))) & 0x200) == 0)) &&
                   (f20 > 100.0f)) &&
                  ((*((int *)(((char *)self + 0x564)))) != 0x2A7)) &&
                 ((*((int *)(((char *)self + 0x564)))) != 0x2AB)) &&
                ((irand() & 7) == 0)) {
                *((unsigned char *)(((char *)self + 0x2F6))) = 2;
                *((int *)(((char *)self + 0x15B0))) = (*((int *)(((char *)self + 0x15B0)))) | 0x200;
            }
            cModel_calcNullPart(self);
            Add_nullspeed(self);
            if (f20 < 1.0f) {
                float d;
                float ad;
                ad = (d = (*((float *)(&self->unk1590.y))) -
                          ((float *)(*((void **)(((char *)self + 0xF0)))))[1]);
                if (d < 0.0f) {
                    ad = -d;
                }
                if (ad < 1.0f) {
                    *((unsigned char *)(((char *)self + 0x2F4))) = 0;
                    *((unsigned char *)(((char *)self + 0x2F5))) = 0;
                    *((unsigned char *)(((char *)self + 0x2F6))) = (d = 0);
                    *((unsigned char *)(((char *)self + 0x2F7))) = 0;
                }
            }
            break;

        case 2:
            v0 = *((int *)(((char *)self + 0x304)));
            func_002A8578(self, (*((int *)(v0 + 0x178))) + v0, (*((int *)(v0 + 0x17C))) + v0, 0.0f,
                          10, 0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5C, self, 0, 0, 0, 0);
            *((unsigned char *)(((char *)self + 0x2F6))) =
                (*((unsigned char *)(((char *)self + 0x2F6)))) + 1;

        case 3:
            cGameObj_SetTgtTurn(self, &self->unk1570, 0.098174773f);
            if (moveMotion(self) != 0) {
                *((unsigned char *)(((char *)self + 0x2F6))) = 0;
            }
            cModel_calcNullPart(self);
            Add_nullspeed(self);
            break;
    }
}
