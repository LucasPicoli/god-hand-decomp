/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern int cCoreSave_getGameLevel(void *a0);
extern char D_00569B70[];

/* sn-2.95.3-136 matched TU. */













__attribute__((section(".text.func_00213EA8")))
void func_00213EA8(void *a0)
{
    char *p = (char *)a0;
    int flag = 1;
    int s2v, s0v;

    switch (*(int *)(p + 0x564)) {
    case 0x20F: case 0x210: case 0x211:
    case 0x226:
    case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
        break;
    default:
        *(int *)(p + 0x16D0) = *(int *)(p + 0x16D0) | 0x400;
        break;
    }

    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0: {
        int gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p) & 0xFFFF;

        switch (*(int *)(p + 0x564)) {
        default:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xB8) + b;
                s0v = *(int *)(b + 0xBC) + b;
            }
            break;
        case 0x202: case 0x203:
        case 0x213:
        case 0x216: case 0x217:
        case 0x229: case 0x22A:
        case 0x24B:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x658) + b;
                s0v = *(int *)(b + 0x65C) + b;
            }
            break;
        case 0x242: case 0x243: case 0x244:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x35DC) + b;
                s0v = *(int *)(b + 0x35E0) + b;
            }
            break;
        case 0x256:
        case 0x27E:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x25E4) + b;
                s0v = *(int *)(b + 0x25E8) + b;
            }
            break;
        case 0x214: case 0x215:
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F:
        case 0x248: case 0x249:
        case 0x24C:
        case 0x24E:
        case 0x252:
        case 0x25A:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x10B8) + b;
                s0v = *(int *)(b + 0x10BC) + b;
            }
            break;
        case 0x225:
        case 0x24D:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3C98) + b;
                s0v = *(int *)(b + 0x3C9C) + b;
            }
            break;
        case 0x20A: case 0x20B:
        case 0x20D: case 0x20E:
        case 0x218:
        case 0x245: case 0x246: case 0x247:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x838) + b;
                s0v = *(int *)(b + 0x83C) + b;
            }
            break;
        case 0x278: case 0x279:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1FC0) + b;
                s0v = *(int *)(b + 0x1FC4) + b;
            }
            break;
        case 0x20C:
        case 0x24F:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1EBC) + b;
                s0v = *(int *)(b + 0x1EC0) + b;
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208:
        case 0x224:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1570) + b;
                s0v = *(int *)(b + 0x1574) + b;
            }
            break;
        case 0x241:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3A10) + b;
                s0v = *(int *)(b + 0x3A14) + b;
            }
            break;
        case 0x209:
        case 0x21F:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3428) + b;
                s0v = *(int *)(b + 0x342C) + b;
            }
            break;
        case 0x250: case 0x251:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1900) + b;
                s0v = *(int *)(b + 0x1904) + b;
            }
            break;
        case 0x260:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3048) + b;
                s0v = *(int *)(b + 0x304C) + b;
            }
            break;
        case 0x264:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x326C) + b;
                s0v = *(int *)(b + 0x3270) + b;
            }
            break;
        case 0x265:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3724) + b;
                s0v = *(int *)(b + 0x3728) + b;
            }
            break;
        case 0x26A:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3D34) + b;
                s0v = *(int *)(b + 0x3D38) + b;
            }
            break;
        case 0x20F: case 0x210: case 0x211:
        case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xD08) + b;
                s0v = *(int *)(b + 0xD0C) + b;
            }
            break;
        case 0x220: case 0x221: case 0x222:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1C00) + b;
                s0v = *(int *)(b + 0x1C04) + b;
            }
            break;
        case 0x223:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x2D6C) + b;
                s0v = *(int *)(b + 0x2D70) + b;
            }
            break;
        case 0x275: case 0x276:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x2284) + b;
                s0v = *(int *)(b + 0x2288) + b;
            }
            break;
        }
        if (*(int *)(p + 0x6EC) != 0) {
            int b = *(int *)(p + 0x304);
            s2v = *(int *)(b + 0x45C) + b;
            s0v = *(int *)(b + 0x460) + b;
        }
        func_002A8578(p, s2v, s0v, 0.0f, 10, gb, 0);
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    }
    case 1:
        AddScaledDeltaToField_104_2A7498(
            p, *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0),
            *(float *)(p + 0x5A8) * 0.09817477f);
        if (moveMotion(p) != 0) {
            func_002705D8(p);
        }
        AddScaledVecToField_100_14F9F0(p, 1.0f);
        AddScaledXfmVecToField_F0_14F928(p, 1.0f);
        if ((*(unsigned short *)(p + 0x3AC) & 0x20) != 0) {
            flag = 0;
        }
        break;
    }

    if (flag != 0) {
        if (*(unsigned char *)(p + 0x2F7) == 0
            && 9.0f < *(float *)(p + 0x618)) {
            func_002705D8(p);
            return;
        }
        flag = 1;
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            if (*(unsigned int *)(p + 0x16D8) != 0) {
                flag = 0;
            }
            break;
        case 2:
            if (*(unsigned int *)(p + 0x16D8) >= 2) {
                flag = 0;
            }
            break;
        case 3:
            if (*(unsigned int *)(p + 0x16D8) >= 3) {
                flag = 0;
            }
            break;
        case 4:
            if (*(unsigned int *)(p + 0x16D8) >= 3) {
                flag = 0;
            }
            break;
        case 5:
            if (*(unsigned int *)(p + 0x16D8) >= 0x64) {
                flag = 0;
            }
            break;
        }
        if (flag != 0) {
            func_00262AA8(p);
        }
    }
}
