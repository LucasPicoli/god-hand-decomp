/* sn-2.95.3-136 matched TU. */

extern void func_002A84A8(void *a0);
extern void espSys_effDataRelease(void *a0, int a1);
extern void func_00208858(void *a0);
extern void func_0028EB88(void *a0, void *a1);
extern char D_007419A0[];
extern char D_004479C8[];

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_00202058")))
void func_00202058(char *s1, void *s2) {
    int h;

    *(int *)(s1 + 0x214) = (int)D_004479C8;
    func_002A84A8(s1);
    h = *(unsigned short *)(s1 + 0x2FE);
    if (h < 0x223) {
        if (h >= 0x220) {
            goto tail;
        }
    }
    {
        switch (*(int *)(s1 + 0x564)) {
        case 0x20C:
        case 0x24F:
            espSys_effDataRelease(D_007419A0, 0x64);
            break;
        case 0x214:
        case 0x215:
            espSys_effDataRelease(D_007419A0, 0x6C);
            break;
        case 0x223:
            espSys_effDataRelease(D_007419A0, 0x7B);
            break;
        case 0x241:
            espSys_effDataRelease(D_007419A0, 0x99);
            break;
        case 0x252:
            espSys_effDataRelease(D_007419A0, 0x72);
            espSys_effDataRelease(D_007419A0, 0xAA);
            break;
        case 0x264:
            espSys_effDataRelease(D_007419A0, 0xAA);
            espSys_effDataRelease(D_007419A0, 0xBC);
            break;
        case 0x265:
            espSys_effDataRelease(D_007419A0, 0xBD);
            break;
        case 0x250:
        case 0x251:
            espSys_effDataRelease(D_007419A0, 0xA8);
            break;
        case 0x260:
            espSys_effDataRelease(D_007419A0, 0xA8);
            espSys_effDataRelease(D_007419A0, 0xB8);
            break;
        case 0x256:
        case 0x27E:
            espSys_effDataRelease(D_007419A0, 0xAE);
            break;
        case 0x209:
            espSys_effDataRelease(D_007419A0, 0x61);
            break;
        case 0x21F:
            espSys_effDataRelease(D_007419A0, 0x61);
            espSys_effDataRelease(D_007419A0, 0x77);
            break;
        case 0x208:
        case 0x20B:
            espSys_effDataRelease(D_007419A0, 0x63);
            break;
        case 0x21C:
            espSys_effDataRelease(D_007419A0, 0x63);
            espSys_effDataRelease(D_007419A0, 0x72);
            break;
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            espSys_effDataRelease(D_007419A0, 0xC8);
            break;
        case 0x275:
        case 0x276:
            espSys_effDataRelease(D_007419A0, 0xCD);
            break;
        case 0x211:
            espSys_effDataRelease(D_007419A0, 0x69);
            break;
        case 0x20E:
        case 0x213:
        case 0x217:
            espSys_effDataRelease(D_007419A0, 0x6F);
            break;
        case 0x26A:
            espSys_effDataRelease(D_007419A0, 0xC2);
            break;
        case 0x247:
            espSys_effDataRelease(D_007419A0, 0x9F);
            break;
        case 0x218:
        case 0x246:
            espSys_effDataRelease(D_007419A0, 0x9E);
            break;
        case 0x278:
        case 0x279:
            espSys_effDataRelease(D_007419A0, 0xD0);
            espSys_effDataRelease(D_007419A0, 0x9E);
            break;
        case 0x21A:
        case 0x21B:
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
        case 0x25A:
            espSys_effDataRelease(D_007419A0, 0x72);
            break;
        case 0x242:
        case 0x243:
        case 0x244:
            espSys_effDataRelease(D_007419A0, 0x9A);
            break;
        }
    }
tail:
    func_00208858(s1);
    func_0028EB88(s1, s2);
}
