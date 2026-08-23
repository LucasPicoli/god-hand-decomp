/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 candidate. */











__attribute__((section(".text.func_002311A8")))
void func_002311A8(void *a0)
{
    char *s1 = (char *)a0;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        int o1;
        int o2;

        switch (*(int *)(s1 + 0x564)) {
        default:
        {
            int b = *(int *)(s1 + 0x304);

            o1 = *(int *)(b + 0x1C0) + b;
            o2 = *(int *)(b + 0x1C4) + b;
        }
            break;
    case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
    case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
        {
            int b = *(int *)(s1 + 0x304);

            o1 = *(int *)(b + 0x948) + b;
            o2 = *(int *)(b + 0x94C) + b;
        }
            break;
    case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
    case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
    case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
        {
            int b = *(int *)(s1 + 0x304);

            o1 = *(int *)(b + 0x11A0) + b;
            o2 = *(int *)(b + 0x11A4) + b;
        }
            break;
        }
        func_002A8578(s1, o1, o2, 0.0f, 0xA, t0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                           (short)Obj0000_Get_Field_424_1595F0(s1),
                           s1, 0, 0, 0, 0);
        *(float *)(s1 + 0x54C) = 2.0f;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    case 1:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}
