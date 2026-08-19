/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern int Forward30F348_31CFE0(void);
extern void func_002705D8(void *a0);
extern void func_0026A638(void *a0, int a1);
extern void func_0026A938(void *a0, int a1, int a2);
extern void func_00260B30(void *a0);
extern unsigned short D_00747A50;

/* sn-2.95.3-136 matched TU. */













__attribute__((section(".text.func_0023F5C8")))
void func_0023F5C8(void *a0)
{
    char *p = (char *)a0;
    int s1v, s0v;

    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0: {
        int gb;

        *(char *)(p + 0x1864) = 0;
        *(float *)(p + 0x54C) = 3.0f;
        if (D_00747A50 == 0x102) {
            *(int *)(p + 0x560) = 0x3D1;
        }
        switch (*(int *)(p + 0x564)) {
        default:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x368) + b;
                s0v = *(int *)(b + 0x36C) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x360) + b;
                s0v = *(int *)(b + 0x364) + b;
            }
            break;

        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217: case 0x229:
        case 0x22A: case 0x242: case 0x243: case 0x244: case 0x24B:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x7A4) + b;
                s0v = *(int *)(b + 0x7A8) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x7AC) + b;
                s0v = *(int *)(b + 0x7B0) + b;
            }
            break;

        case 0x256: case 0x27E:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x2B98) + b;
                s0v = *(int *)(b + 0x2B9C) + b;
            }
            break;

        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247: case 0x24F: case 0x250: case 0x251:
        case 0x278: case 0x279:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                if ((Forward30F348_31CFE0() & 1) != 0) {
                    int b = *(int *)(p + 0x304);
                    s1v = *(int *)(b + 0xB04) + b;
                    s0v = *(int *)(b + 0xB08) + b;
                } else {
                    int b = *(int *)(p + 0x304);
                    s1v = *(int *)(b + 0xB14) + b;
                    s0v = *(int *)(b + 0xB18) + b;
                }
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0xB0C) + b;
                s0v = *(int *)(b + 0xB10) + b;
            }
            break;

        case 0x260:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0xB04) + b;
                s0v = *(int *)(b + 0xB08) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0xB0C) + b;
                s0v = *(int *)(b + 0xB10) + b;
            }
            break;

        case 0x264:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x326C) + b;
                s0v = *(int *)(b + 0x3270) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x326C) + b;
                s0v = *(int *)(b + 0x3270) + b;
            }
            break;

        case 0x265:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x3724) + b;
                s0v = *(int *)(b + 0x3728) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x3724) + b;
                s0v = *(int *)(b + 0x3728) + b;
            }
            break;

        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1788) + b;
                s0v = *(int *)(b + 0x178C) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1790) + b;
                s0v = *(int *)(b + 0x1794) + b;
            }
            break;

        case 0x241:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x3ADC) + b;
                s0v = *(int *)(b + 0x3AE0) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x3AE4) + b;
                s0v = *(int *)(b + 0x3AE8) + b;
            }
            break;

        case 0x209: case 0x21F:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1788) + b;
                s0v = *(int *)(b + 0x178C) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1790) + b;
                s0v = *(int *)(b + 0x1794) + b;
            }
            break;

        case 0x20F:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0xFD4) + b;
                s0v = *(int *)(b + 0xFD8) + b;
                func_0026A638(p, 0);
            }
            break;

        case 0x210: case 0x211: case 0x226: case 0x270: case 0x271: case 0x272:
        case 0x273: case 0x274:
            {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0xFD4) + b;
                s0v = *(int *)(b + 0xFD8) + b;
            }
            break;

        case 0x220: case 0x221: case 0x222:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1D40) + b;
                s0v = *(int *)(b + 0x1D44) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1D48) + b;
                s0v = *(int *)(b + 0x1D4C) + b;
            }
            break;

        case 0x223:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x2E7C) + b;
                s0v = *(int *)(b + 0x2E80) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x2E7C) + b;
                s0v = *(int *)(b + 0x2E80) + b;
            }
            break;

        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
            if ((*(unsigned short *)(p + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1360) + b;
                s0v = *(int *)(b + 0x1364) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s1v = *(int *)(b + 0x1368) + b;
                s0v = *(int *)(b + 0x136C) + b;
            }
            break;
        }
        *(int *)(p + 0x16D0) |= 2;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p);
        func_002A8578(p, s1v, s0v, 0.0f, 0, gb & 0xFFFF, 0);
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    }
    case 1:
        if (moveMotion(p) != 0) {
            func_002705D8(p);
        }
        AddScaledVecToField_100_14F9F0(p, 1.0f);
        AddScaledXfmVecToField_F0_14F928(p, 1.0f);
        break;
    }
    if (*(int *)(p + 0x564) == 0x20F && (*(unsigned short *)(p + 0x3AC) & 1) != 0) {
        func_0026A938(p, 0, 0);
    }
    func_00260B30(p);
}
