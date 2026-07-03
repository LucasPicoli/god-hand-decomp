/* sn-2.95.3-136 matched TU. */

extern int D_00747A0C;

__attribute__((section(".text.func_00272688")))
int func_00272688(char *a0) {
    if (D_00747A0C == 0 && (*(int *)(a0 + 0x564) ^ 0x244) != 0) {
reject:
        return 0;
    }
    if (*(int *)(a0 + 0x16D4) & 0x1000) {
        if ((*(int *)(a0 + 0x564) ^ 0x244) != 0) {
            goto reject;
        }
    }
    switch (*(int *)(a0 + 0x564)) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
    case 0x204:
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x20a:
    case 0x20c:
    case 0x20d:
    case 0x216:
    case 0x218:
    case 0x224:
    case 0x227:
    case 0x228:
    case 0x229:
    case 0x22a:
    case 0x22b:
    case 0x23a:
    case 0x240:
    case 0x241:
    case 0x242:
    case 0x243:
    case 0x244:
    case 0x245:
    case 0x246:
    case 0x247:
    case 0x24a:
    case 0x24b:
        return 1;
    default:
        goto reject;
    }
}
