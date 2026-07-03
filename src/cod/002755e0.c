/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.cEm00_setDevilFlag")))
void cEm00_setDevilFlag(char *a0) {
    switch (*(int *)(a0 + 0x564)) {
    case 0x208:
    case 0x209:
    case 0x20b:
    case 0x20e:
    case 0x213:
    case 0x214:
    case 0x215:
    case 0x217:
    case 0x21c:
    case 0x21f:
    case 0x220:
    case 0x221:
    case 0x222:
    case 0x223:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x256:
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26a:
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274:
    case 0x275:
    case 0x276:
    case 0x278:
    case 0x279:
    case 0x27e:
        break;
    default:
        *(int *)(a0 + 0x16D0) |= 0x200;
        *(int *)(a0 + 0x16D4) |= 0x1000000;
        break;
    }
}
