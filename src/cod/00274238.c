/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */

extern int cCoreSave_getGameLevel(void *a0);
extern float fRand0_1(void);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern char D_00569B70[];
extern char D_005FEE00[];

__attribute__((section(".text.func_00274238")))
void func_00274238(char *a0, unsigned char a1) {
    char *s1 = a0;
    unsigned char s2 = a1;

    if ((*(int *)(s1 + 0x16D0) & 0x2000) != 0) goto tail;
    switch (*(int *)(s1 + 0x564)) {
    default:
        switch (cCoreSave_getGameLevel(D_00569B70)) {
            case 1: default:
            *(float *)(s1 + 0x173C) = 40.0f;
            break;
            case 2:
            *(float *)(s1 + 0x173C) = 30.0f;
            break;
            case 3:
            *(float *)(s1 + 0x173C) = 20.0f;
            break;
            case 4:
            *(float *)(s1 + 0x173C) = 20.0f;
            break;
            case 5:
            *(float *)(s1 + 0x173C) = 15.0f;
            break;
        }
        break;
    case 0x204: case 0x208: case 0x209: case 0x20B: case 0x20E: case 0x211:
    case 0x213: case 0x214: case 0x215: case 0x217: case 0x218: case 0x21C:
    case 0x21F: case 0x220: case 0x221: case 0x222: case 0x223: case 0x241:
    case 0x244: case 0x247: case 0x250: case 0x251: case 0x252: case 0x256:
    case 0x25B: case 0x260: case 0x264: case 0x265: case 0x26A: case 0x270:
    case 0x271: case 0x272: case 0x273: case 0x274: case 0x275: case 0x276:
    case 0x27E:
        switch (cCoreSave_getGameLevel(D_00569B70)) {
            case 2:
            *(float *)(s1 + 0x173C) = 8.0f;
            break;
            case 3:
            *(float *)(s1 + 0x173C) = 6.0f;
            break;
            case 4:
            *(float *)(s1 + 0x173C) = 6.0f;
            break;
            case 5:
            *(float *)(s1 + 0x173C) = 5.0f;
            break;
            case 1: default:
            *(float *)(s1 + 0x173C) = 10.0f;
            break;
        }
        break;
    case 0x24F: case 0x278: case 0x279:
        *(float *)(s1 + 0x173C) = 0.0f;
        goto tail;
    case 0x206: case 0x20C: case 0x20D: case 0x224: case 0x225: case 0x227:
    case 0x228: case 0x229: case 0x22A: case 0x22B: case 0x22C: case 0x22D:
    case 0x22E: case 0x22F: case 0x23A: case 0x246: case 0x24B: case 0x24D:
    case 0x25A:
        switch (cCoreSave_getGameLevel(D_00569B70)) {
            case 1: default:
            *(float *)(s1 + 0x173C) = 15.0f;
            break;
            case 2:
            *(float *)(s1 + 0x173C) = 13.0f;
            break;
            case 3:
            *(float *)(s1 + 0x173C) = 12.0f;
            break;
            case 4:
            *(float *)(s1 + 0x173C) = 12.0f;
            break;
            case 5:
            *(float *)(s1 + 0x173C) = 10.0f;
            break;
        }
        break;
    }
    if (cCoreSave_getGameLevel(D_00569B70) < 5) {
        *(float *)(s1 + 0x173C) = *(float *)(s1 + 0x173C) + fRand0_1() * 4.0f;
    }
tail:
    if (*(int *)(s1 + 0x564) == 0x279) {
        ReleaseField6ECByTag564_26B1E8(s1);
    }
    *(unsigned char *)(s1 + 0x2F4) = 0;
    *(unsigned char *)(s1 + 0x2F5) = 0x69;
    *(unsigned char *)(s1 + 0x2F6) = 0;
    *(unsigned char *)(s1 + 0x2F7) = s2;
    if (s2 != 0) {
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x7C, s1, 0, 0, 0, 0);
    }
}
