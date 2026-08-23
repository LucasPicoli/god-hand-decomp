/* sn-2.95.3-136 matched TU. */

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00393F80")))
int func_00393F80(char *p) {
    if ((*(int *)p & 0xFFFFFF) != 0x524E53) return 1;
    if ((unsigned int)(*(unsigned char *)(p + 3) - 0x31) < 2)
        return (((*(int *)(p + 0x28) - 1) & (int)p) != 0) ? 4 : 0;
    return 2;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002833D8")))
void func_002833D8(char *obj, unsigned char mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 0xD;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 0xD;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 0xD;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00283438")))
void func_00283438(char *obj, unsigned char mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 0xE;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 0xE;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 0xE;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    }
}
