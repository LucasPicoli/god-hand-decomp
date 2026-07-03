/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002740D8")))
int func_002740D8(char *a0) {
    if (*(int *)(a0 + 0x6EC) != 0) {
        return 0;
    }
    if (*(int *)(a0 + 0x6F0) != 0) {
        return 0;
    }
    if (*(int *)(a0 + 0x700) != 0) {
        return 0;
    }
    if (*(int *)(a0 + 0x704) != 0) {
        return 0;
    }
    switch (*(int *)(a0 + 0x564)) {
    case 0x209:
    case 0x213:
    case 0x217:
    case 0x21f:
    case 0x221:
    case 0x223:
    case 0x224:
    case 0x242:
    case 0x243:
    case 0x244:
    case 0x252:
    case 0x256:
    case 0x264:
    case 0x265:
    case 0x26a:
    case 0x275:
    case 0x276:
    case 0x27e:
        return 0;
    default:
        return 1;
    }
}
